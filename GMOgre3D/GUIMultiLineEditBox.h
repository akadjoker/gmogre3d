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

#ifndef GMOGRE_GUI_MULTI_LINE_EDIT_BOX_H
#define GMOGRE_GUI_MULTI_LINE_EDIT_BOX_H

#include "GMOgre3D.h"
#include "GM_API.h"

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIMultiLineEditBox.h"


GMFN double SetGUIMultiLineEditBoxMaxTextLength(double gui_edit_box_ptr, double max_length)
{
   CEGUI::MultiLineEditbox *edit_box = ConvertFromGMPointer<CEGUI::MultiLineEditbox*>(gui_edit_box_ptr);

   if (edit_box == NULL)
      return FALSE;

   edit_box->setMaxTextLength(max_length);

   return TRUE;
}


GMFN double EnableGUIMultiLineEditBoxReadOnly(double gui_edit_box_ptr, double enable)
{
   CEGUI::MultiLineEditbox *edit_box = ConvertFromGMPointer<CEGUI::MultiLineEditbox*>(gui_edit_box_ptr);

   if (edit_box == NULL)
      return FALSE;

   edit_box->setReadOnly((enable != 0));

   return TRUE;
}


GMFN double EnableGUIMultiLineEditBoxWordWrapping(double gui_edit_box_ptr, double enable)
{
   CEGUI::MultiLineEditbox *edit_box = ConvertFromGMPointer<CEGUI::MultiLineEditbox*>(gui_edit_box_ptr);

   if (edit_box == NULL)
      return FALSE;

   edit_box->setWordWrapping((enable != 0));

   return TRUE;
}


GMFN double ShowGUIMultiLineEditBoxVertScrollbarAlways(double gui_edit_box_ptr, double show_always)
{
   CEGUI::MultiLineEditbox *edit_box = ConvertFromGMPointer<CEGUI::MultiLineEditbox*>(gui_edit_box_ptr);

   if (edit_box == NULL)
      return FALSE;

   edit_box->setShowVertScrollbar((show_always != 0));

   return TRUE;
}

/*
bool PerformMultiLineEditBoxWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
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


bool EventMultiLineEditBoxTextAccepted(const CEGUI::EventArgs &args) { return PerformMultiLineEditBoxWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::MultiLineEditbox::EventTextAccepted); }


GMFN double SetGUIEditBoxEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::MultiLineEditbox::EventTextAccepted)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventMultiLineEditBoxTextAccepted));

   return TRUE;
}
*/
#endif
