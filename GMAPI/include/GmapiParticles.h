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
  GmapiParticles.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  void effect_create_below( const int kind, const double x, const double y, const int size,
                            const int color );
  void effect_create_above( const int kind, const double x, const double y, const int size,
                            const int color );
  void effect_clear();
  int part_type_create();
  void part_type_destroy( const int ind );
  bool part_type_exists( const int ind );
  void part_type_clear( const int ind );
  void part_type_shape( const int ind, const int shape );
  void part_type_sprite( const int ind, const int sprite, const bool animat, const bool stretch,
                         const bool random );
  void part_type_size( const int ind, const double size_min, const double size_max, 
                       const double size_incr, const double size_wiggle );
  void part_type_scale( const int ind, const double xscale, const double yscale );
  void part_type_orientation( const int ind, const double ang_min, const double ang_max,
                              const double ang_incr, const double ang_wiggle,
                              const bool ang_relative );
  void part_type_color1( const int ind, const int color1 );
  void part_type_color2( const int ind, const int color1, const int color2 );
  void part_type_color3( const int ind, const int color1, const int color2, const int color3 );
  void part_type_color_mix( const int ind, const int color1, const int color2 );
  void part_type_color_rgb( const int ind, const int rmin, const int rmax, const int gmin,
                            const int gmax, const int bmin, const int bmax );
  void part_type_color_hsv( const int ind, const int hmin, const int hmax, const int smin,
                            const int smax, const int vmin, const int vmax );
  void part_type_alpha1( const int ind, const double alpha1 );
  void part_type_alpha2( const int ind, const double alpha1, const double alpha2 );
  void part_type_alpha3( const int ind, const double alpha1, const double alpha2,
                         const double alpha3 );
  void part_type_blend( const int ind, const bool additive );
  void part_type_life( const int ind, const double life_min, const double life_max );
  void part_type_step( const int ind, const int step_number, const int step_type );
  void part_type_death( const int ind, const int death_number, const int death_type );
  void part_type_speed( const int ind, const double speed_min, const double speed_max,
                        const double speed_incr, const double speed_wiggle );
  void part_type_direction( const int ind, const double dir_min, const double dir_max,
                            const double dir_incr, const double dir_wiggle );
  void part_type_gravity( const int ind, const double grav_amount, const double grav_dir );
  int part_system_create();
  void part_system_destroy( const int ind );
  bool part_system_exists( const int ind );
  void part_system_clear( const int ind );
  void part_system_draw_order( const int ind, const bool oldtonew );
  void part_system_depth( const int ind, const int depth );
  void part_system_position( const int ind, const double x, const double y );
  void part_system_automatic_update( const int ind, const bool automatic );
  void part_system_automatic_draw( const int ind, const bool automatic );
  void part_system_update( const int ind );
  void part_system_drawit( const int ind );
  void part_particles_create( const int ind, const double x, const double y, const int parttype,
                              const int number );
  void part_particles_create_color( const int ind, const double x, const double y, 
                                    const int parttype, const int color, const int number );
  void part_particles_clear( const int ind );
  int part_particles_count( const int ind );
  int part_emitter_create( const int ps );
  void part_emitter_destroy( const int ps, const int ind );
  void part_emitter_destroy_all( const int ps );
  bool part_emitter_exists( const int ps, const int ind );
  void part_emitter_clear( const int ps, const int ind );
  void part_emitter_region( const int ps, const int ind, const double xmin, const double xmax,
                            const double ymin, const double ymax, const int shape,
                            const int distribution );
  void part_emitter_burst( const int ps, const int ind, const int parttype, const int number );
  void part_emitter_stream( const int ps, const int ind, const int parttype, const int number );
  int part_attractor_create( const int ps );
  void part_attractor_destroy( const int ps, const int ind );
  void part_attractor_destroy_all( const int ps );
  bool part_attractor_exists( const int ps, const int ind );
  void part_attractor_clear( const int ps, const int ind );
  void part_attractor_position( const int ps, const int ind, const double x, const double y );
  void part_attractor_force( const int ps, const int ind, const double force, const int dist,
                             const int kind, const bool aditive );
  int part_destroyer_create( const int ps );
  void part_destroyer_destroy( const int ps, const int ind );
  void part_destroyer_destroy_all( const int ps );
  bool part_destroyer_exists( const int ps, const int ind );
  void part_destroyer_clear( const int ps, const int ind );
  int part_destroyer_region( const int ps, const int ind, const double xmin, const double xmax,
                             const double ymin, const double ymax, const int shape );
  void part_deflector_destroy( const int ps, const int ind );
  void part_deflector_destroy_all( const int ps );
  bool part_deflector_exists( const int ps, const int ind );
  void part_deflector_clear( const int ps, const int ind );
  void part_deflector_region( const int ps, const int ind, const double xmin, const double xmax,
                              const double ymin, const double ymax );
  void part_deflector_kind( const int ps, const int ind, const int kind );
  void part_deflector_friction( const int ps, const int ind, const double friction );
  int part_changer_create( const int ps );
  void part_changer_destroy( const int ps, const int ind );
  void part_changer_destroy_all( const int ps );
  bool part_changer_exists( const int ps, const int ind );
  void part_changer_clear( const int ps, const int ind );
  void part_changer_region( const int ps, const int ind, const double xmin, const double xmax,
                            const double ymin, const double ymax, const int shape );
  void part_changer_types( const int ps, const int ind, const int parttype1,
                           const int parttype2 );
  void part_changer_kind( const int ps, const int ind, const int kind );

}