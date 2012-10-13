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
#ifndef GMAPI_FUNCTIONS_RESOURCES_SPRITES_HPP
#define GMAPI_FUNCTIONS_RESOURCES_SPRITES_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real sprite_exists(Real ind)
    {
        return call(functions[840], ind);
    }
    
    inline String sprite_get_name(Real ind)
    {
        return call(functions[841], ind);
    }
    
    inline Real sprite_get_number(Real ind)
    {
        return call(functions[842], ind);
    }
    
    inline Real sprite_get_width(Real ind)
    {
        return call(functions[843], ind);
    }
    
    inline Real sprite_get_height(Real ind)
    {
        return call(functions[844], ind);
    }
    
    inline Real sprite_get_xoffset(Real ind)
    {
        return call(functions[845], ind);
    }
    
    inline Real sprite_get_yoffset(Real ind)
    {
        return call(functions[846], ind);
    }
    
    inline Real sprite_get_bbox_left(Real ind)
    {
        return call(functions[847], ind);
    }
    
    inline Real sprite_get_bbox_right(Real ind)
    {
        return call(functions[848], ind);
    }
    
    inline Real sprite_get_bbox_top(Real ind)
    {
        return call(functions[849], ind);
    }
    
    inline Real sprite_get_bbox_bottom(Real ind)
    {
        return call(functions[850], ind);
    }
    
    inline void sprite_save(Real ind, Real subimg, String fname)
    {
        call(functions[851], ind, subimg, fname);
    }
    
    inline void sprite_save_strip(Real ind, String fname)
    {
        call(functions[852], ind, fname);
    }
    
    inline void sprite_set_offset(Real ind, Real xoff, Real yoff)
    {
        call(functions[853], ind, xoff, yoff);
    }
    
    inline Real sprite_duplicate(Real ind)
    {
        return call(functions[854], ind);
    }
    
    inline void sprite_assign(Real ind, Real spr)
    {
        call(functions[855], ind, spr);
    }
    
    inline void sprite_merge(Real ind1, Real ind2)
    {
        call(functions[856], ind1, ind2);
    }
    
    inline Real sprite_add(String fname, Real imgnumb, Real removeback, Real smooth, Real xorig, Real yorig)
    {
        return call(functions[857], fname, imgnumb, removeback, smooth, xorig, yorig);
    }
    
    inline Real sprite_replace(Real ind, String fname, Real imgnumb, Real removeback, Real smooth, Real xorig, Real yorig)
    {
        return call(functions[858], ind, fname, imgnumb, removeback, smooth, xorig, yorig);
    }
    
    inline Real sprite_add_sprite(String fname)
    {
        return call(functions[859], fname);
    }
    
    inline Real sprite_replace_sprite(Real ind, String fname)
    {
        return call(functions[860], ind, fname);
    }
    
    inline Real sprite_create_from_screen(Real x, Real y, Real w, Real h, Real removeback, Real smooth, Real xorig, Real yorig)
    {
        return call(functions[861], x, y, w, h, removeback, smooth, xorig, yorig);
    }
    
    inline void sprite_add_from_screen(Real ind, Real x, Real y, Real w, Real h, Real removeback, Real smooth)
    {
        call(functions[862], ind, x, y, w, h, removeback, smooth);
    }
    
    inline Real sprite_create_from_surface(Real id, Real x, Real y, Real w, Real h, Real removeback, Real smooth, Real xorig, Real yorig)
    {
        return call(functions[863], id, x, y, w, h, removeback, smooth, xorig, yorig);
    }
    
    inline void sprite_add_from_surface(Real ind, Real id, Real x, Real y, Real w, Real h, Real removeback, Real smooth)
    {
        call(functions[864], ind, id, x, y, w, h, removeback, smooth);
    }
    
    inline void sprite_delete(Real ind)
    {
        call(functions[865], ind);
    }
    
    inline void sprite_set_alpha_from_sprite(Real ind, Real spr)
    {
        call(functions[866], ind, spr);
    }
    
    inline void sprite_collision_mask(Real ind, Real sepmasks, Real bboxmode, Real bbleft, Real bbtop, Real bbright, Real bbbottom, Real kind, Real tolerance)
    {
        call(functions[867], ind, sepmasks, bboxmode, bbleft, bbtop, bbright, bbbottom, kind, tolerance);
    }
    
    ///@}
}
#endif
