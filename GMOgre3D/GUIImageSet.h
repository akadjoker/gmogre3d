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

#ifndef GMOGRE_GUI_IMAGE_SET_H
#define GMOGRE_GUI_IMAGE_SET_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "CEGUIImageSetManager.h"


static Ogre::String gui_image_name;


GMFN double CreateGUIImageSet(char *name, double gui_texture_ptr)
{
   CEGUI::Texture *tex = ConvertFromGMPointer<CEGUI::Texture*>(gui_texture_ptr);

   if (tex == NULL)
      return FALSE;

   CEGUI::Imageset *image_set = NULL;

   TRY
      image_set = &CEGUI::ImagesetManager::getSingleton().create(name, *tex);
   CATCH("CreateGUIImageSet")

   return ConvertToGMPointer(image_set);
}


GMFN double CreateGUIImageSetFromFile(char *name, char *filename)
{
   CEGUI::Imageset *image_set = NULL;

   TRY
      image_set = &CEGUI::ImagesetManager::getSingleton().createFromImageFile(name, filename);
   CATCH("CreateGUIImageSetFromFile")

   return ConvertToGMPointer(image_set);
}


GMFN double DestroyGUIImageSet(double gui_image_set_ptr)
{
   CEGUI::Imageset *image_set = ConvertFromGMPointer<CEGUI::Imageset*>(gui_image_set_ptr);

   if (image_set == NULL)
      return FALSE;

   CEGUI::ImagesetManager::getSingleton().destroy(*image_set);

   return TRUE;
}


GMFN double DefineGUIImageSetImage1(double gui_image_set_ptr, char *name)
{
   CEGUI::Imageset *image_set = ConvertFromGMPointer<CEGUI::Imageset*>(gui_image_set_ptr);

   if (image_set == NULL)
      return FALSE;

   gui_image_name = name;
   
   return TRUE;
}


GMFN double DefineGUIImageSetImage2(double gui_image_set_ptr, double posx, double posy, double width, double height, double offsetx, double offsety)
{
   CEGUI::Imageset *image_set = ConvertFromGMPointer<CEGUI::Imageset*>(gui_image_set_ptr);

   if (image_set == NULL)
      return FALSE;

   image_set->defineImage(gui_image_name, CEGUI::Point(posx, posy), CEGUI::Size(width, height), CEGUI::Point(offsetx, offsety));
   
   return TRUE;
}


GMFN double UndefineGUIImageSetImage(double gui_image_set_ptr, char *name)
{
   CEGUI::Imageset *image_set = ConvertFromGMPointer<CEGUI::Imageset*>(gui_image_set_ptr);

   if (image_set == NULL)
      return FALSE;

   image_set->undefineImage(name);

   return TRUE;
}


GMFN double GetGUIImageSetImage(double gui_image_set_ptr, char *name)
{
   CEGUI::Imageset *image_set = ConvertFromGMPointer<CEGUI::Imageset*>(gui_image_set_ptr);

   if (image_set == NULL)
      return 0;

   CEGUI::Image *image = (CEGUI::Image*)&image_set->getImage(name);

   return ConvertToGMPointer(image);
}


GMFN double GetGUIImageSetTexture(double gui_image_set_ptr)
{
   CEGUI::Imageset *image_set = ConvertFromGMPointer<CEGUI::Imageset*>(gui_image_set_ptr);

   if (image_set == NULL)
      return 0;

   CEGUI::Texture *tex = image_set->getTexture();

   return ConvertToGMPointer(tex);
}


GMFN double EnableGUIImageSetAutoScaling(double gui_image_set_ptr, double enable)
{
   CEGUI::Imageset *image_set = ConvertFromGMPointer<CEGUI::Imageset*>(gui_image_set_ptr);

   if (image_set == NULL)
      return FALSE;

   image_set->setAutoScalingEnabled((enable != 0));

   return TRUE;
}

#endif
