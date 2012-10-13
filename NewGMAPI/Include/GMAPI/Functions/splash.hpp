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
#ifndef GMAPI_FUNCTIONS_SPLASH_HPP
#define GMAPI_FUNCTIONS_SPLASH_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void splash_show_video(String fname, Real loop)
    {
        call(functions[917], fname, loop);
    }
    
    inline void splash_show_text(String fname, Real delay)
    {
        call(functions[918], fname, delay);
    }
    
    inline void splash_show_image(String fname, Real delay)
    {
        call(functions[919], fname, delay);
    }
    
    inline void splash_show_web(String url, Real delay)
    {
        call(functions[920], url, delay);
    }
    
    inline void splash_set_main(Real main)
    {
        call(functions[921], main);
    }
    
    inline void splash_set_scale(Real scale)
    {
        call(functions[922], scale);
    }
    
    inline void splash_set_cursor(Real vis)
    {
        call(functions[923], vis);
    }
    
    inline void splash_set_color(Real col)
    {
        call(functions[924], col);
    }
    
    inline void splash_set_caption(String cap)
    {
        call(functions[925], cap);
    }
    
    inline void splash_set_fullscreen(Real full)
    {
        call(functions[926], full);
    }
    
    inline void splash_set_border(Real border)
    {
        call(functions[927], border);
    }
    
    inline void splash_set_size(Real w, Real h)
    {
        call(functions[928], w, h);
    }
    
    inline void splash_set_position(Real x, Real y)
    {
        call(functions[929], x, y);
    }
    
    inline void splash_set_adapt(Real adapt)
    {
        call(functions[930], adapt);
    }
    
    inline void splash_set_top(Real top)
    {
        call(functions[931], top);
    }
    
    inline void splash_set_interrupt(Real interrupt)
    {
        call(functions[932], interrupt);
    }
    
    inline void splash_set_stop_key(Real stop)
    {
        call(functions[933], stop);
    }
    
    inline void splash_set_stop_mouse(Real stop)
    {
        call(functions[934], stop);
    }
    
    inline void splash_set_close_button(Real show)
    {
        call(functions[935], show);
    }
    
    inline void show_info()
    {
        call(functions[936]);
    }
    
    inline void load_info(String fname)
    {
        call(functions[937], fname);
    }
    
    ///@}
}
#endif
