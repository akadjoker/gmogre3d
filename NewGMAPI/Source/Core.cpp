/* Copyright (c) 2011-2012 William Newbery
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
 */
#include "Precompiled.hpp"
#include "CoreInternal.hpp"
#include "CallHook.hpp"
#include "BinSearch.hpp"
#include "Functions.hpp"
#include "Functions/dll.hpp"
#include "InstanceArray.hpp"
namespace gm
{
    Shared *shared          = 0;
    HANDLE sharedHandle     = 0;
    /**Not the shame as shared::init. This is just the number of times this
     * specific instance has been initialised. E.g. if the same dll is being
     * used by multiple extensions in the same game.
     */
    int initcnt = 0;
    
    bool initShared();
    void freeShared();
    bool initStrings();
    bool initVariables();
    bool initD3d();
    
    
    Shared *getShared()
    {
        return shared;
    }
    
    void remoteRemoveHook()
    {
        assert (shared->hookModule == getThisModule(false));
        assert (shared->hookVersion == HOOK_VERSION);
        assert (shared->removeHook == remoteRemoveHook);
        removeCallHook();
        //If was only hosting the call hooks, free the now not needed shared
        //memory.
        if (initcnt == 0) freeShared();
    }
    bool init(double get_function_address_ptr)
    {
        if(initcnt)
        {
            initcnt++;
            return true;
        }
        else
        {
            if (shared == 0)
            {
                //shared != 0 is possible if previously loaded, and is currently
                //hosting the hooks into GM's code.
                if (!initShared())
                    return false;
            }
            if (!initStrings())
                return false; 
            if (!initFunctions(get_function_address_ptr))
                return false;
            if (!initInstanceArray())
                return false;
            if (!initVariables())
                return false;
            if (!initD3d())
                return false;
            
            if(!shared->initCnt)
            {
                //first shared init
                if(!installCallHook((void*)(uintptr_t)get_function_address("external_call").real))
                    return false;
                shared->hookModule = getThisModule(true);
                shared->removeHook = &remoteRemoveHook;
                shared->hookVersion = HOOK_VERSION;
            }
            else if(shared->hookVersion < HOOK_VERSION)
            {
                //this module has a newer version of the hook code
                shared->removeHook();
                HMODULE module = getThisModule(true);
                FreeLibrary(shared->hookModule);
                shared->hookModule = module;
                shared->removeHook = 0;
                shared->hookVersion = HOOK_VERSION;
                if (!installCallHook((void*)(uintptr_t)get_function_address("external_call").real))
                    return false;
                shared->removeHook = &remoteRemoveHook;
            }
            shared->initCnt++;
            initcnt = 1;
            return true;
        }
    }
    void shutdown()
    {
        //if this gmapi instance is no longer used
        if(!--initcnt)
        {
            //if no gmapi instance is being used
            if(!--shared->initCnt)
            {
                if (shared->hookModule == getThisModule(false))
                    removeCallHook();
                else shared->removeHook();
                FreeLibrary(shared->hookModule);
            }
            //Only free the shared data if this instance is not still being used
            //to host the hook code, since that code uses the shared memory.
            //It will be freed later by remoteRemoveHook
            if (shared->hookModule != getThisModule(false))
                freeShared();
        }
    }
    
    std::wstring getSharedMemName()
    {
        DWORD id = GetCurrentProcessId();
        std::wstringstream ss;
        ss << L"SVGMAPI_SharedMem_" << id;
        return ss.str();
    }
    bool initShared()
    {
        //Create a named shared memory region such that different GMAPI
        //instances can find it without knowing about each other.
        std::wstring name = getSharedMemName();
        sharedHandle = CreateFileMapping(
            INVALID_HANDLE_VALUE,
            NULL,
            PAGE_READWRITE | SEC_COMMIT,
            0, sizeof(Shared),
            name.c_str());
        if (sharedHandle == NULL)
            return false;

        shared = (Shared*)MapViewOfFile(
            sharedHandle, FILE_MAP_WRITE,
            0,0,0);
        return shared != 0;
    }
    void freeShared()
    {
        UnmapViewOfFile(shared);
        CloseHandle(sharedHandle);
        shared = 0;
        sharedHandle = NULL;
    }

    HINSTANCE getThisModule(bool incRef)
    {
        DWORD flags = GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS;
        if (!incRef) flags |= GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT;
        HINSTANCE module;
        if(!GetModuleHandleEx(
            flags,
            (LPWSTR)&getThisModule,
            &module))
            return NULL;
        return module;
    }
}
