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
#include "CallHook.hpp"
#include "CoreInternal.hpp"

namespace gm
{
    void *hookReturn;
    //Implemented in assembly
    void hookFunction();
    
    /**old external_call code
        006175B4 55                   push        ebp  
        006175B5 8B EC                mov         ebp,esp  
        006175B7 81 C4 64 FE FF FF    add         esp,0FFFFFE64h  
    */
    //prevent the compiler inserting padding into the machine code
#   pragma pack(push, 1)
    struct NewCode
    {
        //7 byte jmp op
        //unsigned char jmp; void *jmpAddress; unsigned short jmpSeg;
        //2 nop
        //unsigned char nop1, nop2;
        //7 byte jmp op
        unsigned char jmp; int jmpRel;
        //2 nop
        unsigned char nop1, nop2, nop3, nop4;
    };
#   pragma pack(pop)
    //const NewCode newCode = {0xEA, &hookFunction, 0x0023, 0x90, 0x90};
    //const NewCode newCode = { 0xE9, ((char*)&hookFunction) - ((char*)external_call) - 5, 0x90, 0x90, 0x90, 0x90 };

    const unsigned char oldCode[] =
    {
        0x55,
        0x8B, 0xEC,
        0x81, 0xC4, 0x64, 0xFE, 0xFF, 0xFF,
    };
    
    void *external_call_ptr;
    
    bool unprotectMem(DWORD *oldProtect)
    {
        return VirtualProtect(external_call_ptr, sizeof(NewCode), PAGE_EXECUTE_READWRITE, oldProtect) != 0;
    }
    bool reprotectMem(DWORD protect)
    {
        return VirtualProtect(external_call_ptr, sizeof(NewCode), protect, &protect) != 0;
    }
    bool installCallHook(void *external_call)
    {
        external_call_ptr = external_call;
        const NewCode newCode = { 0xE9, ((char*)&hookFunction) - ((char*)external_call) - 5, 0x90, 0x90, 0x90, 0x90 };

        assert(sizeof(newCode) == sizeof(oldCode));
        hookReturn = (char*)external_call + sizeof(newCode);

        DWORD oldProtect;
        //gain write access to code
        if(!unprotectMem(&oldProtect))
        {
            return false;
        }
        
        assert(memcmp(external_call, oldCode, sizeof(newCode)) == 0);
        memcpy(external_call, &newCode, sizeof(newCode));
        
        //remove write access again
        reprotectMem(oldProtect);

        return true;
    }
    void removeCallHook()
    {
        DWORD oldProtect;
        if(!unprotectMem(&oldProtect))
            return;
        memcpy(external_call_ptr, oldCode, sizeof(NewCode));
        reprotectMem(oldProtect);
    }
}
