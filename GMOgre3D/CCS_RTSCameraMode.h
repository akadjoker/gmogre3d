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

#ifndef GMOGRE_CCS_RTS_CAMERA_MODE_H
#define GMOGRE_CCS_RTS_CAMERA_MODE_H

#include "GMOgre3D.h"
#include "CCSCameraControlSystem.h"
#include "CCSBasicCameraModes.h"
#include "CCSOrbitalCameraMode.h"
#include "CCSFreeCameraMode.h"


GMFN double SetRTSCameraModePitch(double camera_mode_ptr, double pitch)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setCameraPitch(Ogre::Degree((Ogre::Real)pitch));

   return TRUE;
}


GMFN double SetRTSCameraModeZoom(double camera_mode_ptr, double zoom)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setZoom(zoom);

   return TRUE;
}


GMFN double ZoomRTSCameraModeIn(double camera_mode_ptr, double percentage)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->zoomIn(percentage);

   return TRUE;
}


GMFN double ZoomRTSCameraModeOut(double camera_mode_ptr, double percentage)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->zoomOut(percentage);

   return TRUE;
}


GMFN double SetRTSCameraMoveFactor(double camera_mode_ptr, double units_per_sec)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->setMoveFactor(units_per_sec);

   return TRUE;
}


GMFN double SetRTSCameraModeGoLeft(double camera_mode_ptr, double percentage)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->goLeft(percentage);

   return TRUE;
}


GMFN double SetRTSCameraModeGoRight(double camera_mode_ptr, double percentage)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->goRight(percentage);

   return TRUE;
}


GMFN double SetRTSCameraModeGoUp(double camera_mode_ptr, double percentage)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->goUp(percentage);

   return TRUE;
}


GMFN double SetRTSCameraModeGoDown(double camera_mode_ptr, double percentage)
{
   CCS::RTSCameraMode *cam_mode = ConvertFromGMPointer<CCS::RTSCameraMode*>(camera_mode_ptr);

   if (cam_mode == NULL)
      return FALSE;

   cam_mode->goDown(percentage);

   return TRUE;
}

#endif
