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

#ifndef GMOGRE_TEXT_H
#define GMOGRE_TEXT_H

#include "GMOgre3D.h"


static Ogre::String text_font_name;
static Ogre::String text_txt;

GMFN double CreateText1(char *font_name, char *txt)
{
   text_font_name = font_name;
   text_txt = txt;

   return TRUE;
}


GMFN double CreateText2(double x, double y, double color, double alpha)
{
   OgreText *text = NULL;
      
    TRY
       text = new OgreText;

      text->SetFont(text_font_name, GetFontSize(const_cast<char*>(text_font_name.c_str())));
      text->SetCaption(text_txt);
      text->SetPosition(x, y);
      text->SetColor(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));
   CATCH("CreateText")

   return ConvertToGMPointer(text);
}


GMFN double DestroyText(double text_ptr)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   delete text;

   return TRUE;
}


GMFN double SetTextFont(double text_ptr, char *font_name)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->SetFont(font_name, GetFontSize(font_name));

   return TRUE;
}


GMFN double SetTextCaption(double text_ptr, char *txt)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->SetCaption(txt);

   return TRUE;
}


GMFN double SetTextMetrics(double text_ptr, double type)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->SetMetrics(type);

   return TRUE;
}


GMFN double SetTextPosition(double text_ptr, double x, double y)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->SetPosition(x, y);

   return TRUE;
}


GMFN double SetTextColour(double text_ptr, double color, double alpha)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->SetColor(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));

   return TRUE;
}


GMFN double SetTextAlignment(double text_ptr, double type)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return FALSE;

   text->SetAlignment(static_cast<Ogre::TextAreaOverlayElement::Alignment>((int)type));

   return TRUE;
}


GMFN double GetTextWidth(double text_ptr)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return 0;

   return text->GetWidth();
}


GMFN double GetTextHeight(double text_ptr)
{
   OgreText *text = ConvertFromGMPointer<OgreText*>(text_ptr);

   if (text == NULL)
      return 0;

   return text->GetHeight();
}

#endif
