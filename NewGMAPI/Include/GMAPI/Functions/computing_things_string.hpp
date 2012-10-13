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
#ifndef GMAPI_FUNCTIONS_COMPUTING_THINGS_STRING_HPP
#define GMAPI_FUNCTIONS_COMPUTING_THINGS_STRING_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline String chr(Real val)
    {
        return call(functions[94], val);
    }
    
    inline String ansi_char(Real val)
    {
        return call(functions[95], val);
    }
    
    inline Real  ord(String str)
    {
        return call(functions[96], str);
    }
    
    inline Real  real(String str)
    {
        return call(functions[97], str);
    }
    
    inline String string(Real val)
    {
        return call(functions[98], val);
    }
    
    inline String string_format(Real val, Real tot, Real dec)
    {
        return call(functions[99], val, tot, dec);
    }
    
    inline Real string_length(String str)
    {
        return call(functions[100], str);
    }
    
    inline Real string_byte_length(String str)
    {
        return call(functions[101], str);
    }
    
    inline Real string_pos(String substr, String str)
    {
        return call(functions[102], substr, str);
    }
    
    inline String string_copy(String str, Real index, Real count)
    {
        return call(functions[103], str, index, count);
    }
    
    inline String string_char_at(String str, Real index)
    {
        return call(functions[104], str, index);
    }
    
    inline Real string_byte_at(String str, Real index)
    {
        return call(functions[105], str, index);
    }
    
    inline String string_delete(String str, Real index, Real count)
    {
        return call(functions[106], str, index, count);
    }
    
    inline String string_insert(String substr, String str, Real index)
    {
        return call(functions[107], substr, str, index);
    }
    
    inline String string_replace(String str, String substr, String newstr)
    {
        return call(functions[108], str, substr, newstr);
    }
    
    inline String string_replace_all(String str, String substr, String newstr)
    {
        return call(functions[109], str, substr, newstr);
    }
    
    inline Real string_count(String substr, String str)
    {
        return call(functions[110], substr, str);
    }
    
    inline String string_lower(String str)
    {
        return call(functions[111], str);
    }
    
    inline String string_upper(String str)
    {
        return call(functions[112], str);
    }
    
    inline String string_repeat(String str, Real count)
    {
        return call(functions[113], str, count);
    }
    
    inline String string_letters(String str)
    {
        return call(functions[114], str);
    }
    
    inline String string_digits(String str)
    {
        return call(functions[115], str);
    }
    
    inline String string_lettersdigits(String str)
    {
        return call(functions[116], str);
    }
    
    ///@}
}
#endif
