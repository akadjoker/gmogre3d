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
  GmapiInteraction.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiInteraction.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void keyboard_set_map( int key1, int key2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key1, key2 };

    GM_NORMAL_CALL( id_keyboard_set_map );
  }

  int keyboard_get_map( int key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key };

    GM_NORMAL_CALL( id_keyboard_get_map );
    GM_RETURN_INT;
  }

  void keyboard_unset_map() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_keyboard_unset_map );
  }

  bool keyboard_check( int key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key };

    GM_NORMAL_CALL( id_keyboard_check );
    GM_RETURN_BOOL;
  }

  bool keyboard_check_pressed( int key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key };

    GM_NORMAL_CALL( id_keyboard_check_pressed );
    GM_RETURN_BOOL;
  }

  bool keyboard_check_released( int key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key };

    GM_NORMAL_CALL( id_keyboard_check_released );
    GM_RETURN_BOOL;
  }

  bool keyboard_check_direct( int key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key };

    GM_NORMAL_CALL( id_keyboard_check_direct );
    GM_RETURN_BOOL;
  }

  bool keyboard_get_numlock() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_keyboard_get_numlock );
    GM_RETURN_BOOL;
  }

  void keyboard_set_numlock( bool on ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ on };

    GM_NORMAL_CALL( id_keyboard_set_numlock );
  }

  void keyboard_key_press( int key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key };

    GM_NORMAL_CALL( id_keyboard_key_press );
  }

  void keyboard_key_release( int key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key };

    GM_NORMAL_CALL( id_keyboard_key_release );
  }

  void keyboard_clear( int key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key };

    GM_NORMAL_CALL( id_keyboard_clear );
  }

  void io_clear() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_io_clear );
  }

  void io_handle() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_io_handle );
  }

  void keyboard_wait() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_keyboard_wait );
  }

  bool mouse_check_button( int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_mouse_check_button );
    GM_RETURN_BOOL;
  }

  bool mouse_check_button_pressed( int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_mouse_check_button_pressed );
    GM_RETURN_BOOL;
  }

  bool mouse_check_button_released( int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_mouse_check_button_released );
    GM_RETURN_BOOL;
  }

  bool mouse_wheel_up() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mouse_wheel_up );
    GM_RETURN_BOOL;
  }

  bool mouse_wheel_down() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mouse_wheel_down );
    GM_RETURN_BOOL;
  }

  void mouse_clear( int button ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ button };

    GM_NORMAL_CALL( id_mouse_clear );
  }

  void mouse_wait() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mouse_wait );
  }

  bool joystick_exists( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable joystick_name( int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_name );
    GM_RETURN_VAR;
  }

  int joystick_axes( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_axes );
    GM_RETURN_INT;
  }

  int joystick_buttons( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_buttons );
    GM_RETURN_INT;
  }

  bool joystick_has_pov( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_has_pov );
    GM_RETURN_BOOL;
  }

  int joystick_direction( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_direction );
    GM_RETURN_INT;
  }

  bool joystick_check_button( int id, int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, numb };

    GM_NORMAL_CALL( id_joystick_check_button );
    GM_RETURN_BOOL;
  }

  int joystick_xpos( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_xpos );
    GM_RETURN_INT;
  }

  int joystick_ypos( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_ypos );
    GM_RETURN_INT;
  }

  int joystick_zpos( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_zpos );
    GM_RETURN_INT;
  }

  int joystick_rpos( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_rpos );
    GM_RETURN_INT;
  }

  int joystick_upos( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_upos );
    GM_RETURN_INT;
  }

  int joystick_vpos( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_vpos );
    GM_RETURN_INT;
  }

  int joystick_pov( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_joystick_pov );
    GM_RETURN_INT;
  }


}