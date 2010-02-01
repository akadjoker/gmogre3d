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
  Gmapi3DGraphics.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "Gmapi3DGraphics.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  bool d3d_start() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_start );
    GM_RETURN_BOOL;
  }

  bool d3d_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_end );
    GM_RETURN_BOOL;
  }

  void d3d_set_hidden( bool enable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ enable };

    GM_NORMAL_CALL( id_d3d_set_hidden );
  }

  void d3d_set_perspective( bool enable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ enable };

    GM_NORMAL_CALL( id_d3d_set_perspective );
  }

  void d3d_set_depth( int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth };

    GM_NORMAL_CALL( id_d3d_set_depth );
  }

  void d3d_primitive_begin( int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind };

    GM_NORMAL_CALL( id_d3d_primitive_begin );
  }

  void d3d_vertex( double x, double y, double z ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z };

    GM_NORMAL_CALL( id_d3d_vertex );
  }

  void d3d_vertex_color( double x, double y, double z, int col,
                         double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, col, alpha };

    GM_NORMAL_CALL( id_d3d_vertex_color );
  }

  void d3d_primitive_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_primitive_end );
  }

  void d3d_draw_block( double x1, double y1, double z1, double x2,
                       double y2, double z2, int texid, double hrepeat,
                       double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_draw_block );
  }

  void d3d_draw_cylinder( double x1, double y1, double z1, double x2,
                          double y2, double z2, int texid,
                          double hrepeat, double vrepeat, bool closed, 
                          int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps };

    GM_NORMAL_CALL( id_d3d_draw_cylinder );
  }

  void d3d_draw_cone( double x1, double y1, double z1, double x2,
                      double y2, double z2, int texid, double hrepeat,
                      double vrepeat, bool closed, int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps };

    GM_NORMAL_CALL( id_d3d_draw_cone );
  }

  void d3d_draw_ellipsoid( double x1, double y1, double z1, double x2,
                           double y2, double z2, int texid,
                           double hrepeat, double vrepeat, int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, steps };

    GM_NORMAL_CALL( id_d3d_draw_ellipsoid );
  }

  void d3d_draw_wall( double x1, double y1, double z1, double x2,
                      double y2, double z2, int texid, double hrepeat,
                      double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_draw_wall );
  }

  void d3d_draw_floor( double x1, double y1, double z1, double x2,
                       double y2, double z2, int texid, double hrepeat,
                       double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_draw_floor );
  }

  void d3d_set_projection( double xfrom, double yfrom, double zfrom,
                           double xto, double yto, double zto, 
                           double xup, double yup, double zup ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xfrom, yfrom, zfrom, xto, yto, zto, xup, yup, zup };

    GM_NORMAL_CALL( id_d3d_set_projection );
  }

  void d3d_set_projection_ext( double xfrom, double yfrom, double zfrom,
                               double xto, double yto, double zto,
                               double xup, double yup, double zup,
                               double angle, double aspect, double znear, 
                               double zfar ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xfrom, yfrom, zfrom, xto, yto, zto, xup, yup, zup, angle, aspect, znear, zfar };

    GM_NORMAL_CALL( id_d3d_set_projection_ext );
  }

  void d3d_set_projection_ortho( double x, double y, double w, double h,
                                 double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, angle };

    GM_NORMAL_CALL( id_d3d_set_projection_ortho );
  }

  void d3d_set_projection_perspective( double x, double y, double w, 
                                       double h, double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, angle };

    GM_NORMAL_CALL( id_d3d_set_projection_perspective );
  }

  void d3d_transform_set_identity() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_transform_set_identity );
  }

  void d3d_transform_set_translation( double xt, double yt, double zt ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xt, yt, zt };

    GM_NORMAL_CALL( id_d3d_transform_set_translation );
  }

  void d3d_transform_set_scaling( double xs, double ys, double zs ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xs, ys, zs };

    GM_NORMAL_CALL( id_d3d_transform_set_scaling );
  }

  void d3d_transform_set_rotation_x( double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_set_rotation_x );
  }

  void d3d_transform_set_rotation_y( double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_set_rotation_y );
  }

  void d3d_transform_set_rotation_z( double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_set_rotation_z );
  }

  void d3d_transform_set_rotation_axis( double xa, double ya, double za,
                                        double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xa, ya, za, angle };

    GM_NORMAL_CALL( id_d3d_transform_set_rotation_axis );
  }

  void d3d_transform_add_translation( double xt, double yt, double zt ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xt, yt, zt };

    GM_NORMAL_CALL( id_d3d_transform_add_translation );
  }

  void d3d_transform_add_scaling( double xs, double ys, double zs ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xs, ys, zs };

    GM_NORMAL_CALL( id_d3d_transform_add_scaling );
  }

  void d3d_transform_add_rotation_x( double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_add_rotation_x );
  }

  void d3d_transform_add_rotation_y( double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_add_rotation_y );
  }

  void d3d_transform_add_rotation_z( double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_add_rotation_z );
  }

  void d3d_transform_add_rotation_axis( double xa, double ya, double za, 
                                        double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xa, ya, za, angle };

    GM_NORMAL_CALL( id_d3d_transform_add_rotation_axis );
  }

  void d3d_transform_stack_clear() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_transform_stack_clear );
  }

  bool d3d_transform_stack_empty() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_transform_stack_empty );
    GM_RETURN_BOOL;
  }

  bool d3d_transform_stack_push() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_transform_stack_push );
    GM_RETURN_BOOL;
  }

  bool d3d_transform_stack_pop() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_transform_stack_pop );
    GM_RETURN_BOOL;
  }

  bool d3d_transform_stack_top() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_transform_stack_top );
    GM_RETURN_BOOL;
  }

  bool d3d_transform_stack_discard() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_transform_stack_discard );
    GM_RETURN_BOOL;
  }

  void d3d_set_fog( bool enable, int color, double start, double end ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ enable, color, start, end };

    GM_NORMAL_CALL( id_d3d_set_fog );
  }

  void d3d_set_lighting( bool enable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ enable };

    GM_NORMAL_CALL( id_d3d_set_lighting );
  }

  void d3d_set_shading( bool smooth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ smooth };

    GM_NORMAL_CALL( id_d3d_set_shading );
  }

  void d3d_light_define_direction( int ind, double dx, double dy,
                                   double dz, int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, dx, dy, dz, col };

    GM_NORMAL_CALL( id_d3d_light_define_direction );
  }

  void d3d_light_define_point( int ind, double x, double y, double z,
                               double range, int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, range, col };

    GM_NORMAL_CALL( id_d3d_light_define_point );
  }

  void d3d_light_enable( int ind, bool enable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, enable };

    GM_NORMAL_CALL( id_d3d_light_enable );
  }

  void d3d_vertex_normal( double x, double y, double z, double nx,
                          double ny, double nz ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, nx, ny, nz };

    GM_NORMAL_CALL( id_d3d_vertex_normal );
  }

  void d3d_vertex_normal_color( double x, double y, double z, 
                                double nx, double ny, double nz, 
                                int col, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, nx, ny, nz, col, alpha };

    GM_NORMAL_CALL( id_d3d_vertex_normal_color );
  }

  void d3d_vertex_normal_texture( double x, double y, double z,
                                  double nx, double ny, double nz, 
                                  double xtex, double ytex ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, nx, ny, nz, xtex, ytex };

    GM_NORMAL_CALL( id_d3d_vertex_normal_texture );
  }

  void d3d_vertex_normal_texture_color( double x, double y, double z,
                                        double nx, double ny, double nz, 
                                        double xtex, double ytex, int col, 
                                        double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, nx, ny, nz, xtex, ytex, col, alpha };

    GM_NORMAL_CALL( id_d3d_vertex_normal_texture_color );
  }

  int d3d_model_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_model_create );
    GM_RETURN_INT;
  }

  void d3d_model_destroy( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_d3d_model_destroy );
  }

  void d3d_model_clear( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_d3d_model_clear );
  }

  void d3d_model_save( int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_d3d_model_save );
  }

  void d3d_model_load( int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_d3d_model_load );
  }

  void d3d_model_draw( int ind, double x, double y, double z,
                       int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, texid };

    GM_NORMAL_CALL( id_d3d_model_draw );
  }

  void d3d_model_primitive_begin( int ind, int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, kind };

    GM_NORMAL_CALL( id_d3d_model_primitive_begin );
  }

  void d3d_model_vertex( int ind, double x, double y, double z ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z };

    GM_NORMAL_CALL( id_d3d_model_vertex );
  }

  void d3d_model_vertex_color( int ind, double x, double y, double z,
                               int col, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, col, alpha };

    GM_NORMAL_CALL( id_d3d_model_vertex_color );
  }

  void d3d_model_vertex_texture( int ind, double x, double y, double z,
                                 double xtex, double ytex ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, xtex, ytex };

    GM_NORMAL_CALL( id_d3d_model_vertex_texture );
  }

  void d3d_model_vertex_texture_color( int ind, double x, double y,
                                       double z, double xtex, double ytex, 
                                       int col, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, xtex, ytex, col, alpha };

    GM_NORMAL_CALL( id_d3d_model_vertex_texture_color );
  }

  void d3d_model_vertex_normal( int ind, double x, double y, double z, 
                                double nx, double ny, double nz ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, nx, ny, nz };

    GM_NORMAL_CALL( id_d3d_model_vertex_normal );
  }

  void d3d_model_vertex_normal_color( int ind, double x, double y, 
                                      double z, double nx, double ny, 
                                      double nz, int col, double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, nx, ny, nz, col, alpha };

    GM_NORMAL_CALL( id_d3d_model_vertex_normal_color );
  }

  void d3d_model_vertex_normal_texture( int ind, double x, double y, 
                                        double z, double nx, double ny,
                                        double nz, double xtex, double ytex ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, nx, ny, nz, xtex, ytex };

    GM_NORMAL_CALL( id_d3d_model_vertex_normal_texture );
  }

  void d3d_model_vertex_normal_texture_color( int ind, double x, double y,
                                              double z, double nx, double ny,
                                              double nz, double xtex,
                                              double ytex, int col, 
                                              double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, nx, ny, nz, xtex, ytex, col, alpha };

    GM_NORMAL_CALL( id_d3d_model_vertex_normal_texture_color );
  }

  void d3d_model_primitive_end( int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_d3d_model_primitive_end );
  }

  void d3d_model_block( int ind, double x1, double y1, double z1,
                        double x2, double y2, double z2, double hrepeat,
                        double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_model_block );
  }

  void d3d_model_cylinder( int ind, double x1, double y1, double z1,
                           double x2, double y2, double z2, 
                           double hrepeat, double vrepeat, bool closed,
                           int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, closed, steps };

    GM_NORMAL_CALL( id_d3d_model_cylinder );
  }

  void d3d_model_cone( int ind, double x1, double y1, double z1, 
                       double x2, double y2, double z2, double hrepeat,
                       double vrepeat, bool closed, int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, closed, steps };

    GM_NORMAL_CALL( id_d3d_model_cone );
  }

  void d3d_model_ellipsoid( int ind, double x1, double y1, double z1, 
                            double x2, double y2, double z2,
                            double hrepeat, double vrepeat, int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, steps };

    GM_NORMAL_CALL( id_d3d_model_ellipsoid );
  }

  void d3d_model_wall( int ind, double x1, double y1, double z1,
                       double x2, double y2, double z2, double hrepeat,
                       double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_model_wall );
  }

  void d3d_model_floor( int ind, double x1, double y1, double z1,
                        double x2, double y2, double z2, double hrepeat,
                        double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_model_floor );
  }

}