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

#ifndef GMOGRE_GUI_SLIDER_H
#define GMOGRE_GUI_SLIDER_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUISlider.h"


GMFN double SetGUISliderCurrentValue(double gui_slider_ptr, double value)
{
   CEGUI::Slider *slider = ConvertFromGMPointer<CEGUI::Slider*>(gui_slider_ptr);

   if (slider == NULL)
      return FALSE;

   slider->setCurrentValue(value);

   return TRUE;
}


GMFN double GetGUISliderCurrentValue(double gui_slider_ptr)
{
   CEGUI::Slider *slider = ConvertFromGMPointer<CEGUI::Slider*>(gui_slider_ptr);

   if (slider == NULL)
      return 0;

   return slider->getCurrentValue();
}


GMFN double SetGUISliderMaxValue(double gui_slider_ptr, double value)
{
   CEGUI::Slider *slider = ConvertFromGMPointer<CEGUI::Slider*>(gui_slider_ptr);

   if (slider == NULL)
      return FALSE;

   slider->setMaxValue(value);

   return TRUE;
}


GMFN double SetGUISliderClickStepSize(double gui_slider_ptr, double step)
{
   CEGUI::Slider *slider = ConvertFromGMPointer<CEGUI::Slider*>(gui_slider_ptr);

   if (slider == NULL)
      return FALSE;

   slider->setClickStep(step);

   return TRUE;
}


bool PerformSliderWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
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
   gm_args[1].Set(static_cast<CEGUI::Slider*>(static_cast<const CEGUI::WindowEventArgs&>(args).window)->getCurrentValue());
   gm::CGMVariable ret = gm::script_execute(iter->second, gm_args, 2);

   return (ret.real() != 0);
}


bool EventSliderValueChanged(const CEGUI::EventArgs &args) { return PerformSliderWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Slider::EventValueChanged); }


GMFN double SetGUISliderEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Slider::EventValueChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventSliderValueChanged));

   return TRUE;
}

#endif
