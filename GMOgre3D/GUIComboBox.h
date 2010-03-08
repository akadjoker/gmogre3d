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

#ifndef GMOGRE_GUI_COMBO_BOX_H
#define GMOGRE_GUI_COMBO_BOX_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIComboBox.h"
#include "elements/CEGUIListboxTextItem.h"


GMFN double EnableGUIComboBoxReadOnly(double gui_combo_box_ptr, double enable)
{
   CEGUI::Combobox *combo_box = ConvertFromGMPointer<CEGUI::Combobox*>(gui_combo_box_ptr);

   if (combo_box == NULL)
      return FALSE;

   combo_box->setReadOnly((enable != 0));

   return TRUE;
}


GMFN double AddGUIComboBoxItem(double gui_combo_box_ptr, char *text, double id)
{
   CEGUI::Combobox *combo_box = ConvertFromGMPointer<CEGUI::Combobox*>(gui_combo_box_ptr);

   if (combo_box == NULL)
      return FALSE;

   CEGUI::ListboxTextItem *item = new CEGUI::ListboxTextItem(text, id, 0, false, true);
   
   combo_box->addItem(item);

   return TRUE;
}


GMFN double RemoveGUIComboBoxItem(double gui_combo_box_ptr, double index)
{
   CEGUI::Combobox *combo_box = ConvertFromGMPointer<CEGUI::Combobox*>(gui_combo_box_ptr);

   if (combo_box == NULL)
      return FALSE;

   CEGUI::ListboxItem *item = combo_box->getListboxItemFromIndex(index);
   
   combo_box->removeItem(item);

   return TRUE;
}


GMFN double GetGUIComboBoxItemCount(double gui_combo_box_ptr)
{
   CEGUI::Combobox *combo_box = ConvertFromGMPointer<CEGUI::Combobox*>(gui_combo_box_ptr);

   if (combo_box == NULL)
      return 0;

   return combo_box->getItemCount();
}


GMFN double ClearGUIComboBoxItems(double gui_combo_box_ptr)
{
   CEGUI::Combobox *combo_box = ConvertFromGMPointer<CEGUI::Combobox*>(gui_combo_box_ptr);

   if (combo_box == NULL)
      return FALSE;

   combo_box->resetList();

   return TRUE;
}


GMFN double GetGUIComboBoxSelectedIndex(double gui_combo_box_ptr)
{
   CEGUI::Combobox *combo_box = ConvertFromGMPointer<CEGUI::Combobox*>(gui_combo_box_ptr);

   if (combo_box == NULL)
      return 0;

   CEGUI::ListboxItem *item = combo_box->getSelectedItem();

   if (item == NULL)
      return 0;

   return combo_box->getItemIndex(item);
}


GMFN double GetGUIComboBoxSelectedItemID(double gui_combo_box_ptr)
{
   CEGUI::Combobox *combo_box = ConvertFromGMPointer<CEGUI::Combobox*>(gui_combo_box_ptr);

   if (combo_box == NULL)
      return 0;

   CEGUI::ListboxItem *item = combo_box->getSelectedItem();

   if (item == NULL)
      return 0;

   return item->getID();
}


GMFN double SelectGUIComboBoxIndex(double gui_combo_box_ptr, double index)
{
   CEGUI::Combobox *combo_box = ConvertFromGMPointer<CEGUI::Combobox*>(gui_combo_box_ptr);

   if (combo_box == NULL)
      return FALSE;

   combo_box->clearAllSelections();
   combo_box->setItemSelectState(combo_box->getListboxItemFromIndex(index), true);

   return TRUE;
}


bool PerformComboBoxWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
{
   OgreCEGUIWindowData *data = GetGUIWindowData(args.window);
   if (data == NULL)
      return FALSE;

   std::map<std::string, int>::iterator iter = data->m_callback_map.find(std::string(event_name.c_str()));

   if (iter == data->m_callback_map.end())
      return false;

   // Call our GM script to handle this event
   gm::CGMVariable gm_args[2];
   gm_args[0].Set(static_cast<double>(reinterpret_cast<intptr_t>(args.window)));
   CEGUI::Combobox *combo_box = static_cast<CEGUI::Combobox*>(static_cast<const CEGUI::WindowEventArgs&>(args).window);
   gm_args[1].Set(combo_box->getItemIndex(combo_box->getSelectedItem()));
   gm::CGMVariable ret = gm::script_execute(iter->second, gm_args, 2);

   return (ret.real() != 0);
}


bool EventComboBoxItemSelected(const CEGUI::EventArgs &args) { return PerformComboBoxWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Combobox::EventListSelectionAccepted); }


GMFN double SetGUIComboBoxEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Combobox::EventListSelectionAccepted)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventComboBoxItemSelected));

   return TRUE;
}

#endif
