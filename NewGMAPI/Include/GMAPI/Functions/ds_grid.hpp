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
#ifndef GMAPI_FUNCTIONS_DS_GRID_HPP
#define GMAPI_FUNCTIONS_DS_GRID_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real ds_grid_create(Real w, Real h)
    {
        return call(functions[196], w, h);
    }
    
    inline void ds_grid_destroy(Real id)
    {
        call(functions[197], id);
    }
    
    inline void ds_grid_copy(Real id, Real source)
    {
        call(functions[198], id, source);
    }
    
    inline void ds_grid_resize(Real id, Real w, Real h)
    {
        call(functions[199], id, w, h);
    }
    
    inline Real ds_grid_width(Real id)
    {
        return call(functions[200], id);
    }
    
    inline Real ds_grid_height(Real id)
    {
        return call(functions[201], id);
    }
    
    inline void ds_grid_clear(Real id, Value val)
    {
        call(functions[202], id, val);
    }
    
    inline void ds_grid_set(Real id, Real x, Real y, Value val)
    {
        call(functions[203], id, x, y, val);
    }
    
    inline void ds_grid_add(Real id, Real x, Real y, Value val)
    {
        call(functions[204], id, x, y, val);
    }
    
    inline void ds_grid_multiply(Real id, Real x, Real y, Real val)
    {
        call(functions[205], id, x, y, val);
    }
    
    inline void ds_grid_set_region(Real id, Real x1, Real y1, Real x2, Real y2, Value val)
    {
        call(functions[206], id, x1, y1, x2, y2, val);
    }
    
    inline void ds_grid_add_region(Real id, Real x1, Real y1, Real x2, Real y2, Value val)
    {
        call(functions[207], id, x1, y1, x2, y2, val);
    }
    
    inline void ds_grid_multiply_region(Real id, Real x1, Real y1, Real x2, Real y2, Real val)
    {
        call(functions[208], id, x1, y1, x2, y2, val);
    }
    
    inline void ds_grid_set_disk(Real id, Real xm, Real ym, Real r, Value val)
    {
        call(functions[209], id, xm, ym, r, val);
    }
    
    inline void ds_grid_add_disk(Real id, Real xm, Real ym, Real r, Value val)
    {
        call(functions[210], id, xm, ym, r, val);
    }
    
    inline void ds_grid_multiply_disk(Real id, Real xm, Real ym, Real r, Real val)
    {
        call(functions[211], id, xm, ym, r, val);
    }
    
    inline void ds_grid_set_grid_region(Real id, Real source, Real x1, Real y1, Real x2, Real y2, Real xpos, Real ypos)
    {
        call(functions[212], id, source, x1, y1, x2, y2, xpos, ypos);
    }
    
    inline void ds_grid_add_grid_region(Real id, Real source, Real x1, Real y1, Real x2, Real y2, Real xpos, Real ypos)
    {
        call(functions[213], id, source, x1, y1, x2, y2, xpos, ypos);
    }
    
    inline void ds_grid_multiply_grid_region(Real id, Real source, Real x1, Real y1, Real x2, Real y2, Real xpos, Real ypos)
    {
        call(functions[214], id, source, x1, y1, x2, y2, xpos, ypos);
    }
    
    inline Value ds_grid_get(Real id, Real x, Real y)
    {
        return call(functions[215], id, x, y);
    }
    
    inline Real ds_grid_get_sum(Real id, Real x1, Real y1, Real x2, Real y2)
    {
        return call(functions[216], id, x1, y1, x2, y2);
    }
    
    inline Real ds_grid_get_max(Real id, Real x1, Real y1, Real x2, Real y2)
    {
        return call(functions[217], id, x1, y1, x2, y2);
    }
    
    inline Real ds_grid_get_min(Real id, Real x1, Real y1, Real x2, Real y2)
    {
        return call(functions[218], id, x1, y1, x2, y2);
    }
    
    inline Real ds_grid_get_mean(Real id, Real x1, Real y1, Real x2, Real y2)
    {
        return call(functions[219], id, x1, y1, x2, y2);
    }
    
    inline Real ds_grid_get_disk_sum(Real id, Real xm, Real ym, Real r)
    {
        return call(functions[220], id, xm, ym, r);
    }
    
    inline Real ds_grid_get_disk_min(Real id, Real xm, Real ym, Real r)
    {
        return call(functions[221], id, xm, ym, r);
    }
    
    inline Real ds_grid_get_disk_max(Real id, Real xm, Real ym, Real r)
    {
        return call(functions[222], id, xm, ym, r);
    }
    
    inline Real ds_grid_get_disk_mean(Real id, Real xm, Real ym, Real r)
    {
        return call(functions[223], id, xm, ym, r);
    }
    
    inline Real ds_grid_value_exists(Real id, Real x1, Real y1, Real x2, Real y2, Value val)
    {
        return call(functions[224], id, x1, y1, x2, y2, val);
    }
    
    inline Real ds_grid_value_x(Real id, Real x1, Real y1, Real x2, Real y2, Value val)
    {
        return call(functions[225], id, x1, y1, x2, y2, val);
    }
    
    inline Real ds_grid_value_y(Real id, Real x1, Real y1, Real x2, Real y2, Value val)
    {
        return call(functions[226], id, x1, y1, x2, y2, val);
    }
    
    inline Real ds_grid_value_disk_exists(Real id, Real xm, Real ym, Real r, Value val)
    {
        return call(functions[227], id, xm, ym, r, val);
    }
    
    inline Real ds_grid_value_disk_x(Real id, Real xm, Real ym, Real r, Value val)
    {
        return call(functions[228], id, xm, ym, r, val);
    }
    
    inline Real ds_grid_value_disk_y(Real id, Real xm, Real ym, Real r, Value val)
    {
        return call(functions[229], id, xm, ym, r, val);
    }
    
    inline void ds_grid_shuffle(Real id)
    {
        call(functions[230], id);
    }
    
    inline String ds_grid_write(Real id)
    {
        return call(functions[231], id);
    }
    
    inline void ds_grid_read(Real id, String str)
    {
        call(functions[232], id, str);
    }
    
    ///@}
}
#endif
