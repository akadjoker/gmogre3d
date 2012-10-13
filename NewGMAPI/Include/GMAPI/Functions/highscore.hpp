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
#ifndef GMAPI_FUNCTIONS_HIGHSCORE_HPP
#define GMAPI_FUNCTIONS_HIGHSCORE_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void highscore_show(Real numb)
    {
        call(functions[606], numb);
    }
    
    inline void highscore_set_background(Real back)
    {
        call(functions[607], back);
    }
    
    inline void highscore_set_border(Real show)
    {
        call(functions[608], show);
    }
    
    inline void highscore_set_font(String name, Real size, Real style)
    {
        call(functions[609], name, size, style);
    }
    
    inline void highscore_set_colors(Real back, Real newentry, Real otherentires)
    {
        call(functions[610], back, newentry, otherentires);
    }
    
    inline void highscore_set_strings(String caption, String nobody, String escape)
    {
        call(functions[611], caption, nobody, escape);
    }
    
    inline void highscore_show_ext(Real numb, Real back, Real border, Real col1, Real col2, String name, Real size)
    {
        call(functions[612], numb, back, border, col1, col2, name, size);
    }
    
    inline void highscore_clear()
    {
        call(functions[613]);
    }
    
    inline void highscore_add(String str, Real numb)
    {
        call(functions[614], str, numb);
    }
    
    inline void highscore_add_current()
    {
        call(functions[615]);
    }
    
    inline Real highscore_value(Real place)
    {
        return call(functions[616], place);
    }
    
    inline String highscore_name(Real place)
    {
        return call(functions[617], place);
    }
    
    inline void draw_highscore(Real x1, Real y1, Real x2, Real y2)
    {
        call(functions[618], x1, y1, x2, y2);
    }
    
    ///@}
}
#endif
