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

#ifndef GMOGRE_POPUP_MENU_H
#define GMOGRE_POPUP_MENU_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIPopupMenu.h"


GMFN double AddGUIPopupMenuItem(double gui_popup_menu_ptr, double gui_menu_item_ptr)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return FALSE;

   CEGUI::ItemEntry *item_entry = ConvertFromGMPointer<CEGUI::ItemEntry*>(gui_menu_item_ptr);

   if (item_entry == NULL)
      return FALSE;

   popup_menu->addItem(item_entry);

   return TRUE;
}


GMFN double RemoveGUIPopupMenuItem(double gui_popup_menu_ptr, double gui_menu_item_ptr)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return FALSE;

   CEGUI::ItemEntry *item_entry = ConvertFromGMPointer<CEGUI::ItemEntry*>(gui_menu_item_ptr);

   if (item_entry == NULL)
      return FALSE;
   
   popup_menu->removeItem(item_entry);

   return TRUE;
}


GMFN double GetGUIPopupMenuItemCount(double gui_popup_menu_ptr)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return 0;

   return popup_menu->getItemCount();
}


GMFN double ClearGUIPopupMenuItems(double gui_popup_menu_ptr)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return FALSE;

   popup_menu->resetList();

   return TRUE;
}


GMFN double SetGUIPopupMenuFadeInTime(double gui_popup_menu_ptr, double time)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return FALSE;

   popup_menu->setFadeInTime(time);

   return TRUE;
}


GMFN double SetGUIPopupMenuFadeOutTime(double gui_popup_menu_ptr, double time)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return FALSE;

   popup_menu->setFadeOutTime(time);

   return TRUE;
}


GMFN double OpenGUIPopupMenu(double gui_popup_menu_ptr)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return FALSE;

   popup_menu->openPopupMenu();

   return TRUE;
}


GMFN double CloseGUIPopupMenu(double gui_popup_menu_ptr)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return FALSE;

   popup_menu->closePopupMenu();

   return TRUE;
}


GMFN double IsGUIPopupMenuOpen(double gui_popup_menu_ptr)
{
   CEGUI::PopupMenu *popup_menu = ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

   if (popup_menu == NULL)
      return FALSE;

   return popup_menu->isPopupMenuOpen();
}

#endif
