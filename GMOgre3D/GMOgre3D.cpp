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
#include "SubEntity.h"
#include "Vector.h"
#include "Euler.h"
#include "Plane.h"
#include "NewtonBody.h"
#include "NewtonCollision.h"
#include "NewtonContact.h"
#include "NewtonMaterial.h"
#include "NewtonMaterialPair.h"
#include "NewtonWorld.h"
#include "NewtonPlayerController.h"
#include "MovableText.h"
#include "MovableObject.h"
#include "GMApi.h"


void UpdateSceneNodeAttachments();

GMFN double Initialize(char *plugins_cfg, char *ogre_cfg, char *log_file)
{
   try
   {
      mPluginsCfg = plugins_cfg;
      mOgreCfg = ogre_cfg;
      mLogFile = log_file;

      unsigned long result = 0;
      if (!mGMAPI)
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


GMFN double StartEngine(double render_engine, double hwnd, double window_width, double window_height, double fullscreen)
{
   try
   {
      if (mRoot != NULL)
      {
         LogError("GMOgre3D has already been started!");
         return FALSE;
      }

      if (!gMutex)
         gMutex = CreateMutex(NULL, FALSE, NULL);

      mWindowWidth = window_width;
      mWindowHeight = window_height;
      mHWnd = hwnd;
      mFullscreen = (fullscreen != 0);

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
      if (mUseVSync)
         opts["vsync"] = "true";
      opts["FSAA"] = Ogre::StringConverter::toString(mFSAALevel);
      opts["FSAAQuality"] = Ogre::StringConverter::toString(mFSAAQuality);

      // Fullscreen causes issues with input... it may be that it's actually creating a
      // whole NEW window and not using GameMakers window.  Either way no keyboard input.
      // But not going fullscreen everything seems to work, input included.
      mFullscreen = false;

      mRenderWindow = mRoot->createRenderWindow("GMOGRE 3D Window", mWindowWidth, mWindowHeight, mFullscreen, &opts);

      //if (mFrameListener == NULL)
      //   mFrameListener = new GMFrameListener;
      //mRoot->addFrameListener(mFrameListener);

      if (mGMAPI)
      {
         // Setup the links to our GM vector/quaternion/euler result variables
         AcquireGMVectorGlobals();
         AcquireGMEulerGlobals();
      }
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

      if (gMutex)
         CloseHandle(gMutex);
   }    

   return TRUE;
}


GMFN double RenderFrame()
{
   if (mRoot == NULL)
      return FALSE;

   UpdateSceneNodeAttachments();

   mRoot->renderOneFrame();

   return TRUE;
}


GMFN double EnableWaitForVSync(double enable)
{
   mUseVSync = (enable != 0);

   return TRUE;
}


GMFN double SetFSAA(double fsaa_level, double fsaa_quality)
{
   mFSAALevel = (unsigned int)fsaa_level;
   mFSAAQuality = (unsigned int)fsaa_quality;

   return TRUE;
}


GMFN double EnableDisplayFPS(double enable)
{
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


GMFN char *GetOgre3DVersion()
{
   return "GMOgre3D v0.92";
}


void UpdateSceneNodeAttachments()
{
   LockMutex lm(gMutex);

   try
   {
      if (mGMAPI)
      {
         // Cycle through all scene nodes attached to GM instances, and update position/scale/orientation
         SceneNodeMap::iterator iter = mSceneNodeAttachments.begin();
         SceneNodeMap::iterator end_iter = mSceneNodeAttachments.end();

         while (iter != end_iter)
         {
            Ogre::SceneNode *node = iter->first;
            GMInstance *gminst = &iter->second;

            if (gminst->GMInstanceAttached && gminst->mGMInstancePtr)
            {
               gminst->mGMInstancePtr = mGMAPI->GetInstancePtr((int)gminst->mGMInstanceID);
               AcquireGMLocalVariablePointers(gminst);

               bool GMPosChanged = false;
               bool GMRotChanged = false;

               // Update scene node position if GM position changed (either from the
               // user manually changing or from a previous Newton body changing them).
               if (gminst->mGMInstancePtr->x != gminst->mLastX || gminst->mGMInstancePtr->y != gminst->mLastY || *gminst->pZ != gminst->mLastZ)
               {
                  GMPosChanged = true;
                  node->setPosition(gminst->mGMInstancePtr->x, *gminst->pZ, gminst->mGMInstancePtr->y);

                  if (gminst->BodyAttached && gminst->mBody)
                     SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), gminst->mGMInstancePtr->x, gminst->mGMInstancePtr->y, *gminst->pZ);
               }

               // Update scene node rotation if GM rotation changed (either from the
               // user manually changing or from a previous Newton body changing them).
               if (gminst->mGMInstancePtr->direction != gminst->mLastYaw || *gminst->pPitch != gminst->mLastPitch || *gminst->pRoll != gminst->mLastRoll)
               {
                  GMRotChanged = true;
                  node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(gminst->mGMInstancePtr->direction)), Ogre::Degree(*gminst->pPitch), Ogre::Degree(*gminst->pRoll)));

                  if (gminst->BodyAttached && gminst->mBody)
                     SetNewtonBodyOrientation(ConvertToGMPointer(gminst->mBody), gminst->mGMInstancePtr->direction, *gminst->pPitch, *gminst->pRoll);
               }

               // Update scene node scale if GM scale changed.
               if (*gminst->pScaleX != gminst->mLastScaleX || *gminst->pScaleY != gminst->mLastScaleY || *gminst->pScaleZ != gminst->mLastScaleZ)
               {
                  node->scale(*gminst->pScaleX, *gminst->pScaleZ, *gminst->pScaleY);
               }

               // Update GM vars if needed
               if (!GMPosChanged)
               {
                  Ogre::Vector3 pos = node->getPosition();
                  gminst->mGMInstancePtr->x = pos.x;
                  gminst->mGMInstancePtr->y = pos.z;
                  *gminst->pZ = pos.y;
               }
               if (!GMRotChanged)
               {
                  Ogre::Quaternion orient = node->getOrientation();
                  gminst->mGMInstancePtr->direction = ConvertToGMYaw(orient.getYaw().valueDegrees());
                  *gminst->pPitch = orient.getPitch().valueDegrees();
                  *gminst->pRoll = orient.getRoll().valueDegrees();
               }
               {
                  Ogre::Vector3 scale = node->getScale();
                  *gminst->pScaleX = scale.x;
                  *gminst->pScaleY = scale.z;
                  *gminst->pScaleZ = scale.y;
               }
            }

            if (gminst->GMInstanceAttached && gminst->mGMInstancePtr)
            {
               gminst->mLastX = gminst->mGMInstancePtr->x;
               gminst->mLastY = gminst->mGMInstancePtr->y;
               gminst->mLastZ = *gminst->pZ;

               gminst->mLastYaw = gminst->mGMInstancePtr->direction;
               gminst->mLastPitch = *gminst->pPitch;
               gminst->mLastRoll = *gminst->pRoll;

               gminst->mLastScaleX = *gminst->pScaleX;
               gminst->mLastScaleY = *gminst->pScaleY;
               gminst->mLastScaleZ = *gminst->pScaleZ;
            }
            ++iter;
         }
      }
   }
   catch(...)
   {
   }
}
