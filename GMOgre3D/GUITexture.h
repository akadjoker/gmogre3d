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

#ifndef GMOGRE_GUI_TEXTURE_H
#define GMOGRE_GUI_TEXTURE_H

#include "GMOgre3D.h"
#include "GM_API.h"

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "CEGUITexture.h"


GMFN double CreateGUITexture(char *name)
{
   if (mGUIRenderer == NULL)
      return 0;

   CEGUI::Texture *tex = NULL;

   TRY
      tex = &mGUIRenderer->createTexture(name, "");
   CATCH("CreateGUITexture")

   return ConvertToGMPointer(tex);
}


GMFN double DestroyGUITexture(double gui_texture_ptr)
{
   if (mGUIRenderer == NULL)
      return 0;

   CEGUI::Texture *tex = ConvertFromGMPointer<CEGUI::Texture*>(gui_texture_ptr);

   if (tex == NULL)
      return FALSE;

   mGUIRenderer->destroyTexture(*tex);

   return TRUE;
}


GMFN double GetGUITextureWidth(double gui_texture_ptr)
{
   CEGUI::Texture *tex = ConvertFromGMPointer<CEGUI::Texture*>(gui_texture_ptr);

   if (tex == NULL)
      return 0;

   return tex->getSize().d_width;
}


GMFN double GetGUITextureHeight(double gui_texture_ptr)
{
   CEGUI::Texture *tex = ConvertFromGMPointer<CEGUI::Texture*>(gui_texture_ptr);

   if (tex == NULL)
      return 0;

   return tex->getSize().d_height;
}

#endif
