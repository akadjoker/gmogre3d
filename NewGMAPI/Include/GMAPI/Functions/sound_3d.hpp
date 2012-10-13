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
#ifndef GMAPI_FUNCTIONS_SOUND_3D_HPP
#define GMAPI_FUNCTIONS_SOUND_3D_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void sound_3d_set_sound_position(Real snd, Real x, Real y, Real z)
    {
        call(functions[875], snd, x, y, z);
    }
    
    inline void sound_3d_set_sound_velocity(Real snd, Real x, Real y, Real z)
    {
        call(functions[876], snd, x, y, z);
    }
    
    inline void sound_3d_set_sound_distance(Real snd, Real mindist, Real maxdist)
    {
        call(functions[877], snd, mindist, maxdist);
    }
    
    inline void sound_3d_set_sound_cone(Real snd, Real x, Real y, Real z, Real anglein, Real angleout, Real voloutside)
    {
        call(functions[878], snd, x, y, z, anglein, angleout, voloutside);
    }
    
    ///@}
}
#endif
