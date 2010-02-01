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
  GmapiGameplay.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiGameplay.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  bool place_free( double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_place_free );
    GM_RETURN_BOOL;
  }

  bool place_empty( double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_place_empty );
    GM_RETURN_BOOL;
  }

  bool place_meeting( double x, double y, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_place_meeting );
    GM_RETURN_BOOL;
  }

  bool place_snapped( double hsnap, double vsnap ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hsnap, vsnap };

    GM_NORMAL_CALL( id_place_snapped );
    GM_RETURN_BOOL;
  }

  void move_random( double hsnap, double vsnap ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hsnap, vsnap };

    GM_NORMAL_CALL( id_move_random );
  }

  void move_snap( double hsnap, double vsnap ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hsnap, vsnap };

    GM_NORMAL_CALL( id_move_snap );
  }

  void move_wrap( double hor, double vert, double margin ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hor, vert, margin };

    GM_NORMAL_CALL( id_move_wrap );
  }

  void move_towards_point( double x, double y, double sp ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, sp };

    GM_NORMAL_CALL( id_move_towards_point );
  }

  void move_bounce_solid( bool adv ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ adv };

    GM_NORMAL_CALL( id_move_bounce_solid );
  }

  void move_bounce_all( bool adv ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ adv };

    GM_NORMAL_CALL( id_move_bounce_all );
  }

  void move_contact_solid( double dir, double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir, maxdist };

    GM_NORMAL_CALL( id_move_contact_solid );
  }

  void move_contact_all( double dir, double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir, maxdist };

    GM_NORMAL_CALL( id_move_contact_all );
  }

  void move_outside_solid( double dir, double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir, maxdist };

    GM_NORMAL_CALL( id_move_outside_solid );
  }

  void move_outside_all( double dir, double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir, maxdist };

    GM_NORMAL_CALL( id_move_outside_all );
  }

  void distance_to_point( double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_distance_to_point );
  }

  void distance_to_object( int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_distance_to_point );
  }

  bool position_empty( double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_position_empty );
    GM_RETURN_BOOL;
  }

  bool position_meeting( double x, double y, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_position_meeting );
    GM_RETURN_BOOL;
  }

  void path_start( int path, double speed, int endaction, 
                   bool absolute ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, speed, endaction, absolute };

    GM_NORMAL_CALL( id_path_start );
  }

  void path_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_path_end );
  }

  bool mp_linear_step( double x, double y, double stepsize,
                       bool checkall ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, stepsize, checkall };

    GM_NORMAL_CALL( id_mp_linear_step );
    GM_RETURN_BOOL;
  }

  bool mp_linear_step_object( double x, double y, double stepsize,
                              int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, stepsize, obj };

    GM_NORMAL_CALL( id_mp_linear_step_object );
    GM_RETURN_BOOL;
  }

  bool mp_potential_step( double x, double y, double stepsize,
                          bool checkall ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, stepsize, checkall };

    GM_NORMAL_CALL( id_mp_potential_step );
    GM_RETURN_BOOL;
  }

  bool mp_potential_step_object( double x, double y, double stepsize,
                                 int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, stepsize, obj };

    GM_NORMAL_CALL( id_mp_potential_step_object );
    GM_RETURN_BOOL;
  }

  void mp_potential_settings( double maxrot, double rotstep,
                              int ahead, bool onspot ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ maxrot, rotstep, ahead, onspot };

    GM_NORMAL_CALL( id_mp_potential_settings );
  }

  bool mp_linear_path( int path, double xg, double yg,
                       double stepsize, bool checkall ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, xg, yg, stepsize, checkall };

    GM_NORMAL_CALL( id_mp_linear_path );
    GM_RETURN_BOOL;
  }

  bool mp_linear_path_object( int path, double xg, double yg,
                              double stepsize, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, xg, yg, stepsize, obj };

    GM_NORMAL_CALL( id_mp_linear_path_object );
    GM_RETURN_BOOL;
  }

  bool mp_potential_path( int path, double xg, double yg,
                          double stepsize, int factor,
                          bool checkall ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, xg, yg, stepsize, factor, checkall };

    GM_NORMAL_CALL( id_mp_potential_path );
    GM_RETURN_BOOL;
  }

  bool mp_potential_path_object( int path, double xg, double yg,
                                 double stepsize, int factor,
                                 int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, xg, yg, stepsize, factor, obj };

    GM_NORMAL_CALL( id_mp_potential_path_object );
    GM_RETURN_BOOL;
  }

  int mp_grid_create( double left, double top, int hcells,
                      int vcells, double cellwidth, double cellheight ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ left, top, hcells, vcells, cellwidth, cellheight };

    GM_NORMAL_CALL( id_mp_grid_create );
    GM_RETURN_INT;
  }

  void mp_grid_destroy( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_mp_grid_destroy );
  }

  void mp_grid_clear_all( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_mp_grid_clear_all );
  }

  void mp_grid_clear_cell( int id, int h, int v ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, h, v };

    GM_NORMAL_CALL( id_mp_grid_clear_cell );
  }

  void mp_grid_clear_rectangle( int id, double left, double top,
                                double right, double bottom ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, right, bottom };

    GM_NORMAL_CALL( id_mp_grid_clear_rectangle );
  }

  void mp_grid_add_cell( int id, int h, int v ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, h, v };

    GM_NORMAL_CALL( id_mp_grid_add_cell );
  }

  void mp_grid_add_rectangle( int id, double left, double top,
                              double right, double bottom ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, right, bottom };

    GM_NORMAL_CALL( id_mp_grid_add_rectangle );
  }

  void mp_grid_add_instances( int id, int obj, bool prec ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, obj, prec };

    GM_NORMAL_CALL( id_mp_grid_add_instances );
  }

  bool mp_grid_path( int id, int path, double xstart,
                     double ystart, double xgoal, double ygoal,
                     bool allowdiag ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, path, xstart, ystart, xgoal, ygoal, allowdiag };

    GM_NORMAL_CALL( id_mp_grid_path );
    GM_RETURN_BOOL;
  }

  void mp_grid_draw( int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_mp_grid_draw );
  }

  bool collision_point( double x, double y, int obj,
                        bool prec, bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_point );
    GM_RETURN_BOOL;
  }

  bool collision_rectangle( double x1, double y1, double x2,
                            double y2, int obj,
                            bool prec, bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_rectangle );
    GM_RETURN_BOOL;
  }

  bool collision_circle( double xc, double yc, double radius,
                         int obj, bool prec, bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xc, yc, radius, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_circle );
    GM_RETURN_BOOL;
  }

  bool collision_ellipse( double x1, double y1, double x2,
                          double y2, int obj,
                          bool prec, bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_ellipse );
    GM_RETURN_BOOL;
  }

  bool collision_line( double x1, double y1, double x2,
                       double y2, int obj,
                       bool prec, bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_line );
    GM_RETURN_BOOL;
  }

  int instance_find( int obj, int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj, n };

    GM_NORMAL_CALL( id_instance_find );
    GM_RETURN_INT;
  }

  bool instance_exists( int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_instance_exists );
    GM_RETURN_BOOL;
  }

  int instance_number( int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_instance_number );
    GM_RETURN_INT;
  }

  int instance_position( double x, double y, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_position );
    GM_RETURN_INT;
  }

  int instance_nearest( double x, double y, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_nearest );
    GM_RETURN_INT;
  }

  int instance_furthest( double x, double y, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_furthest );
    GM_RETURN_INT;
  }

  int instance_place( double x, double y, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_place );
    GM_RETURN_INT;
  }

  int instance_create( double x, double y, int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_create );
    GM_RETURN_INT;
  }

  int instance_copy( bool performevent ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ performevent };

    GM_NORMAL_CALL( id_instance_copy );
    GM_RETURN_INT;
  }

  void instance_destroy() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_instance_destroy );
  }

  void instance_change( int obj, bool perf ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj, perf };

    GM_NORMAL_CALL( id_instance_change );
  }

  void position_destroy( double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_position_destroy );
  }

  void position_change( double x, double y, int obj, bool perf ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj, perf };

    GM_NORMAL_CALL( id_position_change );
  }

  void instance_deactivate_all( bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ notme };

    GM_NORMAL_CALL( id_instance_deactivate_all );
  }

  void instance_deactivate_object( int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_instance_deactivate_object );
  }

  void instance_deactivate_region( double left, double top,
                                   double width, double height,
                                   bool inside, bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ left, top, width, height, inside, notme };

    GM_NORMAL_CALL( id_instance_deactivate_region );
  }

  void instance_activate_all() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_instance_activate_all );
  }

  void instance_activate_object( int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_instance_activate_object );
  }

  void instance_activate_region( double left, double top,
                                 double width, double height,
                                 bool inside ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ left, top, width, height, inside };

    GM_NORMAL_CALL( id_instance_activate_region );
  }

  void room_goto( int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_room_goto );
  }

  void room_goto_previous() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_room_goto_previous );
  }

  void room_goto_next() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_room_goto_next );
  }

  void room_restart() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_room_restart );
  }

  int room_previous( int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_room_previous );
    GM_RETURN_INT;
  }

  int room_next( int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_room_next );
    GM_RETURN_INT;
  }

  void game_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_game_end );
  }

  void game_restart() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_game_restart );
  }

  void game_save( const CGMVariable& string ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ string };

    GM_NORMAL_CALL( id_game_save );
  }

  void game_load( const CGMVariable& string ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ string };

    GM_NORMAL_CALL( id_game_load );
  }

  void transition_define( int kind, const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind, name };

    GM_NORMAL_CALL( id_transition_define );
  }

  bool transition_exists( int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind };

    GM_NORMAL_CALL( id_transition_exists );
    GM_RETURN_BOOL;
  }

  void event_perform( int type, int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ type, numb };

    GM_NORMAL_CALL( id_event_perform );
  }

  void event_perform_object( int obj, int type, int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj, type, numb };

    GM_NORMAL_CALL( id_event_perform_object );
  }

  void event_user( int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_event_user );
  }

  void event_inherited() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_event_inherited );
  }

  void show_debug_message( const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ str };

    GM_NORMAL_CALL( id_show_debug_message );
  }

  bool variable_global_exists( const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_variable_global_exists );
    GM_RETURN_BOOL;
  }

  bool variable_local_exists( const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_variable_local_exists );
    GM_RETURN_BOOL;
  }

  CGMVariable variable_global_get( const CGMVariable& name ) {
    GM_VAR_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_variable_global_get );
    GM_RETURN_VAR;
  }

  CGMVariable variable_global_array_get( const CGMVariable& name, int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ name, ind };

    GM_NORMAL_CALL( id_variable_global_array_get );
    GM_RETURN_VAR;
  }

  CGMVariable variable_global_array2_get( const CGMVariable& name, int ind1,
                                          int ind2 ) {
    GM_VAR_RESULT;
    GM_ARGS{ name, ind1, ind2 };

    GM_NORMAL_CALL( id_variable_global_array2_get );
    GM_RETURN_VAR;
  }

  CGMVariable variable_local_get( const CGMVariable& name ) {
    GM_VAR_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_variable_local_get );
    GM_RETURN_VAR;
  }

  CGMVariable variable_local_array_get( const CGMVariable& name, int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ name, ind };

    GM_NORMAL_CALL( id_variable_local_array_get );
    GM_RETURN_VAR;
  }

  CGMVariable variable_local_array2_get( const CGMVariable& name, int ind1,
                                         int ind2 ) {
    GM_VAR_RESULT;
    GM_ARGS{ name, ind1, ind2 };

    GM_NORMAL_CALL( id_variable_local_array2_get );
    GM_RETURN_VAR;
  }

  void variable_global_set( const CGMVariable& name, const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, value };

    GM_NORMAL_CALL( id_variable_global_set );
  }

  void variable_global_array_set( const CGMVariable& name, int ind, 
                                  const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, ind, value };

    GM_NORMAL_CALL( id_variable_global_array_set );
  }

  void variable_global_array2_set( const CGMVariable& name, int ind1, 
                                   int ind2, const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, ind1, ind2, value };

    GM_NORMAL_CALL( id_variable_global_array2_set );
  }

  void variable_local_set( const CGMVariable& name, const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, value };

    GM_NORMAL_CALL( id_variable_local_set );
  }

  void variable_local_array_set( const CGMVariable& name, int ind, 
                                 const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, ind, value };

    GM_NORMAL_CALL( id_variable_local_array_set );
  }

  void variable_local_array2_set( const CGMVariable& name, int ind1, 
                                  int ind2, const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, ind1, ind2, value };

    GM_NORMAL_CALL( id_variable_local_array2_set );
  }

  void set_program_priority( int priority ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ priority };

    GM_NORMAL_CALL( id_set_program_priority );
  }

  void set_application_title( const CGMVariable& title ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ title };

    GM_NORMAL_CALL( id_set_application_title );
  }

}
