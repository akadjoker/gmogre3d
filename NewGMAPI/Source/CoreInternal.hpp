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
#ifndef GMAPI_COREINTERNAL_HPP
#define GMAPI_COREINTERNAL_HPP
#include "Core.hpp"
namespace gm
{
    struct Instance;
    struct Shared
    {
        /**The number of times shared initialisation has been performed.
         * e.g. adding the code into GM to preserve the self and other
         * pointers.
         */
        int initCnt;
        Instance *self;
        Instance *other;
        /**The version of the hook code. If a GMAPI instance is loaded after
         * another GMAPI was already loaded, but this one has a newer version
         * of the code, it will replace the old hook with its newer one.*/
        int hookVersion;
        /**The DLL that owns the current hook (to ensure that DLL can't get
         * unloaded while the hook is still in place).
         */
        HINSTANCE hookModule;
        /**The function to remove the current hook, and restore the original
         * GM code.
         */
        void (__cdecl *removeHook)();
    };
    static const unsigned HOOK_VERSION = 2;
    Shared *getShared();
    /**Gets the HINSTANCE/HMODULE/base address of whatever this is
     * implemented in. E.g. the GMAPI DLL is you used that, or the DLL
     * you statically linked the GMAPI into.
     */
    HINSTANCE getThisModule(bool incRef);
}
#endif
