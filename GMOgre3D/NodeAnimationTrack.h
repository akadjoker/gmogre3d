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

#ifndef GMOGRE_NODE_ANIMATION_TRACK_H
#define GMOGRE_NODE_ANIMATION_TRACK_H

#include "GMOgre3D.h"


GMFN double CreateAnimationNodeTrackNodeKeyFrame(double anim_node_ptr, double time)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return NULL;

   Ogre::TransformKeyFrame *key_frm = NULL;
   
   TRY
      key_frm = node_anim->createNodeKeyFrame(time);
   CATCH("CreateAnimationNodeTrackNodeKeyFrame")

   return ConvertToGMPointer(key_frm);
}


GMFN double CreateAnimationNodeTrackKeyFrame(double anim_node_ptr, double time)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return NULL;

   Ogre::KeyFrame *key_frm = NULL;
   
   TRY
      key_frm = node_anim->createKeyFrame(time);
   CATCH("CreateAnimationNodeTrackKeyFrame")

   return ConvertToGMPointer(key_frm);
}


GMFN double RemoveAnimationNodeTrackKeyFrame(double anim_node_ptr, double index)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return FALSE;

   node_anim->removeKeyFrame(index);

   return TRUE;
}


GMFN double RemoveAllAnimationNodeTrackKeyFrames(double anim_node_ptr)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return FALSE;

   node_anim->removeAllKeyFrames();

   return TRUE;
}


GMFN double GetNumAnimationNodeTrackKeyFrames(double anim_node_ptr)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return 0;

   return node_anim->getNumKeyFrames();
}


GMFN double GetAnimationNodeNodeTrackKeyFrame(double anim_node_ptr, double index)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return FALSE;

   return ConvertToGMPointer(node_anim->getNodeKeyFrame(index));
}


GMFN double AcquireAnimationNodeTrackInterpolatedKeyFrame(double anim_node_ptr, double index)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return FALSE;

   Ogre::KeyFrame *kf = new Ogre::KeyFrame(0, 0);
   node_anim->getInterpolatedKeyFrame(index, kf);

   return ConvertToGMPointer(kf);
}


GMFN double ReleaseAnimationNodeTrackInterpolatedKeyFrame(double anim_node_ptr, double interpolated_key_frame_ptr)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return FALSE;

   Ogre::KeyFrame *kf = ConvertFromGMPointer<Ogre::KeyFrame*>(interpolated_key_frame_ptr);

   if (kf == NULL)
      return FALSE;

   delete kf;

   return TRUE;
}

#endif
