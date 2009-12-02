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

#ifndef GMOGRE_OVERLAY_ELEMENT_H
#define GMOGRE_OVERLAY_ELEMENT_H

#include "GMOgre3D.h"
#include "OgrePanelOverlayElement.h"
#include "OgreBorderPanelOverlayElement.h"
#include "font.h"


GMFN double GetOverlayElementByName(char *name)
{
   Ogre::OverlayElement *overlay_elem = Ogre::OverlayManager::getSingleton().getOverlayElement(name);

   return ConvertToGMPointer(overlay_elem);
}


GMFN double CreateOverlayElement(double type)
{
   Ogre::OverlayElement *overlay_elem = NULL;

   if (type == OVERLAY_BORDER_PANEL)
      overlay_elem = Ogre::OverlayManager::getSingleton().createOverlayElement("BorderPanel", GenerateUniqueName());
   else if (type == OVERLAY_PANEL)
      overlay_elem = Ogre::OverlayManager::getSingleton().createOverlayElement("Panel", GenerateUniqueName());
   else if (type == OVERLAY_TEXT_AREA)
      overlay_elem = Ogre::OverlayManager::getSingleton().createOverlayElement("TextArea", GenerateUniqueName());

   // Users can change metrics, but we default to pixels
   if (overlay_elem != NULL)
      overlay_elem->setMetricsMode(Ogre::GMM_PIXELS);

   return ConvertToGMPointer(overlay_elem);
}


GMFN double DestroyOverlayElement(double overlay_elem_ptr)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   Ogre::OverlayManager::getSingleton().destroyOverlayElement(overlay_elem);

   return TRUE;
}


GMFN double ShowOverlayElement(double overlay_elem_ptr)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_elem->show();

   return TRUE;
}


GMFN double HideOverlayElement(double overlay_elem_ptr)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_elem->hide();

   return TRUE;
}


GMFN double SetOverlayElementMetrics(double overlay_elem_ptr, double type)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_elem->setMetricsMode(static_cast<Ogre::GuiMetricsMode>((int)type));

   return TRUE;
}


GMFN double SetOverlayElementPosition(double overlay_elem_ptr, double x, double y)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_elem->setPosition(x, y);

   return TRUE;
}


GMFN double SetOverlayElementDimensions(double overlay_elem_ptr, double width, double height)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_elem->setDimensions(width, height);

   return TRUE;
}


GMFN double SetOverlayElementMaterial(double overlay_elem_ptr, char *name)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_elem->setMaterialName(name);

   return TRUE;
}


GMFN double SetOverlayElementCaption(double overlay_elem_ptr, char *txt)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_elem->setCaption(txt);

   return TRUE;
}


GMFN double SetOverlayElementColor(double overlay_elem_ptr, double color, double alpha = 1.0)
{
   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_elem->setColour(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));

   return TRUE;
}


GMFN double AddOverlayElementChild(double overlay_cntr_ptr, double overlay_elem_ptr)
{
   Ogre::OverlayContainer *overlay_cntr = ConvertFromGMPointer<Ogre::OverlayContainer*>(overlay_cntr_ptr);

   if (overlay_cntr == NULL)
      return FALSE;

   Ogre::OverlayElement *overlay_elem = ConvertFromGMPointer<Ogre::OverlayElement*>(overlay_elem_ptr);

   if (overlay_elem == NULL)
      return FALSE;

   overlay_cntr->addChild(overlay_elem);

   return TRUE;
}


GMFN double SetTextOverlayElementTopColor(double ta_overlay_elem_ptr, double color, double alpha = 1.0)
{
   Ogre::TextAreaOverlayElement *ta_overlay_elem = ConvertFromGMPointer<Ogre::TextAreaOverlayElement*>(ta_overlay_elem_ptr);

   if (ta_overlay_elem == NULL)
      return FALSE;

   ta_overlay_elem->setColourTop(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));

   return TRUE;
}


GMFN double SetTextOverlayElementBottomColor(double ta_overlay_elem_ptr, double color, double alpha = 1.0)
{
   Ogre::TextAreaOverlayElement *ta_overlay_elem = ConvertFromGMPointer<Ogre::TextAreaOverlayElement*>(ta_overlay_elem_ptr);

   if (ta_overlay_elem == NULL)
      return FALSE;

   ta_overlay_elem->setColourBottom(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));

   return TRUE;
}


GMFN double SetTextOverlayElementFont(double ta_overlay_elem_ptr, char *font_name)
{
   Ogre::TextAreaOverlayElement *ta_overlay_elem = ConvertFromGMPointer<Ogre::TextAreaOverlayElement*>(ta_overlay_elem_ptr);

   if (ta_overlay_elem == NULL)
      return FALSE;

   ta_overlay_elem->setFontName(font_name);
   ta_overlay_elem->setCharHeight(GetFontSize(font_name));

   return TRUE;
}


GMFN double SetTextOverlayElementAlignment(double ta_overlay_elem_ptr, double type)
{
   Ogre::TextAreaOverlayElement *ta_overlay_elem = ConvertFromGMPointer<Ogre::TextAreaOverlayElement*>(ta_overlay_elem_ptr);

   if (ta_overlay_elem == NULL)
      return FALSE;

   ta_overlay_elem->setAlignment(static_cast<Ogre::TextAreaOverlayElement::Alignment>((int)type));

   return TRUE;
}


GMFN double SetPanelOverlayElementTiling(double panel_overlay_elem_ptr, double x, double y)
{
   Ogre::PanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::PanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setTiling(x, y);

   return TRUE;
}


GMFN double SetPanelOverlayElementUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::PanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::PanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setUV(u1, v1, u2, v2);

   return TRUE;
}


GMFN double EnablePanelOverlayElementTransparency(double panel_overlay_elem_ptr, double enable)
{
   Ogre::PanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::PanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setTransparent((enable != 0));

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementSize(double panel_overlay_elem_ptr, double left, double right, double top, double bottom)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setBorderSize(left, right, top, bottom);

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementLeftBorderUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setLeftBorderUV(u1, v1, u2, v2);

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementRightBorderUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setRightBorderUV(u1, v1, u2, v2);

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementTopBorderUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setTopBorderUV(u1, v1, u2, v2);

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementBottomBorderUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setBottomBorderUV(u1, v1, u2, v2);

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementTopLeftBorderUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setTopLeftBorderUV(u1, v1, u2, v2);

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementTopRightBorderUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setTopRightBorderUV(u1, v1, u2, v2);

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementBottomLeftBorderUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setBottomLeftBorderUV(u1, v1, u2, v2);

   return TRUE;
}


GMFN double SetBorderPanelOverlayElementBottomRightBorderUV(double panel_overlay_elem_ptr, double u1, double v1, double u2, double v2)
{
   Ogre::BorderPanelOverlayElement *panel_overlay_elem = ConvertFromGMPointer<Ogre::BorderPanelOverlayElement*>(panel_overlay_elem_ptr);

   if (panel_overlay_elem == NULL)
      return FALSE;

   panel_overlay_elem->setBottomRightBorderUV(u1, v1, u2, v2);

   return TRUE;
}

#endif
