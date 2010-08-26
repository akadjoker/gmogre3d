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

#ifndef GMOGRE_MOVABLE_TEXT_H
#define GMOGRE_MOVABLE_TEXT_H

#include "GMOgre3D.h"


static Ogre::String mtext_font_name;
static Ogre::String mtext_txt;

GMFN double CreateMovableText1(char *font_name, char *txt)
{
   mtext_font_name = font_name;
   mtext_txt = txt;

   return TRUE;
}


GMFN double CreateMovableText2(double size, double color, double alpha)
{
   MovableText *text = NULL;
   
   TRY
      text = OGRE_NEW MovableText(GenerateUniqueName(), mtext_txt, mtext_font_name, size);
      text->setColor(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));
   CATCH("CreateMovableText")

   return ConvertToGMPointer(text);
}


GMFN double DestroyMovableText(double text_ptr)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   delete text;

   return TRUE;
}


GMFN double SetMovableTextFont(double text_ptr, char *font_name)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->setFontName(font_name);

   return TRUE;
}


GMFN double SetMovableTextCaption(double text_ptr, char *txt)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->setCaption(txt);

   return TRUE;
}


GMFN double SetMovableTextColour(double text_ptr, double color, double alpha)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->setColor(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));

   return TRUE;
}


GMFN double SetMovableTextAlignment(double text_ptr, double horiz_align, double vert_align)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   MovableText::VerticalAlignment vert;
   MovableText::HorizontalAlignment horiz;

   if (horiz_align == 0)
      horiz = MovableText::H_LEFT;
   else if (horiz_align == 2)
      horiz = MovableText::H_CENTER;

   if (vert_align == 0)
      vert = MovableText::V_BELOW;
   else if (vert_align == 1)
      vert = MovableText::V_ABOVE;
   else
      vert = MovableText::V_CENTER;

   text->setTextAlignment(horiz, vert);

   return TRUE;
}


GMFN double ShowMovableTextOnTop(double text_ptr, double show)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->showOnTop((show != 0));

   return TRUE;
}


GMFN double SetMovableTextGlobalTranslation(double text_ptr, double x, double z, double y)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->setGlobalTranslation(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetMovableTextLocalTranslation(double text_ptr, double x, double z, double y)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->setLocalTranslation(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double AttachMovableTextToSceneNode(double text_ptr, double scene_node_ptr)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;

   node->attachObject(text);

   return TRUE;
}


GMFN double DetachMovableTextFromSceneNode(double text_ptr, double scene_node_ptr)
{
   MovableText *text = ConvertFromGMPointer<MovableText*>(text_ptr);

   if (text == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;

   node->detachObject(text);

   return TRUE;
}

#endif
