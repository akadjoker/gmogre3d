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
#ifndef GMAPI_FUNCTIONS_SOUND_CD_HPP
#define GMAPI_FUNCTIONS_SOUND_CD_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void cd_init()
    {
        call(functions[890]);
    }
    
    inline Real cd_present()
    {
        return call(functions[891]);
    }
    
    inline Real cd_number()
    {
        return call(functions[892]);
    }
    
    inline Real cd_playing()
    {
        return call(functions[893]);
    }
    
    inline Real cd_paused()
    {
        return call(functions[894]);
    }
    
    inline Real cd_track()
    {
        return call(functions[895]);
    }
    
    inline Real cd_length()
    {
        return call(functions[896]);
    }
    
    inline Real cd_track_length(Real n)
    {
        return call(functions[897], n);
    }
    
    inline Real cd_position()
    {
        return call(functions[898]);
    }
    
    inline Real cd_track_position()
    {
        return call(functions[899]);
    }
    
    inline void cd_play(Real first, Real last)
    {
        call(functions[900], first, last);
    }
    
    inline void cd_stop()
    {
        call(functions[901]);
    }
    
    inline void cd_pause()
    {
        call(functions[902]);
    }
    
    inline void cd_resume()
    {
        call(functions[903]);
    }
    
    inline void cd_set_position(Real pos)
    {
        call(functions[904], pos);
    }
    
    inline void cd_set_track_position(Real pos)
    {
        call(functions[905], pos);
    }
    
    inline void cd_open_door()
    {
        call(functions[906]);
    }
    
    inline void cd_close_door()
    {
        call(functions[907]);
    }
    
    inline void MCI_command(String str)
    {
        call(functions[908], str);
    }
    
    ///@}
}
#endif
