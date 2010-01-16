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

#ifndef GMOGRE3D_H
#define GMOGRE3D_H

#include <SkyX.h>
#include <OgreTextAreaOverlayElement.h>
#include <OgreFontManager.h>
#include <OgreParticleFXPlugin.h>
#include <OgreCgPlugin.h>
#include <OgreOctreePlugin.h>
#include <OgreD3D9Plugin.h>
#include <OgreGLPlugin.h>
#include <OgreAny.h>
#include "OgreText.h"
#include "OgreSprite.h"
#include "OgreEuler.h"
#include "OgreNewtBody.h"
#include "OgreNewtWorld.h"
#include "OgreMovableText.h"
#include "CollisionTools.h"
#include "OgreNewt_Body.h"
#include "OgreNewt_Collision.h"
#include "FrameListener.h"
#include <GMAPI.h>
#include <OgreAny.h>
#include <vector>


#define GMFN extern "C" __declspec(dllexport)

#define TRY try {
#define CATCH(func) } catch(Ogre::Exception& e) { LogError(e.what()); } catch(std::exception& e) { LogError(e.what()); }  catch(...) { LogError("An unknown error has occurred in " + Ogre::String(func) + "!"); }

struct NewtonBody;

struct GMCallback
{
   unsigned int mGMInstanceID;
   unsigned int mGMEventNum1;
   unsigned int mGMEventNum2;
   bool mTriggered;

   void *mParam1;
   void *mParam2;
};


struct GMInstance
{
   GMInstance()
   {
      BodyAttached = false;
      GMInstanceAttached = false;
      mGMInstanceID = 0;
      mGMInstancePtr = NULL;
      mBody = NULL;
   }

   bool BodyAttached;
   bool GMInstanceAttached;

   int mGMInstanceID;
   gm::PGMINSTANCE mGMInstancePtr;
   OgreNewtBody *mBody;

	gm::GMVARIABLE *pX;
	gm::GMVARIABLE *pY;
	gm::GMVARIABLE *pZ;
	gm::GMVARIABLE *pPitch;
	gm::GMVARIABLE *pRoll;
	gm::GMVARIABLE *pScaleX;
	gm::GMVARIABLE *pScaleY;
	gm::GMVARIABLE *pScaleZ;

	double mLastX;
	double mLastY;
	double mLastZ;
	double mLastYaw;
	double mLastPitch;
	double mLastRoll;
	double mLastScaleX;
	double mLastScaleY;
	double mLastScaleZ;
};

enum
{
   OVERLAY_PANEL = 1,
   OVERLAY_BORDER_PANEL,
   OVERLAY_TEXT_AREA
};

enum
{
   MO_TYPE_BILLBOARD_CHAIN = 1,
   MO_TYPE_BILLBOARD_SET,
   MO_TYPE_ENTITY,
   MO_TYPE_LIGHT,
   MO_TYPE_PARTICLE_SYSTEM,
   MO_TYPE_RIBBON_TRAIL,
   MO_TYPE_DEFAULT_SCENE_MANAGER,
   MO_TYPE_OCTREE_SCENE_MANAGER,
   MO_TYPE_TERRAIN_SCENE_MANAGER
};

unsigned int mWindowWidth = 0;
unsigned int mWindowHeight = 0;
unsigned int mHWnd = 0;
bool mFullscreen = false;
bool mUseVSync = false;
int mFSAALevel = 0;
int mFSAAQuality = 0;
Ogre::String mRenderEngine = "";
Ogre::String mLogFile = "";
Ogre::String mPluginsCfg = "";
Ogre::String mOgreCfg = "";

Ogre::OctreePlugin *mOctreePlugin = NULL;
Ogre::ParticleFXPlugin *mParticleFXPlugin = NULL;
Ogre::D3D9Plugin *mD3D9Plugin = NULL;
Ogre::GLPlugin *mGLPlugin = NULL;
Ogre::CgPlugin *mCGPlugin = NULL;

Ogre::Root *mRoot = NULL;
Ogre::SceneManager *mSceneMgr = NULL;
Ogre::Camera *mCamera = NULL;
Ogre::Viewport* mViewPort = NULL;
Ogre::RenderWindow* mRenderWindow = NULL;
SkyX::SkyX* mSkyX = NULL;
//GMFrameListener* mFrameListener = NULL;

gm::CGMAPI *mGMAPI = NULL;
gm::GMVARIABLE *mVectorX = NULL;
gm::GMVARIABLE *mVectorY = NULL;
gm::GMVARIABLE *mVectorZ = NULL;
gm::GMVARIABLE *mEulerYaw = NULL;
gm::GMVARIABLE *mEulerPitch = NULL;
gm::GMVARIABLE *mEulerRoll = NULL;
int xsymbol = 0;

HANDLE gMutex = NULL;

Ogre::Material::LodDistanceList mLODLevels;
Ogre::String mCubeTextureNames[6];
//MOC::CollisionTools mCollisionTools;

typedef std::map<Ogre::SceneNode *, GMInstance> SceneNodeMap;
SceneNodeMap mSceneNodeAttachments;

//typedef std::map<OgreNewt::Body *, Ogre::SceneNode *> NewtonBodyMap;
//NewtonBodyMap mNewtonBodyAttachments;

typedef std::map<Ogre::SceneManager *, GMFrameListener*> SceneFrameListenerMap;
SceneFrameListenerMap mSceneListener;

typedef std::map<Ogre::SceneManager *, MOC::CollisionTools*> SceneCollisionToolsMap;
SceneCollisionToolsMap mSceneCollisionMap;

typedef std::map<OgreNewt::Collision *, OgreNewt::CollisionPtr> NewtonCollisionMap;
NewtonCollisionMap mNewtonCollisionMap;

//typedef std::map<std::pair<OgreNewt::MaterialID *, GMCallback> NewtonMaterialMap;
//NewtonMaterialMap mNewtonMaterialMap;


// Helper functions
Ogre::String GenerateUniqueName()
{
   static unsigned int index = 0;
   static Ogre::String base_name = "GMUnique";

   // If for some unholy reason we've created over 4,294,967,295 instances
   // we ensure that we don't reuse an existing instance name
   if (index == 0)
      base_name += "_";

   return base_name + Ogre::StringConverter::toString(index++);
}

float GetRedFromGMColor(double color)
{
   return (float)(((int)color & 0xFF)) / 255;
}

float GetGreenFromGMColor(double color)
{
   return (float)((((int)color >> 8) & 0xFF)) / 255;
}

float GetBlueFromGMColor(double color)
{
   return (float)((((int)color >> 16) & 0xFF)) / 255;
}

template<typename T>
T ConvertFromGMPointer(double ptr)
{
   T obj = reinterpret_cast<T>(static_cast<intptr_t>(ptr));

   if (obj == NULL)
      LogError("Invalid object ID passed from GameMaker!");

   return obj;
}

template<typename T>
double ConvertToGMPointer(T ptr)
{
   return static_cast<double>(reinterpret_cast<intptr_t>(ptr));
}

double ConvertToGMYaw(Ogre::Real yaw)
{
   double gm_yaw = yaw;

   if (gm_yaw >= -90.0)
      gm_yaw += 90.0;
   else
      gm_yaw = 360.0 + (gm_yaw + 90.0);

   if (gm_yaw >= 360.0) gm_yaw = 0.0;

   return gm_yaw;
}

Ogre::Real ConvertFromGMYaw(double yaw)
{
   Ogre::Real ogre_yaw = yaw;

   // We may have passed in values that are greater or less than
   // the yaw constraints, so wrap these around.
   if (ogre_yaw >= 360)
      ogre_yaw -= 360;
   else if (ogre_yaw < 0)
      ogre_yaw += 360;

   if (ogre_yaw <= 90.0)
      ogre_yaw = abs(ogre_yaw - 90);
   else if (ogre_yaw <= 180.0)
      ogre_yaw = 270 + abs(ogre_yaw - 180);
   else if (ogre_yaw <= 270.0)
      ogre_yaw = 180 + abs(ogre_yaw - 270);
   else
      ogre_yaw = 90 + abs(ogre_yaw - 360);

   return ogre_yaw;
}

void AcquireGMVectorGlobals()
{
   if (!mGMAPI)
      return;

   static int symbolVectorX = mGMAPI->GetSymbolID("vector_resx");
   static int symbolVectorY = mGMAPI->GetSymbolID("vector_resy");
   static int symbolVectorZ = mGMAPI->GetSymbolID("vector_resz");

   gm::GMVARIABLE* varArray = (gm::GMVARIABLE*) mGMAPI->GetGlobalVariableListPtr()->variables;
   int varCount = mGMAPI->GetGlobalVariableListPtr()->count;
   int acquiredCount = 0;
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].symbolId == symbolVectorX)
      {
         mVectorX = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolVectorY)
      {
         mVectorY = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolVectorZ)
      {
         mVectorZ = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }

      if (acquiredCount >= 3)
         break;
   }
}

void AcquireGMEulerGlobals()
{
   if (!mGMAPI)
      return;

   static int symbolEulerYaw = mGMAPI->GetSymbolID("euler_yaw");
   static int symbolEulerPitch = mGMAPI->GetSymbolID("euler_pitch");
   static int symbolEulerRoll = mGMAPI->GetSymbolID("euler_roll");

   gm::GMVARIABLE* varArray = (gm::GMVARIABLE*) mGMAPI->GetGlobalVariableListPtr()->variables;
   int varCount = mGMAPI->GetGlobalVariableListPtr()->count;
   int acquiredCount = 0;
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].symbolId == symbolEulerYaw)
      {
         mEulerYaw = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolEulerPitch)
      {
         mEulerPitch = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolEulerRoll)
      {
         mEulerRoll = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }

      if (acquiredCount >= 3)
         break;
   }
}

void AcquireGMLocalVariablePointers(GMInstance *gminst)
{
   if (!mGMAPI)
      return;

   // This function acquires all needed local variables for a GM object.
   // We do it this way for two reasons:
   //   1) Previously acquired pointers are NOT guaranteed to be valid each frame
   //   2) Manually calling GetLocalVariablePtr for each variable is SLOW!
   static int symbolZ = mGMAPI->GetSymbolID("z");
   static int symbolPitch = mGMAPI->GetSymbolID("pitch");
   static int symbolRoll = mGMAPI->GetSymbolID("roll");
   static int symbolScaleX = mGMAPI->GetSymbolID("scalex");
   static int symbolScaleY = mGMAPI->GetSymbolID("scaley");
   static int symbolScaleZ = mGMAPI->GetSymbolID("scalez");

   gm::GMVARIABLE* varArray = gminst->mGMInstancePtr->variableListPtr->variables;
   int varCount = gminst->mGMInstancePtr->variableListPtr->count;
   int acquiredCount = 0;

   for ( int i = 0; i < varCount; i++ )
   {
      if (varArray[i].symbolId == symbolZ)
      {
         gminst->pZ = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolPitch)
      {
         gminst->pPitch = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolRoll)
      {
         gminst->pRoll = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolScaleX)
      {
         gminst->pScaleX = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolScaleY)
      {
         gminst->pScaleY = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolScaleZ)
      {
         gminst->pScaleZ = (gm::PGMVARIABLE)(varArray + i);
         acquiredCount++;
      }

      if (acquiredCount >= 6)
         break;
   }
}


Ogre::Real CalcTerrainHeight(Ogre::Real x, Ogre::Real z, void*)
{
   if (mSceneMgr == NULL)
      return -999999;

   MOC::CollisionTools *ct = mSceneCollisionMap[mSceneMgr];

   if (ct == NULL)
      return -999999;

   return (Ogre::Real)ct->getTSMHeightAt(x, z);
}

void DisplayError(Ogre::String error_msg)
{
   MessageBoxA(NULL, error_msg.c_str(), "GMOgre3D", MB_OK | MB_ICONERROR | MB_TASKMODAL);
}

void LogError(Ogre::String error_msg)
{
   Ogre::LogManager::getSingleton().getDefaultLog()->logMessage(error_msg, Ogre::LML_CRITICAL);
}

void LogNormal(Ogre::String error_msg)
{
   Ogre::LogManager::getSingleton().getDefaultLog()->logMessage(error_msg, Ogre::LML_NORMAL);
}

void LogTrivial(Ogre::String error_msg)
{
   Ogre::LogManager::getSingleton().getDefaultLog()->logMessage(error_msg, Ogre::LML_TRIVIAL);
}

GMFN double EnableDisplayFPS(double enable);

#endif
