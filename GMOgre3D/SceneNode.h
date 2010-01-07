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

#ifndef GMOGRE_SCENE_NODE_H
#define GMOGRE_SCENE_NODE_H

#include "GMOgre3D.h"
#include "NewtonBody.h"


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
      node = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(x, y, z), Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(pitch), Ogre::Degree(roll)));
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
      child_node = scene_node->createChildSceneNode(Ogre::Vector3(x, y, z), Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(pitch), Ogre::Degree(roll)));
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

   scene_node->setScale(Ogre::Vector3(x, y, z));
   
   return TRUE;
}


GMFN double GetSceneNodeScale(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Vector3 vec = scene_node->getScale();

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double SetSceneNodePosition(double scene_node_ptr, double xfrom, double zfrom, double yfrom)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setPosition(Ogre::Vector3(xfrom, yfrom, zfrom));

   return TRUE;
}


GMFN double GetSceneNodePosition(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Vector3 vec = scene_node->getPosition();

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double SetSceneNodeDirection(double scene_node_ptr, double xto, double zto, double yto, double relative_type = 0.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setDirection(xto, yto, zto, static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double SetSceneNodeLookAt(double scene_node_ptr, double xup, double zup, double yup, double relative_type)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->lookAt(Ogre::Vector3(xup, yup, zup), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

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


GMFN double SetSceneNodeOrientation(double scene_node_ptr, double yaw, double pitch, double roll)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree(pitch), Ogre::Degree(roll)));

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
      *mEulerYaw = ConvertToGMYaw(quat.getYaw().valueDegrees());
      *mEulerPitch = quat.getPitch().valueDegrees();
      *mEulerRoll = quat.getRoll().valueDegrees();
   }

   return TRUE;
}


GMFN double SetSceneNodeRoll(double scene_node_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->roll(Ogre::Radian(Ogre::Degree(degrees)), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetSceneNodeRoll(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Quaternion qt = scene_node->getOrientation();

   return qt.getRoll().valueDegrees();
}


GMFN double SetSceneNodeYaw(double scene_node_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->yaw(Ogre::Radian(Ogre::Degree(degrees)), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetSceneNodeYaw(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Quaternion qt = scene_node->getOrientation();

   return ConvertToGMYaw(qt.getYaw().valueDegrees());
}


GMFN double SetSceneNodePitch(double scene_node_ptr, double degrees, double relative_type = 0.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->pitch(Ogre::Radian(Ogre::Degree(degrees)), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

   return TRUE;
}


GMFN double GetSceneNodePitch(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   //Ogre::Quaternion qt = scene_node->getOrientation();
   //return qt.getPitch().valueDegrees();

   // Retrieve proper pitch by removing scene node yaw
   Ogre::Quaternion old_qt = scene_node->getOrientation();
   scene_node->yaw(old_qt.getYaw() * -1);
   Ogre::Quaternion qt = scene_node->getOrientation();
   scene_node->setOrientation(old_qt);

   return old_qt.getPitch().valueDegrees();
}


GMFN double RotateSceneNode(double scene_node_ptr, double x, double z, double y, double degrees, double relative_type = 1.0)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->rotate(Ogre::Vector3(x, y, z), Ogre::Degree(degrees), static_cast<Ogre::Node::TransformSpace>((int)relative_type));

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

   scene_node->translate(z, y, z, static_cast<Ogre::Node::TransformSpace>((int)relative_type));

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

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::UNIT_X * delta));

   return TRUE;
}


GMFN double MoveSceneNodeRight(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::NEGATIVE_UNIT_X * delta));

   return TRUE;
}


GMFN double MoveSceneNodeForward(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::UNIT_Z * delta));

   return TRUE;
}


GMFN double MoveSceneNodeBackward(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::NEGATIVE_UNIT_Z * delta));

   return TRUE;
}


GMFN double MoveSceneNodeUp(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::UNIT_Y * delta));

   return TRUE;
}


GMFN double MoveSceneNodeDown(double scene_node_ptr, double delta)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   scene_node->translate(scene_node->getOrientation() * (Ogre::Vector3::NEGATIVE_UNIT_Y * delta));

   return TRUE;
}


GMFN double GetSceneNodeBoundingBoxSize(double scene_node_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   Ogre::Vector3 vec = scene_node->_getWorldAABB().getSize();

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double AttachSceneNodeToGMInstance(double scene_node_ptr, double gm_instance_ptr)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return FALSE;

   if (mGMAPI == NULL)
      return FALSE;

   LockMutex lm(gMutex);

   GMInstance gminst;

   SceneNodeMap::iterator iter = mSceneNodeAttachments.find(scene_node);
   if (iter != mSceneNodeAttachments.end())
      gminst = iter->second;

   gminst.GMInstanceAttached = true;
   gminst.mGMInstanceID = (int)gm_instance_ptr;

   gminst.mGMInstancePtr = mGMAPI->GetInstancePtr((int)gm_instance_ptr);
   AcquireGMLocalVariablePointers(&gminst);

   gminst.mLastX = gminst.mGMInstancePtr->x;
   gminst.mLastY = gminst.mGMInstancePtr->y;
	gminst.mLastZ = *gminst.pZ;
   gminst.mLastYaw = gminst.mGMInstancePtr->direction;
	gminst.mLastPitch = *gminst.pPitch;
	gminst.mLastRoll = *gminst.pRoll;
	gminst.mLastScaleX = *gminst.pScaleX;
	gminst.mLastScaleY = *gminst.pScaleY;
	gminst.mLastScaleZ = *gminst.pScaleZ;

   mSceneNodeAttachments[scene_node] = gminst;

   // Snap to current position, orientation, and scale
   scene_node->setPosition(gminst.mLastX, gminst.mLastZ, gminst.mLastY);
   scene_node->setOrientation(Euler(Ogre::Degree(ConvertFromGMYaw(gminst.mGMInstancePtr->direction)), Ogre::Degree(*gminst.pPitch), Ogre::Degree(*gminst.pRoll)));
   scene_node->setScale(gminst.mLastScaleX, gminst.mLastScaleZ, gminst.mLastScaleY);

   if (gminst.BodyAttached && gminst.mBody != NULL)
   {
      // Snap to current position/orientation
      SetNewtonBodyPosition(ConvertToGMPointer(gminst.mBody), gminst.mGMInstancePtr->x, gminst.mGMInstancePtr->y, *gminst.pZ);
      SetNewtonBodyOrientation(ConvertToGMPointer(gminst.mBody), gminst.mGMInstancePtr->direction, *gminst.pPitch, *gminst.pRoll);
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
   if (iter->second.BodyAttached == false)
      mSceneNodeAttachments.erase(iter);
   
   return TRUE;
}

#endif
