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

#ifndef GMOGRE_BILLBOARD_SET_H
#define GMOGRE_BILLBOARD_SET_H

#include "GMOgre3D.h"

static Ogre::String bb_set_entity_bone_name;
static double bb_set_id;
static double bb_set_entity_id;


GMFN double CreateBillboardSet(double size = 20.0)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::BillboardSet *bb_set = NULL;
   
   TRY
      bb_set = mSceneMgr->createBillboardSet(GenerateUniqueName(), size);
   CATCH("CreateBillboardSet")

   return ConvertToGMPointer(bb_set);
}


GMFN double DestroyBillboardSet(double bb_set_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;

   mSceneMgr->destroyBillboardSet(bb_set);

   return TRUE;
}


GMFN double SetBillboardSetPoolSize(double bb_set_ptr, double size)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   bb_set->setPoolSize(size);

   return TRUE;
}


GMFN double GetBillboardSetPoolSize(double bb_set_ptr)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   return bb_set->getPoolSize();
}


GMFN double EnableBillboardSetPointRendering(double bb_set_ptr, double enable)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   bb_set->setPointRenderingEnabled((enable != 0));

   return TRUE;
}


GMFN double SetBillboardSetDefaultDimensions(double bb_set_ptr, double width, double height)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   bb_set->setDefaultDimensions(width, height);

   return TRUE;
}


GMFN double GetBillboardSetDefaultWidth(double bb_set_ptr)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return 0;
   
   return bb_set->getDefaultWidth();
}


GMFN double GetBillboardSetDefaultHeight(double bb_set_ptr)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return 0;
   
   return bb_set->getDefaultHeight();
}


GMFN double SetBillboardSetBillboardOrigin(double bb_set_ptr, double type)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   bb_set->setBillboardOrigin(static_cast<Ogre::BillboardOrigin>((int)type));

   return TRUE;
}


GMFN double SetBillboardSetMaterial(double bb_set_ptr, char *mat_name)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   bb_set->setMaterialName(mat_name);

   return TRUE;
}


GMFN double CreateBillboardSetBillboard(double bb_set_ptr, double x, double z, double y, double color, double alpha)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   Ogre::Billboard *bb = bb_set->createBillboard(ConvertFromGMAxis(x, y, z), Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));

   return ConvertToGMPointer(bb);
}


GMFN double RemoveBillboardSetBillboard(double bb_set_ptr, double bb_ptr)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   Ogre::Billboard *bb = ConvertFromGMPointer<Ogre::Billboard *>(bb_ptr);

   if (bb == NULL)
      return FALSE;
   
   bb_set->removeBillboard(bb);

   return TRUE;
}


GMFN double GetNumBillboardSetBillboards(double bb_set_ptr)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   bb_set->getNumBillboards();

   return TRUE;
}


GMFN double AttachBillboardSetToSceneNode(double bb_set_ptr, double scene_node_ptr)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet*>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->attachObject(bb_set);

   return TRUE;
}


GMFN double DetachBillboardSetFromSceneNode(double bb_set_ptr, double scene_node_ptr)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet*>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->detachObject(bb_set);

   return TRUE;
}


GMFN double AttachBillboardSetToEntityBone1(double bb_set_ptr, double entity_ptr, char *bone_name)
{
   bb_set_id = bb_set_ptr;
   bb_set_entity_id = entity_ptr;
   bb_set_entity_bone_name = bone_name;

   return TRUE;
}


GMFN double AttachBillboardSetToEntityBone2(double x, double y, double z, double yaw, double pitch, double roll)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet*>(bb_set_id);

   if (bb_set == NULL)
      return FALSE;

   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(bb_set_entity_id);

   if (entity == NULL)
      return FALSE;

   entity->attachObjectToBone(bb_set_entity_bone_name, bb_set, Euler(Ogre::Degree(ConvertFromGMYaw(yaw + 90)), Ogre::Degree(pitch), Ogre::Degree(roll)), ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double DetachBillboardSetFromEntityBone(double bb_set_ptr, double entity_ptr)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet*>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (entity == NULL)
      return FALSE;
   
   entity->detachObjectFromBone(bb_set->getName());

   return TRUE;
}


GMFN double SetBillboardSetRenderQueueGroup(double bb_set_ptr, double type)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet*>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;

   bb_set->setRenderQueueGroup(static_cast<Ogre::RenderQueueGroupID>((int)type));

   return TRUE;
}


GMFN double SetBillboardSetQueryFlags(double bb_set_ptr, double flags)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet*>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;

   bb_set->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}

#endif
