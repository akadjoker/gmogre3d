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

#ifndef GMAPI_CONSTANTS_HPP
#define GMAPI_CONSTANTS_HPP
#include "Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    static const Real all   = -1.;
    enum EventType
    {
        ev_create       =  0,
        ev_destroy      =  1,
        ev_step         =  2,
        ev_alarm        =  3,
        ev_keyboard     =  4,
        ev_mouse        =  5,
        ev_collision    =  6,
        ev_other        =  7,
        ev_draw         =  8,
        ev_keypress     =  9,
        ev_keyrelease   = 10,
        ev_trigger      = 11,
    };
    enum EventMouse
    {
        ev_left_button              =  0,
        ev_right_button             =  1,
        ev_middle_button            =  2,
        ev_no_button                =  3,
        ev_left_press               =  4,
        ev_right_press              =  5,
        ev_middle_press             =  6,
        ev_left_release             =  7,
        ev_right_release            =  8,
        ev_middle_release           =  9,
        ev_mouse_enter              = 10,
        ev_mouse_leave              = 11,
        ev_mouse_wheel_up           = 60,
        ev_mouse_wheel_down         = 61,
        ev_global_left_button       = 50,
        ev_global_right_button      = 51,
        ev_global_middle_button     = 52,
        ev_global_left_press        = 53,
        ev_global_right_press       = 54,
        ev_global_middle_press      = 55,
        ev_global_left_release      = 56,
        ev_global_right_release     = 57,
        ev_global_middle_release    = 58,
        ev_joystick1_left           = 16,
        ev_joystick1_right          = 17,
        ev_joystick1_up             = 18,
        ev_joystick1_down           = 19,
        ev_joystick1_button1        = 21,
        ev_joystick1_button2        = 22,
        ev_joystick1_button3        = 23,
        ev_joystick1_button4        = 24,
        ev_joystick1_button5        = 25,
        ev_joystick1_button6        = 26,
        ev_joystick1_button7        = 27,
        ev_joystick1_button8        = 28,
        ev_joystick2_left           = 31,
        ev_joystick2_right          = 32,
        ev_joystick2_up             = 33,
        ev_joystick2_down           = 34,
        ev_joystick2_button1        = 36,
        ev_joystick2_button2        = 37,
        ev_joystick2_button3        = 38,
        ev_joystick2_button4        = 39,
        ev_joystick2_button5        = 40,
        ev_joystick2_button6        = 41,
        ev_joystick2_button7        = 42,
        ev_joystick2_button8        = 43,
    };
    enum EventOther
    {
        ev_outside          =  0,
        ev_boundary         =  1,
        ev_game_start       =  2,
        ev_game_end         =  3,
        ev_room_start       =  4,
        ev_room_end         =  5,
        ev_no_more_lives    =  6,
        ev_no_more_health   =  9,
        ev_animation_end    =  7,
        ev_end_of_path      =  8,
        ev_close_button     = 30,
        ev_user0            = 10,
        ev_user1            = 11,
        ev_user2            = 12,
        ev_user3            = 13,
        ev_user4            = 14,
        ev_user5            = 15,
        ev_user6            = 16,
        ev_user7            = 17,
        ev_user8            = 18,
        ev_user9            = 19,
        ev_user10           = 20,
        ev_user11           = 21,
        ev_user12           = 22,
        ev_user13           = 23,
        ev_user14           = 24,
        ev_user15           = 25,
    };
    enum EventStep
    {
        ev_step_normal  = 0,
        ev_step_begin   = 1,
        ev_step_end     = 2,
    };
    enum PathStart
    {
        pathstart_start             = 0,
        pathstart_continue_start    = 1,
        pathstart_continue_current  = 2,
        pathstart_reverse           = 3,
    };
    enum MouseButtons
    {
        mb_none   = 0,
        mb_left   = 1,
        mb_middle = 3,
        mb_right  = 2,
    };
    enum Primitives
    {
        pr_pointlist     = 1,
        pr_linelist      = 2,
        pr_linestrip     = 3,
        pr_trianglelist  = 4,
        pr_trianglestrip = 5,
        pr_trianglefan   = 6,
    };
    enum SoundEffect
    {
        se_none         = 0,
        se_chorus       = 1,
        se_echo         = 2,
        se_flanger      = 4,
        se_gargle       = 8,
        se_reverb       =16,
        se_compressor   =32,
        se_equalizer    =64
    };
    ///@}
}
#endif
