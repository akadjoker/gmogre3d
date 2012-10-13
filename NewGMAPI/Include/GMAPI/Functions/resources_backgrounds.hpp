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
#ifndef GMAPI_FUNCTIONS_RESOURCES_BACKGROUNDS_HPP
#define GMAPI_FUNCTIONS_RESOURCES_BACKGROUNDS_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real background_exists(Real ind)
    {
        return call(functions[724], ind);
    }
    
    inline String background_get_name(Real ind)
    {
        return call(functions[725], ind);
    }
    
    inline Real background_get_width(Real ind)
    {
        return call(functions[726], ind);
    }
    
    inline Real background_get_height(Real ind)
    {
        return call(functions[727], ind);
    }
    
    inline void background_save(Real ind, String fname)
    {
        call(functions[728], ind, fname);
    }
    
    inline Real background_duplicate(Real ind)
    {
        return call(functions[729], ind);
    }
    
    inline void background_assign(Real ind, Real back)
    {
        call(functions[730], ind, back);
    }
    
    inline Real background_add(String fname, Real removeback, Real smooth)
    {
        return call(functions[731], fname, removeback, smooth);
    }
    
    inline void background_replace(Real ind, String fname, Real removeback, Real smooth)
    {
        call(functions[732], ind, fname, removeback, smooth);
    }
    
    inline Real background_add_background(String fname)
    {
        return call(functions[733], fname);
    }
    
    inline void background_replace_background(Real ind, String fname)
    {
        call(functions[734], ind, fname);
    }
    
    inline Real background_create_color(Real w, Real h, Real col)
    {
        return call(functions[735], w, h, col);
    }
    
    inline Real background_create_gradient(Real w, Real h, Real col1, Real col2, Real kind)
    {
        return call(functions[736], w, h, col1, col2, kind);
    }
    
    inline Real background_create_from_screen(Real x, Real y, Real w, Real h, Real removeback, Real smooth)
    {
        return call(functions[737], x, y, w, h, removeback, smooth);
    }
    
    inline Real background_create_from_surface(Real id, Real x, Real y, Real w, Real h, Real removeback, Real smooth)
    {
        return call(functions[738], id, x, y, w, h, removeback, smooth);
    }
    
    inline void background_delete(Real ind)
    {
        call(functions[739], ind);
    }
    
    inline void background_set_alpha_from_background(Real ind, Real back)
    {
        call(functions[740], ind, back);
    }
    
    ///@}
}
#endif
