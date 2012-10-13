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

#ifndef GMOGRE_BONE_H
#define GMOGRE_BONE_H

#include "GMOgre3D.h"


GMFN double GetBoneHandle(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return 0;

   return bone->getHandle();
}


GMFN double SetBoneBindingPose(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setBindingPose();

   return TRUE;
}


GMFN double ResetBone(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->reset();

   return TRUE;
}


GMFN double EnableBoneManualControl(double bone_ptr, double enable)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setManuallyControlled((enable != 0));

   return TRUE;
}


GMFN double EnableBoneInheritScale(double bone_ptr, double enable)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setInheritScale((enable != 0));

   return TRUE;
}


GMFN double EnableBoneInheritOrientation(double bone_ptr, double enable)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setInheritOrientation((enable != 0));

   return TRUE;
}


GMFN double SetBoneScale(double bone_ptr, double x, double z, double y)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setScale(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetBonePosition(double bone_ptr, double x, double z, double y)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setPosition(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double GetBonePosition(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return 0;

   Ogre::Vector3 vec = bone->getPosition();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double BoneTranslate(double bone_ptr, double x, double z, double y, double relative_type = 1.0)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->translate(ConvertFromGMAxis(x, y, z), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double SetBoneOrientation(double bone_ptr, double yaw, double pitch, double roll)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));

   return TRUE;
}


GMFN double GetBoneOrientation(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   Ogre::Quaternion quat = bone->getOrientation();

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      SetGMVariable(*mEulerYaw, ConvertToGMYaw(quat.getYaw().valueDegrees()));
      SetGMVariable(*mEulerPitch, ConvertToGMPitch(quat.getPitch().valueDegrees()));
      SetGMVariable(*mEulerRoll, ConvertToGMRoll(quat.getRoll().valueDegrees()));
   }

   return TRUE;
}


GMFN double SetBoneRoll(double bone_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->roll(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetBoneRoll(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   Ogre::Quaternion quat = bone->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMRoll(euler.getRoll().valueDegrees());
}


GMFN double SetBoneYaw(double bone_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->yaw(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetBoneYaw(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   Ogre::Quaternion qt = bone->getOrientation();

   return ConvertToGMYaw(qt.getYaw().valueDegrees());
}


GMFN double SetBonePitch(double bone_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->pitch(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetBonePitch(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   Ogre::Quaternion quat = bone->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMRoll(euler.getPitch().valueDegrees());
}


GMFN double RotateBone(double bone_ptr, double x, double z, double y, double degrees, double relative_type = 0.0)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->rotate(ConvertFromGMAxis(x, y, z), Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double SetBoneInitialState(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setInitialState();

   return TRUE;
}


GMFN double ResetBoneToInitialState(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->resetToInitialState();

   return TRUE;
}

#endif
