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

#ifndef GMOGRE_NEWTON_MATERIAL
#define GMOGRE_NEWTON_MATERIAL

#include "OgreNewt_MaterialID.h"


GMFN double CreateNewtonMaterial(double newton_world_ptr)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewt::World*>(newton_world_ptr);

   if (!world)
      return 0;

   OgreNewt::MaterialID *mat;

   TRY
      mat = new OgreNewt::MaterialID(world);
   CATCH("CreateNewtonMaterial")

   return ConvertToGMPointer(mat);
}


GMFN double DestroyNewtonMaterial(double material_ptr)
{
   OgreNewt::MaterialID *mat = ConvertFromGMPointer<OgreNewt::MaterialID*>(material_ptr);

   if (!mat)
      return FALSE;

   delete mat;

   return TRUE;
}


GMFN double GetNewtonMaterialID(double material_ptr)
{
   OgreNewt::MaterialID *mat = ConvertFromGMPointer<OgreNewt::MaterialID*>(material_ptr);

   if (!mat)
      return 0;

   return mat->getID();
}

#endif
