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

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
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

  void d3d_set_hidden( const bool enable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ enable };

    GM_NORMAL_CALL( id_d3d_set_hidden );
  }

  void d3d_set_perspective( const bool enable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ enable };

    GM_NORMAL_CALL( id_d3d_set_perspective );
  }

  void d3d_set_depth( const int depth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ depth };

    GM_NORMAL_CALL( id_d3d_set_depth );
  }

  void d3d_primitive_begin( const int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ kind };

    GM_NORMAL_CALL( id_d3d_primitive_begin );
  }

  void d3d_vertex( const double x, const double y, const double z ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z };

    GM_NORMAL_CALL( id_d3d_vertex );
  }

  void d3d_vertex_color( const double x, const double y, const double z, const int col,
                         const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, col, alpha };

    GM_NORMAL_CALL( id_d3d_vertex_color );
  }

  void d3d_primitive_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_primitive_end );
  }

  void d3d_draw_block( const double x1, const double y1, const double z1, const double x2,
                       const double y2, const double z2, const int texid, const double hrepeat,
                       const double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_draw_block );
  }

  void d3d_draw_cylinder( const double x1, const double y1, const double z1, const double x2,
                          const double y2, const double z2, const int texid,
                          const double hrepeat, const double vrepeat, const bool closed, 
                          const int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps };

    GM_NORMAL_CALL( id_d3d_draw_cylinder );
  }

  void d3d_draw_cone( const double x1, const double y1, const double z1, const double x2,
                      const double y2, const double z2, const int texid, const double hrepeat,
                      const double vrepeat, const bool closed, const int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps };

    GM_NORMAL_CALL( id_d3d_draw_cone );
  }

  void d3d_draw_ellipsoid( const double x1, const double y1, const double z1, const double x2,
                           const double y2, const double z2, const int texid,
                           const double hrepeat, const double vrepeat, const int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, steps };

    GM_NORMAL_CALL( id_d3d_draw_ellipsoid );
  }

  void d3d_draw_wall( const double x1, const double y1, const double z1, const double x2,
                      const double y2, const double z2, const int texid, const double hrepeat,
                      const double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_draw_wall );
  }

  void d3d_draw_floor( const double x1, const double y1, const double z1, const double x2,
                       const double y2, const double z2, const int texid, const double hrepeat,
                       const double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_draw_floor );
  }

  void d3d_set_projection( const double xfrom, const double yfrom, const double zfrom,
                           const double xto, const double yto, const double zto, 
                           const double xup, const double yup, const double zup ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xfrom, yfrom, zfrom, xto, yto, zto, xup, yup, zup };

    GM_NORMAL_CALL( id_d3d_set_projection );
  }

  void d3d_set_projection_ext( const double xfrom, const double yfrom, const double zfrom,
                               const double xto, const double yto, const double zto,
                               const double xup, const double yup, const double zup,
                               const double angle, const double aspect, const double znear, 
                               const double zfar ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xfrom, yfrom, zfrom, xto, yto, zto, xup, yup, zup, angle, aspect, znear, zfar };

    GM_NORMAL_CALL( id_d3d_set_projection_ext );
  }

  void d3d_set_projection_ortho( const double x, const double y, const double w, const double h,
                                 const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, angle };

    GM_NORMAL_CALL( id_d3d_set_projection_ortho );
  }

  void d3d_set_projection_perspective( const double x, const double y, const double w, 
                                       const double h, const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, w, h, angle };

    GM_NORMAL_CALL( id_d3d_set_projection_perspective );
  }

  void d3d_transform_set_identity() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_transform_set_identity );
  }

  void d3d_transform_set_translation( const double xt, const double yt, const double zt ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xt, yt, zt };

    GM_NORMAL_CALL( id_d3d_transform_set_translation );
  }

  void d3d_transform_set_scaling( const double xs, const double ys, const double zs ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xs, ys, zs };

    GM_NORMAL_CALL( id_d3d_transform_set_scaling );
  }

  void d3d_transform_set_rotation_x( const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_set_rotation_x );
  }

  void d3d_transform_set_rotation_y( const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_set_rotation_y );
  }

  void d3d_transform_set_rotation_z( const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_set_rotation_z );
  }

  void d3d_transform_set_rotation_axis( const double xa, const double ya, const double za,
                                        const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xa, ya, za, angle };

    GM_NORMAL_CALL( id_d3d_transform_set_rotation_axis );
  }

  void d3d_transform_add_translation( const double xt, const double yt, const double zt ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xt, yt, zt };

    GM_NORMAL_CALL( id_d3d_transform_add_translation );
  }

  void d3d_transform_add_scaling( const double xs, const double ys, const double zs ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ xs, ys, zs };

    GM_NORMAL_CALL( id_d3d_transform_add_scaling );
  }

  void d3d_transform_add_rotation_x( const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_add_rotation_x );
  }

  void d3d_transform_add_rotation_y( const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_add_rotation_y );
  }

  void d3d_transform_add_rotation_z( const double angle ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ angle };

    GM_NORMAL_CALL( id_d3d_transform_add_rotation_z );
  }

  void d3d_transform_add_rotation_axis( const double xa, const double ya, const double za, 
                                        const double angle ) {
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

  void d3d_set_fog( const bool enable, const int color, const double start, const double end ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ enable, color, start, end };

    GM_NORMAL_CALL( id_d3d_set_fog );
  }

  void d3d_set_lighting( const bool enable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ enable };

    GM_NORMAL_CALL( id_d3d_set_lighting );
  }

  void d3d_set_shading( const bool smooth ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ smooth };

    GM_NORMAL_CALL( id_d3d_set_shading );
  }

  void d3d_light_define_direction( const int ind, const double dx, const double dy,
                                   const double dz, const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, dx, dy, dz, col };

    GM_NORMAL_CALL( id_d3d_light_define_direction );
  }

  void d3d_light_define_point( const int ind, const double x, const double y, const double z,
                               const double range, const int col ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, range, col };

    GM_NORMAL_CALL( id_d3d_light_define_point );
  }

  void d3d_light_enable( const int ind, const bool enable ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, enable };

    GM_NORMAL_CALL( id_d3d_light_enable );
  }

  void d3d_vertex_normal( const double x, const double y, const double z, const double nx,
                          const double ny, const double nz ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, nx, ny, nz };

    GM_NORMAL_CALL( id_d3d_vertex_normal );
  }

  void d3d_vertex_normal_color( const double x, const double y, const double z, 
                                const double nx, const double ny, const double nz, 
                                const int col, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, nx, ny, nz, col, alpha };

    GM_NORMAL_CALL( id_d3d_vertex_normal_color );
  }

  void d3d_vertex_normal_texture( const double x, const double y, const double z,
                                  const double nx, const double ny, const double nz, 
                                  const double xtex, const double ytex ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, nx, ny, nz, xtex, ytex };

    GM_NORMAL_CALL( id_d3d_vertex_normal_texture );
  }

  void d3d_vertex_normal_texture_color( const double x, const double y, const double z,
                                        const double nx, const double ny, const double nz, 
                                        const double xtex, const double ytex, const int col, 
                                        const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ x, y, z, nx, ny, nz, xtex, ytex, col, alpha };

    GM_NORMAL_CALL( id_d3d_vertex_normal_texture_color );
  }

  int d3d_model_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_d3d_model_create );
    GM_RETURN_INT;
  }

  void d3d_model_destroy( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_d3d_model_destroy );
  }

  void d3d_model_clear( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_d3d_model_clear );
  }

  void d3d_model_save( const int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_d3d_model_save );
  }

  void d3d_model_load( const int ind, const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, fname };

    GM_NORMAL_CALL( id_d3d_model_load );
  }

  void d3d_model_draw( const int ind, const double x, const double y, const double z,
                       const int texid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, texid };

    GM_NORMAL_CALL( id_d3d_model_draw );
  }

  void d3d_model_primitive_begin( const int ind, const int kind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, kind };

    GM_NORMAL_CALL( id_d3d_model_primitive_begin );
  }

  void d3d_model_vertex( const int ind, const double x, const double y, const double z ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z };

    GM_NORMAL_CALL( id_d3d_model_vertex );
  }

  void d3d_model_vertex_color( const int ind, const double x, const double y, const double z,
                               const int col, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, col, alpha };

    GM_NORMAL_CALL( id_d3d_model_vertex_color );
  }

  void d3d_model_vertex_texture( const int ind, const double x, const double y, const double z,
                                 const double xtex, const double ytex ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, xtex, ytex };

    GM_NORMAL_CALL( id_d3d_model_vertex_texture );
  }

  void d3d_model_vertex_texture_color( const int ind, const double x, const double y,
                                       const double z, const double xtex, const double ytex, 
                                       const int col, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, xtex, ytex, col, alpha };

    GM_NORMAL_CALL( id_d3d_model_vertex_texture_color );
  }

  void d3d_model_vertex_normal( const int ind, const double x, const double y, const double z, 
                                const double nx, const double ny, const double nz ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, nx, ny, nz };

    GM_NORMAL_CALL( id_d3d_model_vertex_normal );
  }

  void d3d_model_vertex_normal_color( const int ind, const double x, const double y, 
                                      const double z, const double nx, const double ny, 
                                      const double nz, const int col, const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, nx, ny, nz, col, alpha };

    GM_NORMAL_CALL( id_d3d_model_vertex_normal_color );
  }

  void d3d_model_vertex_normal_texture( const int ind, const double x, const double y, 
                                        const double z, const double nx, const double ny,
                                        const double nz, const double xtex, const double ytex ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, nx, ny, nz, xtex, ytex };

    GM_NORMAL_CALL( id_d3d_model_vertex_normal_texture );
  }

  void d3d_model_vertex_normal_texture_color( const int ind, const double x, const double y,
                                              const double z, const double nx, const double ny,
                                              const double nz, const double xtex,
                                              const double ytex, const int col, 
                                              const double alpha ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x, y, z, nx, ny, nz, xtex, ytex, col, alpha };

    GM_NORMAL_CALL( id_d3d_model_vertex_normal_texture_color );
  }

  void d3d_model_primitive_end( const int ind ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_d3d_model_primitive_end );
  }

  void d3d_model_block( const int ind, const double x1, const double y1, const double z1,
                        const double x2, const double y2, const double z2, const double hrepeat,
                        const double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_model_block );
  }

  void d3d_model_cylinder( const int ind, const double x1, const double y1, const double z1,
                           const double x2, const double y2, const double z2, 
                           const double hrepeat, const double vrepeat, const bool closed,
                           const int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, closed, steps };

    GM_NORMAL_CALL( id_d3d_model_cylinder );
  }

  void d3d_model_cone( const int ind, const double x1, const double y1, const double z1, 
                       const double x2, const double y2, const double z2, const double hrepeat,
                       const double vrepeat, const bool closed, const int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, closed, steps };

    GM_NORMAL_CALL( id_d3d_model_cone );
  }

  void d3d_model_ellipsoid( const int ind, const double x1, const double y1, const double z1, 
                            const double x2, const double y2, const double z2,
                            const double hrepeat, const double vrepeat, const int steps ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, steps };

    GM_NORMAL_CALL( id_d3d_model_ellipsoid );
  }

  void d3d_model_wall( const int ind, const double x1, const double y1, const double z1,
                       const double x2, const double y2, const double z2, const double hrepeat,
                       const double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_model_wall );
  }

  void d3d_model_floor( const int ind, const double x1, const double y1, const double z1,
                        const double x2, const double y2, const double z2, const double hrepeat,
                        const double vrepeat ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat };

    GM_NORMAL_CALL( id_d3d_model_floor );
  }

}