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
#include "NewtonBallAndSocketJoint.h"
#include "NewtonBody.h"
#include "NewtonCollision.h"
#include "NewtonContact.h"
#include "NewtonHingeJoint.h"
#include "NewtonMaterial.h"
#include "NewtonMaterialPair.h"
#include "NewtonSliderJoint.h"
#include "NewtonWorld.h"
#include "NewtonPlayerController.h"
#include "MovableText.h"
#include "MovableObject.h"
#include "Mesh.h"
#include "CCS.h"
#include "CCS_FreeCameraMode.h"
#include "CCS_ClosestToTargetCameraMode.h"
#include "CCS_FixedTrackingCameraMode.h"
#include "CCS_OrbitalCameraMode.h"
#include "CCS_ChaseFreeYawAxisCameraMode.h"
#include "CCS_FixedDirectionCameraMode.h"
#include "CCS_FirstPersonCameraMode.h"
#include "CCS_ThroughTargetCameraMode.h"
#include "CCS_PlaneBindedCameraMode.h"
#include "CCS_ChaseCameraMode.h"
#include "CCS_FixedCameraMode.h"
#include "GMApi.h"
#include "LockMutex.h"
#include "RibbonTrail.h"
#include "GUISystem.h"
#include "GUIWindow.h"
#include "GUIImageSet.h"
#include "GUITexture.h"
#include "GUIPushButton.h"
#include "GUIEditBox.h"
#include "GUIMultiLineEditBox.h"
#include "GUICheckBox.h"
#include "GUIRadioButton.h"
#include "GUITabControl.h"
#include "GUIComboBox.h"
#include "GUIListBox.h"
#include "GUIItemListBox.h"
#include "GUIProgressBar.h"
#include "GUIPopupMenu.h"
#include "GUIMenuBar.h"
#include "GUIMenuItem.h"
#include "GUIMultiColumnListBox.h"
#include "GUISpinner.h"
#include "GUISlider.h"
#include "PSSMShadowCameraSetup.h"
#include "GPUProgramParameters.h"
#include <OgreDynLib.h>
#include <algorithm>


void UpdateSceneNodeAttachments();

// We delay load DX9 so it's not required if running GL
#ifdef _DEBUG
#	pragma comment(lib, "d3dx9d.lib")
#else
#	pragma comment(lib, "d3dx9.lib")
#endif


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
      static Ogre::OctreePlugin *mOctreePlugin = NULL;
      static Ogre::ParticleFXPlugin *mParticleFXPlugin = NULL;
      static Ogre::D3D9Plugin *mD3D9Plugin = NULL;
      static Ogre::GLPlugin *mGLPlugin = NULL;
      static Ogre::CgPlugin *mCGPlugin = NULL;

      if (mOctreePlugin == NULL)
         mOctreePlugin = new Ogre::OctreePlugin;

      if (mParticleFXPlugin == NULL)
         mParticleFXPlugin = new Ogre::ParticleFXPlugin;

      if (mCGPlugin == NULL)
         mCGPlugin = new Ogre::CgPlugin;

      if (mD3D9Plugin == NULL && render_engine == 1)
      {
         // Verify a later version of DX is installed and if not display a nice
         // error message.  Otherwise the DX renderer cannot load and the game
         // will crash!
         HMODULE hmod = LoadLibraryA("D3DX9_41.dll");
         if (!hmod)
         {
            DisplayError("Unable to find a recent version of DirectX 9. Please visit Microsoft's website and update your DirectX 9 version.");
            return false;
         }
         FreeLibrary(hmod);

         mD3D9Plugin = new Ogre::D3D9Plugin;
      }

      if (mGLPlugin == NULL && render_engine == 2)
         mGLPlugin = new Ogre::GLPlugin;

      if (mOctreePlugin != NULL)
         mRoot->installPlugin(mOctreePlugin);
      if (mParticleFXPlugin != NULL)
         mRoot->installPlugin(mParticleFXPlugin);
      if (mCGPlugin != NULL)
         mRoot->installPlugin(mCGPlugin);
      if (mGLPlugin != NULL)
         mRoot->installPlugin(mGLPlugin);
      if (mD3D9Plugin != NULL)
         mRoot->installPlugin(mD3D9Plugin);

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
      opts["externalWindowHandle"] = Ogre::StringConverter::toString((size_t)mHWnd);
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


GMFN double EnableRenderWindow(double enable)
{
   if (enable != 0)
   {
      // Attach to existing GM window
      Ogre::NameValuePairList opts;
      opts["externalWindowHandle"] = Ogre::StringConverter::toString((size_t)mHWnd);
      opts["left"] = "0";
      opts["top"] = "0";
      if (mUseVSync)
         opts["vsync"] = "true";
      opts["FSAA"] = Ogre::StringConverter::toString(mFSAALevel);
      opts["FSAAQuality"] = Ogre::StringConverter::toString(mFSAAQuality);

      mRenderWindow->create("GMOGRE 3D Window", mWindowWidth, mWindowHeight, mFullscreen, &opts);
   }
   else
   {
      mRenderWindow->destroy();
   }

   mRenderWindow->setActive((enable != 0));
   mRenderWindow->setAutoUpdated((enable != 0));

   return TRUE;
}


GMFN double ShutdownEngine()
{
   try
   {
      if (mGUIRenderer != NULL)
      {
         //delete mGUIRenderer;
         mGUIRenderer = NULL;
      }

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


GMFN double RenderFrame()
{
   if (mRoot == NULL)
      return FALSE;

   if (mRenderWindow == NULL)
      return FALSE;

   UpdateSceneNodeAttachments();

   if (mRenderWindow->isActive())
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
   mFSAALevel = (int)fsaa_level;
   mFSAAQuality = (int)fsaa_quality;

   // Ensure the combinations are valid!
   mFSAALevel = std::min(6, mFSAALevel);
   if (mFSAALevel == 5)
      mFSAALevel = 4;
   else if (mFSAALevel == 3)
      mFSAALevel = 2;

   if (mFSAALevel > 2)
      mFSAAQuality = 0;
   else if (mFSAALevel == 1)
      mFSAAQuality = std::min(2, mFSAAQuality);

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
   return "GMOgre3D v1.1";
}

GMFN double SetRotationMode(double mode)
{
   mRotationMode = static_cast<RotationMode>((int)mode);

   return TRUE;
}

GMFN double HasCapability(double capability)
{
   if (mRenderWindow == NULL)
      return FALSE;

   if (mRoot->getRenderSystem() == NULL)
      return FALSE;

   Ogre::RenderSystemCapabilities *rsc = (Ogre::RenderSystemCapabilities *)mRoot->getRenderSystem()->getCapabilities();

   if (rsc == NULL)
      return FALSE;

   return rsc->hasCapability(static_cast<Ogre::Capabilities>((int)capability));
}


GMFN double IsGPUSyntaxSupported(char *syntax)
{
   return Ogre::GpuProgramManager::getSingleton().isSyntaxSupported(syntax);
}


GMFN double GetAverageFPS()
{
   Ogre::RenderSystem *rs = Ogre::Root::getSingleton().getRenderSystem();

   if (rs == NULL)
      return 0;

   Ogre::RenderTarget *rt = rs->getRenderTarget("GMOGRE 3D Window");

   if (rt == NULL)
      return 0;

   return rt->getAverageFPS();
}


GMFN double GetLastFPS()
{
   Ogre::RenderSystem *rs = Ogre::Root::getSingleton().getRenderSystem();

   if (rs == NULL)
      return 0;

   Ogre::RenderTarget *rt = rs->getRenderTarget("GMOGRE 3D Window");

   if (rt == NULL)
      return 0;

   return rt->getLastFPS();
}


GMFN double GetBestFPS()
{
   Ogre::RenderSystem *rs = Ogre::Root::getSingleton().getRenderSystem();

   if (rs == NULL)
      return 0;

   Ogre::RenderTarget *rt = rs->getRenderTarget("GMOGRE 3D Window");

   if (rt == NULL)
      return 0;

   return rt->getBestFPS();
}


GMFN double GetWorstFPS()
{
   Ogre::RenderSystem *rs = Ogre::Root::getSingleton().getRenderSystem();

   if (rs == NULL)
      return 0;

   Ogre::RenderTarget *rt = rs->getRenderTarget("GMOGRE 3D Window");

   if (rt == NULL)
      return 0;

   return rt->getWorstFPS();
}


GMFN double GetBatchCount()
{
   Ogre::RenderSystem *rs = Ogre::Root::getSingleton().getRenderSystem();

   if (rs == NULL)
      return 0;

   Ogre::RenderTarget *rt = rs->getRenderTarget("GMOGRE 3D Window");

   if (rt == NULL)
      return 0;

   return rt->getBatchCount();
}


GMFN double GetTriangleCount()
{
   Ogre::RenderSystem *rs = Ogre::Root::getSingleton().getRenderSystem();

   if (rs == NULL)
      return 0;

   Ogre::RenderTarget *rt = rs->getRenderTarget("GMOGRE 3D Window");

   if (rt == NULL)
      return 0;

   return rt->getTriangleCount();
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
                  //node->setPosition(ConvertFromGMAxis(gminst->mGMInstancePtr->x, *gminst->pZ, gminst->mGMInstancePtr->y));
                  SetSceneNodePosition(ConvertToGMPointer(node), gminst->mGMInstancePtr->x, gminst->mGMInstancePtr->y, *gminst->pZ);

                  if (gminst->BodyAttached && gminst->mBody)
                  {
                     Ogre::Vector3 pos = node->_getDerivedPosition();
                     SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), pos.x, pos.z, pos.y);
                     //SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), gminst->mGMInstancePtr->x, gminst->mGMInstancePtr->y, *gminst->pZ);
                  }
               }

               // Update scene node rotation if GM rotation changed (either from the
               // user manually changing or from a previous Newton body changing them).
               if (*gminst->pYaw != gminst->mLastYaw || *gminst->pPitch != gminst->mLastPitch || *gminst->pRoll != gminst->mLastRoll)
               {
                  GMRotChanged = true;
                  //node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(*gminst->pYaw)), Ogre::Degree(*gminst->pPitch), Ogre::Degree(*gminst->pRoll)));
                  SetSceneNodeOrientation(ConvertToGMPointer(node), *gminst->pYaw, *gminst->pPitch, *gminst->pRoll);

                  if (gminst->BodyAttached && gminst->mBody)
                  {
                     Ogre::Quaternion quat = node->_getDerivedOrientation();
                     SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), ConvertToGMYaw(quat.getYaw().valueDegrees()), quat.getPitch().valueDegrees(), quat.getRoll().valueDegrees());
                     //SetNewtonBodyOrientation(ConvertToGMPointer(gminst->mBody), *gminst->pYaw, *gminst->pPitch, *gminst->pRoll);
                  }
               }

               // Update scene node scale if GM scale changed.
               if (*gminst->pScaleX != gminst->mLastScaleX || *gminst->pScaleY != gminst->mLastScaleY || *gminst->pScaleZ != gminst->mLastScaleZ)
               {
                  //node->scale(ConvertFromGMAxis(*gminst->pScaleX, *gminst->pScaleZ, *gminst->pScaleY));
                  SetSceneNodeScale(ConvertToGMPointer(node), *gminst->pScaleX, *gminst->pScaleY, *gminst->pScaleZ);
               }

               // Update GM vars if needed
               if (!GMPosChanged)
               {
                  Ogre::Vector3 pos = ConvertToGMAxis(node->getPosition());
                  gminst->mGMInstancePtr->x = pos.x;
                  gminst->mGMInstancePtr->y = pos.y;
                  *gminst->pZ = pos.z;
               }
               if (!GMRotChanged)
               {
                  Ogre::Quaternion orient = node->getOrientation();
                  *gminst->pYaw = ConvertToGMYaw(orient.getYaw().valueDegrees());
                  *gminst->pPitch = orient.getPitch().valueDegrees();
                  *gminst->pRoll = orient.getRoll().valueDegrees();
               }
               {
                  Ogre::Vector3 scale = ConvertToGMAxis(node->getScale());
                  *gminst->pScaleX = scale.x;
                  *gminst->pScaleY = scale.y;
                  *gminst->pScaleZ = scale.z;
               }
            }

            if (gminst->GMInstanceAttached && gminst->mGMInstancePtr)
            {
               gminst->mLastX = gminst->mGMInstancePtr->x;
               gminst->mLastY = gminst->mGMInstancePtr->y;
               gminst->mLastZ = *gminst->pZ;

               gminst->mLastYaw = *gminst->pYaw;
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
