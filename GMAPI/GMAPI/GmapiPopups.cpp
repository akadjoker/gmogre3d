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
  GmapiPopups.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiPopups.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void show_message( const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ str };

    GM_NORMAL_CALL( id_show_message );
  }

  double show_message_ext( const CGMVariable& str, const CGMVariable& but1, 
                           const CGMVariable& but2, const CGMVariable& but3 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ str, but1, but2, but3 };

    GM_NORMAL_CALL( id_show_message_ext );
    GM_RETURN_REAL;
  }

  bool show_question( const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ str };

    GM_NORMAL_CALL( id_show_question );
    GM_RETURN_BOOL;
  }

  double get_integer( const CGMVariable& str, double def ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ str, def };

    GM_NORMAL_CALL( id_get_integer );
    GM_RETURN_REAL;
  }

  CGMVariable get_string( const CGMVariable& str, const CGMVariable& def ) {
    GM_VAR_RESULT;
    GM_ARGS{ str, def };

    GM_NORMAL_CALL( id_get_string );
    GM_RETURN_VAR;
  }

  void message_background( int back ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back };

    GM_NORMAL_CALL( id_message_background );
  }

  void message_alpha( double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ alpha };

    GM_NORMAL_CALL( id_message_alpha );
  }

  void message_button( int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ spr };

    GM_NORMAL_CALL( id_message_button );
  }

  void message_text_font( const CGMVariable& name, int size,
                          int color, int style ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, size, color, style };

    GM_NORMAL_CALL( id_message_text_font );
  }

  void message_button_font( const CGMVariable& name, int size,
                            int color, int style ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, size, color, style };

    GM_NORMAL_CALL( id_message_button_font );
  }

  void message_input_font( const CGMVariable& name, int size,
                           int color, int style ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, size, color, style };

    GM_NORMAL_CALL( id_message_input_font );
  }

  void message_input_color( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_message_input_color );
  }


  ////////////


  void message_mouse_color( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_message_mouse_color );
  }

  void message_caption( bool show, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ show, str };

    GM_NORMAL_CALL( id_message_caption );
  }

  void message_position( int x, int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_message_position );
  }

  void message_size( int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_message_size );
  }

  int show_menu( const CGMVariable& str, int def ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ str, def };

    GM_NORMAL_CALL( id_show_menu );
    GM_RETURN_INT;
  }

  int show_menu_pos( int x, int y, const CGMVariable& str, int def ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, str, def };

    GM_NORMAL_CALL( id_show_menu_pos );
    GM_RETURN_INT;
  }

  int get_color( int defcol ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ defcol };

    GM_NORMAL_CALL( id_get_color );
    GM_RETURN_INT;
  }

  CGMVariable get_open_filename( const CGMVariable& filter, const CGMVariable& fname ) {
    GM_VAR_RESULT;
    GM_ARGS{ filter, fname };

    GM_NORMAL_CALL( id_get_open_filename );
    GM_RETURN_VAR;
  }

  CGMVariable get_save_filename( const CGMVariable& filter, const CGMVariable& fname ) {
    GM_VAR_RESULT;
    GM_ARGS{ filter, fname };

    GM_NORMAL_CALL( id_get_save_filename );
    GM_RETURN_VAR;
  }

  CGMVariable get_directory( const CGMVariable& dname ) {
    GM_VAR_RESULT;
    GM_ARGS{ dname };

    GM_NORMAL_CALL( id_get_directory );
    GM_RETURN_VAR;
  }

  CGMVariable get_directory_alt( const CGMVariable& capt, const CGMVariable& root ) {
    GM_VAR_RESULT;
    GM_ARGS{ capt, root };

    GM_NORMAL_CALL( id_get_directory_alt );
    GM_RETURN_VAR;
  }

  void show_error( const CGMVariable& str, bool abort ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ str, abort };

    GM_NORMAL_CALL( id_show_error );
  }

  void splash_show_video( const CGMVariable& fname, bool loop ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, loop };

    GM_NORMAL_CALL( id_splash_show_video );
  }

  void splash_show_text( const CGMVariable& fname, int delay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, delay };

    GM_NORMAL_CALL( id_splash_show_text );
  }

  void splash_show_image( const CGMVariable& fname, int delay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, delay };

    GM_NORMAL_CALL( id_splash_show_image );
  }

  void splash_show_web( const CGMVariable& url, int delay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ url, delay };

    GM_NORMAL_CALL( id_splash_show_web );
  }

  void splash_set_main( bool main ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ main };

    GM_NORMAL_CALL( id_splash_set_main );
  }

  void splash_set_scale( double scale ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ scale };

    GM_NORMAL_CALL( id_splash_set_scale );
  }

  void splash_set_cursor( bool vis ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ vis };

    GM_NORMAL_CALL( id_splash_set_cursor );
  }

  void splash_set_color( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_splash_set_color );
  }

  void splash_set_caption( const CGMVariable& cap ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ cap };

    GM_NORMAL_CALL( id_splash_set_caption );
  }

  void splash_set_fullscreen( bool full ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ full };

    GM_NORMAL_CALL( id_splash_set_fullscreen );
  }

  void splash_set_border( bool border ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ border };

    GM_NORMAL_CALL( id_splash_set_border );
  }

  void splash_set_size( int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_splash_set_size );
  }

  void splash_set_adapt( bool adapt ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ adapt };

    GM_NORMAL_CALL( id_splash_set_adapt );
  }

  void splash_set_top( bool top ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ top };

    GM_NORMAL_CALL( id_splash_set_top );
  }

  void splash_set_interrupt( bool interrupt ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ interrupt };

    GM_NORMAL_CALL( id_splash_set_interrupt );
  }

  void splash_set_stop_key( bool stop ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ stop };

    GM_NORMAL_CALL( id_splash_set_stop_key );
  }

  void splash_set_stop_mouse( bool stop ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ stop };

    GM_NORMAL_CALL( id_splash_set_stop_mouse );
  }

  void splash_set_position( int x, int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_splash_set_position );
  }

  void splash_set_close_button( bool show ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ show };

    GM_NORMAL_CALL( id_splash_set_close_button );
  }

  void show_info() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_show_info );
  }

  void load_info( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_load_info );
  }

  void highscore_show( double numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_highscore_show );
  }

  void highscore_set_background( int back ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back };

    GM_NORMAL_CALL( id_highscore_set_background );
  }

  void highscore_set_border( bool show ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ show };

    GM_NORMAL_CALL( id_highscore_set_border );
  }

  void highscore_set_font( const CGMVariable& name, int size, int style ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, size, style };

    GM_NORMAL_CALL( id_highscore_set_font );
  }

  void highscore_set_colors( int back, int new_, int other ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, new_, other };

    GM_NORMAL_CALL( id_highscore_set_colors );
  }

  void highscore_set_strings( const CGMVariable& caption, const CGMVariable& nobody,
                              const CGMVariable& escape ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ caption, nobody, escape };

    GM_NORMAL_CALL( id_highscore_set_strings );
  }

  void highscore_show_ext( double numb, int back, bool border,
                           int col1, int col2,
                           const CGMVariable& name, int size ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb, back, border, col1, col2, name, size };

    GM_NORMAL_CALL( id_highscore_show_ext );
  }

  void highscore_clear() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_highscore_clear );
  }

  void highscore_add( const CGMVariable& str, double numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ str, numb };

    GM_NORMAL_CALL( id_highscore_add );
  }

  void highscore_add_current() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_highscore_add_current );
  }

  double highscore_value( int place ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ place };

    GM_NORMAL_CALL( id_highscore_value );
    GM_RETURN_REAL;
  }

  CGMVariable highscore_name( int place ) {
    GM_VAR_RESULT;
    GM_ARGS{ place };

    GM_NORMAL_CALL( id_highscore_name );
    GM_RETURN_VAR;
  }

  void draw_highscore( double x1, double y1, 
                       double x2, double y2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2 };

    GM_NORMAL_CALL( id_draw_highscore );
  }

}