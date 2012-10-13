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


GMFN char *GetTextureUnitStateTextureName(double tex_unit_ptr)
{
   static Ogre::String texture_name;

   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);
   
   texture_name.clear();

   if (tex_unit != NULL)
      texture_name = tex_unit->getTextureName();

   return const_cast<char*>(texture_name.c_str());
}


GMFN double SetTextureUnitStateCubicTextureNames1(char *tex_name1, char *tex_name2, char *tex_name3, char *tex_name4)
{
   for (int x = 0; x < 6; x++)
      mCubeTextureNames[x].empty();

   mCubeTextureNames[0] = tex_name1;
   mCubeTextureNames[1] = tex_name2;
   mCubeTextureNames[2] = tex_name3;
   mCubeTextureNames[3] = tex_name4;

   return TRUE;
}


GMFN double SetTextureUnitStateCubicTextureNames2(double tex_unit_ptr, char *tex_name5, char *tex_name6, double for_uvw = false)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);
   
   if (tex_unit == NULL)
      return FALSE;

   mCubeTextureNames[4] = tex_name5;
   mCubeTextureNames[5] = tex_name6;

   tex_unit->setCubicTextureName(mCubeTextureNames, (for_uvw != 0));

   return TRUE;
}


GMFN double SetTextureUnitStateTextureCoordSet(double tex_unit_ptr, double set)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureCoordSet((unsigned int)set);

   return TRUE;
}


GMFN double SetTextureUnitStateScrollAnimation(double tex_unit_ptr, double uspeed, double vspeed)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setScrollAnimation((Ogre::Real)uspeed, (Ogre::Real)vspeed);

   return TRUE;
}


GMFN double SetTextureUnitStateRotateAnimation(double tex_unit_ptr, double speed)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setRotateAnimation((Ogre::Real)speed);

   return TRUE;
}

GMFN double SetTextureUnitStateTransformAnimation(double tex_unit_ptr, double transform_type, double waveform_type, double base, double frequency, double phase, double amplitude)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTransformAnimation(static_cast<Ogre::TextureUnitState::TextureTransformType>((int)transform_type), static_cast<Ogre::WaveformType>((int)waveform_type), (Ogre::Real)base, (Ogre::Real)frequency, (Ogre::Real)phase, (Ogre::Real)amplitude);

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


GMFN double SetTextureUnitStateTextureScroll(double tex_unit_ptr, double uscroll, double vscroll)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureScroll((Ogre::Real)uscroll, (Ogre::Real)vscroll);

   return TRUE;
}


GMFN double SetTextureUnitStateTextureScale(double tex_unit_ptr, double uscale, double vscale)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureScale((Ogre::Real)uscale, (Ogre::Real)vscale);

   return TRUE;
}


GMFN double SetTextureUnitStateTextureRotate(double tex_unit_ptr, double degrees)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureRotate(Ogre::Degree((Ogre::Real)degrees));

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


GMFN double SetTextureUnitStateTextureAnisotropy(double tex_unit_ptr, double level)
{
   Ogre::TextureUnitState *tex_unit = ConvertFromGMPointer<Ogre::TextureUnitState *>(tex_unit_ptr);

   if (tex_unit == NULL)
      return FALSE;

   tex_unit->setTextureAnisotropy((unsigned int)level);

   return TRUE;
}

#endif
