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
  GmapiGameplay.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  bool place_free( const double x, const double y );
  bool place_empty( const double x, const double y );
  bool place_meeting( const double x, const double y, const int obj );
  bool place_snapped( const double hsnap, const double vsnap );

  void move_random( const double hsnap, const double vsnap );
  void move_snap( const double hsnap, const double vsnap );
  void move_wrap( const double hor, const double vert, const double margin );
  void move_towards_point( const double x, const double y, const double sp );
  void move_bounce_solid( const bool adv );
  void move_bounce_all( const bool adv );
  void move_contact_solid( const double dir, const double maxdist );
  void move_contact_all( const double dir, const double maxdist );
  void move_outside_solid( const double dir, const double maxdist );
  void move_outside_all( const double dir, const double maxdist );

  void distance_to_point( const double x, const double y );
  void distance_to_object( const int obj );

  bool position_empty( const double x, const double y );
  bool position_meeting( const double x, const double y, const int obj );

  void path_start( const int path, const double speed, const int endaction, 
                   const bool absolute );
  void path_end();

  bool mp_linear_step( const double x, const double y, const double stepsize,
                       const bool checkall );
  bool mp_linear_step_object( const double x, const double y, const double stepsize,
                              const int obj );
  bool mp_potential_step( const double x, const double y, const double stepsize,
                          const bool checkall );
  bool mp_potential_step_object( const double x, const double y, const double stepsize,
                                 const int obj );
  void mp_potential_settings( const double maxrot, const double rotstep,
                              const int ahead, const bool onspot );
  bool mp_linear_path( const int path, const double xg, const double yg,
                       const double stepsize, const bool checkall );
  bool mp_linear_path_object( const int path, const double xg, const double yg,
                              const double stepsize, const int obj );
  bool mp_potential_path( const int path, const double xg, const double yg,
                          const double stepsize, const int factor,
                          const bool checkall );
  bool mp_potential_path_object( const int path, const double xg, const double yg,
                                 const double stepsize, const int factor,
                                 const int obj );
  int mp_grid_create( const double left, const double top, const int hcells,
                      const int vcells, const double cellwidth, const double cellheight );
  void mp_grid_destroy( const int id );
  void mp_grid_clear_all( const int id );
  void mp_grid_clear_cell( const int id, const int h, const int v );
  void mp_grid_clear_rectangle( const int id, const double left, const double top,
                                const double right, const double bottom );
  void mp_grid_add_cell( const int id, const int h, const int v );
  void mp_grid_add_rectangle( const int id, const double left, const double top,
                              const double right, const double bottom );
  void mp_grid_add_instances( const int id, const int obj, const bool prec );
  bool mp_grid_path( const int id, const int path, const double xstart,
                     const double ystart, const double xgoal, const double ygoal,
                     const bool allowdiag );
  void mp_grid_draw( const int id );

  bool collision_point( const double x, const double y, const int obj,
                        const bool prec, const bool notme );
  bool collision_rectangle( const double x1, const double y1, const double x2,
                            const double y2, const int obj,
                            const bool prec, const bool notme );
  bool collision_circle( const double xc, const double yc, const double radius,
                            const bool prec, const bool notme );
  bool collision_ellipse( const double x1, const double y1, const double x2,
                          const double y2, const int obj,
                          const bool prec, const bool notme );
  bool collision_line( const double x1, const double y1, const double x2,
                       const double y2, const int obj,
                       const bool prec, const bool notme );

  int instance_find( const int obj, const int n );
  void instance_exists( const int obj );
  void instance_number( const int obj );
  int instance_position( const double x, const double y, const int obj );
  int instance_nearest( const double x, const double y, const int obj );
  int instance_furthest( const double x, const double y, const int obj );
  int instance_place( const double x, const double y, const int obj );
  int instance_create( const double x, const double y, const int obj );
  int instance_copy( const bool performevent );
  void instance_destroy();
  void instance_change( const int obj, const bool perf );
  void position_destroy( const double x, const double y );
  void position_change( const double x, const double y, const int obj, const bool perf );
  void instance_deactivate_all( const bool notme );
  void instance_deactivate_object( const int obj );
  void instance_deactivate_region( const double left, const double top,
                                   const double width, const double height,
                                   const bool inside, const bool notme );
  void instance_activate_all();
  void instance_activate_object( const int obj );
  void instance_activate_region( const double left, const double top,
                                 const double width, const double height,
                                 const bool inside );

  void room_goto( const int numb );
  void room_goto_previous();
  void room_goto_next();
  void room_restart();
  int room_previous( const int numb );
  int room_next( const int numb );

  void game_end();
  void game_restart();
  void game_save( const CGMVariable& string );
  void game_load( const CGMVariable& string );

  void transition_define( const int kind, const CGMVariable& name );
  bool transition_exists( const int kind );

  void event_perform( const int type, const int numb );
  void event_perform_object( const int obj, const int type, const int numb );
  void event_user( const int numb );
  void event_inherited();

  void show_debug_message( const CGMVariable& str );

  bool variable_global_exists( const CGMVariable& name );
  bool variable_local_exists( const CGMVariable& name );
  CGMVariable variable_global_get( const CGMVariable& name );
  CGMVariable variable_global_array_get( const CGMVariable& name, const int ind );
  CGMVariable variable_global_array2_get( const CGMVariable& name, const int ind1,
                                          const int ind2 );
  CGMVariable variable_local_get( const CGMVariable& name );
  CGMVariable variable_local_array_get( const CGMVariable& name, const int ind );
  CGMVariable variable_local_array2_get( const CGMVariable& name, const int ind1,
                                         const int ind2 );
  void variable_global_set( const CGMVariable& name, const CGMVariable& value );
  void variable_global_array_set( const CGMVariable& name, const int ind, 
                                  const CGMVariable& value );
  void variable_global_array2_set( const CGMVariable& name, const int ind1, 
                                   const int ind2, const CGMVariable& value );
  void variable_local_set( const CGMVariable& name, const CGMVariable& value );
  void variable_local_array_set( const CGMVariable& name, const int ind, 
                                 const CGMVariable& value );
  void variable_local_array2_set( const CGMVariable& name, const int ind1, 
                                  const int ind2, const CGMVariable& value );

  void set_program_priority( const int priority ) ;
  
}
