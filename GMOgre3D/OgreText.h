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

#include "OgreTextAreaOverlayElement.h"
#include "OgreStringConverter.h"

#ifndef OGRE_TEXT_H
#define OGRE_TEXT_H

class OgreText
{
public:
	OgreText();
	~OgreText();

   void SetFont(Ogre::String font_name, Ogre::Real height);

	void SetCaption(char *txt);
	void SetCaption(Ogre::String txt);

   void SetMetrics(double type);
	void SetPosition(double x, double y);
   void SetColor(Ogre::ColourValue color);
   void SetAlignment(Ogre::TextAreaOverlayElement::Alignment align);

   double GetWidth();
   double GetHeight();

protected:
   static unsigned int m_initialized;

   Ogre::OverlayManager *m_overlay_mgr;
	Ogre::OverlayContainer *m_panel;
	Ogre::Overlay *overlay;
	Ogre::TextAreaOverlayElement *m_text_area;
};

#endif
