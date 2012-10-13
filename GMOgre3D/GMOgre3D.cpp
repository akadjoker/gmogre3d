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
#include "CCS_RTSCameraMode.h"
#include "GM_API.h"
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
#include "Rectangle2D.h"
#include "Lightmap.h"
#include "DotSceneLoader.h"
#include "TagPoint.h"
#include "GUIScrollBar.h"
#include <OgreDynLib.h>
#include <algorithm>


void UpdateSceneNodeAttachments();

// We delay load DX9 so it's not required if running GL
#ifdef _DEBUG
#	pragma comment(lib, "d3dx9d.lib")
#	pragma comment(lib, "cg.lib")
#else
#	pragma comment(lib, "d3dx9.lib")
#	pragma comment(lib, "cg.lib")
#endif


GMFN double Initialize(double function_address_ptr, char *plugins_cfg, char *ogre_cfg, char *log_file)
{
   try
   {
      mPluginsCfg = plugins_cfg;
      mOgreCfg = ogre_cfg;
      mLogFile = log_file;

      unsigned long result = 0;
      if (!IsGMInitialized())
      {
         InitializeGM(function_address_ptr);
      }
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

      mRoot = OGRE_NEW Ogre::Root(mPluginsCfg, mOgreCfg, mLogFile);


#ifdef OGRE_STATIC_LIB
      static Ogre::OctreePlugin *mOctreePlugin = NULL;
      static Ogre::ParticleFXPlugin *mParticleFXPlugin = NULL;
      static Ogre::D3D9Plugin *mD3D9Plugin = NULL;
      static Ogre::GLPlugin *mGLPlugin = NULL;
      static Ogre::CgPlugin *mCGPlugin = NULL;

      if (mOctreePlugin == NULL)
         mOctreePlugin = OGRE_NEW Ogre::OctreePlugin;

      if (mParticleFXPlugin == NULL)
         mParticleFXPlugin = OGRE_NEW Ogre::ParticleFXPlugin;

      if (mCGPlugin == NULL)
      {
         // Only load our CG plugin if it exists!
         HMODULE hmod = LoadLibraryA("cg.dll");
         if (hmod)
         {
            FreeLibrary(hmod);
            mCGPlugin = OGRE_NEW Ogre::CgPlugin;
         }
      }

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

         mD3D9Plugin = OGRE_NEW Ogre::D3D9Plugin;
      }

      if (mGLPlugin == NULL && render_engine == 2)
         mGLPlugin = OGRE_NEW Ogre::GLPlugin;

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
      Ogre::RenderSystemList rsList = mRoot->getAvailableRenderers();
      Ogre::RenderSystemList::iterator it = rsList.begin();
      Ogre::RenderSystem *selectedRenderSystem=0;
      bool foundit = false;

      while (it != rsList.end())
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
      if (mFSAAQuality == 0)
         opts["FSAAQuality"] = "";
      else if (mFSAAQuality == 1)
         opts["FSAAQuality"] = "Quality";

      // Fullscreen causes issues with input... it may be that it's actually creating a
      // whole NEW window and not using GameMakers window.  Either way no keyboard input.
      // But not going fullscreen everything seems to work, input included.
      mFullscreen = false;

      mRenderWindow = mRoot->createRenderWindow("GMOGRE 3D Window", mWindowWidth, mWindowHeight, mFullscreen, &opts);

      //if (mFrameListener == NULL)
      //   mFrameListener = OGRE_NEW GMFrameListener;
      //mRoot->addFrameListener(mFrameListener);

      if (IsGMInitialized())
      {
         // Setup the links to our GM vector/quaternion/euler result variables
         AcquireGMVectorGlobals();
         AcquireGMEulerGlobals();
      }

      // Start our high performance timers
      mPerfTimer.Start();
      mLastFrameTime = mPerfTimer.Elapsedms();
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
      if (mFSAAQuality == 0)
         opts["FSAAQuality"] = "";
      else if (mFSAAQuality == 1)
         opts["FSAAQuality"] = "Quality";

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

   // Calculate the last frame time
   AcquireGMElapsedMSGlobal();
   SetGMVariable(*mElapsedFrameMS, mPerfTimer.Elapsedms() - mLastFrameTime);
   mLastFrameTime = mPerfTimer.Elapsedms();
   
   return TRUE;
}


GMFN double EnableWaitForVSync(double enable)
{
   mUseVSync = (enable != 0);

   return TRUE;
}


GMFN double SetFSAA(double fsaa_level, double fsaa_hint)
{
   mFSAALevel = (int)fsaa_level;
   mFSAAQuality = (int)fsaa_hint;

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
   return "GMOgre3D v1.2";
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


GMFN double GetElapsedMS()
{
   return mPerfTimer.Elapsedms();
}


GMFN double GetElapsedFrameMS()
{
   return mPerfTimer.Elapsedms() - mLastFrameTime;

   // DO NOT REMOVE: This shows how you can access GM variables (and how hard it is to do so),
   // to be used in future code to auto-update position/rotation, etc.
/*
   GM_VARIABLE &globalArrayTwo = *mArrayTwo;

   DisplayError(Ogre::String(globalArrayTwo));

   for (unsigned long i = 0; i < globalArrayTwo.GetFirstDimensionSize(); i++)
   {
      for (unsigned long j = 0; j < globalArrayTwo.GetSecondDimensionSize( i ); j++)
      {
         if (i != 0 && j != 0)
            DisplayError(Ogre::String(globalArrayTwo[i][j]));
      }
   }

   return TRUE;*/
}


void UpdateSceneNodeAttachments()
{
   LockMutex lm(gMutex);

   try
   {
      if (IsGMInitialized())
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
               gminst->mGMInstancePtr = GetGMInstance((int)gminst->mGMInstanceID);
               AcquireGMLocalVariablePointers(gminst);

               bool GMPosChanged = false;
               bool GMRotChanged = false;

               // Update scene node position if GM position changed (either from the
               // user manually changing or from a previous Newton body changing them).
               if (gminst->mGMInstancePtr->x != gminst->mLastX || gminst->mGMInstancePtr->y != gminst->mLastY || GetGMRealVariable(*gminst->pZ) != gminst->mLastZ)
               {
                  GMPosChanged = true;
                  //node->setPosition(ConvertFromGMAxis(gminst->mGMInstancePtr->x, *gminst->pZ, gminst->mGMInstancePtr->y));
                  SetSceneNodePosition(ConvertToGMPointer(node), gminst->mGMInstancePtr->x, gminst->mGMInstancePtr->y, GetGMRealVariable(*gminst->pZ));

                  if (gminst->BodyAttached && gminst->mBody)
                  {
                     Ogre::Vector3 pos = node->_getDerivedPosition();
                     SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), pos.x, pos.z, pos.y);
                     //SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), gminst->mGMInstancePtr->x, gminst->mGMInstancePtr->y, *gminst->pZ);
                  }
               }

               // Update scene node rotation if GM rotation changed (either from the
               // user manually changing or from a previous Newton body changing them).
               if (GetGMRealVariable(*gminst->pYaw) != gminst->mLastYaw)
               {
                  GMRotChanged = true;
                  SetSceneNodeYaw(ConvertToGMPointer(node), GetGMRealVariable(*gminst->pYaw) - gminst->mLastYaw);
               }
               if (GetGMRealVariable(*gminst->pPitch) != gminst->mLastPitch)
               {
                  GMRotChanged = true;
                  SetSceneNodePitch(ConvertToGMPointer(node), GetGMRealVariable(*gminst->pPitch) - gminst->mLastPitch);
               }
               if (GetGMRealVariable(*gminst->pRoll) != gminst->mLastRoll)
               {
                  GMRotChanged = true;
                  SetSceneNodeRoll(ConvertToGMPointer(node), GetGMRealVariable(*gminst->pRoll) - gminst->mLastRoll);
               }

               if (GMRotChanged == true && gminst->BodyAttached && gminst->mBody)
               {
                  Ogre::Quaternion quat = node->_getDerivedOrientation();
                  SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), ConvertToGMYaw(quat.getYaw().valueDegrees()), ConvertToGMPitch(quat.getPitch().valueDegrees()), ConvertToGMRoll(quat.getRoll().valueDegrees()));
                  //SetNewtonBodyOrientation(ConvertToGMPointer(gminst->mBody), *gminst->pYaw, *gminst->pPitch, *gminst->pRoll);
               }

               // Update scene node scale if GM scale changed.
               if (GetGMRealVariable(*gminst->pScaleX) != gminst->mLastScaleX || GetGMRealVariable(*gminst->pScaleY) != gminst->mLastScaleY || GetGMRealVariable(*gminst->pScaleZ) != gminst->mLastScaleZ)
               {
                  //node->scale(ConvertFromGMAxis(*gminst->pScaleX, *gminst->pScaleZ, *gminst->pScaleY));
                  SetSceneNodeScale(ConvertToGMPointer(node), GetGMRealVariable(*gminst->pScaleX), GetGMRealVariable(*gminst->pScaleY), GetGMRealVariable(*gminst->pScaleZ));
               }

               // Update GM vars if needed
               if (!GMPosChanged)
               {
                  Ogre::Vector3 pos = ConvertToGMAxis(node->getPosition());
                  gminst->mGMInstancePtr->x = pos.x;
                  gminst->mGMInstancePtr->y = pos.y;
                  SetGMVariable(*gminst->pZ, pos.z);
               }
               if (!GMRotChanged)
               {
                  Ogre::Quaternion orient = node->getOrientation();
                  Euler euler = QuaternionToEuler(orient);

                  SetGMVariable(*gminst->pYaw, ConvertToGMYaw(euler.getYaw().valueDegrees()));
                  SetGMVariable(*gminst->pPitch, ConvertToGMPitch(euler.getPitch().valueDegrees()));
                  SetGMVariable(*gminst->pRoll, ConvertToGMRoll(euler.getRoll().valueDegrees()));
               }
               {
                  Ogre::Vector3 scale = ConvertToGMAxis(node->getScale());
                  SetGMVariable(*gminst->pScaleX, scale.x);
                  SetGMVariable(*gminst->pScaleY, scale.y);
                  SetGMVariable(*gminst->pScaleZ, scale.z);
               }
            }

            if ((gminst->GMPositionVariableAttached && gminst->pGlobalPosition) || (gminst->GMOrientationVariableAttached && gminst->pGlobalOrientation) || (gminst->GMScaleVariableAttached && gminst->pGlobalScale))
            {
               AcquireGMGlobalVariablePointer(gminst);

               bool GMPosChanged = false;
               bool GMRotChanged = false;
               bool GMScaleChanged = false;

               // Update scene node position if GM position changed (either from the
               // user manually changing or from a previous Newton body changing them).
               if (gminst->GMPositionVariableAttached && gminst->pGlobalPosition)
               {
                  Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst->pGlobalPosition, gminst->iGlobalPositionIndex);

                  if (vec.x != gminst->mLastX || vec.y != gminst->mLastY || vec.z != gminst->mLastZ)
                  {
                     GMPosChanged = true;

                     SetGMGlobalArray(gminst->pGlobalPosition, gminst->iGlobalPositionIndex, vec);

                     //node->setPosition(ConvertFromGMAxis(gminst->mGMInstancePtr->x, *gminst->pZ, gminst->mGMInstancePtr->y));
                     SetSceneNodePosition(ConvertToGMPointer(node), vec.x, vec.y, vec.z);

                     if (gminst->BodyAttached && gminst->mBody)
                     {
                        Ogre::Vector3 pos = node->_getDerivedPosition();
                        SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), pos.x, pos.z, pos.y);
                        //SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), gminst->mGMInstancePtr->x, gminst->mGMInstancePtr->y, *gminst->pZ);
                     }
                  }
               }

               // Update scene node rotation if GM rotation changed (either from the
               // user manually changing or from a previous Newton body changing them).
               if (gminst->GMOrientationVariableAttached && gminst->pGlobalOrientation)
               {
                  Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst->pGlobalOrientation, gminst->iGlobalOrientationIndex);

                  if (vec.x != gminst->mLastYaw)
                  {
                     GMRotChanged = true;
                     SetSceneNodeYaw(ConvertToGMPointer(node), vec.x - gminst->mLastYaw);
                  }
                  if (vec.y != gminst->mLastPitch)
                  {
                     GMRotChanged = true;
                     SetSceneNodePitch(ConvertToGMPointer(node), vec.y - gminst->mLastPitch);
                  }
                  if (vec.z != gminst->mLastRoll)
                  {
                     GMRotChanged = true;
                     SetSceneNodeRoll(ConvertToGMPointer(node), vec.z - gminst->mLastRoll);
                  }

                  if (GMRotChanged = true && gminst->BodyAttached && gminst->mBody)
                  {
                     Ogre::Quaternion quat = node->_getDerivedOrientation();
                     SetNewtonBodyPosition(ConvertToGMPointer(gminst->mBody), ConvertToGMYaw(quat.getYaw().valueDegrees()), ConvertToGMPitch(quat.getPitch().valueDegrees()), ConvertToGMRoll(quat.getRoll().valueDegrees()));
                     //SetNewtonBodyOrientation(ConvertToGMPointer(gminst->mBody), *gminst->pYaw, *gminst->pPitch, *gminst->pRoll);
                  }
               }

               // Update scene node scale if GM scale changed.
               if (gminst->GMScaleVariableAttached && gminst->pGlobalScale)
               {
                  Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst->pGlobalScale, gminst->iGlobalScaleIndex);

                  if (vec.x != gminst->mLastScaleX || vec.y != gminst->mLastScaleY || vec.z != gminst->mLastScaleZ)
                  {
                     GMScaleChanged = true;

                     //node->scale(ConvertFromGMAxis(*gminst->pScaleX, *gminst->pScaleZ, *gminst->pScaleY));
                     SetSceneNodeScale(ConvertToGMPointer(node), vec.x, vec.y, vec.z);
                  }
               }

               // Update GM vars if needed
               if (!GMPosChanged && (gminst->GMPositionVariableAttached && gminst->pGlobalPosition))
               {
                  Ogre::Vector3 pos = ConvertToGMAxis(node->getPosition());
                  SetGMGlobalArray(gminst->pGlobalPosition, gminst->iGlobalPositionIndex, pos);
               }
               if (!GMRotChanged && (gminst->GMOrientationVariableAttached && gminst->pGlobalOrientation))
               {
                  Ogre::Quaternion orient = node->getOrientation();
                  Euler euler = QuaternionToEuler(orient);

                  Ogre::Vector3 vec(ConvertToGMYaw(euler.getYaw().valueDegrees()), ConvertToGMPitch(euler.getPitch().valueDegrees()), ConvertToGMRoll(euler.getRoll().valueDegrees()));
                  SetGMGlobalArray(gminst->pGlobalOrientation, gminst->iGlobalOrientationIndex, vec);
               }
               if (!GMScaleChanged && (gminst->GMScaleVariableAttached && gminst->pGlobalScale))
               {
                  Ogre::Vector3 scale = ConvertToGMAxis(node->getScale());
                  SetGMGlobalArray(gminst->pGlobalScale, gminst->iGlobalScaleIndex, scale);
               }
            }

            // Update our last known positions
            if (gminst->GMInstanceAttached && gminst->mGMInstancePtr)
            {
               gminst->mLastX = gminst->mGMInstancePtr->x;
               gminst->mLastY = gminst->mGMInstancePtr->y;
               gminst->mLastZ = GetGMRealVariable(*gminst->pZ);

               gminst->mLastYaw = GetGMRealVariable(*gminst->pYaw);
               gminst->mLastPitch = GetGMRealVariable(*gminst->pPitch);
               gminst->mLastRoll = GetGMRealVariable(*gminst->pRoll);

               gminst->mLastScaleX = GetGMRealVariable(*gminst->pScaleX);
               gminst->mLastScaleY = GetGMRealVariable(*gminst->pScaleY);
               gminst->mLastScaleZ = GetGMRealVariable(*gminst->pScaleZ);
            }
            if (gminst->GMPositionVariableAttached && gminst->pGlobalPosition)
            {
               Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst->pGlobalPosition, gminst->iGlobalPositionIndex);
               gminst->mLastX = vec.x;
               gminst->mLastY = vec.y;
               gminst->mLastZ = vec.z;
            }
            if (gminst->GMOrientationVariableAttached && gminst->pGlobalOrientation)
            {
               Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst->pGlobalOrientation, gminst->iGlobalOrientationIndex);
               gminst->mLastYaw = vec.x;
               gminst->mLastPitch = vec.y;
               gminst->mLastRoll = vec.z;
            }
            if (gminst->GMScaleVariableAttached && gminst->pGlobalScale)
            {
               Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst->pGlobalScale, gminst->iGlobalScaleIndex);
               gminst->mLastScaleX = vec.x;
               gminst->mLastScaleY = vec.y;
               gminst->mLastScaleZ = vec.z;
            }
            ++iter;
         }
      }
   }
   catch(...)
   {
   }
}
