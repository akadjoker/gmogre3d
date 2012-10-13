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
//Auto-Generated File
#ifndef GMAPI_FUNCTIONS_GAMEPLAY_MISC_HPP
#define GMAPI_FUNCTIONS_GAMEPLAY_MISC_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real variable_global_exists(String name)
    {
        return call(functions[333], name);
    }
    
    inline Real variable_local_exists(String name)
    {
        return call(functions[334], name);
    }
    
    inline Value variable_global_get(String name)
    {
        return call(functions[335], name);
    }
    
    inline Value variable_global_array_get(String name, Real ind)
    {
        return call(functions[336], name, ind);
    }
    
    inline Value variable_global_array2_get(String name, Real ind1, Real ind2)
    {
        return call(functions[337], name, ind1, ind2);
    }
    
    inline Value variable_local_get(String name)
    {
        return call(functions[338], name);
    }
    
    inline Value variable_local_array_get(String name, Real ind)
    {
        return call(functions[339], name, ind);
    }
    
    inline Value variable_local_array2_get(String name, Real ind1, Real ind2)
    {
        return call(functions[340], name, ind1, ind2);
    }
    
    inline void variable_global_set(String name, Value value)
    {
        call(functions[341], name, value);
    }
    
    inline void variable_global_array_set(String name, Real ind, Value value)
    {
        call(functions[342], name, ind, value);
    }
    
    inline void variable_global_array2_set(String name, Real ind1, Real ind2, Value value)
    {
        call(functions[343], name, ind1, ind2, value);
    }
    
    inline void variable_local_set(String name, Value value)
    {
        call(functions[344], name, value);
    }
    
    inline void variable_local_array_set(String name, Real ind, Value value)
    {
        call(functions[345], name, ind, value);
    }
    
    inline void variable_local_array2_set(String name, Real ind1, Real ind2, Value value)
    {
        call(functions[346], name, ind1, ind2, value);
    }
    
    inline void set_program_priority(Real priority)
    {
        call(functions[347], priority);
    }
    
    inline void set_application_title(String title)
    {
        call(functions[348], title);
    }
    
    ///@}
}
#endif
