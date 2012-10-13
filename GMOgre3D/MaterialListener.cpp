/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2010 Robert Geiman
<robgeiman@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
--------------------------------------------------------------------------------
*/

#include "stdafx.h"
#include "MaterialListener.h"
//#include "GMOgre3D.h"
#include "GM_API.h"


template<typename T>
T ConvertFromGMPointer2(double ptr)
{
   T obj = reinterpret_cast<T>(static_cast<intptr_t>(ptr));

   return obj;
}

template<typename T>
double ConvertToGMPointer2(T ptr)
{
   return static_cast<double>(reinterpret_cast<intptr_t>(ptr));
}

GMMaterialListener::GMMaterialListener()
:  mHandleSchemeNotFoundCallback(-1)
{
}


Ogre::Technique* GMMaterialListener::handleSchemeNotFound(unsigned short schemeIndex, const Ogre::String &schemeName, Ogre::Material *originalMaterial,	unsigned short lodIndex, const Ogre::Renderable *rend)
{
   // Call our GM script to handle this callback
   if (mHandleSchemeNotFoundCallback >= 0)
   {
      GM_VALUE &ret = GM_script_execute(mHandleSchemeNotFoundCallback, schemeIndex, schemeName, ConvertToGMPointer2(originalMaterial), lodIndex);

      if (GetGMRealValue(ret) < 1.0f)
         return NULL;

      return ConvertFromGMPointer2<Ogre::Technique*>(GetGMRealValue(ret));
   }

   return NULL;
}


void GMMaterialListener::SetSchemeNotFoundCallback(int func)
{
   mHandleSchemeNotFoundCallback = func;
}
