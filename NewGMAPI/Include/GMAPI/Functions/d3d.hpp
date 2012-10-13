/* Copyright (c) 2011-2012 William Newbery
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
 */
//Auto-Generated File
#ifndef GMAPI_FUNCTIONS_D3D_HPP
#define GMAPI_FUNCTIONS_D3D_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real d3d_start()
    {
        return call(functions[117]);
    }
    
    inline Real d3d_end()
    {
        return call(functions[118]);
    }
    
    inline void d3d_set_hidden(Real enable)
    {
        call(functions[119], enable);
    }
    
    inline void d3d_set_perspective(Real enable)
    {
        call(functions[120], enable);
    }
    
    inline void d3d_set_depth(Real depth)
    {
        call(functions[121], depth);
    }
    
    inline void d3d_primitive_begin(Real kind)
    {
        call(functions[122], kind);
    }
    
    inline void d3d_vertex(Real x, Real y, Real z)
    {
        call(functions[123], x, y, z);
    }
    
    inline void d3d_vertex_color(Real x, Real y, Real z, Real col, Real alpha)
    {
        call(functions[124], x, y, z, col, alpha);
    }
    
    inline void d3d_primitive_end()
    {
        call(functions[125]);
    }
    
    inline void d3d_primitive_begin_texture(Real kind, Real texid)
    {
        call(functions[126], kind, texid);
    }
    
    inline void d3d_vertex_texture(Real x, Real y, Real z, Real xtex, Real ytex)
    {
        call(functions[127], x, y, z, xtex, ytex);
    }
    
    inline void d3d_vertex_texture_color(Real x, Real y, Real z, Real xtex, Real ytex, Real col, Real alpha)
    {
        call(functions[128], x, y, z, xtex, ytex, col, alpha);
    }
    
    inline void d3d_set_culling(Real cull)
    {
        call(functions[129], cull);
    }
    
    inline void d3d_draw_block(Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real texid, Real hrepeat, Real vrepeat)
    {
        call(functions[130], x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
    }
    
    inline void d3d_draw_cylinder(Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real texid, Real hrepeat, Real vrepeat, Real closed, Real steps)
    {
        call(functions[131], x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps);
    }
    
    inline void d3d_draw_cone(Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real texid, Real hrepeat, Real vrepeat, Real closed, Real steps)
    {
        call(functions[132], x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, closed, steps);
    }
    
    inline void d3d_draw_ellipsoid(Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real texid, Real hrepeat, Real vrepeat, Real steps)
    {
        call(functions[133], x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat, steps);
    }
    
    inline void d3d_draw_wall(Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real texid, Real hrepeat, Real vrepeat)
    {
        call(functions[134], x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
    }
    
    inline void d3d_draw_floor(Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real texid, Real hrepeat, Real vrepeat)
    {
        call(functions[135], x1, y1, z1, x2, y2, z2, texid, hrepeat, vrepeat);
    }
    
    inline void d3d_set_projection(Real xfrom, Real yfrom, Real zfrom, Real xto, Real yto, Real zto, Real xup, Real yup, Real zup)
    {
        call(functions[136], xfrom, yfrom, zfrom, xto, yto, zto, xup, yup, zup);
    }
    
    inline void d3d_set_projection_ext(Real xfrom, Real yfrom, Real zfrom, Real xto, Real yto, Real zto, Real xup, Real yup, Real zup, Real angle, Real aspect, Real znear, Real zfar)
    {
        call(functions[137], xfrom, yfrom, zfrom, xto, yto, zto, xup, yup, zup, angle, aspect, znear, zfar);
    }
    
    inline void d3d_set_projection_ortho(Real x, Real y, Real w, Real h, Real angle)
    {
        call(functions[138], x, y, w, h, angle);
    }
    
    inline void d3d_set_projection_perspective(Real x, Real y, Real w, Real h, Real angle)
    {
        call(functions[139], x, y, w, h, angle);
    }
    
    inline void d3d_transform_set_identity()
    {
        call(functions[140]);
    }
    
    inline void d3d_transform_set_translation(Real xt, Real yt, Real zt)
    {
        call(functions[141], xt, yt, zt);
    }
    
    inline void d3d_transform_set_scaling(Real xs, Real ys, Real zs)
    {
        call(functions[142], xs, ys, zs);
    }
    
    inline void d3d_transform_set_rotation_x(Real angle)
    {
        call(functions[143], angle);
    }
    
    inline void d3d_transform_set_rotation_y(Real angle)
    {
        call(functions[144], angle);
    }
    
    inline void d3d_transform_set_rotation_z(Real angle)
    {
        call(functions[145], angle);
    }
    
    inline void d3d_transform_set_rotation_axis(Real xa, Real ya, Real za, Real angle)
    {
        call(functions[146], xa, ya, za, angle);
    }
    
    inline void d3d_transform_add_translation(Real xt, Real yt, Real zt)
    {
        call(functions[147], xt, yt, zt);
    }
    
    inline void d3d_transform_add_scaling(Real xs, Real ys, Real zs)
    {
        call(functions[148], xs, ys, zs);
    }
    
    inline void d3d_transform_add_rotation_x(Real angle)
    {
        call(functions[149], angle);
    }
    
    inline void d3d_transform_add_rotation_y(Real angle)
    {
        call(functions[150], angle);
    }
    
    inline void d3d_transform_add_rotation_z(Real angle)
    {
        call(functions[151], angle);
    }
    
    inline void d3d_transform_add_rotation_axis(Real xa, Real ya, Real za, Real angle)
    {
        call(functions[152], xa, ya, za, angle);
    }
    
    inline void d3d_transform_stack_clear()
    {
        call(functions[153]);
    }
    
    inline Real d3d_transform_stack_empty()
    {
        return call(functions[154]);
    }
    
    inline Real d3d_transform_stack_push()
    {
        return call(functions[155]);
    }
    
    inline Real d3d_transform_stack_pop()
    {
        return call(functions[156]);
    }
    
    inline Real d3d_transform_stack_top()
    {
        return call(functions[157]);
    }
    
    inline Real d3d_transform_stack_discard()
    {
        return call(functions[158]);
    }
    
    inline void d3d_set_fog(Real enable, Real color, Real start, Real end)
    {
        call(functions[159], enable, color, start, end);
    }
    
    inline void d3d_set_lighting(Real enable)
    {
        call(functions[160], enable);
    }
    
    inline void d3d_set_shading(Real smooth)
    {
        call(functions[161], smooth);
    }
    
    inline void d3d_light_define_direction(Real ind, Real dx, Real dy, Real dz, Real col)
    {
        call(functions[162], ind, dx, dy, dz, col);
    }
    
    inline void d3d_light_define_point(Real ind, Real x, Real y, Real z, Real range, Real col)
    {
        call(functions[163], ind, x, y, z, range, col);
    }
    
    inline void d3d_light_enable(Real ind, Real enable)
    {
        call(functions[164], ind, enable);
    }
    
    inline void d3d_vertex_normal(Real x, Real y, Real z, Real nx, Real ny, Real nz)
    {
        call(functions[165], x, y, z, nx, ny, nz);
    }
    
    inline void d3d_vertex_normal_color(Real x, Real y, Real z, Real nx, Real ny, Real nz, Real col, Real alpha)
    {
        call(functions[166], x, y, z, nx, ny, nz, col, alpha);
    }
    
    inline void d3d_vertex_normal_texture(Real x, Real y, Real z, Real nx, Real ny, Real nz, Real xtex, Real ytex)
    {
        call(functions[167], x, y, z, nx, ny, nz, xtex, ytex);
    }
    
    inline void d3d_vertex_normal_texture_color(Real x, Real y, Real z, Real nx, Real ny, Real nz, Real xtex, Real ytex, Real col, Real alpha)
    {
        call(functions[168], x, y, z, nx, ny, nz, xtex, ytex, col, alpha);
    }
    
    inline Real d3d_model_create()
    {
        return call(functions[169]);
    }
    
    inline void d3d_model_destroy(Real ind)
    {
        call(functions[170], ind);
    }
    
    inline void d3d_model_clear(Real ind)
    {
        call(functions[171], ind);
    }
    
    inline void d3d_model_save(Real ind, Real fname)
    {
        call(functions[172], ind, fname);
    }
    
    inline void d3d_model_load(Real ind, Real fname)
    {
        call(functions[173], ind, fname);
    }
    
    inline void d3d_model_draw(Real ind, Real x, Real y, Real z, Real texid)
    {
        call(functions[174], ind, x, y, z, texid);
    }
    
    inline void d3d_model_primitive_begin(Real ind, Real kind)
    {
        call(functions[175], ind, kind);
    }
    
    inline void d3d_model_vertex(Real ind, Real x, Real y, Real z)
    {
        call(functions[176], ind, x, y, z);
    }
    
    inline void d3d_model_vertex_color(Real ind, Real x, Real y, Real z, Real col, Real alpha)
    {
        call(functions[177], ind, x, y, z, col, alpha);
    }
    
    inline void d3d_model_vertex_texture(Real ind, Real x, Real y, Real z, Real xtex, Real ytex)
    {
        call(functions[178], ind, x, y, z, xtex, ytex);
    }
    
    inline void d3d_model_vertex_texture_color(Real ind, Real x, Real y, Real z, Real xtex, Real ytex, Real col, Real alpha)
    {
        call(functions[179], ind, x, y, z, xtex, ytex, col, alpha);
    }
    
    inline void d3d_model_vertex_normal(Real ind, Real x, Real y, Real z, Real nx, Real ny, Real nz)
    {
        call(functions[180], ind, x, y, z, nx, ny, nz);
    }
    
    inline void d3d_model_vertex_normal_color(Real ind, Real x, Real y, Real z, Real nx, Real ny, Real nz, Real col, Real alpha)
    {
        call(functions[181], ind, x, y, z, nx, ny, nz, col, alpha);
    }
    
    inline void d3d_model_vertex_normal_texture(Real ind, Real x, Real y, Real z, Real nx, Real ny, Real nz, Real xtex, Real ytex)
    {
        call(functions[182], ind, x, y, z, nx, ny, nz, xtex, ytex);
    }
    
    inline void d3d_model_vertex_normal_texture_color(Real ind, Real x, Real y, Real z, Real nx, Real ny, Real nz, Real xtex, Real ytex, Real col, Real alpha)
    {
        call(functions[183], ind, x, y, z, nx, ny, nz, xtex, ytex, col, alpha);
    }
    
    inline void d3d_model_primitive_end(Real ind)
    {
        call(functions[184], ind);
    }
    
    inline void d3d_model_block(Real ind, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real hrepeat, Real vrepeat)
    {
        call(functions[185], ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat);
    }
    
    inline void d3d_model_cylinder(Real ind, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real hrepeat, Real vrepeat, Real closed, Real steps)
    {
        call(functions[186], ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, closed, steps);
    }
    
    inline void d3d_model_cone(Real ind, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real hrepeat, Real vrepeat, Real closed, Real steps)
    {
        call(functions[187], ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, closed, steps);
    }
    
    inline void d3d_model_ellipsoid(Real ind, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real hrepeat, Real vrepeat, Real steps)
    {
        call(functions[188], ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat, steps);
    }
    
    inline void d3d_model_wall(Real ind, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real hrepeat, Real vrepeat)
    {
        call(functions[189], ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat);
    }
    
    inline void d3d_model_floor(Real ind, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2, Real hrepeat, Real vrepeat)
    {
        call(functions[190], ind, x1, y1, z1, x2, y2, z2, hrepeat, vrepeat);
    }
    
    ///@}
}
#endif
