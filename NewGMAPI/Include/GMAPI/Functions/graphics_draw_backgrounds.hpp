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
#ifndef GMAPI_FUNCTIONS_GRAPHICS_DRAW_BACKGROUNDS_HPP
#define GMAPI_FUNCTIONS_GRAPHICS_DRAW_BACKGROUNDS_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void draw_background(Real back, Real x, Real y)
    {
        call(functions[442], back, x, y);
    }
    
    inline void draw_background_stretched(Real back, Real x, Real y, Real w, Real h)
    {
        call(functions[443], back, x, y, w, h);
    }
    
    inline void draw_background_tiled(Real back, Real x, Real y)
    {
        call(functions[444], back, x, y);
    }
    
    inline void draw_background_part(Real back, Real left, Real top, Real width, Real height, Real x, Real y)
    {
        call(functions[445], back, left, top, width, height, x, y);
    }
    
    inline void draw_background_ext(Real back, Real x, Real y, Real xscale, Real yscale, Real rot, Real color, Real alpha)
    {
        call(functions[446], back, x, y, xscale, yscale, rot, color, alpha);
    }
    
    inline void draw_background_stretched_ext(Real back, Real x, Real y, Real w, Real h, Real color, Real alpha)
    {
        call(functions[447], back, x, y, w, h, color, alpha);
    }
    
    inline void draw_background_tiled_ext(Real back, Real x, Real y, Real xscale, Real yscale, Real color, Real alpha)
    {
        call(functions[448], back, x, y, xscale, yscale, color, alpha);
    }
    
    inline void draw_background_part_ext(Real back, Real left, Real top, Real width, Real height, Real x, Real y, Real xscale, Real yscale, Real color, Real alpha)
    {
        call(functions[449], back, left, top, width, height, x, y, xscale, yscale, color, alpha);
    }
    
    inline void draw_background_general(Real back, Real left, Real top, Real width, Real height, Real x, Real y, Real xscale, Real yscale, Real rot, Real c1, Real c2, Real c3, Real c4, Real alpha)
    {
        call(functions[450], back, left, top, width, height, x, y, xscale, yscale, rot, c1, c2, c3, c4, alpha);
    }
    
    ///@}
}
#endif
