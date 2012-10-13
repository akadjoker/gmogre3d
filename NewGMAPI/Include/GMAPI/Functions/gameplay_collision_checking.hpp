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
#ifndef GMAPI_FUNCTIONS_GAMEPLAY_COLLISION_CHECKING_HPP
#define GMAPI_FUNCTIONS_GAMEPLAY_COLLISION_CHECKING_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real collision_point(Real x, Real y, Real obj, Real prec, Real notme)
    {
        return call(functions[305], x, y, obj, prec, notme);
    }
    
    inline Real collision_rectangle(Real x1, Real y1, Real x2, Real y2, Real obj, Real prec, Real notme)
    {
        return call(functions[306], x1, y1, x2, y2, obj, prec, notme);
    }
    
    inline Real collision_circle(Real xc, Real yc, Real radius, Real obj, Real prec, Real notme)
    {
        return call(functions[307], xc, yc, radius, obj, prec, notme);
    }
    
    inline Real collision_ellipse(Real x1, Real y1, Real x2, Real y2, Real obj, Real prec, Real notme)
    {
        return call(functions[308], x1, y1, x2, y2, obj, prec, notme);
    }
    
    inline Real collision_line(Real x1, Real y1, Real x2, Real y2, Real obj, Real prec, Real notme)
    {
        return call(functions[309], x1, y1, x2, y2, obj, prec, notme);
    }
    
    ///@}
}
#endif
