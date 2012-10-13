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
#ifndef GMAPI_FUNCTIONS_DS_QUEUE_HPP
#define GMAPI_FUNCTIONS_DS_QUEUE_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real ds_queue_create()
    {
        return call(functions[282]);
    }
    
    inline void ds_queue_destroy(Real id)
    {
        call(functions[283], id);
    }
    
    inline void ds_queue_clear(Real id)
    {
        call(functions[284], id);
    }
    
    inline Real ds_queue_copy(Real id, Real source)
    {
        return call(functions[285], id, source);
    }
    
    inline Real ds_queue_size(Real id)
    {
        return call(functions[286], id);
    }
    
    inline Real ds_queue_empty(Real id)
    {
        return call(functions[287], id);
    }
    
    inline void ds_queue_enqueue(Real id, Value val)
    {
        call(functions[288], id, val);
    }
    
    inline Value ds_queue_dequeue(Real id)
    {
        return call(functions[289], id);
    }
    
    inline Value ds_queue_head(Real id)
    {
        return call(functions[290], id);
    }
    
    inline Value ds_queue_tail(Real id)
    {
        return call(functions[291], id);
    }
    
    inline String ds_queue_write(Real id)
    {
        return call(functions[292], id);
    }
    
    inline void ds_queue_read(Real id, String str)
    {
        call(functions[293], id, str);
    }
    
    ///@}
}
#endif
