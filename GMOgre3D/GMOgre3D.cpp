// GMOgre3D.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "GMOgre3D.h"
#include "Resource.h"
#include "SceneManager.h"
#include "Viewport.h"
#include "Camera.h"
#include "Light.h"
#include "SceneNode.h"
#include "Entity.h"
#include "Font.h"
#include "SkyX.h"
#include "OgreText.h"
#include "Overlay.h"
#include "OverlayElement.h"
#include "Text.h"
#include "Material.h"
#include "Technique.h"
#include "Pass.h"
#include "TextureUnitState.h"
#include "BillboardSet.h"
#include "BillboardChain.h"
#include "Billboard.h"
#include "AnimationState.h"
#include "ParticleSystem.h"
#include "ParticleEmitter.h"
#include "SimpleSpline.h"
#include "Sprite.h"
#include "Texture.h"
#include "RaySceneQuery.h"
#include "Ray.h"
#include "Collision.h"
#include "StaticGeometry.h"
#include "ManualObject.h"
#include "Skeleton.h"
#include "Animation.h"
#include "NodeAnimationTrack.h"
#include "TransformKeyFrame.h"
#include "Bone.h"
#include "Compositor.h"
#include "CompositionTechnique.h"
#include "CompositionPass.h"
#include "TargetPass.h"
#include "PagedGeometry.h"
#include "TreeLoader3D.h"
#include "TreeLoader2D.h"
#include "GrassLoader.h"
#include "GrassLayer.h"
#include "Vector.h"
#include "Euler.h"
#include "Plane.h"
#include "GMApi.h"


GMFN double Initialize(char *plugins_cfg, char *ogre_cfg, char *log_file)
{
   try
   {
      mPluginsCfg = plugins_cfg;
      mOgreCfg = ogre_cfg;
      mLogFile = log_file;

      unsigned long result = 0;
      mGMAPI = gm::CGMAPI::Create( &result );
   }
   catch(Ogre::Exception& e)
   {
      DisplayError(e.what());
      return FALSE;
   }
   catch(...)
   {
      DisplayError("An unknown error has occurred initializing GMOgre!");
      return FALSE;
   }

   return TRUE;
}


GMFN double StartEngine(double render_engine, double hwnd, double window_width, double window_height)
{
   try
   {
      if (mRoot != NULL)
      {
         LogError("GMOgre3D has already been started!");
         return FALSE;
      }

      mWindowWidth = window_width;
      mWindowHeight = window_height;
      mHWnd = hwnd;

      if (render_engine == 2)
         mRenderEngine = "OpenGL";
      else if (render_engine == 3)
         mRenderEngine = "Direct3D10";
      else
         mRenderEngine = "Direct3D9";

      mRoot = new Ogre::Root(mPluginsCfg, mOgreCfg, mLogFile);

#ifdef OGRE_STATIC_LIB
      if (mOctreePlugin == NULL)
         mOctreePlugin = new Ogre::OctreePlugin;

      if (mParticleFXPlugin == NULL)
         mParticleFXPlugin = new Ogre::ParticleFXPlugin;

      if (mCGPlugin == NULL)
         mCGPlugin = new Ogre::CgPlugin;

      if (mD3D9Plugin == NULL)
         mD3D9Plugin = new Ogre::D3D9Plugin;

      if (mGLPlugin == NULL)
         mGLPlugin = new Ogre::GLPlugin;

      mRoot->installPlugin(mOctreePlugin);
      mRoot->installPlugin(mParticleFXPlugin);
      mRoot->installPlugin(mCGPlugin);

      mRoot->installPlugin(mD3D9Plugin);
      mRoot->installPlugin(mGLPlugin);

#endif

      // Load rendering system so we don't display Configuration Dialog
      Ogre::RenderSystemList *rsList = mRoot->getAvailableRenderers();
      Ogre::RenderSystemList::iterator it = rsList->begin();
      Ogre::RenderSystem *selectedRenderSystem=0;
      bool foundit = false;

      while (it != rsList->end())
      {
         selectedRenderSystem = *(it++);
         Ogre::String rname = selectedRenderSystem->getName();

         if (rname.find(mRenderEngine) == 0)
         {
            foundit = true;
            break;
         }
      }

      if (!foundit)
      {
         Ogre::String render_error;

         render_error = "'";
         render_error += render_engine;
         render_error += "' renderer not found!";
         LogError(render_error);
         return FALSE; //we didn't find it...
      }

      // We found it, we might as well use it!
      mRoot->setRenderSystem(selectedRenderSystem);

      mRoot->initialise(false);
 
           // Attach to existing GM window
      Ogre::NameValuePairList opts;
      opts["parentWindowHandle"] = Ogre::StringConverter::toString((size_t)mHWnd);
      opts["left"] = "0";
      opts["top"] = "0";

      mRenderWindow = mRoot->createRenderWindow("GMOGRE 3D Window", mWindowWidth, mWindowHeight, mFullscreen, &opts);
/*
      if (mFrameListener == NULL)
         mFrameListener = new GMFrameListener;
      mRoot->addFrameListener(mFrameListener);
*/
      // Setup the links to our GM vector/quaternion/euler result variables
      mVectorX = mGMAPI->GetGlobalVariablePtr(mGMAPI->GetSymbolID("vector_resx"));
      mVectorY = mGMAPI->GetGlobalVariablePtr(mGMAPI->GetSymbolID("vector_resy"));
      mVectorZ = mGMAPI->GetGlobalVariablePtr(mGMAPI->GetSymbolID("vector_resz"));

      mEulerYaw = mGMAPI->GetGlobalVariablePtr(mGMAPI->GetSymbolID("euler_yaw"));
      mEulerPitch = mGMAPI->GetGlobalVariablePtr(mGMAPI->GetSymbolID("euler_pitch"));
      mEulerRoll = mGMAPI->GetGlobalVariablePtr(mGMAPI->GetSymbolID("euler_roll"));
   }
   catch(Ogre::Exception& e)
   {
      DisplayError(e.what());
      LogError(e.what());
      return FALSE;
   }
   catch(...)
   {
      DisplayError("An unknown error has occurred starting the Ogre3D engine!");
      LogError("An unknown error has occurred starting the Ogre3D engine!");
      return FALSE;
   }


   return TRUE;
}


GMFN double ShutdownEngine()
{
   if (mRoot != NULL)
   {
      delete mRoot;

      //if (mFrameListener != NULL)
         //delete mFrameListener;

      mRoot = NULL;
      //mFrameListener = NULL;
      mSceneMgr = NULL;
      mRenderWindow = NULL;
   }    

   return TRUE;
}


GMFN double RenderFrame()
{
   if (mRoot == NULL)
      return FALSE;

   // Cycle through all scene nodes attached to GM instances, and update position/scale/orientation
   SceneNodeMap::iterator iter = mSceneNodeGMInstances.begin();
   SceneNodeMap::iterator end_iter = mSceneNodeGMInstances.end();

   while (iter != end_iter)
   {
      Ogre::SceneNode *node = iter->first;
      GMInstance &gminst = iter->second;

      gm::PGMINSTANCE gminstance = mGMAPI->GetInstancePtr(gminst.mGMInstanceID);
      if (gminstance == NULL)
      {
         LogError("GM object instance " + Ogre::StringConverter::toString(gminst.mGMInstanceID) + " not found, DetachSceneNodeGMInstance() must not have been called!");
         ++iter;
         continue;
      }

      if (gminstance->x != gminst.mLastX || gminstance->y != gminst.mLastY || *gminst.pZ != gminst.mLastZ)
      {
         node->setPosition(gminstance->x, *gminst.pZ, gminstance->y);
         gminst.mLastX = gminstance->x;
         gminst.mLastY = gminstance->y;
         gminst.mLastZ = *gminst.pZ;
      }

      if (gminstance->direction != gminst.mLastYaw || *gminst.pPitch != gminst.mLastPitch || *gminst.pRoll != gminst.mLastRoll)
      {
         node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(gminstance->direction)), Ogre::Degree(*gminst.pPitch), Ogre::Degree(*gminst.pRoll)));

         gminst.mLastYaw = gminstance->direction;
         gminst.mLastPitch = *gminst.pPitch;
         gminst.mLastRoll = *gminst.pRoll;
      }

      if (*gminst.pScaleX != gminst.mLastScaleX || *gminst.pScaleY != gminst.mLastScaleY || *gminst.pScaleZ != gminst.mLastScaleZ)
      {
         node->scale(*gminst.pScaleX, *gminst.pScaleZ, *gminst.pScaleY);
         gminst.mLastScaleX = *gminst.pScaleX;
         gminst.mLastScaleY = *gminst.pScaleY;
         gminst.mLastScaleZ = *gminst.pScaleZ;
      }

      ++iter;
   }

   mRoot->renderOneFrame();

   return TRUE;
}


GMFN double EnableWaitForVSync(double enable)
{
   if (mRoot == NULL)
      return FALSE;

   Ogre::RenderSystem *rs = mRoot->getRenderSystem();

   if (rs == NULL)
      return FALSE;

   rs->setWaitForVerticalBlank((enable != 0));

   return TRUE;
}


GMFN double EnableDisplayFPS(double enable)
{
   // Delete frame listener
   GMFrameListener *fl = mSceneListener[mSceneMgr];

   if (fl == NULL)
      return FALSE;

   fl->DisplayFPS((enable != 0));

   return TRUE;
}


GMFN double EnableMouseCursor(double enable)
{
   ShowCursor((enable != 0));

   return TRUE;
}

GMFN double SetLoggingLevel(double type)
{
   Ogre::LogManager::getSingleton().getDefaultLog()->setLogDetail(static_cast<Ogre::LoggingLevel>((int)type));

   return TRUE;
}


GMFN double LogMessage(char *error_msg, double level)
{
   if (level == 3)
      LogError(error_msg);
   else if (level == 2)
      LogNormal(error_msg);
   else
      LogTrivial(error_msg);
   
   return TRUE;
}


GMFN double SaveScreenshot(char *filename)
{
   if (mRenderWindow == NULL)
      return FALSE;

   mRenderWindow->writeContentsToFile(filename);
   
   return TRUE;
}
