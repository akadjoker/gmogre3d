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
#include "String.hpp"
#include "CoreInternal.hpp"
#include "BinSearch.hpp"
namespace gm
{
    const void *delphiNewUtf8     = 0;
    const void *delphiReleaseStr  = 0;
    const void *delphiStrAlloc    = 0;


    static const SearchByte DELPHI_NEWUTF8_PATTERN[] =
    {
        //Based on 0x407388 in GM 8.1.135
        {0x85,0},{0xC0,0},
        {0x7E,0},{0,1},
        {0x50,0},
        {0x83,0},{0xC0,0},{0x0E,0},
        {0x70,0},{0,1},
        {0x83,0},{0xE0,0}, {0xFE,0},
        {0x52,0},
        {0x50,0},
        {0xE8,0},{0,1},{0,1},{0,1},{0,1},
        {0x5A,0},
        {0x59,0},
        {0x66,0},{0xC7,0},{0x44,0},{0x02,0},{0xFE,0},{0x00,0},{0x00,0},
        {0x83,0},{0xC0,0},{0x0C,0},
        {0x5A,0},
        {0x89,0},{0x50,0},{0xFC,0},
        {0xC7,0},{0x40,0},{0xF8,0},{0x01,0},{0x00,0},{0x00,0},{0x00,0},
        {0x85,0},{0xC9,0},
        {0x75,0},{0,1},
        {0x8B,0},{0x0D},{0,1},{0,1},{0,1},{0,1},
        {0x89,0},{0xCA,0},
        {0x66,0},{0x89,0},{0x50,0},{0xF4,0},
        {0x66,0},{0xC7,0},{0x40,0},{0xF6,0},{0x01,0},{0x00,0},
        {0xC3,0},
        {0xE9,0},{0,1},{0,1},{0,1},{0,1},
        {0x31,0},{0xC0,0},
        {0xC3,0}
    };
    static const unsigned DELPHI_NEWUTF8_PATTERN_LEN = 
        sizeof(DELPHI_NEWUTF8_PATTERN) / sizeof(SearchByte);
    static const SearchByte DELPHI_RELEASESTR_PATTERN[] =
    {
        //Based on 0x004072D8 in GM 8.1.135
        {0x8B,0},{0x10,0},
        {0x85,0},{0xD2,0},
        {0x74,0},{0,1},
        {0xC7,0},{0x00,0},{0x00,0},{0x00,0},{0x00,0},{0x00,0},
        {0x8B,0},{0x4A,0},{0xF8,0},
        {0x49,0},
        {0x7C,0},{0,1},
        {0xF0,0},{0xFF,0},{0x4A,0},{0xF8,0},
        {0x75,0},{0,1},
        {0x50,0},
        {0x8D,0},{0x42,0},{0xF4,0},
        {0xE8,0},{0,1},{0,1},{0,1},{0,1},
        {0x58,0},
        {0xC3,0}
    };
    static const unsigned DELPHI_RELEASESTR_PATTERN_LEN = 
        sizeof(DELPHI_RELEASESTR_PATTERN) / sizeof(SearchByte);
    static const SearchByte DELPHI_ALLOCSTR_PATTERN[] =
    {
        //Based on 0x00404324 in GM 8.1.141
        {0x85,0},{0xC0,0},
        {0x7E,0},{0,1},
        {0xFF,0},{0,1},{0,1},{0,1},{0,1},{0,1},
        {0x85,0},{0xC0,0},
        {0x74,0},{0x02,0},
        {0xF3,0},{0xC3,0},
        {0xB0,0},{0x01,0},
        {0xE9,0},{0,1},{0,1},{0,1},{0,1},
        {0x31,0},{0xC0,0},
        {0xF3,0},{0xC3,0}
    };
    static const unsigned DELPHI_ALLOCSTR_PATTERN_LEN = 
        sizeof(DELPHI_ALLOCSTR_PATTERN) / sizeof(SearchByte);
    
    //Implemented in assembly
    //GMAPI_DLL char *newStr(unsigned len, unsigned short elementSize, unsigned short codePage)
    //GMAPI_DLL void releaseStr(char *gmstr)

    char *newStr(const void *str, unsigned len, unsigned short elementSize, unsigned short codePage)
    {
        char *out = newStr(len, elementSize, codePage);
        memcpy(out, str, len*elementSize);
        memset(out + len*elementSize, 0, 2);
        return out;
    }
    void strIncRef(const char *gmstr)
    {
        InterlockedIncrement((volatile long*)(gmstr - 8));
    }
    char *cpyStr(const void *vdelphiStr)
    {
        const char *delphiStr = (const char*)vdelphiStr;
        return newStr(
             (const void*)(delphiStr-0),
            *(unsigned*)(delphiStr-4),
            *(unsigned short*)(delphiStr-10),
            *(unsigned short*)(delphiStr-12));
    }
    bool initStrings()
    {
        delphiNewUtf8    = searchMemory(DELPHI_NEWUTF8_PATTERN, DELPHI_NEWUTF8_PATTERN_LEN);
        delphiReleaseStr = searchMemory(DELPHI_RELEASESTR_PATTERN, DELPHI_RELEASESTR_PATTERN_LEN);
        delphiStrAlloc   = searchMemory(DELPHI_ALLOCSTR_PATTERN, DELPHI_ALLOCSTR_PATTERN_LEN);
        return delphiNewUtf8 && delphiReleaseStr && delphiStrAlloc;
    }
}
