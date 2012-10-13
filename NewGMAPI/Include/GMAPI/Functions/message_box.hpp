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
#ifndef GMAPI_FUNCTIONS_MESSAGE_BOX_HPP
#define GMAPI_FUNCTIONS_MESSAGE_BOX_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline void show_message(String str)
    {
        call(functions[619], str);
    }
    
    inline Real show_message_ext(String str, String but1, String but2, String but3)
    {
        return call(functions[620], str, but1, but2, but3);
    }
    
    inline Real show_question(String str)
    {
        return call(functions[621], str);
    }
    
    inline Real get_integer(String str, Real def)
    {
        return call(functions[622], str, def);
    }
    
    inline String get_string(String str, String def)
    {
        return call(functions[623], str, def);
    }
    
    inline void message_background(Real back)
    {
        call(functions[624], back);
    }
    
    inline void message_alpha(Real alpha)
    {
        call(functions[625], alpha);
    }
    
    inline void message_button(Real spr)
    {
        call(functions[626], spr);
    }
    
    inline void message_text_font(String name, Real size, Real color, Real style)
    {
        call(functions[627], name, size, color, style);
    }
    
    inline void message_button_font(String name, Real size, Real color, Real style)
    {
        call(functions[628], name, size, color, style);
    }
    
    inline void message_input_font(String name, Real size, Real color, Real style)
    {
        call(functions[629], name, size, color, style);
    }
    
    inline void message_text_charset(Real type, Real charset)
    {
        call(functions[630], type, charset);
    }
    
    inline void message_mouse_color(Real col)
    {
        call(functions[631], col);
    }
    
    inline void message_input_color(Real col)
    {
        call(functions[632], col);
    }
    
    inline void message_caption(Real show, String str)
    {
        call(functions[633], show, str);
    }
    
    inline void message_position(Real x, Real y)
    {
        call(functions[634], x, y);
    }
    
    inline void message_size(Real w, Real h)
    {
        call(functions[635], w, h);
    }
    
    inline Value show_menu(String str, Value def)
    {
        return call(functions[636], str, def);
    }
    
    inline Value show_menu_pos(Real x, Real y, String str, Value def)
    {
        return call(functions[637], x, y, str, def);
    }
    
    inline Real get_color(Real defcol)
    {
        return call(functions[638], defcol);
    }
    
    inline String get_open_filename(String filter, String fname)
    {
        return call(functions[639], filter, fname);
    }
    
    inline String get_save_filename(String filter, String fname)
    {
        return call(functions[640], filter, fname);
    }
    
    inline String get_directory(String dname)
    {
        return call(functions[641], dname);
    }
    
    inline String get_directory_alt(String capt, String root)
    {
        return call(functions[642], capt, root);
    }
    
    inline void show_error(String str, String abort)
    {
        call(functions[643], str, abort);
    }
    
    ///@}
}
#endif
