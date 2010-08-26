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

#ifndef GMOGRE_PLANE_H
#define GMOGRE_PLANE_H

#include "GMOgre3D.h"


GMFN double CreatePlane(double normalx, double normalz, double normaly, double depth)
{
   Ogre::Plane *plane = NULL;
   
   TRY
      plane = OGRE_NEW Ogre::Plane(ConvertFromGMAxis(normalx, normaly, normalz), depth);
   CATCH("CreatePlane")

   return ConvertToGMPointer(plane);
}


GMFN double CreateMovablePlane(double normalx, double normalz, double normaly, double depth)
{
   Ogre::Plane *plane = NULL;
   
   TRY
      plane = OGRE_NEW Ogre::MovablePlane(ConvertFromGMAxis(normalx, normaly, normalz), depth);
   CATCH("CreateMovablePlane")

   return ConvertToGMPointer(plane);
}


GMFN double DestroyPlane(double plane_ptr)
{
   Ogre::Plane *plane = ConvertFromGMPointer<Ogre::Plane*>(plane_ptr);

   if (plane == NULL)
      return FALSE;

   delete plane;

   return TRUE;
}

#endif
