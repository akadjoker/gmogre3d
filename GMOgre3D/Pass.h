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

#ifndef GMOGRE_PASS_H
#define GMOGRE_PASS_H

#include "GMOgre3D.h"


GMFN double SetPassAmbientColor(double pass_ptr, double color)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);
   
   if (pass == NULL)
      return FALSE;

   pass->setAmbient(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color));

   return TRUE;
}


GMFN double SetPassDiffuseColor(double pass_ptr, double color, double alpha)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);
   
   if (pass == NULL)
      return FALSE;

   pass->setDiffuse(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), (Ogre::Real)alpha);

   return TRUE;
}


GMFN double SetPassSpecularColor(double pass_ptr, double color, double alpha)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setSpecular(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), (Ogre::Real)alpha);

   return TRUE;
}


GMFN double SetPassSelfIllumination(double pass_ptr, double color)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setSelfIllumination(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color));

   return TRUE;
}


GMFN double SetPassShininess(double pass_ptr, double shininess)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setShininess((Ogre::Real)shininess);

   return TRUE;
}


GMFN double EnablePassPointSprites(double pass_ptr, double enable)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setPointSpritesEnabled((enable != 0));

   return TRUE;
}


GMFN double EnablePassDepthWrite(double pass_ptr, double enable)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setDepthWriteEnabled((enable != 0));

   return TRUE;
}


GMFN double EnablePassDepthCheck(double pass_ptr, double enable)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setDepthCheckEnabled((enable != 0));

   return TRUE;
}


GMFN double SetPassDepthFunc(double pass_ptr, double func)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setDepthFunction(static_cast<Ogre::CompareFunction>((int)func));

   return TRUE;
}


GMFN double EnablePassLighting(double pass_ptr, double enable)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setLightingEnabled((enable != 0));

   return TRUE;
}


GMFN double EnablePassPointSizeAttenuation(double pass_ptr, double enable, double constant = 0.0, double linear = 1.0, double quadratic = 0.0)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   if (enable != 0)
      pass->setPointAttenuation(true, (Ogre::Real)constant, (Ogre::Real)linear, (Ogre::Real)quadratic);
   else
      pass->setPointAttenuation(false);

   return TRUE;
}


GMFN double SetPassMinPointSize(double pass_ptr, double size)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setPointMinSize((Ogre::Real)size);

   return TRUE;
}


GMFN double SetPassMaxPointSize(double pass_ptr, double size)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setPointMaxSize((Ogre::Real)size);

   return TRUE;
}


GMFN double SetPassPointSize(double pass_ptr, double size)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setPointSize((Ogre::Real)size);

   return TRUE;
}


GMFN double SetPassSceneBlendingType(double pass_ptr, double type)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setSceneBlending(static_cast<Ogre::SceneBlendType>((int)type));

   return TRUE;
}


GMFN double GetPassVertexProgramParameters(double pass_ptr)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return 0;

   return ConvertToGMPointer(pass->getVertexProgramParameters().get());
}


GMFN double GetPassShadowCasterVertexProgramParameters(double pass_ptr)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return 0;

   return ConvertToGMPointer(pass->getShadowCasterVertexProgramParameters().get());
}


GMFN double GetPassShadowReceiverVertexProgramParameters(double pass_ptr)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return 0;

   return ConvertToGMPointer(pass->getShadowReceiverVertexProgramParameters().get());
}


GMFN double GetPassShadowReceiverFragmentProgramParameters(double pass_ptr)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return 0;

   return ConvertToGMPointer(pass->getShadowReceiverFragmentProgramParameters().get());
}


GMFN double GetPassFragmentProgramParameters(double pass_ptr)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return 0;

   return ConvertToGMPointer(pass->getFragmentProgramParameters().get());
}


GMFN double GetPassGeometryProgramParameters(double pass_ptr)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return 0;

   return ConvertToGMPointer(pass->getGeometryProgramParameters().get());
}


GMFN double CreatePassTextureUnitState(double pass_ptr)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);

   if (pass == NULL)
      return 0;

   Ogre::TextureUnitState *tex_unit = NULL;
   
   TRY
      tex_unit = pass->createTextureUnitState();
   CATCH("CreatePassTextureUnitState")

   return ConvertToGMPointer(tex_unit);
}


GMFN double GetPassTextureUnitState(double pass_ptr, double tex_unit_index)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);
   
   if (pass == NULL)
      return 0;

   return ConvertToGMPointer(pass->getTextureUnitState((unsigned short)tex_unit_index));
}


GMFN double GetNumPassTextureUnitStates(double pass_ptr)
{
   Ogre::Pass *pass = ConvertFromGMPointer<Ogre::Pass *>(pass_ptr);
   
   if (pass == NULL)
      return 0;

   return pass->getNumTextureUnitStates();
}

#endif
