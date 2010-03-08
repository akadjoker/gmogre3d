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

#ifndef GMOGRE_GUI_SPINNER_H
#define GMOGRE_GUI_SPINNER_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUISpinner.h"


GMFN double SetGUISpinnerCurrentValue(double gui_spinner_ptr, double value)
{
   CEGUI::Spinner *spinner = ConvertFromGMPointer<CEGUI::Spinner*>(gui_spinner_ptr);

   if (spinner == NULL)
      return FALSE;

   spinner->setCurrentValue(value);

   return TRUE;
}


GMFN double GetGUISpinnerCurrentValue(double gui_spinner_ptr)
{
   CEGUI::Spinner *spinner = ConvertFromGMPointer<CEGUI::Spinner*>(gui_spinner_ptr);

   if (spinner == NULL)
      return 0;

   return spinner->getCurrentValue();
}


GMFN double SetGUISpinnerMaxValue(double gui_spinner_ptr, double value)
{
   CEGUI::Spinner *spinner = ConvertFromGMPointer<CEGUI::Spinner*>(gui_spinner_ptr);

   if (spinner == NULL)
      return FALSE;

   spinner->setMaximumValue(value);

   return TRUE;
}


GMFN double SetGUISpinnerMinValue(double gui_spinner_ptr, double value)
{
   CEGUI::Spinner *spinner = ConvertFromGMPointer<CEGUI::Spinner*>(gui_spinner_ptr);

   if (spinner == NULL)
      return FALSE;

   spinner->setMinimumValue(value);

   return TRUE;
}


GMFN double SetGUISpinnerStepSize(double gui_spinner_ptr, double step)
{
   CEGUI::Spinner *spinner = ConvertFromGMPointer<CEGUI::Spinner*>(gui_spinner_ptr);

   if (spinner == NULL)
      return FALSE;

   spinner->setStepSize(step);

   return TRUE;
}


GMFN double SetGUISpinnerTextInputMode(double gui_spinner_ptr, double type)
{
   CEGUI::Spinner *spinner = ConvertFromGMPointer<CEGUI::Spinner*>(gui_spinner_ptr);

   if (spinner == NULL)
      return FALSE;

   spinner->setTextInputMode(static_cast<CEGUI::Spinner::TextInputMode>((int)type));

   return TRUE;
}


bool PerformSpinnerWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
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
   gm_args[1].Set(static_cast<CEGUI::Spinner*>(static_cast<const CEGUI::WindowEventArgs&>(args).window)->getCurrentValue());
   gm::CGMVariable ret = gm::script_execute(iter->second, gm_args, 2);

   return (ret.real() != 0);
}


bool EventSpinnerValueChanged(const CEGUI::EventArgs &args) { return PerformSpinnerWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Spinner::EventValueChanged); }


GMFN double SetGUISpinnerEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Spinner::EventValueChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventSpinnerValueChanged));

   return TRUE;
}

#endif
