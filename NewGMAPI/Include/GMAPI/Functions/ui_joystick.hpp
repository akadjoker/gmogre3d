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
#ifndef GMAPI_FUNCTIONS_UI_JOYSTICK_HPP
#define GMAPI_FUNCTIONS_UI_JOYSTICK_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real joystick_exists(Real id)
    {
        return call(functions[940], id);
    }
    
    inline String joystick_name(Real id)
    {
        return call(functions[941], id);
    }
    
    inline Real joystick_axes(Real id)
    {
        return call(functions[942], id);
    }
    
    inline Real joystick_buttons(Real id)
    {
        return call(functions[943], id);
    }
    
    inline Real joystick_has_pov(Real id)
    {
        return call(functions[944], id);
    }
    
    inline Real joystick_direction(Real id)
    {
        return call(functions[945], id);
    }
    
    inline Real joystick_check_button(Real id, Real numb)
    {
        return call(functions[946], id, numb);
    }
    
    inline Real joystick_xpos(Real id)
    {
        return call(functions[947], id);
    }
    
    inline Real joystick_ypos(Real id)
    {
        return call(functions[948], id);
    }
    
    inline Real joystick_zpos(Real id)
    {
        return call(functions[949], id);
    }
    
    inline Real joystick_rpos(Real id)
    {
        return call(functions[950], id);
    }
    
    inline Real joystick_upos(Real id)
    {
        return call(functions[951], id);
    }
    
    inline Real joystick_vpos(Real id)
    {
        return call(functions[952], id);
    }
    
    inline Real joystick_pov(Real id)
    {
        return call(functions[953], id);
    }
    
    ///@}
}
#endif
