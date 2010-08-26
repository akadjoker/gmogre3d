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

#ifndef GMOGRE_OVERLAY_H
#define GMOGRE_OVERLAY_H

#include "GMOgre3D.h"


GMFN double GetOverlayByName(char *name)
{
   Ogre::Overlay *overlay = Ogre::OverlayManager::getSingleton().getByName(name);

   return ConvertToGMPointer(overlay);
}


GMFN double CreateOverlay()
{
   Ogre::Overlay *overlay = NULL;
   
   TRY
      overlay = Ogre::OverlayManager::getSingleton().create(GenerateUniqueName());
   CATCH("CreateOverlay")

   return ConvertToGMPointer(overlay);
}


GMFN double DestroyOverlay(double overlay_ptr)
{
   Ogre::Overlay *overlay = ConvertFromGMPointer<Ogre::Overlay*>(overlay_ptr);

   if (overlay == NULL)
      return FALSE;

   Ogre::OverlayManager::getSingleton().destroy(overlay);

   return TRUE;
}


GMFN double ShowOverlay(double overlay_ptr)
{
   Ogre::Overlay *overlay = ConvertFromGMPointer<Ogre::Overlay*>(overlay_ptr);

   if (overlay == NULL)
      return FALSE;

   overlay->show();

   return TRUE;
}


GMFN double HideOverlay(double overlay_ptr)
{
   Ogre::Overlay *overlay = ConvertFromGMPointer<Ogre::Overlay*>(overlay_ptr);

   if (overlay == NULL)
      return FALSE;

   overlay->hide();

   return TRUE;
}


GMFN double RotateOverlay(double overlay_ptr, double degrees)
{
   Ogre::Overlay *overlay = ConvertFromGMPointer<Ogre::Overlay*>(overlay_ptr);

   if (overlay == NULL)
      return FALSE;

   overlay->rotate(Ogre::Degree((Ogre::Real)degrees));

   return TRUE;
}


GMFN double SetOverlayScale(double overlay_ptr, double x, double y)
{
   Ogre::Overlay *overlay = ConvertFromGMPointer<Ogre::Overlay*>(overlay_ptr);

   if (overlay == NULL)
      return FALSE;

   overlay->setScale((Ogre::Real)x, (Ogre::Real)y);

   return TRUE;
}


GMFN double SetOverlayZOrder(double overlay_ptr, double index)
{
   Ogre::Overlay *overlay = ConvertFromGMPointer<Ogre::Overlay*>(overlay_ptr);

   if (overlay == NULL)
      return FALSE;

   overlay->setZOrder((Ogre::ushort)index);

   return TRUE;
}


GMFN double AddOverlayChild(double overlay_ptr, double overlay_cntr_ptr)
{
   Ogre::Overlay *overlay = ConvertFromGMPointer<Ogre::Overlay*>(overlay_ptr);

   if (overlay == NULL)
      return FALSE;

   Ogre::OverlayContainer *overlay_cntr = ConvertFromGMPointer<Ogre::OverlayContainer*>(overlay_cntr_ptr);

   if (overlay_cntr == NULL)
      return FALSE;

   overlay->add2D(overlay_cntr);

   return TRUE;
}

#endif
