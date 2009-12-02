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
#include "OgreText.h"
#include "OgreSprite.h"
#include "OgreEuler.h"
#include "FrameListener.h"
#include "CollisionTools.h"
#include <GMAPI.h>

#define GMFN extern "C" __declspec(dllexport)

struct GMInstance
{
   int mGMInstanceID;

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

unsigned int mWindowWidth = 0;
unsigned int mWindowHeight = 0;
unsigned int mHWnd = 0;
bool mFullscreen = false;
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
GMFrameListener* mFrameListener = NULL;

gm::CGMAPI *mGMAPI = NULL;
gm::GMVARIABLE *mVectorX = NULL;
gm::GMVARIABLE *mVectorY = NULL;
gm::GMVARIABLE *mVectorZ = NULL;
gm::GMVARIABLE *mEulerYaw = NULL;
gm::GMVARIABLE *mEulerPitch = NULL;
gm::GMVARIABLE *mEulerRoll = NULL;

Ogre::Material::LodDistanceList mLODLevels;
Ogre::String mCubeTextureNames[6];
MOC::CollisionTools mCollisionTools;

typedef std::map<Ogre::SceneNode *, GMInstance> SceneNodeMap;
SceneNodeMap mSceneNodeGMInstances;


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

#endif
