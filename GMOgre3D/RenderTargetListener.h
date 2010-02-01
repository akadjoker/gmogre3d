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

#ifndef GMOGRE_RENDER_TARGET_LISTENER_H
#define GMOGRE_RENDER_TARGET_LISTENER_H

#include "GMOgre3D.h"


class GMRenderTargetListener: public Ogre::RenderTargetListener
{
public:
   GMRenderTargetListener(unsigned int target_object, unsigned int pre_event_num, unsigned int post_event_num)
   :  mTargetObject(target_object),
      mPreEventNum(pre_event_num),
      mPostEventNum(post_event_num)
   {
   }

   void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
   {
      gm::event_perform_object(mTargetObject, gm::ev_other, mPreEventNum);
   }

   void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
   {
      gm::event_perform_object(mTargetObject, gm::ev_other, mPostEventNum);
   }

protected:
   unsigned int mTargetObject;
   unsigned int mPreEventNum;
   unsigned int mPostEventNum;
};

#endif
