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

#ifndef GMOGRE_NEWTON_WORLD
#define GMOGRE_NEWTON_WORLD

#include "OgreNewtWorld.h"
#include <map>


GMFN double CreateNewtonWorld()
{
   OgreNewtWorld *world = NULL;

   TRY
      world = new OgreNewtWorld();
   CATCH("CreateNewtonWorld")

   return ConvertToGMPointer(world);
}


GMFN double DestroyNewtonWorld(double newton_world_ptr)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;

   delete newton_world;

   return TRUE;
}


GMFN double EnableNewtonWorldDebugger(double newton_world_ptr, double enable)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;

   GMFrameListener *fl = mSceneListener[mSceneMgr];

   if (fl == NULL)
      return FALSE;

   if (enable != 0)
      newton_world->getDebugger().init(mSceneMgr);
   else
      newton_world->getDebugger().deInit();

   fl->DisplayNewtonDebugger(newton_world->getOgreNewtWorld(), (enable != 0));

   return TRUE;
}


GMFN double SetNewtonWorldDebuggerFont(double newton_world_ptr, char *name, double size)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;

   newton_world->getDebugger().setFont(name, size);

   return TRUE;
}


GMFN double DestroyAllNewtonWorldBodies(double newton_world_ptr)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;
   
   newton_world->destroyAllBodies();

   return TRUE;
}


GMFN double SetNewtonWorldSolverModel(double newton_world_ptr, double type)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;
   
   newton_world->setSolverModel((int)type);

   return TRUE;
}


GMFN double SetNewtonWorldFrictionModel(double newton_world_ptr, double type)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;
   
   newton_world->setFrictionModel((int)type);

   return TRUE;
}


GMFN double SetNewtonWorldPlatformArchitecture(double newton_world_ptr, double type)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;
   
   newton_world->setFrictionModel((int)type);

   return TRUE;
}


GMFN double SetNewtonWorldThreadCount(double newton_world_ptr, double threads)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;
   
   newton_world->setThreadCount((int)threads);

   return TRUE;
}


GMFN double InvalidateNewtonWorldCache(double newton_world_ptr)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;

   newton_world->invalidateCache();

   return TRUE;
}


GMFN double SetNewtonWorldSize(double newton_world_ptr, double minx, double minz, double miny, double maxx, double maxz, double maxy)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;
   
   newton_world->setWorldSize(Ogre::Vector3(minx, miny, minz), Ogre::Vector3(maxx, maxy, maxz));

   return TRUE;
}


GMFN double GetNewtonWorldDefaultMaterial(double newton_world_ptr)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;

   return ConvertToGMPointer(newton_world->getDefaultMaterialID());
}


GMFN double SetNewtonWorldGravity(double newton_world_ptr, double x, double z, double y)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;

   newton_world->setWorldGravity(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double SetNewtonWorldLeaveWorldCallback(double newton_world_ptr, double func)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;

   newton_world->setGMLeaveWorldFunc(func);

   return TRUE;
}


GMFN double UpdateNewtonWorld(double newton_world_ptr, double seconds)
{
   OgreNewtWorld *newton_world = ConvertFromGMPointer<OgreNewtWorld*>(newton_world_ptr);

   if (!newton_world)
      return FALSE;

   newton_world->update(seconds);

   return TRUE;
}

#endif
