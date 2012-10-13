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

#include "Precompiled.hpp"
#include "Functions/dll.hpp"
//#include "D3d.hpp"
namespace gm
{
    //IDirect3DDevice8 *d3dDev = 0;
    bool initD3d()
    {/*
        //Locate some internal functions out of the variable_local_get code
        static const unsigned REF_START = 0x005FE1D0;
        static const unsigned REF_CALLREF2 = 0x005FE1DE + 1;
        static const unsigned REF_CALLREF2_START = 0x00566200;
        static const unsigned REF_CALLREF2_D3D = 0x0056625C + 1;

        static const unsigned char BEFORE_CALLREF2[] = {0xE8};
        static const unsigned  char AFTER_CALLREF2[]  = {0x5D,   0xC2, 0x0C, 0x00};
        static const size_t BEFORE_CALLREF2_LEN  = sizeof(BEFORE_CALLREF2);
        static const size_t AFTER_CALLREF2_LEN = sizeof(AFTER_CALLREF2);

        static const unsigned char BEFORE_CALLREF2_D3D[] = {0x50,   0x6A,0x03,   0x6A,0x00,   0x6A,0x00,   0xA1};
        static const unsigned  char AFTER_CALLREF2_D3D[]  = {0x8B,0x00,   0x50,   0x8B,0x00};
        static const size_t BEFORE_CALLREF2_D3D_LEN  = sizeof(BEFORE_CALLREF2_D3D);
        static const size_t AFTER_CALLREF2_D3D_LEN = sizeof(AFTER_CALLREF2_D3D);

        static const unsigned CALLREF2_OFFSET  = REF_CALLREF2 - REF_START;
        static const unsigned CALLREF2_D3D_OFFSET  = REF_CALLREF2_D3D - REF_CALLREF2_START;

        unsigned  char *p = (unsigned  char*)(unsigned)gm::get_function_address("draw_clear").real;

        if (memcmp(p+CALLREF2_OFFSET-BEFORE_CALLREF2_LEN, BEFORE_CALLREF2, BEFORE_CALLREF2_LEN) != 0)
            return false;
        if (memcmp(p+CALLREF2_OFFSET+4, AFTER_CALLREF2, AFTER_CALLREF2_LEN) != 0)
            return false;

        p = (unsigned  char*)(((int)p+CALLREF2_OFFSET +4) + *((int*)(p+CALLREF2_OFFSET)));

        if (memcmp(
            p+CALLREF2_D3D_OFFSET-BEFORE_CALLREF2_D3D_LEN,
            BEFORE_CALLREF2_D3D,
            BEFORE_CALLREF2_D3D_LEN) != 0)
            return false;
        if (memcmp(
            p+CALLREF2_D3D_OFFSET+4,
            AFTER_CALLREF2_D3D,
            AFTER_CALLREF2_D3D_LEN) != 0)
            return false;

        IDirect3DDevice8 ***pppD3dDev = *(IDirect3DDevice8****)(p + CALLREF2_D3D_OFFSET);
        d3dDev = **pppD3dDev;
        */
        return true;
    }
}

