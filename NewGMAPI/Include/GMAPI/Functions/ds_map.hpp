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
#ifndef GMAPI_FUNCTIONS_DS_MAP_HPP
#define GMAPI_FUNCTIONS_DS_MAP_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real ds_map_create()
    {
        return call(functions[249]);
    }
    
    inline void ds_map_destroy(Real id)
    {
        call(functions[250], id);
    }
    
    inline void ds_map_clear(Real id)
    {
        call(functions[251], id);
    }
    
    inline Real ds_map_copy(Real id, Real source)
    {
        return call(functions[252], id, source);
    }
    
    inline Real ds_map_size(Real id)
    {
        return call(functions[253], id);
    }
    
    inline Real ds_map_empty(Real id)
    {
        return call(functions[254], id);
    }
    
    inline void ds_map_add(Real id, Value key, Value val)
    {
        call(functions[255], id, key, val);
    }
    
    inline void ds_map_replace(Real id, Value key, Value val)
    {
        call(functions[256], id, key, val);
    }
    
    inline void ds_map_delete(Real id, Value key)
    {
        call(functions[257], id, key);
    }
    
    inline Real ds_map_exists(Real id, Value key)
    {
        return call(functions[258], id, key);
    }
    
    inline Value ds_map_find_value(Real id, Value key)
    {
        return call(functions[259], id, key);
    }
    
    inline Value ds_map_find_previous(Real id, Value key)
    {
        return call(functions[260], id, key);
    }
    
    inline Value ds_map_find_next(Real id, Value key)
    {
        return call(functions[261], id, key);
    }
    
    inline Value ds_map_find_first(Real id)
    {
        return call(functions[262], id);
    }
    
    inline Value ds_map_find_last(Real id)
    {
        return call(functions[263], id);
    }
    
    inline String ds_map_write(Real id)
    {
        return call(functions[264], id);
    }
    
    inline void ds_map_read(Real id, String str)
    {
        call(functions[265], id, str);
    }
    
    ///@}
}
#endif
