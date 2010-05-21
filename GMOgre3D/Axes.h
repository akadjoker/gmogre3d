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

#ifndef GMOGRE_AXES_H
#define GMOGRE_AXES_H


enum RotationMode
{
   XYZ_ROTATION = 1,
   XZY_ROTATION,
   ZXY_ROTATION,
   ZYX_ROTATION,
   YZX_ROTATION,
   YXZ_ROTATION
};

int mRotationMode = XYZ_ROTATION;


Ogre::Vector3 ConvertFromGMAxis(double x, double y, double z)
{
   if (mRotationMode == XYZ_ROTATION)
      return Ogre::Vector3(x, y, z);
   else if (mRotationMode == XZY_ROTATION)
      return Ogre::Vector3(x, z, y);
   else if (mRotationMode == ZXY_ROTATION)
      return Ogre::Vector3(z, x, y);
   else if (mRotationMode == ZYX_ROTATION)
      return Ogre::Vector3(z, y, x);
   else if (mRotationMode == YZX_ROTATION)
      return Ogre::Vector3(y, z, x);
   else
      return Ogre::Vector3(y, x, z);
}


Ogre::Vector3 ConvertToGMAxis(double x, double z, double y)
{
   if (mRotationMode == XYZ_ROTATION)
      return Ogre::Vector3(x, y, z);
   else if (mRotationMode == XZY_ROTATION)
      return Ogre::Vector3(x, z, y);
   else if (mRotationMode == ZXY_ROTATION)
      return Ogre::Vector3(z, x, y);
   else if (mRotationMode == ZYX_ROTATION)
      return Ogre::Vector3(y, x, z);
   else if (mRotationMode == YZX_ROTATION)
      return Ogre::Vector3(y, z, x);
   else
      return Ogre::Vector3(z, y, x);
}


Ogre::Vector3 ConvertToGMAxis(const Ogre::Vector3 &vec)
{
   return ConvertToGMAxis(vec.x, vec.y, vec.z);
}

#endif
