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
  Gmapi3DGraphics.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  bool d3d_start();
  bool d3d_end();
  void d3d_set_hidden( const bool enable );
  void d3d_set_perspective( const bool enable );
  void d3d_set_depth( const int depth );
  void d3d_primitive_begin( const int kind );
  void d3d_vertex( const double x, const double y, const double z );
  void d3d_vertex_color( const double x, const double y, const double z, const int col,
                         const double alpha );
  void d3d_primitive_end();
  void d3d_draw_block( const double x1, const double y1, const double z1, const double x2, 
                       const double y2, const double z2, const int texid, const double hrepeat,
                       const double vrepeat );
  void d3d_draw_cylinder( const double x1, const double y1, const double z1, const double x2,
                          const double y2, const double z2, const int texid, 
                          const double hrepeat, const double vrepeat, const bool closed, 
                          const int steps );
  void d3d_draw_cone( const double x1, const double y1, const double z1, const double x2, 
                      const double y2, const double z2, const int texid, const double hrepeat,
                      const double vrepeat, const bool closed, const int steps );
  void d3d_draw_ellipsoid( const double x1, const double y1, const double z1, const double x2,
                           const double y2, const double z2, const int texid,
                           const double hrepeat, const double vrepeat, const int steps );
  void d3d_draw_wall( const double x1, const double y1, const double z1, const double x2,
                      const double y2, const double z2, const int texid, const double hrepeat,
                      const double vrepeat );
  void d3d_draw_floor( const double x1, const double y1, const double z1, const double x2,
                       const double y2, const double z2, const int texid, const double hrepeat,
                       const double vrepeat );
  void d3d_set_projection( const double xfrom, const double yfrom, const double zfrom, 
                           const double xto, const double yto, const double zto, 
                           const double xup, const double yup, const double zup );
  void d3d_set_projection_ext( const double xfrom, const double yfrom, const double zfrom, 
                               const double xto, const double yto, const double zto, 
                               const double xup, const double yup, const double zup, 
                               const double angle, const double aspect, const double znear,
                               const double zfar );
  void d3d_set_projection_ortho( const double x, const double y, const double w, const double h,
                                 const double angle );
  void d3d_set_projection_perspective( const double x, const double y, const double w, 
                                       const double h, const double angle );
  void d3d_transform_set_identity();
  void d3d_transform_set_translation( const double xt, const double yt, const double zt );
  void d3d_transform_set_scaling( const double xs, const double ys, const double zs );
  void d3d_transform_set_rotation_x( const double angle );
  void d3d_transform_set_rotation_y( const double angle );
  void d3d_transform_set_rotation_z( const double angle );
  void d3d_transform_set_rotation_axis( const double xa, const double ya, const double za,
                                        const double angle );
  void d3d_transform_add_translation( const double xt, const double yt, const double zt );
  void d3d_transform_add_scaling( const double xs, const double ys, const double zs );
  void d3d_transform_add_rotation_x( const double angle );
  void d3d_transform_add_rotation_y( const double angle );
  void d3d_transform_add_rotation_z( const double angle );
  void d3d_transform_add_rotation_axis( const double xa, const double ya, const double za,
                                        const double angle );
  void d3d_transform_stack_clear();
  bool d3d_transform_stack_empty();
  bool d3d_transform_stack_push();
  bool d3d_transform_stack_pop();
  bool d3d_transform_stack_top();
  bool d3d_transform_stack_discard();
  void d3d_set_fog( const bool enable, const int color, const double start, const double end );
  void d3d_set_lighting( const bool enable );
  void d3d_set_shading( const bool smooth );
  void d3d_light_define_direction( const int ind, const double dx, const double dy, 
                                   const double dz, const int col );
  void d3d_light_define_point( const int ind, const double x, const double y, const double z,
                               const double range, const int col );
  void d3d_light_enable( const int ind, const bool enable );
  void d3d_vertex_normal( const double x, const double y, const double z, const double nx, 
                          const double ny, const double nz );
  void d3d_vertex_normal_color( const double x, const double y, const double z, const double nx,
                                const double ny, const double nz, const int col,
                                const double alpha );
  void d3d_vertex_normal_texture( const double x, const double y, const double z,
                                  const double nx, const double ny, const double nz,
                                  const double xtex, const double ytex );
  void d3d_vertex_normal_texture_color( const double x, const double y, const double z,
                                        const double nx, const double ny, const double nz,
                                        const double xtex, const double ytex, const int col,
                                        const double alpha );
  int d3d_model_create();
  void d3d_model_destroy( const int ind );
  void d3d_model_clear( const int ind );
  void d3d_model_save( const int ind, const CGMVariable& fname );
  void d3d_model_load( const int ind, const CGMVariable& fname );
  void d3d_model_draw( const int ind, const double x, const double y, const double z, 
                       const int texid );
  void d3d_model_primitive_begin( const int ind, const int kind );
  void d3d_model_vertex( const int ind, const double x, const double y, const double z );
  void d3d_model_vertex_color( const int ind, const double x, const double y, const double z,
                               const int col, const double alpha );
  void d3d_model_vertex_texture( const int ind, const double x, const double y, const double z,
                                 const double xtex, const double ytex );
  void d3d_model_vertex_texture_color( const int ind, const double x, const double y, 
                                       const double z, const double xtex, const double ytex,
                                       const int col, const double alpha );
  void d3d_model_vertex_normal( const int ind, const double x, const double y, const double z,
                                const double nx, const double ny, const double nz );
  void d3d_model_vertex_normal_color( const int ind, const double x, const double y,
                                      const double z, const double nx, const double ny,
                                      const double nz, const int col, const double alpha );
  void d3d_model_vertex_normal_texture( const int ind, const double x, const double y, 
                                        const double z, const double nx, const double ny, 
                                        const double nz, const double xtex, const double ytex );
  void d3d_model_vertex_normal_texture_color( const int ind, const double x, const double y,
                                              const double z, const double nx, const double ny,
                                              const double nz, const double xtex,
                                              const double ytex, const int col, 
                                              const double alpha );
  void d3d_model_primitive_end( const int ind );
  void d3d_model_block( const int ind, const double x1, const double y1, const double z1,
                        const double x2, const double y2, const double z2, const double hrepeat, 
                        const double vrepeat );
  void d3d_model_cylinder( const int ind, const double x1, const double y1, const double z1,
                           const double x2, const double y2, const double z2, 
                           const double hrepeat, const double vrepeat, const bool closed, 
                           const int steps );
  void d3d_model_cone( const int ind, const double x1, const double y1, const double z1,
                       const double x2, const double y2, const double z2, const double hrepeat,
                       const double vrepeat, const bool closed, const int steps );
  void d3d_model_ellipsoid( const int ind, const double x1, const double y1, const double z1,
                            const double x2, const double y2, const double z2,
                            const double hrepeat, const double vrepeat, const int steps );
  void d3d_model_wall( const int ind, const double x1, const double y1, const double z1,
                       const double x2, const double y2, const double z2, const double hrepeat, const double vrepeat );
  void d3d_model_floor( const int ind, const double x1, const double y1, const double z1, 
                        const double x2, const double y2, const double z2, const double hrepeat,
                        const double vrepeat );

}