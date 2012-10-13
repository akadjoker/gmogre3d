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
#ifndef GMAPI_VALUE_HPP
#define GMAPI_VALUE_HPP
#include "String.hpp"
#include <cassert>
namespace gm
{
    /**@defgroup gm_variables GM Variables & Values
     * @brief Objects and methods for working with GM variables and rvalues.
     */
    ///@{
    /**@brief A dynamically typed GM value.
     * 
     * The type member indicates if this value is a string or a real.
     */
    class Value
    {
    public:
        friend void swap(Value &a, Value &v);
        /**Indicates if the value currently represents a real (double) or a
         * string.
         */
        enum Type
        {
            REAL   = 0,
            STRING = 1
        };
        /**Default constructor. Sets the value to a real with value 0.0.*/
        Value():type(REAL), real(0), str(){}
        /**Constructs a real value.*/
        Value(double real):type(REAL), real(real), str(){}
        Value(int real):type(REAL), real(real), str(){}
        /**Constructs a string value using a copy of str.*/
        Value(const char *str):type(STRING), real(0), str(str) {}
        Value(const char *str, unsigned len):type(STRING), real(0), str(str, len) {}
        Value(const std::string &str):type(STRING), real(0), str(str.data(), str.size()) {}
        Value(const wchar_t *str):type(STRING), real(0), str(str) {}
        Value(const wchar_t *str, unsigned len):type(STRING), real(0), str(str, len) {}
        Value(const std::wstring &str):type(STRING), real(0), str(str.data(), str.size()) {}

        template<class IMP>
        Value(const DelphiBaseString<IMP> &str):type(str.isNull() ? REAL : STRING), real(0), str(str) {}

        /**Constructs the value as a copy of v.*/
        Value(const Value &v)
        :type(v.type), real(v.real), str(v.str)
        {
        }
        ~Value()
        {
        }
        
        void setReal(double r)
        {
            type = REAL;
            real = r;
            str.setNull();
        }
        void setStr(const char *newstr)
        {
            type = STRING;
            str.set(newstr);
        }
        void setStr(const wchar_t *newstr)
        {
            type = STRING;
            str.set(newstr);
        }
        void setStr(const char *newstr, unsigned len)
        {
            type = STRING;
            str.set(newstr, len);
        }
        void setStr(const wchar_t *newstr, unsigned len)
        {
            type = STRING;
            str.set(newstr, len);
        }
        void setStr(const std::string& newstr)
        {
            type = STRING;
            str.set(newstr);
        }
        void setStr(const std::wstring& newstr)
        {
            type = STRING;
            str.set(newstr);
        }
        template<class IMP>
        void setStr(const DelphiBaseString<IMP> &newstr)
        {
            str.set(newstr);
        }
        
        void set(const Value &v)
        {
            v.type == REAL ? setReal(v.real) : setStr(v.str);
        }

        double& getReal()
        {
            assert(type == REAL);
            return real;
        }
        double getReal()const
        {
            assert(type == REAL);
            return real;
        }
        ValueString& getStr()
        {
            assert(type == STRING);
            return str;
        }
        const ValueString& getStr()const
        {
            assert(type == STRING);
            return str;
        }

        Value& operator = (const Value &v)
        {
            set(v);
            return *this;
        }
        Value& operator = (double v)
        {
            setReal(v);
            return *this;
        }
        Value& operator = (const char *str)
        {
            setStr(str);
            return *this;
        }
        Value& operator = (const std::string &str)
        {
            setStr(str);
            return *this;
        }
        Value& operator = (const wchar_t *str)
        {
            setStr(str);
            return *this;
        }
        Value& operator = (const std::wstring &str)
        {
            setStr(str);
            return *this;
        }
        template<class IMP>
        Value& operator = (const DelphiBaseString<IMP> &str)
        {
            setStr(str);
            return *this;
        }
        
        operator double()const {return getReal();}
        operator ValueString&() {return getStr();}
        operator const ValueString&()const {return getStr();}
        
        Type type;
        /**When type == REAL, stores the real value.
         * @note Assigning to this field will not force type to equal REAL.
         */
        double real;
        /**When type == STRING, points to the string object.
         * 
         * @note Assigning to this field will not force type to equal STRING.
         */
        ValueString str;
    };
    
    /**Swap the values of two gm::Value objects.
     * This has been implemented to avoid an expensive string copy (or even
     * reference count changes).
     */
    inline void swap(Value &a, Value &b)
    {
        using std::swap;
        swap(a.type, b.type);
        swap(a.real, b.real);
        swap(a.str, b.str);
    }
    ///@}
}
#endif
