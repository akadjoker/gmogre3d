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

#ifndef GMOGRE_MENU_ITEM_H
#define GMOGRE_MENU_ITEM_H

#include "GMOgre3D.h"
#include "GM_API.h"

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIMenuItem.h"



GMFN double SetGUIMenuItemPopupMenu(double gui_menu_item_ptr, double gui_popup_menu_ptr)
{
   CEGUI::MenuItem *menu_item = ConvertFromGMPointer<CEGUI::MenuItem*>(gui_menu_item_ptr);

   if (menu_item == NULL)
      return FALSE;

   CEGUI::PopupMenu *popup_menu = NULL;
   
   if (gui_popup_menu_ptr > 0.1)
   {
      ConvertFromGMPointer<CEGUI::PopupMenu*>(gui_popup_menu_ptr);

      if (popup_menu == NULL)
         return FALSE;
   }

   menu_item->setPopupMenu(popup_menu);

   return TRUE;
}


GMFN double OpenGUIMenuItemPopupMenu(double gui_menu_item_ptr)
{
   CEGUI::MenuItem *menu_item = ConvertFromGMPointer<CEGUI::MenuItem*>(gui_menu_item_ptr);

   if (menu_item == NULL)
      return FALSE;

   menu_item->openPopupMenu();

   return TRUE;
}


GMFN double CloseGUIMenuItemPopupMenu(double gui_menu_item_ptr)
{
   CEGUI::MenuItem *menu_item = ConvertFromGMPointer<CEGUI::MenuItem*>(gui_menu_item_ptr);

   if (menu_item == NULL)
      return FALSE;

   menu_item->closePopupMenu();

   return TRUE;
}


GMFN double IsGUIMenuItemPopupMenuOpened(double gui_menu_item_ptr)
{
   CEGUI::MenuItem *menu_item = ConvertFromGMPointer<CEGUI::MenuItem*>(gui_menu_item_ptr);

   if (menu_item == NULL)
      return FALSE;

   return menu_item->isOpened();
}


GMFN double IsGUIMenuItemHovering(double gui_menu_item_ptr)
{
   CEGUI::MenuItem *menu_item = ConvertFromGMPointer<CEGUI::MenuItem*>(gui_menu_item_ptr);

   if (menu_item == NULL)
      return FALSE;

   return menu_item->isHovering();
}


bool PerformMenuItemWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
{
   OgreCEGUIWindowData *data = GetGUIWindowData(args.window);
   if (data == NULL)
      return FALSE;

   std::map<std::string, int>::iterator iter = data->m_callback_map.find(std::string(event_name.c_str()));

   if (iter == data->m_callback_map.end())
      return false;

   // Call our GM script to handle this event
   GM_VALUE ret = GM_script_execute(iter->second, static_cast<double>(reinterpret_cast<intptr_t>(args.window)));

   return (GetGMRealValue(ret) != 0);
}


bool EventMenuItemClicked(const CEGUI::EventArgs &args) { return PerformMenuItemWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::MenuItem::EventClicked); }


GMFN double SetGUIMenuItemEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::MenuItem::EventClicked)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventMenuItemClicked));

   return TRUE;
}

#endif
