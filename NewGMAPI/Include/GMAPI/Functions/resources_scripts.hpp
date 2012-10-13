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
#ifndef GMAPI_FUNCTIONS_RESOURCES_SCRIPTS_HPP
#define GMAPI_FUNCTIONS_RESOURCES_SCRIPTS_HPP
#include "../Function.hpp"
#include "../Types.hpp"
namespace gm
{
    /**@addtogroup gm_functions*/
    ///@{
    inline Real script_exists(Real ind)
    {
        return call(functions[825], ind);
    }
    
    inline String script_get_name(Real ind)
    {
        return call(functions[826], ind);
    }
    
    inline String script_get_text(Real ind)
    {
        return call(functions[827], ind);
    }
    
    inline Value execute_string(unsigned argcnt, Value *args)
    {
        return docall(functions[828], argcnt, args);
    }
    inline Value execute_string(String str)
    {
        return call(functions[828], str);
    }
    inline Value execute_string(String str, Value v0)
    {
        return call(functions[828], str, v0);
    }
    inline Value execute_string(String str, Value v0, Value v1)
    {
        return call(functions[828], str, v0, v1);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2)
    {
        return call(functions[828], str, v0, v1, v2);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3)
    {
        return call(functions[828], str, v0, v1, v2, v3);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6, v7);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6, v7, v8);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    inline Value execute_string(String str, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14)
    {
        return call(functions[828], str, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
    

    inline Value execute_file(unsigned argcnt, Value *args)
    {
        return docall(functions[829], argcnt, args);
    }
    inline Value execute_file(String fname)
    {
        return call(functions[829], fname);
    }
    inline Value execute_file(String fname, Value v0)
    {
        return call(functions[829], fname, v0);
    }
    inline Value execute_file(String fname, Value v0, Value v1)
    {
        return call(functions[829], fname, v0, v1);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2)
    {
        return call(functions[829], fname, v0, v1, v2);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3)
    {
        return call(functions[829], fname, v0, v1, v2, v3);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6, v7);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6, v7, v8);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    inline Value execute_file(String fname, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14)
    {
        return call(functions[829], fname, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
    

    inline Value script_execute(unsigned argcnt, Value *args)
    {
        return docall(functions[830], argcnt, args);
    }
    inline Value script_execute(Real scr)
    {
        return call(functions[830], scr);
    }
    inline Value script_execute(Real scr, Value v0)
    {
        return call(functions[830], scr, v0);
    }
    inline Value script_execute(Real scr, Value v0, Value v1)
    {
        return call(functions[830], scr, v0, v1);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2)
    {
        return call(functions[830], scr, v0, v1, v2);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3)
    {
        return call(functions[830], scr, v0, v1, v2, v3);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6, v7);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6, v7, v8);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    inline Value script_execute(Real scr, Value v0, Value v1, Value v2, Value v3, Value v4, Value v5, Value v6, Value v7, Value v8, Value v9, Value v10, Value v11, Value v12, Value v13, Value v14)
    {
        return call(functions[830], scr, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
    
    ///@}
}
#endif
