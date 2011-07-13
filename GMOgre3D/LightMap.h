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

#ifndef GMOGRE_LIGHT_MAP_H
#define GMOGRE_LIGHT_MAP_H

#include "GMOgre3D.h"
#include "OgreLightMap.h"


GMFN double CreateLightmapFromEntity(double ent_ptr, double pixels_per_unit, double texture_size, double use_debug)
{
   Ogre::Entity *ent = ConvertFromGMPointer<Ogre::Entity*>(ent_ptr);

   if (ent == NULL)
      return FALSE;

   CEntityLightMap* lightmap = NULL;

   TRY
      lightmap = OGRE_NEW CEntityLightMap(ent, (Ogre::Real)pixels_per_unit, (int)texture_size, -1, (bool)use_debug);
   CATCH("CreateLightMapFromEntity")

   return ConvertToGMPointer(lightmap);

   return TRUE;
}


GMFN double DestroyLightmap(double lightmap_ptr)
{
   CEntityLightMap *lightmap = ConvertFromGMPointer<CEntityLightMap*>(lightmap_ptr);

   if (lightmap == NULL)
      return FALSE;

   TRY
      OGRE_DELETE lightmap;
   CATCH("DestroyLightMap")

   return TRUE;
}


GMFN double SetLightmapBlur(double lightmap_ptr, double blur)
{
   CEntityLightMap *lightmap = ConvertFromGMPointer<CEntityLightMap*>(lightmap_ptr);

   if (lightmap == NULL)
      return FALSE;

   lightmap->SetBlur(blur);

   return TRUE;
}


GMFN double SetLightMapLightSource(double lightmap_ptr, double posx, double posz, double posy, double ambient_level)
{
   CEntityLightMap *lightmap = ConvertFromGMPointer<CEntityLightMap*>(lightmap_ptr);

   if (lightmap == NULL)
      return FALSE;

   lightmap->SetLightSource(ConvertFromGMAxis(posx, posy, posz), ambient_level);

   return TRUE;
}


GMFN double SetLightMapIntensityCallback(double lightmap_ptr, double light_intense_callback)
{
   CEntityLightMap *lightmap = ConvertFromGMPointer<CEntityLightMap*>(lightmap_ptr);

   if (lightmap == NULL)
      return FALSE;

   lightmap->SetIntensityCallback(light_intense_callback);

   return TRUE;
}


GMFN double CalculateLightmap(double lightmap_ptr)
{
   CEntityLightMap *lightmap = ConvertFromGMPointer<CEntityLightMap*>(lightmap_ptr);

   if (lightmap == NULL)
      return FALSE;

   lightmap->CreateLightmap();

   return TRUE;
}


GMFN double SaveLightmapTextures(double lightmap_ptr, char *filename)
{
   CEntityLightMap *lightmap = ConvertFromGMPointer<CEntityLightMap*>(lightmap_ptr);

   if (lightmap == NULL)
      return FALSE;

   lightmap->SaveLightmapTextures(filename);

   return TRUE;
}

#endif
