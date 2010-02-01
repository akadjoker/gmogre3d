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

#ifndef GMOGRE_SKYX_H
#define GMOGRE_SKYX_H

#include "GMOgre3D.h"


GMFN double CreateSkyX(double camera_ptr)
{
   SkyX::SkyX *skyx = NULL;

   TRY
      if (mSceneMgr == NULL)
         return FALSE;

      skyx = new SkyX::SkyX(mSceneMgr, ConvertFromGMPointer<Ogre::Camera*>(camera_ptr));
      skyx->create();

      if (mSkyX == NULL)
         mSkyX = skyx;

      // Add our ground atmospheric scattering pass to terrain material
      Ogre::MaterialPtr mat = static_cast<Ogre::MaterialPtr>(Ogre::MaterialManager::getSingleton().getByName("Terrain"));

      if (!mat.isNull())
	      mSkyX->getGPUManager()->addGroundPass(mat->getTechnique(0)->createPass(), 5000, Ogre::SBT_TRANSPARENT_COLOUR);
   CATCH("CreateSkyX")

   return ConvertToGMPointer(skyx);
}


GMFN double DestroySkyX(double skyx_ptr)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   skyx->remove();

   return TRUE;
}


GMFN double EnableSkyXStarfield(double skyx_ptr, double enable)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   skyx->setStarfieldEnabled((enable != 0));

   return TRUE;
}


GMFN double SetSkyXLightingMode(double skyx_ptr, double type)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   skyx->setLightingMode(static_cast<SkyX::SkyX::LightingMode>((int)type));

   return TRUE;
}


GMFN double SetSkyXTime(double skyx_ptr, double time_seconds)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   SkyX::AtmosphereManager::Options opt = skyx->getAtmosphereManager()->getOptions();
   opt.Time.x = time_seconds / 3600;
	skyx->getAtmosphereManager()->setOptions(opt);

   return TRUE;
}


GMFN double UpdateSkyXTime(double skyx_ptr, double time_seconds)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   skyx->update(time_seconds);

   return TRUE;
}


GMFN double SetSkyXSunriseHour(double skyx_ptr, double time_hour)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   SkyX::AtmosphereManager::Options opt = skyx->getAtmosphereManager()->getOptions();
   opt.Time.y = time_hour;
	skyx->getAtmosphereManager()->setOptions(opt);

   return TRUE;
}


GMFN double SetSkyXSunsetHour(double skyx_ptr, double time_hour)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   SkyX::AtmosphereManager::Options opt = skyx->getAtmosphereManager()->getOptions();
   opt.Time.z = time_hour;
	skyx->getAtmosphereManager()->setOptions(opt);

   return TRUE;
}


GMFN double AddCloudLayer(double skyx_ptr, double height = 100.0, double scale = 0.001, double wind_dirx = 1, double wind_diry = 1, double time_mult = 0.125, double distance_attenuation = 0.05, double detail_attenuation = 1, double normal_mult = 2, double height_vol = 0.25, double vol_displacement = 0.01)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   SkyX::CloudLayer *layer = skyx->getCloudsManager()->add(SkyX::CloudLayer::Options(height, scale, Ogre::Vector2(wind_dirx, wind_diry), time_mult, distance_attenuation, detail_attenuation, normal_mult, height_vol, vol_displacement));

   return ConvertToGMPointer(layer);
}


GMFN double RemoveCloudLayer(double skyx_ptr, double cloud_layer_ptr)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   skyx->getCloudsManager()->remove(ConvertFromGMPointer<SkyX::CloudLayer*>(cloud_layer_ptr));

   return TRUE;
}


GMFN double AddVolumetricClouds(double skyx_ptr)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   skyx->getVCloudsManager()->create();

   return TRUE;
}


GMFN double RemoveVolumetricClouds(double skyx_ptr)
{
   SkyX::SkyX *skyx = ConvertFromGMPointer<SkyX::SkyX*>(skyx_ptr);

   if (skyx == NULL)
      return FALSE;

   skyx->getVCloudsManager()->remove();

   return TRUE;
}

#endif
