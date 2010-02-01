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

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiResources.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

using namespace gm::core;

namespace gm {

  CGMVariable script_execute( int ind, const CGMVariable* aArguments, int aArgCount ) {
    GM_VAR_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[aArgCount + 2];
    ZeroMemory( argument, sizeof( GMVALUE ) * (aArgCount + 2) );

    argument[0] = ind;

    for ( int i = 0; i < aArgCount; i++ )
      argument[i + 1] = aArguments[i];

    RunnerCallFunction( CGMAPI::GMAPIGMFunctionTable( id_script_execute ), argument, aArgCount + 1,
                        &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_VAR;
  }

  CGMVariable execute_string( const CGMVariable& str, const CGMVariable* aArguments, int aArgCount ) {
    GM_VAR_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[aArgCount + 2];
    ZeroMemory( argument, sizeof( GMVALUE ) * (aArgCount + 2) );

    argument[0] = str;

    for ( int i = 0; i < aArgCount; i++ )
      argument[i + 1] = aArguments[i];

    RunnerCallFunction( CGMAPI::GMAPIGMFunctionTable( id_execute_string ), argument, aArgCount + 1,
                        &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_VAR;
  }

  CGMVariable execute_file( const CGMVariable& fname, const CGMVariable* aArguments, int aArgCount ) {
    GM_VAR_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[aArgCount + 2];
    ZeroMemory( argument, sizeof( GMVALUE ) * (aArgCount + 2) );

    argument[0] = fname;

    for ( int i = 0; i < aArgCount; i++ )
      argument[i + 1] = aArguments[i];

    RunnerCallFunction( CGMAPI::GMAPIGMFunctionTable( id_execute_file ), argument, aArgCount + 1,
                        &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_VAR;
  }

  int external_define( const CGMVariable& dll, const CGMVariable& name, int calltype,
                       int restype, int argnumb, const int* aArgTypes ) {
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

    RunnerCallFunction( CGMAPI::GMAPIGMFunctionTable( id_external_define ), argument, argnumb + 5,
                        &result );

    delete [] argument;
    GM_RESTORE_INSTANCE_DATA;
    GM_RETURN_INT;
  }

  CGMVariable external_call( int id, const CGMVariable* aArguments, int aArgCount ) {
    GM_VAR_RESULT;
    GM_PRESERVE_INSTANCE_DATA;

    GMVALUE* argument = new GMVALUE[aArgCount + 1];
    ZeroMemory( argument, sizeof( GMVALUE ) * (aArgCount + 1) );

    argument[0] = id;

    for ( int i = 0; i < aArgCount; i++ )
      argument[i + 1] = aArguments[i];

    RunnerCallFunction( CGMAPI::GMAPIGMFunctionTable( id_external_call ), argument, aArgCount + 1,
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

  void sprite_set_offset( int ind, int xoff, int yoff ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, xoff, yoff };

    GM_NORMAL_CALL( id_sprite_set_offset );
  }

  void sprite_set_bbox_mode( int ind, int mode ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, mode };

    GM_NORMAL_CALL( id_sprite_set_bbox_mode );
  }

  void sprite_set_bbox( int ind, int left, int top, int right,
                        int bottom ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, left, top, right, bottom };

    GM_NORMAL_CALL( id_sprite_set_bbox );
  }

  void sprite_set_precise( int ind, bool mode ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, mode };

    GM_NORMAL_CALL( id_sprite_set_precise );
  }

  int sprite_duplicate( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_duplicate );
    GM_RETURN_INT;
  }

  void sprite_assign( int ind, int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr };

    GM_NORMAL_CALL( id_sprite_assign );
  }

  void sprite_merge( int ind1, int ind2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind1, ind2 };

    GM_NORMAL_CALL( id_sprite_merge );
  }

  int sprite_add( const CGMVariable& fname, int imgnumb, bool precise,
                  bool transparent, bool smooth, bool preload,
                  int xorig, int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, imgnumb, precise, transparent, smooth, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_add );
    GM_RETURN_INT;
  }

  int sprite_add( const CGMVariable& fname, int imgnumb, bool removeback,
                  bool smooth, int xorig, int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, imgnumb, removeback, smooth, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_add );
    GM_RETURN_INT;
  }

  int sprite_add_sprite( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_sprite_add_sprite );
    GM_RETURN_INT;
  }

  int sprite_add_alpha( const CGMVariable& fname, int imgnumb, bool precise,
                        bool preload, int xorig, int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, imgnumb, precise, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_add_alpha );
    GM_RETURN_INT;
  }

  void sprite_replace( int ind, const CGMVariable& fname, int imgnumb, 
                       bool precise, bool transparent, bool smooth,
                       bool preload, int xorig, int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, imgnumb, precise, transparent, smooth, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_replace );
  }

  void sprite_replace( int ind, const CGMVariable& fname, int imgnumb,
                       bool removeback, bool smooth, int xorig,
                       int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, imgnumb, removeback, smooth, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_replace );
  }

  void sprite_replace_sprite( int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_sprite_replace_sprite );
  }

  void sprite_replace_alpha( int ind, const CGMVariable& fname, int imgnumb,
                             bool precise, bool preload, int xorig,
                             int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, imgnumb, precise, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_replace_alpha );
  }

  int sprite_create_from_screen( int x, int y, int w, int h,
                                 bool precise, bool transparent, bool smooth,
                                 bool preload, int xorig, int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, precise, transparent, smooth, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_create_from_screen );
    GM_RETURN_INT;
  }

  int sprite_create_from_screen( int x, int y, int w, int h,
                                 bool removeback, bool smooth, int xorig,
                                 int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, removeback, smooth, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_create_from_screen );
    GM_RETURN_INT;
  }

  void sprite_add_from_screen( int ind, int x, int y, int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, w, h };

    GM_NORMAL_CALL( id_sprite_add_from_screen );
  }

  void sprite_add_from_screen( int ind, int x, int y, int w,
                               int h, bool removeback, bool smooth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, w, h, removeback, smooth };

    GM_NORMAL_CALL( id_sprite_add_from_screen );
  }

  int sprite_create_from_surface( int id, int x, int y, int w,
                                  int h, bool precise, bool transparent,
                                  bool smooth, bool preload, int xorig,
                                  int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h, precise, transparent, smooth, preload, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_create_from_surface );
    GM_RETURN_INT;
  }

  int sprite_create_from_surface( int id, int x, int y, int w,
                                  int h, bool removeback, bool smooth,
                                  int xorig, int yorig ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h, removeback, smooth, xorig, yorig };

    GM_NORMAL_CALL( id_sprite_create_from_surface );
    GM_RETURN_INT;
  }

  void sprite_add_from_surface( int ind, int id, int x, int y,
                                int w, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, id, x, y, w, h };

    GM_NORMAL_CALL( id_sprite_add_from_surface );
  }

  void sprite_add_from_surface( int ind, int id, int x, int y,
                                int w, int h, bool removeback, bool smooth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, id, x, y, w, h, removeback, smooth };

    GM_NORMAL_CALL( id_sprite_add_from_surface );
  }

  void sprite_delete( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_delete );
  }

  void sprite_set_alpha_from_sprite( int ind, int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr };

    GM_NORMAL_CALL( id_sprite_set_alpha_from_sprite );
  }

  void sprite_collision_mask( int ind,  bool sepmasks, int bboxmode,
                              int bbleft, int bbright, int bbtop,
                              int bbbottom, int kind, int tolerance ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, sepmasks, bboxmode, bbleft, bbright, bbtop, bbbottom, kind, tolerance };

    GM_NORMAL_CALL( id_sprite_collision_mask );
  }

  int sound_add( const CGMVariable& fname, int kind, bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, kind, preload };

    GM_NORMAL_CALL( id_sound_add );
    GM_RETURN_INT;
  }

  void sound_replace( int index, const CGMVariable& fname, int kind,
                      bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index, fname, kind, preload };

    GM_NORMAL_CALL( id_sound_replace );
  }

  void sound_delete( int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_delete );
  }

  int background_duplicate( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_duplicate );
    GM_RETURN_INT;
  }

  void background_assign( int ind, int back ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, back };

    GM_NORMAL_CALL( id_background_assign );
  }

  int background_add( const CGMVariable& fname, bool transparent, bool smooth,
                      bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, transparent, smooth, preload };

    GM_NORMAL_CALL( id_background_add );
    GM_RETURN_INT;
  }

  int background_add( const CGMVariable& fname, bool removeback, bool smooth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, removeback, smooth };

    GM_NORMAL_CALL( id_background_add );
    GM_RETURN_INT;
  }

  int background_add_background( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_background_add_background );
    GM_RETURN_INT;
  }

  int background_add_alpha( const CGMVariable& fname, bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, preload };

    GM_NORMAL_CALL( id_background_add_alpha );
    GM_RETURN_INT;
  }

  void background_replace( int ind, const CGMVariable& fname, bool transparent,
                           bool smooth, bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, transparent, smooth, preload };

    GM_NORMAL_CALL( id_background_replace );
  }

  void background_replace( int ind, const CGMVariable& fname, bool removeback,
                           bool smooth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, removeback, smooth };

    GM_NORMAL_CALL( id_background_replace );
  }

  void background_replace_background( int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_background_replace_background );
  }

  void background_replace_alpha( int ind, const CGMVariable& fname, bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname, preload };

    GM_NORMAL_CALL( id_background_replace_alpha );
  }

  int background_create_color( int w, int h, int col, bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, col, preload };

    GM_NORMAL_CALL( id_background_create_color );
    GM_RETURN_INT;
  }

  int background_create_color( int w, int h, int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, col };

    GM_NORMAL_CALL( id_background_create_color );
    GM_RETURN_INT;
  }

  int background_create_gradient( int w, int h, int col1, int col2,
                                  int kind, bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, col1, col2, kind, preload };

    GM_NORMAL_CALL( id_background_create_gradient );
    GM_RETURN_INT;
  }

  int background_create_gradient( int w, int h, int col1, int col2,
                                  int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h, col1, col2, kind };

    GM_NORMAL_CALL( id_background_create_gradient );
    GM_RETURN_INT;
  }

  int background_create_from_screen( int x, int y, int w, int h,
                                     bool transparent, bool smooth, 
                                     bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, transparent, smooth, preload };

    GM_NORMAL_CALL( id_background_create_from_screen );
    GM_RETURN_INT;
  }

  int background_create_from_screen( int x, int y, int w, int h,
                                     bool removeback, bool smooth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, removeback, smooth };

    GM_NORMAL_CALL( id_background_create_from_screen );
    GM_RETURN_INT;
  }

  int background_create_from_surface( int id, int x, int y, int w,
                                      int h, bool transparent, bool smooth,
                                      bool preload ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h, transparent, smooth, preload };

    GM_NORMAL_CALL( id_background_create_from_surface );
    GM_RETURN_INT;
  }

  int background_create_from_surface( int id, int x, int y, int w,
                                      int h, bool removeback, bool smooth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, w, h, removeback, smooth };

    GM_NORMAL_CALL( id_background_create_from_surface );
    GM_RETURN_INT;
  }

  void background_delete( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_delete );
  }

  void background_set_alpha_from_background( int ind, int back ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, back };

    GM_NORMAL_CALL( id_background_set_alpha_from_background );
  }

  int font_add( const CGMVariable& name, int size, bool bold, bool italic,
                int first, int last ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, size, bold, italic, first, last };

    GM_NORMAL_CALL( id_font_add );
    GM_RETURN_INT;
  }

  int font_add_sprite( int spr, int first, bool prop, int sep ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ spr, first, prop, sep };

    GM_NORMAL_CALL( id_font_add_sprite );
    GM_RETURN_INT;
  }

  void font_replace( int ind, const CGMVariable& name, int size, bool bold,
                     bool italic, int first, int last ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, name, size, bold, italic, first, last };

    GM_NORMAL_CALL( id_font_replace );
  }

  void font_replace_sprite( int ind, int spr, int first, bool prop,
                            int sep ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr, first, prop, sep };

    GM_NORMAL_CALL( id_font_replace_sprite );
  }

  void font_delete( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_delete );
  }

  void path_set_kind( int ind, int val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, val };

    GM_NORMAL_CALL( id_path_set_kind );
  }

  void path_set_closed( int ind, bool closed ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, closed };

    GM_NORMAL_CALL( id_path_set_closed );
  }

  void path_set_precision( int ind, int prec ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, prec };

    GM_NORMAL_CALL( id_path_set_precision );
  }

  int path_add() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_path_add );
    GM_RETURN_INT;
  }

  void path_delete( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_delete );
  }

  int path_duplicate( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_duplicate );
    GM_RETURN_INT;
  }

  void path_assign( int ind, int path ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, path };

    GM_NORMAL_CALL( id_path_assign );
  }

  void path_append( int ind, int path ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, path };

    GM_NORMAL_CALL( id_path_append );
  }

  void path_add_point( int ind, double x, double y, double speed ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, speed };

    GM_NORMAL_CALL( id_path_add_point );
  }

  void path_insert_point( int ind, int n, double x, double y,
                          double speed ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n, x, y, speed };

    GM_NORMAL_CALL( id_path_insert_point );
  }

  void path_change_point( int ind, int n, double x, double y,
                          double speed ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n, x, y, speed };

    GM_NORMAL_CALL( id_path_change_point );
  }

  void path_delete_point( int ind, int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n };

    GM_NORMAL_CALL( id_path_delete_point );
  }

  void path_clear_points( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_clear_points );
  }

  void path_reverse( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_reverse );
  }

  void path_mirror( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_mirror );
  }

  void path_flip( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_flip );
  }

  void path_rotate( int ind, double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, angle };

    GM_NORMAL_CALL( id_path_rotate );
  }

  void path_scale( int ind, double xscale, double yscale ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, xscale, yscale };

    GM_NORMAL_CALL( id_path_scale );
  }

  void path_shift( int ind, double xshift, double yshift ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, xshift, yshift };

    GM_NORMAL_CALL( id_path_shift );
  }

  int timeline_add() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_timeline_add );
    GM_RETURN_INT;
  }

  void timeline_delete( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_timeline_delete );
  }

  void timeline_moment_add( int ind, int step, const CGMVariable& codestr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, step, codestr };

    GM_NORMAL_CALL( id_timeline_moment_add );
  }

  void timeline_moment_clear( int ind, int step ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, step };

    GM_NORMAL_CALL( id_timeline_moment_clear );
  }

  void timeline_clear( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_timeline_clear );
  }

  void object_set_sprite( int ind, int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr };

    GM_NORMAL_CALL( id_object_set_sprite );
  }

  void object_set_solid( int ind, bool solid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, solid };

    GM_NORMAL_CALL( id_object_set_solid );
  }

  void object_set_visible( int ind, bool vis ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, vis };

    GM_NORMAL_CALL( id_object_set_visible );
  }

  void object_set_depth( int ind, int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, depth };

    GM_NORMAL_CALL( id_object_set_depth );
  }

  void object_set_persistent( int ind, bool pers ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, pers };

    GM_NORMAL_CALL( id_object_set_persistent );
  }

  void object_set_mask( int ind, int spr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, spr };

    GM_NORMAL_CALL( id_object_set_mask );
  }

  void object_set_parent( int ind, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, obj };

    GM_NORMAL_CALL( id_object_set_parent );
  }

  int object_add() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_object_add );
    GM_RETURN_INT;
  }

  void object_delete( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_delete );
  }

  void object_event_add( int ind, int evtype, int evnumb,
                         const CGMVariable& codestr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, evtype, evnumb, codestr };

    GM_NORMAL_CALL( id_object_event_add );
  }

  void object_event_clear( int ind, int evtype, int evnumb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, evtype, evnumb };

    GM_NORMAL_CALL( id_object_event_clear );
  }

  void room_set_width( int ind, int w ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, w };

    GM_NORMAL_CALL( id_room_set_width );
  }

  void room_set_height( int ind, int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, h };

    GM_NORMAL_CALL( id_room_set_height );
  }

  void room_set_caption( int ind, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, str };

    GM_NORMAL_CALL( id_room_set_caption );
  }

  void room_set_persistent( int ind, bool val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, val };

    GM_NORMAL_CALL( id_room_set_persistent );
  }

  void room_set_code( int ind, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, str };

    GM_NORMAL_CALL( id_room_set_code );
  }

  void room_set_background_color( int ind, int col, bool show ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, col, show };

    GM_NORMAL_CALL( id_room_set_background_color );
  }

  void room_set_background( int ind, int bind, bool vis, bool fore,
                            int back, int x, int y, bool htiled,
                            bool vtiled, double hspeed, double vspeed,
                            double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, bind, vis, fore, back, x, y, htiled, vtiled, hspeed, vspeed, alpha };

    GM_NORMAL_CALL( id_room_set_background );
  }

  void room_set_view( int ind, int vind, bool vis, int xview,
                      int yview, int wview, int hview, int xport,
                      int yport, int wport, int hport, int hborder,
                      int vborder, double hspeed, double vspeed,
                      int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, vind, vis, xview, yview, wview, hview, xport, yport, wport, hport,
                hborder, vborder, hspeed, vspeed, obj };

    GM_NORMAL_CALL( id_room_set_view );
  }

  void room_set_view_enabled( int ind, int val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, val };

    GM_NORMAL_CALL( id_room_set_view_enabled );
  }

  int room_add() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_room_add );
    GM_RETURN_INT;
  }

  void room_duplicate( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_duplicate );
  }

  void room_assign( int ind, int room ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, room };

    GM_NORMAL_CALL( id_room_assign );
  }

  int room_instance_add( int ind, double x, double y, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, obj };

    GM_NORMAL_CALL( id_room_instance_add );
    GM_RETURN_INT;
  }

  void room_instance_clear( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_instance_clear );
  }

  int room_tile_add( int ind, int back, int left, int top,
                     int width, int height, double x, double y,
                     int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, back, left, top, width, height, x, y, depth };

    GM_NORMAL_CALL( id_room_tile_add );
    GM_RETURN_INT;
  }

  int room_tile_add_ext( int ind, int back, int left, int top,
                         int width, int height, double x, double y,
                         int depth, double xscale, double yscale,
                         double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, back, left, top, width, height, x, y, depth, xscale, yscale, alpha };

    GM_NORMAL_CALL( id_room_tile_add_ext );
    GM_RETURN_INT;
  }

  void room_tile_clear( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_tile_clear );
  }

  bool sprite_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable sprite_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_name );
    GM_RETURN_VAR;
  }

  int sprite_get_number( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_number );
    GM_RETURN_INT;
  }

  int sprite_get_width( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_width );
    GM_RETURN_INT;
  }

  int sprite_get_height( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_height );
    GM_RETURN_INT;
  }

  bool sprite_get_transparent( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_transparent );
    GM_RETURN_BOOL;
  }

  bool sprite_get_smooth( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_smooth );
    GM_RETURN_BOOL;
  }

  bool sprite_get_preload( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_preload );
    GM_RETURN_BOOL;
  }

  int sprite_get_xoffset( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_xoffset );
    GM_RETURN_INT;
  }

  int sprite_get_yoffset( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_yoffset );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_left( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_left );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_right( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_right );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_top( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_top );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_bottom( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_bottom );
    GM_RETURN_INT;
  }

  int sprite_get_bbox_mode( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_bbox_mode );
    GM_RETURN_INT;
  }

  bool sprite_get_precise( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sprite_get_precise );
    GM_RETURN_BOOL;
  }

  void sprite_save( int ind, int subimg, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, subimg, fname };

    GM_NORMAL_CALL( id_sprite_save );
  }

  void sprite_save_strip( int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_sprite_save_strip );
  }

  bool sound_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sound_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable sound_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sound_get_name );
    GM_RETURN_VAR;
  }

  int sound_get_kind( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sound_get_kind );
    GM_RETURN_INT;
  }

  bool sound_get_preload( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_sound_get_preload );
    GM_RETURN_BOOL;
  }

  void sound_discard( int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_discard );
  }

  void sound_restore( int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_restore );
  }

  bool background_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable background_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_name );
    GM_RETURN_VAR;
  }

  int background_get_width( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_width );
    GM_RETURN_INT;
  }

  int background_get_height( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_height );
    GM_RETURN_INT;
  }

  bool background_get_transparent( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_transparent );
    GM_RETURN_BOOL;
  }

  bool background_get_smooth( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_smooth );
    GM_RETURN_BOOL;
  }

  bool background_get_preload( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_background_get_preload );
    GM_RETURN_BOOL;
  }

  void background_save( int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_background_save );
  }

  bool font_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable font_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_name );
    GM_RETURN_VAR;
  }

  CGMVariable font_get_fontname( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_fontname );
    GM_RETURN_VAR;
  }

  bool font_get_bold( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_bold );
    GM_RETURN_BOOL;
  }

  bool font_get_italic( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_italic );
    GM_RETURN_BOOL;
  }

  int font_get_first( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_first );
    GM_RETURN_INT;
  }

  int font_get_last( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_font_get_last );
    GM_RETURN_INT;
  }

  bool path_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable path_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_name );
    GM_RETURN_VAR;
  }

  int path_get_length( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_length );
    GM_RETURN_INT;
  }

  int path_get_kind( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_kind );
    GM_RETURN_INT;
  }

  bool path_get_closed( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_closed );
    GM_RETURN_BOOL;
  }

  bool path_get_precision( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_precision );
    GM_RETURN_BOOL;
  }

  int path_get_number( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_path_get_number );
    GM_RETURN_INT;
  }

  double path_get_point_x( int ind, int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n };

    GM_NORMAL_CALL( id_path_get_point_x );
    GM_RETURN_REAL;
  }

  double path_get_point_y( int ind, int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n };

    GM_NORMAL_CALL( id_path_get_point_y );
    GM_RETURN_REAL;
  }

  double path_get_point_speed( int ind, int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, n };

    GM_NORMAL_CALL( id_path_get_point_speed );
    GM_RETURN_REAL;
  }

  double path_get_x( int ind, double pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, pos };

    GM_NORMAL_CALL( id_path_get_x );
    GM_RETURN_REAL;
  }

  double path_get_y( int ind, double pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, pos };

    GM_NORMAL_CALL( id_path_get_y );
    GM_RETURN_REAL;
  }

  double path_get_speed( int ind, double pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, pos };

    GM_NORMAL_CALL( id_path_get_speed );
    GM_RETURN_REAL;
  }

  bool script_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_script_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable script_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_script_get_name );
    GM_RETURN_VAR;
  }

  CGMVariable script_get_text( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_script_get_text );
    GM_RETURN_VAR;
  }

  bool timeline_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_timeline_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable timeline_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_timeline_get_name );
    GM_RETURN_VAR;
  }

  bool object_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable object_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_name );
    GM_RETURN_VAR;
  }

  int object_get_sprite( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_sprite );
    GM_RETURN_INT;
  }

  bool object_get_solid( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_solid );
    GM_RETURN_BOOL;
  }

  bool object_get_visible( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_visible );
    GM_RETURN_BOOL;
  }

  int object_get_depth( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_depth );
    GM_RETURN_INT;
  }

  bool object_get_persistent( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_persistent );
    GM_RETURN_BOOL;
  }

  int object_get_mask( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_mask );
    GM_RETURN_INT;
  }

  int object_get_parent( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_object_get_parent );
    GM_RETURN_INT;
  }

  bool object_is_ancestor( int ind1, int ind2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind1, ind2 };

    GM_NORMAL_CALL( id_object_is_ancestor );
    GM_RETURN_BOOL;
  }

  bool room_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable room_get_name( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_room_get_name );
    GM_RETURN_VAR;
  }

}
