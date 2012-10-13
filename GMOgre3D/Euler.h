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

#ifndef GMOGRE_EULER_H
#define GMOGRE_EULER_H

#include "GMOgre3D.h"


GMFN double GetRotationTo(double fromx, double fromz, double fromy, double tox, double toz, double toy)
{
   Ogre::Vector3 direction = ConvertFromGMAxis(fromx, fromy, fromz) - ConvertFromGMAxis(tox, toy, toz);
   Ogre::Quaternion orientation;

   direction.normalise();

   // Test for opposite vectors
   Ogre::Real d = 1.0f + Ogre::Vector3::UNIT_X.dotProduct(direction);
   if (fabs(d) < 0.00001)
      orientation.FromAxes(Ogre::Vector3::NEGATIVE_UNIT_X, Ogre::Vector3::UNIT_Y, Ogre::Vector3::NEGATIVE_UNIT_Z);
   else
      orientation = Ogre::Vector3::UNIT_X.getRotationTo(direction);

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      SetGMVariable(*mEulerYaw, ConvertToGMYaw(orientation.getYaw().valueDegrees()));
      SetGMVariable(*mEulerPitch, ConvertToGMPitch(orientation.getPitch().valueDegrees()));
      SetGMVariable(*mEulerRoll, ConvertToGMRoll(orientation.getRoll().valueDegrees()));
   }

   return TRUE;
}

#endif
