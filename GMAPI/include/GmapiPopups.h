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
  GmapiPopups.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {
  void show_message( const CGMVariable& str );
  double show_message_ext( const CGMVariable& str, const CGMVariable& but1,
                           const CGMVariable& but2, const CGMVariable& but3 );
  bool show_question( const CGMVariable& str );

  double get_integer( const CGMVariable& str, const double def );
  CGMVariable get_string( const CGMVariable& str, const CGMVariable& def );

  void message_background( const int back );
  void message_alpha( const double alpha );
  void message_button( const int spr );
  void message_text_font( const CGMVariable& name, const int size,
                          const int color, const int style );
  void message_button_font( const CGMVariable& name, const int size,
                            const int color, const int style );

  void message_input_font( const CGMVariable& name, const int size,
                           const int color, const int style );
  void message_input_color( const int col );
  void message_mouse_color( const int col );
  void message_caption( const bool show, const CGMVariable& str );
  void message_position( const int x, const int y );
  void message_size( const int w, const int h );

  int show_menu( const CGMVariable& str, const int def );
  int show_menu_pos( const int x, const int y, const CGMVariable& str, const int def );

  int get_color( const int defcol );
  CGMVariable get_open_filename( const CGMVariable& filter, const CGMVariable& fname );
  CGMVariable get_save_filename( const CGMVariable& filter, const CGMVariable& fname );
  CGMVariable get_directory( const CGMVariable& dname );
  CGMVariable get_directory_alt( const CGMVariable& capt, const CGMVariable& root );

  void splash_show_video( const CGMVariable& fname, const bool loop );
  void splash_show_text( const CGMVariable& fname, const int delay );
  void splash_show_image( const CGMVariable& fname, const int delay );
  void splash_set_main( const bool main );
  void splash_set_scale( const double scape );
  void splash_set_cursor( const bool vis );
  void splash_set_color( const int col );
  void splash_set_caption( const CGMVariable& cap );
  void splash_set_fullscreen( const bool full );
  void splash_set_border( const bool border );
  void splash_set_size( const int w, const int h );
  void splash_set_adapt( const bool adapt );
  void splash_set_top( const bool top );
  void splash_set_interrupt( const bool interrupt );
  void splash_set_stop_key( const bool stop );
  void splash_set_stop_mouse( const bool stop );

  void show_info();
  void load_info( const CGMVariable& fname );
  void show_error( const CGMVariable& str, const bool abort );

  void highscore_show( const double numb );
  void highscore_set_background( const int back );
  void highscore_set_border( const bool show );
  void highscore_set_font( const CGMVariable& name, const int size, const int style );
  void highscore_set_colors( const int back, const int new_, const int other );
  void highscore_set_strings( const CGMVariable& caption, const CGMVariable& nobody,
                              const CGMVariable& escape );
  void highscore_show_ext( const double numb, const int back, const bool border,
                           const int col1, const int col2,
                           const CGMVariable& name, const int size );
  void highscore_clear();
  void highscore_add( const CGMVariable& str, const double numb );
  void highscore_add_current();
  double highscore_value( const int place );
  CGMVariable highscore_name( const int place );
  void draw_highscore( const double x1, const double y1, 
                       const double x2, const double y2 );

};