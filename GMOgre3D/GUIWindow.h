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

#ifndef GMOGRE_GUI_WINDOW_H
#define GMOGRE_GUI_WINDOW_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIFrameWindow.h"


int mScanCodeConversion[256];

void SetupScanCodeConversion()
{
   static bool setup = false;

   if (!setup)
   {
      for (int x = 0; x < 256; x++)
         mScanCodeConversion[x] = 0;

      mScanCodeConversion[CEGUI::Key::Escape] = 27;
      mScanCodeConversion[CEGUI::Key::One] = 49;
      mScanCodeConversion[CEGUI::Key::Two] = 50;
      mScanCodeConversion[CEGUI::Key::Three] = 51;
      mScanCodeConversion[CEGUI::Key::Four] = 52;
      mScanCodeConversion[CEGUI::Key::Five] = 53;
      mScanCodeConversion[CEGUI::Key::Six] = 54;
      mScanCodeConversion[CEGUI::Key::Seven] = 55;
      mScanCodeConversion[CEGUI::Key::Eight] = 56;
      mScanCodeConversion[CEGUI::Key::Nine] = 57;
      mScanCodeConversion[CEGUI::Key::Zero] = 48;
      mScanCodeConversion[CEGUI::Key::Minus] = 189;
      mScanCodeConversion[CEGUI::Key::Equals] = 187;
      mScanCodeConversion[CEGUI::Key::Backspace] = 8;
      mScanCodeConversion[CEGUI::Key::Tab] = 9;
      mScanCodeConversion[CEGUI::Key::Q] = 81;
      mScanCodeConversion[CEGUI::Key::W] = 87;
      mScanCodeConversion[CEGUI::Key::E] = 69;
      mScanCodeConversion[CEGUI::Key::R] = 82;
      mScanCodeConversion[CEGUI::Key::T] = 84;
      mScanCodeConversion[CEGUI::Key::Y] = 89;
      mScanCodeConversion[CEGUI::Key::U] = 85;
      mScanCodeConversion[CEGUI::Key::I] = 73;
      mScanCodeConversion[CEGUI::Key::O] = 79;
      mScanCodeConversion[CEGUI::Key::P] = 80;
      mScanCodeConversion[CEGUI::Key::LeftBracket] = 219;
      mScanCodeConversion[CEGUI::Key::RightBracket] = 221;
      mScanCodeConversion[CEGUI::Key::Return] = 13;
      mScanCodeConversion[CEGUI::Key::LeftControl] = 17;
      mScanCodeConversion[CEGUI::Key::A] = 65;
      mScanCodeConversion[CEGUI::Key::S] = 83;
      mScanCodeConversion[CEGUI::Key::D] = 68;
      mScanCodeConversion[CEGUI::Key::F] = 70;
      mScanCodeConversion[CEGUI::Key::G] = 71;
      mScanCodeConversion[CEGUI::Key::H] = 72;
      mScanCodeConversion[CEGUI::Key::J] = 74;
      mScanCodeConversion[CEGUI::Key::K] = 75;
      mScanCodeConversion[CEGUI::Key::L] = 76;
      mScanCodeConversion[CEGUI::Key::Semicolon] = 186;
      mScanCodeConversion[CEGUI::Key::Apostrophe] = 222;
      mScanCodeConversion[CEGUI::Key::Grave] = 192;
      mScanCodeConversion[CEGUI::Key::LeftShift] = 16;
      mScanCodeConversion[CEGUI::Key::Backslash] = 220;
      mScanCodeConversion[CEGUI::Key::Z] = 90;
      mScanCodeConversion[CEGUI::Key::X] = 88;
      mScanCodeConversion[CEGUI::Key::C] = 67;
      mScanCodeConversion[CEGUI::Key::V] = 86;
      mScanCodeConversion[CEGUI::Key::B] = 66;
      mScanCodeConversion[CEGUI::Key::N] = 78;
      mScanCodeConversion[CEGUI::Key::M] = 77;
      mScanCodeConversion[CEGUI::Key::Comma] = 188;
      mScanCodeConversion[CEGUI::Key::Period] = 190;
      mScanCodeConversion[CEGUI::Key::Slash] = 191;
      mScanCodeConversion[CEGUI::Key::Multiply] = 106;
      mScanCodeConversion[CEGUI::Key::LeftAlt] = 18;
      mScanCodeConversion[CEGUI::Key::Space] = 32;
      mScanCodeConversion[CEGUI::Key::Capital] = 20;
      mScanCodeConversion[CEGUI::Key::F1] = 112;
      mScanCodeConversion[CEGUI::Key::F2] = 113;
      mScanCodeConversion[CEGUI::Key::F3] = 114;
      mScanCodeConversion[CEGUI::Key::F4] = 115;
      mScanCodeConversion[CEGUI::Key::F5] = 116;
      mScanCodeConversion[CEGUI::Key::F6] = 117;
      mScanCodeConversion[CEGUI::Key::F7] = 118;
      mScanCodeConversion[CEGUI::Key::F8] = 119;
      mScanCodeConversion[CEGUI::Key::F9] = 120;
      mScanCodeConversion[CEGUI::Key::F10] = 121;
      mScanCodeConversion[CEGUI::Key::NumLock] = 144;
      mScanCodeConversion[CEGUI::Key::Numpad7] = 103;
      mScanCodeConversion[CEGUI::Key::Numpad8] = 104;
      mScanCodeConversion[CEGUI::Key::Numpad9] = 105;
      mScanCodeConversion[CEGUI::Key::Subtract] = 109;
      mScanCodeConversion[CEGUI::Key::Numpad4] = 100;
      mScanCodeConversion[CEGUI::Key::Numpad5] = 101;
      mScanCodeConversion[CEGUI::Key::Numpad6] = 102;
      mScanCodeConversion[CEGUI::Key::Add] = 107;
      mScanCodeConversion[CEGUI::Key::Numpad1] = 97;
      mScanCodeConversion[CEGUI::Key::Numpad2] = 98;
      mScanCodeConversion[CEGUI::Key::Numpad3] = 99;
      mScanCodeConversion[CEGUI::Key::Numpad0] = 96;
      mScanCodeConversion[CEGUI::Key::Decimal] = 110;
      mScanCodeConversion[CEGUI::Key::F11] = 122;
      mScanCodeConversion[CEGUI::Key::F12] = 123;
      mScanCodeConversion[CEGUI::Key::Divide] = 111;
      mScanCodeConversion[CEGUI::Key::Pause] = 19;
      mScanCodeConversion[CEGUI::Key::Home] = 36;
      mScanCodeConversion[CEGUI::Key::ArrowUp] = 38;
      mScanCodeConversion[CEGUI::Key::PageUp] = 33;
      mScanCodeConversion[CEGUI::Key::ArrowLeft] = 37;
      mScanCodeConversion[CEGUI::Key::ArrowRight] = 39;
      mScanCodeConversion[CEGUI::Key::End] = 35;
      mScanCodeConversion[CEGUI::Key::ArrowDown] = 40;
      mScanCodeConversion[CEGUI::Key::PageDown] = 34;
      mScanCodeConversion[CEGUI::Key::Insert] = 45;
      mScanCodeConversion[CEGUI::Key::Delete] = 46;
      mScanCodeConversion[CEGUI::Key::LeftWindows] = 91;

      setup = true;
   }
}

struct OgreCEGUIWindowData
{
   void *m_userdata;
   Ogre::GuiMetricsMode m_metrics_mode;
   Ogre::String m_selection_brush_imageset;
   Ogre::String m_selection_brush_image;
   std::map<std::string, int> m_callback_map;
};


bool GUIWindowDestructionStarted(const CEGUI::EventArgs &args)
{
   const CEGUI::WindowEventArgs &window_args = static_cast<const CEGUI::WindowEventArgs&>(args);
   
   OgreCEGUIWindowData *data = (OgreCEGUIWindowData *)window_args.window->getUserData();

   if (data != NULL)
   {
      delete data;
      window_args.window->setUserData(NULL);
   }

   return true;
}


OgreCEGUIWindowData *GetGUIWindowData(CEGUI::Window *win)
{
   OgreCEGUIWindowData *data = (OgreCEGUIWindowData *)win->getUserData();
   
   if (data == NULL)
   {
      data = OGRE_NEW OgreCEGUIWindowData;
      data->m_metrics_mode = Ogre::GMM_PIXELS;
      win->setUserData(data);

      win->subscribeEvent(CEGUI::Window::EventDestructionStarted, CEGUI::Event::Subscriber(&GUIWindowDestructionStarted));
   }

   return data;
}


void DestroyGUIWindowData(CEGUI::Window *win)
{
   OgreCEGUIWindowData *data = (OgreCEGUIWindowData *)win->getUserData();

   if (data != NULL)
   {
      delete data;
      win->setUserData(NULL);
   }
}


GMFN double GetGUIWindowByName(char *name)
{
   CEGUI::WindowManager *win_mgr = CEGUI::WindowManager::getSingletonPtr();
   CEGUI::Window *win = win_mgr->getWindow(name);

   return ConvertToGMPointer(win);
}


GMFN double CreateGUIWindow(char *type, char *name)
{
   if (mSceneMgr == NULL)
      return FALSE;

   CEGUI::Window *win = NULL;

   TRY
      CEGUI::WindowManager *win_mgr = CEGUI::WindowManager::getSingletonPtr();
      win = win_mgr->createWindow(type, name);
      GetGUIWindowData(win);
   CATCH("CreateGUIWindow")

   return ConvertToGMPointer(win);
}


GMFN double DestroyGUIWindow(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   DestroyGUIWindowData(win);

   CEGUI::WindowManager *win_mgr = CEGUI::WindowManager::getSingletonPtr();
   win_mgr->destroyWindow(win);

   return TRUE;
}


GMFN char *GetGUIWindowName(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return "";

   static CEGUI::String text = win->getName();

   return (char*)text.c_str();
}


GMFN double SetGUIWindowText(double gui_window_ptr, char *text)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   win->setText(text);

   return TRUE;
}


GMFN char *GetGUIWindowText(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return "";

   static CEGUI::String text;
   
   text = win->getText();

   return (char*)text.c_str();
}


GMFN double SetGUIWindowMetricsMode(double gui_window_ptr, double type)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_metrics_mode = static_cast<Ogre::GuiMetricsMode>((int)type);

   return TRUE;
}


GMFN double SetGUIWindowPosition(double gui_window_ptr, double x, double y)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   if (data->m_metrics_mode == Ogre::GMM_RELATIVE)
      win->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
   else
      win->setPosition(CEGUI::UVector2(cegui_absdim(x), cegui_absdim(y)));

   return TRUE;
}


GMFN double GetGUIWindowPosition(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   Ogre::Vector3 vec;
   
   if (data->m_metrics_mode == Ogre::GMM_RELATIVE)
   {
      vec.x = win->getXPosition().d_scale;
      vec.y = 0;
      vec.z = win->getYPosition().d_scale;
   }
   else
   {
      vec.x = win->getXPosition().d_offset;
      vec.y = 0;
      vec.z = win->getYPosition().d_offset;
   }

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double SetGUIWindowSize(double gui_window_ptr, double width, double height)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   if (data->m_metrics_mode == Ogre::GMM_RELATIVE)
      win->setSize(CEGUI::UVector2(cegui_reldim(width), cegui_reldim(height)));
   else
      win->setSize(CEGUI::UVector2(cegui_absdim(width), cegui_absdim(height)));

   return TRUE;
}


GMFN double GetGUIWindowSize(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   Ogre::Vector3 vec;
   
   if (data->m_metrics_mode == Ogre::GMM_RELATIVE)
   {
      vec.x = win->getWidth().d_scale;
      vec.y = 0;
      vec.z = win->getHeight().d_scale;
   }
   else
   {
      vec.x = win->getWidth().d_offset;
      vec.y = 0;
      vec.z = win->getHeight().d_offset;
   }

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double SetGUIWindowProperty(double gui_window_ptr, char *name, char *value)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   win->setProperty(name, value);

   return TRUE;
}


GMFN char *GetGUIWindowProperty(double gui_window_ptr, char *name)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return "";

   static CEGUI::String text = win->getProperty(name);

   return (char*)text.c_str();
}


GMFN double SetGUIWindowTooltipText(double gui_window_ptr, char *tip)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   win->setTooltipText(tip);

   return TRUE;
}


GMFN double SetGUIWindowAlpha(double gui_window_ptr, double alpha)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   win->setAlpha(alpha);

   return TRUE;
}


GMFN double SetGUIWindowID(double gui_window_ptr, double id)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   win->setID(id);

   return TRUE;
}


GMFN double GetGUIWindowID(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return 0;

   return win->getID();
}


GMFN double AddGUIWindowChildWindow(double gui_window_ptr, double gui_child_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   CEGUI::Window *child_win = ConvertFromGMPointer<CEGUI::Window*>(gui_child_window_ptr);

   if (child_win == NULL)
      return FALSE;

   win->addChildWindow(child_win);

   return TRUE;
}


GMFN double RemoveGUIWindowChildWindow(double gui_window_ptr, double gui_child_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   CEGUI::Window *child_win = ConvertFromGMPointer<CEGUI::Window*>(gui_child_window_ptr);

   if (child_win == NULL)
      return FALSE;

   win->removeChildWindow(child_win);

   return TRUE;
}


GMFN double GetGUIWindowChildWindowCount(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   return win->getChildCount();
}


GMFN double GetGUIWindowChildWindowAtIndex(double gui_window_ptr, double index)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   CEGUI::Window *child_win = win->getChildAtIdx(index);

   return ConvertToGMPointer(child_win);
}


GMFN double SetGUIWindowHorizontalAlignment(double gui_window_ptr, double alignment)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   CEGUI::HorizontalAlignment horiz;
   if (alignment == 2)
      horiz = CEGUI::HA_CENTRE;
   else if (alignment == 1)
      horiz = CEGUI::HA_RIGHT;
   else
      horiz = CEGUI::HA_LEFT;

   win->setHorizontalAlignment(horiz);

   return TRUE;
}


GMFN double SetGUIWindowVerticalAlignment(double gui_window_ptr, double alignment)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   CEGUI::VerticalAlignment vert;
   if (alignment == 0)
      vert = CEGUI::VA_BOTTOM;
   else if (alignment == 2)
      vert = CEGUI::VA_CENTRE;
   else
      vert = CEGUI::VA_TOP;

   win->setVerticalAlignment(vert);

   return TRUE;
}


GMFN double ShowGUIWindow(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   win->show();

   return TRUE;
}


GMFN double HideGUIWindow(double gui_window_ptr)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   win->hide();

   return TRUE;
}


GMFN double ActivateGUIWindow(double gui_window_ptr, double activate)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   if (activate != 0)
      win->activate();
   else
      win->deactivate();

   return TRUE;
}


GMFN double EnableGUIWindow(double gui_window_ptr, double enable)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   win->setEnabled((enable != 0));

   return TRUE;
}


bool PerformGUIWindowWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
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


bool PerformGUIWindowActivationEventCallback(const CEGUI::ActivationEventArgs& args, CEGUI::String event_name)
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
   gm_args[1].Set(static_cast<double>(reinterpret_cast<intptr_t>(args.otherWindow)));
   gm::CGMVariable ret = gm::script_execute(iter->second, gm_args, 2);

   return (ret.real() != 0);
}


bool PerformGUIWindowDragDropEventCallback(const CEGUI::DragDropEventArgs& args, CEGUI::String event_name)
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
   gm_args[1].Set(static_cast<double>(reinterpret_cast<intptr_t>(args.dragDropItem)));
   gm::CGMVariable ret = gm::script_execute(iter->second, gm_args, 2);

   return (ret.real() != 0);
}


bool PerformGUIWindowMouseEventCallback(const CEGUI::MouseEventArgs& args, CEGUI::String event_name)
{
   OgreCEGUIWindowData *data = GetGUIWindowData(args.window);
   if (data == NULL)
      return FALSE;

   std::map<std::string, int>::iterator iter = data->m_callback_map.find(std::string(event_name.c_str()));

   if (iter == data->m_callback_map.end())
      return false;

   // Call our GM script to handle this event
   gm::CGMVariable gm_args[6];
   gm_args[0].Set(static_cast<double>(reinterpret_cast<intptr_t>(args.window)));
   gm_args[1].Set(static_cast<double>(args.button));
   gm_args[2].Set(static_cast<double>(args.clickCount));
   gm_args[3].Set(static_cast<double>(args.position.d_x));
   gm_args[4].Set(static_cast<double>(args.position.d_y));
   gm_args[5].Set(static_cast<double>(args.wheelChange));
   gm::CGMVariable ret = gm::script_execute(iter->second, gm_args, 6);

   return (ret.real() != 0);
}


bool PerformGUIWindowKeyEventCallback(const CEGUI::KeyEventArgs& args, CEGUI::String event_name)
{
   OgreCEGUIWindowData *data = GetGUIWindowData(args.window);
   if (data == NULL)
      return FALSE;

   std::map<std::string, int>::iterator iter = data->m_callback_map.find(std::string(event_name.c_str()));

   if (iter == data->m_callback_map.end())
      return false;

   SetupScanCodeConversion();

   // Call our GM script to handle this event
   gm::CGMVariable gm_args[3];
   gm_args[0].Set(static_cast<double>(reinterpret_cast<intptr_t>(args.window)));
   gm_args[1].Set(static_cast<double>(mScanCodeConversion[args.scancode]));
   gm_args[2].Set(static_cast<double>(args.codepoint));
   gm::CGMVariable ret = gm::script_execute(iter->second, gm_args, 3);

   return (ret.real() != 0);
}


bool GUIWindowEventParentSized(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventParentSized); }
bool GUIWindowEventSized(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventSized); }
bool GUIWindowEventMoved(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventMoved); }
bool GUIWindowEventTextChanged(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventTextChanged); }
bool GUIWindowEventFontChanged(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventFontChanged); }
bool GUIWindowEventAlphaChanged(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventAlphaChanged); }
bool GUIWindowEventActivated(const CEGUI::EventArgs &args) { return PerformGUIWindowActivationEventCallback(static_cast<const CEGUI::ActivationEventArgs&>(args), CEGUI::Window::EventActivated); }
bool GUIWindowEventDeactivated(const CEGUI::EventArgs &args) { return PerformGUIWindowActivationEventCallback(static_cast<const CEGUI::ActivationEventArgs&>(args), CEGUI::Window::EventDeactivated); }
bool GUIWindowEventShown(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventShown); }
bool GUIWindowEventHidden(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventHidden); }
bool GUIWindowEventEnabled(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventEnabled); }
bool GUIWindowEventDisabled(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventDisabled); }
bool GUIWindowEventInputCaptureGained(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventInputCaptureGained); }
bool GUIWindowEventInputCaptureLost(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventInputCaptureLost); }
bool GUIWindowEventRenderingStarted(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventRenderingStarted); }
bool GUIWindowEventRenderingEnded(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventRenderingEnded); }
bool GUIWindowEventChildAdded(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventChildAdded); }
bool GUIWindowEventChildRemoved(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventChildRemoved); }
bool GUIWindowEventZOrderChanged(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventZOrderChanged); }
bool GUIWindowEventDragDropItemEnters(const CEGUI::EventArgs &args) { return PerformGUIWindowDragDropEventCallback(static_cast<const CEGUI::DragDropEventArgs&>(args), CEGUI::Window::EventDragDropItemEnters); }
bool GUIWindowEventDragDropItemLeaves(const CEGUI::EventArgs &args) { return PerformGUIWindowDragDropEventCallback(static_cast<const CEGUI::DragDropEventArgs&>(args), CEGUI::Window::EventDragDropItemLeaves); }
bool GUIWindowEventDragDropItemDropped(const CEGUI::EventArgs &args) { return PerformGUIWindowDragDropEventCallback(static_cast<const CEGUI::DragDropEventArgs&>(args), CEGUI::Window::EventDragDropItemDropped); }
bool GUIWindowEventVerticalAlignmentChanged(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventVerticalAlignmentChanged); }
bool GUIWindowEventHorizontalAlignmentChanged(const CEGUI::EventArgs &args) { return PerformGUIWindowWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::Window::EventHorizontalAlignmentChanged); }
bool GUIWindowEventMouseEnters(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args), CEGUI::Window::EventMouseEnters); }
bool GUIWindowEventMouseLeaves(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args), CEGUI::Window::EventMouseLeaves); }
bool GUIWindowEventMouseMove(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args), CEGUI::Window::EventMouseMove); }
bool GUIWindowEventMouseWheel(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args), CEGUI::Window::EventMouseWheel); }
bool GUIWindowEventMouseButtonDown(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args).window, CEGUI::Window::EventMouseButtonDown); }
bool GUIWindowEventMouseButtonUp(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args), CEGUI::Window::EventMouseButtonUp); }
bool GUIWindowEventMouseClick(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args), CEGUI::Window::EventMouseClick); }
bool GUIWindowEventMouseDoubleClick(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args), CEGUI::Window::EventMouseDoubleClick); }
bool GUIWindowEventMouseTripleClick(const CEGUI::EventArgs &args) { return PerformGUIWindowMouseEventCallback(static_cast<const CEGUI::MouseEventArgs&>(args), CEGUI::Window::EventMouseTripleClick); }
bool GUIWindowEventKeyDown(const CEGUI::EventArgs &args) { return PerformGUIWindowKeyEventCallback(static_cast<const CEGUI::KeyEventArgs&>(args), CEGUI::Window::EventKeyDown); }
bool GUIWindowEventKeyUp(const CEGUI::EventArgs &args) { return PerformGUIWindowKeyEventCallback(static_cast<const CEGUI::KeyEventArgs&>(args), CEGUI::Window::EventKeyUp); }
bool GUIWindowEventCharacterKey(const CEGUI::EventArgs &args) { return PerformGUIWindowKeyEventCallback(static_cast<const CEGUI::KeyEventArgs&>(args), CEGUI::Window::EventCharacterKey); }

/*
GMFN double SetGUIWindowWindowEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Window::EventParentSized)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventParentSized));
   else if (evt_name == CEGUI::Window::EventSized)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventSized));
   else if (evt_name == CEGUI::Window::EventMoved)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMoved));
   else if (evt_name == CEGUI::Window::EventTextChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventTextChanged));
   else if (evt_name == CEGUI::Window::EventFontChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventFontChanged));
   else if (evt_name == CEGUI::Window::EventAlphaChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventAlphaChanged));
   else if (evt_name == CEGUI::Window::EventShown)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventShown));
   else if (evt_name == CEGUI::Window::EventHidden)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventHidden));
   else if (evt_name == CEGUI::Window::EventEnabled)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventEnabled));
   else if (evt_name == CEGUI::Window::EventDisabled)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDisabled));
   else if (evt_name == CEGUI::Window::EventInputCaptureGained)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventInputCaptureGained));
   else if (evt_name == CEGUI::Window::EventInputCaptureLost)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventInputCaptureLost));
   else if (evt_name == CEGUI::Window::EventRenderingStarted)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventRenderingStarted));
   else if (evt_name == CEGUI::Window::EventRenderingEnded)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventRenderingEnded));
   else if (evt_name == CEGUI::Window::EventChildAdded)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventChildAdded));
   else if (evt_name == CEGUI::Window::EventChildRemoved)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventChildRemoved));
   else if (evt_name == CEGUI::Window::EventZOrderChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventZOrderChanged));
   else if (evt_name == CEGUI::Window::EventVerticalAlignmentChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventVerticalAlignmentChanged));
   else if (evt_name == CEGUI::Window::EventHorizontalAlignmentChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventHorizontalAlignmentChanged));

   return TRUE;
}


GMFN double SetGUIWindowActivationEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Window::EventActivated)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventActivated));
   else if (evt_name == CEGUI::Window::EventDeactivated)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDeactivated));

   return TRUE;
}


GMFN double SetGUIWindowDragDropEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Window::EventDragDropItemEnters)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDragDropItemEnters));
   else if (evt_name == CEGUI::Window::EventDragDropItemLeaves)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDragDropItemLeaves));
   else if (evt_name == CEGUI::Window::EventDragDropItemDropped)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDragDropItemDropped));

   return TRUE;
}


GMFN double SetGUIWindowMouseEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Window::EventMouseEnters)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseEnters));
   else if (evt_name == CEGUI::Window::EventMouseLeaves)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseLeaves));
   else if (evt_name == CEGUI::Window::EventMouseMove)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseMove));
   else if (evt_name == CEGUI::Window::EventMouseWheel)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseWheel));
   else if (evt_name == CEGUI::Window::EventMouseButtonDown)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseButtonDown));
   else if (evt_name == CEGUI::Window::EventMouseButtonUp)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseButtonUp));
   else if (evt_name == CEGUI::Window::EventMouseClick)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseClick));
   else if (evt_name == CEGUI::Window::EventMouseDoubleClick)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseDoubleClick));
   else if (evt_name == CEGUI::Window::EventMouseTripleClick)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseTripleClick));

   return TRUE;
}


GMFN double SetGUIWindowKeyEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Window::EventKeyDown)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventKeyDown));
   else if (evt_name == CEGUI::Window::EventKeyUp)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventKeyUp));
   else if (evt_name == CEGUI::Window::EventCharacterKey)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventCharacterKey));   

   return TRUE;
}
*/


GMFN double SetGUIWindowEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::Window::EventParentSized)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventParentSized));
   else if (evt_name == CEGUI::Window::EventSized)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventSized));
   else if (evt_name == CEGUI::Window::EventMoved)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMoved));
   else if (evt_name == CEGUI::Window::EventTextChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventTextChanged));
   else if (evt_name == CEGUI::Window::EventFontChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventFontChanged));
   else if (evt_name == CEGUI::Window::EventAlphaChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventAlphaChanged));
   else if (evt_name == CEGUI::Window::EventShown)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventShown));
   else if (evt_name == CEGUI::Window::EventHidden)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventHidden));
   else if (evt_name == CEGUI::Window::EventEnabled)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventEnabled));
   else if (evt_name == CEGUI::Window::EventDisabled)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDisabled));
   else if (evt_name == CEGUI::Window::EventInputCaptureGained)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventInputCaptureGained));
   else if (evt_name == CEGUI::Window::EventInputCaptureLost)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventInputCaptureLost));
   else if (evt_name == CEGUI::Window::EventRenderingStarted)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventRenderingStarted));
   else if (evt_name == CEGUI::Window::EventRenderingEnded)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventRenderingEnded));
   else if (evt_name == CEGUI::Window::EventChildAdded)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventChildAdded));
   else if (evt_name == CEGUI::Window::EventChildRemoved)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventChildRemoved));
   else if (evt_name == CEGUI::Window::EventZOrderChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventZOrderChanged));
   else if (evt_name == CEGUI::Window::EventVerticalAlignmentChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventVerticalAlignmentChanged));
   else if (evt_name == CEGUI::Window::EventHorizontalAlignmentChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventHorizontalAlignmentChanged));
   else if (evt_name == CEGUI::Window::EventKeyDown)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventKeyDown));
   else if (evt_name == CEGUI::Window::EventKeyUp)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventKeyUp));
   else if (evt_name == CEGUI::Window::EventCharacterKey)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventCharacterKey));
   else if (evt_name == CEGUI::Window::EventMouseEnters)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseEnters));
   else if (evt_name == CEGUI::Window::EventMouseLeaves)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseLeaves));
   else if (evt_name == CEGUI::Window::EventMouseMove)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseMove));
   else if (evt_name == CEGUI::Window::EventMouseWheel)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseWheel));
   else if (evt_name == CEGUI::Window::EventMouseButtonDown)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseButtonDown));
   else if (evt_name == CEGUI::Window::EventMouseButtonUp)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseButtonUp));
   else if (evt_name == CEGUI::Window::EventMouseClick)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseClick));
   else if (evt_name == CEGUI::Window::EventMouseDoubleClick)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseDoubleClick));
   else if (evt_name == CEGUI::Window::EventMouseTripleClick)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventMouseTripleClick));
   else if (evt_name == CEGUI::Window::EventActivated)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventActivated));
   else if (evt_name == CEGUI::Window::EventDeactivated)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDeactivated));
   else if (evt_name == CEGUI::Window::EventDragDropItemEnters)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDragDropItemEnters));
   else if (evt_name == CEGUI::Window::EventDragDropItemLeaves)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDragDropItemLeaves));
   else if (evt_name == CEGUI::Window::EventDragDropItemDropped)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&GUIWindowEventDragDropItemDropped));

   return TRUE;
}

#endif
