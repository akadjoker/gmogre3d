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

#ifndef GMOGRE_SCENE_MANAGER_H
#define GMOGRE_SCENE_MANAGER_H

#include "GMOgre3D.h"

static Ogre::String scene_mgr_mat_name;
static double scene_mgr_enable;


GMFN double CreateSceneManager(double type)
{
   if (mRoot == NULL)
      return 0;

   Ogre::SceneManager *scene_mgr = NULL;
   
   TRY
      scene_mgr = mRoot->createSceneManager(static_cast<Ogre::SceneType>((int)type), GenerateUniqueName());

      // Set our current to the only one that exists
      if (mSceneMgr == NULL)
         mSceneMgr = scene_mgr;

      GMFrameListener *fl = OGRE_NEW GMFrameListener;
      mRoot->addFrameListener(fl);
      fl->Create2DManager(mSceneMgr);
      mSceneListener[scene_mgr] = fl;

      GMSceneManagerListener *sml = OGRE_NEW GMSceneManagerListener;
      scene_mgr->addListener(sml);
      mSceneManagerListener[scene_mgr] = sml;

      MOC::CollisionTools *ct = OGRE_NEW MOC::CollisionTools(scene_mgr);
      mSceneCollisionMap[scene_mgr] = ct;
   CATCH("CreateSceneManager")

   return ConvertToGMPointer(scene_mgr);
}


GMFN double DestroySceneManager(double scene_mgr_ptr)
{
   Ogre::SceneManager *scene_mgr = ConvertFromGMPointer<Ogre::SceneManager*>(scene_mgr_ptr);

   if (scene_mgr == NULL)
      return FALSE;

   if (mRoot == NULL)
      return FALSE;

   TRY
      // Delete frame listener
      GMFrameListener *fl = mSceneListener[scene_mgr];
      mRoot->removeFrameListener(fl);
      delete fl;
      mSceneListener.erase(scene_mgr);

      GMSceneManagerListener *sml = mSceneManagerListener[scene_mgr];
      scene_mgr->removeListener(sml);
      delete sml;
      mSceneManagerListener.erase(scene_mgr);

      // Delete collision tools
      MOC::CollisionTools *ct = mSceneCollisionMap[scene_mgr];
      delete ct;
      mSceneCollisionMap.erase(scene_mgr);

      mRoot->destroySceneManager(scene_mgr);
   CATCH("DestroySceneManager")

   return TRUE;
}


GMFN double SetCurrentSceneManager(double scene_mgr_ptr)
{
   Ogre::SceneManager *scene_mgr = ConvertFromGMPointer<Ogre::SceneManager*>(scene_mgr_ptr);

   if (scene_mgr == NULL)
      return FALSE;

   TRY
      mSceneMgr = scene_mgr;
   CATCH("SetCurrentSceneManager")

   return TRUE;
}


GMFN double ClearScene()
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->clearScene();

   return TRUE;
}


GMFN double SetWorldGeometry(char *filename)
{
   if (mSceneMgr == NULL)
      return FALSE;

   TRY
      mSceneMgr->setWorldGeometry(filename);
   CATCH("SetCurrentSceneManager")

   return TRUE;
}


GMFN double SetVisibilityMask(double mask)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setVisibilityMask((Ogre::uint32)mask);

   return TRUE;
}


GMFN double SetShadowTextureCasterPreViewProjCallback(double func)
{
   if (mSceneMgr == NULL)
      return FALSE;

   GMSceneManagerListener *sml = mSceneManagerListener[mSceneMgr];
   
   if (sml == NULL)
      return false;

   sml->SetShadowTextureCasterPreViewProjCallback((int)func);

   return TRUE;
}


GMFN double SetStartFrameCallback(double func)
{
   if (mSceneMgr == NULL)
      return FALSE;

   GMFrameListener *fl = mSceneListener[mSceneMgr];
   
   if (fl == NULL)
      return false;

   fl->SetStartFrameCallback((int)func);

   return TRUE;
}


GMFN double SetFrameQueuedCallback(double func)
{
   if (mSceneMgr == NULL)
      return FALSE;

   GMFrameListener *fl = mSceneListener[mSceneMgr];
   
   if (fl == NULL)
      return false;

   fl->SetFrameQueuedCallback((int)func);

   return TRUE;
}


GMFN double SetEndFrameCallback(double func)
{
   if (mSceneMgr == NULL)
      return FALSE;

   GMFrameListener *fl = mSceneListener[mSceneMgr];
   
   if (fl == NULL)
      return false;

   fl->SetEndFrameCallback((int)func);

   return TRUE;
}


GMFN double EnableSkyBox(double enable, char *material_name, double distance, double drawlast)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setSkyBox((enable != 0), material_name, (Ogre::Real)distance, (drawlast == 0.0));

   return TRUE;
}


GMFN double EnableSkyDome1(double enable, char *material_name)
{
   scene_mgr_enable = enable;
   scene_mgr_mat_name = material_name;

   return TRUE;
}


GMFN double EnableSkyDome2(double curvature, double tiling, double distance, double drawlast)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setSkyDome((scene_mgr_enable != 0), scene_mgr_mat_name, (Ogre::Real)curvature, (Ogre::Real)tiling, (Ogre::Real)distance, (drawlast == 0.0));

   return TRUE;
}


GMFN double EnableSkyPlane1(double enable, char *material_name)
{
   scene_mgr_enable = enable;
   scene_mgr_mat_name = material_name;

   return TRUE;
}


GMFN double EnableSkyPlane2(double scale, double tiling, double distance, double drawlast, double bow, double xsegments, double ysegments)
{
   Ogre::Plane plane;
   plane.d = (Ogre::Real)distance;
   plane.normal = -Ogre::Vector3::UNIT_Y;

   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setSkyPlane((scene_mgr_enable != 0), plane, scene_mgr_mat_name, (Ogre::Real)scale, (Ogre::Real)tiling, (drawlast == 0.0), (Ogre::Real)bow, (int)xsegments, (int)ysegments);

   return TRUE;
}


GMFN double SetAmbientLight(double color)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setAmbientLight(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color)));

   return TRUE;
}


GMFN double SetShadowTechnique(double type)
{
   if (mSceneMgr == NULL)
      return FALSE;
   
   mSceneMgr->setShadowTechnique(static_cast<Ogre::ShadowTechnique>((int)type));

   return TRUE;
}


GMFN double EnableShadowLightClipPlanes(double enable)
{
   if (mSceneMgr == NULL)
      return FALSE;
   
   mSceneMgr->setShadowUseLightClipPlanes((enable != 0));

   return TRUE;
}


GMFN double SetShadowFarDistance(double distance)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowFarDistance((Ogre::Real)distance);

   return TRUE;
}


GMFN double SetShadowDirectionalLightExtrusionDistance(double distance)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowDirectionalLightExtrusionDistance((Ogre::Real)distance);

   return TRUE;
}


GMFN double SetShadowTextureCountPerLightType(double light_types, double count)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowTextureCountPerLightType(static_cast<Ogre::Light::LightTypes>((int)light_types), (size_t)count);

   return TRUE;
}


GMFN double SetShadowTextureSettings(double size, double count, double pixel_format)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowTextureSettings((unsigned short)size, (unsigned short)count, static_cast<Ogre::PixelFormat>((int)pixel_format));

   return TRUE;
}


GMFN double SetShadowTextureFade(double fade_start, double fade_end)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowTextureFadeStart((Ogre::Real)fade_start);
   mSceneMgr->setShadowTextureFadeEnd((Ogre::Real)fade_end);

   return TRUE;
}


GMFN double SetShadowDirLightTextureOffset(double offset)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowDirLightTextureOffset((Ogre::Real)offset);

   return TRUE;
}


GMFN char *GetShadowTexture(double shadow_index)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::TexturePtr tex = mSceneMgr->getShadowTexture((size_t)shadow_index);

   return const_cast<char*>(tex->getName().c_str());
}


GMFN double EnableShadowInfiniteFarPlane(double enable)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowUseInfiniteFarPlane((enable != 0));

   return TRUE;
}


GMFN double SetShadowColor(double color)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowColour(Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color)));

   return TRUE;
}


GMFN double EnableShadowTextureSelfShadow(double enable)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowTextureSelfShadow((enable != 0));

   return TRUE;
}


GMFN double SetShadowTextureCasterMaterial(char *material)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowTextureCasterMaterial(material);

   return TRUE;
}


GMFN double SetShadowTextureReceiverMaterial(char *material)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowTextureReceiverMaterial(material);

   return TRUE;
}


GMFN double EnableShadowCasterRenderBackFaces(double enable)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setShadowCasterRenderBackFaces((enable != 0));

   return TRUE;
}


GMFN double SetShadowCameraSetup(double pssm_shadow_camera_setup_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::PSSMShadowCameraSetup *pssm_shadow_camera_setup = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup*>(pssm_shadow_camera_setup_ptr);

   if (pssm_shadow_camera_setup == NULL)
      return FALSE;

   mSceneMgr->setShadowCameraSetup(Ogre::ShadowCameraSetupPtr(pssm_shadow_camera_setup));

   return TRUE;
}


GMFN double SetFog(double type, double color, double density, double start, double end)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setFog(static_cast<Ogre::FogMode>((int)type), Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color)), (Ogre::Real)density, (Ogre::Real)start, (Ogre::Real)end);

   return TRUE;
}


GMFN double GetNumberOfEntities()
{
   if (mSceneMgr == NULL)
      return FALSE;

   double num = 0;

   for (Ogre::SceneManager::MovableObjectIterator iter = mSceneMgr->getMovableObjectIterator("Entity"); iter.hasMoreElements();)
	   num++;

   return num;
}

#endif
