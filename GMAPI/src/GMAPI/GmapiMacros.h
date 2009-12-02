/************************************************************************** 
  LICENSE:

    GMAPI is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    GMAPI is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with GMAPI; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301 USA
***************************************************************************/

/*************************************************************************
  GmapiMacros.h
  - Macros used to wrap GM function

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once

#define GMVAR_LEN( aArray ) (sizeof( aArray )/sizeof(gm::GMVALUE))

#define GM_NORMAL_CALL( aFunctionID ) gm::core::GMCallFunction(gm::CGMAPI::GMAPIFunctionArray(gm:: aFunctionID ),&argument,GMVAR_LEN(argument),&result)
#define GM_VOID_CALL( aFunctionID ) gm::core::GMCallFunction(gm::CGMAPI::GMAPIFunctionArray(gm:: aFunctionID ),NULL,0,&result)

#define GM_ARGS GMVALUE argument[]=
#define GM_NORMAL_RESULT gm::GMVALUE result;
#define GM_VAR_RESULT gm::CGMVariable retval(false);gm::GMVALUE result;ZeroMemory(&result,sizeof(result))
#define GM_PRESERVE_INSTANCE_DATA DWORD tInst=*((DWORD*)0x400804);DWORD wInst=*((DWORD*)0x400808)
#define GM_RESTORE_INSTANCE_DATA *((DWORD*)0x400804)=tInst;*((DWORD*)0x400808)=wInst

#define GM_RETURN_REAL return result.real
#define GM_RETURN_INT return(int)result.real
#define GM_RETURN_BOOL return(bool)(((int)result.real)&1)
#define GM_RETURN_VAR retval=result;gm::core::GMDeallocateResult( &result );return retval
