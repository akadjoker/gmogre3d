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

#ifndef GMOGRE_TRANSFORM_KEY_FRAME_H
#define GMOGRE_TRANSFORM_KEY_FRAME_H

#include "GMOgre3D.h"


GMFN double SetTransformKeyFrameTranslate(double key_frame_ptr, double x, double z, double y)
{
   Ogre::TransformKeyFrame *key_frame = ConvertFromGMPointer<Ogre::TransformKeyFrame*>(key_frame_ptr);

   if (key_frame == NULL)
      return FALSE;

   key_frame->setTranslate(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetTransformKeyFrameScale(double key_frame_ptr, double x, double z, double y)
{
   Ogre::TransformKeyFrame *key_frame = ConvertFromGMPointer<Ogre::TransformKeyFrame*>(key_frame_ptr);

   if (key_frame == NULL)
      return FALSE;

   key_frame->setScale(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetTransformKeyFrameRotation(double key_frame_ptr, double yaw, double pitch, double roll)
{
   Ogre::TransformKeyFrame *key_frame = ConvertFromGMPointer<Ogre::TransformKeyFrame*>(key_frame_ptr);

   if (key_frame == NULL)
      return FALSE;

   key_frame->setRotation(Euler(Ogre::Degree((yaw * -1) - 90), Ogre::Degree(pitch), Ogre::Degree(roll)));

   return TRUE;
}

#endif
