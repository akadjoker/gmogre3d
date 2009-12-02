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

#ifndef GMOGRE_ENTITY_H
#define GMOGRE_ENTITY_H

#include "GMOgre3D.h"
#include "Material.h"


static Ogre::String anim_names;

GMFN double CreateEntity(char *mesh_name)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *entity = mSceneMgr->createEntity(GenerateUniqueName(), mesh_name);

   return ConvertToGMPointer(entity);
}


GMFN double CreateCubeEntity()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Entity *entity = mSceneMgr->createEntity(GenerateUniqueName(), Ogre::SceneManager::PT_CUBE);

   return ConvertToGMPointer(entity);
}


GMFN double CreateSphereEntity()
{
   Ogre::Entity *entity = mSceneMgr->createEntity(GenerateUniqueName(), Ogre::SceneManager::PT_SPHERE);

   return ConvertToGMPointer(entity);
}


GMFN double CreateFloorEntity(double width, double height, double xsegments, double ysegments, double hrepeat, double vrepeat)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Plane plane;
   plane.d = 0;
   plane.normal = Ogre::Vector3::UNIT_Y;

   Ogre::String plane_name = GenerateUniqueName();
   Ogre::MeshManager::getSingleton().createPlane(plane_name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, width, height, xsegments, ysegments, true, 1, hrepeat, vrepeat, Ogre::Vector3::UNIT_Z);
   Ogre::Entity *ent = mSceneMgr->createEntity(GenerateUniqueName(), plane_name);

   return ConvertToGMPointer(ent);
}


GMFN double CreateCeilingEntity(double width, double height, double xsegments, double ysegments, double hrepeat, double vrepeat)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Plane plane;
   plane.d = 0;
   plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;

   Ogre::String plane_name = GenerateUniqueName();
   Ogre::MeshManager::getSingleton().createPlane(plane_name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, width, height, xsegments, ysegments, true, 1, hrepeat, vrepeat, Ogre::Vector3::UNIT_Z);
   Ogre::Entity *ent = mSceneMgr->createEntity(GenerateUniqueName(), plane_name);

   return ConvertToGMPointer(ent);
}


GMFN double CreateWallEntity(double width, double height, double xsegments, double ysegments, double hrepeat, double vrepeat)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Plane plane;
   plane.d = 0;
   plane.normal = Ogre::Vector3::UNIT_X;

   Ogre::String plane_name = GenerateUniqueName();
   Ogre::MeshManager::getSingleton().createPlane(plane_name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane, width, height, xsegments, ysegments, true, 1, hrepeat, vrepeat, Ogre::Vector3::UNIT_Z);
   Ogre::Entity *ent = mSceneMgr->createEntity(GenerateUniqueName(), plane_name);

   return ConvertToGMPointer(ent);
}


GMFN double CreatePlaneEntity(double plane_ptr, double width, double height, double xsegments, double ysegments, double hrepeat, double vrepeat, double dirx, double dirz, double diry)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Plane *plane = ConvertFromGMPointer<Ogre::Plane*>(plane_ptr);

   if (plane == NULL)
      return FALSE;

   Ogre::String plane_name = GenerateUniqueName();
   Ogre::MeshManager::getSingleton().createPlane(plane_name, Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *plane, width, height, xsegments, ysegments, true, 1, hrepeat, vrepeat, Ogre::Vector3(dirx, diry, dirz));
   Ogre::Entity *ent = mSceneMgr->createEntity(GenerateUniqueName(), plane_name);

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

   ent->setRenderingDistance(distance);

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


GMFN double GetEntityParentSceneNode(double ent_ptr)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   Ogre::SceneNode *node = ent->getParentSceneNode();

   return ConvertToGMPointer(node);
}


GMFN double SetEntityQueryFlags(double ent_ptr, double flags)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   ent->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}

#endif
