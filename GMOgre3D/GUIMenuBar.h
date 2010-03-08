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

#ifndef GMOGRE_MENU_BAR_H
#define GMOGRE_MENU_BAR_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIMenuBar.h"


GMFN double AddGUIMenuBarItem(double gui_menu_bar_ptr, double gui_menu_item_ptr)
{
   CEGUI::Menubar *menu_bar = ConvertFromGMPointer<CEGUI::Menubar*>(gui_menu_bar_ptr);

   if (menu_bar == NULL)
      return FALSE;

   CEGUI::ItemEntry *item_entry = ConvertFromGMPointer<CEGUI::ItemEntry*>(gui_menu_item_ptr);

   if (item_entry == NULL)
      return FALSE;

   menu_bar->addItem(item_entry);

   return TRUE;
}


GMFN double RemoveGUIMenuBarItem(double gui_menu_bar_ptr, double gui_menu_item_ptr)
{
   CEGUI::Menubar *menu_bar = ConvertFromGMPointer<CEGUI::Menubar*>(gui_menu_bar_ptr);

   if (menu_bar == NULL)
      return FALSE;

   CEGUI::ItemEntry *item_entry = ConvertFromGMPointer<CEGUI::ItemEntry*>(gui_menu_item_ptr);

   if (item_entry == NULL)
      return FALSE;
   
   menu_bar->removeItem(item_entry);

   return TRUE;
}


GMFN double GetGUIMenuBarItemCount(double gui_menu_bar_ptr)
{
   CEGUI::Menubar *menu_bar = ConvertFromGMPointer<CEGUI::Menubar*>(gui_menu_bar_ptr);

   if (menu_bar == NULL)
      return 0;

   return menu_bar->getItemCount();
}


GMFN double ClearGUIMenuBarItems(double gui_menu_bar_ptr)
{
   CEGUI::Menubar *menu_bar = ConvertFromGMPointer<CEGUI::Menubar*>(gui_menu_bar_ptr);

   if (menu_bar == NULL)
      return FALSE;

   menu_bar->resetList();

   return TRUE;
}

#endif
