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

#ifndef GMOGRE_GUI_SCROLLBAR_H
#define GMOGRE_GUI_SCROLLBAR_H

#include "GMOgre3D.h"
#include "GM_API.h"

// CEGUI includes
#include "CEGUIWindow.h"
#include "elements/CEGUIScrollBar.h"


GMFN double SetGUIScrollBarStepSize(double gui_scrollbar_ptr, double value)
{
   CEGUI::Scrollbar *scrollbar = ConvertFromGMPointer<CEGUI::Scrollbar*>(gui_scrollbar_ptr);

   if (scrollbar == NULL)
   {
      return 0.0;
   }

   scrollbar->setStepSize(value);

   return 1.0;
}


GMFN double SetGUIScrollBarPageSize(double gui_scrollbar_ptr, double value)
{
   CEGUI::Scrollbar *scrollbar = ConvertFromGMPointer<CEGUI::Scrollbar*>(gui_scrollbar_ptr);

   if (scrollbar == NULL)
   {
      return 0.0;
   }

   scrollbar->setPageSize(value);

   return 1.0;
}


GMFN double SetGUIScrollBarScrollPosition(double gui_scrollbar_ptr, double value)
{
   CEGUI::Scrollbar *scrollbar = ConvertFromGMPointer<CEGUI::Scrollbar*>(gui_scrollbar_ptr);

   if (scrollbar == NULL)
   {
      return 0.0;
   }

   scrollbar->setScrollPosition(value);

   return 1.0;
}


GMFN double GetGUIScrollBarScrollPosition(double gui_scrollbar_ptr)
{
   CEGUI::Scrollbar *scrollbar = ConvertFromGMPointer<CEGUI::Scrollbar*>(gui_scrollbar_ptr);

   if (scrollbar == NULL)
   {
      return 0.0;
   }

   return scrollbar->getScrollPosition();
}

#endif
