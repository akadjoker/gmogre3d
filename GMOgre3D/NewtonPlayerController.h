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

#ifndef GMOGRE_NEWTON_PLAYER_CONTROLLER
#define GMOGRE_NEWTON_PLAYER_CONTROLLER

#include "OgreNewt_PlayerController.h"


GMFN double CreateNewtonPlayerController(double newton_body_ptr, double max_stair_height_factor, double max_slope, double kinematic_cushion)
{
   OgreNewtBody *body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!body)
      return 0;

   OgreNewt::PlayerController *controller;

   TRY
      controller = new OgreNewt::PlayerController(body->getOgreNewtBody(), max_stair_height_factor, max_slope, kinematic_cushion);
      controller->setVelocity(0.0f, 0.0f, Ogre::Degree(ConvertFromGMYaw(-90.0f)));
   CATCH("CreateNewtonPlayerController")

   return ConvertToGMPointer(controller);
}


GMFN double DestroyNewtonPlayerController(double player_controller_ptr)
{
   OgreNewt::PlayerController *controller = ConvertFromGMPointer<OgreNewt::PlayerController*>(player_controller_ptr);

   if (!controller)
      return FALSE;

   delete controller;

   return TRUE;
}


GMFN double SetNewtonPlayerControllerVelocity(double player_controller_ptr, double forward_speed, double side_speed, double yaw)
{
   OgreNewt::PlayerController *controller = ConvertFromGMPointer<OgreNewt::PlayerController*>(player_controller_ptr);

   if (!controller)
      return FALSE;

   controller->setVelocity(forward_speed, side_speed, -Ogre::Degree(ConvertFromGMYaw(yaw - 90.0f)));

   return TRUE;
}


GMFN double GetNewtonPlayerControllerForwardVelocity(double player_controller_ptr)
{
   OgreNewt::PlayerController *controller = ConvertFromGMPointer<OgreNewt::PlayerController*>(player_controller_ptr);

   if (!controller)
      return 0;

   Ogre::Real foward, side;
   Ogre::Radian yaw;

   controller->getVelocity(foward, side, yaw);

   return foward;
}


GMFN double GetNewtonPlayerControllerSideVelocity(double player_controller_ptr)
{
   OgreNewt::PlayerController *controller = ConvertFromGMPointer<OgreNewt::PlayerController*>(player_controller_ptr);

   if (!controller)
      return 0;

   Ogre::Real foward, side;
   Ogre::Radian yaw;

   controller->getVelocity(foward, side, yaw);

   return side;
}


GMFN double GetNewtonPlayerControllerHeading(double player_controller_ptr)
{
   OgreNewt::PlayerController *controller = ConvertFromGMPointer<OgreNewt::PlayerController*>(player_controller_ptr);

   if (!controller)
      return 0;

   Ogre::Real foward, side;
   Ogre::Radian yaw;

   controller->getVelocity(foward, side, yaw);

   return ConvertToGMYaw(yaw.valueDegrees() + 90.0f);
}


GMFN double GetNewtonPlayerControllerPlayerHeight(double player_controller_ptr)
{
   OgreNewt::PlayerController *controller = ConvertFromGMPointer<OgreNewt::PlayerController*>(player_controller_ptr);

   if (!controller)
      return 0;

   return controller->getPlayerHeight();
}

#endif
