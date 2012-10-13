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
#ifndef GMAPI_FUNCTIONS_COMPUTING_THINGS_REAL_HPP
#define GMAPI_FUNCTIONS_COMPUTING_THINGS_REAL_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real random(Real x)
    {
        return call(functions[50], x);
    }
    
    inline Real random_range(Real x1, Real x2)
    {
        return call(functions[51], x1, x2);
    }
    
    inline Real irandom(Real x)
    {
        return call(functions[52], x);
    }
    
    inline Real irandom_range(Real x1, Real x2)
    {
        return call(functions[53], x1, x2);
    }
    
    inline Real random_set_seed(Real seed)
    {
        return call(functions[54], seed);
    }
    
    inline Real random_get_seed()
    {
        return call(functions[55]);
    }
    
    inline Real randomize()
    {
        return call(functions[56]);
    }
    
    inline Value choose()
    {
        return call(functions[57]);
    }
    inline Value choose(Value v0)
    {
        return call(functions[57], v0);
    }
    inline Value choose(Value v0, Value v1)
    {
        return call(functions[57], v0, v1);
    }
    inline Value choose(Value v0, Value v1, Value v2)
    {
        return call(functions[57], v0, v1, v2);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3)
    {
        return call(functions[57], v0, v1, v2, v3);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4)
    {
        return call(functions[57], v0, v1, v2, v3, v4);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7, v8);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
    inline Value choose(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14, Value v15)
    {
        return call(functions[57], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);
    }
    
    inline Real abs(Real x)
    {
        return call(functions[58], x);
    }
    
    inline Real sign(Real x)
    {
        return call(functions[59], x);
    }
    
    inline Real round(Real x)
    {
        return call(functions[60], x);
    }
    
    inline Real floor(Real x)
    {
        return call(functions[61], x);
    }
    
    inline Real ceil(Real x)
    {
        return call(functions[62], x);
    }
    
    inline Real frac(Real x)
    {
        return call(functions[63], x);
    }
    
    inline Real sqrt(Real x)
    {
        return call(functions[64], x);
    }
    
    inline Real sqr(Real x)
    {
        return call(functions[65], x);
    }
    
    inline Real power(Real x, Real n)
    {
        return call(functions[66], x, n);
    }
    
    inline Real exp(Real x)
    {
        return call(functions[67], x);
    }
    
    inline Real ln(Real x)
    {
        return call(functions[68], x);
    }
    
    inline Real log2(Real x)
    {
        return call(functions[69], x);
    }
    
    inline Real log10(Real x)
    {
        return call(functions[70], x);
    }
    
    inline Real logn(Real n, Real x)
    {
        return call(functions[71], n, x);
    }
    
    inline Real sin(Real x)
    {
        return call(functions[72], x);
    }
    
    inline Real cos(Real x)
    {
        return call(functions[73], x);
    }
    
    inline Real tan(Real x)
    {
        return call(functions[74], x);
    }
    
    inline Real arcsin(Real x)
    {
        return call(functions[75], x);
    }
    
    inline Real arccos(Real x)
    {
        return call(functions[76], x);
    }
    
    inline Real arctan(Real x)
    {
        return call(functions[77], x);
    }
    
    inline Real arctan2(Real y, Real x)
    {
        return call(functions[78], y, x);
    }
    
    inline Real degtorad(Real x)
    {
        return call(functions[79], x);
    }
    
    inline Real radtodeg(Real x)
    {
        return call(functions[80], x);
    }
    
    inline Real min()
    {
        return call(functions[81]);
    }
    inline Real min(Value v0)
    {
        return call(functions[81], v0);
    }
    inline Real min(Value v0, Value v1)
    {
        return call(functions[81], v0, v1);
    }
    inline Real min(Value v0, Value v1, Value v2)
    {
        return call(functions[81], v0, v1, v2);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3)
    {
        return call(functions[81], v0, v1, v2, v3);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4)
    {
        return call(functions[81], v0, v1, v2, v3, v4);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7, v8);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
    inline Real min(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14, Value v15)
    {
        return call(functions[81], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);
    }
    
    inline Real max()
    {
        return call(functions[82]);
    }
    inline Real max(Value v0)
    {
        return call(functions[82], v0);
    }
    inline Real max(Value v0, Value v1)
    {
        return call(functions[82], v0, v1);
    }
    inline Real max(Value v0, Value v1, Value v2)
    {
        return call(functions[82], v0, v1, v2);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3)
    {
        return call(functions[82], v0, v1, v2, v3);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4)
    {
        return call(functions[82], v0, v1, v2, v3, v4);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7, v8);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
    inline Real max(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14, Value v15)
    {
        return call(functions[82], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);
    }
    
    inline Real mean()
    {
        return call(functions[83]);
    }
    inline Real mean(Value v0)
    {
        return call(functions[83], v0);
    }
    inline Real mean(Value v0, Value v1)
    {
        return call(functions[83], v0, v1);
    }
    inline Real mean(Value v0, Value v1, Value v2)
    {
        return call(functions[83], v0, v1, v2);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3)
    {
        return call(functions[83], v0, v1, v2, v3);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4)
    {
        return call(functions[83], v0, v1, v2, v3, v4);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7, v8);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
    inline Real mean(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14, Value v15)
    {
        return call(functions[83], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);
    }
    
    inline Real median()
    {
        return call(functions[84]);
    }
    inline Real median(Value v0)
    {
        return call(functions[84], v0);
    }
    inline Real median(Value v0, Value v1)
    {
        return call(functions[84], v0, v1);
    }
    inline Real median(Value v0, Value v1, Value v2)
    {
        return call(functions[84], v0, v1, v2);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3)
    {
        return call(functions[84], v0, v1, v2, v3);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4)
    {
        return call(functions[84], v0, v1, v2, v3, v4);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7, v8);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
    inline Real median(Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14, Value v15)
    {
        return call(functions[84], v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15);
    }
    
    inline Real point_distance(Real x1, Real y1, Real x2, Real y2)
    {
        return call(functions[85], x1, y1, x2, y2);
    }
    
    inline Real point_distance_3d(Real x1, Real y1, Real z1, Real x2, Real y2, Real z2)
    {
        return call(functions[86], x1, y1, z1, x2, y2, z2);
    }
    
    inline Real point_direction(Real x1, Real y1, Real x2, Real y2)
    {
        return call(functions[87], x1, y1, x2, y2);
    }
    
    inline Real lengthdir_x(Real len, Real dir)
    {
        return call(functions[88], len, dir);
    }
    
    inline Real lengthdir_y(Real len, Real dir)
    {
        return call(functions[89], len, dir);
    }
    
    inline Real dot_product(Real x1, Real y1, Real x2, Real y2)
    {
        return call(functions[90], x1, y1, x2, y2);
    }
    
    inline Real dot_product_3d(Real x1, Real y1, Real z1, Real x2, Real y2, Real z2)
    {
        return call(functions[91], x1, y1, z1, x2, y2, z2);
    }
    
    inline Real is_real(Value x)
    {
        return call(functions[92], x);
    }
    
    inline Real is_string(Value x)
    {
        return call(functions[93], x);
    }
    
    ///@}
}
#endif
