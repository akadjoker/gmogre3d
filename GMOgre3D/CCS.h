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

#ifndef GMOGRE_CAMERA_CONTROL_SYSTEM_H
#define GMOGRE_CAMERA_CONTROL_SYSTEM_H

#include "GMOgre3D.h"
#include "CCSCameraControlSystem.h"
#include "CCSBasicCameraModes.h"
#include "CCSOrbitalCameraMode.h"
#include "CCSFreeCameraMode.h"


static double ccs_pos_x = 0;
static double ccs_pos_y = 0;
static double ccs_pos_z = 0;

GMFN double CreateCameraControlSystem(double cam_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   CCS::CameraControlSystem *ccs = NULL;

   Ogre::Camera *cam = NULL;

   if (cam_ptr != 0.0)
      cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   TRY
      ccs = OGRE_NEW CCS::CameraControlSystem(mSceneMgr, GenerateUniqueName(), cam);
   CATCH("CreateCameraControlSystem")

   return ConvertToGMPointer(ccs);
}


GMFN double DestroyCameraControlSystem(double ccs_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   ccs->deleteAllCameraModes();
   delete ccs;

   return TRUE;
}


GMFN double RegisterCameraControlSystemCameraMode(double ccs_ptr, double camera_mode_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   CCS::CameraControlSystem::CameraMode *camera_mode = ConvertFromGMPointer<CCS::CameraControlSystem::CameraMode*>(camera_mode_ptr);

   if (camera_mode == NULL)
      return FALSE;

   ccs->registerCameraMode(GenerateUniqueName(), camera_mode);

   return TRUE;
}

/*
GMFN double RemoveCameraControlSystemCameraMode(double ccs_ptr, double camera_mode_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   CCS::CameraControlSystem::CameraMode *camera_mode = ConvertFromGMPointer<CCS::CameraControlSystem::CameraMode*>(camera_mode_ptr);

   if (camera_mode == NULL)
      return FALSE;

   ccs->removeCameraMode(camera_mode);

   return TRUE;
}


GMFN double DeleteAllCameraControlSystemCameraModes(double ccs_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   ccs->deleteAllCameraModes();

   return TRUE;
}
*/

//GMFN double GetCameraControlSystemCameraMode(double type_ptr)

GMFN double GetCameraControlSystemCurrentCameraMode(double ccs_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return 0;

   CCS::CameraControlSystem::CameraMode *camera_mode = ccs->getCurrentCameraMode();

   return ConvertToGMPointer(camera_mode);
}


GMFN double SetCameraControlSystemCurrentCameraMode(double ccs_ptr, double camera_mode_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   CCS::CameraControlSystem::CameraMode *camera_mode = ConvertFromGMPointer<CCS::CameraControlSystem::CameraMode*>(camera_mode_ptr);

   if (camera_mode == NULL)
      return FALSE;

   ccs->setCurrentCameraMode(camera_mode);

   return TRUE;
}


GMFN double UpdateCameraControlSystem(double ccs_ptr, double time_passed)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   ccs->update(time_passed);

   return TRUE;
}


GMFN double SetCameraControlSystemCameraTargetSceneNode(double ccs_ptr, double node_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(node_ptr);

   if (ccs == NULL)
      return FALSE;

   ccs->setCameraTarget(node);

   return TRUE;
}


GMFN double GetCameraControlSystemCameraPosition(double ccs_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   Ogre::Vector3 vec = ccs->getCameraPosition();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double GetCameraControlSystemCameraOrientation(double ccs_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   Ogre::Quaternion quat = ccs->getCameraOrientation();

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      *mEulerYaw = ConvertToGMYaw(quat.getYaw().valueDegrees());
      *mEulerPitch = quat.getPitch().valueDegrees();
      *mEulerRoll = quat.getRoll().valueDegrees();
   }

   return TRUE;
}


GMFN double EnableCameraControlSystemAutoTrackTarget(double ccs_ptr, double enable)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   ccs->setAutoTrackingTarget((enable != 0));

   return TRUE;
}


GMFN double EnableCameraControlSystemFixedYawAxis(double ccs_ptr, double enable, double x, double z, double y)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   ccs->setFixedYawAxis((enable != 0), ConvertFromGMAxis(x, y, z));

   return TRUE;
} 


GMFN double CreateCameraControlSystemFixedCameraMode(double ccs_ptr, double axisx, double axisz, double axisy)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   CCS::FixedCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::FixedCameraMode(ccs, (axisx == 0 && axisy == 0 && axisz == 0) ? Ogre::Vector3(0, 1, 0) : ConvertFromGMAxis(axisx, axisy, axisz));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemFixedCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemChaseCameraMode(double ccs_ptr, double relative_posx, double relative_posz, double relative_posy, double axisx, double axisz, double axisy)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   CCS::ChaseCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::ChaseCameraMode(ccs, ConvertFromGMAxis(relative_posx, relative_posy, relative_posz), (axisx == 0 && axisy == 0 && axisz == 0) ? Ogre::Vector3(0, 1, 0) : ConvertFromGMAxis(axisx, axisy, axisz));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemChaseCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemAttachedCameraMode(double ccs_ptr, double relative_posx, double relative_posz, double relative_posy, double yaw, double pitch, double roll)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   CCS::AttachedCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::AttachedCameraMode(ccs, ConvertFromGMAxis(relative_posx, relative_posy, relative_posz), Euler(Ogre::Degree(yaw * -1), Ogre::Degree((Ogre::Real)pitch), Ogre::Degree((Ogre::Real)roll)));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemAttachedCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemPlaneBindedCameraMode(double ccs_ptr, double plane_ptr, double axisx, double axisz, double axisy)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
  
   Ogre::Plane *plane = ConvertFromGMPointer<Ogre::Plane*>(plane_ptr);

   if (plane == NULL)
      return FALSE;

   CCS::PlaneBindedCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::PlaneBindedCameraMode(ccs, *plane, (axisx == 0 && axisy == 0 && axisz == 0) ? Ogre::Vector3(0, 1, 0) : ConvertFromGMAxis(axisx, axisy, axisz));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemPlaneBindedCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemThroughTargetCameraMode(double ccs_ptr, double margin, double inverse, double focus_posx, double focus_posz, double focus_posy, double axisx, double axisz, double axisy)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   CCS::ThroughTargetCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::ThroughTargetCameraMode(ccs, margin, (inverse != 0), ConvertFromGMAxis(focus_posx, focus_posy, focus_posz), (axisx == 0 && axisy == 0 && axisz == 0) ? Ogre::Vector3(0, 1, 0) : ConvertFromGMAxis(axisx, axisy, axisz));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemThroughTargetCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemFixedDirectionCameraMode(double ccs_ptr, double dirx, double dirz, double diry, double distance, double axisx, double axisz, double axisy)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   CCS::FixedDirectionCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::FixedDirectionCameraMode(ccs, ConvertFromGMAxis(dirx, diry, dirz), distance, (axisx == 0 && axisy == 0 && axisz == 0) ? Ogre::Vector3(0, 1, 0) : ConvertFromGMAxis(axisx, axisy, axisz));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemFixedDirectionCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemFirstPersonCameraMode(double ccs_ptr, double relative_posx, double relative_posz, double relative_posy, double yaw, double pitch, double roll)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   CCS::FirstPersonCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::FirstPersonCameraMode(ccs, ConvertFromGMAxis(relative_posx, relative_posy, relative_posz), Euler(Ogre::Degree(yaw * -1), Ogre::Degree((Ogre::Real)pitch), Ogre::Degree((Ogre::Real)roll)));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemFirstPersonCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemChaseFreeYawAxisCameraMode(double ccs_ptr, double relative_posx, double relative_posz, double relative_posy, double yaw, double pitch, double roll)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   CCS::ChaseFreeYawAxisCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::ChaseFreeYawAxisCameraMode(ccs, ConvertFromGMAxis(relative_posx, relative_posy, relative_posz), Euler(Ogre::Degree(yaw * -1), Ogre::Degree((Ogre::Real)pitch), Ogre::Degree((Ogre::Real)roll)));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemChaseFreeYawAxisCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemOrbitalCameraMode(double ccs_ptr, double zoom, double horiz_rotation, double vert_rotation)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   CCS::OrbitalCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::OrbitalCameraMode(ccs, zoom, Ogre::Degree((horiz_rotation * -1)), Ogre::Degree(vert_rotation));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemOrbitalCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemFixedTrackingCameraMode(double ccs_ptr, double axisx, double axisz, double axisy)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   CCS::FixedTrackingCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::FixedTrackingCameraMode(ccs, (axisx == 0 && axisy == 0 && axisz == 0) ? Ogre::Vector3(0, 1, 0) : ConvertFromGMAxis(axisx, axisy, axisz));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemFixedTrackingCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemClosestToTargetCameraMode(double ccs_ptr, double time_interval, double axisx, double axisz, double axisy)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;
   
   CCS::ClosestToTargetCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::ClosestToTargetCameraMode(ccs, time_interval, (axisx == 0 && axisy == 0 && axisz == 0) ? Ogre::Vector3(0, 1, 0) : ConvertFromGMAxis(axisx, axisy, axisz));
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemClosestToTargetCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemFreeCameraMode(double ccs_ptr)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   CCS::FreeCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::FreeCameraMode(ccs);
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemFreeCameraMode")

   return ConvertToGMPointer(cam_mode);
}


GMFN double CreateCameraControlSystemRTSCameraMode1(double ccs_ptr, double posx, double posz, double posy)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   ccs_pos_x = posx;
   ccs_pos_y = posy;
   ccs_pos_z = posz;

   return TRUE;
}


GMFN double CreateCameraControlSystemRTSCameraMode2(double ccs_ptr, double upx, double upz, double upy, double leftx, double leftz, double lefty, double pitch, double min_zoom, double max_zoom)
{
   CCS::CameraControlSystem *ccs = ConvertFromGMPointer<CCS::CameraControlSystem*>(ccs_ptr);

   if (ccs == NULL)
      return FALSE;

   CCS::RTSCameraMode *cam_mode = NULL;

   TRY
      cam_mode = OGRE_NEW CCS::RTSCameraMode(ccs, ConvertFromGMAxis(ccs_pos_x, ccs_pos_y, ccs_pos_z), ConvertFromGMAxis(upx, upy, upz), ConvertFromGMAxis(leftx, lefty, leftz), Ogre::Degree((Ogre::Real)pitch), min_zoom, max_zoom);
      ccs->registerCameraMode(GenerateUniqueName(), cam_mode);
   CATCH("CreateCameraControlSystemRTSCameraMode")

   return ConvertToGMPointer(cam_mode);
}

#endif
