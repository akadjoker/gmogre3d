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

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiParticles.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void effect_create_below( int kind, double x, double y, int size,
                            int color ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind, x, y, size, color };

    GM_NORMAL_CALL( id_effect_create_below );
  }

  void effect_create_above( int kind, double x, double y, int size,
                            int color ) {
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

  void part_type_destroy( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_type_destroy );
  }

  bool part_type_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_type_exists );
    GM_RETURN_BOOL;
  }

  void part_type_clear( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_type_clear );
  }

  void part_type_shape( int ind, int shape ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, shape };

    GM_NORMAL_CALL( id_part_type_shape );
  }

  void part_type_sprite( int ind, int sprite, bool animat, bool stretch,
                         bool random ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, sprite, animat, stretch, random };

    GM_NORMAL_CALL( id_part_type_sprite );
  }

  void part_type_size( int ind, double size_min, double size_max,
                       double size_incr, double size_wiggle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, size_min, size_max, size_incr, size_wiggle };

    GM_NORMAL_CALL( id_part_type_size );
  }

  void part_type_scale( int ind, double xscale, double yscale ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, xscale, yscale };

    GM_NORMAL_CALL( id_part_type_scale );
  }

  void part_type_orientation( int ind, double ang_min, double ang_max,
                              double ang_incr, double ang_wiggle,
                              bool ang_relative ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, ang_min, ang_max, ang_incr, ang_wiggle, ang_relative };

    GM_NORMAL_CALL( id_part_type_orientation );
  }

  void part_type_color1( int ind, int color1 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, color1 };

    GM_NORMAL_CALL( id_part_type_color1 );
  }

  void part_type_color2( int ind, int color1, int color2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, color1, color2 };

    GM_NORMAL_CALL( id_part_type_color2 );
  }

  void part_type_color3( int ind, int color1, int color2, int color3 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, color1, color2, color3 };

    GM_NORMAL_CALL( id_part_type_color3 );
  }

  void part_type_color_mix( int ind, int color1, int color2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, color1, color2 };

    GM_NORMAL_CALL( id_part_type_color_mix );
  }

  void part_type_color_rgb( int ind, int rmin, int rmax, int gmin,
                            int gmax, int bmin, int bmax ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, rmin, rmax, gmin, gmax, bmin, bmax };

    GM_NORMAL_CALL( id_part_type_color_rgb );
  }

  void part_type_color_hsv( int ind, int hmin, int hmax, int smin,
                            int smax, int vmin, int vmax ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, hmin, hmax, smin, smax, vmin, vmax };

    GM_NORMAL_CALL( id_part_type_color_hsv );
  }

  void part_type_alpha1( int ind, double alpha1 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, alpha1 };

    GM_NORMAL_CALL( id_part_type_alpha1 );
  }

  void part_type_alpha2( int ind, double alpha1, double alpha2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, alpha1, alpha2 };

    GM_NORMAL_CALL( id_part_type_alpha2 );
  }

  void part_type_alpha3( int ind, double alpha1, double alpha2,
                         double alpha3 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, alpha1, alpha2, alpha3 };

    GM_NORMAL_CALL( id_part_type_alpha3 );
  }

  void part_type_blend( int ind, bool additive ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, additive };

    GM_NORMAL_CALL( id_part_type_blend );
  }

  void part_type_life( int ind, double life_min, double life_max ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, life_min, life_max };

    GM_NORMAL_CALL( id_part_type_life );
  }

  void part_type_step( int ind, int step_number, int step_type ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, step_number, step_type };

    GM_NORMAL_CALL( id_part_type_step );
  }

  void part_type_death( int ind, int death_number, int death_type ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, death_number, death_type };

    GM_NORMAL_CALL( id_part_type_death );
  }

  void part_type_speed( int ind, double speed_min, double speed_max,
                        double speed_incr, double speed_wiggle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, speed_min, speed_max, speed_incr, speed_wiggle };

    GM_NORMAL_CALL( id_part_type_speed );
  }

  void part_type_direction( int ind, double dir_min, double dir_max,
                            double dir_incr, double dir_wiggle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, dir_min, dir_max, dir_incr, dir_wiggle };

    GM_NORMAL_CALL( id_part_type_direction );
  }

  void part_type_gravity( int ind, double grav_amount, double grav_dir ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, grav_amount, grav_dir };

    GM_NORMAL_CALL( id_part_type_gravity );
  }

  int part_system_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_part_system_create );
    GM_RETURN_INT;
  }

  void part_system_destroy( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_destroy );
  }

  bool part_system_exists( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_exists );
    GM_RETURN_BOOL;
  }

  void part_system_clear( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_clear );
  }

  void part_system_draw_order( int ind, bool oldtonew ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, oldtonew };

    GM_NORMAL_CALL( id_part_system_draw_order );
  }

  void part_system_depth( int ind, int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, depth };

    GM_NORMAL_CALL( id_part_system_depth );
  }

  void part_system_position( int ind, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y };

    GM_NORMAL_CALL( id_part_system_position );
  }

  void part_system_automatic_update( int ind, bool automatic ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, automatic };

    GM_NORMAL_CALL( id_part_system_automatic_update );
  }

  void part_system_automatic_draw( int ind, bool automatic ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, automatic };

    GM_NORMAL_CALL( id_part_system_automatic_draw );
  }

  void part_system_update( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_update );
  }

  void part_system_drawit( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_system_drawit );
  }

  void part_particles_create( int ind, double x, double y, int parttype,
                              int number ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, parttype, number };

    GM_NORMAL_CALL( id_part_particles_create );
  }

  void part_particles_create_color( int ind, double x, double y,
                                    int parttype, int color, int number ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, parttype, color, number };

    GM_NORMAL_CALL( id_part_particles_create_color );
  }

  void part_particles_clear( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_particles_clear );
  }

  int part_particles_count( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_part_particles_count );
    GM_RETURN_INT;
  }

  int part_emitter_create( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_emitter_create );
    GM_RETURN_INT;
  }

  void part_emitter_destroy( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_emitter_destroy );
  }

  void part_emitter_destroy_all( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_emitter_destroy_all );
  }

  bool part_emitter_exists( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_emitter_exists );
    GM_RETURN_BOOL;
  }

  void part_emitter_clear( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_emitter_clear );
  }

  void part_emitter_region( int ps, int ind, double xmin, double xmax,
                            double ymin, double ymax, int shape,
                            int distribution ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, xmin, xmax, ymin, ymax, shape, distribution };

    GM_NORMAL_CALL( id_part_emitter_region );
  }

  void part_emitter_burst( int ps, int ind, int parttype, int number ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, parttype, number };

    GM_NORMAL_CALL( id_part_emitter_burst );
  }

  void part_emitter_stream( int ps, int ind, int parttype, int number ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, parttype, number };

    GM_NORMAL_CALL( id_part_emitter_stream );
  }

  int part_attractor_create( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_attractor_create );
    GM_RETURN_INT;
  }

  void part_attractor_destroy( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_attractor_destroy );
  }

  void part_attractor_destroy_all( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_attractor_destroy_all );
  }

  bool part_attractor_exists( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_attractor_exists );
    GM_RETURN_BOOL;
  }

  void part_attractor_clear( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_attractor_clear );
  }

  void part_attractor_position( int ps, int ind, double x, double y ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, x, y };

    GM_NORMAL_CALL( id_part_attractor_position );
  }

  void part_attractor_force( int ps, int ind, double force, int dist,
                             int kind, bool aditive ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, force, dist, kind, aditive };

    GM_NORMAL_CALL( id_part_attractor_force );
  }

  int part_destroyer_create( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_destroyer_create );
    GM_RETURN_INT;
  }

  void part_destroyer_destroy( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_destroyer_destroy );
  }

  void part_destroyer_destroy_all( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_destroyer_destroy_all );
  }

  bool part_destroyer_exists( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_destroyer_exists );
    GM_RETURN_BOOL;
  }

  void part_destroyer_clear( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_destroyer_clear );
  }

  int part_destroyer_region( int ps, int ind, double xmin, double xmax,
                             double ymin, double ymax, int shape ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, xmin, xmax, ymin, ymax, shape };

    GM_NORMAL_CALL( id_part_destroyer_region );
    GM_RETURN_INT;
  }

  void part_deflector_destroy( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_deflector_destroy );
  }

  void part_deflector_destroy_all( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_deflector_destroy_all );
  }

  bool part_deflector_exists( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_deflector_exists );
    GM_RETURN_BOOL;
  }

  void part_deflector_clear( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_deflector_clear );
  }

  void part_deflector_region( int ps, int ind, double xmin, double xmax,
                              double ymin, double ymax ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, xmin, xmax, ymin, ymax };

    GM_NORMAL_CALL( id_part_deflector_region );
  }

  void part_deflector_kind( int ps, int ind, int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, kind };

    GM_NORMAL_CALL( id_part_deflector_kind );
  }

  void part_deflector_friction( int ps, int ind, double friction ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, friction };

    GM_NORMAL_CALL( id_part_deflector_friction );
  }

  int part_changer_create( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_changer_create );
    GM_RETURN_INT;
  }

  void part_changer_destroy( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_changer_destroy );
  }

  void part_changer_destroy_all( int ps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps };

    GM_NORMAL_CALL( id_part_changer_destroy_all );
  }

  bool part_changer_exists( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_changer_exists );
    GM_RETURN_BOOL;
  }

  void part_changer_clear( int ps, int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind };

    GM_NORMAL_CALL( id_part_changer_clear );
  }

  void part_changer_region( int ps, int ind, double xmin, 
                            double xmax, double ymin, double ymax, 
                            int shape ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, xmin, xmax, ymin, ymax, shape };

    GM_NORMAL_CALL( id_part_changer_region );
  }

  void part_changer_types( int ps, int ind, int parttype1,
                           int parttype2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, parttype1, parttype2 };

    GM_NORMAL_CALL( id_part_changer_types );
  }

  void part_changer_kind( int ps, int ind, int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ps, ind, kind };

    GM_NORMAL_CALL( id_part_changer_kind );
  }

}