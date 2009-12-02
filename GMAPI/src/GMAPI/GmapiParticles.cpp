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
  GmapiParticles.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiParticles.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void effect_create_below( const int kind, const double x, const double y, const int size,
                            const int color ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind, x, y, size, color };

    GM_NORMAL_CALL( id_effect_create_below );
  }

  void effect_create_above( const int kind, const double x, const double y, const int size,
                            const int color ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind, x, y, size, color };

    GM_NORMAL_CALL( id_effect_create_above );
  }

  void effect_clear() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_effect_clear );
  }

  int part_type_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_part_type_create );
    GM_RETURN_INT;
  }

  void part_type_destroy( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_type_destroy );
  }

  bool part_type_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_type_exists );
    GM_RETURN_BOOL;
  }

  void part_type_clear( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_type_clear );
  }

  void part_type_shape( const int ind, const int shape ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, shape };

    GM_NORMAL_CALL( id_part_type_shape );
  }

  void part_type_sprite( const int ind, const int sprite, const bool animat, const bool stretch,
                         const bool random ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, sprite, animat, stretch, random };

    GM_NORMAL_CALL( id_part_type_sprite );
  }

  void part_type_size( const int ind, const double size_min, const double size_max,
                       const double size_incr, const double size_wiggle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, size_min, size_max, size_incr, size_wiggle };

    GM_NORMAL_CALL( id_part_type_size );
  }

  void part_type_scale( const int ind, const double xscale, const double yscale ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, xscale, yscale };

    GM_NORMAL_CALL( id_part_type_scale );
  }

  void part_type_orientation( const int ind, const double ang_min, const double ang_max,
                              const double ang_incr, const double ang_wiggle,
                              const bool ang_relative ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, ang_min, ang_max, ang_incr, ang_wiggle, ang_relative };

    GM_NORMAL_CALL( id_part_type_orientation );
  }

  void part_type_color1( const int ind, const int color1 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, color1 };

    GM_NORMAL_CALL( id_part_type_color1 );
  }

  void part_type_color2( const int ind, const int color1, const int color2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, color1, color2 };

    GM_NORMAL_CALL( id_part_type_color2 );
  }

  void part_type_color3( const int ind, const int color1, const int color2, const int color3 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, color1, color2, color3 };

    GM_NORMAL_CALL( id_part_type_color3 );
  }

  void part_type_color_mix( const int ind, const int color1, const int color2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, color1, color2 };

    GM_NORMAL_CALL( id_part_type_color_mix );
  }

  void part_type_color_rgb( const int ind, const int rmin, const int rmax, const int gmin,
                            const int gmax, const int bmin, const int bmax ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, rmin, rmax, gmin, gmax, bmin, bmax };

    GM_NORMAL_CALL( id_part_type_color_rgb );
  }

  void part_type_color_hsv( const int ind, const int hmin, const int hmax, const int smin,
                            const int smax, const int vmin, const int vmax ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, hmin, hmax, smin, smax, vmin, vmax };

    GM_NORMAL_CALL( id_part_type_color_hsv );
  }

  void part_type_alpha1( const int ind, const double alpha1 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, alpha1 };

    GM_NORMAL_CALL( id_part_type_alpha1 );
  }

  void part_type_alpha2( const int ind, const double alpha1, const double alpha2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, alpha1, alpha2 };

    GM_NORMAL_CALL( id_part_type_alpha2 );
  }

  void part_type_alpha3( const int ind, const double alpha1, const double alpha2,
                         const double alpha3 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, alpha1, alpha2, alpha3 };

    GM_NORMAL_CALL( id_part_type_alpha3 );
  }

  void part_type_blend( const int ind, const bool additive ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, additive };

    GM_NORMAL_CALL( id_part_type_blend );
  }

  void part_type_life( const int ind, const double life_min, const double life_max ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, life_min, life_max };

    GM_NORMAL_CALL( id_part_type_life );
  }

  void part_type_step( const int ind, const int step_number, const int step_type ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, step_number, step_type };

    GM_NORMAL_CALL( id_part_type_step );
  }

  void part_type_death( const int ind, const int death_number, const int death_type ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, death_number, death_type };

    GM_NORMAL_CALL( id_part_type_death );
  }

  void part_type_speed( const int ind, const double speed_min, const double speed_max,
                        const double speed_incr, const double speed_wiggle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, speed_min, speed_max, speed_incr, speed_wiggle };

    GM_NORMAL_CALL( id_part_type_speed );
  }

  void part_type_direction( const int ind, const double dir_min, const double dir_max,
                            const double dir_incr, const double dir_wiggle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, dir_min, dir_max, dir_incr, dir_wiggle };

    GM_NORMAL_CALL( id_part_type_direction );
  }

  void part_type_gravity( const int ind, const double grav_amount, const double grav_dir ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, grav_amount, grav_dir };

    GM_NORMAL_CALL( id_part_type_gravity );
  }

  int part_system_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_part_system_create );
    GM_RETURN_INT;
  }

  void part_system_destroy( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_destroy );
  }

  bool part_system_exists( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_exists );
    GM_RETURN_BOOL;
  }

  void part_system_clear( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_clear );
  }

  void part_system_draw_order( const int ind, const bool oldtonew ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, oldtonew };

    GM_NORMAL_CALL( id_part_system_draw_order );
  }

  void part_system_depth( const int ind, const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, depth };

    GM_NORMAL_CALL( id_part_system_depth );
  }

  void part_system_position( const int ind, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y };

    GM_NORMAL_CALL( id_part_system_position );
  }

  void part_system_automatic_update( const int ind, const bool automatic ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, automatic };

    GM_NORMAL_CALL( id_part_system_automatic_update );
  }

  void part_system_automatic_draw( const int ind, const bool automatic ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, automatic };

    GM_NORMAL_CALL( id_part_system_automatic_draw );
  }

  void part_system_update( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_update );
  }

  void part_system_drawit( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_drawit );
  }

  void part_particles_create( const int ind, const double x, const double y, const int parttype,
                              const int number ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, parttype, number };

    GM_NORMAL_CALL( id_part_particles_create );
  }

  void part_particles_create_color( const int ind, const double x, const double y,
                                    const int parttype, const int color, const int number ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, parttype, color, number };

    GM_NORMAL_CALL( id_part_particles_create_color );
  }

  void part_particles_clear( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_particles_clear );
  }

  int part_particles_count( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_particles_count );
    GM_RETURN_INT;
  }

  int part_emitter_create( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_emitter_create );
    GM_RETURN_INT;
  }

  void part_emitter_destroy( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_emitter_destroy );
  }

  void part_emitter_destroy_all( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_emitter_destroy_all );
  }

  bool part_emitter_exists( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_emitter_exists );
    GM_RETURN_BOOL;
  }

  void part_emitter_clear( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_emitter_clear );
  }

  void part_emitter_region( const int ps, const int ind, const double xmin, const double xmax,
                            const double ymin, const double ymax, const int shape,
                            const int distribution ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, xmin, xmax, ymin, ymax, shape, distribution };

    GM_NORMAL_CALL( id_part_emitter_region );
  }

  void part_emitter_burst( const int ps, const int ind, const int parttype, const int number ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, parttype, number };

    GM_NORMAL_CALL( id_part_emitter_burst );
  }

  void part_emitter_stream( const int ps, const int ind, const int parttype, const int number ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, parttype, number };

    GM_NORMAL_CALL( id_part_emitter_stream );
  }

  int part_attractor_create( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_attractor_create );
    GM_RETURN_INT;
  }

  void part_attractor_destroy( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_attractor_destroy );
  }

  void part_attractor_destroy_all( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_attractor_destroy_all );
  }

  bool part_attractor_exists( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_attractor_exists );
    GM_RETURN_BOOL;
  }

  void part_attractor_clear( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_attractor_clear );
  }

  void part_attractor_position( const int ps, const int ind, const double x, const double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, x, y };

    GM_NORMAL_CALL( id_part_attractor_position );
  }

  void part_attractor_force( const int ps, const int ind, const double force, const int dist,
                             const int kind, const bool aditive ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, force, dist, kind, aditive };

    GM_NORMAL_CALL( id_part_attractor_force );
  }

  int part_destroyer_create( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_destroyer_create );
    GM_RETURN_INT;
  }

  void part_destroyer_destroy( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_destroyer_destroy );
  }

  void part_destroyer_destroy_all( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_destroyer_destroy_all );
  }

  bool part_destroyer_exists( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_destroyer_exists );
    GM_RETURN_BOOL;
  }

  void part_destroyer_clear( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_destroyer_clear );
  }

  int part_destroyer_region( const int ps, const int ind, const double xmin, const double xmax,
                             const double ymin, const double ymax, const int shape ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, xmin, xmax, ymin, ymax, shape };

    GM_NORMAL_CALL( id_part_destroyer_region );
    GM_RETURN_INT;
  }

  void part_deflector_destroy( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_deflector_destroy );
  }

  void part_deflector_destroy_all( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_deflector_destroy_all );
  }

  bool part_deflector_exists( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_deflector_exists );
    GM_RETURN_BOOL;
  }

  void part_deflector_clear( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_deflector_clear );
  }

  void part_deflector_region( const int ps, const int ind, const double xmin, const double xmax,
                              const double ymin, const double ymax ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, xmin, xmax, ymin, ymax };

    GM_NORMAL_CALL( id_part_deflector_region );
  }

  void part_deflector_kind( const int ps, const int ind, const int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, kind };

    GM_NORMAL_CALL( id_part_deflector_kind );
  }

  void part_deflector_friction( const int ps, const int ind, const double friction ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, friction };

    GM_NORMAL_CALL( id_part_deflector_friction );
  }

  int part_changer_create( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_changer_create );
    GM_RETURN_INT;
  }

  void part_changer_destroy( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_changer_destroy );
  }

  void part_changer_destroy_all( const int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_changer_destroy_all );
  }

  bool part_changer_exists( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_changer_exists );
    GM_RETURN_BOOL;
  }

  void part_changer_clear( const int ps, const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_changer_clear );
  }

  void part_changer_region( const int ps, const int ind, const double xmin, 
                            const double xmax, const double ymin, const double ymax, 
                            const int shape ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, xmin, xmax, ymin, ymax, shape };

    GM_NORMAL_CALL( id_part_changer_region );
  }

  void part_changer_types( const int ps, const int ind, const int parttype1,
                           const int parttype2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, parttype1, parttype2 };

    GM_NORMAL_CALL( id_part_changer_types );
  }

  void part_changer_kind( const int ps, const int ind, const int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, kind };

    GM_NORMAL_CALL( id_part_changer_kind );
  }

}