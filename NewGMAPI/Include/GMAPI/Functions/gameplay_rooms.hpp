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
#ifndef GMAPI_FUNCTIONS_GAMEPLAY_ROOMS_HPP
#define GMAPI_FUNCTIONS_GAMEPLAY_ROOMS_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void room_goto(Real numb)
    {
        call(functions[390], numb);
    }
    
    inline void room_goto_previous()
    {
        call(functions[391]);
    }
    
    inline void room_goto_next()
    {
        call(functions[392]);
    }
    
    inline void room_restart()
    {
        call(functions[393]);
    }
    
    inline Real room_previous(Real numb)
    {
        return call(functions[394], numb);
    }
    
    inline Real room_next(Real numb)
    {
        return call(functions[395], numb);
    }
    
    inline void game_end()
    {
        call(functions[396]);
    }
    
    inline void game_restart()
    {
        call(functions[397]);
    }
    
    inline void game_save(String string)
    {
        call(functions[398], string);
    }
    
    inline void game_load(String string)
    {
        call(functions[399], string);
    }
    
    inline void transition_define(Real kind, String name)
    {
        call(functions[400], kind, name);
    }
    
    inline Real transition_exists(Real kind)
    {
        return call(functions[401], kind);
    }
    
    ///@}
}
#endif
