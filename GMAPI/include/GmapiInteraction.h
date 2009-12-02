/************************************************************************** 
  LICENSE:

    GMAPI is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    GMAPI is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with GMAPI; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301 USA
***************************************************************************/

/*************************************************************************
  GmapiInteraction.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  void keyboard_set_map( const int key1, const int key2 );
  int keyboard_get_map( const int key );
  void keyboard_unset_map();
  bool keyboard_check( const int key );
  bool keyboard_check_pressed( const int key );
  bool keyboard_check_released( const int key );
  bool keyboard_check_direct( const int key );
  bool keyboard_get_numlock();
  void keyboard_set_numlock( const bool on );
  void keyboard_key_press( const int key );
  void keyboard_key_release( const int key );
  void keyboard_clear( const int key );
  void io_clear();
  void keyboard_wait();
  bool mouse_check_button( const int numb );
  bool mouse_check_button_pressed( const int numb );
  bool mouse_check_button_released( const int numb );
  void mouse_clear( const int button );
  void io_clear();
  void io_handle();
  void mouse_wait();
  bool joystick_exists( const int id );
  CGMVariable joystick_name( const int id );
  int joystick_axes( const int id );
  int joystick_buttons( const int id );
  bool joystick_has_pov( const int id );
  int joystick_direction( const int id );
  bool joystick_check_button( const int id, const int numb );
  int joystick_xpos( const int id );
  int joystick_ypos( const int id );
  int joystick_zpos( const int id );
  int joystick_rpos( const int id );
  int joystick_upos( const int id );
  int joystick_vpos( const int id );
  int joystick_pov( const int id );

}