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

#ifndef GMOGRE_MOVABLE_OBJECT_H
#define GMOGRE_MOVABLE_OBJECT_H

#include "GMOgre3D.h"
#include "OgreRibbonTrail.h"
#include "OgreBillboardChain.h"
#include "OgreBillboardSet.h"
#include "OgreEntity.h"
#include "OgreLight.h"
#include "OgreManualObject.h"
#include "OgreParticleSystem.h"
#include "OgreParticleSystemManager.h"
#include "OgreTerrainSceneManager.h"
#include "OgreOctreeSceneManager.h"
#include "OgreSceneManager.h"

GMFN double GetMovableObjectType(double movable_object_ptr)
{
   Ogre::MovableObject *mo = ConvertFromGMPointer<Ogre::Entity*>(movable_object_ptr);

   if (mo == NULL)
      return 0;
   
   if (mo->getMovableType() == Ogre::BillboardChainFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_BILLBOARD_CHAIN;
   if (mo->getMovableType() == Ogre::BillboardSetFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_BILLBOARD_SET;
   if (mo->getMovableType() == Ogre::EntityFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_ENTITY;
   if (mo->getMovableType() == Ogre::LightFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_LIGHT;
   if (mo->getMovableType() == Ogre::ParticleSystemFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_PARTICLE_SYSTEM;
   if (mo->getMovableType() == Ogre::RibbonTrailFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_RIBBON_TRAIL;
   if (mo->getMovableType() == Ogre::DefaultSceneManagerFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_DEFAULT_SCENE_MANAGER;
   if (mo->getMovableType() == Ogre::OctreeSceneManagerFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_OCTREE_SCENE_MANAGER;
   if (mo->getMovableType() == Ogre::TerrainSceneManagerFactory::FACTORY_TYPE_NAME)
      return MO_TYPE_TERRAIN_SCENE_MANAGER;

   return 0;
}


GMFN double DetachMovableObjectFromParentSceneNode(double movable_object_ptr)
{
   Ogre::MovableObject *mo = ConvertFromGMPointer<Ogre::Entity*>(movable_object_ptr);

   if (mo == NULL)
      return FALSE;
   
   mo->detatchFromParent();

   return TRUE;
}


GMFN double GetMovableObjectParentSceneNode(double movable_object_ptr)
{
   Ogre::MovableObject *mo = ConvertFromGMPointer<Ogre::MovableObject*>(movable_object_ptr);

   if (mo == NULL)
      return FALSE;

   Ogre::SceneNode *node = mo->getParentSceneNode();

   return ConvertToGMPointer(node);
}


GMFN double SetMovableObjectRenderQueueGroup(double movable_object_ptr, double type)
{
   Ogre::MovableObject *mo = ConvertFromGMPointer<Ogre::MovableObject*>(movable_object_ptr);

   if (mo == NULL)
      return FALSE;

   mo->setRenderQueueGroup(static_cast<Ogre::RenderQueueGroupID>((int)type));

   return TRUE;
}


GMFN double SetMovableObjectQueryFlags(double movable_object_ptr, double flags)
{
   Ogre::MovableObject *mo = ConvertFromGMPointer<Ogre::MovableObject*>(movable_object_ptr);

   if (mo == NULL)
      return FALSE;

   mo->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}

#endif
