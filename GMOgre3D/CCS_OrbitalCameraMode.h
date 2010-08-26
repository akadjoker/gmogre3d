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

#ifndef GMOGRE_CCS_ORBITAL_CAMERA_MODE_H
#define GMOGRE_CCS_ORBITAL_CAMERA_MODE_H

#include "GMOgre3D.h"
#include "CCSCameraControlSystem.h"
#include "CCSBasicCameraModes.h"
#include "CCSOrbitalCameraMode.h"
#include "CCSFreeCameraMode.h"

/*
class CustomCameraCollisionDetection
{
public:
   Ogre::Vector3 CustomCollisionDetectionFunction(Ogre::Vector3 cameraTargetPosition, Ogre::Vector3 cameraPosition)
   {
		// Call our GM script to handle this leave world callback
      gm::CGMVariable args[6];
      args[0].Set(static_cast<double>(reinterpret_cast<intptr_t>(contact.m_body1)));
      args[1].Set(static_cast<double>(reinterpret_cast<intptr_t>(contact.m_body1)));
      args[2].Set(contact.m_speed);
      args[3].Set(ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).x);
      args[4].Set(ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).z);
      args[5].Set(ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).y);

      // Can't do this because we can't return a x/y/z pos!
      gm::CGMVariable ret = gm::script_execute(contact.m_function, args, 6);  

		return cameraPosition;
	}
};

static CustomCameraCollisionDetection camera_collision;
*/

GMFN double SetOrbitalCameraModeRotationFactor(double camera_mode_ptr, double degrees_per_second)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setRotationFactor(degrees_per_second);

   return TRUE;
}


GMFN double SetOrbitalCameraModeZoomFactor(double camera_mode_ptr, double units_per_second)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setZoomFactor(units_per_second);

   return TRUE;
}


GMFN double SetOrbitalCameraModeZoom(double camera_mode_ptr, double zoom)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setZoom(zoom);

   return TRUE;
}


GMFN double ZoomOrbitalCameraMode(double camera_mode_ptr, double percentage)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->zoom(percentage);

   return TRUE;
}


GMFN double SetOrbitalCameraModeYaw(double camera_mode_ptr, double degrees)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setYaw(Ogre::Degree((Ogre::Real)degrees));

   return TRUE;
}


GMFN double YawOrbitalCameraMode(double camera_mode_ptr, double percentage)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->yaw(percentage);

   return TRUE;
}


GMFN double SetOrbitalCameraModePitch(double camera_mode_ptr, double degrees)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setPitch(Ogre::Degree((Ogre::Real)degrees));

   return TRUE;
}


GMFN double PitchOrbitalCameraMode(double camera_mode_ptr, double percentage)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->pitch(percentage);

   return TRUE;
}


GMFN double SetOrbitalCameraModeRelativePosition(double camera_mode_ptr, double relative_posx, double relative_posz, double relative_posy, double offset_yaw, double offset_pitch, double offset_roll)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setCameraRelativePosition(ConvertFromGMAxis(relative_posx, relative_posy, relative_posz), Euler(Ogre::Degree(ConvertFromGMYaw(offset_yaw + 90)), Ogre::Degree(offset_pitch), Ogre::Degree(offset_roll)));

   return TRUE;
}


GMFN double SetOrbitalCameraModeTightness(double camera_mode_ptr, double tightness)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setCameraTightness(tightness);

   return TRUE;
}


GMFN double EnableOrbitalCameraModeCollisions(double camera_mode_ptr, double enable)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setCollisionsEnabled((enable != 0));

   return TRUE;
}

/*
GMFN double SetOrbitalCameraModeCollisionCallback(double camera_mode_ptr, double func)
{
   CCS::OrbitalCameraMode *cam_mode = ConvertFromGMPointer<CCS::OrbitalCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->collisionDelegate = CCS::CollidableCamera::newCollisionDelegate(&camera_collision, &CustomCameraCollisionDetection::CustomCollisionDetectionFunction);

   return TRUE;
}
*/

#endif
