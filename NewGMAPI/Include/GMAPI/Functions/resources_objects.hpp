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
#ifndef GMAPI_FUNCTIONS_RESOURCES_OBJECTS_HPP
#define GMAPI_FUNCTIONS_RESOURCES_OBJECTS_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real object_exists(Real ind)
    {
        return call(functions[753], ind);
    }
    
    inline String object_get_name(Real ind)
    {
        return call(functions[754], ind);
    }
    
    inline Real object_get_sprite(Real ind)
    {
        return call(functions[755], ind);
    }
    
    inline Real object_get_solid(Real ind)
    {
        return call(functions[756], ind);
    }
    
    inline Real object_get_visible(Real ind)
    {
        return call(functions[757], ind);
    }
    
    inline Real object_get_depth(Real ind)
    {
        return call(functions[758], ind);
    }
    
    inline Real object_get_persistent(Real ind)
    {
        return call(functions[759], ind);
    }
    
    inline Real object_get_mask(Real ind)
    {
        return call(functions[760], ind);
    }
    
    inline Real object_get_parent(Real ind)
    {
        return call(functions[761], ind);
    }
    
    inline Real object_is_ancestor(Real ind1, Real ind2)
    {
        return call(functions[762], ind1, ind2);
    }
    
    inline void object_set_sprite(Real ind, Real spr)
    {
        call(functions[763], ind, spr);
    }
    
    inline void object_set_solid(Real ind, Real solid)
    {
        call(functions[764], ind, solid);
    }
    
    inline void object_set_visible(Real ind, Real vis)
    {
        call(functions[765], ind, vis);
    }
    
    inline void object_set_depth(Real ind, Real depth)
    {
        call(functions[766], ind, depth);
    }
    
    inline void object_set_persistent(Real ind, Real pers)
    {
        call(functions[767], ind, pers);
    }
    
    inline void object_set_mask(Real ind, Real spr)
    {
        call(functions[768], ind, spr);
    }
    
    inline void object_set_parent(Real ind, Real obj)
    {
        call(functions[769], ind, obj);
    }
    
    inline Real object_add()
    {
        return call(functions[770]);
    }
    
    inline void object_delete(Real ind)
    {
        call(functions[771], ind);
    }
    
    inline void object_event_add(Real ind, Real evtype, Real evnumb, String codestr)
    {
        call(functions[772], ind, evtype, evnumb, codestr);
    }
    
    inline void object_event_clear(Real ind, Real evtype, Real evnumb)
    {
        call(functions[773], ind, evtype, evnumb);
    }
    
    ///@}
}
#endif
