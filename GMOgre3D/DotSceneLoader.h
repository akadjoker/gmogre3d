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

#ifndef GMOGRE_DOTSCENE_LOADER_H
#define GMOGRE_DOTSCENE_LOADER_H

#include "GMOgre3D.h"
#include "OgreDotSceneLoader.h"


GMFN double LoadDotScene(char *filename, char *group)
{
   if (mDotSceneLoader == NULL)
      mDotSceneLoader = OGRE_NEW DotSceneLoader;

   TRY
      mDotSceneLoader->parseDotScene(filename, group, mSceneMgr);

      //Ogre::TerrainGroup* terrain_group = mDotSceneLoader->getTerrainGroup();

      // Set default camera for all viewports if needed
      if (mRenderWindow)
      {
         for (short x = 0; x < mRenderWindow->getNumViewports(); x++)
         {
            Ogre::Viewport *viewport = mRenderWindow->getViewport(x);

            if (viewport->getCamera() == NULL)
            {
               Ogre::SceneManager::CameraIterator iter = mSceneMgr->getCameraIterator();
               if (iter.hasMoreElements())
                  viewport->setCamera(iter.getNext());
            }
         }
      }

      return 1.0;
   CATCH("LoadDotScene")

   return 0.0;
}


// Note we can't unload a scene currently... too many things not tracked like terrain, sky, etc.
/*
void UnloadDotScene()
{
   if (mDotSceneLoader == NULL)
   {
      return 1.0;
   }

   OGRE_DELETE mDotSceneLoader;
   mDotSceneLoader = NULL;

   // Remove all objects from the scene
   for (std::map<Ogre::String, Ogre::Node *>::iterator iter = mDotSceneLoader->nodeObjects.begin(); iter != mDotSceneLoader->nodeObjects.end(); ++iter);
      mSceneMgr-destroySceneNode(iter->second);

   for (std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->entityObjects.begin(); iter != mDotSceneLoader->entityObjects.end(); ++iter);
      mSceneMgr-destroyEntity(iter->second);

   for (std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->cameraObjects.begin(); iter != mDotSceneLoader->cameraObjects.end(); ++iter);
      mSceneMgr-destroyCamera(iter->second);

   for (std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->lightObjects.begin(); iter != mDotSceneLoader->lightObjects.end(); ++iter);
      mSceneMgr-destroyLight(iter->second);

   for (std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->particleSystemObjects.begin(); iter != mDotSceneLoader->particleSystemObjects.end(); ++iter);
      mSceneMgr-destroyParticleSystem(iter->second);

   return 1.0;
}
GMAPI_GMFUNCTION_GENERATEHANDLER(UnloadDotScene);
*/

GMFN double GetDotSceneSceneNode(char *name)
{
   if (mDotSceneLoader == NULL)
   {
      return 0.0;
   }

   Ogre::Node *node = NULL;

   std::map<Ogre::String, Ogre::Node *>::iterator iter = mDotSceneLoader->nodeObjects.find("Ogre#0");
   if (iter != mDotSceneLoader->nodeObjects.end())
      node = iter->second;

   return ConvertToGMPointer(node);
}


GMFN double GetDotSceneEntity(char *name)
{
   if (mDotSceneLoader == NULL)
   {
      return 0.0;
   }

   Ogre::MovableObject *mo = NULL;

   std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->entityObjects.find(name);
   if (iter != mDotSceneLoader->entityObjects.end())
      mo = iter->second;

   return ConvertToGMPointer(mo);
}


GMFN double GetDotSceneCamera(char *name)
{
   if (mDotSceneLoader == NULL)
   {
      return 0.0;
   }

   Ogre::MovableObject *mo = NULL;

   std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->cameraObjects.find(name);
   if (iter != mDotSceneLoader->cameraObjects.end())
      mo = iter->second;

   return ConvertToGMPointer(mo);
}


GMFN double GetDotSceneLight(char *name)
{
   if (mDotSceneLoader == NULL)
   {
      return 0.0;
   }

   Ogre::MovableObject *mo = NULL;

   std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->lightObjects.find(name);
   if (iter != mDotSceneLoader->lightObjects.end())
      mo = iter->second;

   return ConvertToGMPointer(mo);
}


GMFN double GetDotSceneParticleSystem(char *name)
{
   if (mDotSceneLoader == NULL)
   {
      return 0.0;
   }

   Ogre::MovableObject *mo = NULL;

   std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->particleSystemObjects.find(name);
   if (iter != mDotSceneLoader->particleSystemObjects.end())
      mo = iter->second;

   return ConvertToGMPointer(mo);
}


GMFN double GetDotSceneBillboardSet(char *name)
{
   if (mDotSceneLoader == NULL)
   {
      return 0.0;
   }

   Ogre::MovableObject *mo = NULL;

   std::map<Ogre::String, Ogre::MovableObject *>::iterator iter = mDotSceneLoader->billboardSetObjects.find(name);
   if (iter != mDotSceneLoader->billboardSetObjects.end())
      mo = iter->second;

   return ConvertToGMPointer(mo);
}

#endif
