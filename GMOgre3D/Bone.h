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


GMFN double SetBoneScale(double bone_ptr, double x, double z, double y)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setScale(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double SetBonePosition(double bone_ptr, double x, double z, double y)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setPosition(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double GetBonePosition(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return 0;

   Ogre::Vector3 vec = bone->getPosition();

   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double BoneTranslate(double bone_ptr, double x, double z, double y, double relative_type = 1.0)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->translate(z, y, z, static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double SetBoneOrientation(double bone_ptr, double yaw, double pitch, double roll)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(pitch), Ogre::Degree(roll)));

   return TRUE;
}


GMFN double GetBoneOrientation(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   Ogre::Quaternion quat = bone->getOrientation();

   if (mEulerYaw != NULL)
   {
      *mEulerYaw = ConvertToGMYaw(quat.getYaw().valueDegrees());
      *mEulerPitch = quat.getPitch().valueDegrees();
      *mEulerRoll = quat.getRoll().valueDegrees();
   }

   return TRUE;
}


GMFN double SetBoneRoll(double bone_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->roll(Ogre::Degree(degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetBoneRoll(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   Ogre::Quaternion qt = bone->getOrientation();

   return qt.getRoll().valueDegrees();
}


GMFN double SetBoneYaw(double bone_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->yaw(Ogre::Degree(degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

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

   bone->pitch(Ogre::Degree(degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetBonePitch(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   //Ogre::Quaternion qt = bone->getOrientation();
   //return qt.getPitch().valueDegrees();

   // Retrieve proper pitch by removing bone yaw
   Ogre::Quaternion old_qt = bone->getOrientation();
   bone->yaw(old_qt.getYaw() * -1);
   Ogre::Quaternion qt = bone->getOrientation();
   bone->setOrientation(old_qt);

   return old_qt.getPitch().valueDegrees();
}


GMFN double SetBoneInitialState(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->setInitialState();

   return TRUE;
}


GMFN double ResetBoneInitialState(double bone_ptr)
{
   Ogre::Bone *bone = ConvertFromGMPointer<Ogre::Bone*>(bone_ptr);

   if (bone == NULL)
      return FALSE;

   bone->resetToInitialState();

   return TRUE;
}

#endif
