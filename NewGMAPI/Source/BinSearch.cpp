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
#include "BinSearch.hpp"

namespace gm
{
    bool matchByte(const SearchByte *search, unsigned char byte);
    bool checkMatch(const SearchByte *search, unsigned len, const unsigned char *mem);
    const void *searchMemoryRange(const SearchByte *search, unsigned len, const unsigned char *beg, const unsigned char *end);
    const void *searchMemory(const SearchByte *search, unsigned len)
    {
        void *p = 0x00000000;
        MEMORY_BASIC_INFORMATION info;
        while(VirtualQueryEx(
            GetCurrentProcess(),
            p,
            &info,
            sizeof(info)))
        {
            if(info.State == MEM_COMMIT && (info.Protect & PAGE_GUARD) == 0)
            {
                const void *found = searchMemoryRange(
                    search, len,
                    (unsigned char *)info.BaseAddress, (unsigned char *)info.BaseAddress + info.RegionSize);
                if(found)
                    return found;
            }
            p = (unsigned char *)info.BaseAddress + info.RegionSize;
        }
        return 0;
    }
    const void *searchMemoryRange(const SearchByte *search, unsigned len, const unsigned char *beg, const unsigned char *end)
    {

        for(; beg < end - len; ++beg)
        {
            if(checkMatch(search, len, beg))
            {
                return beg;
            }
        }
        return 0;
    }
    bool matchByte(const SearchByte *search, unsigned char byte)
    {
        return search->wild || search->byte == byte;
    }
    bool checkMatch(const SearchByte *search, unsigned len, const unsigned char *mem)
    {
        for(unsigned i = 0; i < len; ++search, ++mem, ++i)
        {
            if(!matchByte(search, *mem))
            {
                return false;
            }
        }
        return true;
    }
}
