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

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiGameplay.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  bool place_free( const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_place_free );
    GM_RETURN_BOOL;
  }

  bool place_empty( const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_place_empty );
    GM_RETURN_BOOL;
  }

  bool place_meeting( const double x, const double y, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_place_meeting );
    GM_RETURN_BOOL;
  }

  bool place_snapped( const double hsnap, const double vsnap ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hsnap, vsnap };

    GM_NORMAL_CALL( id_place_snapped );
    GM_RETURN_BOOL;
  }

  void move_random( const double hsnap, const double vsnap ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hsnap, vsnap };

    GM_NORMAL_CALL( id_move_random );
  }

  void move_snap( const double hsnap, const double vsnap ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hsnap, vsnap };

    GM_NORMAL_CALL( id_move_snap );
  }

  void move_wrap( const double hor, const double vert, const double margin ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ hor, vert, margin };

    GM_NORMAL_CALL( id_move_wrap );
  }

  void move_towards_point( const double x, const double y, const double sp ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, sp };

    GM_NORMAL_CALL( id_move_towards_point );
  }

  void move_bounce_solid( const bool adv ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ adv };

    GM_NORMAL_CALL( id_move_bounce_solid );
  }

  void move_bounce_all( const bool adv ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ adv };

    GM_NORMAL_CALL( id_move_bounce_all );
  }

  void move_contact_solid( const double dir, const double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir, maxdist };

    GM_NORMAL_CALL( id_move_contact_solid );
  }

  void move_contact_all( const double dir, const double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir, maxdist };

    GM_NORMAL_CALL( id_move_contact_all );
  }

  void move_outside_solid( const double dir, const double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir, maxdist };

    GM_NORMAL_CALL( id_move_outside_solid );
  }

  void move_outside_all( const double dir, const double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir, maxdist };

    GM_NORMAL_CALL( id_move_outside_all );
  }

  void distance_to_point( const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_distance_to_point );
  }

  void distance_to_object( const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_distance_to_point );
  }

  bool position_empty( const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_position_empty );
    GM_RETURN_BOOL;
  }

  bool position_meeting( const double x, const double y, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_position_meeting );
    GM_RETURN_BOOL;
  }

  void path_start( const int path, const double speed, const int endaction, 
                   const bool absolute ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, speed, endaction, absolute };

    GM_NORMAL_CALL( id_path_start );
  }

  void path_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_path_end );
  }

  bool mp_linear_step( const double x, const double y, const double stepsize,
                       const bool checkall ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, stepsize, checkall };

    GM_NORMAL_CALL( id_mp_linear_step );
    GM_RETURN_BOOL;
  }

  bool mp_linear_step_object( const double x, const double y, const double stepsize,
                              const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, stepsize, obj };

    GM_NORMAL_CALL( id_mp_linear_step_object );
    GM_RETURN_BOOL;
  }

  bool mp_potential_step( const double x, const double y, const double stepsize,
                          const bool checkall ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, stepsize, checkall };

    GM_NORMAL_CALL( id_mp_potential_step );
    GM_RETURN_BOOL;
  }

  bool mp_potential_step_object( const double x, const double y, const double stepsize,
                                 const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, stepsize, obj };

    GM_NORMAL_CALL( id_mp_potential_step_object );
    GM_RETURN_BOOL;
  }

  void mp_potential_settings( const double maxrot, const double rotstep,
                              const int ahead, const bool onspot ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ maxrot, rotstep, ahead, onspot };

    GM_NORMAL_CALL( id_mp_potential_settings );
  }

  bool mp_linear_path( const int path, const double xg, const double yg,
                       const double stepsize, const bool checkall ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, xg, yg, stepsize, checkall };

    GM_NORMAL_CALL( id_mp_linear_path );
    GM_RETURN_BOOL;
  }

  bool mp_linear_path_object( const int path, const double xg, const double yg,
                              const double stepsize, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, xg, yg, stepsize, obj };

    GM_NORMAL_CALL( id_mp_linear_path_object );
    GM_RETURN_BOOL;
  }

  bool mp_potential_path( const int path, const double xg, const double yg,
                          const double stepsize, const int factor,
                          const bool checkall ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, xg, yg, stepsize, factor, checkall };

    GM_NORMAL_CALL( id_mp_potential_path );
    GM_RETURN_BOOL;
  }

  bool mp_potential_path_object( const int path, const double xg, const double yg,
                                 const double stepsize, const int factor,
                                 const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ path, xg, yg, stepsize, factor, obj };

    GM_NORMAL_CALL( id_mp_potential_path_object );
    GM_RETURN_BOOL;
  }

  int mp_grid_create( const double left, const double top, const int hcells,
                      const int vcells, const double cellwidth, const double cellheight ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ left, top, hcells, vcells, cellwidth, cellheight };

    GM_NORMAL_CALL( id_mp_grid_create );
    GM_RETURN_INT;
  }

  void mp_grid_destroy( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_mp_grid_destroy );
  }

  void mp_grid_clear_all( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_mp_grid_clear_all );
  }

  void mp_grid_clear_cell( const int id, const int h, const int v ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, h, v };

    GM_NORMAL_CALL( id_mp_grid_clear_cell );
  }

  void mp_grid_clear_rectangle( const int id, const double left, const double top,
                                const double right, const double bottom ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, right, bottom };

    GM_NORMAL_CALL( id_mp_grid_clear_rectangle );
  }

  void mp_grid_add_cell( const int id, const int h, const int v ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, h, v };

    GM_NORMAL_CALL( id_mp_grid_add_cell );
  }

  void mp_grid_add_rectangle( const int id, const double left, const double top,
                              const double right, const double bottom ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, left, top, right, bottom };

    GM_NORMAL_CALL( id_mp_grid_add_rectangle );
  }

  void mp_grid_add_instances( const int id, const int obj, const bool prec ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, obj, prec };

    GM_NORMAL_CALL( id_mp_grid_add_instances );
  }

  bool mp_grid_path( const int id, const int path, const double xstart,
                     const double ystart, const double xgoal, const double ygoal,
                     const bool allowdiag ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, path, xstart, ystart, xgoal, ygoal, allowdiag };

    GM_NORMAL_CALL( id_mp_grid_path );
    GM_RETURN_BOOL;
  }

  void mp_grid_draw( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_mp_grid_draw );
  }

  bool collision_point( const double x, const double y, const int obj,
                        const bool prec, const bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_point );
    GM_RETURN_BOOL;
  }

  bool collision_rectangle( const double x1, const double y1, const double x2,
                            const double y2, const int obj,
                            const bool prec, const bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_rectangle );
    GM_RETURN_BOOL;
  }

  bool collision_circle( const double xc, const double yc, const double radius,
                         const int obj, const bool prec, const bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xc, yc, radius, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_circle );
    GM_RETURN_BOOL;
  }

  bool collision_ellipse( const double x1, const double y1, const double x2,
                          const double y2, const int obj,
                          const bool prec, const bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_ellipse );
    GM_RETURN_BOOL;
  }

  bool collision_line( const double x1, const double y1, const double x2,
                       const double y2, const int obj,
                       const bool prec, const bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, x2, y2, obj, prec, notme };

    GM_NORMAL_CALL( id_collision_line );
    GM_RETURN_BOOL;
  }

  int instance_find( const int obj, const int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj, n };

    GM_NORMAL_CALL( id_instance_find );
    GM_RETURN_INT;
  }

  void instance_exists( const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_instance_exists );
  }

  void instance_number( const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_instance_number );
  }

  int instance_position( const double x, const double y, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_position );
    GM_RETURN_INT;
  }

  int instance_nearest( const double x, const double y, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_nearest );
    GM_RETURN_INT;
  }

  int instance_furthest( const double x, const double y, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_furthest );
    GM_RETURN_INT;
  }

  int instance_place( const double x, const double y, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_place );
    GM_RETURN_INT;
  }

  int instance_create( const double x, const double y, const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj };

    GM_NORMAL_CALL( id_instance_create );
    GM_RETURN_INT;
  }

  int instance_copy( const bool performevent ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ performevent };

    GM_NORMAL_CALL( id_instance_copy );
    GM_RETURN_INT;
  }

  void instance_destroy() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_instance_destroy );
  }

  void instance_change( const int obj, const bool perf ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj, perf };

    GM_NORMAL_CALL( id_instance_change );
  }

  void position_destroy( const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y };

    GM_NORMAL_CALL( id_position_destroy );
  }

  void position_change( const double x, const double y, const int obj, const bool perf ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, obj, perf };

    GM_NORMAL_CALL( id_position_change );
  }

  void instance_deactivate_all( const bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ notme };

    GM_NORMAL_CALL( id_instance_deactivate_all );
  }

  void instance_deactivate_object( const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_instance_deactivate_object );
  }

  void instance_deactivate_region( const double left, const double top,
                                   const double width, const double height,
                                   const bool inside, const bool notme ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ left, top, width, height, inside, notme };

    GM_NORMAL_CALL( id_instance_deactivate_region );
  }

  void instance_activate_all() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_instance_activate_all );
  }

  void instance_activate_object( const int obj ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj };

    GM_NORMAL_CALL( id_instance_activate_object );
  }

  void instance_activate_region( const double left, const double top,
                                 const double width, const double height,
                                 const bool inside ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ left, top, width, height, inside };

    GM_NORMAL_CALL( id_instance_activate_region );
  }

  void room_goto( const int numb ) {
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

  int room_previous( const int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_room_previous );
    GM_RETURN_INT;
  }

  int room_next( const int numb ) {
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

  void transition_define( const int kind, const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind, name };

    GM_NORMAL_CALL( id_transition_define );
  }

  bool transition_exists( const int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind };

    GM_NORMAL_CALL( id_transition_exists );
    GM_RETURN_BOOL;
  }

  void event_perform( const int type, const int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ type, numb };

    GM_NORMAL_CALL( id_event_perform );
  }

  void event_perform_object( const int obj, const int type, const int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ obj, type, numb };

    GM_NORMAL_CALL( id_event_perform_object );
  }

  void event_user( const int numb ) {
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

  CGMVariable variable_global_array_get( const CGMVariable& name, const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ name, ind };

    GM_NORMAL_CALL( id_variable_global_array_get );
    GM_RETURN_VAR;
  }

  CGMVariable variable_global_array2_get( const CGMVariable& name, const int ind1,
                                          const int ind2 ) {
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

  CGMVariable variable_local_array_get( const CGMVariable& name, const int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ name, ind };

    GM_NORMAL_CALL( id_variable_local_array_get );
    GM_RETURN_VAR;
  }

  CGMVariable variable_local_array2_get( const CGMVariable& name, const int ind1,
                                         const int ind2 ) {
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

  void variable_global_array_set( const CGMVariable& name, const int ind, 
                                  const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, ind, value };

    GM_NORMAL_CALL( id_variable_global_array_set );
  }

  void variable_global_array2_set( const CGMVariable& name, const int ind1, 
                                   const int ind2, const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, ind1, ind2, value };

    GM_NORMAL_CALL( id_variable_global_array2_set );
  }

  void variable_local_set( const CGMVariable& name, const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, value };

    GM_NORMAL_CALL( id_variable_local_set );
  }

  void variable_local_array_set( const CGMVariable& name, const int ind, 
                                 const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, ind, value };

    GM_NORMAL_CALL( id_variable_local_array_set );
  }

  void variable_local_array2_set( const CGMVariable& name, const int ind1, 
                                  const int ind2, const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, ind1, ind2, value };

    GM_NORMAL_CALL( id_variable_local_array2_set );
  }

  void set_program_priority( const int priority ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ priority };

    GM_NORMAL_CALL( id_set_program_priority );
  }

}
