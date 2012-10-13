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
#ifndef GMAPI_FUNCTIONS_UI_MOUSE_HPP
#define GMAPI_FUNCTIONS_UI_MOUSE_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real mouse_check_button(Real numb)
    {
        return call(functions[967], numb);
    }
    
    inline Real mouse_check_button_pressed(Real numb)
    {
        return call(functions[968], numb);
    }
    
    inline Real mouse_check_button_released(Real numb)
    {
        return call(functions[969], numb);
    }
    
    inline Real mouse_wheel_up()
    {
        return call(functions[970]);
    }
    
    inline Real mouse_wheel_down()
    {
        return call(functions[971]);
    }
    
    inline void mouse_clear(Real button)
    {
        call(functions[972], button);
    }
    
    inline void mouse_wait()
    {
        call(functions[973]);
    }
    
    ///@}
}
#endif
