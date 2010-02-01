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

#ifndef GMOGRE_NEWTON_HINGE_JOINT
#define GMOGRE_NEWTON_HINGE_JOINT

#include "OgreNewt_BasicJoints.h"
#include "OgreNewt_Joint.h"


GMFN double CreateNewtonHingeJoint(double newton_child_body_ptr, double newton_parent_body_ptr, double posx, double posz, double posy, double pinx, double pinz, double piny)
{
   OgreNewtBody *newton_child_body = ConvertFromGMPointer<OgreNewtBody*>(newton_child_body_ptr);

   if (!newton_child_body)
      return FALSE;

   OgreNewtBody *newton_parent_body = NULL;
   
   if (newton_parent_body_ptr != 0.0)
   {
      newton_parent_body = ConvertFromGMPointer<OgreNewtBody*>(newton_parent_body_ptr);

      if (!newton_parent_body)
         return FALSE;
   }

   OgreNewt::Joint *joint;

   TRY
      joint = new OgreNewt::Hinge(newton_child_body->getOgreNewtBody(), newton_parent_body ? newton_parent_body->getOgreNewtBody() : NULL, ConvertFromGMAxis(posx, posy, posz), ConvertFromGMAxis(pinx, piny, pinz));
   CATCH("CreateNewtonHingeJoint")

   return ConvertToGMPointer(joint);
}


GMFN double DestroyNewtonHingeJoint(double newton_joint_ptr)
{
   OgreNewt::Joint *newton_joint = ConvertFromGMPointer<OgreNewt::Joint*>(newton_joint_ptr);

   if (!newton_joint)
      return FALSE;

   delete newton_joint;

   return TRUE;
}


GMFN double EnableNewtonHingeJointLimits(double newton_joint_ptr, double enable)
{
   OgreNewt::Hinge *newton_joint = ConvertFromGMPointer<OgreNewt::Hinge*>(newton_joint_ptr);

   if (!newton_joint)
      return FALSE;

   newton_joint->enableLimits((enable != 0));

   return TRUE;
}


GMFN double SetNewtonHingeJointLimits(double newton_joint_ptr, double min_angle, double max_angle)
{
   OgreNewt::Hinge *newton_joint = ConvertFromGMPointer<OgreNewt::Hinge*>(newton_joint_ptr);

   if (!newton_joint)
      return FALSE;

   newton_joint->setLimits(Ogre::Degree(min_angle), Ogre::Degree(max_angle));

   return TRUE;
}


GMFN double GetNewtonHingeJointAngle(double newton_joint_ptr)
{
   OgreNewt::Hinge *newton_joint = ConvertFromGMPointer<OgreNewt::Hinge*>(newton_joint_ptr);

   if (!newton_joint)
      return FALSE;

   return newton_joint->getJointAngle();
}


GMFN double GetNewtonHingeJointAngularVelocity(double newton_joint_ptr)
{
   OgreNewt::Hinge *newton_joint = ConvertFromGMPointer<OgreNewt::Hinge*>(newton_joint_ptr);

   if (!newton_joint)
      return FALSE;

   return newton_joint->getJointAngulatVelocity();
}


GMFN double GetNewtonHingeJointPinAxis(double newton_joint_ptr)
{
   OgreNewt::Hinge *newton_joint = ConvertFromGMPointer<OgreNewt::Hinge*>(newton_joint_ptr);

   if (!newton_joint)
      return FALSE;

   Ogre::Vector3 vec = newton_joint->getJointPin();

   SetGMVectorGlobals(vec);

   return TRUE;
}

#endif
