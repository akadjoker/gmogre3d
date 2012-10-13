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
#ifndef GMAPI_FUNCTIONS_GRAPHICS_TILES_HPP
#define GMAPI_FUNCTIONS_GRAPHICS_TILES_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real tile_add(Real background, Real left, Real top, Real width, Real height, Real x, Real y, Real depth)
    {
        return call(functions[534], background, left, top, width, height, x, y, depth);
    }
    
    inline void tile_delete(Real id)
    {
        call(functions[535], id);
    }
    
    inline Real tile_exists(Real id)
    {
        return call(functions[536], id);
    }
    
    inline Real tile_get_x(Real id)
    {
        return call(functions[537], id);
    }
    
    inline Real tile_get_y(Real id)
    {
        return call(functions[538], id);
    }
    
    inline Real tile_get_left(Real id)
    {
        return call(functions[539], id);
    }
    
    inline Real tile_get_top(Real id)
    {
        return call(functions[540], id);
    }
    
    inline Real tile_get_width(Real id)
    {
        return call(functions[541], id);
    }
    
    inline Real tile_get_height(Real id)
    {
        return call(functions[542], id);
    }
    
    inline Real tile_get_depth(Real id)
    {
        return call(functions[543], id);
    }
    
    inline Real tile_get_visible(Real id)
    {
        return call(functions[544], id);
    }
    
    inline Real tile_get_xscale(Real id)
    {
        return call(functions[545], id);
    }
    
    inline Real tile_get_yscale(Real id)
    {
        return call(functions[546], id);
    }
    
    inline Real tile_get_background(Real id)
    {
        return call(functions[547], id);
    }
    
    inline Real tile_get_blend(Real id)
    {
        return call(functions[548], id);
    }
    
    inline Real tile_get_alpha(Real id)
    {
        return call(functions[549], id);
    }
    
    inline void tile_set_position(Real id, Real x, Real y)
    {
        call(functions[550], id, x, y);
    }
    
    inline void tile_set_region(Real id, Real left, Real top, Real width, Real height)
    {
        call(functions[551], id, left, top, width, height);
    }
    
    inline void tile_set_background(Real id, Real background)
    {
        call(functions[552], id, background);
    }
    
    inline void tile_set_visible(Real id, Real visible)
    {
        call(functions[553], id, visible);
    }
    
    inline void tile_set_depth(Real id, Real depth)
    {
        call(functions[554], id, depth);
    }
    
    inline void tile_set_scale(Real id, Real xscale, Real yscale)
    {
        call(functions[555], id, xscale, yscale);
    }
    
    inline void tile_set_blend(Real id, Real color)
    {
        call(functions[556], id, color);
    }
    
    inline void tile_set_alpha(Real id, Real alpha)
    {
        call(functions[557], id, alpha);
    }
    
    inline void tile_layer_hide(Real depth)
    {
        call(functions[558], depth);
    }
    
    inline void tile_layer_show(Real depth)
    {
        call(functions[559], depth);
    }
    
    inline void tile_layer_delete(Real depth)
    {
        call(functions[560], depth);
    }
    
    inline void tile_layer_shift(Real depth, Real x, Real y)
    {
        call(functions[561], depth, x, y);
    }
    
    inline void tile_layer_find(Real depth, Real x, Real y)
    {
        call(functions[562], depth, x, y);
    }
    
    inline void tile_layer_delete_at(Real depth, Real x, Real y)
    {
        call(functions[563], depth, x, y);
    }
    
    inline void tile_layer_depth(Real depth, Real newdepth)
    {
        call(functions[564], depth, newdepth);
    }
    
    ///@}
}
#endif
