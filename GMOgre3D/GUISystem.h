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

#ifndef GMOGRE_CEGUI_SYSTEM_H
#define GMOGRE_CEGUI_SYSTEM_H

#include "GMOgre3D.h"

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIFrameWindow.h"


int mKeyboardConversion[256];

void SetupKeyboadConversion()
{
   static bool setup = false;

   if (!setup)
   {
      for (int x = 0; x < 256; x++)
         mKeyboardConversion[x] = 0;

      mKeyboardConversion[8] = CEGUI::Key::Backspace;
      mKeyboardConversion[9] = CEGUI::Key::Tab;
      mKeyboardConversion[13] = CEGUI::Key::Return;
      mKeyboardConversion[16] = CEGUI::Key::LeftShift;
      mKeyboardConversion[17] = CEGUI::Key::LeftControl;
      mKeyboardConversion[18] = CEGUI::Key::LeftAlt;
      mKeyboardConversion[19] = CEGUI::Key::Pause;
    
      mKeyboardConversion[20] = CEGUI::Key::Capital;
      mKeyboardConversion[27] = CEGUI::Key::Escape;
  
      mKeyboardConversion[32] = CEGUI::Key::Space;
      mKeyboardConversion[33] = CEGUI::Key::PageUp;
      mKeyboardConversion[34] = CEGUI::Key::PageDown;
      mKeyboardConversion[35] = CEGUI::Key::End;
      mKeyboardConversion[36] = CEGUI::Key::Home;
      mKeyboardConversion[37] = CEGUI::Key::ArrowLeft;
      mKeyboardConversion[38] = CEGUI::Key::ArrowUp;
      mKeyboardConversion[39] = CEGUI::Key::ArrowRight;
      mKeyboardConversion[40] = CEGUI::Key::ArrowDown;
      
      mKeyboardConversion[45] = CEGUI::Key::Insert;
      mKeyboardConversion[46] = CEGUI::Key::Delete;
      mKeyboardConversion[48] = CEGUI::Key::Zero;
      mKeyboardConversion[49] = CEGUI::Key::One;
      mKeyboardConversion[50] = CEGUI::Key::Two;
      mKeyboardConversion[51] = CEGUI::Key::Three;
      mKeyboardConversion[52] = CEGUI::Key::Four;
      mKeyboardConversion[53] = CEGUI::Key::Five;
      mKeyboardConversion[54] = CEGUI::Key::Six;
      mKeyboardConversion[55] = CEGUI::Key::Seven;
      mKeyboardConversion[56] = CEGUI::Key::Eight;
      mKeyboardConversion[57] = CEGUI::Key::Nine;
      
      mKeyboardConversion[65] = CEGUI::Key::A;
      mKeyboardConversion[66] = CEGUI::Key::B;
      mKeyboardConversion[67] = CEGUI::Key::C;
      mKeyboardConversion[68] = CEGUI::Key::D;
      mKeyboardConversion[69] = CEGUI::Key::E;   
      mKeyboardConversion[70] = CEGUI::Key::F;
      mKeyboardConversion[71] = CEGUI::Key::G;
      mKeyboardConversion[72] = CEGUI::Key::H;
      mKeyboardConversion[73] = CEGUI::Key::I;
      mKeyboardConversion[74] = CEGUI::Key::J;
      mKeyboardConversion[75] = CEGUI::Key::K;
      mKeyboardConversion[76] = CEGUI::Key::L;
      mKeyboardConversion[77] = CEGUI::Key::M;
      mKeyboardConversion[78] = CEGUI::Key::N;
      mKeyboardConversion[79] = CEGUI::Key::O;
      mKeyboardConversion[80] = CEGUI::Key::P;
      mKeyboardConversion[81] = CEGUI::Key::Q;
      mKeyboardConversion[82] = CEGUI::Key::R;
      mKeyboardConversion[83] = CEGUI::Key::S;
      mKeyboardConversion[84] = CEGUI::Key::T;
      mKeyboardConversion[85] = CEGUI::Key::U;
      mKeyboardConversion[86] = CEGUI::Key::V;
      mKeyboardConversion[87] = CEGUI::Key::W;
      mKeyboardConversion[88] = CEGUI::Key::X;
      mKeyboardConversion[89] = CEGUI::Key::Y;
      mKeyboardConversion[90] = CEGUI::Key::Z;
      mKeyboardConversion[91] = CEGUI::Key::LeftWindows;
      
      mKeyboardConversion[96] = CEGUI::Key::Numpad0;
      mKeyboardConversion[97] = CEGUI::Key::Numpad1;
      mKeyboardConversion[98] = CEGUI::Key::Numpad2;
      mKeyboardConversion[99] = CEGUI::Key::Numpad3;
      mKeyboardConversion[100] = CEGUI::Key::Numpad4;
      mKeyboardConversion[101] = CEGUI::Key::Numpad5;
      mKeyboardConversion[102] = CEGUI::Key::Numpad6;
      mKeyboardConversion[103] = CEGUI::Key::Numpad7;
      mKeyboardConversion[104] = CEGUI::Key::Numpad8;
      mKeyboardConversion[105] = CEGUI::Key::Numpad9;
      mKeyboardConversion[106] = CEGUI::Key::Multiply;
      mKeyboardConversion[107] = CEGUI::Key::Add;
      mKeyboardConversion[109] = CEGUI::Key::Subtract;
      mKeyboardConversion[110] = CEGUI::Key::Decimal;
      mKeyboardConversion[111] = CEGUI::Key::Divide;
      mKeyboardConversion[112] = CEGUI::Key::F1;
      mKeyboardConversion[113] = CEGUI::Key::F2;
      mKeyboardConversion[114] = CEGUI::Key::F3;
      mKeyboardConversion[115] = CEGUI::Key::F4;
      mKeyboardConversion[116] = CEGUI::Key::F5;
      mKeyboardConversion[117] = CEGUI::Key::F6;
      mKeyboardConversion[118] = CEGUI::Key::F7;
      mKeyboardConversion[119] = CEGUI::Key::F8;
      mKeyboardConversion[120] = CEGUI::Key::F9;
      mKeyboardConversion[121] = CEGUI::Key::F10;
      mKeyboardConversion[122] = CEGUI::Key::F11;
      mKeyboardConversion[123] = CEGUI::Key::F12;
      
      mKeyboardConversion[144] = CEGUI::Key::NumLock;

      mKeyboardConversion[186] = CEGUI::Key::Semicolon;
      mKeyboardConversion[187] = CEGUI::Key::Equals;
      mKeyboardConversion[188] = CEGUI::Key::Comma;
      mKeyboardConversion[189] = CEGUI::Key::Minus;
      mKeyboardConversion[190] = CEGUI::Key::Period;
      mKeyboardConversion[191] = CEGUI::Key::Slash;
      mKeyboardConversion[192] = CEGUI::Key::Grave;

      mKeyboardConversion[219] = CEGUI::Key::LeftBracket;
      mKeyboardConversion[220] = CEGUI::Key::Backslash;
      mKeyboardConversion[221] = CEGUI::Key::RightBracket;
      mKeyboardConversion[222] = CEGUI::Key::Apostrophe; 

      setup = true;
   }
}


GMFN double InitializeGUI(char *config_name)
{
   if (mSceneMgr == NULL)
      return FALSE;

   CEGUI::System *system = NULL;

   TRY
      if (mGUIRenderer != NULL)
         CEGUI::OgreRenderer::destroySystem();

      Ogre::RenderSystem *rs = Ogre::Root::getSingleton().getRenderSystem();
      Ogre::RenderTarget *rt = rs->getRenderTarget("GMOGRE 3D Window");

      mGUIRenderer = &CEGUI::OgreRenderer::create(*rt);
      CEGUI::OgreResourceProvider *rp = &CEGUI::OgreRenderer::createOgreResourceProvider();
      CEGUI::OgreImageCodec *ic = &CEGUI::OgreRenderer::createOgreImageCodec();
      CEGUI::System::create(*(CEGUI::Renderer*)mGUIRenderer, (CEGUI::ResourceProvider*)rp, (CEGUI::XMLParser*)0, (CEGUI::ImageCodec*)ic, (CEGUI::ScriptModule*)0, config_name, "GMOgre3DGUI.log");
   CATCH("InitializeGUI")

   return TRUE;
}


GMFN double LoadGUIScheme(char *scheme_name)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return 0;

   CEGUI::Scheme *scheme = NULL;

   TRY
      CEGUI::SchemeManager::getSingleton().create(scheme_name);
   CATCH("LoadGUIScheme")

   return ConvertToGMPointer(scheme);
}


GMFN double LoadGUILayout(char *layout_name)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return 0;

   CEGUI::Window *layout = NULL;

   TRY
      layout = CEGUI::WindowManager::getSingleton().loadWindowLayout(layout_name);
   CATCH("LoadGUILayout")

   return ConvertToGMPointer(layout);
}


GMFN double SetGUISheet(double gui_sheet_ptr)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   CEGUI::Window *sheet = ConvertFromGMPointer<CEGUI::Window*>(gui_sheet_ptr);

   if (sheet == NULL)
      return FALSE;

   TRY
      system->setGUISheet(sheet);
   CATCH("SetGUISheet")

   return TRUE;
}


GMFN double CreateGUIFont(char *filename)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   TRY
      CEGUI::FontManager::getSingleton().create(filename);
   CATCH("CreateGUIFont")

   return TRUE;
}


GMFN char *CreateGUITrueTypeFont(char *name, char *filename, double size, double anti_aliased = 1)
{
   TRY
      CEGUI::FontManager::getSingleton().createFreeTypeFont(name, size, (anti_aliased != 0), filename);
   CATCH("CreateGUITrueTypeFont")

   return name;
}


GMFN double SetGUIDefaultFont(char *font_name)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   TRY
      system->setDefaultFont(font_name);
   CATCH("SetGUIDefaultFont")

   return TRUE;
}


GMFN double SetGUIDefaultMouseCursor(char *image_set, char *image_name)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   TRY
      system->setDefaultMouseCursor((CEGUI::utf8*)image_set, (CEGUI::utf8*)image_name);
   CATCH("SetGUIDefaultMouseCursor")

   return TRUE;
}


GMFN double InjectGUIMouseWheelMoved(double delta)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   system->injectMouseWheelChange(delta);

   return TRUE;
}


GMFN double InjectGUIMouseMoved(double x_delta, double y_delta)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   system->injectMouseMove(x_delta, y_delta);

   return TRUE;
}


GMFN double InjectGUIMousePosition(double x, double y)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   system->injectMousePosition(x, y);

   return TRUE;
}


GMFN double InjectGUIMouseButtonPressed(double button)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   system->injectMouseButtonDown(static_cast<CEGUI::MouseButton>((int)button - 1));

   return TRUE;
}


GMFN double InjectGUIMouseButtonReleased(double button)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   system->injectMouseButtonUp(static_cast<CEGUI::MouseButton>((int)button - 1));

   return TRUE;
}


GMFN double InjectGUIKeyPressed(double key)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   SetupKeyboadConversion();

   system->injectKeyDown(static_cast<CEGUI::Key::Scan>(mKeyboardConversion[(int)key]));

   return TRUE;
}


GMFN double InjectGUIKeyReleased(double key)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   SetupKeyboadConversion();

   system->injectKeyUp(static_cast<CEGUI::Key::Scan>(mKeyboardConversion[(int)key]));

   return TRUE;
}


GMFN double InjectGUIChar(char *ch)
{
   CEGUI::System *system = CEGUI::System::getSingletonPtr();

   if (system == NULL)
      return FALSE;

   SetupKeyboadConversion();

   system->injectChar((int)ch[0]);

   return TRUE;
}

#endif
