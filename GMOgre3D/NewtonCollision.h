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

#ifndef GMOGRE_NEWTON_COLLISION
#define GMOGRE_NEWTON_COLLISION

#include "OgreNewtWorld.h"
#include "OgreNewt_Collision.h"
#include "OgreNewt_CollisionPrimitives.h"
#include "OgreNewt_CollisionSerializer.h"


GMFN double CreateNewtonBoxCollision(double newton_world_ptr, double x, double z, double y, double id = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col = OgreNewt::CollisionPtr(new OgreNewt::CollisionPrimitives::Box(world, Ogre::Vector3(x, y, z), id));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonBoxCollision")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonCapsuleCollision(double newton_world_ptr, double radius, double height, double id = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::Capsule(world, radius, height, id));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonCapsuleCollision")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonChamferCylinderCollision(double newton_world_ptr, double radius, double height, double id = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::ChamferCylinder(world, radius, height, id));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonChamferCylinderCollision")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonCylinderCollision(double newton_world_ptr, double radius, double height, double id = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::Cylinder(world, radius, height, id));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonCylinderCollision")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonConeCollision(double newton_world_ptr, double radius, double height, double id = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::Cone(world, radius, height, id));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonConeCollision")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonConvexHullCollisionFromEntity(double newton_world_ptr, double entity_ptr, double id = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (!entity)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::ConvexHull(world, entity, id));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonConvexHullCollisionFromEntity")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonEllipsoidCollision(double newton_world_ptr, double x, double z, double y, double id = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::Ellipsoid(world, Ogre::Vector3(x, y, z), id));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonEllipsoidCollision")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonPyramidCollision(double newton_world_ptr, double x, double z, double y, double id = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::Pyramid(world, Ogre::Vector3(x, y, z), id));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonPyramidCollision")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonTreeCollision(double newton_world_ptr)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::TreeCollision(world));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonTreeCollision")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonTreeCollisionFromEntity(double newton_world_ptr, double entity_ptr, double optimize, double id = 0, double face_winding = 0)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (!entity)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      col.reset(new OgreNewt::CollisionPrimitives::TreeCollision(world, entity, (optimize != 0), (int)id, static_cast<OgreNewt::CollisionPrimitives::FaceWinding>((int)face_winding)));
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonTreeCollisionFromEntity")

   return ConvertToGMPointer(col.get());
}


GMFN double CreateNewtonCollisionFromFile(double newton_world_ptr, char *filename)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr)->getOgreNewtWorld();

   if (!world)
      return 0;

   OgreNewt::CollisionPtr col;

   TRY
      Ogre::DataStreamPtr stream = Ogre::ResourceGroupManager::getSingletonPtr()->openResource(filename);
      OgreNewt::CollisionSerializer collision_serializer;
      col = collision_serializer.importCollision((*stream.get()), world);
      mNewtonCollisionMap[col.get()] = col;
   CATCH("CreateNewtonCollisionFromFile")

   return ConvertToGMPointer(col.get());
}


GMFN double DestroyNewtonCollision(double newton_collision_ptr)
{
   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);

   if (!collision)
      return FALSE;

   if (mNewtonCollisionMap.find(collision) != mNewtonCollisionMap.end())
      mNewtonCollisionMap.erase(collision);

   return TRUE;
}


GMFN double ExportNewtonCollisionToFile(double newton_collision_ptr, char *filename)
{
   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);

   if (!collision)
      return FALSE;

   TRY
      OgreNewt::CollisionSerializer collision_serializer;

      if (mNewtonCollisionMap.find(collision) != mNewtonCollisionMap.end())
         collision_serializer.exportCollision(mNewtonCollisionMap[collision], filename);
   CATCH("ExportNewtonCollisionToFile")

   return TRUE;
}


GMFN double StartNewtonTreeCollision(double newton_collision_ptr, double id)
{
   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);
   
   if (!collision)
      return FALSE;

   if (collision->getCollisionPrimitiveType() != OgreNewt::TreeCollisionPrimitiveType)
      return FALSE;

   OgreNewt::CollisionPrimitives::TreeCollision *tree_col = (OgreNewt::CollisionPrimitives::TreeCollision *)collision;
   tree_col->start(id);

   return TRUE;
}


GMFN double AddNewtonTreeCollisionPoly(double newton_collision_ptr, double x, double z, double y, double id)
{
   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);
   
   if (!collision)
      return FALSE;

   if (collision->getCollisionPrimitiveType() != OgreNewt::TreeCollisionPrimitiveType)
      return FALSE;

   OgreNewt::CollisionPrimitives::TreeCollision *tree_col = (OgreNewt::CollisionPrimitives::TreeCollision *)collision;
   tree_col->addPoly(&Ogre::Vector3(x, y, z), id);

   return TRUE;
}


GMFN double FinishNewtonTreeCollision(double newton_collision_ptr, double optimize)
{
   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);
   
   if (!collision)
      return FALSE;

   if (collision->getCollisionPrimitiveType() != OgreNewt::TreeCollisionPrimitiveType)
      return FALSE;

   OgreNewt::CollisionPrimitives::TreeCollision *tree_col = (OgreNewt::CollisionPrimitives::TreeCollision *)collision;
   tree_col->finish((optimize != 0));

   return TRUE;
}


GMFN double CalculateNewtonConvexCollisionInertia(double newton_collision_ptr)
{
   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);
   
   if (!collision)
      return FALSE;

   if (collision->getCollisionPrimitiveType() == OgreNewt::TreeCollisionPrimitiveType)
      return FALSE;

   OgreNewt::ConvexCollision *col = reinterpret_cast<OgreNewt::ConvexCollision*>(collision);

   Ogre::Vector3 vec, vec2;

   col->calculateInertialMatrix(vec, vec2);

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double CalculateNewtonConvexCollisionCenterOfMass(double newton_collision_ptr)
{
   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);
   
   if (!collision)
      return FALSE;

   if (collision->getCollisionPrimitiveType() == OgreNewt::TreeCollisionPrimitiveType)
      return FALSE;

   OgreNewt::ConvexCollision *col = reinterpret_cast<OgreNewt::ConvexCollision*>(collision);

   Ogre::Vector3 vec, vec2;

   col->calculateInertialMatrix(vec2, vec);

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double CalculateNewtonConvexCollisionVolume(double newton_collision_ptr)
{
   OgreNewt::Collision *collision = ConvertFromGMPointer<OgreNewt::Collision*>(newton_collision_ptr);
   
   if (!collision)
      return FALSE;

   if (collision->getCollisionPrimitiveType() == OgreNewt::TreeCollisionPrimitiveType)
      return FALSE;

   OgreNewt::ConvexCollision *col = reinterpret_cast<OgreNewt::ConvexCollision*>(collision);

   return col->calculateVolume();
}

#endif
