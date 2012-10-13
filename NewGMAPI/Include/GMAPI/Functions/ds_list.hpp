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
#ifndef GMAPI_FUNCTIONS_DS_LIST_HPP
#define GMAPI_FUNCTIONS_DS_LIST_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real ds_list_create()
    {
        return call(functions[233]);
    }
    
    inline void ds_list_destroy(Real id)
    {
        call(functions[234], id);
    }
    
    inline void ds_list_clear(Real id)
    {
        call(functions[235], id);
    }
    
    inline Real ds_list_copy(Real id, Real source)
    {
        return call(functions[236], id, source);
    }
    
    inline Real ds_list_size(Real id)
    {
        return call(functions[237], id);
    }
    
    inline Real ds_list_empty(Real id)
    {
        return call(functions[238], id);
    }
    
    inline void ds_list_add(Real id, Value val)
    {
        call(functions[239], id, val);
    }
    
    inline void ds_list_insert(Real id, Real pos, Value val)
    {
        call(functions[240], id, pos, val);
    }
    
    inline void ds_list_replace(Real id, Real pos, Value val)
    {
        call(functions[241], id, pos, val);
    }
    
    inline void ds_list_delete(Real id, Real pos)
    {
        call(functions[242], id, pos);
    }
    
    inline Real ds_list_find_index(Real id, Value val)
    {
        return call(functions[243], id, val);
    }
    
    inline Value ds_list_find_value(Real id, Real pos)
    {
        return call(functions[244], id, pos);
    }
    
    inline void ds_list_sort(Real id, Real ascend)
    {
        call(functions[245], id, ascend);
    }
    
    inline void ds_list_shuffle(Real id)
    {
        call(functions[246], id);
    }
    
    inline String ds_list_write(Real id)
    {
        return call(functions[247], id);
    }
    
    inline void ds_list_read(Real id, String str)
    {
        call(functions[248], id, str);
    }
    
    ///@}
}
#endif
