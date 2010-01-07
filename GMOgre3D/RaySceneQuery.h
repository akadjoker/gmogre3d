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

#ifndef GMOGRE_RAY_SCENE_QUERY_H
#define GMOGRE_RAY_SCENE_QUERY_H

#include "GMOgre3D.h"


GMFN double CreateRaySceneQuery()
{
   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->createRayQuery(Ogre::Ray());

   return TRUE;
}


GMFN double DestroyRaySceneQuery(double ray_scn_qry_ptr)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return FALSE;

   if (mSceneMgr == NULL)
      return FALSE;

   mSceneMgr->destroyQuery(ray_scn_qry);

   return TRUE;
}


GMFN double SetRaySceneQueryRay(double ray_scn_qry_ptr, double ray_ptr)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return FALSE;

   Ogre::Ray *ray = ConvertFromGMPointer<Ogre::Ray*>(ray_ptr);

   if (ray == NULL)
      return FALSE;

   ray_scn_qry->setRay(*ray);

   return TRUE;
}


GMFN double EnableSortRaySceneQueryByDistance(double ray_scn_qry_ptr, double enable)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return FALSE;

   ray_scn_qry->setSortByDistance((enable != 0));

   return TRUE;
}


GMFN double SetRaySceneQueryMask(double ray_scn_qry_ptr, double mask)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return FALSE;

   ray_scn_qry->setQueryMask((Ogre::uint)mask);

   // Currently we only support single intersection for world geometry... so we force it
   if ((Ogre::uint)mask == Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK)
      ray_scn_qry->setWorldFragmentType(Ogre::SceneQuery::WFT_SINGLE_INTERSECTION);

   return TRUE;
}

/*
GMFN double SetRaySceneQueryWorldFragmentType(double ray_scn_qry_ptr, double mask)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return FALSE;

   ray_scn_qry->setWorldFragmentType(static_cast<Ogre::SceneQuery::WorldFragmentType>((int)mask));

   return TRUE;
}
*/

GMFN double ExecuteRaySceneQuery(double ray_scn_qry_ptr)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return FALSE;

   ray_scn_qry->execute();

   return TRUE;
}


GMFN double GetNumRaySceneQueryResults(double ray_scn_qry_ptr)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return 0;

   Ogre::RaySceneQueryResult query_result = ray_scn_qry->getLastResults();

   return query_result.size();
}


GMFN double GetRaySceneQueryResultDistance(double ray_scn_qry_ptr, double index)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return 0;

   Ogre::RaySceneQueryResult query_result = ray_scn_qry->getLastResults();

   return query_result[(int)index].distance;
}


GMFN double GetRaySceneQueryResultObject(double ray_scn_qry_ptr, double index)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return 0;

   Ogre::RaySceneQueryResult query_result = ray_scn_qry->getLastResults();

   return ConvertToGMPointer(query_result[(int)index].movable);
}


GMFN double GetRaySceneQueryResultWorldFragmentIntersectPoint(double ray_scn_qry_ptr, double index)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return FALSE;

   Ogre::RaySceneQueryResult query_result = ray_scn_qry->getLastResults();

   Ogre::SceneQuery::WorldFragment *world_frag = query_result[(int)index].worldFragment;

   if (world_frag == NULL)
      return FALSE;

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = world_frag->singleIntersection.x;
      *mVectorY = world_frag->singleIntersection.z;
      *mVectorZ = world_frag->singleIntersection.y;
   }

   return TRUE;
}


GMFN double ClearRaySceneQueryResults(double ray_scn_qry_ptr)
{
   Ogre::RaySceneQuery *ray_scn_qry = ConvertFromGMPointer<Ogre::RaySceneQuery*>(ray_scn_qry_ptr);

   if (ray_scn_qry == NULL)
      return FALSE;

   ray_scn_qry->clearResults();

   return TRUE;
}

#endif
