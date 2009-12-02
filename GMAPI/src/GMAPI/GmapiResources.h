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
  GmapiResources.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {
  CGMVariable script_execute( const int ind, const CGMVariable* aArguments = NULL,
                              int aArgCount = 0 );
  CGMVariable execute_string( const CGMVariable& str, const CGMVariable* aArguments = NULL,
                              int aArgCount = 0 );
  CGMVariable execute_file( const CGMVariable& fname, const CGMVariable* aArguments = NULL,
                            int aArgCount = 0 ); 

  int external_define( const CGMVariable& dll, const CGMVariable& name, const int calltype, 
                       const int restype, const int argnumb, const int* aArgTypes );
  CGMVariable external_call( const int id, const CGMVariable* aArguments, int aArgCount );
  void external_free( const CGMVariable& dll );

  void sprite_set_offset( const int ind, const int xoff, const int yoff );
  void sprite_set_bbox_mode( const int ind, const int mode );
  void sprite_set_bbox( const int ind, const int left, const int top, const int right,
                        const int bottom );
  void sprite_set_precise( const int ind, const bool mode );
  int sprite_duplicate( const int ind );
  void sprite_assign( const int ind, const int spr );
  void sprite_merge( const int ind1, const int ind2 );
  int sprite_add( const CGMVariable& fname, const int imgnumb, const bool precise,
                  const bool transparent, const bool smooth, const bool preload,
                  const int xorig, const int yorig );
  int sprite_add_alpha( const CGMVariable& fname, const int imgnumb, const bool precise,
                        const bool preload, const int xorig, const int yorig );
  void sprite_replace( const int ind, const CGMVariable& fname, const int imgnumb,
                       const bool precise, const bool transparent, const bool smooth,
                       const bool preload, const int xorig, const int yorig );
  void sprite_replace_alpha( const int ind, const CGMVariable& fname, const int imgnumb,
                             const bool precise, const bool preload, const int xorig,
                             const int yorig );
  int sprite_create_from_screen( const int x, const int y, const int w, const int h,
                                 const bool precise, const bool transparent,
                                 const bool smooth, const bool preload, const int xorig,
                                 const int yorig );
  void sprite_add_from_screen( const int ind, const int x, const int y, const int w,
                               const int h );
  int sprite_create_from_surface( const int id, const int x, const int y, const int w,
                                  const int h, const bool precise, const bool transparent,
                                  const bool smooth, const bool preload, const int xorig,
                                  const int yorig );
  void sprite_add_from_surface( const int ind, const int id, const int x, const int y,
                                const int w, const int h );
  void sprite_delete( const int ind );
  void sprite_set_alpha_from_sprite( const int ind, const int spr );

  int sound_add( const CGMVariable& fname, const int kind, const bool preload );
  void sound_replace( const int index, const CGMVariable& fname, const int kind, 
                      const bool preload );
  void sound_delete( const int index );

  int background_duplicate( const int ind );
  void background_assign( const int ind, const int back );
  int background_add( const CGMVariable& fname, const bool transparent, const bool smooth,
                      const bool preload );
  int background_add_alpha( const CGMVariable& fname, const bool preload );
  void background_replace( const int ind, const CGMVariable& fname, const bool transparent,
                           const bool smooth, const bool preload );
  void background_replace_alpha( const int ind, const CGMVariable& fname, const bool preload );
  int background_create_color( const int w, const int h, const int col, const bool preload );
  int background_create_gradient( const int w, const int h, const int col1, const int col2,
                                  const int kind, const bool preload );
  int background_create_from_screen( const int x, const int y, const int w, const int h,
                                     const bool transparent, const bool smooth, 
                                     const bool preload );
  int background_create_from_surface( const int id, const int x, const int y, const int w,
                                      const int h, const bool transparent, const bool smooth,
                                      const bool preload );
  void background_delete( const int ind );
  void background_set_alpha_from_background( const int ind, const int back );

  int font_add( const CGMVariable& name, const int size, const bool bold, const bool italic,
                const int first, const int last );
  int font_add_sprite( const int spr, const int first, const bool prop, const int sep );
  void font_replace( const int ind, const CGMVariable& name, const int size, const bool bold, 
                     const bool italic, const int first, const int last );
  void font_replace_sprite( const int ind, const int spr, const int first, const bool prop,
                            const int sep );
  void font_delete( const int ind );

  void path_set_kind( const int ind, const int val );
  void path_set_closed( const int ind, const bool closed );
  void path_set_precision( const int ind, const int prec );
  int path_add();
  void path_delete( const int ind );
  int path_duplicate( const int ind );
  void path_assign( const int ind, const int path );
  void path_append( const int ind, const int path );
  void path_add_point( const int ind, const double x, const double y, const double speed );
  void path_insert_point( const int ind, const int n, const double x, const double y,
                          const double speed );
  void path_change_point( const int ind, const int n, const double x, const double y,
                          const double speed );
  void path_delete_point( const int ind, const int n );
  void path_clear_points( const int ind );
  void path_reverse( const int ind );
  void path_mirror( const int ind );
  void path_flip( const int ind );
  void path_rotate( const int ind, const double angle );
  void path_scale( const int ind, const double xscale, const double yscale );
  void path_shift( const int ind, const double xshift, const double yshift );

  int timeline_add();
  void timeline_delete( const int ind );
  void timeline_moment_add( const int ind, const int step, const CGMVariable& codestr );
  void timeline_moment_clear( const int ind, const int step );

  void object_set_sprite( const int ind, const int spr );
  void object_set_solid( const int ind, const bool solid );
  void object_set_visible( const int ind, const bool vis );
  void object_set_depth( const int ind, const int depth );
  void object_set_persistent( const int ind, const bool pers );
  void object_set_mask( const int ind, const int spr );
  void object_set_parent( const int ind, const int obj );
  int object_add();
  void object_delete( const int ind );
  void object_event_add( const int ind, const int evtype, const int evnumb, 
                         const CGMVariable& codestr );
  void object_event_clear( const int ind, const int evtype, const int evnumb );

  void room_set_width( const int ind, const int w );
  void room_set_height( const int ind, const int h );
  void room_set_caption( const int ind, const CGMVariable& str );
  void room_set_persistent( const int ind, const bool val );
  void room_set_code( const int ind, const CGMVariable& str );
  void room_set_background_color( const int ind, const int col, const bool show );
  void room_set_background( const int ind, const int bind, const bool vis, const bool fore,
                            const int back, const int x, const int y, const bool htiled,
                            const bool vtiled, const double hspeed, const double vspeed,
                            const double alpha );
  void room_set_view( const int ind, const int vind, const bool vis, const int xview,
                      const int yview, const int wview, const int hview, const int xport,
                      const int yport, const int wport, const int hport, const int hborder,
                      const int vborder, const double hspeed, const double vspeed,
                      const int obj );
  void room_set_view_enabled( const int ind, const int val );
  int room_add();
  void room_duplicate( const int ind );
  void room_assign( const int ind, const int room );
  int room_instance_add( const int ind, const double x, const double y, const int obj );
  void room_instance_clear( const int ind );
  int room_tile_add( const int ind, const int back, const int left, const int top, 
                     const int width, const int height, const double x, const double y,
                     const int depth );
  int room_tile_add_ext( const int ind, const int back, const int left, const int top,
                         const int width, const int height, const double x, const double y, 
                         const int depth, const double xscale, const double yscale,
                         const double alpha );
  void room_tile_clear( const int ind );

  bool sprite_exists( const int ind );
  CGMVariable sprite_get_name( const int ind );
  int sprite_get_number( const int ind );
  int sprite_get_width( const int ind );
  int sprite_get_height( const int ind );
  bool sprite_get_transparent( const int ind );
  bool sprite_get_smooth( const int ind );
  bool sprite_get_preload( const int ind );
  int sprite_get_xoffset( const int ind );
  int sprite_get_yoffset( const int ind );
  int sprite_get_bbox_left( const int ind );
  int sprite_get_bbox_right( const int ind );
  int sprite_get_bbox_top( const int ind );
  int sprite_get_bbox_bottom( const int ind );
  int sprite_get_bbox_mode( const int ind );
  bool sprite_get_precise( const int ind );
  void sprite_save( const int ind, const int subimg, const CGMVariable& fname );

  bool sound_exists( const int ind );
  CGMVariable sound_get_name( const int ind );
  int sound_get_kind( const int ind );
  bool sound_get_preload( const int ind );
  void sound_discard( const int index );
  void sound_restore( const int index );

  bool background_exists( const int ind );
  CGMVariable background_get_name( const int ind );
  int background_get_width( const int ind );
  int background_get_height( const int ind );
  bool background_get_transparent( const int ind );
  bool background_get_smooth( const int ind );
  bool background_get_preload( const int ind );
  void background_save( const int ind, const CGMVariable& fname );

  bool font_exists( const int ind );
  CGMVariable font_get_name( const int ind );
  CGMVariable font_get_fontname( const int ind );
  bool font_get_bold( const int ind );
  bool font_get_italic( const int ind );
  int font_get_first( const int ind );
  int font_get_last( const int ind );

  bool path_exists( const int ind );
  CGMVariable path_get_name( const int ind );
  int path_get_length( const int ind );
  int path_get_kind( const int ind );
  bool path_get_closed( const int ind );
  bool path_get_precision( const int ind );
  int path_get_number( const int ind );
  double path_get_point_x( const int ind, const int n );
  double path_get_point_y( const int ind, const int n );
  double path_get_point_speed( const int ind, const int n );
  double path_get_x( const int ind, const double pos );
  double path_get_y( const int ind, const double pos );
  double path_get_speed( const int ind, const double pos );

  bool script_exists( const int ind );
  CGMVariable script_get_name( const int ind );
  CGMVariable script_get_text( const int ind );

  bool timeline_exists( const int ind );
  CGMVariable timeline_get_name( const int ind );

  bool object_exists( const int ind );
  CGMVariable object_get_name( const int ind );
  int object_get_sprite( const int ind );
  bool object_get_solid( const int ind );
  bool object_get_visible( const int ind );
  int object_get_depth( const int ind );
  bool object_get_persistent( const int ind );
  int object_get_mask( const int ind );
  int object_get_parent( const int ind );
  bool object_is_ancestor( const int ind1, const int ind2 );

  bool room_exists( const int ind );
  CGMVariable room_get_name( const int ind );

}