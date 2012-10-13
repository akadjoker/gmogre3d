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
#ifndef GMAPI_FUNCTIONS_GAMEPLAY_DEACTIVATING_INSTANCES_HPP
#define GMAPI_FUNCTIONS_GAMEPLAY_DEACTIVATING_INSTANCES_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void instance_deactivate_all(Real notme)
    {
        call(functions[310], notme);
    }
    
    inline void instance_deactivate_object(Real obj)
    {
        call(functions[311], obj);
    }
    
    inline void instance_deactivate_region(Real left, Real top, Real width, Real height, Real inside, Real notme)
    {
        call(functions[312], left, top, width, height, inside, notme);
    }
    
    inline void instance_activate_all()
    {
        call(functions[313]);
    }
    
    inline void instance_activate_object(Real obj)
    {
        call(functions[314], obj);
    }
    
    inline void instance_activate_region(Real left, Real top, Real width, Real height, Real inside)
    {
        call(functions[315], left, top, width, height, inside);
    }
    
    ///@}
}
#endif
