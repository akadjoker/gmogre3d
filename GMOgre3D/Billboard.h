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

#ifndef GMOGRE_BILLBOARD_H
#define GMOGRE_BILLBOARD_H

#include "GMOgre3D.h"


GMFN double SetBillboardRotation(double bb_ptr, double degrees)
{
   Ogre::Billboard *bb = ConvertFromGMPointer<Ogre::Billboard *>(bb_ptr);

   if (bb == NULL)
      return FALSE;
   
   bb->setRotation(Ogre::Degree((Ogre::Real)degrees));

   return TRUE;
}


GMFN double SetBillboardPosition(double bb_ptr, double x, double z, double y)
{
   Ogre::Billboard *bb = ConvertFromGMPointer<Ogre::Billboard *>(bb_ptr);

   if (bb == NULL)
      return FALSE;
   
   bb->setPosition(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetBillboardDimensions(double bb_ptr, double width, double height)
{
   Ogre::Billboard *bb = ConvertFromGMPointer<Ogre::Billboard *>(bb_ptr);

   if (bb == NULL)
      return FALSE;
   
   bb->setDimensions((Ogre::Real)width, (Ogre::Real)height);

   return TRUE;
}


GMFN double GetBillboardWidth(double bb_ptr)
{
   Ogre::Billboard *bb = ConvertFromGMPointer<Ogre::Billboard *>(bb_ptr);

   if (bb == NULL)
      return 0;
   
   return bb->getOwnWidth();
}


GMFN double GetBillboardHeight(double bb_ptr)
{
   Ogre::Billboard *bb = ConvertFromGMPointer<Ogre::Billboard *>(bb_ptr);

   if (bb == NULL)
      return 0;
   
   return bb->getOwnHeight();
}


GMFN double SetBillboardColor(double bb_ptr, double color, double alpha)
{
   Ogre::Billboard *bb = ConvertFromGMPointer<Ogre::Billboard *>(bb_ptr);

   if (bb == NULL)
      return 0;

   bb->setColour(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), (float)alpha));

   return TRUE;
}

#endif
