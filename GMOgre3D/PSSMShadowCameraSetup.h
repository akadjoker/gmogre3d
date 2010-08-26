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

#ifndef GMOGRE_PSSMSHADOWCAMERASETUP_H
#define GMOGRE_PSSMSHADOWCAMERASETUP_H

#include "GMOgre3D.h"


GMFN double CreatePSSMShadowCameraSetup()
{
   Ogre::PSSMShadowCameraSetup *cam = NULL;

   TRY
      cam = OGRE_NEW Ogre::PSSMShadowCameraSetup;
   CATCH("CreatePSSMShadowCameraSetup")

   return ConvertToGMPointer(cam);
}


GMFN double DestroyPSSMShadowCameraSetup(double ppsm_shadow_camera_setup_ptr)
{
   Ogre::PSSMShadowCameraSetup *cam = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup *>(ppsm_shadow_camera_setup_ptr);

   if (cam == NULL)
      return FALSE;
   
   delete cam;

   return TRUE;
}


GMFN double SetPSSMShadowCameraSetupSplitPadding(double ppsm_shadow_camera_setup_ptr, double padding)
{
   Ogre::PSSMShadowCameraSetup *cam = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup *>(ppsm_shadow_camera_setup_ptr);

   if (cam == NULL)
      return FALSE;
   
   cam->setSplitPadding(padding);

   return TRUE;
}


GMFN double SetPSSMShadowCameraSetupOptimalAdjustFactor(double ppsm_shadow_camera_setup_ptr, double split_index, double factor)
{
   Ogre::PSSMShadowCameraSetup *cam = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup *>(ppsm_shadow_camera_setup_ptr);

   if (cam == NULL)
      return FALSE;
   
   cam->setOptimalAdjustFactor(split_index, factor);

   return TRUE;
}


GMFN double EnablePSSMShadowCameraSetupOptimalAdjust(double ppsm_shadow_camera_setup_ptr, double enable)
{
   Ogre::PSSMShadowCameraSetup *cam = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup *>(ppsm_shadow_camera_setup_ptr);

   if (cam == NULL)
      return FALSE;
   
   cam->setUseSimpleOptimalAdjust((enable != 0));

   return TRUE;
}


GMFN double SetPSSMShadowCameraSetupCameraLightDirectionThreshold(double ppsm_shadow_camera_setup_ptr, double degrees)
{
   Ogre::PSSMShadowCameraSetup *cam = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup *>(ppsm_shadow_camera_setup_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setCameraLightDirectionThreshold(Ogre::Degree((Ogre::Real)degrees));

   return TRUE;
}


GMFN double EnablePSSMShadowCameraSetupAggressiveFocusRegion(double ppsm_shadow_camera_setup_ptr, double enable)
{
   Ogre::PSSMShadowCameraSetup *cam = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup *>(ppsm_shadow_camera_setup_ptr);

   if (cam == NULL)
      return FALSE;

   cam->setUseAggressiveFocusRegion((enable != 0));

   return TRUE;
}


GMFN double CalculatePSSMShadowCameraSetupSplitPoints(double ppsm_shadow_camera_setup_ptr, double split_count, double near_dist, double far_dist, double lambda)
{
   Ogre::PSSMShadowCameraSetup *cam = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup *>(ppsm_shadow_camera_setup_ptr);

   if (cam == NULL)
      return FALSE;
   
   cam->calculateSplitPoints(split_count, near_dist, far_dist, lambda);

   return TRUE;
}


GMFN double GetPSSMShadowCameraSetupSplitPoints(double ppsm_shadow_camera_setup_ptr, double split_index)
{
   Ogre::PSSMShadowCameraSetup *cam = ConvertFromGMPointer<Ogre::PSSMShadowCameraSetup *>(ppsm_shadow_camera_setup_ptr);

   if (cam == NULL)
      return 0;

   const Ogre::PSSMShadowCameraSetup::SplitPointList &splitPointList = cam->getSplitPoints();

   return splitPointList[split_index];
}

#endif
