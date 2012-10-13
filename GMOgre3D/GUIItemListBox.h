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

#ifndef GMOGRE_GUI_ITEM_LIST_BOX_H
#define GMOGRE_GUI_ITEM_LIST_BOX_H

#include "GMOgre3D.h"
#include "GM_API.h"

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIItemListBox.h"
#include "elements/CEGUIListboxTextItem.h"


GMFN double GetGUIItemListBoxSelectedCount(double gui_list_box_ptr)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   return list_box->getSelectedCount();
}


GMFN double AddGUIItemListBoxItem(double gui_list_box_ptr, double gui_item_entry_ptr)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   CEGUI::ItemEntry *item_entry = ConvertFromGMPointer<CEGUI::ItemEntry*>(gui_item_entry_ptr);

   if (item_entry == NULL)
      return FALSE;

   list_box->addItem(item_entry);

   return TRUE;
}


GMFN double RemoveGUIItemListBoxItem(double gui_list_box_ptr, double index)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   CEGUI::ItemEntry *item = list_box->getItemFromIndex(index);

   if (item == NULL)
      return FALSE;
   
   list_box->removeItem(item);

   return TRUE;
}


GMFN double GetGUIItemListBoxItemCount(double gui_list_box_ptr)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return 0;

   return list_box->getItemCount();
}


GMFN double ClearGUIItemListBoxItems(double gui_list_box_ptr)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->resetList();

   return TRUE;
}


GMFN double ClearGUIItemListBoxSelections(double gui_list_box_ptr)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->clearAllSelections();

   return TRUE;
}


GMFN double IsGUIItemListBoxItemSelected(double gui_list_box_ptr, double index)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   return list_box->isItemSelected(index);
}


GMFN double GetGUIItemListBoxFirstSelectedItem(double gui_list_box_ptr)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   CEGUI::ItemEntry *item = list_box->getFirstSelectedItem();

   if (item == NULL)
      return -1;

   return list_box->getItemIndex(item);
}


GMFN double GetGUIItemListBoxNextSelectedItem(double gui_list_box_ptr, double index)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   CEGUI::ItemEntry *item = list_box->getFirstSelectedItem(index + 1);

   if (item == NULL)
      return -1;

   return list_box->getItemIndex(item);
}


GMFN double SelectGUIItemListBoxItem(double gui_list_box_ptr, double index)
{
   CEGUI::ItemListbox *list_box = ConvertFromGMPointer<CEGUI::ItemListbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->selectRange(index, index);

   return TRUE;
}


bool PerformItemListBoxWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
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


bool EventItemListBoxSelectionChanged(const CEGUI::EventArgs &args) { return PerformItemListBoxWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::ItemListbox::EventSelectionChanged); }


GMFN double SetGUIItemListBoxEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::ItemListbox::EventSelectionChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventItemListBoxSelectionChanged));

   return TRUE;
}

#endif
