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

#ifndef GMOGRE_BILLBOARD_CHAIN_H
#define GMOGRE_BILLBOARD_CHAIN_H

#include "GMOgre3D.h"

static Ogre::String bb_chain_entity_bone_name;
static double bb_chain_id;
static double bb_chain_entity_id;


GMFN double CreateBillboardChain()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::BillboardChain *bb_chain = NULL;
   
   TRY
      bb_chain = mSceneMgr->createBillboardChain(GenerateUniqueName());
   CATCH("CreateBillboardChain")

   return ConvertToGMPointer(bb_chain);
}


GMFN double DestroyBillboardChain(double bb_chain_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   mSceneMgr->destroyBillboardChain(bb_chain);

   return TRUE;
}


GMFN double SetBillboardChainMaxChainElements(double bb_chain_ptr, double max)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setMaxChainElements((size_t)max);

   return TRUE;
}


GMFN double SetBillboardChainNumberOfChains(double bb_chain_ptr, double num)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setNumberOfChains((size_t)num);

   return TRUE;
}


GMFN double EnableBillboardChainTextureCoords(double bb_chain_ptr, double enable)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   bb_chain->setUseTextureCoords((enable != 0));

   return TRUE;
}


GMFN double SetBillboardChainTextureCoordDirection(double bb_chain_ptr, double type)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setTextureCoordDirection(static_cast<Ogre::BillboardChain::TexCoordDirection>((int)type));

   return TRUE;
}


GMFN double SetBillboardChainOtherTextureCoordRange(double bb_chain_ptr, double start, double end)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   bb_chain->setOtherTextureCoordRange((Ogre::Real)start, (Ogre::Real)end);

   return TRUE;
}


GMFN double EnableBillboardChainVertexColours(double bb_chain_ptr, double enable)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   bb_chain->setUseVertexColours((enable != 0));

   return TRUE;
}


GMFN double EnableBillboardChainDynamic(double bb_chain_ptr, double enable)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   bb_chain->setDynamic((enable != 0));

   return TRUE;
}


GMFN double AddBillboardChainChainElement(double bb_chain_ptr, double index, double x, double z, double y, double width, double tex_coord, double clr, double alpha)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   Ogre::BillboardChain::Element element;
   element.position = ConvertFromGMAxis(x, y, z);
   element.width = (Ogre::Real)width;
   element.texCoord = (Ogre::Real)tex_coord;
   element.colour = Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), (float)alpha);
   
   bb_chain->addChainElement((size_t)index, element);

   return TRUE;
}


GMFN double RemoveBillboardChainChainElement(double bb_chain_ptr, double index)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->removeChainElement((size_t)index);

   return TRUE;
}


GMFN double UpdateBillboardChainChainElement(double bb_chain_ptr, double index, double elementindex, double x, double z, double y, double width, double tex_coord, double clr, double alpha)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   Ogre::BillboardChain::Element element;
   element.position = ConvertFromGMAxis(x, y, z);
   element.width = (Ogre::Real)width;
   element.texCoord = (Ogre::Real)tex_coord;
   element.colour = Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), (float)alpha);
   
   bb_chain->updateChainElement((size_t)index, (size_t)elementindex, element);

   return TRUE;
}


GMFN double ClearBillboardChainChain(double bb_chain_ptr, double index)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->clearChain((size_t)index);

   return TRUE;
}


GMFN double ClearBillboardChainAllChains(double bb_chain_ptr)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->clearAllChains();

   return TRUE;
}


GMFN double SetBillboardChainMaterial(double bb_chain_ptr, char *mat_name)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setMaterialName(mat_name);

   return TRUE;
}


GMFN double AttachBillboardChainToSceneNode(double bb_chain_ptr, double scene_node_ptr)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->attachObject(bb_chain);

   return TRUE;
}


GMFN double DetachBillboardChainFromSceneNode(double bb_chain_ptr, double scene_node_ptr)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->detachObject(bb_chain);

   return TRUE;
}


GMFN double AttachBillboardChainToEntityBone1(double bb_chain_ptr, double entity_ptr, char *bone_name)
{
   bb_chain_id = bb_chain_ptr;
   bb_chain_entity_id = entity_ptr;
   bb_chain_entity_bone_name = bone_name;

   return TRUE;
}


GMFN double AttachBillboardChainToEntityBone2(double x, double y, double z, double yaw, double pitch, double roll)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_id);

   if (bb_chain == NULL)
      return FALSE;

   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(bb_chain_entity_id);

   if (entity == NULL)
      return FALSE;

   entity->attachObjectToBone(bb_chain_entity_bone_name, bb_chain, Euler(Ogre::Degree(ConvertFromGMYaw(yaw + 90)), Ogre::Degree(ConvertFromGMPitch(pitch)), Ogre::Degree(ConvertFromGMRoll(roll))), ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double DetachBillboardChainFromEntityBone(double bb_chain_ptr, double entity_ptr)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (entity == NULL)
      return FALSE;
   
   entity->detachObjectFromBone(bb_chain->getName());

   return TRUE;
}


GMFN double SetBillboardChainRenderQueueGroup(double bb_chain_ptr, double type)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setRenderQueueGroup(static_cast<Ogre::RenderQueueGroupID>((int)type));

   return TRUE;
}


GMFN double SetBillboardChainQueryFlags(double bb_chain_ptr, double flags)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetBillboardChainLightFlags(double bb_chain_ptr, double flags)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setLightMask((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetBillboardChainVisibilityFlags(double bb_chain_ptr, double flags)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setVisibilityFlags((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetBillboardChainUserData(double bb_chain_ptr, char *key, double data)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   if (key == NULL)
      ((Ogre::MovableObject*)bb_chain)->getUserObjectBindings().setUserAny(Ogre::Any(data));
   else
      ((Ogre::MovableObject*)bb_chain)->getUserObjectBindings().setUserAny(key, Ogre::Any(data));

   return TRUE;
}


GMFN double GetBillboardChainUserData(double bb_chain_ptr, char *key)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   if (key == NULL)
      return Ogre::any_cast<double>(((Ogre::MovableObject*)bb_chain)->getUserObjectBindings().getUserAny());
   else
      return Ogre::any_cast<double>(((Ogre::MovableObject*)bb_chain)->getUserObjectBindings().getUserAny(key));
}

#endif
