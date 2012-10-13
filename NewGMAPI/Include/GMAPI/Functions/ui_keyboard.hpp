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
#ifndef GMAPI_FUNCTIONS_UI_KEYBOARD_HPP
#define GMAPI_FUNCTIONS_UI_KEYBOARD_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void keyboard_set_map(Real key1, Real key2)
    {
        call(functions[954], key1, key2);
    }
    
    inline Real keyboard_get_map(Real key)
    {
        return call(functions[955], key);
    }
    
    inline void keyboard_unset_map()
    {
        call(functions[956]);
    }
    
    inline Real keyboard_check(Real key)
    {
        return call(functions[957], key);
    }
    
    inline Real keyboard_check_pressed(Real key)
    {
        return call(functions[958], key);
    }
    
    inline Real keyboard_check_released(Real key)
    {
        return call(functions[959], key);
    }
    
    inline Real keyboard_check_direct(Real key)
    {
        return call(functions[960], key);
    }
    
    inline Real keyboard_get_numlock()
    {
        return call(functions[961]);
    }
    
    inline void keyboard_set_numlock(Real on)
    {
        call(functions[962], on);
    }
    
    inline Real keyboard_key_press(Real key)
    {
        return call(functions[963], key);
    }
    
    inline Real keyboard_key_release(Real key)
    {
        return call(functions[964], key);
    }
    
    inline void keyboard_clear(Real key)
    {
        call(functions[965], key);
    }
    
    inline void keyboard_wait()
    {
        call(functions[966]);
    }
    
    ///@}
}
#endif
