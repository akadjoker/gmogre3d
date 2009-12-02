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

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiGameGraphics.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void draw_sprite( const int sprite, const int subimg, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y };

    GM_NORMAL_CALL( id_draw_sprite );
  }

  void draw_sprite_stretched( const int sprite, const int subimg, const double x, const double y,
                              const double w, const double h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y, w, h };

    GM_NORMAL_CALL( id_draw_sprite_stretched );
  }

  void draw_sprite_tiled( const int sprite, const int subimg, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y };

    GM_NORMAL_CALL( id_draw_sprite_tiled );
  }

  void draw_sprite_part( const int sprite, const int subimg, const int left, const int top,
                         const int width, const int height, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, left, top, width, height, x, y };

    GM_NORMAL_CALL( id_draw_sprite_part );
  }

  void draw_background( const int back, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y };

    GM_NORMAL_CALL( id_draw_background );
  }

  void draw_background_stretched( const int back, const double x, const double y,
                                  const double w, const double h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y, w, h };

    GM_NORMAL_CALL( id_draw_background_stretched );
  }

  void draw_background_tiled( const int back, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y };

    GM_NORMAL_CALL( id_draw_background_tiled );
  }

  void draw_background_part( const int back, const int left, const int top, const int width,
                             const int height, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, left, top, width, height, x, y };

    GM_NORMAL_CALL( id_draw_background_part );
  }

  void draw_sprite_ext( const int sprite, const int subimg, const double x, const double y,
                        const double xscale, const double yscale, const double rot,
                        const int color, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y, xscale, yscale, rot, color, alpha };

    GM_NORMAL_CALL( id_draw_sprite_ext );
  }

  void draw_sprite_stretched_ext( const int sprite, const int subimg, const double x,
                                  const double y, const double w, const double h,
                                  const int color, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y, w, h, color, alpha };

    GM_NORMAL_CALL( id_draw_sprite_stretched_ext );
  }

  void draw_sprite_tiled_ext( const int sprite, const int subimg, const double x, const double y,
                              const double xscale, const double yscale, const int color,
                              const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_sprite_tiled_ext );
  }

  void draw_sprite_part_ext( const int sprite, const int subimg, const int left, const int top,
                             const int width, const int height, const double x, const double y,
                             const double xscale, const double yscale, const int color,
                             const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, left, top, width, height, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_sprite_part_ext );
  }

  void draw_sprite_general( const int sprite, const int subimg, const int left, const int top,
                            const int width, const int height, const double x, const double y,
                            const double xscale, const double yscale, const double rot,
                            const int c1, const int c2, const int c3, const int c4,
                            const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sprite, subimg, left, top, width, height, x, y, xscale, yscale, rot, c1, c2, c3,
                c4, alpha };

    GM_NORMAL_CALL( id_draw_sprite_general );
  }

  void draw_background_ext( const int back, const double x, const double y, const double xscale,
                            const double yscale, const double rot, const int color,
                            const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y, xscale, yscale, rot, color, alpha };

    GM_NORMAL_CALL( id_draw_background_ext );
  }

  void draw_background_stretched_ext( const int back, const double x, const double y,
                                      const double w, const double h, const int color,
                                      const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y, w, h, color, alpha };

    GM_NORMAL_CALL( id_draw_background_stretched_ext );
  }

  void draw_background_tiled_ext( const int back, const double x, const double y,
                                  const double xscale, const double yscale, const int color,
                                  const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_background_tiled_ext );
  }

  void draw_background_part_ext( const int back, const int left, const int top, const int width,
                                 const int height, const double x, const double y, 
                                 const double xscale, const double yscale, const int color, 
                                 const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, left, top, width, height, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_background_part_ext );
  }

  void draw_background_general( const int back, const int left, const int top, const int width,
                                const int height, const double x, const double y,
                                const double xscale, const double yscale, const double rot,
                                const int c1, const int c2, const int c3, const int c4,
                                const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back, left, top, width, height, x, y, xscale, yscale, rot, c1, c2, c3, c4,
                alpha };

    GM_NORMAL_CALL( id_draw_background_general );
  }

  void draw_clear( const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_draw_clear );
  }

  void draw_clear_alpha( const int col, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col, alpha };

    GM_NORMAL_CALL( id_draw_clear_alpha );
  }

  void draw_point( const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_draw_point );
  }

  void draw_line( const double x1, const double y1, const double x2, const double y2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2 };

    GM_NORMAL_CALL( id_draw_line );
  }

  void draw_line_width( const double x1, const double y1, const double x2, const double y2,
                        const double w ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, w };

    GM_NORMAL_CALL( id_draw_line_width );
  }

  void draw_rectangle( const double x1, const double y1, const double x2, const double y2,
                       const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, outline };

    GM_NORMAL_CALL( id_draw_rectangle );
  }

  void draw_roundrect( const double x1, const double y1, const double x2, const double y2,
                       const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, outline };

    GM_NORMAL_CALL( id_draw_roundrect );
  }

  void draw_triangle( const double x1, const double y1, const double x2, const double y2,
                      const double x3, const double y3, const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, x3, y3, outline };

    GM_NORMAL_CALL( id_draw_triangle );
  }

  void draw_circle( const double x, const double y, const double r, const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, r, outline };

    GM_NORMAL_CALL( id_draw_circle );
  }

  void draw_ellipse( const double x1, const double y1, const double x2, const double y2,
                     const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, outline };

    GM_NORMAL_CALL( id_draw_ellipse );
  }

  void draw_set_circle_precision( const int precision ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ precision };

    GM_NORMAL_CALL( id_draw_set_circle_precision );
  }

  void draw_arrow( const double x1, const double y1, const double x2, const double y2,
                   const int size ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, size };

    GM_NORMAL_CALL( id_draw_arrow );
  }

  void draw_button( const double x1, const double y1, const double x2, const double y2,
                    const bool up ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, up };

    GM_NORMAL_CALL( id_draw_button );
  }

  void draw_path( const int path, const double x, const double y, const bool absolute ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, x, y, absolute };

    GM_NORMAL_CALL( id_draw_path );
  }

  void draw_healthbar( const double x1, const double y1, const double x2, const double y2,
                       const double amount, const int backcol, const int mincol,
                       const int maxcol, const double direction, const bool showback,
                       const bool showborder ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, amount, backcol, mincol, maxcol, direction, showback,
                showborder };

    GM_NORMAL_CALL( id_draw_healthbar );
  }

  void draw_set_color( const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_draw_set_color );
  }

  void draw_set_alpha( const double alpha ) {
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

  int make_color_rgb( const int red, const int green, const int blue ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ red, green, blue };

    GM_NORMAL_CALL( id_make_color_rgb );
    GM_RETURN_INT;
  }

  int make_color_hsv( const int hue, const int saturation, const int value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hue, saturation, value };

    GM_NORMAL_CALL( id_make_color_hsv );
    GM_RETURN_INT;
  }

  int color_get_red( const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_red );
    GM_RETURN_INT;
  }

  int color_get_green( const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_green );
    GM_RETURN_INT;
  }

  int color_get_blue( const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_blue );
    GM_RETURN_INT;
  }

  int color_get_hue( const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_hue );
    GM_RETURN_INT;
  }

  int color_get_saturation( const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_saturation );
    GM_RETURN_INT;
  }

  int color_get_value( const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col };

    GM_NORMAL_CALL( id_color_get_value );
    GM_RETURN_INT;
  }

  int merge_color( const int col1, const int col2, const double amount ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ col1, col2, amount };

    GM_NORMAL_CALL( id_merge_color );
    GM_RETURN_INT;
  }

  int draw_getpixel( const double x, const double y ) {
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

  void screen_save_part( const CGMVariable& fname, const int x, const int y, const int w,
                         const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, x, y, w, h };

    GM_NORMAL_CALL( id_screen_save_part );
  }

  void draw_set_font( const int font ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ font };

    GM_NORMAL_CALL( id_draw_set_font );
  }

  void draw_set_halign( const int halign ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ halign };

    GM_NORMAL_CALL( id_draw_set_halign );
  }

  void draw_set_valign( const int valign ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ valign };

    GM_NORMAL_CALL( id_draw_set_valign );
  }

  void draw_text( const double x, const double y, const CGMVariable& string ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string };

    GM_NORMAL_CALL( id_draw_text );
  }

  void draw_text_ext( const double x, const double y, const CGMVariable& string,
                      const double sep, const int w ) {
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

  double string_width_ext( const CGMVariable& string, const double sep, const double w ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ string, sep, w };

    GM_NORMAL_CALL( id_string_width_ext );
    GM_RETURN_REAL;
  }

  double string_height_ext( const CGMVariable& string, const double sep, const double w ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ string, sep, w };

    GM_NORMAL_CALL( id_string_height_ext );
    GM_RETURN_REAL;
  }

  void draw_text_transformed( const double x, const double y, const CGMVariable& string,
                              const double xscale, const double yscale, const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, xscale, yscale, angle };

    GM_NORMAL_CALL( id_draw_text_transformed );
  }

  void draw_text_ext_transformed( const double x, const double y, const CGMVariable& string,
                                  const double sep, const double w, const double xscale,
                                  const double yscale, const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, sep, w, xscale, yscale, angle };

    GM_NORMAL_CALL( id_draw_text_ext_transformed );
  }

  void draw_text_color( const double x, const double y, const CGMVariable& string,
                        const int c1, const int c2, const int c3, const int c4,
                        const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_text_color );
  }

  void draw_text_ext_color( const double x, const double y, const CGMVariable& string,
                            const double sep, const double w, const int c1, const int c2, 
                            const int c3, const int c4, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, sep, w, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_text_ext_color );
  }

  void draw_text_transformed_color( const double x, const double y, const CGMVariable& string,
                                    const double xscale, const double yscale, const double angle,
                                    const int c1, const int c2, const int c3, const int c4,
                                    const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, xscale, yscale, angle, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_text_transformed_color );
  }

  void draw_text_ext_transformed_color( const double x, const double y,
                                        const CGMVariable& string, const double sep,
                                        const double w, const double xscale,
                                        const double yscale, const double angle,
                                        const int c1, const int c2, const int c3, const int c4,
                                        const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, string, sep, w, xscale, yscale, angle, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_text_ext_transformed_color );
  }

  void draw_point_color( const double x, const double y, const int col1 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, col1 };

    GM_NORMAL_CALL( id_draw_point_color );
  }

  void draw_line_color( const double x1, const double y1, const double x2, const double y2,
                        const int col1, const int col2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, col1, col2 };

    GM_NORMAL_CALL( id_draw_line_color );
  }

  void draw_line_width_color( const double x1, const double y1, const double x2, const double y2,
                              const double w, const int col1, const int col2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, w, col1, col2 };

    GM_NORMAL_CALL( id_draw_line_width_color );
  }

  void draw_rectangle_color( const double x1, const double y1, const double x2, const double y2,
                             const int col1, const int col2, const int col3, const int col4,
                             const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, col1, col2, col3, col4, outline };

    GM_NORMAL_CALL( id_draw_rectangle_color );
  }

  void draw_roundrect_color( const double x1, const double y1, const double x2, const double y2,
                             const int col1, const int col2, const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, col1, col2, outline };

    GM_NORMAL_CALL( id_draw_roundrect_color );
  }

  void draw_triangle_color( const double x1, const double y1, const double x2, const double y2,
                            const double x3, const double y3, const int col1, const int col2,
                            const int col3, const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, x3, y3, col1, col2, col3, outline };

    GM_NORMAL_CALL( id_draw_triangle_color );
  }

  void draw_circle_color( const double x, const double y, const double r, const int col1, 
                          const int col2, const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, r, col1, col2, outline };

    GM_NORMAL_CALL( id_draw_circle_color );
  }

  void draw_ellipse_color( const double x1, const double y1, const double x2, const double y2,
                           const int col1, const int col2, const bool outline ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, col1, col2, outline };

    GM_NORMAL_CALL( id_draw_ellipse_color );
  }

  void draw_primitive_begin( const int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind };

    GM_NORMAL_CALL( id_draw_primitive_begin );
  }

  void draw_vertex( const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_draw_vertex );
  }

  void draw_vertex_color( const double x, const double y, const int col, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, col, alpha };

    GM_NORMAL_CALL( id_draw_vertex_color );
  }

  void draw_primitive_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_draw_primitive_end );
  }

  int sprite_get_texture( const int spr, const int subimg ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ spr, subimg };

    GM_NORMAL_CALL( id_sprite_get_texture );
    GM_RETURN_INT;
  }

  int background_get_texture( const int back ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ back };

    GM_NORMAL_CALL( id_background_get_texture );
    GM_RETURN_INT;
  }

  void texture_preload( const int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ texid };

    GM_NORMAL_CALL( id_texture_preload );
  }

  void texture_set_priority( const int texid, const int prio ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ texid, prio };

    GM_NORMAL_CALL( id_texture_set_priority );
  }

  int texture_get_width( const int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ texid };

    GM_NORMAL_CALL( id_texture_get_width );
    GM_RETURN_INT;
  }

  double texture_get_height( const int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ texid };

    GM_NORMAL_CALL( id_texture_get_height );
    GM_RETURN_REAL;
  }

  void draw_primitive_begin_texture( const int kind, const int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind, texid };

    GM_NORMAL_CALL( id_draw_primitive_begin_texture );
  }

  void draw_vertex_texture( const double x, const double y, const double xtex,
                            const double ytex ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, xtex, ytex };

    GM_NORMAL_CALL( id_draw_vertex_texture );
  }

  void draw_vertex_texture_color( const double x, const double y, const double xtex, 
                                  const double ytex, const int col, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, xtex, ytex, col, alpha };

    GM_NORMAL_CALL( id_draw_vertex_texture_color );
  }

  void texture_set_interpolation( const bool linear ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ linear };

    GM_NORMAL_CALL( id_texture_set_interpolation );
  }

  void texture_set_blending( const bool blend ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ blend };

    GM_NORMAL_CALL( id_texture_set_blending );
  }

  void texture_set_repeat( const double repeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ repeat };

    GM_NORMAL_CALL( id_texture_set_repeat );
  }

  void draw_set_blend_mode( const int mode ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ mode };

    GM_NORMAL_CALL( id_draw_set_blend_mode );
  }

  void draw_set_blend_mode_ext( const int src, const int dest ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ src, dest };

    GM_NORMAL_CALL( id_draw_set_blend_mode_ext );
  }

  int surface_create( const int w, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_surface_create );
    GM_RETURN_INT;
  }

  void surface_free( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_free );
  }

  bool surface_exists( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_exists );
    GM_RETURN_BOOL;
  }

  int surface_get_width( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_get_width );
    GM_RETURN_INT;
  }

  int surface_get_height( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_get_height );
    GM_RETURN_INT;
  }

  int surface_get_texture( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_get_texture );
    GM_RETURN_INT;
  }

  void surface_set_target( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_surface_set_target );
  }

  void surface_reset_target() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_surface_reset_target );
  }

  int surface_getpixel( const int id, const int x, const int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_surface_getpixel );
    GM_RETURN_INT;
  }

  void surface_save( const int id, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, fname };

    GM_NORMAL_CALL( id_surface_save );
  }

  void surface_save_part( const int id, const CGMVariable& fname, const int x, const int y,
                          const int w, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, fname, x, y, w, h };

    GM_NORMAL_CALL( id_surface_save_part );
  }

  void draw_surface( const int id, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_draw_surface );
  }

  void draw_surface_stretched( const int id, const double x, const double y, const double w,
                               const double h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h };

    GM_NORMAL_CALL( id_draw_surface_stretched );
  }

  void draw_surface_tiled( const int id, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_draw_surface_tiled );
  }

  void draw_surface_part( const int id, const int left, const int top, const int width,
                          const int height, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, width, height, x, y };

    GM_NORMAL_CALL( id_draw_surface_part );
  }

  void draw_surface_ext( const int id, const double x, const double y, const double xscale,
                         const double yscale, const double rot, const int color,
                         const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, xscale, yscale, rot, color, alpha };

    GM_NORMAL_CALL( id_draw_surface_ext );
  }

  void draw_surface_stretched_ext( const int id, const double x, const double y, const double w,
                                   const double h, const int color, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h, color, alpha };

    GM_NORMAL_CALL( id_draw_surface_stretched_ext );
  }

  void draw_surface_tiled_ext( const int id, const double x, const double y, const double xscale,
                               const double yscale, const int color, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_surface_tiled_ext );
  }

  void draw_surface_part_ext( const int id, const int left, const int top, const int width, 
                              const int height, const double x, const double y,
                              const double xscale, const double yscale, const int color, 
                              const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, width, height, x, y, xscale, yscale, color, alpha };

    GM_NORMAL_CALL( id_draw_surface_part_ext );
  }

  void draw_surface_general( const int id, const int left, const int top, const int width,
                             const int height, const double x, const double y,
                             const double xscale, const double yscale, const double rot,
                             const int c1, const int c2, const int c3, const int c4, 
                             const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, width, height, x, y, xscale, yscale, rot, c1, c2, c3, c4, alpha };

    GM_NORMAL_CALL( id_draw_surface_general );
  }

  void surface_copy( const int destination, const double x, const double y, const int source ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ destination, x, y, source };

    GM_NORMAL_CALL( id_surface_copy );
  }

  void surface_copy_part( const int destination, const double x, const double y, 
                          const int source, const double xs, const double ys, const double ws,
                          const double hs ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ destination, x, y, source, xs, ys, ws, hs };

    GM_NORMAL_CALL( id_surface_copy_part );
  }

  int tile_add( const int background, const int left, const int top, const int width,
                const int height, const double x, const double y, const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ background, left, top, width, height, x, y, depth };

    GM_NORMAL_CALL( id_tile_add );
    GM_RETURN_INT;
  }

  void tile_delete( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_delete );
  }

  bool tile_exists( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_exists );
    GM_RETURN_BOOL;
  }

  double tile_get_x( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_x );
    GM_RETURN_REAL;
  }

  double tile_get_y( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_y );
    GM_RETURN_REAL;
  }

  int tile_get_left( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_left );
    GM_RETURN_INT;
  }

  int tile_get_top( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_top );
    GM_RETURN_INT;
  }

  int tile_get_width( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_width );
    GM_RETURN_INT;
  }

  int tile_get_height( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_height );
    GM_RETURN_INT;
  }

  int tile_get_depth( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_depth );
    GM_RETURN_INT;
  }

  bool tile_get_visible( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_visible );
    GM_RETURN_BOOL;
  }

  double tile_get_xscale( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_xscale );
    GM_RETURN_REAL;
  }

  double tile_get_yscale( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_yscale );
    GM_RETURN_REAL;
  }

  int tile_get_background( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_background );
    GM_RETURN_INT;
  }

  int tile_get_blend( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_blend );
    GM_RETURN_INT;
  }

  double tile_get_alpha( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_tile_get_alpha );
    GM_RETURN_REAL;
  }

  void tile_set_position( const int id, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_tile_set_position );
  }

  void tile_set_region( const int id, const double left, const double right,
                        const double width, const double height ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, right, width, height };

    GM_NORMAL_CALL( id_tile_set_region );
  }

  void tile_set_background( const int id, const int background ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, background };

    GM_NORMAL_CALL( id_tile_set_background );
  }

  void tile_set_visible( const int id, const bool visible ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, visible };

    GM_NORMAL_CALL( id_tile_set_visible );
  }

  void tile_set_depth( const int id, const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, depth };

    GM_NORMAL_CALL( id_tile_set_depth );
  }

  void tile_set_scale( const int id, const double xscale, const double yscale ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xscale, yscale };

    GM_NORMAL_CALL( id_tile_set_scale );
  }

  void tile_set_blend( const int id, const int color ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, color };

    GM_NORMAL_CALL( id_tile_set_blend );
  }

  void tile_set_alpha( const int id, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, alpha };

    GM_NORMAL_CALL( id_tile_set_alpha );
  }

  void tile_layer_hide( const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth };

    GM_NORMAL_CALL( id_tile_layer_hide );
  }

  void tile_layer_show( const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth };

    GM_NORMAL_CALL( id_tile_layer_show );
  }

  void tile_layer_delete( const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth };

    GM_NORMAL_CALL( id_tile_layer_delete );
  }

  void tile_layer_shift( const int depth, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth, x, y };

    GM_NORMAL_CALL( id_tile_layer_shift );
  }

  int tile_layer_find( const int depth, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth, x, y };

    GM_NORMAL_CALL( id_tile_layer_find );
    GM_RETURN_INT;
  }

  void tile_layer_delete_at( const int depth, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth, x, y };

    GM_NORMAL_CALL( id_tile_layer_delete_at );
  }

  void tile_layer_depth( const int depth, const int newdepth ) {
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

  void display_set_size( const int w, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_display_set_size );
  }

  void display_set_colordepth( const int coldepth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ coldepth };

    GM_NORMAL_CALL( id_display_set_colordepth );
  }

  void display_set_frequency( const int frequency ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ frequency };

    GM_NORMAL_CALL( id_display_set_frequency );
  }

  void display_set_all( const int w, const int h, const int frequency, const int coldepth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, frequency, coldepth };

    GM_NORMAL_CALL( id_display_set_all );
  }

  bool display_test_all( const int w, const int h, const int frequency, const int coldepth ) {
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

  void display_mouse_set( const int x, const int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_display_mouse_set );
  }

  void window_set_visible( const bool visible ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ visible };

    GM_NORMAL_CALL( id_window_set_visible );
  }

  bool window_get_visible() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_visible );
    GM_RETURN_BOOL;
  }

  void window_set_fullscreen( const bool full ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ full };

    GM_NORMAL_CALL( id_window_set_fullscreen );
  }

  bool window_get_fullscreen() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_fullscreen );
    GM_RETURN_BOOL;
  }

  void window_set_showborder( const bool show ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ show };

    GM_NORMAL_CALL( id_window_set_showborder );
  }

  bool window_get_showborder() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_showborder );
    GM_RETURN_BOOL;
  }

  void window_set_showicons( const bool show ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ show };

    GM_NORMAL_CALL( id_window_set_showicons );
  }

  bool window_get_showicons() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_showicons );
    GM_RETURN_BOOL;
  }

  void window_set_stayontop( const bool stay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ stay };

    GM_NORMAL_CALL( id_window_set_stayontop );
  }

  bool window_get_stayontop() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_stayontop );
    GM_RETURN_BOOL;
  }

  void window_set_sizeable( const bool sizeable ) {
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

  void window_set_cursor( const int curs ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ curs };

    GM_NORMAL_CALL( id_window_set_cursor );
  }

  int window_get_cursor() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_cursor );
    GM_RETURN_INT;
  }

  void window_set_color( const int color ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ color };

    GM_NORMAL_CALL( id_window_set_color );
  }

  int window_get_color() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_color );
    GM_RETURN_INT;
  }

  void window_set_region_scale( const double scale, const bool adaptwindow ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ scale, adaptwindow };

    GM_NORMAL_CALL( id_window_set_region_scale );
  }

  double window_get_region_scale() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_window_get_region_scale );
    GM_RETURN_REAL;
  }

  void window_set_position( const int x, const int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_window_set_position );
  }

  void window_set_size( const int w, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_window_set_size );
  }

  void window_set_rectangle( const int x, const int y, const int w, const int h ) {
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

  void window_mouse_set( const int x, const int y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_window_mouse_set );
  }

  void window_set_region_size( const int w, const int h, const bool adaptwindow ) {
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

  int window_view_mouse_get_x( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_window_view_mouse_get_x );
    GM_RETURN_INT;
  }

  int window_view_mouse_get_y( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_window_view_mouse_get_y );
    GM_RETURN_INT;
  }

  void window_view_mouse_set( const int id, const int x, const int y ) {
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

  void window_views_mouse_set( const int x, const int y ) {
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

  void set_automatic_draw( const bool value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ value };

    GM_NORMAL_CALL( id_set_automatic_draw );
  }

  void set_synchronization( const bool value ) {
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
