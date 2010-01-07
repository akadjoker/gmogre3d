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

#ifndef GMOGRE_FRAMELISTENER_H
#define GMOGRE_FRAMELISTENER_H

#include "OgreNewt_World.h"

class GMFrameListener: public Ogre::FrameListener
{
private:
   void UpdateFPSStats(void);

public:
   GMFrameListener();

   void Create2DManager(Ogre::SceneManager *scene_mgr);
   void DisplayFPS(bool enable);
   void DisplayNewtonDebugger(OgreNewt::World *world, bool enable);

   bool frameStarted(const Ogre::FrameEvent& evt);
   bool frameEnded(const Ogre::FrameEvent& evt);

protected:
   //Ogre2dManager *mOgre2DManager;
   bool mDisplayFPS;
   bool mDisplayNewtonDebugger;
   OgreNewt::World *mNewtonWorld;
};

#endif
