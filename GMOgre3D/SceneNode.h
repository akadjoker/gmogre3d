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

#ifndef GMOGRE_SCENE_NODE_H
#define GMOGRE_SCENE_NODE_H

#include "GMOgre3D.h"
#include "NewtonBody.h"
#include "LockMutex.h"


GMFN double GetRootSceneNode()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::SceneNode *node = mSceneMgr->getRootSceneNode();

   return ConvertToGMPointer(node);
}


GMFN double CreateSceneNode()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::SceneNode *node = NULL;
   
   TRY
      node = mSceneMgr->createSceneNode();
      node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(0)), Ogre::Degree(0), Ogre::Degree(0)));
   CATCH("CreateSceneNode")

   return ConvertToGMPointer(node);
}


GMFN double CreateRootChildSceneNode(double x, double z, double y, double yaw, double pitch, double roll)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::SceneNode *node = NULL;
   
   TRY
      node = mSceneMgr->getRootSceneNode()->createChildSceneNode(ConvertFromGMAxis(x, y, z), Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));
   CATCH("CreateRootChildSceneNode")
   
   return ConvertToGMPointer(node);
}


GMFN double CreateChildSceneNode(double scene_node_ptr, double x, double z, double y, double yaw, double pitch, double roll)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::SceneNode *child_node = NULL;
   
   TRY
      if (scene_node == mSceneMgr->getRootSceneNode())
         child_node = scene_node->createChildSceneNode(ConvertFromGMAxis(x, y, z), Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));
      else
         child_node = scene_node->createChildSceneNode(ConvertFromGMAxis(x, y, z), Euler(Ogre::Degree(ConvertFromGMYaw(yaw + 90)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));
   CATCH("CreateChildSceneNode")

   return ConvertToGMPointer(child_node);
}


GMFN double DestroySceneNode(double scene_node_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->destroySceneNode(ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr));

   return TRUE;
}


GMFN double AddChildSceneNode(double parent_scene_node_ptr, double scene_node_ptr)
{
   Ogre::SceneNode *parent_scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(parent_scene_node_ptr);

   if (parent_scene_node == NULL)
      return FALSE;

   Ogre::SceneNode *child_scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (child_scene_node == NULL)
      return FALSE;

   parent_scene_node->addChild(child_scene_node);

   return TRUE;
}


GMFN double RemoveChildSceneNode(double parent_scene_node_ptr, double scene_node_ptr)
{
   Ogre::SceneNode *parent_scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(parent_scene_node_ptr);

   if (parent_scene_node == NULL)
      return FALSE;

   Ogre::SceneNode *child_scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (child_scene_node == NULL)
      return FALSE;

   parent_scene_node->removeChild(child_scene_node);

   return TRUE;
}


GMFN double AttachObjectToSceneNode(double scene_node_ptr, double obj_ptr)
{
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   Ogre::MovableObject *obj = ConvertFromGMPointer<Ogre::MovableObject*>(obj_ptr);

   if (obj == NULL)
      return FALSE;
   
   node->attachObject(obj);

   return TRUE;
}


GMFN double DetachObjectFromSceneNode(double scene_node_ptr, double obj_ptr)
{
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   Ogre::MovableObject *obj = ConvertFromGMPointer<Ogre::MovableObject*>(obj_ptr);

   if (obj == NULL)
      return FALSE;
   
   node->detachObject(obj);

   return TRUE;
}


GMFN double EnableSceneNodeInheritScale(double scene_node_ptr, double enable)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setInheritScale((enable != 0));

   return TRUE;
}


GMFN double EnableSceneNodeInheritOrientation(double scene_node_ptr, double enable)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setInheritOrientation((enable != 0));

   return TRUE;
}


GMFN double SetSceneNodeScale(double scene_node_ptr, double x, double z, double y)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setScale(ConvertFromGMAxis(x, y, z));
   
   return TRUE;
}


GMFN double GetSceneNodeScale(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Vector3 vec = scene_node->getScale();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double GetSceneNodeDerivedScale(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Vector3 vec = scene_node->_getDerivedScale();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double SetSceneNodePosition(double scene_node_ptr, double x, double z, double y)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setPosition(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetSceneNodeDerivedPosition(double scene_node_ptr, double x, double z, double y)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   //scene_node->setPosition(ConvertFromGMAxis(x, y, z));
   
   // This bit of trickery can be replaced with a simple _setDerivedPosition call once
   // OGRE 1.7 is released and merged into GMOgre.
   //scene_node->setPosition(scene_node->getParent()->_getDerivedOrientation().Inverse() * (ConvertFromGMAxis(x, y, z) - scene_node->getParent()->_getDerivedPosition()) / scene_node->getParent()->_getDerivedScale());
   scene_node->_setDerivedPosition(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double GetSceneNodePosition(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Vector3 vec = scene_node->getPosition();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double GetSceneNodeDerivedPosition(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Vector3 vec = scene_node->_getDerivedPosition();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double SetSceneNodeDirection(double scene_node_ptr, double xto, double zto, double yto, double relative_type = 0.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setDirection(ConvertFromGMAxis(xto, yto, zto), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double SetSceneNodeLookAt(double scene_node_ptr, double xup, double zup, double yup, double relative_type)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->lookAt(ConvertFromGMAxis(xup, yup, zup), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double SetSceneNodeInitalState(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setInitialState();

   return TRUE;
}


GMFN double SetSceneNodeDerivedOrientation(double scene_node_ptr, double yaw, double pitch, double roll)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   // This bit of trickery can be replaced with a simple _setDerivedOrientation call once
   // OGRE 1.7 is released and merged into GMOgre.
   //scene_node->setOrientation(scene_node->getParent()->_getDerivedOrientation().Inverse() * Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree((Ogre::Real)pitch), Ogre::Degree((Ogre::Real)roll)));
   scene_node->_setDerivedOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));

   return TRUE;
}


GMFN double SetSceneNodeOrientation(double scene_node_ptr, double yaw, double pitch, double roll)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   // If we are a child scene node that inherits our parents orientation then
   // we don't WANT to yaw -90... so take this into consideration!
   if (scene_node->getParentSceneNode() == mSceneMgr->getRootSceneNode())
      scene_node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));
   else
      scene_node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw + 90)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))));

   return TRUE;
}


GMFN double GetSceneNodeOrientation(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Quaternion quat = scene_node->getOrientation();

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      Euler euler = QuaternionToEuler(quat);

      if (scene_node->getParentSceneNode() == mSceneMgr->getRootSceneNode())
         SetGMVariable(*mEulerYaw, ConvertToGMYaw(euler.getYaw().valueDegrees()));
      else
         SetGMVariable(*mEulerYaw, ConvertToGMYaw(euler.getYaw().valueDegrees() - 90));

      SetGMVariable(*mEulerPitch, ConvertToGMPitch(euler.getPitch().valueDegrees()));
      SetGMVariable(*mEulerRoll, ConvertToGMRoll(euler.getRoll().valueDegrees()));
   }

   return TRUE;
}


GMFN double GetSceneNodeDerivedOrientation(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Quaternion quat = scene_node->_getDerivedOrientation();

   AcquireGMEulerGlobals();
   if (mEulerYaw != NULL)
   {
      Euler euler = QuaternionToEuler(quat);

      SetGMVariable(*mEulerYaw, ConvertToGMYaw(euler.getYaw().valueDegrees()));
      SetGMVariable(*mEulerPitch, ConvertToGMPitch(euler.getPitch().valueDegrees()));
      SetGMVariable(*mEulerRoll, ConvertToGMRoll(euler.getRoll().valueDegrees()));
   }

   return TRUE;
}


GMFN double SetSceneNodeRoll(double scene_node_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->roll(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetSceneNodeRoll(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Quaternion quat = scene_node->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMRoll(euler.getRoll().valueDegrees());
}


GMFN double SetSceneNodeYaw(double scene_node_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->yaw(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetSceneNodeYaw(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Quaternion quat = scene_node->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMYaw(euler.getYaw().valueDegrees());
}


GMFN double SetSceneNodePitch(double scene_node_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->pitch(Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetSceneNodePitch(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Quaternion quat = scene_node->getOrientation();
   Euler euler = QuaternionToEuler(quat);

   return ConvertToGMPitch(quat.getPitch().valueDegrees());
}


GMFN double RotateSceneNode(double scene_node_ptr, double x, double z, double y, double degrees, double relative_type = 1.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->rotate(ConvertFromGMAxis(x, y, z), Ogre::Degree((Ogre::Real)degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double ResetSceneNodeOrientation(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->resetOrientation();

   return TRUE;
}


GMFN double TranslateSceneNode(double scene_node_ptr, double x, double z, double y, double relative_type = 1.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(ConvertFromGMAxis(x, y, z), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double ShowSceneNode(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setVisible(true);

   return TRUE;
}


GMFN double HideSceneNode(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setVisible(false);

   return TRUE;
}


GMFN double ShowSceneNodeBoundingBox(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->showBoundingBox(true);

   return TRUE;
}


GMFN double HideSceneNodeBoundingBox(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->showBoundingBox(false);

   return TRUE;
}


GMFN double MoveSceneNodeLeft(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::UNIT_X * (Ogre::Real)delta));

   return TRUE;
}


GMFN double MoveSceneNodeRight(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::NEGATIVE_UNIT_X * (Ogre::Real)delta));

   return TRUE;
}


GMFN double MoveSceneNodeForward(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::UNIT_Z * (Ogre::Real)delta));

   return TRUE;
}


GMFN double MoveSceneNodeBackward(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::NEGATIVE_UNIT_Z * (Ogre::Real)delta));

   return TRUE;
}


GMFN double MoveSceneNodeUp(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::UNIT_Y * (Ogre::Real)delta));

   return TRUE;
}


GMFN double MoveSceneNodeDown(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::NEGATIVE_UNIT_Y * (Ogre::Real)delta));

   return TRUE;
}


GMFN double EnableSceneNodeAutoTracking(double scene_node_ptr, double enable, double track_scene_node_ptr, double x, double z, double y)
{
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (node == NULL)
      return FALSE;

   if (enable != 0)
   {
      Ogre::SceneNode *track_node = ConvertFromGMPointer<Ogre::SceneNode*>(track_scene_node_ptr);

      if (track_node == NULL)
         return FALSE;

      node->setAutoTracking(true, track_node, ConvertFromGMAxis(x, y, z));
   }
   else
      node->setAutoTracking(false);

   return TRUE;
}


GMFN double GetSceneNodeBoundingBoxSize(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->_updateBounds();
   Ogre::Vector3 vec = scene_node->_getWorldAABB().getSize();

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double GetSceneNodeBoundingBoxCorner(double scene_node_ptr, double index)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

      scene_node->_updateBounds();
      Ogre::Vector3 vec = scene_node->_getWorldAABB().getCorner(static_cast<Ogre::AxisAlignedBox::CornerEnum>((int)index));

   SetGMVectorGlobals(vec);

   return TRUE;
}


GMFN double AttachSceneNodeToGMInstance(double scene_node_ptr, double gm_instance_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   if (!IsGMInitialized())
      return FALSE;

   LockMutex lm(gMutex);

   GMInstance gminst;

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);
   if (iter != mSceneNodeAttachments.end())
      gminst = iter->second;

   gminst.GMInstanceAttached = true;
   gminst.mGMInstanceID = (int)gm_instance_ptr;

   gminst.mGMInstancePtr = GetGMInstance((int)gm_instance_ptr);
   AcquireGMLocalVariablePointers(&gminst);

   gminst.mLastX = gminst.mGMInstancePtr->x;
   gminst.mLastY = gminst.mGMInstancePtr->y;
	gminst.mLastZ = GetGMRealVariable(*gminst.pZ);
   gminst.mLastYaw = GetGMRealVariable(*gminst.pYaw);
	gminst.mLastPitch = GetGMRealVariable(*gminst.pPitch);
	gminst.mLastRoll = GetGMRealVariable(*gminst.pRoll);
	gminst.mLastScaleX = GetGMRealVariable(*gminst.pScaleX);
	gminst.mLastScaleY = GetGMRealVariable(*gminst.pScaleY);
	gminst.mLastScaleZ = GetGMRealVariable(*gminst.pScaleZ);

   mSceneNodeAttachments[scene_node] = gminst;

   // Snap to current position, orientation, and scale
   //scene_node->setPosition(ConvertFromGMAxis(gminst.mLastX, gminst.mLastZ, gminst.mLastY));
   //scene_node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(*gminst.pYaw)), Ogre::Degree(*gminst.pPitch), Ogre::Degree(*gminst.pRoll)));
   //scene_node->setScale(ConvertFromGMAxis(gminst.mLastScaleX, gminst.mLastScaleZ, gminst.mLastScaleY));
   SetSceneNodePosition(ConvertToGMPointer(scene_node), gminst.mLastX, gminst.mLastY, gminst.mLastZ);
   SetSceneNodeOrientation(ConvertToGMPointer(scene_node), GetGMRealVariable(*gminst.pYaw), GetGMRealVariable(*gminst.pPitch), GetGMRealVariable(*gminst.pRoll));
   SetSceneNodeScale(ConvertToGMPointer(scene_node), gminst.mLastScaleX, gminst.mLastScaleY, gminst.mLastScaleZ);

   if (gminst.BodyAttached && gminst.mBody != NULL)
   {
      // Snap to current position/orientation
      SetNewtonBodyPosition(ConvertToGMPointer(gminst.mBody), gminst.mGMInstancePtr->x, gminst.mGMInstancePtr->y, GetGMRealVariable(*gminst.pZ));
      SetNewtonBodyOrientation(ConvertToGMPointer(gminst.mBody), GetGMRealVariable(*gminst.pYaw), GetGMRealVariable(*gminst.pPitch), GetGMRealVariable(*gminst.pRoll));
   }

   return TRUE;
}


GMFN double DetachSceneNodeFromGMInstance(double scene_node_ptr, double gm_instance_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   LockMutex lm(gMutex);

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);

   if (iter == mSceneNodeAttachments.end())
      return FALSE;

   // Remove from map if needed.
   (&iter->second)->GMInstanceAttached = false;
   if (iter->second.BodyAttached == false && iter->second.GMPositionVariableAttached == false && iter->second.GMOrientationVariableAttached == false && iter->second.GMScaleVariableAttached == false)
      mSceneNodeAttachments.erase(iter);
   
   return TRUE;
}


GMFN double AttachSceneNodePositionToGMVariable(double scene_node_ptr, char *gm_variable_name, double gm_variable_index)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   if (!IsGMInitialized())
      return FALSE;

   LockMutex lm(gMutex);

   GMInstance gminst;

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);
   if (iter != mSceneNodeAttachments.end())
      gminst = iter->second;

   gminst.GMPositionVariableAttached = true;
   gminst.sGlobalPosition = gm_variable_name;
   gminst.iGlobalPositionIndex = (unsigned int)gm_variable_index;

   AcquireGMGlobalVariablePointer(&gminst);

   if (!gminst.pGlobalPosition)
      return FALSE;

   Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst.pGlobalPosition, gminst.iGlobalPositionIndex);
   gminst.mLastX = vec.x;
   gminst.mLastY = vec.y;
	gminst.mLastZ = vec.z;

   mSceneNodeAttachments[scene_node] = gminst;

   // Snap to current position
   //scene_node->setPosition(ConvertFromGMAxis(gminst.mLastX, gminst.mLastZ, gminst.mLastY));
   SetSceneNodePosition(ConvertToGMPointer(scene_node), gminst.mLastX, gminst.mLastY, gminst.mLastZ);

   if (gminst.BodyAttached && gminst.mBody != NULL)
   {
      // Snap to current position/orientation
      SetNewtonBodyPosition(ConvertToGMPointer(gminst.mBody), gminst.mLastX, gminst.mLastY, gminst.mLastZ);
   }

   return TRUE;
}


GMFN double DetachSceneNodePositionFromGMVariable(double scene_node_ptr, double gm_instance_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   LockMutex lm(gMutex);

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);

   if (iter == mSceneNodeAttachments.end())
      return FALSE;

   // Remove from map if needed.
   (&iter->second)->GMPositionVariableAttached = false;
   if (iter->second.BodyAttached == false && iter->second.GMInstanceAttached == false && iter->second.GMOrientationVariableAttached == false && iter->second.GMScaleVariableAttached == false)
      mSceneNodeAttachments.erase(iter);
   
   return TRUE;
}


GMFN double AttachSceneNodeOrientationToGMVariable(double scene_node_ptr, char *gm_variable_name, double gm_variable_index)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   if (!IsGMInitialized())
      return FALSE;

   LockMutex lm(gMutex);

   GMInstance gminst;

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);
   if (iter != mSceneNodeAttachments.end())
      gminst = iter->second;

   gminst.GMOrientationVariableAttached = true;
   gminst.sGlobalOrientation = gm_variable_name;
   gminst.iGlobalOrientationIndex = (unsigned int)gm_variable_index;

   AcquireGMGlobalVariablePointer(&gminst);

   if (!gminst.pGlobalOrientation)
      return FALSE;

   Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst.pGlobalOrientation, gminst.iGlobalOrientationIndex);
   gminst.mLastYaw = vec.x;
   gminst.mLastPitch = vec.y;
	gminst.mLastRoll = vec.z;

   mSceneNodeAttachments[scene_node] = gminst;

   // Snap to current orientation
   //scene_node->setOrientation(ConvertFromGMAxis(gminst.mLastYaw, gminst.mLastPitch, gminst.mLastRoll));
   SetSceneNodeOrientation(ConvertToGMPointer(scene_node), gminst.mLastYaw, gminst.mLastPitch, gminst.mLastRoll);

   if (gminst.BodyAttached && gminst.mBody != NULL)
   {
      // Snap to current position/orientation
      SetNewtonBodyOrientation(ConvertToGMPointer(gminst.mBody), gminst.mLastYaw, gminst.mLastPitch, gminst.mLastRoll);
   }

   return TRUE;
}


GMFN double DetachSceneNodeOrientationFromGMVariable(double scene_node_ptr, double gm_instance_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   LockMutex lm(gMutex);

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);

   if (iter == mSceneNodeAttachments.end())
      return FALSE;

   // Remove from map if needed.
   (&iter->second)->GMOrientationVariableAttached = false;
   if (iter->second.BodyAttached == false && iter->second.GMInstanceAttached == false && iter->second.GMPositionVariableAttached == false && iter->second.GMScaleVariableAttached == false)
      mSceneNodeAttachments.erase(iter);
   
   return TRUE;
}


GMFN double AttachSceneNodeScaleToGMVariable(double scene_node_ptr, char *gm_variable_name, double gm_variable_index)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   if (!IsGMInitialized())
      return FALSE;

   LockMutex lm(gMutex);

   GMInstance gminst;

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);
   if (iter != mSceneNodeAttachments.end())
      gminst = iter->second;

   gminst.GMScaleVariableAttached = true;
   gminst.sGlobalScale = gm_variable_name;
   gminst.iGlobalScaleIndex = (unsigned int)gm_variable_index;

   AcquireGMGlobalVariablePointer(&gminst);

   if (!gminst.pGlobalScale)
      return FALSE;

   Ogre::Vector3 vec = RetrieveGMGlobalArray(gminst.pGlobalScale, gminst.iGlobalScaleIndex);
   gminst.mLastScaleX = vec.x;
   gminst.mLastScaleY = vec.y;
	gminst.mLastScaleZ = vec.z;

   mSceneNodeAttachments[scene_node] = gminst;

   // Snap to current scale
   //scene_node->setScale(ConvertFromGMAxis(gminst.mLastScaleX, gminst.mLastScaleY, gminst.mLastScaleZ));
   SetSceneNodeScale(ConvertToGMPointer(scene_node), gminst.mLastScaleX, gminst.mLastScaleY, gminst.mLastScaleZ);

   if (gminst.BodyAttached && gminst.mBody != NULL)
   {
      // Snap to current scale
      //SetNewtonBodyScale(ConvertToGMPointer(gminst.mBody), gminst.mLastScaleX, gminst.mLastScaleY, gminst.mLastScaleZ);
   }

   return TRUE;
}


GMFN double DetachSceneNodeScaleFromGMVariable(double scene_node_ptr, double gm_instance_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   LockMutex lm(gMutex);

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);

   if (iter == mSceneNodeAttachments.end())
      return FALSE;

   // Remove from map if needed.
   (&iter->second)->GMScaleVariableAttached = false;
   if (iter->second.BodyAttached == false && iter->second.GMInstanceAttached == false && iter->second.GMPositionVariableAttached == false && iter->second.GMOrientationVariableAttached == false)
      mSceneNodeAttachments.erase(iter);
   
   return TRUE;
}

#endif
