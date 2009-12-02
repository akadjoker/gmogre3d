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

#ifndef GMOGRE_SKELETON_H
#define GMOGRE_SKELETON_H

#include "GMOgre3D.h"


GMFN double GetSkeletonBoneByName(double skel_ptr, char *name)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return 0;

   Ogre::Bone *bone = skel->getBone(name);

   return ConvertToGMPointer(bone);
}


GMFN double GetSkeletonNumBones(double skel_ptr)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return 0;

   return skel->getNumBones();
}


GMFN double GetSkeletonBone(double skel_ptr, double index)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return 0;

   Ogre::Bone *bone = skel->getBone((unsigned short)index);

   return ConvertToGMPointer(bone);
}


GMFN double CreateSkeletonAnimation(double skel_ptr, char *anim_name, double length)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return 0;

   Ogre::Animation *anim = skel->createAnimation(anim_name, length);

   return ConvertToGMPointer(anim);
}


GMFN double GetSkeletonNumAnimation(double skel_ptr)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return 0;

   return skel->getNumAnimations();
}


GMFN double GetSkeletonAnimation(double skel_ptr, double index)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return 0;

   Ogre::Animation *anim = skel->getAnimation(index);

   return ConvertToGMPointer(anim);
}


GMFN double GetSkeletonAnimationByName(double skel_ptr, char *anim_name)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return 0;

   Ogre::Animation *anim = skel->getAnimation(anim_name);

   return ConvertToGMPointer(anim);
}


GMFN double SetSkeletonBindingPose(double skel_ptr)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return FALSE;

   skel->setBindingPose();

   return TRUE;
}


GMFN double ResetSkeleton(double skel_ptr)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return FALSE;

   skel->reset();

   return TRUE;
}


GMFN double SetSkeletonEntityAnimationState(double skel_ptr, double ent_ptr)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return FALSE;

   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   skel->setAnimationState(*ent->getAllAnimationStates());

   return TRUE;
}


GMFN double SetSkeletonBlendMode(double skel_ptr, double type)
{
   Ogre::SkeletonInstance *skel = ConvertFromGMPointer<Ogre::SkeletonInstance*>(skel_ptr);

   if (skel == NULL)
      return FALSE;

   skel->setBlendMode(static_cast<Ogre::SkeletonAnimationBlendMode>((int)type));

   return TRUE;
}

#endif
