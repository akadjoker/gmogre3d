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
#include "Function.hpp"
#include "Functions.hpp"
#include "FunctionNames.hpp"
namespace gm
{
    static const unsigned FUNCTION_COUNT = sizeof(FUNCTION_NAMES) / sizeof(FUNCTION_NAMES[0]);
    GMAPI_DLL Function functions[FUNCTION_COUNT];
    
    bool initFunctions(double get_function_address)
    {
        Function get_function_address_ptr = (Function)(uintptr_t)get_function_address;
        for(unsigned i = 0; i < FUNCTION_COUNT; ++i)
        {
            Value v = call(get_function_address_ptr, gm::Value(FUNCTION_NAMES[i]));
            functions[i] = (Function)(uintptr_t)v.real;
        }
        return true;
    }
}
