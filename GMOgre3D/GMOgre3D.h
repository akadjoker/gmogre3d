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
#include "OgreLightMap.h"
#include "CollisionTools.h"
#include "OgreNewt_Body.h"
#include "OgreNewt_Collision.h"
#include "FrameListener.h"
#include "GMSceneManagerListener.h"
#include "MaterialListener.h"
#include "GMCompositorListener.h"
#include "GMTerrainPageSourceListener.h"
#include "RendererModules/Ogre/CEGUIOgreRenderer.h"
#include "Axes.h"
#include "OgreDotSceneLoader.h"
#include "PerfTimer.h"
#include "GM_API.h"
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
Ogre::Viewport* mViewPort = NULL;
Ogre::RenderWindow* mRenderWindow = NULL;
SkyX::SkyX* mSkyX = NULL;
//GMFrameListener* mFrameListener = NULL;
GMMaterialListener* mMaterialListener = NULL;

CEGUI::OgreRenderer *mGUIRenderer = NULL;
DotSceneLoader *mDotSceneLoader = NULL;

HANDLE gMutex = NULL;

Ogre::Material::LodValueList mLODLevels;
Ogre::String mCubeTextureNames[6];
//MOC::CollisionTools mCollisionTools;

typedef std::map<Ogre::SceneNode *, GMInstance> SceneNodeMap;
SceneNodeMap mSceneNodeAttachments;

//typedef std::map<OgreNewt::Body *, Ogre::SceneNode *> NewtonBodyMap;
//NewtonBodyMap mNewtonBodyAttachments;

typedef std::map<Ogre::SceneManager *, GMFrameListener*> SceneFrameListenerMap;
SceneFrameListenerMap mSceneListener;

typedef std::map<Ogre::SceneManager *, GMSceneManagerListener*> SceneManagerListenerMap;
SceneManagerListenerMap mSceneManagerListener;

typedef std::map<Ogre::SceneManager *, MOC::CollisionTools*> SceneCollisionToolsMap;
SceneCollisionToolsMap mSceneCollisionMap;

typedef std::map<OgreNewt::Collision *, OgreNewt::CollisionPtr> NewtonCollisionMap;
NewtonCollisionMap mNewtonCollisionMap;

//typedef std::map<std::pair<OgreNewt::MaterialID *, GMCallback> NewtonMaterialMap;
//NewtonMaterialMap mNewtonMaterialMap;

typedef std::map<Ogre::String, GMCompositorListener*> CompositorListenerMap;
CompositorListenerMap mCompositorListener;

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

Ogre::Real GetRedFromGMColor(double color)
{
   return (Ogre::Real)(((int)color & 0xFF)) / 255;
}

Ogre::Real GetGreenFromGMColor(double color)
{
   return (Ogre::Real)((((int)color >> 8) & 0xFF)) / 255;
}

Ogre::Real GetBlueFromGMColor(double color)
{
   return (Ogre::Real)((((int)color >> 16) & 0xFF)) / 255;
}

double ConvertColorToGMColor(double r, double g, double b)
{
   return (int)(r*255.0) + ((int)(g*255.0) << 8) + ((int)(b*255.0) << 16);
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
   Ogre::Real ogre_yaw = (Ogre::Real)yaw;

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

double ConvertToGMPitch(Ogre::Real pitch)
{
   double gm_pitch = pitch;

   if (gm_pitch < 0.0)
      gm_pitch += 360;

   return gm_pitch;
}

Ogre::Real ConvertFromGMPitch(double pitch)
{
   Ogre::Real ogre_pitch = (Ogre::Real)pitch;

   while (ogre_pitch >= 360)
      ogre_pitch -= 360;

   if (ogre_pitch > 180)
      ogre_pitch -= 360;

   return ogre_pitch;
}

double ConvertToGMRoll(Ogre::Real roll)
{
   double gm_roll = roll;

   while (gm_roll < 0.0)
      gm_roll += 360;

   return gm_roll;
}

Ogre::Real ConvertFromGMRoll(double roll)
{
   Ogre::Real ogre_roll = (Ogre::Real)roll;

   while (ogre_roll >= 360)
      ogre_roll -= 360;

   return ogre_roll;
}

Euler QuaternionToEuler(Ogre::Quaternion quat)
{
   Ogre::Matrix3 mat;
   Ogre::Radian yRad, pRad, rRad;

   quat.ToRotationMatrix(mat);
   mat.ToEulerAnglesYXZ(yRad, pRad, rRad);

   return Euler(yRad, pRad, rRad);
}

Ogre::Quaternion EulerToQuaternion(Ogre::Real yaw, Ogre::Real pitch, Ogre::Real roll)
{
   Ogre::Matrix3 mat;
   Ogre::Quaternion quat;

   mat.FromEulerAnglesYXZ(Ogre::Degree(yaw), Ogre::Degree(pitch), Ogre::Degree(roll));
   quat.FromRotationMatrix(mat);

   return quat;
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
