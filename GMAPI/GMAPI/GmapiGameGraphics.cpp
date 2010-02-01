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
  GmapiGameGraphics.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiGameGraphics.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void draw_sprite( int sprite, int subimg, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y };

    GM_NORMAL_CALL( id_draw_sprite );
  }

  void draw_sprite_stretched( int sprite, int subimg, double x, double y,
                              double w, double h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y, w, h };

    GM_NORMAL_CALL( id_draw_sprite_stretched );
  }

  void draw_sprite_tiled( int sprite, int subimg, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y };

    GM_NORMAL_CALL( id_draw_sprite_tiled );
  }

  void draw_sprite_part( int sprite, int subimg, int left, int top,
                         int width, int height, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, left, top, width, height, x, y };

    GM_NORMAL_CALL( id_draw_sprite_part );
  }

  void draw_background( int back, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y };

    GM_NORMAL_CALL( id_draw_background );
  }

  void draw_background_stretched( int back, double x, double y,
                                  double w, double h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y, w, h };

    GM_NORMAL_CALL( id_draw_background_stretched );
  }

  void draw_background_tiled( int back, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y };

    GM_NORMAL_CALL( id_draw_background_tiled );
  }

  void draw_background_part( int back, int left, int top, int width,
                             int height, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, left, top, width, height, x, y };

    GM_NORMAL_CALL( id_draw_background_part );
  }

  void draw_sprite_ext( int sprite, int subimg, double x, double y,
                        double xscale, double yscale, double rot,
                        int color, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y, xscale, yscale, rot, color, alpha };

    GM_NORMAL_CALL( id_draw_sprite_ext );
  }

  void draw_sprite_stretched_ext( int sprite, int subimg, double x,
                                  double y, double w, double h,
                                  int color, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y, w, h, color, alpha };

    GM_NORMAL_CALL( id_draw_sprite_stretched_ext );
  }

  void draw_sprite_tiled_ext( int sprite, int subimg, double x, double y,
                              double xscale, double yscale, int color,
                              double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_sprite_tiled_ext );
  }

  void draw_sprite_part_ext( int sprite, int subimg, int left, int top,
                             int width, int height, double x, double y,
                             double xscale, double yscale, int color,
                             double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, left, top, width, height, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_sprite_part_ext );
  }

  void draw_sprite_general( int sprite, int subimg, int left, int top,
                            int width, int height, double x, double y,
                            double xscale, double yscale, double rot,
                            int c1, int c2, int c3, int c4,
                            double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, left, top, width, height, x, y, xscale, yscale, rot, c1, c2, c3,
                c4, alpha };

    GM_NORMAL_CALL( id_draw_sprite_general );
  }

  void draw_background_ext( int back, double x, double y, double xscale,
                            double yscale, double rot, int color,
                            double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y, xscale, yscale, rot, color, alpha };

    GM_NORMAL_CALL( id_draw_background_ext );
  }

  void draw_background_stretched_ext( int back, double x, double y,
                                      double w, double h, int color,
                                      double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y, w, h, color, alpha };

    GM_NORMAL_CALL( id_draw_background_stretched_ext );
  }

  void draw_background_tiled_ext( int back, double x, double y,
                                  double xscale, double yscale, int color,
                                  double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_background_tiled_ext );
  }

  void draw_background_part_ext( int back, int left, int top, int width,
                                 int height, double x, double y, 
                                 double xscale, double yscale, int color, 
                                 double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, left, top, width, height, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_background_part_ext );
  }

  void draw_background_general( int back, int left, int top, int width,
                                int height, double x, double y,
                                double xscale, double yscale, double rot,
                                int c1, int c2, int c3, int c4,
                                double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, left, top, width, height, x, y, xscale, yscale, rot, c1, c2, c3, c4,
                alpha };

    GM_NORMAL_CALL( id_draw_background_general );
  }

  void draw_clear( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_draw_clear );
  }

  void draw_clear_alpha( int col, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col, alpha };

    GM_NORMAL_CALL( id_draw_clear_alpha );
  }

  void draw_point( double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_draw_point );
  }

  void draw_line( double x1, double y1, double x2, double y2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2 };

    GM_NORMAL_CALL( id_draw_line );
  }

  void draw_line_width( double x1, double y1, double x2, double y2,
                        double w ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, w };

    GM_NORMAL_CALL( id_draw_line_width );
  }

  void draw_rectangle( double x1, double y1, double x2, double y2,
                       bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, outline };

    GM_NORMAL_CALL( id_draw_rectangle );
  }

  void draw_roundrect( double x1, double y1, double x2, double y2,
                       bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, outline };

    GM_NORMAL_CALL( id_draw_roundrect );
  }

  void draw_triangle( double x1, double y1, double x2, double y2,
                      double x3, double y3, bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, x3, y3, outline };

    GM_NORMAL_CALL( id_draw_triangle );
  }

  void draw_circle( double x, double y, double r, bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, r, outline };

    GM_NORMAL_CALL( id_draw_circle );
  }

  void draw_ellipse( double x1, double y1, double x2, double y2,
                     bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, outline };

    GM_NORMAL_CALL( id_draw_ellipse );
  }

  void draw_set_circle_precision( int precision ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ precision };

    GM_NORMAL_CALL( id_draw_set_circle_precision );
  }

  void draw_arrow( double x1, double y1, double x2, double y2,
                   int size ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, size };

    GM_NORMAL_CALL( id_draw_arrow );
  }

  void draw_button( double x1, double y1, double x2, double y2,
                    bool up ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, up };

    GM_NORMAL_CALL( id_draw_button );
  }

  void draw_path( int path, double x, double y, bool absolute ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, x, y, absolute };

    GM_NORMAL_CALL( id_draw_path );
  }

  void draw_healthbar( double x1, double y1, double x2, double y2,
                       double amount, int backcol, int mincol,
                       int maxcol, double direction, bool showback,
                       bool showborder ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, amount, backcol, mincol, maxcol, direction, showback,
                showborder };

    GM_NORMAL_CALL( id_draw_healthbar );
  }

  void draw_set_color( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_draw_set_color );
  }

  void draw_set_alpha( double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ alpha };

    GM_NORMAL_CALL( id_draw_set_alpha );
  }

  int draw_get_color() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_draw_get_color );
    GM_RETURN_INT;
  }

  double draw_get_alpha() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_draw_get_alpha );
    GM_RETURN_REAL;
  }

  int make_color_rgb( int red, int green, int blue ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ red, green, blue };

    GM_NORMAL_CALL( id_make_color_rgb );
    GM_RETURN_INT;
  }

  int make_color_hsv( int hue, int saturation, int value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hue, saturation, value };

    GM_NORMAL_CALL( id_make_color_hsv );
    GM_RETURN_INT;
  }

  int color_get_red( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_red );
    GM_RETURN_INT;
  }

  int color_get_green( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_green );
    GM_RETURN_INT;
  }

  int color_get_blue( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_blue );
    GM_RETURN_INT;
  }

  int color_get_hue( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_hue );
    GM_RETURN_INT;
  }

  int color_get_saturation( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_saturation );
    GM_RETURN_INT;
  }

  int color_get_value( int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_value );
    GM_RETURN_INT;
  }

  int merge_color( int col1, int col2, double amount ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col1, col2, amount };

    GM_NORMAL_CALL( id_merge_color );
    GM_RETURN_INT;
  }

  int draw_getpixel( double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_draw_getpixel );
    GM_RETURN_INT;
  }

  void screen_save( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_screen_save );
  }

  void screen_save_part( const CGMVariable& fname, int x, int y, int w,
                         int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, x, y, w, h };

    GM_NORMAL_CALL( id_screen_save_part );
  }

  void draw_set_font( int font ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ font };

    GM_NORMAL_CALL( id_draw_set_font );
  }

  void draw_set_halign( int halign ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ halign };

    GM_NORMAL_CALL( id_draw_set_halign );
  }

  void draw_set_valign( int valign ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ valign };

    GM_NORMAL_CALL( id_draw_set_valign );
  }

  void draw_text( double x, double y, const CGMVariable& string ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string };

    GM_NORMAL_CALL( id_draw_text );
  }

  void draw_text_ext( double x, double y, const CGMVariable& string,
                      double sep, int w ) {
    GM_NORMAL_RESULT;   
    GM_ARGS{ x, y, string, sep, w };

    GM_NORMAL_CALL( id_draw_text_ext );
  }

  double string_width( const CGMVariable& string ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ string };

    GM_NORMAL_CALL( id_string_width );
    GM_RETURN_REAL;
  }

  double string_height( const CGMVariable& string ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ string };

    GM_NORMAL_CALL( id_string_height );
    GM_RETURN_REAL;
  }

  double string_width_ext( const CGMVariable& string, double sep, double w ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ string, sep, w };

    GM_NORMAL_CALL( id_string_width_ext );
    GM_RETURN_REAL;
  }

  double string_height_ext( const CGMVariable& string, double sep, double w ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ string, sep, w };

    GM_NORMAL_CALL( id_string_height_ext );
    GM_RETURN_REAL;
  }

  void draw_text_transformed( double x, double y, const CGMVariable& string,
                              double xscale, double yscale, double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, xscale, yscale, angle };

    GM_NORMAL_CALL( id_draw_text_transformed );
  }

  void draw_text_ext_transformed( double x, double y, const CGMVariable& string,
                                  double sep, double w, double xscale,
                                  double yscale, double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, sep, w, xscale, yscale, angle };

    GM_NORMAL_CALL( id_draw_text_ext_transformed );
  }

  void draw_text_color( double x, double y, const CGMVariable& string,
                        int c1, int c2, int c3, int c4,
                        double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_text_color );
  }

  void draw_text_ext_color( double x, double y, const CGMVariable& string,
                            double sep, double w, int c1, int c2, 
                            int c3, int c4, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, sep, w, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_text_ext_color );
  }

  void draw_text_transformed_color( double x, double y, const CGMVariable& string,
                                    double xscale, double yscale, double angle,
                                    int c1, int c2, int c3, int c4,
                                    double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, xscale, yscale, angle, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_text_transformed_color );
  }

  void draw_text_ext_transformed_color( double x, double y,
                                        const CGMVariable& string, double sep,
                                        double w, double xscale,
                                        double yscale, double angle,
                                        int c1, int c2, int c3, int c4,
                                        double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, sep, w, xscale, yscale, angle, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_text_ext_transformed_color );
  }

  void draw_point_color( double x, double y, int col1 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, col1 };

    GM_NORMAL_CALL( id_draw_point_color );
  }

  void draw_line_color( double x1, double y1, double x2, double y2,
                        int col1, int col2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, col1, col2 };

    GM_NORMAL_CALL( id_draw_line_color );
  }

  void draw_line_width_color( double x1, double y1, double x2, double y2,
                              double w, int col1, int col2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, w, col1, col2 };

    GM_NORMAL_CALL( id_draw_line_width_color );
  }

  void draw_rectangle_color( double x1, double y1, double x2, double y2,
                             int col1, int col2, int col3, int col4,
                             bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, col1, col2, col3, col4, outline };

    GM_NORMAL_CALL( id_draw_rectangle_color );
  }

  void draw_roundrect_color( double x1, double y1, double x2, double y2,
                             int col1, int col2, bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, col1, col2, outline };

    GM_NORMAL_CALL( id_draw_roundrect_color );
  }

  void draw_triangle_color( double x1, double y1, double x2, double y2,
                            double x3, double y3, int col1, int col2,
                            int col3, bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, x3, y3, col1, col2, col3, outline };

    GM_NORMAL_CALL( id_draw_triangle_color );
  }

  void draw_circle_color( double x, double y, double r, int col1, 
                          int col2, bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, r, col1, col2, outline };

    GM_NORMAL_CALL( id_draw_circle_color );
  }

  void draw_ellipse_color( double x1, double y1, double x2, double y2,
                           int col1, int col2, bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, col1, col2, outline };

    GM_NORMAL_CALL( id_draw_ellipse_color );
  }

  void draw_primitive_begin( int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind };

    GM_NORMAL_CALL( id_draw_primitive_begin );
  }

  void draw_vertex( double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_draw_vertex );
  }

  void draw_vertex_color( double x, double y, int col, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, col, alpha };

    GM_NORMAL_CALL( id_draw_vertex_color );
  }

  void draw_primitive_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_draw_primitive_end );
  }

  int sprite_get_texture( int spr, int subimg ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ spr, subimg };

    GM_NORMAL_CALL( id_sprite_get_texture );
    GM_RETURN_INT;
  }

  int background_get_texture( int back ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back };

    GM_NORMAL_CALL( id_background_get_texture );
    GM_RETURN_INT;
  }

  void texture_preload( int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ texid };

    GM_NORMAL_CALL( id_texture_preload );
  }

  void texture_set_priority( int texid, int prio ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ texid, prio };

    GM_NORMAL_CALL( id_texture_set_priority );
  }

  int texture_get_width( int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ texid };

    GM_NORMAL_CALL( id_texture_get_width );
    GM_RETURN_INT;
  }

  double texture_get_height( int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ texid };

    GM_NORMAL_CALL( id_texture_get_height );
    GM_RETURN_REAL;
  }

  void draw_primitive_begin_texture( int kind, int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind, texid };

    GM_NORMAL_CALL( id_draw_primitive_begin_texture );
  }

  void draw_vertex_texture( double x, double y, double xtex,
                            double ytex ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, xtex, ytex };

    GM_NORMAL_CALL( id_draw_vertex_texture );
  }

  void draw_vertex_texture_color( double x, double y, double xtex, 
                                  double ytex, int col, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, xtex, ytex, col, alpha };

    GM_NORMAL_CALL( id_draw_vertex_texture_color );
  }

  void texture_set_interpolation( bool linear ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ linear };

    GM_NORMAL_CALL( id_texture_set_interpolation );
  }

  void texture_set_blending( bool blend ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ blend };

    GM_NORMAL_CALL( id_texture_set_blending );
  }

  void texture_set_repeat( double repeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ repeat };

    GM_NORMAL_CALL( id_texture_set_repeat );
  }

  void draw_set_blend_mode( int mode ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ mode };

    GM_NORMAL_CALL( id_draw_set_blend_mode );
  }

  void draw_set_blend_mode_ext( int src, int dest ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ src, dest };

    GM_NORMAL_CALL( id_draw_set_blend_mode_ext );
  }

  int surface_create( int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_surface_create );
    GM_RETURN_INT;
  }

  void surface_free( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_free );
  }

  bool surface_exists( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_exists );
    GM_RETURN_BOOL;
  }

  int surface_get_width( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_get_width );
    GM_RETURN_INT;
  }

  int surface_get_height( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_get_height );
    GM_RETURN_INT;
  }

  int surface_get_texture( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_get_texture );
    GM_RETURN_INT;
  }

  void surface_set_target( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_set_target );
  }

  void surface_reset_target() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_surface_reset_target );
  }

  int surface_getpixel( int id, int x, int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_surface_getpixel );
    GM_RETURN_INT;
  }

  void surface_save( int id, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, fname };

    GM_NORMAL_CALL( id_surface_save );
  }

  void surface_save_part( int id, const CGMVariable& fname, int x, int y,
                          int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, fname, x, y, w, h };

    GM_NORMAL_CALL( id_surface_save_part );
  }

  void draw_surface( int id, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_draw_surface );
  }

  void draw_surface_stretched( int id, double x, double y, double w,
                               double h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h };

    GM_NORMAL_CALL( id_draw_surface_stretched );
  }

  void draw_surface_tiled( int id, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_draw_surface_tiled );
  }

  void draw_surface_part( int id, int left, int top, int width,
                          int height, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, width, height, x, y };

    GM_NORMAL_CALL( id_draw_surface_part );
  }

  void draw_surface_ext( int id, double x, double y, double xscale,
                         double yscale, double rot, int color,
                         double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, xscale, yscale, rot, color, alpha };

    GM_NORMAL_CALL( id_draw_surface_ext );
  }

  void draw_surface_stretched_ext( int id, double x, double y, double w,
                                   double h, int color, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h, color, alpha };

    GM_NORMAL_CALL( id_draw_surface_stretched_ext );
  }

  void draw_surface_tiled_ext( int id, double x, double y, double xscale,
                               double yscale, int color, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_surface_tiled_ext );
  }

  void draw_surface_part_ext( int id, int left, int top, int width, 
                              int height, double x, double y,
                              double xscale, double yscale, int color, 
                              double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, width, height, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_surface_part_ext );
  }

  void draw_surface_general( int id, int left, int top, int width,
                             int height, double x, double y,
                             double xscale, double yscale, double rot,
                             int c1, int c2, int c3, int c4, 
                             double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, width, height, x, y, xscale, yscale, rot, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_surface_general );
  }

  void surface_copy( int destination, double x, double y, int source ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ destination, x, y, source };

    GM_NORMAL_CALL( id_surface_copy );
  }

  void surface_copy_part( int destination, double x, double y, 
                          int source, double xs, double ys, double ws,
                          double hs ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ destination, x, y, source, xs, ys, ws, hs };

    GM_NORMAL_CALL( id_surface_copy_part );
  }

  int tile_add( int background, int left, int top, int width,
                int height, double x, double y, int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ background, left, top, width, height, x, y, depth };

    GM_NORMAL_CALL( id_tile_add );
    GM_RETURN_INT;
  }

  void tile_delete( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_delete );
  }

  bool tile_exists( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_exists );
    GM_RETURN_BOOL;
  }

  double tile_get_x( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_x );
    GM_RETURN_REAL;
  }

  double tile_get_y( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_y );
    GM_RETURN_REAL;
  }

  int tile_get_left( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_left );
    GM_RETURN_INT;
  }

  int tile_get_top( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_top );
    GM_RETURN_INT;
  }

  int tile_get_width( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_width );
    GM_RETURN_INT;
  }

  int tile_get_height( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_height );
    GM_RETURN_INT;
  }

  int tile_get_depth( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_depth );
    GM_RETURN_INT;
  }

  bool tile_get_visible( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_visible );
    GM_RETURN_BOOL;
  }

  double tile_get_xscale( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_xscale );
    GM_RETURN_REAL;
  }

  double tile_get_yscale( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_yscale );
    GM_RETURN_REAL;
  }

  int tile_get_background( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_background );
    GM_RETURN_INT;
  }

  int tile_get_blend( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_blend );
    GM_RETURN_INT;
  }

  double tile_get_alpha( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_alpha );
    GM_RETURN_REAL;
  }

  void tile_set_position( int id, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_tile_set_position );
  }

  void tile_set_region( int id, double left, double top,
                        double width, double height ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, width, height };

    GM_NORMAL_CALL( id_tile_set_region );
  }

  void tile_set_background( int id, int background ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, background };

    GM_NORMAL_CALL( id_tile_set_background );
  }

  void tile_set_visible( int id, bool visible ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, visible };

    GM_NORMAL_CALL( id_tile_set_visible );
  }

  void tile_set_depth( int id, int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, depth };

    GM_NORMAL_CALL( id_tile_set_depth );
  }

  void tile_set_scale( int id, double xscale, double yscale ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xscale, yscale };

    GM_NORMAL_CALL( id_tile_set_scale );
  }

  void tile_set_blend( int id, int color ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, color };

    GM_NORMAL_CALL( id_tile_set_blend );
  }

  void tile_set_alpha( int id, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, alpha };

    GM_NORMAL_CALL( id_tile_set_alpha );
  }

  void tile_layer_hide( int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth };

    GM_NORMAL_CALL( id_tile_layer_hide );
  }

  void tile_layer_show( int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth };

    GM_NORMAL_CALL( id_tile_layer_show );
  }

  void tile_layer_delete( int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth };

    GM_NORMAL_CALL( id_tile_layer_delete );
  }

  void tile_layer_shift( int depth, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth, x, y };

    GM_NORMAL_CALL( id_tile_layer_shift );
  }

  int tile_layer_find( int depth, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth, x, y };

    GM_NORMAL_CALL( id_tile_layer_find );
    GM_RETURN_INT;
  }

  void tile_layer_delete_at( int depth, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth, x, y };

    GM_NORMAL_CALL( id_tile_layer_delete_at );
  }

  void tile_layer_depth( int depth, int newdepth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth, newdepth };

    GM_NORMAL_CALL( id_tile_layer_depth );
  }

  int display_get_width() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_display_get_width );
    GM_RETURN_INT;
  }

  int display_get_height() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_display_get_height );
    GM_RETURN_INT;
  }

  int display_get_colordepth() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_display_get_colordepth );
    GM_RETURN_INT;
  }

  int display_get_frequency() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_display_get_frequency );
    GM_RETURN_INT;
  }

  void display_set_size( int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_display_set_size );
  }

  void display_set_colordepth( int coldepth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ coldepth };

    GM_NORMAL_CALL( id_display_set_colordepth );
  }

  void display_set_frequency( int frequency ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ frequency };

    GM_NORMAL_CALL( id_display_set_frequency );
  }

  void display_set_all( int w, int h, int frequency, int coldepth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, frequency, coldepth };

    GM_NORMAL_CALL( id_display_set_all );
  }

  bool display_test_all( int w, int h, int frequency, int coldepth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, frequency, coldepth };

    GM_NORMAL_CALL( id_display_test_all );
    GM_RETURN_BOOL;
  }

  void display_reset() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_display_reset );
  }

  int display_mouse_get_x() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_display_mouse_get_x );
    GM_RETURN_INT;
  }

  int display_mouse_get_y() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_display_mouse_get_y );
    GM_RETURN_INT;
  }

  void display_mouse_set( int x, int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_display_mouse_set );
  }

  void window_set_visible( bool visible ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ visible };

    GM_NORMAL_CALL( id_window_set_visible );
  }

  bool window_get_visible() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_visible );
    GM_RETURN_BOOL;
  }

  void window_set_fullscreen( bool full ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ full };

    GM_NORMAL_CALL( id_window_set_fullscreen );
  }

  bool window_get_fullscreen() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_fullscreen );
    GM_RETURN_BOOL;
  }

  void window_set_showborder( bool show ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ show };

    GM_NORMAL_CALL( id_window_set_showborder );
  }

  bool window_get_showborder() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_showborder );
    GM_RETURN_BOOL;
  }

  void window_set_showicons( bool show ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ show };

    GM_NORMAL_CALL( id_window_set_showicons );
  }

  bool window_get_showicons() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_showicons );
    GM_RETURN_BOOL;
  }

  void window_set_stayontop( bool stay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ stay };

    GM_NORMAL_CALL( id_window_set_stayontop );
  }

  bool window_get_stayontop() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_stayontop );
    GM_RETURN_BOOL;
  }

  void window_set_sizeable( bool sizeable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sizeable };

    GM_NORMAL_CALL( id_window_set_sizeable );
  }

  bool window_get_sizeable() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_sizeable );
    GM_RETURN_BOOL;
  }

  void window_set_caption( const CGMVariable& caption ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ caption };

    GM_NORMAL_CALL( id_window_set_caption );
  }

  CGMVariable window_get_caption() {
    GM_VAR_RESULT;

    GM_VOID_CALL( id_window_get_caption );
    GM_RETURN_VAR;
  }

  void window_set_cursor( int curs ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ curs };

    GM_NORMAL_CALL( id_window_set_cursor );
  }

  int window_get_cursor() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_cursor );
    GM_RETURN_INT;
  }

  void window_set_color( int color ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ color };

    GM_NORMAL_CALL( id_window_set_color );
  }

  int window_get_color() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_color );
    GM_RETURN_INT;
  }

  void window_set_region_scale( double scale, bool adaptwindow ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ scale, adaptwindow };

    GM_NORMAL_CALL( id_window_set_region_scale );
  }

  double window_get_region_scale() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_region_scale );
    GM_RETURN_REAL;
  }

  void window_set_position( int x, int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_window_set_position );
  }

  void window_set_size( int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_window_set_size );
  }

  void window_set_rectangle( int x, int y, int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h };

    GM_NORMAL_CALL( id_window_set_rectangle );
  }

  void window_center() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_center );
  }

  void window_default() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_default );
  }

  int window_get_x() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_x );
    GM_RETURN_INT;
  }

  int window_get_y() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_y );
    GM_RETURN_INT;
  }

  int window_get_width() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_width );
    GM_RETURN_INT;
  }

  int window_get_height() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_height );
    GM_RETURN_INT;
  }

  int window_mouse_get_x() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_mouse_get_x );
    GM_RETURN_INT;
  }

  int window_mouse_get_y() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_mouse_get_y );
    GM_RETURN_INT;
  }

  void window_mouse_set( int x, int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_window_mouse_set );
  }

  void window_set_region_size( int w, int h, bool adaptwindow ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, adaptwindow };

    GM_NORMAL_CALL( id_window_set_region_size );
  }

  int window_get_region_width() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_region_width );
    GM_RETURN_INT;
  }

  int window_get_region_height() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_region_height );
    GM_RETURN_INT;
  }

  int window_view_mouse_get_x( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_window_view_mouse_get_x );
    GM_RETURN_INT;
  }

  int window_view_mouse_get_y( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_window_view_mouse_get_y );
    GM_RETURN_INT;
  }

  void window_view_mouse_set( int id, int x, int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_window_view_mouse_set );
  }

  int window_views_mouse_get_x() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_views_mouse_get_x );
    GM_RETURN_INT;
  }

  int window_views_mouse_get_y() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_views_mouse_get_y );
    GM_RETURN_INT;
  }

  void window_views_mouse_set( int x, int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_window_views_mouse_set );
  }

  void screen_redraw() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_screen_redraw );
  }

  void screen_refresh() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_screen_refresh );
  }

  void set_automatic_draw( bool value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ value };

    GM_NORMAL_CALL( id_set_automatic_draw );
  }

  void set_synchronization( bool value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ value };

    GM_NORMAL_CALL( id_set_synchronization );
  }

  void screen_wait_vsync() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_screen_wait_vsync );
  }

  HWND window_handle() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_handle );
    return (HWND) (DWORD) result.real;
  }

}
