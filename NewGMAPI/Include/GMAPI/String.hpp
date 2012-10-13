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
#ifndef GMAPI_STRING_HPP
#define GMAPI_STRING_HPP
#include "Dll.hpp"
#include <string>
#include <Windows.h>
namespace gm
{
    /**Allocate the delphi UnicodeString memory.*/
    GMAPI_DLL char *newStr(unsigned len, unsigned short elementSize=1, unsigned short codePage=65001);
    GMAPI_DLL char *newStr(const void *str, unsigned len, unsigned short elementSize=1, unsigned short codePage=65001);
    GMAPI_DLL char *cpyStr(const void *delphiStr);

    /**Decrements the string objects reference counter, destroying it if the
     * reference count reaches zero.
     */
    GMAPI_DLL void releaseStr(const char *delphiStr);
    /**Adds an extra reference to the string object.*/
    GMAPI_DLL void strIncRef(const char *delphiStr);

    /**@brief Limited functionality string so can restrict gm::value str to
     * UTF-8.
     */
    template<typename IMP>
    class DelphiBaseString
    {
    public:
        DelphiBaseString() : data(0) {}
        /**Need to handle at a higher level. Not implemented!*/
        DelphiBaseString(const DelphiBaseString& str){assert(0);}

        char *getData()const{return data;}
        bool isNull()const
        {
            return data == 0;
        }
        bool isUnique()const
        {
            return getRefCnt() == 1;
        }
        unsigned getLen()const
        {
            return *(unsigned*)(data-4);
        }
        long getRefCnt()const
        {
            return *(long*)(data-8);
        }
        unsigned short getElementSize()const
        {
            return *(unsigned short*)(data-10);
        }
        unsigned short getCodePage()const
        {
            return *(unsigned short*)(data-12);
        }
        

        operator std::string()const
        {
            if (isNull())
                return "";
            else if (getElementSize() == 1)
                return std::string(getData(), getLen());
            else
            {
                int len8 = WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)getData(),
                    getLen(), 0,0, NULL,NULL);
                std::string out(len8,0);
                WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)getData(),
                    getLen(), &out[0], len8, NULL,NULL);
                return out;
            }
        }
        operator std::wstring()const
        {
            if (isNull())
                return L"";
            else if (getElementSize() == 2)
                return std::wstring((const wchar_t*)getData(), getLen());
            else
            {
                int len16 = MultiByteToWideChar(CP_UTF8, 0, getData(), getLen(), 0, 0);
                std::wstring out(len16,0);
                MultiByteToWideChar(CP_UTF8, 0, getData(), getLen(), &out[0], len16);
                return out;
            }
        }
    protected:
        char *data;
    };
    /**@brief Limited functionality string so can restrict gm::value str to
     * UTF-8.
     */
    template<class IMP>
    class DelphiModifiableString : public DelphiBaseString<IMP>
    {
    public:
        DelphiModifiableString(){}
        DelphiModifiableString(const DelphiModifiableString &str): DelphiBaseString() {((IMP*)this)->set(str);}
        template<class IMP2> DelphiModifiableString(const DelphiBaseString<IMP2> &str): DelphiBaseString() {((IMP*)this)->set(str);}

        void setNull()
        {
            ((IMP*)this)->release(data);
            data = 0;
        }

//         void set(const char *utf8){utf8 ? ((IMP*)this)->set(utf8, strlen(utf8)) : setNull();}
//         void set(const wchar_t *utf16){utf16 ? ((IMP*)this)->set(utf16, wcslen(utf16)) : setNull();}
//         void set(const std::string &utf8){((IMP*)this)->set(utf8.data(), utf8.size());}
//         void set(const std::wstring &utf16){((IMP*)this)->set(utf16.data(), utf16.size());}

        void setUtf8(const char *utf8){utf8 ? setUtf8(utf8, strlen(utf8)) : setNull();}
        void setUtf8(const wchar_t *utf16){utf16 ? setUtf8(utf16, wcslen(utf16)) : setNull();}
        void setUtf8(const std::string &utf8){setUtf8(utf8.data(), utf8.size());}
        void setUtf8(const std::wstring &utf16){setUtf8(utf16.data(), utf16.size());}
        void setUtf8(const char *utf8, unsigned len)
        {
            ((IMP*)this)->release(data);
            data = utf8 ? newStr(utf8, len, 1, 65001) : 0;
        }
        void setUtf8(const wchar_t *utf16, unsigned len)
        {
            ((IMP*)this)->release(data);
            if (utf16)
            {
                int len8 = WideCharToMultiByte(CP_UTF8, 0, utf16, len,
                    0,0, NULL,NULL);
                data = newStr(len8,1,65001);
                WideCharToMultiByte(CP_UTF8, 0, utf16, len,
                    data,len8, NULL,NULL);
                data[len8] = 0;
            }
            else data = 0;
        }
        template<class IMP2>
        void setUtf8(const DelphiBaseString<IMP2> &str)
        {
            if (str.isNull()) setNull();
            else if (str.getCodePage() == 65001)
            {
                strIncRef(str.getData());
                ((IMP*)this)->release(data);
                data = str.getData();
            }
            else setUtf8((const wchar_t*)str.getData(), str.getLen());//convert
        }

        DelphiBaseString& operator = (const DelphiBaseString &str) { ((IMP*)this)->set(str); return *this; }
        template<class IMP2>
        DelphiBaseString& operator = (const DelphiBaseString<IMP2> &str) { ((IMP*)this)->set(str); return *this; }
        DelphiBaseString& operator = (const char *utf8) { ((IMP*)this)->set(utf8); return *this; }
        DelphiBaseString& operator = (const wchar_t *utf16) { ((IMP*)this)->set(utf16); return *this; }
        DelphiBaseString& operator = (const std::string &utf8) { ((IMP*)this)->set(utf8); return *this; }
        DelphiBaseString& operator = (const std::wstring &utf16) { ((IMP*)this)->set(utf16); return *this; }
    protected:
        void release()
        {
            releaseStr(data);
            data = 0;
        }
        void release(char *data)
        {
           releaseStr(data);
        }
    };
    /**@brief References a string, but does not own it.*/
    class RefString : public DelphiBaseString<RefString>
    {
    public:
        RefString(){}
        template<class IMP2>
        RefString(const DelphiBaseString<IMP2> &str){data=str.data;}
        RefString(const void *delphiStr){data = (char*)delphiStr;}
    };
    /**@brief Less complete than DelphiString, used as the string member in
     * gm::Value.
     * 
     * Comparison to DelphiString:
     * - Can only hold UTF-8 data.
     * - Has no utf8/utf16 factory methods. Constructors act as the utf8 ones.
     * - Has no setUtf16 methods, and the set methods map to the setUtf8 ones.
     */
    class ValueString : public DelphiModifiableString<ValueString>
    {
    public:
        ValueString(){}
        ValueString(const ValueString &str):DelphiModifiableString(str){}
        template<class IMP2> ValueString(const DelphiBaseString<IMP2> &str):DelphiModifiableString(str){}
        ValueString(const char *utf8) {set(utf8);}
        ValueString(const wchar_t *utf16) {set(utf16);}
        ValueString(const char *utf8, unsigned len) {set(utf8, len);}
        ValueString(const wchar_t *utf16, unsigned len) {set(utf16, len);}
        ValueString(const std::string &utf8) {set(utf8);}
        ValueString(const std::wstring &utf16) {set(utf16);}
        ValueString(const void *delphiString, bool takeOwnership)
        {
            RefString ref = delphiString;
            if (ref.getCodePage() == 65001)
            {
                data = (char*)delphiString;
                if (!takeOwnership)
                    strIncRef(data);
            }
            else
            {
                set(ref);
                if (takeOwnership)
                    releaseStr((const char*)delphiString);
            }
        }
        ~ValueString()
        {
            releaseStr(data);
        }

        void set(const char *utf8){utf8 ? set(utf8, strlen(utf8)) : setNull();}
        void set(const wchar_t *utf16){utf16 ? set(utf16, wcslen(utf16)) : setNull();}
        void set(const std::string &utf8){set(utf8.data(), utf8.size());}
        void set(const std::wstring &utf16){set(utf16.data(), utf16.size());}

        void set(const char *utf8, unsigned len){setUtf8(utf8,len);}
        void set(const wchar_t *utf16, unsigned len){setUtf8(utf16,len);}

        template<class IMP2> void set(const DelphiBaseString<IMP2> &str){setUtf8(str);}
    };
    /**@brief Basically works as a wrapper/smart pointer for delphi
     * UnicodeString objects with support for easy handling of UTF-16.
     */
    class GMAPI_DLL DelphiString : public DelphiModifiableString<DelphiString>
    {
    public:
        DelphiString(){}
        DelphiString(const DelphiString &str):DelphiModifiableString(str){}
        template<class IMP2> DelphiString(const DelphiBaseString<IMP2> &str):DelphiModifiableString(str){}
        DelphiString(void *str, unsigned len, unsigned short elemSize, unsigned short codePage)
        {
            set(str, len, elemSize, codePage);
        }
        DelphiString(const char *utf8) {set(utf8);}
        DelphiString(const wchar_t *utf16) {set(utf16);}
        DelphiString(const char *utf8, unsigned len) {set(utf8, len);}
        DelphiString(const wchar_t *utf16, unsigned len) {set(utf16, len);}
        DelphiString(const std::string &utf8) {set(utf8);}
        DelphiString(const std::wstring &utf16) {set(utf16);}
        DelphiString(const void *delphiString, bool takeOwnership)
        {
            data = (char*)delphiString;
            if (!takeOwnership) strIncRef(data);
        }
        ~DelphiString()
        {
            releaseStr(data);
        }

        static DelphiString utf8(const DelphiString &str) {DelphiString d; d.setUtf8(str); return d;}
        static DelphiString utf8(const char *utf8) {DelphiString d; d.setUtf8(utf8); return d;}
        static DelphiString utf8(const wchar_t *utf16) {DelphiString d; d.setUtf8(utf16); return d;}
        static DelphiString utf8(const std::string &utf8) {DelphiString d; d.setUtf8(utf8); return d;}
        static DelphiString utf8(const std::wstring &utf16) {DelphiString d; d.setUtf8(utf16); return d;}

        static DelphiString utf16(const DelphiString &str) {DelphiString d; d.setUtf16(str); return d;}
        static DelphiString utf16(const char *utf8) {DelphiString d; d.setUtf16(utf8); return d;}
        static DelphiString utf16(const wchar_t *utf16) {DelphiString d; d.setUtf16(utf16); return d;}
        static DelphiString utf16(const std::string &utf8) {DelphiString d; d.setUtf16(utf8); return d;}
        static DelphiString utf16(const std::wstring &utf16) {DelphiString d; d.setUtf16(utf16); return d;}

        
        void setUtf16(const char *utf8){utf8 ? setUtf16(utf8, strlen(utf8)) : setNull();}
        void setUtf16(const wchar_t *utf16){utf16 ? setUtf16(utf16, wcslen(utf16)) : setNull();}
        void setUtf16(const std::string &utf8){setUtf16(utf8.data(), utf8.size());}
        void setUtf16(const std::wstring &utf16){setUtf16(utf16.data(), utf16.size());}

        void set(const char *utf8){utf8 ? set(utf8, strlen(utf8)) : setNull();}
        void set(const wchar_t *utf16){utf16 ? set(utf16, wcslen(utf16)) : setNull();}
        void set(const std::string &utf8){set(utf8.data(), utf8.size());}
        void set(const std::wstring &utf16){set(utf16.data(), utf16.size());}

        void set(const char *utf8, unsigned len){setUtf8(utf8,len);}
        void set(const wchar_t *utf16, unsigned len)
        {
            releaseStr(data);
            data = utf16 ? newStr(utf16, len, 2, 1200) : 0;
        }
        void set(const void *str, unsigned len,
            unsigned short elemSize, unsigned short codePage)
        {
            releaseStr(data);
            data = newStr(str, len, elemSize, codePage);
        }

        void setUtf16(const char *utf8, unsigned len)
        {
            releaseStr(data);
            if (utf8)
            {
                int len16 = MultiByteToWideChar(
                    CP_UTF8, 0, utf8, len,
                    0, 0);
                data = newStr(len16, 2, 1200);
                MultiByteToWideChar(
                    CP_UTF8, 0, utf8, len,
                    (wchar_t*)data, len16);
                ((wchar_t*)data)[len16] = 0;
            }
            else data = 0;
        }
        void setUtf16(const wchar_t *utf16, unsigned len)
        {
            releaseStr(data);
            data = utf16 ? newStr(utf16, len, 2, 1200) : 0;
        }


        template<class IMP2> void set(const DelphiBaseString<IMP2> &str)
        {
            if (str.isNull()) setNull();
            else
            {
                strIncRef(str.getData());
                releaseStr(data);
                data = str.getData();
            }
        }
        template<class IMP2> void setUtf16(const DelphiBaseString<IMP2> &str)
        {
            if (str.isNull()) setNull();
            else if (str.getCodePage() == 1200)
            {
                strIncRef(str.getData());
                releaseStr(data);
                data = str.getData();
            }
            else setUtf16(str.getData(), str.getLen());
        }

        
        /**Perform a deep copy.*/
        DelphiString clone()const
        {
            return DelphiString(data, getLen(), getElementSize(), getCodePage());
        }
        
    };
}
#endif
