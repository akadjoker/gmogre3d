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
#ifndef GMAPI_FUNCTIONS_GRAPHICS_DISPLAY_HPP
#define GMAPI_FUNCTIONS_GRAPHICS_DISPLAY_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real display_get_width()
    {
        return call(functions[403]);
    }
    
    inline Real display_get_height()
    {
        return call(functions[404]);
    }
    
    inline Real display_get_colordepth()
    {
        return call(functions[405]);
    }
    
    inline Real display_get_frequency()
    {
        return call(functions[406]);
    }
    
    inline void display_set_size(Real w, Real h)
    {
        call(functions[407], w, h);
    }
    
    inline void display_set_colordepth(Real coldepth)
    {
        call(functions[408], coldepth);
    }
    
    inline void display_set_frequency(Real frequency)
    {
        call(functions[409], frequency);
    }
    
    inline void display_set_all(Real w, Real h, Real frequency, Real coldepth)
    {
        call(functions[410], w, h, frequency, coldepth);
    }
    
    inline Real display_test_all(Real w, Real h, Real frequency, Real coldepth)
    {
        return call(functions[411], w, h, frequency, coldepth);
    }
    
    inline void display_reset(Real AA)
    {
        call(functions[412], AA);
    }
    
    inline Real display_mouse_get_x()
    {
        return call(functions[413]);
    }
    
    inline Real display_mouse_get_y()
    {
        return call(functions[414]);
    }
    
    inline void display_mouse_set(Real x, Real y)
    {
        call(functions[415], x, y);
    }
    
    ///@}
}
#endif
