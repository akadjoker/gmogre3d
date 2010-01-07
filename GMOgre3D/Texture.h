/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2009 Robert Geiman
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

#ifndef GMOGRE_TEXTURE_H
#define GMOGRE_TEXTURE_H

#include "GMOgre3D.h"


static Ogre::String tex_name;
static Ogre::String tex_group;
static double tex_type;


GMFN char *GetTextureByName(char *name)
{
   // This is just a convienence function to allow users to use the same
   // standard for retrieving script objects (fonts, materials, overlay, etc)
   // the same way.  In this case the ID really IS the name, but for other
   // script types it may be an actual object pointer.

   return name;
}


GMFN double CreateTexture1(char *name, char *group, double type)
{
   tex_name = name;
   tex_group = group;
   tex_type = type;

   return TRUE;
}


GMFN char *CreateTexture2(double width, double height, double depth, double num_mips, double pixel_format, double usage = Ogre::TU_DEFAULT)
{
   TRY
      Ogre::TextureManager::getSingleton().createManual(tex_name, tex_group, static_cast<Ogre::TextureType>((int)tex_type), width, height, num_mips, static_cast<Ogre::PixelFormat>((int)pixel_format), static_cast<Ogre::TextureUsage>((int)usage));
   CATCH("CreateTexture")

   return const_cast<char*>(tex_name.c_str());
}


GMFN double DestroyTexture(char *name)
{
   Ogre::TextureManager::getSingleton().remove(name);

   return TRUE;
}


GMFN double LoadTexture(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return FALSE;
   
   tex->load();

   return TRUE;
}


GMFN double UnloadTexture(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return FALSE;
   
   tex->unload();

   return TRUE;
}


GMFN double CreateTextureViewport(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);

   if (tex.isNull())
      return NULL;

   Ogre::RenderTexture *render_tex = NULL;
   Ogre::Viewport *view = NULL;

   TRY
      render_tex = tex->getBuffer()->getRenderTarget();

      if (render_tex == NULL)
         return NULL;

      view = render_tex->addViewport(NULL);

      if (view == NULL)
         return NULL;

      view->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.0f));
   CATCH("CreateTextureViewport")

   return ConvertToGMPointer(view);
}


GMFN double GetTextureWidth(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return 0;

   return tex->getWidth();
}


GMFN double GetTextureHeight(char *name)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return 0;

   return tex->getHeight();
}


GMFN double SetTextureFSAA(char *name, double fsaa)
{
   Ogre::TexturePtr tex = Ogre::TextureManager::getSingleton().getByName(name);
   
   if (tex.isNull())
      return NULL;

   tex->setFSAA(fsaa);

   return TRUE;
}

#endif
