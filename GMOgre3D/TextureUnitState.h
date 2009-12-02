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

#ifndef GMOGRE_TEXTURE_UNIT_STATE_H
#define GMOGRE_TEXTURE_UNIT_STATE_H

#include "GMOgre3D.h"


GMFN double SetTextureUnitStateTextureName(double tex_unit_ptr, char *tex_name)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);
   
   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureName(tex_name);

   return TRUE;
}


GMFN double SetTextureUnitStateCubicTextureNames1(double tex_unit_ptr, char *tex_name1, char *tex_name2, char *tex_name3)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);
   
   if (tex_unit == NULL)
      return FALSE;

   for (int x = 0; x < 6; x++)
      mCubeTextureNames[x].empty();

   mCubeTextureNames[0] = tex_name1;
   mCubeTextureNames[1] = tex_name2;
   mCubeTextureNames[2] = tex_name3;

   return TRUE;
}


GMFN double SetTextureUnitStateCubicTextureNames2(double tex_unit_ptr, char *tex_name4, char *tex_name5, char *tex_name6)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);
   
   if (tex_unit == NULL)
      return FALSE;

   mCubeTextureNames[3] = tex_name4;
   mCubeTextureNames[4] = tex_name5;
   mCubeTextureNames[5] = tex_name6;

   tex_unit->setCubicTextureName(mCubeTextureNames);

   return TRUE;
}


GMFN double SetTextureUnitStateTextureCoordSet(double tex_unit_ptr, double set)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureCoordSet(set);

   return TRUE;
}


GMFN double SetTextureUnitStateScrollAnimation(double tex_unit_ptr, double uspeed, double vspeed)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setScrollAnimation(uspeed, vspeed);

   return TRUE;
}


GMFN double SetTextureUnitStateRotateAnimation(double tex_unit_ptr, double speed)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setRotateAnimation(speed);

   return TRUE;
}


GMFN double SetTextureUnitStateContentType(double tex_unit_ptr, double type)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setContentType(static_cast<Ogre::TextureUnitState::ContentType>((int)type));

   return TRUE;
}


GMFN double SetTextureUnitStateColorOperation(double tex_unit_ptr, double type)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setColourOperation(static_cast<Ogre::LayerBlendOperation>((int)type));

   return TRUE;
}


GMFN double EnableTextureUnitStateEnvironmentMap(double tex_unit_ptr, double enable, double type)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   if (enable != 0)
      tex_unit->setEnvironmentMap(true, static_cast<Ogre::TextureUnitState::EnvMapType>((int)type));
   else
      tex_unit->setEnvironmentMap(false);

   return TRUE;
}


GMFN double SetTextureUnitStateTextureAddressingMode(double tex_unit_ptr, double type)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureAddressingMode(static_cast<Ogre::TextureUnitState::TextureAddressingMode>((int)type));

   return TRUE;
}


GMFN double SetTextureUnitStateTextureBorderColor(double tex_unit_ptr, double color)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureBorderColour(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color)));

   return TRUE;
}


GMFN double SetTextureUnitStateTextureFiltering(double tex_unit_ptr, double type)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureFiltering(static_cast<Ogre::TextureFilterOptions>((int)type));

   return TRUE;
}

#endif
