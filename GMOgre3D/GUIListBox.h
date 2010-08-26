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

#ifndef GMOGRE_GUI_LIST_BOX_H
#define GMOGRE_GUI_LIST_BOX_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIListBox.h"
#include "elements/CEGUIListboxTextItem.h"


GMFN double GetGUIListBoxSelectedCount(double gui_list_box_ptr)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   return list_box->getSelectedCount();
}


GMFN double AddGUIListBoxItem(double gui_list_box_ptr, char *text, double id)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   CEGUI::ListboxTextItem *item = OGRE_NEW CEGUI::ListboxTextItem(text, id, 0, false, true);
   
   list_box->addItem(item);

   return TRUE;
}


GMFN double RemoveGUIListBoxItem(double gui_list_box_ptr, double index)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   CEGUI::ListboxItem *item = list_box->getListboxItemFromIndex(index);

   if (item == NULL)
      return FALSE;
   
   list_box->removeItem(item);

   return TRUE;
}


GMFN double GetGUIListBoxItemCount(double gui_list_box_ptr)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return 0;

   return list_box->getItemCount();
}


GMFN double GetGUIListBoxItemID(double gui_list_box_ptr, double index)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return 0;

   CEGUI::ListboxItem *item = list_box->getListboxItemFromIndex(index);

   if (item == NULL)
      return 0;

   return item->getID();
}


GMFN double GetGUIListBoxIndexFromID(double gui_list_box_ptr, double id)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   for (size_t x = 0; x < list_box->getItemCount(); x++)
   {
      CEGUI::ListboxItem *item = list_box->getListboxItemFromIndex(x);

      if (item == NULL)
         continue;

      if (item->getID() == id)
         return x;
   }

   return -1;
}


GMFN double ClearGUIListBoxItems(double gui_list_box_ptr)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->resetList();

   return TRUE;
}


GMFN double ClearGUIListBoxSelections(double gui_list_box_ptr)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->clearAllSelections();

   return TRUE;
}


GMFN double IsGUIListBoxItemSelected(double gui_list_box_ptr, double index)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   return list_box->isItemSelected(index);
}


GMFN double GetGUIListBoxFirstSelectedItem(double gui_list_box_ptr)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   CEGUI::ListboxItem *item = list_box->getFirstSelectedItem();

   if (item == NULL)
      return -1;

   return list_box->getItemIndex(item);
}


GMFN double GetGUIListBoxNextSelectedItem(double gui_list_box_ptr, double index)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   CEGUI::ListboxItem *item = list_box->getNextSelected(list_box->getListboxItemFromIndex(index));

   if (item == NULL)
      return -1;

   return list_box->getItemIndex(item);
}


GMFN double SelectGUIListBoxItem(double gui_list_box_ptr, double index, double select)
{
   CEGUI::Listbox *list_box = ConvertFromGMPointer<CEGUI::Listbox*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   CEGUI::ListboxItem *item = list_box->getListboxItemFromIndex(index);

   if (item == NULL)
      return FALSE;

   list_box->setItemSelectState(item, (select != 0));

   return TRUE;
}


bool PerformListBoxWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
{
   OgreCEGUIWindowData *data = GetGUIWindowData(args.window);
   if (data == NULL)
      return FALSE;

   std::map<std::string, int>::iterator iter = data->m_callback_map.find(std::string(event_name.c_str()));

   if (iter == data->m_callback_map.end())
      return false;

   // Call our GM script to handle this event
   gm::CGMVariable gm_args[1];
   gm_args[0].Set(static_cast<double>(reinterpret_cast<intptr_t>(args.window)));
   gm::CGMVariable ret = gm::script_execute(iter->second, gm_args, 1);

   return (ret.real() != 0);
}


bool EventListBoxSelectionChanged(const CEGUI::EventArgs &args) { return PerformListBoxWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Listbox::EventSelectionChanged); }


GMFN double SetGUIListBoxEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Listbox::EventSelectionChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventListBoxSelectionChanged));

   return TRUE;
}

#endif
