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

#ifndef GMOGRE_PAGED_GEOMETRY_H
#define GMOGRE_PAGED_GEOMETRY_H

#include "GMOgre3D.h"
#include "../PagedGeometry/include/PagedGeometry.h"
#include "../PagedGeometry/include/BatchPage.h"
#include "../PagedGeometry/include/ImpostorPage.h"
#include "../PagedGeometry/include/GrassLoader.h"


GMFN double CreatePagedGeometry(double cam_ptr, double page_size)
{
   Ogre::Camera *cam = NULL;
   
   if (cam_ptr != 0)
      cam = ConvertFromGMPointer<Ogre::Camera*>(cam_ptr);

   Forests::PagedGeometry *pg = new Forests::PagedGeometry(cam, page_size);
   pg->setInfinite();

   return ConvertToGMPointer(pg);
}


GMFN double DestroyPagedGeometry(double pg_ptr)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return FALSE;

   delete pg;

   return TRUE;
}


GMFN double SetPagedGeometryCamera(double pg_ptr, double camera_ptr)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return FALSE;

   Ogre::Camera *cam = ConvertFromGMPointer<Ogre::Camera*>(camera_ptr);

   if (cam == NULL)
      return FALSE;

   pg->setCamera(cam);

   return TRUE;
}


GMFN double SetPagedGeometryPageSize(double pg_ptr, double size)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return FALSE;

   pg->setPageSize(size);

   return TRUE;
}


GMFN double AddPagedGeometryBatchPageLOD(double pg_ptr, double max_range, double transition_length = 0)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return FALSE;

   pg->addDetailLevel<Forests::BatchPage>(max_range, transition_length);

   return TRUE;
}


GMFN double AddPagedGeometryImpostorPageLOD(double pg_ptr, double max_range, double transition_length = 0)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return FALSE;

   pg->addDetailLevel<Forests::ImpostorPage>(max_range, transition_length);

   return TRUE;
}


GMFN double AddPagedGeometryGrassPageLOD(double pg_ptr, double max_range, double transition_length = 0)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return FALSE;

   pg->addDetailLevel<Forests::GrassPage>(max_range, transition_length);

   return TRUE;
}


GMFN double SetPagedGeometryPageLoader(double pg_ptr, double pl_ptr)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return FALSE;

   Forests::PageLoader *pl = ConvertFromGMPointer<Forests::PageLoader*>(pl_ptr);

   if (pl == NULL)
      return FALSE;

   pg->setPageLoader(pl);

   return TRUE;
}


GMFN double UpdatePagedGeometry(double pg_ptr)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return FALSE;

   pg->update();

   return TRUE;
}

#endif
