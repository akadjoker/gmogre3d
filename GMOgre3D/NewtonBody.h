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

#ifndef GMOGRE_NEWTON_BODY_H
#define GMOGRE_NEWTON_BODY_H

#include "GMOgre3D.h"
#include "OgreNewtBody.h"
#include "NewtonWorld.h"
#include "LockMutex.h"


GMFN double CreateNewtonBody(double newton_world_ptr, double newton_collision_ptr, double type = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);

   if (!collision)
      return 0;

   OgreNewtBody *body = NULL;

   TRY
      OgreNewt::CollisionPtr col = mNewtonCollisionMap[collision];

      body = OGRE_NEW OgreNewtBody(world, col, (int)type);
      body->setPositionOrientation(Ogre::Vector3(0,0,0), Euler(Ogre::Degree(ConvertFromGMYaw(0)), Ogre::Degree(0), Ogre::Degree(0)));
   CATCH("CreateNewtonBody")

   return ConvertToGMPointer(body);
}


GMFN double DestroyNewtonBody(double newton_body_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   delete newton_body;

   return TRUE;
}


GMFN double SetNewtonBodyPosition(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   Ogre::Vector3 pos;
   Ogre::Quaternion orient;

   newton_body->getPositionOrientation(pos, orient);
   newton_body->setPositionOrientation(ConvertFromGMAxis(x, y, z), orient);

   return TRUE;
}


GMFN double GetNewtonBodyPosition(double newton_body_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   Ogre::Vector3 pos;
   Ogre::Quaternion orient;

   newton_body->getPositionOrientation(pos, orient);

   SetGMVectorGlobals(pos);

   return TRUE;
}


GMFN double SetNewtonBodyOrientation(double newton_body_ptr, double yaw, double pitch, double roll)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   Ogre::Vector3 pos;
   Ogre::Quaternion orient;

   newton_body->getPositionOrientation(pos, orient);
   newton_body->setPositionOrientation(pos, Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMPitch(roll))));

   return TRUE;
}


GMFN double GetNewtonBodyOrientation(double newton_body_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   Ogre::Vector3 pos;
   Ogre::Quaternion orient;

   newton_body->getPositionOrientation(pos, orient);

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      SetGMVariable(*mEulerYaw, ConvertToGMYaw(orient.getYaw().valueDegrees()));
      SetGMVariable(*mEulerPitch, ConvertToGMPitch(orient.getPitch().valueDegrees()));
      SetGMVariable(*mEulerRoll, ConvertToGMRoll(orient.getRoll().valueDegrees()));
   }

   return TRUE;
}


GMFN double AddNewtonBodyForce(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->addForce(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double AddNewtonBodyImpulse(double newton_body_ptr, double deltax, double deltaz, double deltay, double posx, double posz, double posy)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->addImpulse(ConvertFromGMAxis(deltax, deltay, deltaz), ConvertFromGMAxis(posx, posy, posz));

   return TRUE;
}


GMFN double AddNewtonBodyTorque(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->addTorque(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetNewtonBodyAngularDamping(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setAngularDamping(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetNewtonBodyCenterOfMass(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setCenterOfMass(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double EnableNewtonBodyAutoSleep(double newton_body_ptr, double enable)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setAutoSleep(((int)enable == 0 ? 0 : 1));

   return TRUE;
}


GMFN double EnableNewtonBodyContinuousCollisionChecks(double newton_body_ptr, double enable)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setContinuousCollisionMode(((int)enable == 0 ? 0 : 1));

   return TRUE;
}


GMFN double SetNewtonBodyForce(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setForce(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetNewtonBodyGravity(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->EnableGravityOverride(true);
   newton_body->setGravity(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetNewtonBodyMassMatrix(double newton_body_ptr, double mass, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setMassMatrix((Ogre::Real)mass, ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetNewtonBodyLinearDamping(double newton_body_ptr, double damp)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setLinearDamping((Ogre::Real)damp);

   return TRUE;
}


GMFN double SetNewtonBodyMaterial(double newton_body_ptr, double material_id_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   OgreNewt::MaterialID *mat_id = ConvertFromGMPointer<OgreNewt::MaterialID*>(material_id_ptr);

   if (!mat_id)
      return FALSE;

   newton_body->setMaterialGroupID(mat_id);

   return TRUE;
}


GMFN double GetNewtonBodyMaterial(double newton_body_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return 0;

   return ConvertToGMPointer(newton_body->getMaterialGroupID());
}


GMFN double SetNewtonBodyOmega(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setOmega(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetNewtonBodyTorque(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setTorque(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetNewtonBodyVelocity(double newton_body_ptr, double x, double z, double y)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setVelocity(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double AddNewtonBodyGlobalForce(double newton_body_ptr, double x, double z, double y, double posx, double posz, double posy)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->addGlobalForce(ConvertFromGMAxis(x, y, z), ConvertFromGMAxis(posx, posy, posz));

   return TRUE;
}


GMFN double AddNewtonBodyLocalForce(double newton_body_ptr, double x, double z, double y, double posx, double posz, double posy)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->addLocalForce(ConvertFromGMAxis(x, y, z), ConvertFromGMAxis(posx, posy, posz));

   return TRUE;
}


GMFN double GetNewtonBodyType(double newton_body_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->getType();

   return TRUE;
}


GMFN double FreezeNewtonBody(double newton_body_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->freeze();

   return TRUE;
}


GMFN double UnfreezeNewtonBody(double newton_body_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->unFreeze();

   return TRUE;
}


GMFN double SetNewtonBodyUserData(double newton_body_ptr, char *key, double data)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   newton_body->setUserData(key, ConvertFromGMPointer<void*>(data));

   return TRUE;
}


GMFN double GetNewtonBodyUserData(double newton_body_ptr, char *key)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return 0;

   return ConvertToGMPointer(newton_body->getUserData(key));
}

/*
GMFN double SetNewtonBodyForceCallback(double newton_body_ptr, double func)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return 0;

   newton_body->SetForceCallback(func);

   return TRUE;
}
*/

GMFN double AttachNewtonBodyToSceneNode(double newton_body_ptr, double scene_node_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (!node)
      return FALSE;

   LockMutex lm(gMutex);

   GMInstance gminst;

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(node);
   if (iter != mSceneNodeAttachments.end())
      gminst = iter->second;

   gminst.BodyAttached = true;
   gminst.mBody = newton_body;

   mSceneNodeAttachments[node] = gminst;
   //mNewtonBodyAttachments[newton_body] = node;

   // We are already attached to our GM object, so update body position/orientation
   if (IsGMInitialized() && (gminst.GMInstanceAttached || gminst.GMPositionVariableAttached || gminst.GMOrientationVariableAttached || gminst.GMScaleVariableAttached))
   {
      if (gminst.GMInstanceAttached)
      {
         gminst.mGMInstancePtr = GetGMInstance(gminst.mGMInstanceID);
         AcquireGMLocalVariablePointers(&gminst);

         Ogre::Vector3 pos = node->_getDerivedPosition();
         Ogre::Quaternion quat = node->_getDerivedOrientation();
      
         // Snap to current position/orientation
         //newton_body->setPositionOrientation(Ogre::Vector3(gminst.mGMInstancePtr->x, gminst.mGMInstancePtr->y, *gminst.pZ), Euler(Ogre::Degree(ConvertFromGMYaw(*gminst.pYaw)), Ogre::Degree(ConvertFromGMPitch(*gminst.pPitch)), Ogre::Degree(ConvertFromGMRoll(*gminst.pRoll))));
         newton_body->setPositionOrientation(pos, quat);
      }
      if (gminst.GMPositionVariableAttached)
      {
         Ogre::Vector3 pos;
         Ogre::Quaternion quat;
         newton_body->getPositionOrientation(pos, quat);
         pos = node->_getDerivedPosition();
         newton_body->setPositionOrientation(pos, quat);
      }
      if (gminst.GMOrientationVariableAttached)
      {
         Ogre::Vector3 pos;
         Ogre::Quaternion quat;
         newton_body->getPositionOrientation(pos, quat);
         quat = node->_getDerivedOrientation();
         newton_body->setPositionOrientation(pos, quat);
      }
   }

   newton_body->attachNode(node);

   return TRUE;
}


GMFN double DetachNewtonBodyFromSceneNode(double newton_body_ptr, double scene_node_ptr)
{
   OgreNewtBody *newton_body = ConvertFromGMPointer<OgreNewtBody*>(newton_body_ptr);

   if (!newton_body)
      return FALSE;

   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (!node)
      return FALSE;

   if (newton_body->getOgreNode() == node)
   {
      newton_body->attachNode(NULL);

      LockMutex lm(gMutex);

      SceneNodeMap::iterator iter = mSceneNodeAttachments.find(node);

      if (iter == mSceneNodeAttachments.end())
         return FALSE;

      // Remove from map if needed.
      (&iter->second)->BodyAttached = false;
      (&iter->second)->mBody = NULL;
      if (iter->second.GMInstanceAttached == false)
         mSceneNodeAttachments.erase(iter);

      //mNewtonBodyAttachments.erase(mNewtonBodyAttachments.find(newton_body));
   }

   return TRUE;
}

#endif
