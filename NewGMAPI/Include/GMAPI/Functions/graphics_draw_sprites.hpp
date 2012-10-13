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
#ifndef GMAPI_FUNCTIONS_GRAPHICS_DRAW_SPRITES_HPP
#define GMAPI_FUNCTIONS_GRAPHICS_DRAW_SPRITES_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void draw_sprite(Real sprite, Real subimg, Real x, Real y)
    {
        call(functions[482], sprite, subimg, x, y);
    }
    
    inline void draw_sprite_stretched(Real sprite, Real subimg, Real x, Real y, Real w, Real h)
    {
        call(functions[483], sprite, subimg, x, y, w, h);
    }
    
    inline void draw_sprite_tiled(Real sprite, Real subimg, Real x, Real y)
    {
        call(functions[484], sprite, subimg, x, y);
    }
    
    inline void draw_sprite_part(Real sprite, Real subimg, Real left, Real top, Real width, Real height, Real x, Real y)
    {
        call(functions[485], sprite, subimg, left, top, width, height, x, y);
    }
    
    inline void draw_sprite_ext(Real sprite, Real subimg, Real x, Real y, Real xscale, Real yscale, Real rot, Real color, Real alpha)
    {
        call(functions[486], sprite, subimg, x, y, xscale, yscale, rot, color, alpha);
    }
    
    inline void draw_sprite_stretched_ext(Real sprite, Real subimg, Real x, Real y, Real w, Real h, Real color, Real alpha)
    {
        call(functions[487], sprite, subimg, x, y, w, h, color, alpha);
    }
    
    inline void draw_sprite_tiled_ext(Real sprite, Real subimg, Real x, Real y, Real xscale, Real yscale, Real color, Real alpha)
    {
        call(functions[488], sprite, subimg, x, y, xscale, yscale, color, alpha);
    }
    
    inline void draw_sprite_part_ext(Real sprite, Real subimg, Real left, Real top, Real width, Real height, Real x, Real y, Real xscale, Real yscale, Real color, Real alpha)
    {
        call(functions[489], sprite, subimg, left, top, width, height, x, y, xscale, yscale, color, alpha);
    }
    
    inline void draw_sprite_general(Real sprite, Real subimg, Real left, Real top, Real width, Real height, Real x, Real y, Real xscale, Real yscale, Real rot, Real c1, Real c2, Real c3, Real c4, Real alpha)
    {
        call(functions[490], sprite, subimg, left, top, width, height, x, y, xscale, yscale, rot, c1, c2, c3, c4, alpha);
    }
    
    inline void draw_self()
    {
        call(functions[491]);
    }
    
    ///@}
}
#endif
