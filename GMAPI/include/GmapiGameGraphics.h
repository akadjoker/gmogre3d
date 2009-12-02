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
  GmapiGameGraphics.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  void draw_sprite( const int sprite, const int subimg, const double x, const double y );
  void draw_sprite_stretched( const int sprite, const int subimg, const double x,
                              const double y, const double w, const double h );
  void draw_sprite_tiled( const int sprite, const int subimg, const double x, const double y );
  void draw_sprite_part( const int sprite, const int subimg, const int left, const int top,
                         const int width, const int height, const double x, const double y );
  void draw_background( const int back, const double x, const double y );
  void draw_background_stretched( const int back, const double x, const double y, 
                                  const double w, const double h );
  void draw_background_tiled( const int back, const double x, const double y );
  void draw_background_part( const int back, const int left, const int top, const int width,
                             const int height, const double x, const double y );
  void draw_sprite_ext( const int sprite, const int subimg, const double x, const double y,
                        const double xscale, const double yscale, const double rot,
                        const int color, const double alpha );
  void draw_sprite_stretched_ext( const int sprite, const int subimg, const double x,
                                  const double y, const double w, const double h,
                                  const int color, const double alpha );
  void draw_sprite_tiled_ext( const int sprite, const int subimg, const double x,
                              const double y, const double xscale, const double yscale,
                              const int color, const double alpha );
  void draw_sprite_part_ext( const int sprite, const int subimg, const int left, const int top,
                             const int width, const int height, const double x, const double y,
                             const double xscale, const double yscale, const int color,
                             const double alpha );
  void draw_sprite_general( const int sprite, const int subimg, const int left, const int top,
                            const int width, const int height, const double x, const double y,
                            const double xscale, const double yscale, const double rot,
                            const int c1, const int c2, const int c3, const int c4,
                            const double alpha );
  
  void draw_background_ext( const int back, const double x, const double y, const double xscale,
                            const double yscale, const double rot, const int color,
                            const double alpha );
  void draw_background_stretched_ext( const int back, const double x, const double y,
                                      const double w, const double h, const int color,
                                      const double alpha );
  void draw_background_tiled_ext( const int back, const double x, const double y,
                                  const double xscale, const double yscale, const int color,
                                  const double alpha );
  void draw_background_part_ext( const int back, const int left, const int top, const int width,
                                 const int height, const double x, const double y,
                                 const double xscale, const double yscale, const int color,
                                 const double alpha );
  void draw_background_general( const int back, const int left, const int top, const int width,
                                const int height, const double x, const double y,
                                const double xscale, const double yscale, const double rot,
                                const int c1, const int c2, const int c3, const int c4,
                                const double alpha );
  void draw_clear( const int col );
  void draw_clear_alpha( const int col, const double alpha );
  
  void draw_point( const double x, const double y );
  void draw_line( const double x1, const double y1, const double x2, const double y2 );
  void draw_line_width( const double x1, const double y1, const double x2, const double y2,
                        const double w );
  void draw_rectangle( const double x1, const double y1, const double x2, const double y2,
                       const bool outline );
  void draw_roundrect( const double x1, const double y1, const double x2, const double y2,
                       const bool outline );
  void draw_triangle( const double x1, const double y1, const double x2, const double y2,
                      const double x3, const double y3, const bool outline );
  void draw_circle( const double x, const double y, const double r, const bool outline );
  void draw_ellipse( const double x1, const double y1, const double x2, const double y2,
                     const bool outline );
  void draw_set_circle_precision( const int precision );
  void draw_arrow( const double x1, const double y1, const double x2, const double y2,
                   const int size );
  
  void draw_button( const double x1, const double y1, const double x2, const double y2,
                    const bool up );
  void draw_path( const int path, const double x, const double y, const bool absolute );
  void draw_healthbar( const double x1, const double y1, const double x2, const double y2,
                       const double amount, const int backcol, const int mincol,
                       const int maxcol, const double direction, const bool showback,
                       const bool showborder );
  
  void draw_set_color( const int col );
  void draw_set_alpha( const double alpha );
  int draw_get_color();
  double draw_get_alpha();

  int make_color_rgb( const int red, const int green, const int blue );
  int make_color_hsv( const int hue, const int saturation, const int value );
  int color_get_red( const int col );
  int color_get_green( const int col );
  int color_get_blue( const int col );
  int color_get_hue( const int col );
  int color_get_saturation( const int col );
  int color_get_value( const int col );
  int merge_color( const int col1, const int col2, const double amount );

  int draw_getpixel( const double x, const double y );

  void screen_save( const CGMVariable& fname );
  void screen_save_part( const CGMVariable& fname, const int x, const int y,
                         const int w, const int h );

  void draw_set_font( const int font );
  void draw_set_halign( const int halign );
  void draw_set_valign( const int valign );

  void draw_text( const double x, const double y, const CGMVariable& string );
  void draw_text_ext( const double x, const double y, const CGMVariable& string,
                      const double sep, const int w );

  double string_width( const CGMVariable& string );
  double string_height( const CGMVariable& string );
  double string_width_ext( const CGMVariable& string, const double sep, const double w );
  double string_height_ext( const CGMVariable& string, const double sep, const double w );

  void draw_text_transformed( const double x, const double y, const CGMVariable& string, 
                              const double xscale, const double yscale, const double angle );
  void draw_text_ext_transformed( const double x, const double y, const CGMVariable& string,
                                  const double sep, const double w, const double xscale,
                                  const double yscale, const double angle );
  void draw_text_color( const double x, const double y, const CGMVariable& string,
                        const int c1, const int c2, const int c3, const int c4, 
                        const double alpha );
  void draw_text_ext_color( const double x, const double y, const CGMVariable& string,
                            const double sep, const double w, const int c1, const int c2,
                            const int c3, const int c4, const double alpha );
  void draw_text_transformed_color( const double x, const double y, const CGMVariable& string,
                                    const double xscale, const double yscale, const double angle,
                                    const int c1, const int c2, const int c3, const int c4,
                                    const double alpha );
  void draw_text_ext_transformed_color( const double x, const double y, 
                                        const CGMVariable& string, const double sep,
                                        const double w, const double xscale,
                                        const double yscale, const double angle, const int c1,
                                        const int c2, const int c3, const int c4,
                                        const double alpha );
  
  void draw_point_color( const double x, const double y, const int col1 );
  void draw_line_color( const double x1, const double y1, const double x2, const double y2,
                        const int col1, const int col2 );
  void draw_line_width_color( const double x1, const double y1, const double x2,
                              const double y2, const double w, const int col1, const int col2 );
  void draw_rectangle_color( const double x1, const double y1, const double x2, const double y2,
                             const int col1, const int col2, const int col3, const int col4,
                             const bool outline );
  void draw_roundrect_color( const double x1, const double y1, const double x2, const double y2,
                             const int col1, const int col2, const bool outline );
  void draw_triangle_color( const double x1, const double y1, const double x2, const double y2,
                            const double x3, const double y3, const int col1, const int col2,
                            const int col3, const bool outline );
  void draw_circle_color( const double x, const double y, const double r, const int col1,
                          const int col2, const bool outline );
  void draw_ellipse_color( const double x1, const double y1, const double x2, const double y2,
                           const int col1, const int col2, const bool outline );
  
  void draw_primitive_begin( const int kind );
  void draw_vertex( const double x, const double y );
  void draw_vertex_color( const double x, const double y, const int col, const double alpha );
  void draw_primitive_end();

  int sprite_get_texture( const int spr, const int subimg );
  int background_get_texture( const int back );
  
  void texture_preload( const int texid );
  void texture_set_priority( const int texid, const int prio );
  int texture_get_width( const int texid );
  double texture_get_height( const int texid );
  void draw_primitive_begin_texture( const int kind, const int texid );
  void draw_vertex_texture( const double x, const double y, const double xtex,
                            const double ytex );
  void draw_vertex_texture_color( const double x, const double y, const double xtex,
                                  const double ytex, const int col, const double alpha );
  void draw_primitive_end();
  void texture_set_interpolation( const bool linear );
  void texture_set_blending( const bool blend );
  void texture_set_repeat( const double repeat );
  void draw_set_blend_mode( const int mode );
  void draw_set_blend_mode_ext( const int src, const int dest );
  
  int surface_create( const int w, const int h );
  void surface_free( const int id );
  bool surface_exists( const int id );
  int surface_get_width( const int id );
  int surface_get_height( const int id );
  int surface_get_texture( const int id );
  void surface_set_target( const int id );
  void surface_reset_target();
  int surface_getpixel( const int id, const int x, const int y );
  void surface_save( const int id, const CGMVariable& fname );
  void surface_save_part( const int id, const CGMVariable& fname, const int x, const int y,
                          const int w, const int h );
  
  void draw_surface( const int id, const double x, const double y );
  void draw_surface_stretched( const int id, const double x, const double y, const double w,
                               const double h );
  void draw_surface_tiled( const int id, const double x, const double y );
  void draw_surface_part( const int id, const int left, const int top, const int width,
                          const int height, const double x, const double y );
  void draw_surface_ext( const int id, const double x, const double y, const double xscale,
                         const double yscale, const double rot, const int color,
                         const double alpha );
  void draw_surface_stretched_ext( const int id, const double x, const double y, const double w,
                                   const double h, const int color, const double alpha );
  void draw_surface_tiled_ext( const int id, const double x, const double y, const double xscale,
                               const double yscale, const int color, const double alpha );
  void draw_surface_part_ext( const int id, const int left, const int top, const int width,
                              const int height, const double x, const double y, 
                              const double xscale, const double yscale, const int color,
                              const double alpha );
  void draw_surface_general( const int id, const int left, const int top, const int width,
                             const int height, const double x, const double y, 
                             const double xscale, const double yscale, const double rot,
                             const int c1, const int c2, const int c3, const int c4,
                             const double alpha );
  
  void surface_copy( const int destination, const double x, const double y, const int source );
  void surface_copy_part( const int destination, const double x, const double y, 
                          const int source, const double xs, const double ys, const double ws,
                          const double hs );
  
  int tile_add( const int background, const int left, const int top, const int width,
                const int height, const double x, const double y, const int depth );
  void tile_delete( const int id );
  bool tile_exists( const int id );
  double tile_get_x( const int id );
  double tile_get_y( const int id );
  int tile_get_left( const int id );
  int tile_get_top( const int id );
  int tile_get_width( const int id );
  int tile_get_height( const int id );
  int tile_get_depth( const int id );
  bool tile_get_visible( const int id );
  double tile_get_xscale( const int id );
  double tile_get_yscale( const int id );
  int tile_get_background( const int id );
  int tile_get_blend( const int id );
  double tile_get_alpha( const int id );
  void tile_set_position( const int id, const double x, const double y );
  void tile_set_region( const int id, const double left, const double right, const double width,
                        const double height );
  void tile_set_background( const int id, const int background );
  void tile_set_visible( const int id, const bool visible );
  void tile_set_depth( const int id, const int depth );
  void tile_set_scale( const int id, const double xscale, const double yscale );
  void tile_set_blend( const int id, const int color );
  void tile_set_alpha( const int id, const double alpha );

  void tile_layer_hide( const int depth );
  void tile_layer_show( const int depth );
  void tile_layer_delete( const int depth );
  void tile_layer_shift( const int depth, const double x, const double y );
  int tile_layer_find( const int depth, const double x, const double y );
  void tile_layer_delete_at( const int depth, const double x, const double y );
  void tile_layer_depth( const int depth, const int newdepth );

  int display_get_width();
  int display_get_height();
  int display_get_colordepth();
  int display_get_frequency();
  void display_set_size( const int w, const int h );
  void display_set_colordepth( const int coldepth );
  void display_set_frequency( const int frequency );
  void display_set_all( const int w, const int h, const int frequency, const int coldepth );
  bool display_test_all( const int w, const int h, const int frequency, const int coldepth );
  void display_reset();

  int display_mouse_get_x();
  int display_mouse_get_y();
  void display_mouse_set( const int x, const int y );

  void window_set_visible( const bool visible );
  bool window_get_visible();
  void window_set_fullscreen( const bool full );
  bool window_get_fullscreen();
  void window_set_showborder( const bool show );
  bool window_get_showborder();
  void window_set_showicons( const bool show );
  bool window_get_showicons();
  void window_set_stayontop( const bool stay );
  bool window_get_stayontop();
  void window_set_sizeable( const bool sizeable );
  bool window_get_sizeable();
  void window_set_caption( const CGMVariable& caption );
  CGMVariable window_get_caption();
  void window_set_cursor( const int curs );
  int window_get_cursor();
  void window_set_color( const int color );
  int window_get_color();
  void window_set_region_scale( const double scale, const bool adaptwindow );
  double window_get_region_scale();
  void window_set_position( const int x, const int y );
  void window_set_size( const int w, const int h );
  void window_set_rectangle( const int x, const int y, const int w, const int h );
  void window_center();
  void window_default();
  int window_get_x();
  int window_get_y();
  int window_get_width();
  int window_get_height();
  int window_mouse_get_x();
  int window_mouse_get_y();
  void window_mouse_set( const int x, const int y );
  void window_set_region_size( const int w, const int h, const bool adaptwindow );
  int window_get_region_width();
  int window_get_region_height();
  int window_view_mouse_get_x( const int id );
  int window_view_mouse_get_y( const int id );
  void window_view_mouse_set( const int id, const int x, const int y );
  int window_views_mouse_get_x();
  int window_views_mouse_get_y();
  void window_views_mouse_set( const int x, const int y );

  void screen_redraw();
  void screen_refresh();

  void set_automatic_draw( const bool value );
  void set_synchronization( const bool value );
  void screen_wait_vsync();

  HWND window_handle();
}
