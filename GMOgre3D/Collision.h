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

#ifndef GMOGRE_COLLISION_H
#define GMOGRE_COLLISION_H

#include "GMOgre3D.h"


GMFN double CollidesWithObject(double fromx, double fromz, double fromy, double tox, double toz, double toy, double collision_radius, double ray_height, double mask = 0xFFFFFFFF)
{
   return mCollisionTools.collidesWithEntity(Ogre::Vector3(fromx, fromy, fromz), Ogre::Vector3(tox, toy, toz), collision_radius, ray_height, mask);
}


GMFN double GetZCollisionDistance(double scene_node_ptr, double check_terrain, double space_width, double mask = 0xFFFFFFFF)
{
   Ogre::SceneNode *scene_node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (scene_node == NULL)
      return 999999;

   return mCollisionTools.calculateYDistance(scene_node, (check_terrain != 0), space_width, mask);
}


GMFN double DistanceToCollisionWithObject(double fromx, double fromz, double fromy, double tox, double toz, double toy, double collision_radius, double ray_height, double mask = 0xFFFFFFFF)
{
   Ogre::Vector3 fromPointAdj(fromx, fromy + ray_height, fromz);
	Ogre::Vector3 toPointAdj(tox, toy + ray_height, toz);
	Ogre::Vector3 normal = toPointAdj - fromPointAdj;
	float distToDest = normal.normalise();

	Ogre::Vector3 myResult(0, 0, 0);
	Ogre::MovableObject* myObject = NULL;
	float distToColl = 0.0f;

	if (mCollisionTools.raycastFromPoint(fromPointAdj, normal, myResult, myObject, distToColl, mask))
	{
		distToColl -= collision_radius;
		return (distToColl <= distToDest);
	}
	else
	{
		return false;
	}
}

#endif
