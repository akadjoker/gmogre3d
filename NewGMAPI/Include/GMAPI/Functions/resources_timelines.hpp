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
#ifndef GMAPI_FUNCTIONS_RESOURCES_TIMELINES_HPP
#define GMAPI_FUNCTIONS_RESOURCES_TIMELINES_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real timeline_exists(Real ind)
    {
        return call(functions[868], ind);
    }
    
    inline String timeline_get_name(Real ind)
    {
        return call(functions[869], ind);
    }
    
    inline Real timeline_add()
    {
        return call(functions[870]);
    }
    
    inline void timeline_delete(Real ind)
    {
        call(functions[871], ind);
    }
    
    inline void timeline_clear(Real ind)
    {
        call(functions[872], ind);
    }
    
    inline void timeline_moment_add(Real ind, Real step, String codestr)
    {
        call(functions[873], ind, step, codestr);
    }
    
    inline void timeline_moment_clear(Real ind, Real step)
    {
        call(functions[874], ind, step);
    }
    
    ///@}
}
#endif
