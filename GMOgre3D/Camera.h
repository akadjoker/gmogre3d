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

#ifndef GMOGRE_CAMERA_H
#define GMOGRE_CAMERA_H

#include "GMOgre3D.h"


GMFN double CreateCamera(double aspect, double znear, double zfar, double fov)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Camera *cam = mSceneMgr->createCamera(GenerateUniqueName());

   if (cam == NULL)
      return FALSE;

   if (mCamera == NULL)
      mCamera = cam;

   cam->setNearClipDistance(znear);
   cam->setFarClipDistance(zfar);
   cam->setAspectRatio(Ogre::Real(aspect));
   cam->setFOVy(Ogre::Radian(Ogre::Degree(fov)));

   return ConvertToGMPointer(cam);
}


GMFN double DestroyCamera(double camera_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   mSceneMgr->destroyCamera(cam);

   return TRUE;
}


GMFN double SetCameraProjection(double camera_ptr, double xfrom, double zfrom, double yfrom, double xto, double zto, double yto, double xup, double zup, double yup)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setPosition(xfrom, yfrom, zfrom);
   cam->setDirection(xto, yto, zto);
   cam->lookAt(xup, yup, zup);

   return TRUE;
}


GMFN double SetCameraPosition(double camera_ptr, double x, double z, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setPosition(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double SetCameraDirection(double camera_ptr, double xto, double zto, double yto)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setDirection(xto, yto, zto);

   return TRUE;
}


GMFN double MoveCameraForward(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getDirection() * delta);

   return TRUE;
}


GMFN double MoveCameraBackward(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getDirection() * (delta * -1));

   return TRUE;
}


GMFN double MoveCameraRight(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getRight() * delta);

   return TRUE;
}


GMFN double MoveCameraLeft(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getRight() * (delta * -1));

   return TRUE;
}


GMFN double MoveCameraUp(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getUp() * delta);

   return TRUE;
}


GMFN double MoveCameraDown(double camera_ptr, double delta)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->move(cam->getUp() * (delta * -1));

   return TRUE;
}


GMFN double GetCameraPosition(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Vector3 vec = cam->getPosition();

   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double SetCameraLookAt(double camera_ptr, double x, double z, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->lookAt(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double SetCameraOrientation(double cam_ptr, double yaw, double pitch, double roll)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(pitch), Ogre::Degree(roll)));

   return TRUE;
}


GMFN double GetCameraOrientation(double cam_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Quaternion quat = cam->getOrientation();

   if (mEulerYaw != NULL)
   {
      *mEulerYaw = ConvertToGMYaw(quat.getYaw().valueDegrees());
      *mEulerPitch = quat.getPitch().valueDegrees();
      *mEulerRoll = quat.getRoll().valueDegrees();
   }

   return TRUE;
}


GMFN double SetCameraRoll(double camera_ptr, double degrees)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->roll(Ogre::Radian(Ogre::Degree(degrees)));

   return TRUE;
}


GMFN double GetCameraRoll(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Quaternion qt = cam->getOrientation();

   return qt.getRoll().valueDegrees();
}


GMFN double SetCameraYaw(double camera_ptr, double degrees)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->yaw(Ogre::Radian(Ogre::Degree(degrees)));

   return TRUE;
}


GMFN double GetCameraYaw(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::Quaternion qt = cam->getOrientation();

   return ConvertToGMYaw(qt.getYaw().valueDegrees());
}


GMFN double SetCameraPitch(double camera_ptr, double degrees)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->pitch(Ogre::Radian(Ogre::Degree(degrees)));

   return TRUE;
}


GMFN double GetCameraPitch(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   //Ogre::Quaternion qt = cam->getOrientation();
   //return qt.getPitch().valueDegrees();

   // Retrieve proper pitch by removing camera yaw
   Ogre::Quaternion old_qt = cam->getOrientation();
   cam->yaw(old_qt.getYaw() * -1);
   Ogre::Quaternion qt = cam->getOrientation();
   cam->setOrientation(old_qt);

   return old_qt.getPitch().valueDegrees();
}


GMFN double SetCameraFOV(double camera_ptr, double angle)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setFOVy(Ogre::Radian(Ogre::Degree(angle)));

   return TRUE;
}


GMFN double SetCameraProjectionType(double camera_ptr, double type)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setProjectionType(static_cast<Ogre::ProjectionType>((int)type));
   //cam->setOrthoWindow(w, h);

   return TRUE;
}


GMFN double SetCameraRenderType(double camera_ptr, double type)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setPolygonMode(static_cast<Ogre::PolygonMode>((int)type));

   return TRUE;
}


GMFN double SetCameraLODBias(double camera_ptr, double factor)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setLodBias(factor);

   return TRUE;
}


GMFN double GetCameraLODBias(double camera_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   return cam->getLodBias();
}


GMFN double EnableCameraAutoTracking(double camera_ptr, double enable, double scene_node_ptr, double x, double z, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (node == NULL)
      return FALSE;

   if (enable != 0)
      cam->setAutoTracking(true, node, Ogre::Vector3(x, y, z));
   else
      cam->setAutoTracking(false);

   return TRUE;
}


GMFN double EnableCameraFixedYawAxis(double cam_ptr, double enable, double x, double z, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   cam->setFixedYawAxis((enable != 0), Ogre::Vector3(x, y, z));

   return TRUE;
} 


GMFN double EnableCameraReflection(double cam_ptr, double enable, double plane_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   Ogre::Plane *plane = ConvertFromGMPointer<Ogre::Plane*>(plane_ptr);

   if (plane == NULL)
      return FALSE;

   if (enable != 0)
      cam->enableReflection(*plane);
   else
      cam->disableReflection();

   return TRUE;
} 


GMFN double AttachCameraToSceneNode(double cam_ptr, double scene_node_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->attachObject(cam);

   return TRUE;
}


GMFN double DetachCameraFromSceneNode(double cam_ptr, double scene_node_ptr)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   if (cam == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->detachObject(cam);

   return TRUE;
}

#endif
