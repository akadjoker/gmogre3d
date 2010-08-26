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

#ifndef GMOGRE_ENTITY_H
#define GMOGRE_ENTITY_H

#include "GMOgre3D.h"
#include "Material.h"
#include "NewtonBody.h"


static Ogre::String anim_names;
static Ogre::String entity_entity_bone_name;
static double entity_id;
static double entity_entity_id;


GMFN double CreateEntity(char *mesh_name)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *entity = NULL;
   
   TRY
      entity = mSceneMgr->createEntity(GenerateUniqueName(), mesh_name);

   CATCH("CreateEntity")

   return ConvertToGMPointer(entity);
}


GMFN double CreateCubeEntity()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *ent = NULL;
   
   TRY
      ent = mSceneMgr->createEntity(GenerateUniqueName(), Ogre::SceneManager::PT_CUBE);
   CATCH("CreateCubeEntity")

   return ConvertToGMPointer(ent);
}


GMFN double CreateSphereEntity()
{
   Ogre::Entity *ent = NULL;

   TRY
      ent = mSceneMgr->createEntity(GenerateUniqueName(), Ogre::SceneManager::PT_SPHERE);
   CATCH("CreateSphereEntity")

   return ConvertToGMPointer(ent);
}


GMFN double CreateFloorEntity(double width, double height, double xsegments, double ysegments, double utile, double vtile)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *ent = NULL;

   TRY
      Ogre::Plane plane;
      plane.d = 0;
      plane.normal = Ogre::Vector3::UNIT_Y;

      Ogre::String plane_name = GenerateUniqueName();
      Ogre::MeshManager::getSingleton().createPlane(plane_name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, (Ogre::Real)width, (Ogre::Real)height, (int)xsegments, (int)ysegments, true, 1, (Ogre::Real)utile, (Ogre::Real)vtile, Ogre::Vector3::UNIT_Z);
      ent = mSceneMgr->createEntity(GenerateUniqueName(), plane_name);
   CATCH("CreateFloorEntity")

   return ConvertToGMPointer(ent);
}


GMFN double CreateCeilingEntity(double width, double height, double xsegments, double ysegments, double utile, double vtile)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *ent = NULL;

   TRY
      Ogre::Plane plane;
      plane.d = 0;
      plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;

      Ogre::String plane_name = GenerateUniqueName();
      Ogre::MeshManager::getSingleton().createPlane(plane_name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, (Ogre::Real)width, (Ogre::Real)height, (int)xsegments, (int)ysegments, true, 1, (Ogre::Real)utile, (Ogre::Real)vtile, Ogre::Vector3::UNIT_Z);
      ent = mSceneMgr->createEntity(GenerateUniqueName(), plane_name);
   CATCH("CreateCeilingEntity")

   return ConvertToGMPointer(ent);
}


GMFN double CreateWallEntity(double width, double height, double xsegments, double ysegments, double utile, double vtile)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *ent = NULL;

   TRY
      Ogre::Plane plane;
      plane.d = 0;
      plane.normal = Ogre::Vector3::UNIT_X;

      Ogre::String plane_name = GenerateUniqueName();
      Ogre::MeshManager::getSingleton().createPlane(plane_name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, (Ogre::Real)width, (Ogre::Real)height, (int)xsegments, (int)ysegments, true, 1, (Ogre::Real)utile, (Ogre::Real)vtile, Ogre::Vector3::UNIT_Z);
      ent = mSceneMgr->createEntity(GenerateUniqueName(), plane_name);
   CATCH("CreateWallEntity")

   return ConvertToGMPointer(ent);
}


GMFN double CreatePlaneEntity(double plane_ptr, double width, double height, double xsegments, double ysegments, double utile, double vtile, double dirx, double dirz, double diry)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *ent = NULL;
   
   TRY
      Ogre::Plane *plane = ConvertFromGMPointer<Ogre::Plane*>(plane_ptr);

      if (plane == NULL)
         return FALSE;

      Ogre::String plane_name = GenerateUniqueName();
      Ogre::MeshManager::getSingleton().createPlane(plane_name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *plane, (Ogre::Real)width, (Ogre::Real)height, (int)xsegments, (int)ysegments, true, 1, (Ogre::Real)utile, (Ogre::Real)vtile, Ogre::Vector3((Ogre::Real)dirx, (Ogre::Real)diry, (Ogre::Real)dirz));
      ent = mSceneMgr->createEntity(GenerateUniqueName(), plane_name);
   CATCH("CreatePlaneEntity")

   return ConvertToGMPointer(ent);
}


GMFN double DestroyEntity(double entity_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   mSceneMgr->destroyEntity(ent);

   return TRUE;
}


GMFN double SetEntityMaterial(double entity_ptr, char *mat_name)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setMaterialName(mat_name);

   return TRUE;
}


GMFN double ShowEntity(double entity_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setVisible(true);

   return TRUE;
}


GMFN double HideEntity(double entity_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setVisible(false);

   return TRUE;
}


GMFN double EnableEntityCastShadows(double entity_ptr, double enable)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setCastShadows((enable != 0));

   return TRUE;
}


GMFN double GetEntityAnimationState(double entity_ptr, char *state_name)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return 0;

   Ogre::AnimationState *anim_state = ent->getAnimationState(state_name);

   return ConvertToGMPointer(anim_state);
}


GMFN char *GetEntityAllAnimationStates(double entity_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   anim_names.clear();

   Ogre::AnimationStateSet *anim_set = ent->getAllAnimationStates();
   Ogre::AnimationStateIterator iter = anim_set->getAnimationStateIterator(); 
   while (iter.hasMoreElements()) 
   { 
      Ogre::AnimationState *anim_state = iter.getNext();

	 	if (!anim_names.empty())
         anim_names += ",";
      anim_names += anim_state->getAnimationName(); 
   }

   return const_cast<char*>(anim_names.c_str());
}


GMFN double GetEntitySkeleton(double entity_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return 0;

   Ogre::SkeletonInstance *skel = ent->getSkeleton();

   return ConvertToGMPointer(skel);
}


GMFN double SetEntityRenderingDistance(double entity_ptr, double distance)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setRenderingDistance((Ogre::Real)distance);

   return TRUE;
}


GMFN double AttachEntityToSceneNode(double ent_ptr, double scene_node_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->attachObject(ent);

   return TRUE;
}


GMFN double DetachEntityFromSceneNode(double ent_ptr, double scene_node_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->detachObject(ent);

   return TRUE;
}


GMFN double AttachEntityToEntityBone1(double ent_ptr, double ent_ptr2, char *bone_name)
{
   entity_id = ent_ptr;
   entity_entity_id = ent_ptr2;
   entity_entity_bone_name = bone_name;

   return TRUE;
}


GMFN double AttachEntityToEntityBone2(double x, double y, double z, double yaw, double pitch, double roll)
{
   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_id);

   if (entity == NULL)
      return FALSE;

   Ogre::Entity *entity2 = ConvertFromGMPointer<Ogre::Entity*>(entity_entity_id);

   if (entity2 == NULL)
      return FALSE;

   entity2->attachObjectToBone(entity_entity_bone_name, entity, Euler(Ogre::Degree(ConvertFromGMYaw(yaw + 90)), Ogre::Degree((Ogre::Real)pitch), Ogre::Degree((Ogre::Real)roll)), ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double DetachEntityFromEntityBone(double entity_ptr, double entity_ptr2)
{
   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (entity == NULL)
      return FALSE;
   
   Ogre::Entity *entity2 = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr2);

   if (entity2 == NULL)
      return FALSE;
   
   entity->detachObjectFromBone(entity2->getName());

   return TRUE;
}


GMFN double DetachEntitiesFromEntityBones(double entity_ptr)
{
   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (entity == NULL)
      return FALSE;

   entity->detachAllObjectsFromBone();

   return TRUE;
}


GMFN double GetEntityParentSceneNode(double ent_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   Ogre::SceneNode *node = ent->getParentSceneNode();

   return ConvertToGMPointer(node);
}


GMFN double GetEntityParentNode(double ent_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   Ogre::Node *node = ent->getParentNode();

   return ConvertToGMPointer(node);
}


GMFN double GetEntitySubEntity(double ent_ptr, double sub_index)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return 0;

   return ConvertToGMPointer(ent->getSubEntity((unsigned int)sub_index));
}


GMFN double GetEntitySubEntityByName(double ent_ptr, char *name)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return 0;

   return ConvertToGMPointer(ent->getSubEntity(name));
}


GMFN double GetEntityNumSubEntities(double ent_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return 0;

   return ent->getNumSubEntities();
}


GMFN double SetEntityRenderQueueGroup(double ent_ptr, double type)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return 0;

   ent->setRenderQueueGroup(static_cast<Ogre::RenderQueueGroupID>((int)type));

   return TRUE;
}


GMFN double SetEntityQueryFlags(double ent_ptr, double flags)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetEntityLightFlags(double ent_ptr, double flags)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setLightMask((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetEntityVisibilityFlags(double ent_ptr, double flags)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setVisibilityFlags((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetEntityUserData(double ent_ptr, char *key, double data)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   if (key == NULL)
      ent->getUserObjectBindings().setUserAny(Ogre::Any(data));
   else
      ent->getUserObjectBindings().setUserAny(key, Ogre::Any(data));

   return TRUE;
}


GMFN double GetEntityUserData(double ent_ptr, char *key)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   if (key == NULL)
      return Ogre::any_cast<double>(ent->getUserObjectBindings().getUserAny());
   else
      return Ogre::any_cast<double>(ent->getUserObjectBindings().getUserAny(key));
}

#endif
