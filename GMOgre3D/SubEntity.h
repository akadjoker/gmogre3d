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

#ifndef GMOGRE_SUB_ENTITY_H
#define GMOGRE_SUB_ENTITY_H

#include "GMOgre3D.h"
#include "Material.h"


GMFN double SetSubEntityMaterial(double sub_entity_ptr, char *mat_name)
{
   Ogre::SubEntity *sub_ent = ConvertFromGMPointer<Ogre::SubEntity*>(sub_entity_ptr);

   if (sub_ent == NULL)
      return FALSE;

   sub_ent->setMaterialName(mat_name);

   return TRUE;
}


GMFN double ShowSubEntity(double sub_entity_ptr)
{
   Ogre::SubEntity *sub_ent = ConvertFromGMPointer<Ogre::SubEntity*>(sub_entity_ptr);

   if (sub_ent == NULL)
      return FALSE;

   sub_ent->setVisible(true);

   return TRUE;
}


GMFN double HideSubEntity(double sub_entity_ptr)
{
   Ogre::SubEntity *sub_ent = ConvertFromGMPointer<Ogre::SubEntity*>(sub_entity_ptr);

   if (sub_ent == NULL)
      return FALSE;

   sub_ent->setVisible(false);

   return TRUE;
}


GMFN double SetSubEntityCustomParameter(double sub_entity_ptr, double index, double p1, double p2, double p3, double p4)
{
   Ogre::SubEntity *sub_ent = ConvertFromGMPointer<Ogre::SubEntity*>(sub_entity_ptr);

   if (sub_ent == NULL)
      return FALSE;

   sub_ent->setCustomParameter((size_t)index, Ogre::Vector4(p1, p2, p3, p4));

   return TRUE;
}


#endif
