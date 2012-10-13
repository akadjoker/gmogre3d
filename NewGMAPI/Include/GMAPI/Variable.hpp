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
#ifndef GMAPI_VARIABLE_HPP
#define GMAPI_VARIABLE_HPP
#include "Value.hpp"
namespace gm
{
    /**@addtogroup gm_variables*/
    ///@{
    /**
     * Total size: 40 (0x28) Bytes 
     */
    class Variable
    {
    public:
#pragma warning(push)
#pragma warning(disable : 4200)
        template<class T>
        class Array
        {
        public:
            unsigned getLen()const {return *(unsigned*)(((char*)this)-4);}
            T v[];
        };
#pragma warning(pop)
        typedef Array<Value> Row;

        /**The variables symbol id.*/
        int id;
        char padd04[4];
        //0x18 bytes
        /**The variables value.*/
        Value val;
        Array<Row*> *arr2d;
        char padd24[4];

        unsigned getRows()const
        {
            return arr2d ? arr2d->getLen() : 0;
        }
        unsigned getCols(unsigned row=0)const
        {
            if (getRows() < row || !arr2d->v[row]) return 0;
            else return arr2d->v[row]->getLen();
        }
        Row *getRow(unsigned row)
        {
            if (getRows() <= row) return 0;
            else return arr2d->v[row];
        }
        /**Returns a pointer to the value at some array location, or null if
         * the element does not exist.
         */
        Value *getValP(unsigned col=0, unsigned row=0)
        {
            //dont use array element 0,0, use the val member
            if (col == 0 && row == 0)
                return &val;
            //get array row
            Row *rowp = getRow(row);
            if (!rowp)
                return 0;
            //get element from row
            if (rowp->getLen() <= col)
                return 0;
            return &rowp->v[col];
        }
        /**Gets a value. If the value at that location exists, returns 0.0.*/
        Value getVal(unsigned col=0, unsigned row=0)
        {
            Value *v = getValP(col, row);
            return v ? *v : Value();
        }
    };

    /**@brief Array container for gm::Variable objects.
     * 
     * Used for all the user-defined variables, with one per instance and
     * another for global variables. Can not access the built in variables.
     */
    class GMAPI_DLL Variables
    {
    public:
        /**Returns the variable varid if it exists or null otherwise.*/
        Variable *findVar(int varid)
        {
            int index = findIndex(varid);
            if (index >= 0) return getFromIndex(index);
            else return 0;
        }
        
        /**Returns the index of name into the varid array.*/
        int findIndex(int varid)
        {
            for (int i=0; i<len; ++i)
                if (vars[i].id == varid)
                    return i;
            return -1;
        }
        /**Returns the variable located at index. Index must be valid.*/
        Variable *getFromIndex(int index)
        {
            assert (index >= 0 && index < len);
            return vars + index;
        }

        /**Get the number of variables stored here.*/
        int getLen(){return len;}
        Variable *getVars(){return vars;}
        
        Value getVal(int varid, int col=0, int row=0)
        {
            Variable *var = findVar(varid);
            if (var) return var->getVal(col, row);
            else return 0;
        }
    private:
        int unknown;
        Variable *vars;
        int len;
    };
    
    
    GMAPI_DLL extern Variables *userGlobals;
    /**Gets the id for a variable name. Works for both built in and user
     * defined, member and global variables,
     * 
     * Does not work for constants.
     * 
     * If their is no varid for the requested name, a new one is created.
     */
    GMAPI_DLL int getVarId(const DelphiString &name);

    ///@}
}
#endif
