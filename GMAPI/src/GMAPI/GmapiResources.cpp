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
  GmapiResources.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiResources.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

using namespace gm::core;

namespace gm {

  CGMVariable script_execute( const int ind, const CGMVariable* aArguments, int aArgCount ) {
    GM_VAR_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[aArgCount + 1];
    ZeroMemory( argument, sizeof( GMVALUE ) * (aArgCount + 1) );

    argument[0] = ind;

    for ( int i = 0; i < aArgCount; i++ )
      argument[i + 1] = aArguments[i];

    GMCallFunction( CGMAPI::GMAPIFunctionArray( id_script_execute ), argument, aArgCount + 1,
                    &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_VAR;
  }

  CGMVariable execute_string( const CGMVariable& str, const CGMVariable* aArguments, int aArgCount ) {
    GM_VAR_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[aArgCount + 1];
    ZeroMemory( argument, sizeof( GMVALUE ) * (aArgCount + 1) );

    argument[0] = str;

    for ( int i = 0; i < aArgCount; i++ )
      argument[i + 1] = aArguments[i];

    GMCallFunction( CGMAPI::GMAPIFunctionArray( id_execute_string ), argument, aArgCount + 1,
                    &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_VAR;
  }

  CGMVariable execute_file( const CGMVariable& fname, const CGMVariable* aArguments, int aArgCount ) {
    GM_VAR_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[aArgCount + 1];
    ZeroMemory( argument, sizeof( GMVALUE ) * (aArgCount + 1) );

    argument[0] = fname;

    for ( int i = 0; i < aArgCount; i++ )
      argument[i + 1] = aArguments[i];

    GMCallFunction( CGMAPI::GMAPIFunctionArray( id_execute_file ), argument, aArgCount + 1,
                    &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_VAR;
  }

  int external_define( const CGMVariable& dll, const CGMVariable& name, const int calltype,
                       const int restype, const int argnumb, const int* aArgTypes ) {
    GM_NORMAL_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[argnumb + 5];
    ZeroMemory( argument, sizeof( GMVALUE ) * (argnumb + 5) );

    argument[0] = dll;
    argument[1] = name;
    argument[2] = calltype;
    argument[3] = restype;
    argument[4] = argnumb;

    for ( int i = 0; i < argnumb; i++ )
      argument[i + 5] = aArgTypes[i];

    GMCallFunction( CGMAPI::GMAPIFunctionArray( id_external_call ), argument, argnumb + 5,
                    &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_INT;
  }

  CGMVariable external_call( const int id, const CGMVariable* aArguments, int aArgCount ) {
    GM_VAR_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[aArgCount + 1];
    ZeroMemory( argument, sizeof( GMVALUE ) * (aArgCount + 1) );

    argument[0] = id;

    for ( int i = 0; i < aArgCount; i++ )
      argument[i + 1] = aArguments[i];

    GMCallFunction( CGMAPI::GMAPIFunctionArray( id_external_call ), argument, aArgCount + 1,
                    &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_VAR;
  }

  void external_free( const CGMVariable& dll ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dll };

    GM_NORMAL_CALL( id_external_free );
  }

  void sprite_set_offset( const int ind, const int xoff, const int yoff ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, xoff, yoff };

    GM_NORMAL_CALL( id_sprite_set_offset );
  }

  void sprite_set_bbox_mode( const int ind, const int mode ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, mode };

    GM_NORMAL_CALL( id_sprite_set_bbox_mode );
  }

  void sprite_set_bbox( const int ind, const int left, const int top, const int right,
                        const int bottom ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, left, top, right, bottom };

    GM_NORMAL_CALL( id_sprite_set_bbox );
  }

  void sprite_set_precise( const int ind, const bool mode ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, mode };

    GM_NORMAL_CALL( id_sprite_set_precise );
  }

  int sprite_duplicate( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_duplicate );
    GM_RETURN_INT;
  }

  void sprite_assign( const int ind, const int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr };

    GM_NORMAL_CALL( id_sprite_assign );
  }

  void sprite_merge( const int ind1, const int ind2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind1, ind2 };

    GM_NORMAL_CALL( id_sprite_merge );
  }

  int sprite_add( const CGMVariable& fname, const int imgnumb, const bool precise,
                  const bool transparent, const bool smooth, const bool preload,
                  const int xorig, const int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, imgnumb, precise, transparent, smooth, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_add );
    GM_RETURN_INT;
  }

  int sprite_add_alpha( const CGMVariable& fname, const int imgnumb, const bool precise,
                        const bool preload, const int xorig, const int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, imgnumb, precise, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_add_alpha );
    GM_RETURN_INT;
  }

  void sprite_replace( const int ind, const CGMVariable& fname, const int imgnumb, 
                       const bool precise, const bool transparent, const bool smooth,
                       const bool preload, const int xorig, const int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, imgnumb, precise, transparent, smooth, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_replace );
  }

  void sprite_replace_alpha( const int ind, const CGMVariable& fname, const int imgnumb,
                             const bool precise, const bool preload, const int xorig,
                             const int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, imgnumb, precise, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_replace_alpha );
  }

  int sprite_create_from_screen( const int x, const int y, const int w, const int h,
                                 const bool precise, const bool transparent, const bool smooth,
                                 const bool preload, const int xorig, const int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, precise, transparent, smooth, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_create_from_screen );
    GM_RETURN_INT;
  }

  void sprite_add_from_screen( const int ind, const int x, const int y, const int w, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, w, h };

    GM_NORMAL_CALL( id_sprite_add_from_screen );
  }

  int sprite_create_from_surface( const int id, const int x, const int y, const int w,
                                  const int h, const bool precise, const bool transparent,
                                  const bool smooth, const bool preload, const int xorig,
                                  const int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h, precise, transparent, smooth, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_create_from_surface );
    GM_RETURN_INT;
  }

  void sprite_add_from_surface( const int ind, const int id, const int x, const int y,
                                const int w, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, id, x, y, w, h };

    GM_NORMAL_CALL( id_sprite_add_from_surface );
  }

  void sprite_delete( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_delete );
  }

  void sprite_set_alpha_from_sprite( const int ind, const int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr };

    GM_NORMAL_CALL( id_sprite_set_alpha_from_sprite );
  }

  int sound_add( const CGMVariable& fname, const int kind, const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, kind, preload };

    GM_NORMAL_CALL( id_sound_add );
    GM_RETURN_INT;
  }

  void sound_replace( const int index, const CGMVariable& fname, const int kind,
                      const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index, fname, kind, preload };

    GM_NORMAL_CALL( id_sound_replace );
  }

  void sound_delete( const int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_delete );
  }

  int background_duplicate( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_duplicate );
    GM_RETURN_INT;
  }

  void background_assign( const int ind, const int back ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, back };

    GM_NORMAL_CALL( id_background_assign );
  }

  int background_add( const CGMVariable& fname, const bool transparent, const bool smooth,
                      const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, transparent, smooth, preload };

    GM_NORMAL_CALL( id_background_add );
    GM_RETURN_INT;
  }

  int background_add_alpha( const CGMVariable& fname, const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, preload };

    GM_NORMAL_CALL( id_background_add_alpha );
    GM_RETURN_INT;
  }

  void background_replace( const int ind, const CGMVariable& fname, const bool transparent,
                           const bool smooth, const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, transparent, smooth, preload };

    GM_NORMAL_CALL( id_background_replace );
  }

  void background_replace_alpha( const int ind, const CGMVariable& fname, const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, preload };

    GM_NORMAL_CALL( id_background_replace_alpha );
  }

  int background_create_color( const int w, const int h, const int col, const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, col, preload };

    GM_NORMAL_CALL( id_background_create_color );
    GM_RETURN_INT;
  }

  int background_create_gradient( const int w, const int h, const int col1, const int col2,
                                  const int kind, const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, col1, col2, kind, preload };

    GM_NORMAL_CALL( id_background_create_gradient );
    GM_RETURN_INT;
  }

  int background_create_from_screen( const int x, const int y, const int w, const int h,
                                     const bool transparent, const bool smooth, 
                                     const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, transparent, smooth, preload };

    GM_NORMAL_CALL( id_background_create_from_screen );
    GM_RETURN_INT;
  }

  int background_create_from_surface( const int id, const int x, const int y, const int w,
                                      const int h, const bool transparent, const bool smooth,
                                      const bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h, transparent, smooth, preload };

    GM_NORMAL_CALL( id_background_create_from_surface );
    GM_RETURN_INT;
  }

  void background_delete( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_delete );
  }

  void background_set_alpha_from_background( const int ind, const int back ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, back };

    GM_NORMAL_CALL( id_background_set_alpha_from_background );
  }

  int font_add( const CGMVariable& name, const int size, const bool bold, const bool italic,
                const int first, const int last ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, size, bold, italic, first, last };

    GM_NORMAL_CALL( id_font_add );
    GM_RETURN_INT;
  }

  int font_add_sprite( const int spr, const int first, const bool prop, const int sep ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ spr, first, prop, sep };

    GM_NORMAL_CALL( id_font_add_sprite );
    GM_RETURN_INT;
  }

  void font_replace( const int ind, const CGMVariable& name, const int size, const bool bold,
                     const bool italic, const int first, const int last ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, name, size, bold, italic, first, last };

    GM_NORMAL_CALL( id_font_replace );
  }

  void font_replace_sprite( const int ind, const int spr, const int first, const bool prop,
                            const int sep ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr, first, prop, sep };

    GM_NORMAL_CALL( id_font_replace_sprite );
  }

  void font_delete( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_delete );
  }

  void path_set_kind( const int ind, const int val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, val };

    GM_NORMAL_CALL( id_path_set_kind );
  }

  void path_set_closed( const int ind, const bool closed ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, closed };

    GM_NORMAL_CALL( id_path_set_closed );
  }

  void path_set_precision( const int ind, const int prec ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, prec };

    GM_NORMAL_CALL( id_path_set_precision );
  }

  int path_add() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_path_add );
    GM_RETURN_INT;
  }

  void path_delete( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_delete );
  }

  int path_duplicate( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_duplicate );
    GM_RETURN_INT;
  }

  void path_assign( const int ind, const int path ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, path };

    GM_NORMAL_CALL( id_path_assign );
  }

  void path_append( const int ind, const int path ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, path };

    GM_NORMAL_CALL( id_path_append );
  }

  void path_add_point( const int ind, const double x, const double y, const double speed ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, speed };

    GM_NORMAL_CALL( id_path_add_point );
  }

  void path_insert_point( const int ind, const int n, const double x, const double y,
                          const double speed ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n, x, y, speed };

    GM_NORMAL_CALL( id_path_insert_point );
  }

  void path_change_point( const int ind, const int n, const double x, const double y,
                          const double speed ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n, x, y, speed };

    GM_NORMAL_CALL( id_path_change_point );
  }

  void path_delete_point( const int ind, const int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n };

    GM_NORMAL_CALL( id_path_delete_point );
  }

  void path_clear_points( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_clear_points );
  }

  void path_reverse( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_reverse );
  }

  void path_mirror( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_mirror );
  }

  void path_flip( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_flip );
  }

  void path_rotate( const int ind, const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, angle };

    GM_NORMAL_CALL( id_path_rotate );
  }

  void path_scale( const int ind, const double xscale, const double yscale ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, xscale, yscale };

    GM_NORMAL_CALL( id_path_scale );
  }

  void path_shift( const int ind, const double xshift, const double yshift ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, xshift, yshift };

    GM_NORMAL_CALL( id_path_shift );
  }

  int timeline_add() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_timeline_add );
    GM_RETURN_INT;
  }

  void timeline_delete( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_timeline_delete );
  }

  void timeline_moment_add( const int ind, const int step, const CGMVariable& codestr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, step, codestr };

    GM_NORMAL_CALL( id_timeline_moment_add );
  }

  void timeline_moment_clear( const int ind, const int step ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, step };

    GM_NORMAL_CALL( id_timeline_moment_clear );
  }

  void object_set_sprite( const int ind, const int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr };

    GM_NORMAL_CALL( id_object_set_sprite );
  }

  void object_set_solid( const int ind, const bool solid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, solid };

    GM_NORMAL_CALL( id_object_set_solid );
  }

  void object_set_visible( const int ind, const bool vis ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, vis };

    GM_NORMAL_CALL( id_object_set_visible );
  }

  void object_set_depth( const int ind, const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, depth };

    GM_NORMAL_CALL( id_object_set_depth );
  }

  void object_set_persistent( const int ind, const bool pers ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, pers };

    GM_NORMAL_CALL( id_object_set_persistent );
  }

  void object_set_mask( const int ind, const int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr };

    GM_NORMAL_CALL( id_object_set_mask );
  }

  void object_set_parent( const int ind, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, obj };

    GM_NORMAL_CALL( id_object_set_parent );
  }

  int object_add() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_object_add );
    GM_RETURN_INT;
  }

  void object_delete( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_delete );
  }

  void object_event_add( const int ind, const int evtype, const int evnumb,
                         const CGMVariable& codestr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, evtype, evnumb, codestr };

    GM_NORMAL_CALL( id_object_event_add );
  }

  void object_event_clear( const int ind, const int evtype, const int evnumb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, evtype, evnumb };

    GM_NORMAL_CALL( id_object_event_clear );
  }

  void room_set_width( const int ind, const int w ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, w };

    GM_NORMAL_CALL( id_room_set_width );
  }

  void room_set_height( const int ind, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, h };

    GM_NORMAL_CALL( id_room_set_height );
  }

  void room_set_caption( const int ind, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, str };

    GM_NORMAL_CALL( id_room_set_caption );
  }

  void room_set_persistent( const int ind, const bool val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, val };

    GM_NORMAL_CALL( id_room_set_persistent );
  }

  void room_set_code( const int ind, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, str };

    GM_NORMAL_CALL( id_room_set_code );
  }

  void room_set_background_color( const int ind, const int col, const bool show ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, col, show };

    GM_NORMAL_CALL( id_room_set_background_color );
  }

  void room_set_background( const int ind, const int bind, const bool vis, const bool fore,
                            const int back, const int x, const int y, const bool htiled,
                            const bool vtiled, const double hspeed, const double vspeed,
                            const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, bind, vis, fore, back, x, y, htiled, vtiled, hspeed, vspeed, alpha };

    GM_NORMAL_CALL( id_room_set_background );
  }

  void room_set_view( const int ind, const int vind, const bool vis, const int xview,
                      const int yview, const int wview, const int hview, const int xport,
                      const int yport, const int wport, const int hport, const int hborder,
                      const int vborder, const double hspeed, const double vspeed,
                      const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, vind, vis, xview, yview, wview, hview, xport, yport, wport, hport,
                hborder, vborder, hspeed, vspeed, obj };

    GM_NORMAL_CALL( id_room_set_view );
  }

  void room_set_view_enabled( const int ind, const int val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, val };

    GM_NORMAL_CALL( id_room_set_view_enabled );
  }

  int room_add() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_room_add );
    GM_RETURN_INT;
  }

  void room_duplicate( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_duplicate );
  }

  void room_assign( const int ind, const int room ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, room };

    GM_NORMAL_CALL( id_room_assign );
  }

  int room_instance_add( const int ind, const double x, const double y, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, obj };

    GM_NORMAL_CALL( id_room_instance_add );
    GM_RETURN_INT;
  }

  void room_instance_clear( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_instance_clear );
  }

  int room_tile_add( const int ind, const int back, const int left, const int top,
                     const int width, const int height, const double x, const double y,
                     const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, back, left, top, width, height, x, y, depth };

    GM_NORMAL_CALL( id_room_tile_add );
    GM_RETURN_INT;
  }

  int room_tile_add_ext( const int ind, const int back, const int left, const int top,
                         const int width, const int height, const double x, const double y,
                         const int depth, const double xscale, const double yscale,
                         const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, back, left, top, width, height, x, y, depth, xscale, yscale, alpha };

    GM_NORMAL_CALL( id_room_tile_add_ext );
    GM_RETURN_INT;
  }

  void room_tile_clear( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_tile_clear );
  }

  bool sprite_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable sprite_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_name );
    GM_RETURN_VAR;
  }

  int sprite_get_number( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_number );
    GM_RETURN_INT;
  }

  int sprite_get_width( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_width );
    GM_RETURN_INT;
  }

  int sprite_get_height( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_height );
    GM_RETURN_INT;
  }

  bool sprite_get_transparent( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_transparent );
    GM_RETURN_BOOL;
  }

  bool sprite_get_smooth( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_smooth );
    GM_RETURN_BOOL;
  }

  bool sprite_get_preload( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_preload );
    GM_RETURN_BOOL;
  }

  int sprite_get_xoffset( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_xoffset );
    GM_RETURN_INT;
  }

  int sprite_get_yoffset( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_yoffset );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_left( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_left );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_right( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_right );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_top( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_top );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_bottom( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_bottom );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_mode( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_mode );
    GM_RETURN_INT;
  }

  bool sprite_get_precise( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_precise );
    GM_RETURN_BOOL;
  }

  void sprite_save( const int ind, const int subimg, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, subimg, fname };

    GM_NORMAL_CALL( id_sprite_save );
  }

  bool sound_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sound_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable sound_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sound_get_name );
    GM_RETURN_VAR;
  }

  int sound_get_kind( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sound_get_kind );
    GM_RETURN_INT;
  }

  bool sound_get_preload( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sound_get_preload );
    GM_RETURN_BOOL;
  }

  void sound_discard( const int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_discard );
  }

  void sound_restore( const int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_restore );
  }

  bool background_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable background_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_name );
    GM_RETURN_VAR;
  }

  int background_get_width( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_width );
    GM_RETURN_INT;
  }

  int background_get_height( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_height );
    GM_RETURN_INT;
  }

  bool background_get_transparent( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_transparent );
    GM_RETURN_BOOL;
  }

  bool background_get_smooth( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_smooth );
    GM_RETURN_BOOL;
  }

  bool background_get_preload( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_preload );
    GM_RETURN_BOOL;
  }

  void background_save( const int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_background_save );
  }

  bool font_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable font_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_name );
    GM_RETURN_VAR;
  }

  CGMVariable font_get_fontname( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_fontname );
    GM_RETURN_VAR;
  }

  bool font_get_bold( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_bold );
    GM_RETURN_BOOL;
  }

  bool font_get_italic( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_italic );
    GM_RETURN_BOOL;
  }

  int font_get_first( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_first );
    GM_RETURN_INT;
  }

  int font_get_last( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_last );
    GM_RETURN_INT;
  }

  bool path_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable path_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_name );
    GM_RETURN_VAR;
  }

  int path_get_length( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_length );
    GM_RETURN_INT;
  }

  int path_get_kind( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_kind );
    GM_RETURN_INT;
  }

  bool path_get_closed( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_closed );
    GM_RETURN_BOOL;
  }

  bool path_get_precision( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_precision );
    GM_RETURN_BOOL;
  }

  int path_get_number( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_number );
    GM_RETURN_INT;
  }

  double path_get_point_x( const int ind, const int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n };

    GM_NORMAL_CALL( id_path_get_point_x );
    GM_RETURN_REAL;
  }

  double path_get_point_y( const int ind, const int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n };

    GM_NORMAL_CALL( id_path_get_point_y );
    GM_RETURN_REAL;
  }

  double path_get_point_speed( const int ind, const int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n };

    GM_NORMAL_CALL( id_path_get_point_speed );
    GM_RETURN_REAL;
  }

  double path_get_x( const int ind, const double pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, pos };

    GM_NORMAL_CALL( id_path_get_x );
    GM_RETURN_REAL;
  }

  double path_get_y( const int ind, const double pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, pos };

    GM_NORMAL_CALL( id_path_get_y );
    GM_RETURN_REAL;
  }

  double path_get_speed( const int ind, const double pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, pos };

    GM_NORMAL_CALL( id_path_get_speed );
    GM_RETURN_REAL;
  }

  bool script_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_script_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable script_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_script_get_name );
    GM_RETURN_VAR;
  }

  CGMVariable script_get_text( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_script_get_text );
    GM_RETURN_VAR;
  }

  bool timeline_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_timeline_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable timeline_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_timeline_get_name );
    GM_RETURN_VAR;
  }

  bool object_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable object_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_name );
    GM_RETURN_VAR;
  }

  int object_get_sprite( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_sprite );
    GM_RETURN_INT;
  }

  bool object_get_solid( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_solid );
    GM_RETURN_BOOL;
  }

  bool object_get_visible( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_visible );
    GM_RETURN_BOOL;
  }

  int object_get_depth( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_depth );
    GM_RETURN_INT;
  }

  bool object_get_persistent( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_persistent );
    GM_RETURN_BOOL;
  }

  int object_get_mask( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_mask );
    GM_RETURN_INT;
  }

  int object_get_parent( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_parent );
    GM_RETURN_INT;
  }

  bool object_is_ancestor( const int ind1, const int ind2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind1, ind2 };

    GM_NORMAL_CALL( id_object_is_ancestor );
    GM_RETURN_BOOL;
  }

  bool room_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable room_get_name( const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_get_name );
    GM_RETURN_VAR;
  }

}
