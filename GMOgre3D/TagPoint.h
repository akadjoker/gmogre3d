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

#ifndef GMOGRE_TAGPOINT_H
#define GMOGRE_TAGPOINT_H

#include "GMOgre3D.h"
#include "OgreTagPoint.h"
#include "GM_API.h"


GMFN double GetTagPointHandle(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   return tag_point->getHandle();
}


GMFN double SetTagPointBindingPose(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->setBindingPose();

   return 1.0;
}


GMFN double ResetTagPoint(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->reset();

   return 1.0;
}


GMFN double EnableTagPointManualControl(double tag_point_ptr, double enable)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->setManuallyControlled((enable != 0));

   return 1.0;
}


GMFN double EnableTagPointInheritScale(double tag_point_ptr, double enable)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->setInheritScale((enable != 0));

   return 1.0;
}


GMFN double EnableTagPointInheritOrientation(double tag_point_ptr, double enable)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->setInheritOrientation((enable != 0));

   return 1.0;
}


GMFN double SetTagPointScale(double tag_point_ptr, double x, double z, double y)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->setScale(ConvertFromGMAxis(x, y, z));

   return 1.0;
}


GMFN double SetTagPointPosition(double tag_point_ptr, double x, double z, double y)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->setPosition(ConvertFromGMAxis(x, y, z));

   return 1.0;
}


GMFN double GetTagPointPosition(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   Ogre::Vector3 vec = tag_point->getPosition();

   SetGMVectorGlobals(vec);

   return 1.0;
}



GMFN double TagPointTranslate(double tag_point_ptr, double x, double z, double y, double relative_type)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->translate(ConvertFromGMAxis(x, y, z), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return 1.0;
}


GMFN double SetTagPointOrientation(double tag_point_ptr, double yaw, double pitch, double roll)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));

   return 1.0;
}


GMFN double GetTagPointOrientation(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   Ogre::Quaternion quat = tag_point->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      SetGMVariable(*mEulerYaw, ConvertToGMYaw(euler.getYaw().valueDegrees()));
      SetGMVariable(*mEulerPitch, ConvertToGMPitch(euler.getPitch().valueDegrees()));
      SetGMVariable(*mEulerRoll, ConvertToGMRoll(euler.getRoll().valueDegrees()));
   }

   return 1.0;
}


GMFN double RollTagPoint(double tag_point_ptr, double degrees, double relative_type)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->roll(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return 1.0;
}


GMFN double GetTagPointRoll(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   Ogre::Quaternion quat = tag_point->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMRoll(euler.getRoll().valueDegrees());
}


GMFN double YawTagPoint(double tag_point_ptr, double degrees, double relative_type)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->yaw(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return 1.0;
}


GMFN double GetTagPointYaw(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   Ogre::Quaternion quat = tag_point->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMYaw(euler.getYaw().valueDegrees());
}


GMFN double PitchTagPoint(double tag_point_ptr, double degrees, double relative_type)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->pitch(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return 1.0;
}


GMFN double GetTagPointPitch(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   Ogre::Quaternion quat = tag_point->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMRoll(euler.getPitch().valueDegrees());
}


GMFN double RotateTagPoint(double tag_point_ptr, double x, double z, double y, double degrees, double relative_type)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->rotate(ConvertFromGMAxis(x, y, z), Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return 1.0;
}


GMFN double SetTagPointInitialState(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->setInitialState();

   return 1.0;
}


GMFN double ResetTagPointToInitialState(double tag_point_ptr)
{
   Ogre::TagPoint *tag_point = ConvertFromGMPointer<Ogre::TagPoint*>(tag_point_ptr);

   if (tag_point == NULL)
   {
      LogError("Invalid tag point ID!");
      return 0.0;
   }

   tag_point->resetToInitialState();

   return 1.0;
}

#endif
