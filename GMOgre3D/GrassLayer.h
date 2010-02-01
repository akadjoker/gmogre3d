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

#ifndef GMOGRE_GRASS_LAYER_H
#define GMOGRE_GRASS_LAYER_H

#include "GMOgre3D.h"
#include "../PagedGeometry/include/GrassLoader.h"


GMFN double SetGrassLayerMinSize(double gl_ptr, double width, double height)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setMinimumSize(width, height);

   return TRUE;
}


GMFN double SetGrassLayerMaxSize(double gl_ptr, double width, double height)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setMaximumSize(width, height);

   return TRUE;
}



GMFN double SetGrassLayerDensity(double gl_ptr, double density)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setDensity(density);

   return TRUE;
}


GMFN double SetGrassLayerHeightRange(double gl_ptr, double min, double max)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setHeightRange(min, max);

   return TRUE;
}


GMFN double EnableGrassLayerAnimation(double gl_ptr, double enable)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setAnimationEnabled((enable != 0));

   return TRUE;
}


GMFN double SetGrassLayerSwayLength(double gl_ptr, double mag)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setSwayLength(mag);

   return TRUE;
}


GMFN double SetGrassLayerSwaySpeed(double gl_ptr, double speed)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setSwaySpeed(speed);

   return TRUE;
}


GMFN double SetGrassLayerSwayDistribution(double gl_ptr, double freq)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setSwayDistribution(freq);

   return TRUE;
}


GMFN double SetGrassLayerFadeTechnique(double gl_ptr, double type)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setFadeTechnique(static_cast<Forests::FadeTechnique>((int)type));

   return TRUE;
}


GMFN double SetGrassLayerDensityMap(double gl_ptr, char *map_file)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setDensityMap(map_file);

   return TRUE;
}


GMFN double SetGrassLayerColorMap(double gl_ptr, char *map_file)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setColorMap(map_file);

   return TRUE;
}


GMFN double SetGrassLayerMapBounds(double gl_ptr, double left, double top, double right, double bottom)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setMapBounds(Forests::TBounds(left, top, right, bottom));

   return TRUE;
}


GMFN double SetGrassLayerRenderTechnique(double gl_ptr, double type, double fade_base)
{
   Forests::GrassLayer *gl = ConvertFromGMPointer<Forests::GrassLayer*>(gl_ptr);

   if (gl == NULL)
      return FALSE;

   gl->setRenderTechnique(static_cast<Forests::GrassTechnique>((int)type), (fade_base != 0));

   return TRUE;
}

#endif
