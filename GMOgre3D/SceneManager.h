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
      {
         mSceneMgr = scene_mgr;

         //if (mFrameListener != NULL)
         //   mFrameListener->Create2DManager(mSceneMgr);

         //mCollisionTools.setSceneManager(mSceneMgr);
      }

      GMFrameListener *fl = new GMFrameListener;
      mRoot->addFrameListener(fl);
      fl->Create2DManager(mSceneMgr);
      mSceneListener[scene_mgr] = fl;

      MOC::CollisionTools *ct = new MOC::CollisionTools(scene_mgr);
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

   // Delete frame listener
   GMFrameListener *fl = mSceneListener[scene_mgr];
   mRoot->removeFrameListener(fl);
   delete fl;
   mSceneListener.erase(scene_mgr);

   // Delete collision tools
   MOC::CollisionTools *ct = mSceneCollisionMap[scene_mgr];
   delete ct;
   mSceneCollisionMap.erase(scene_mgr);

   mRoot->destroySceneManager(scene_mgr);

   return TRUE;
}


GMFN double SetCurrentSceneManager(double scene_mgr_ptr)
{
   Ogre::SceneManager *scene_mgr = ConvertFromGMPointer<Ogre::SceneManager*>(scene_mgr_ptr);

   if (scene_mgr == NULL)
      return FALSE;

   mSceneMgr = scene_mgr;

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
   try
   {   
      if (mSceneMgr == NULL)
         return FALSE;

      mSceneMgr->setWorldGeometry(filename);
   }
   catch(Ogre::Exception& e)
   {
      LogError(e.what());
      return FALSE;
   }

   return TRUE;
}

GMFN double SetVisibilityMask(double mask)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setVisibilityMask(mask);

   return TRUE;
}

GMFN double EnableSkyBox(double enable, char *material_name, double distance, double drawlast)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setSkyBox((enable != 0), material_name, distance, (drawlast == 0.0));

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

   mSceneMgr->setSkyDome((scene_mgr_enable != 0), scene_mgr_mat_name, curvature, tiling, distance, (drawlast == 0.0));

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
   plane.d = distance;
   plane.normal = -Ogre::Vector3::UNIT_Y;

   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setSkyPlane((scene_mgr_enable != 0), plane, scene_mgr_mat_name, scale, tiling, (drawlast == 0.0), bow, xsegments, ysegments);

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

   mSceneMgr->setShadowFarDistance(distance);

   return TRUE;
}


GMFN double EnableShadowUseInfiniteFarPlane(double enable)
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


GMFN double SetFog(double type, double color, double density, double start, double end)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->setFog(static_cast<Ogre::FogMode>((int)type), Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color)), density, start, end);

   return TRUE;
}

#endif
