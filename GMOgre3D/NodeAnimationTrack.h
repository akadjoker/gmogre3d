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

   Ogre::TransformKeyFrame *key_frm = node_anim->createNodeKeyFrame(time);

   return ConvertToGMPointer(key_frm);
}


GMFN double RemoveAnimationNodeKeyFrame(double anim_node_ptr, double anim_node_key_frame_ptr)
{
   Ogre::NodeAnimationTrack *node_anim = ConvertFromGMPointer<Ogre::NodeAnimationTrack*>(anim_node_ptr);

   if (node_anim == NULL)
      return FALSE;

   Ogre::KeyFrame *anim_node_key_frame = ConvertFromGMPointer<Ogre::KeyFrame*>(anim_node_key_frame_ptr);

   if (anim_node_key_frame == NULL)
      return FALSE;

   node_anim->removeKeyFrame(anim_node_key_frame->getTime());

   return TRUE;
}

#endif
