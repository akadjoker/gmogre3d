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
#ifndef GMAPI_FUNCTIONS_GRAPHICS_WINDOW_HPP
#define GMAPI_FUNCTIONS_GRAPHICS_WINDOW_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void window_set_visible(Real visible)
    {
        call(functions[574], visible);
    }
    
    inline Real window_get_visible()
    {
        return call(functions[575]);
    }
    
    inline void window_set_fullscreen(Real full)
    {
        call(functions[576], full);
    }
    
    inline Real window_get_fullscreen()
    {
        return call(functions[577]);
    }
    
    inline void window_set_showborder(Real show)
    {
        call(functions[578], show);
    }
    
    inline Real window_get_showborder()
    {
        return call(functions[579]);
    }
    
    inline void window_set_showicons(Real show)
    {
        call(functions[580], show);
    }
    
    inline Real window_get_showicons()
    {
        return call(functions[581]);
    }
    
    inline void window_set_stayontop(Real stay)
    {
        call(functions[582], stay);
    }
    
    inline Real window_get_stayontop()
    {
        return call(functions[583]);
    }
    
    inline void window_set_sizeable(Real sizeable)
    {
        call(functions[584], sizeable);
    }
    
    inline Real window_get_sizeable()
    {
        return call(functions[585]);
    }
    
    inline void window_set_caption(String caption)
    {
        call(functions[586], caption);
    }
    
    inline String window_get_caption()
    {
        return call(functions[587]);
    }
    
    inline void window_set_cursor(Real curs)
    {
        call(functions[588], curs);
    }
    
    inline Real window_get_cursor()
    {
        return call(functions[589]);
    }
    
    inline void window_set_color(Real color)
    {
        call(functions[590], color);
    }
    
    inline Real window_get_color()
    {
        return call(functions[591]);
    }
    
    inline void window_set_region_scale(Real scale, Real adaptwindow)
    {
        call(functions[592], scale, adaptwindow);
    }
    
    inline Real window_get_region_scale()
    {
        return call(functions[593]);
    }
    
    inline void window_set_position(Real x, Real y)
    {
        call(functions[594], x, y);
    }
    
    inline void window_set_size(Real w, Real h)
    {
        call(functions[595], w, h);
    }
    
    inline void window_set_rectangle(Real x, Real y, Real w, Real h)
    {
        call(functions[596], x, y, w, h);
    }
    
    inline void window_center()
    {
        call(functions[597]);
    }
    
    inline void window_default()
    {
        call(functions[598]);
    }
    
    inline Real window_get_x()
    {
        return call(functions[599]);
    }
    
    inline Real window_get_y()
    {
        return call(functions[600]);
    }
    
    inline Real window_get_width()
    {
        return call(functions[601]);
    }
    
    inline Real window_get_height()
    {
        return call(functions[602]);
    }
    
    inline Real window_mouse_get_x()
    {
        return call(functions[603]);
    }
    
    inline Real window_mouse_get_y()
    {
        return call(functions[604]);
    }
    
    inline void window_mouse_set(Real x, Real y)
    {
        call(functions[605], x, y);
    }
    
    ///@}
}
#endif
