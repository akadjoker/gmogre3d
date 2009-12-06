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

#ifndef GMOGRE_TREE_LOADER_2D_H
#define GMOGRE_TREE_LOADER_2D_H

#include "GMOgre3D.h"
#include "../PagedGeometry/include/TreeLoader2D.h"


GMFN double CreateTreeLoader2D(double pg_ptr, double top, double left, double bottom, double right)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return 0;

   Forests::TreeLoader2D *tl = new Forests::TreeLoader2D(pg, Forests::TBounds(left, top, right, bottom));

   tl->setHeightFunction(CalcTerrainHeight);

   return ConvertToGMPointer(tl);
}


GMFN double AddTreeLoader2DTree(double tl_ptr, double entity_ptr, double x, double z, double yaw, double scale)
{
   Forests::TreeLoader2D *tl = ConvertFromGMPointer<Forests::TreeLoader2D*>(tl_ptr);

   if (tl == NULL)
      return FALSE;

   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (ent == NULL)
      return FALSE;

   tl->addTree(ent, Ogre::Vector3(x, 0, z), Ogre::Degree(yaw), scale);

   return TRUE;
}


GMFN double RemoveTreeLoader2DTrees(double tl_ptr, double x, double z, double y, double radius)
{
   Forests::TreeLoader2D *tl = ConvertFromGMPointer<Forests::TreeLoader2D*>(tl_ptr);

   if (tl == NULL)
      return FALSE;

   tl->deleteTrees(Ogre::Vector3(x, y, z), radius);

   return TRUE;
}


GMFN double SetTreeLoader2DMinScale(double tl_ptr, double scale)
{
   Forests::TreeLoader2D *tl = ConvertFromGMPointer<Forests::TreeLoader2D*>(tl_ptr);

   if (tl == NULL)
      return FALSE;

   tl->setMinimumScale(scale);

   return TRUE;
}


GMFN double SetTreeLoader2DMaxScale(double tl_ptr, double scale)
{
   Forests::TreeLoader2D *tl = ConvertFromGMPointer<Forests::TreeLoader2D*>(tl_ptr);

   if (tl == NULL)
      return FALSE;

   tl->setMaximumScale(scale);

   return TRUE;
}


GMFN double SetTreeLoader2DColorMap(double tl_ptr, char *map_file)
{
   Forests::TreeLoader2D *tl = ConvertFromGMPointer<Forests::TreeLoader2D*>(tl_ptr);

   if (tl == NULL)
      return FALSE;

   tl->setColorMap(map_file);

   return TRUE;
}


GMFN double SetTreeLoader2DColorMapFilter(double tl_ptr, double type)
{
   Forests::TreeLoader2D *tl = ConvertFromGMPointer<Forests::TreeLoader2D*>(tl_ptr);

   if (tl == NULL)
      return FALSE;

   tl->setColorMapFilter(static_cast<Forests::MapFilter>((int)type));

   return TRUE;
}

#endif
