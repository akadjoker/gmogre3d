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

#include "stdafx.h"
#include "FrameListener.h"
#include "OgreNewt_World.h"
//#include "GMOgre3D.h"
#include "GMAPI.h"


GMFrameListener::GMFrameListener()
//:   mOgre2DManager(NULL),
:  mDisplayFPS(false),
   mDisplayNewtonDebugger(false),
   mNewtonWorld(NULL),
   mFrameStartedCallback(-1),
   mFrameEndedCallback(-1)
{
}


void GMFrameListener::UpdateFPSStats(void)
{
   static Ogre::String currFps = "Current FPS: ";
   static Ogre::String avgFps = "Average FPS: ";
   static Ogre::String bestFps = "Best FPS: ";
   static Ogre::String worstFps = "Worst FPS: ";
   static Ogre::String tris = "Triangle Count: ";
   static Ogre::String batchCount = "Batch Count: ";

   Ogre::RenderSystem *rs = Ogre::Root::getSingleton().getRenderSystem();

   if (rs == NULL)
      return;

   Ogre::RenderTarget *rt = rs->getRenderTarget("GMOGRE 3D Window");

   if (rt == NULL)
      return;

   // update stats when necessary
   Ogre::OverlayElement* guiAvg = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/AverageFps");
   Ogre::OverlayElement* guiCurr = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/CurrFps");
   Ogre::OverlayElement* guiBest = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/BestFps");
   Ogre::OverlayElement* guiWorst = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/WorstFps");
   Ogre::OverlayElement* guiBatch = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/NumBatches");

   guiAvg->setCaption(avgFps + Ogre::StringConverter::toString(rt->getAverageFPS()));
   guiCurr->setCaption(currFps + Ogre::StringConverter::toString(rt->getLastFPS()));
   guiBest->setCaption(bestFps + Ogre::StringConverter::toString(rt->getBestFPS())+" "+Ogre::StringConverter::toString(rt->getBestFrameTime())+" ms");
   guiWorst->setCaption(worstFps + Ogre::StringConverter::toString(rt->getWorstFPS())+" "+Ogre::StringConverter::toString(rt->getWorstFrameTime())+" ms");

   guiBatch->setCaption(batchCount + Ogre::StringConverter::toString(rt->getBatchCount()));

   Ogre::OverlayElement* guiTris = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/NumTris");
   guiTris->setCaption(tris + Ogre::StringConverter::toString(rt->getTriangleCount()));
}


void GMFrameListener::Create2DManager(Ogre::SceneManager *scene_mgr)
{
   //mOgre2DManager = new Ogre2dManager;
   //mOgre2DManager->init(scene_mgr, Ogre::RENDER_QUEUE_OVERLAY, true);
}


void GMFrameListener::DisplayFPS(bool enable)
{
   mDisplayFPS = enable;

   Ogre::Overlay *overlay = Ogre::OverlayManager::getSingleton().getByName("Core/DebugOverlay");

   if (overlay != NULL)
   {
      if (mDisplayFPS)
         overlay->show();
      else
         overlay->hide();
   }
}


void GMFrameListener::DisplayNewtonDebugger(OgreNewt::World *world, bool enable)
{
   mDisplayNewtonDebugger = enable;
   mNewtonWorld = world;
}


void GMFrameListener::SetStartFrameCallback(int func)
{
   mFrameStartedCallback = func;
}


void GMFrameListener::SetEndFrameCallback(int func)
{
   mFrameEndedCallback = func;
}


bool GMFrameListener::frameStarted(const Ogre::FrameEvent& evt)
{
   // Call our GM script to handle this callback
   if (mFrameStartedCallback >= 0)
   {
      gm::CGMVariable args[1];
      args[0].Set(evt.timeSinceLastFrame);

      gm::script_execute(mFrameStartedCallback, args, 1);  
   }

   if (mNewtonWorld)
   {
      if (mDisplayNewtonDebugger)
      {
         mNewtonWorld->getDebugger().showDebugInformation();
         //mNewtonDebugger->startRaycastRecording();
         //mNewtonDebugger->clearRaycastsRecorded();
      }
      else
      {
         mNewtonWorld->getDebugger().hideDebugInformation();
         //mNewtonDebugger->clearRaycastsRecorded();
         //mNewtonDebugger->stopRaycastRecording();
      }
   }

   return true;
}


bool GMFrameListener::frameEnded(const Ogre::FrameEvent& evt)
{
   if (mDisplayFPS)
      UpdateFPSStats();

   // Call our GM script to handle this callback
   if (mFrameEndedCallback >= 0)
   {
      gm::CGMVariable args[1];
      args[0].Set(evt.timeSinceLastFrame);

      gm::script_execute(mFrameEndedCallback, args, 1);  
   }

   return true;
}


/*
bool GMFrameListener::processUnbufferedMouseInput(const Ogre::FrameEvent& evt)
{
   
   return true;
}
*/