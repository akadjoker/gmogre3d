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

#ifndef GMOGRE_VECTOR_H
#define GMOGRE_VECTOR_H

#include "GMOgre3D.h"
#include "Euler.h"


GMFN double AddVector(double x1, double z1, double y1, double x2, double z2, double y2)
{
   Ogre::Vector3 vec = ConvertFromGMAxis(x1, y1, z1) + ConvertFromGMAxis(x2, y2, z2);

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double SubtractVector(double x1, double z1, double y1, double x2, double z2, double y2)
{
   Ogre::Vector3 vec = ConvertFromGMAxis(x1, y1, z1) - ConvertFromGMAxis(x2, y2, z2);

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double MultiplyVector(double x1, double z1, double y1, double x2, double z2, double y2)
{
   Ogre::Vector3 vec = ConvertFromGMAxis(x1, y1, z1) * ConvertFromGMAxis(x2, y2, z2);

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double RotateVector(double x1, double z1, double y1, double yaw, double pitch, double roll)
{
   Ogre::Vector3 vec = Euler(Ogre::Degree(yaw * -1), Ogre::Degree(pitch * -1), Ogre::Degree(roll * -1)).toQuaternion() * ConvertFromGMAxis(x1, y1, z1);

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double CalcVectorCrossProduct(double x1, double z1, double y1, double x2, double z2, double y2)
{
   Ogre::Vector3 vec = ConvertFromGMAxis(x1, y1, z1).crossProduct(ConvertFromGMAxis(x2, y2, z2));
   
   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double CalcVectorDotProduct(double x1, double y1, double z1, double x2, double y2, double z2)
{
   return ConvertFromGMAxis(x1, y1, z1).dotProduct(ConvertFromGMAxis(x2, y2, z2));
}


GMFN double CalcVectorDistance(double x1, double y1, double z1, double x2, double y2, double z2)
{
   return ConvertFromGMAxis(x1, y1, z1).distance(ConvertFromGMAxis(x2, y2, z2));
}


GMFN double NormalizeVector(double x, double z, double y)
{
   Ogre::Vector3 vec = ConvertFromGMAxis(x, y, z);

   Ogre::Real len = vec.normalise();

   SetGMVectorGlobals(vec);

   return len;
}


GMFN double NormalizeResultVector()
{
   Ogre::Real len = 0.0;

   Ogre::Vector3 vec = ConvertFromGMAxis(GetGMRealVariable(*mVectorX), GetGMRealVariable(*mVectorZ), GetGMRealVariable(*mVectorY));
   len = vec.normalise();

   SetGMVectorGlobals(vec);

   return len;
}


GMFN double GetVectorLength(double x, double z, double y)
{
   return ConvertFromGMAxis(x, y, z).length();
}

#endif
