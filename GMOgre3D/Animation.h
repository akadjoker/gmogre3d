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

#ifndef GMOGRE_ANIMATION_H
#define GMOGRE_ANIMATION_H

#include "GMOgre3D.h"


GMFN double GetAnimationLength(double anim_ptr)
{
   Ogre::Animation *anim = ConvertFromGMPointer<Ogre::Animation*>(anim_ptr);

   if (anim == NULL)
      return 0;

   return anim->getLength();
}


GMFN double SetAnimationInterpolationMode(double anim_ptr, double type)
{
   Ogre::Animation *anim = ConvertFromGMPointer<Ogre::Animation*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   anim->setInterpolationMode(static_cast<Ogre::Animation::InterpolationMode>((int)type));

   return TRUE;
}


GMFN double CreateAnimationNodeTrack(double anim_ptr, double handle, double node_ptr)
{
   Ogre::Animation *anim = ConvertFromGMPointer<Ogre::Animation*>(anim_ptr);

   if (anim == NULL)
      return NULL;

   Ogre::Node *node = ConvertFromGMPointer<Ogre::Node*>(node_ptr);

   if (node == NULL)
      return NULL;

   Ogre::NodeAnimationTrack *track = anim->createNodeTrack((unsigned short)handle, node);

   return ConvertToGMPointer(track);
}


GMFN double DestroyAnimationNodeTrack(double anim_ptr, double node_track_ptr)
{
   Ogre::Animation *anim = ConvertFromGMPointer<Ogre::Animation*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   Ogre::NodeAnimationTrack *node_track = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(node_track_ptr);

   if (node_track == NULL)
      return FALSE;

   anim->destroyNodeTrack(node_track->getHandle());

   return TRUE;
}


GMFN double GetAnimationNodeTrackByHandle(double anim_ptr, double handle)
{
   Ogre::Animation *anim = ConvertFromGMPointer<Ogre::Animation*>(anim_ptr);

   if (anim == NULL)
      return FALSE;

   Ogre::NodeAnimationTrack *node_track = anim->getNodeTrack(handle);

   return ConvertToGMPointer(node_track);
}


#endif
