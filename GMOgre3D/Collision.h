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

#ifndef GMOGRE_COLLISION_H
#define GMOGRE_COLLISION_H

#include "GMOgre3D.h"


   class MyRaySceneQueryListener: public Ogre::RaySceneQueryListener
	{
	public:
		inline bool queryResult(Ogre::SceneQuery::WorldFragment *fragment, Ogre::Real distance)
		{
			resultDistance = fragment->singleIntersection.y;
			return false;
		}
		inline bool queryResult(Ogre::MovableObject *obj, Ogre::Real distance)
		{
			resultDistance = distance;
			return false;
		}

		float resultDistance;
	};


GMFN double FindEntityFromCameraPosition(double camera_ptr, double x, double y, double mask = 0xFFFFFFFF)
{
   MOC::CollisionTools *ct = mSceneCollisionMap[mSceneMgr];

   if (ct == NULL)
      return 0;

   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return 0;

   Ogre::Entity *ent = NULL;
   Ogre::Vector3 result = Ogre::Vector3::ZERO;
	float distToColl;

   if (ct->raycastFromCamera(mRenderWindow, cam, Ogre::Vector2(x, y), result, ent, distToColl, mask))
	{
      SetGMVectorGlobals(result);
		return ConvertToGMPointer(ent);
	}

   return 0;
}


GMFN double FindTerrainFromCameraPosition(double camera_ptr, double x, double y)
{
   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Real realitive_x = x / cam->getViewport()->getActualWidth();
   Ogre::Real realitive_y = y / cam->getViewport()->getActualHeight();

   static Ogre::Ray ray;
   cam->getCameraToViewportRay(realitive_x, realitive_y, &ray);

   static Ogre::RaySceneQuery *ray_query = NULL;

   if (ray_query == NULL)
      ray_query = mSceneMgr->createRayQuery(ray);

   ray_query->setSortByDistance(true);
   ray_query->setRay(ray);
   
   Ogre::RaySceneQueryResult& qryResult = ray_query->execute();

   Ogre::RaySceneQueryResult::iterator i = qryResult.begin();
   while (i != qryResult.end())
   {
      if (i->worldFragment)
      {
         Ogre::Vector3 result = i->worldFragment->singleIntersection;
         SetGMVectorGlobals(result);
		   return TRUE;
      }

      i++;
   }

   return FALSE;
}


GMFN double CollidesWithObject(double fromx, double fromz, double fromy, double tox, double toz, double toy, double collision_radius, double ray_height, double mask = 0xFFFFFFFF)
{
   MOC::CollisionTools *ct = mSceneCollisionMap[mSceneMgr];

   if (ct == NULL)
      return FALSE;

   return ct->collidesWithEntity(ConvertFromGMAxis(fromx, fromy, fromz), ConvertFromGMAxis(tox, toy, toz), collision_radius, ray_height, mask);
}


GMFN double GetZCollisionDistance(double scene_node_ptr, double check_terrain, double space_width, double mask = 0xFFFFFFFF)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return 999999;

   MOC::CollisionTools *ct = mSceneCollisionMap[mSceneMgr];

   if (ct == NULL)
      return 999999;

   return ct->calculateYDistance(scene_node, (check_terrain != 0), space_width, mask);
}


GMFN double DistanceToCollisionWithObject(double fromx, double fromz, double fromy, double tox, double toz, double toy, double collision_radius, double ray_height, double mask = 0xFFFFFFFF)
{
   Ogre::Vector3 fromPointAdj = ConvertFromGMAxis(fromx, fromy, fromz);
   fromPointAdj.y += ray_height;

   Ogre::Vector3 toPointAdj = ConvertFromGMAxis(tox, toy, toz);
   toPointAdj.y += ray_height;

	Ogre::Vector3 normal = toPointAdj - fromPointAdj;
	float distToDest = normal.normalise();

	Ogre::Vector3 myResult(0, 0, 0);
	Ogre::MovableObject* myObject = NULL;
	float distToColl = 0.0f;

   MOC::CollisionTools *ct = mSceneCollisionMap[mSceneMgr];

   if (ct == NULL)
      return 999999;

	if (ct->raycastFromPoint(fromPointAdj, normal, myResult, myObject, distToColl, mask))
	{
		distToColl -= collision_radius;
		return (distToColl <= distToDest);
	}
	else
	{
		return 999999;
	}
}


GMFN double GetTerrainHeight(double x, double z)
{
   MOC::CollisionTools *ct = mSceneCollisionMap[mSceneMgr];

   if (ct == NULL)
      return -999999;

   return ct->getTSMHeightAt(x, z);	
}

#endif
