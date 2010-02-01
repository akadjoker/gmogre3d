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

#ifndef GMOGRE_ANIMATION_STATE_H
#define GMOGRE_ANIMATION_STATE_H

#include "GMOgre3D.h"


GMFN double GetAnimationStateByName(char *name)
{
   if (mSceneMgr == NULL)
      return NULL;

   Ogre::AnimationState *anim = mSceneMgr->getAnimationState(name);

   return ConvertToGMPointer(anim);
}


GMFN double CreateAnimationState(char *name)
{
   if (mSceneMgr == NULL)
      return NULL;

   Ogre::AnimationState *anim = NULL;
      
   TRY
      anim = mSceneMgr->createAnimationState(name);
   CATCH("CreateAnimationState")

   return ConvertToGMPointer(anim);
}


GMFN double DestroyAnimationState(double anim_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   mSceneMgr->destroyAnimationState(anim->getAnimationName());

   return TRUE;
}


GMFN double EnableAnimationState(double anim_ptr, double enabled)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->setEnabled((enabled != 0));

   return TRUE;
}


GMFN double IsAnimationStateEnabled(double anim_ptr)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   return anim->getEnabled();
}


GMFN double EnableAnimationStateLoop(double anim_ptr, double enabled)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->setLoop((enabled != 0));

   return TRUE;
}


GMFN double IsAnimationStateLoopEnabled(double anim_ptr)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   return anim->getLoop();
}


GMFN double AddAnimationStateTime(double anim_ptr, double time)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->addTime(time);

   return TRUE;
}


GMFN double SetAnimationStateWeight(double anim_ptr, double weight)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->setWeight(weight);

   return TRUE;
}


GMFN double GetAnimationStateWeight(double anim_ptr)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   return anim->getWeight();
}


GMFN double SetAnimationStateTimePosition(double anim_ptr, double pos)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->setTimePosition(pos);

   return TRUE;
}


GMFN double GetAnimationStateTimePosition(double anim_ptr)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   return anim->getTimePosition();
}


GMFN double SetAnimationStateLength(double anim_ptr, double length)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->setLength(length);

   return TRUE;
}


GMFN double GetAnimationStateLength(double anim_ptr)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   return anim->getLength();
}


GMFN double SetAnimationStateBlendMaskEntry(double anim_ptr, double bone_handle, double weight)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->setBlendMaskEntry((size_t)bone_handle, weight);

   return TRUE;
}


GMFN double CreateAnimationStateBlendMask(double anim_ptr, double size, double weight)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->createBlendMask((size_t)size, weight);

   return TRUE;
}	


GMFN double DestroyAnimationStateBlendMask(double anim_ptr)
{
   Ogre::AnimationState *anim = ConvertFromGMPointer<Ogre::AnimationState*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->destroyBlendMask();

   return TRUE;
}

#endif
