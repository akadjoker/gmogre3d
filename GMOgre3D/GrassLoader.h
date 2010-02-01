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

#ifndef GMOGRE_GRASS_LOADER_H
#define GMOGRE_GRASS_LOADER_H

#include "GMOgre3D.h"
#include "../PagedGeometry/include/GrassLoader.h"


GMFN double CreateGrassLoader(double pg_ptr)
{
   Forests::PagedGeometry *pg = ConvertFromGMPointer<Forests::PagedGeometry*>(pg_ptr);

   if (pg == NULL)
      return 0;

   Forests::GrassLoader *gl = new Forests::GrassLoader(pg);

   gl->setHeightFunction(CalcTerrainHeight);

   return ConvertToGMPointer(gl);
}


GMFN double DestroyGrassLoader(double gl_ptr)
{
   Forests::GrassLoader *gl = ConvertFromGMPointer<Forests::GrassLoader*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   delete gl;

   return TRUE;
}


GMFN double AddGrassLoaderLayer(double gl_ptr, char *mat_name)
{
   Forests::GrassLoader *gl = ConvertFromGMPointer<Forests::GrassLoader*>(gl_ptr);

   if (gl == NULL)
      return 0;

   Forests::GrassLayer *grass_layer = gl->addLayer(mat_name);

   return ConvertToGMPointer(grass_layer);
}


GMFN double RemoveGrassLoaderLayer(double gl_ptr, double grass_layer_ptr)
{
   Forests::GrassLoader *gl = ConvertFromGMPointer<Forests::GrassLoader*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   Forests::GrassLayer *grass_layer = ConvertFromGMPointer<Forests::GrassLayer*>(grass_layer_ptr);

   if (grass_layer == NULL)
      return FALSE;

   gl->deleteLayer(grass_layer);

   return TRUE;
}


GMFN double SetGrassLoaderWindDirection(double gl_ptr, double x, double z, double y)
{
   Forests::GrassLoader *gl = ConvertFromGMPointer<Forests::GrassLoader*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setWindDirection(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetGrassLoaderDensityFactor(double gl_ptr, double density)
{
   Forests::GrassLoader *gl = ConvertFromGMPointer<Forests::GrassLoader*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setDensityFactor(density);

   return TRUE;
}

#endif
