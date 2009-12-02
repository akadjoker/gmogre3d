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

#ifndef GMOGRE_FONT_H
#define GMOGRE_FONT_H

#include "GMOgre3D.h"


GMFN char *GetFontByName(char *name)
{
   // This is just a convienence function to allow users to use the same
   // standard for retrieving script objects (fonts, materials, overlay, etc)
   // the same way.  In this case the ID really IS the name, but for other
   // script types it may be an actual object pointer.

   return name;
}


GMFN char *CreateGMFont(char *name, char *group = const_cast<char*>(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str()), char *font_source = "", double size = 12)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().create(name, group);
   font->setParameter("type", "truetype");
   font->setParameter("source", font_source);
   font->setParameter("size", Ogre::StringConverter::toString((Ogre::Real)size));
   font->setParameter("resolution", "96");

   return name;
}


GMFN double DestroyGMFont(char *name)
{
   Ogre::FontManager::getSingleton().remove(name);

   return TRUE;
}


GMFN double LoadFont(char *name)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);
   
   if (font.isNull())
      return FALSE;
   
   font->load();

   return TRUE;
}


GMFN double UnloadFont(char *name)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);
   
   if (font.isNull())
      return FALSE;

   font->unload();

   return TRUE;
}


GMFN double SetFontResolution(char *name, double resolution)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);
   
   if (font.isNull())
      return FALSE;

   font->setParameter("resolution", Ogre::StringConverter::toString((Ogre::Real)resolution));

   return TRUE;
}


GMFN double GetFontResolution(char *name)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);

   if (font.isNull())
      return 0;

   return Ogre::StringConverter::parseUnsignedInt(font->getParameter("resolution"));
}


GMFN double SetFontSource(char *name, char *font_source)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);
   
   if (font.isNull())
      return FALSE;

   font->setParameter("source", font_source);

   return TRUE;
}


GMFN char *GetFontSource(char *name)
{
   static Ogre::String font_source;
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);

   if (!font.isNull())
      font_source = font->getParameter("source");
   else
      font_source.empty();

   return const_cast<char*>(font_source.c_str());
}


GMFN double SetFontSize(char *name, double size)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);
   
   if (font.isNull())
      return FALSE;

   font->setParameter("size", Ogre::StringConverter::toString((Ogre::Real)size));

   return TRUE;
}


GMFN double GetFontSize(char *name)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);

   if (font.isNull())
      return 0;

   return Ogre::StringConverter::parseUnsignedInt(font->getParameter("size"));
}


GMFN double GetFontStringWidth(char *name, char *txt)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);

   if (font.isNull())
      return 0;

   // Font needs to be loaded in order to calculate string width!
   if (!font->isLoaded())
      font->load();

   Ogre::String text = txt;
   int fontSize = Ogre::StringConverter::parseUnsignedInt(font->getParameter("size"));
   double textWidth = 0.0;

   for (Ogre::String::iterator i = text.begin(); i < text.end();i++)
   {   
      if (*i == 0x0020)
         textWidth += dynamic_cast<Ogre::Font*>(font.get())->getGlyphAspectRatio(0x0030);
      else
         textWidth += dynamic_cast<Ogre::Font*>(font.get())->getGlyphAspectRatio(*i);
   }
   textWidth *= fontSize;

   return textWidth;
}


GMFN double GetFontHeight(char *name)
{
   Ogre::ResourcePtr font = Ogre::FontManager::getSingleton().getByName(name);

   if (font.isNull())
      return 0;

   return Ogre::StringConverter::parseUnsignedInt(font->getParameter("size"));
}

#endif
