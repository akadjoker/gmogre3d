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

#ifndef GMOGRE_VIEWPORT_H
#define GMOGRE_VIEWPORT_H

#include "GMOgre3D.h"
#include "RenderTargetListener.h"


GMFN double CreateViewport(double zorder, double left, double top, double width, double height)
{
   Ogre::Viewport *view = NULL;
   
   TRY
      view = mRenderWindow->addViewport(NULL, zorder, left / mWindowWidth, top / mWindowHeight, width / mWindowWidth, height / mWindowHeight);
      view->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.0f));
   CATCH("CreateViewport")

   return ConvertToGMPointer(view);
}


GMFN double SetViewportCamera(double viewport_ptr, double camera_ptr)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   view->setCamera(cam);

   return TRUE;
}


GMFN double DestroyViewport(double viewport_ptr)
{
   mRenderWindow->removeViewport(ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr)->getZOrder());

   return TRUE;
}


GMFN double DestroyAllViewports()
{
   mRenderWindow->removeAllViewports();

   return TRUE;
}


GMFN double SetViewportBackgroundColor(double viewport_ptr, double color)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   view->setBackgroundColour(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color)));

   return TRUE;
}


GMFN double EnableViewportClearEveryFrame(double viewport_ptr, double enable)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   view->setClearEveryFrame((enable != 0));

   return TRUE;
}


GMFN double EnableViewportOverlays(double viewport_ptr, double enabled)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   view->setOverlaysEnabled((enabled != 0));

   return TRUE;
}


GMFN double EnableViewportSkies(double viewport_ptr, double enabled)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   view->setSkiesEnabled((enabled != 0));

   return TRUE;
}


GMFN double EnableViewportShadows(double viewport_ptr, double enabled)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   view->setShadowsEnabled((enabled != 0));

   return TRUE;
}


GMFN double AddViewportTargetListener(double viewport_ptr, double obj, double pre_event, double post_event)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return NULL;

   GMRenderTargetListener *listener = new GMRenderTargetListener((unsigned int)obj, (unsigned int)pre_event, (unsigned int)post_event);
   view->getTarget()->addListener(listener);

   return ConvertToGMPointer(listener);
}


GMFN double RemoveViewportTargetListener(double viewport_ptr, double listener_ptr)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   GMRenderTargetListener *listener = ConvertFromGMPointer<GMRenderTargetListener*>(listener_ptr);

   if (listener == NULL)
      return FALSE;

   view->getTarget()->removeListener(listener);

   return TRUE;
}

#endif
