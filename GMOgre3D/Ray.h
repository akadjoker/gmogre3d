/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2009 Robert Geiman
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

#ifndef GMOGRE_RAY_H
#define GMOGRE_RAY_H

#include "GMOgre3D.h"


GMFN double CreateRay()
{
   Ogre::Ray *ray = new Ogre::Ray;

   return ConvertToGMPointer(ray);
}


GMFN double DestroyRay(double ray_ptr)
{
   Ogre::Ray *ray = ConvertFromGMPointer<Ogre::Ray*>(ray_ptr);

   if (ray == NULL)
      return FALSE;

   delete ray;

   return TRUE;
}


GMFN double SetRayFromViewportCamera(double ray_ptr, double cam_ptr, double x, double y)
{
   Ogre::Ray *ray = ConvertFromGMPointer<Ogre::Ray*>(ray_ptr);

   if (ray == NULL)
      return FALSE;

   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   cam->getCameraToViewportRay(x, y, ray);

   return TRUE;
}


GMFN double SetRayDirection(double ray_ptr, double x, double z, double y)
{
   Ogre::Ray *ray = ConvertFromGMPointer<Ogre::Ray*>(ray_ptr);

   if (ray == NULL)
      return FALSE;

   ray->setDirection(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double SetRayOrigin(double ray_ptr, double x, double z, double y)
{
   Ogre::Ray *ray = ConvertFromGMPointer<Ogre::Ray*>(ray_ptr);

   if (ray == NULL)
      return FALSE;

   ray->setDirection(Ogre::Vector3(x, y, z));

   return TRUE;
}

#endif
