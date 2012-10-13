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

#ifndef GMOGRE_GUI_CHECK_BOX_H
#define GMOGRE_GUI_CHECK_BOX_H

#include "GMOgre3D.h"
#include "GM_API.h"

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUICheckBox.h"


GMFN double SetGUICheckBoxSelected(double gui_check_box_ptr, double selected)
{
   CEGUI::Checkbox *check_box = ConvertFromGMPointer<CEGUI::Checkbox*>(gui_check_box_ptr);

   if (check_box == NULL)
      return FALSE;

   check_box->setSelected((selected != 0));

   return TRUE;
}


GMFN double IsGUICheckBoxSelected(double gui_check_box_ptr)
{
   CEGUI::Checkbox *check_box = ConvertFromGMPointer<CEGUI::Checkbox*>(gui_check_box_ptr);

   if (check_box == NULL)
      return FALSE;

   return check_box->isSelected();
}


bool PerformCheckBoxWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
{
   OgreCEGUIWindowData *data = GetGUIWindowData(args.window);
   if (data == NULL)
      return FALSE;

   std::map<std::string, int>::iterator iter = data->m_callback_map.find(std::string(event_name.c_str()));

   if (iter == data->m_callback_map.end())
      return false;

   // Call our GM script to handle this event
   GM_VALUE ret = GM_script_execute(iter->second, static_cast<double>(reinterpret_cast<intptr_t>(args.window)), static_cast<CEGUI::Checkbox*>(static_cast<const CEGUI::WindowEventArgs&>(args).window)->isSelected());

   return (GetGMRealValue(ret) != 0);
}


bool EventCheckBoxStateChanged(const CEGUI::EventArgs &args) { return PerformCheckBoxWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Checkbox::EventCheckStateChanged); }


GMFN double SetGUICheckBoxEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Checkbox::EventCheckStateChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventCheckBoxStateChanged));

   return TRUE;
}

#endif
