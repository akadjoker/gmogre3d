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

#ifndef GMOGRE_STATIC_GEOMETRY_H
#define GMOGRE_STATIC_GEOMETRY_H

#include "GMOgre3D.h"


GMFN double CreateStaticGeometry()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::StaticGeometry *static_geo = NULL;
   
   TRY
      static_geo = mSceneMgr->createStaticGeometry(GenerateUniqueName());
   CATCH("CreateStaticGeometry")

   return ConvertToGMPointer(static_geo);
}


GMFN double DestroyStaticGeometry(double static_geo_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   mSceneMgr->destroyStaticGeometry(static_geo);

   return TRUE;
}


GMFN double SetStaticGeometryRegionRenderingDistance(double static_geo_ptr, double distance)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   static_geo->setRenderingDistance((Ogre::Real)distance);

   return TRUE;
}


GMFN double SetStaticGeometryRegionDimensions(double static_geo_ptr, double sizex, double sizez, double sizey)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   static_geo->setRegionDimensions(ConvertFromGMAxis(sizex, sizey, sizez));

   return TRUE;
}


GMFN double SetStaticGeometryOrigin(double static_geo_ptr, double sizex, double sizez, double sizey)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   static_geo->setOrigin(ConvertFromGMAxis(sizex, sizey, sizez));

   return TRUE;
}


GMFN double AddStaticGeometryEntity(double static_geo_ptr, double entity_ptr, double posx, double posz, double posy, double yaw, double pitch, double roll, double scalex, double scalez, double scaley)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   static_geo->addEntity(ent, ConvertFromGMAxis(posx, posy, posz), Euler(Ogre::Degree(ConvertFromGMYaw(yaw)), Ogre::Degree((Ogre::Real)pitch), Ogre::Degree((Ogre::Real)roll)), ConvertFromGMAxis(scalex, scaley, scalez));

   return TRUE;
}


GMFN double AddStaticGeometrySceneNode(double static_geo_ptr, double scene_node_ptr)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);

   if (node == NULL)
      return FALSE;

   static_geo->addSceneNode(node);

   return TRUE;
}


GMFN double BuildStaticGeometry(double static_geo_ptr)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   static_geo->build();

   return TRUE;
}


GMFN double ResetStaticGeometry(double static_geo_ptr)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   static_geo->reset();

   return TRUE;
}


GMFN double EnableStaticGeometryCastShadows(double static_geo_ptr, double enable)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   static_geo->setCastShadows((enable != 0));

   return TRUE;
}


GMFN double SetStaticGeometryVisibilityFlags(double static_geo_ptr, double flags)
{
   Ogre::StaticGeometry *static_geo = ConvertFromGMPointer<Ogre::StaticGeometry*>(static_geo_ptr);

   if (static_geo == NULL)
      return FALSE;

   static_geo->setVisibilityFlags((Ogre::uint)flags);

   return TRUE;
}

#endif
