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

#ifndef GMOGRE_BILLBOARD_CHAIN_H
#define GMOGRE_BILLBOARD_CHAIN_H

#include "GMOgre3D.h"


GMFN double CreateBillboardChain()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::BillboardChain *bb_chain = mSceneMgr->createBillboardChain(GenerateUniqueName());

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

   bb_chain->setMaxChainElements(max);

   return TRUE;
}


GMFN double SetBillboardChainNumberOfChains(double bb_chain_ptr, double num)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain *>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setNumberOfChains(num);

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
   
   bb_chain->setOtherTextureCoordRange(start, end);

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
   element.position = Ogre::Vector3(x, y, z);
   element.width = width;
   element.texCoord = tex_coord;
   element.colour = Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), alpha);
   
   bb_chain->addChainElement(index, element);

   return TRUE;
}


GMFN double RemoveBillboardChainChainElement(double bb_chain_ptr, double index)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->removeChainElement(index);

   return TRUE;
}


GMFN double UpdateBillboardChainChainElement(double bb_chain_ptr, double index, double elementindex, double x, double z, double y, double width, double tex_coord, double clr, double alpha)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;
   
   Ogre::BillboardChain::Element element;
   element.position = Ogre::Vector3(x, y, z);
   element.width = width;
   element.texCoord = tex_coord;
   element.colour = Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), alpha);
   
   bb_chain->updateChainElement(index, elementindex, element);

   return TRUE;
}


GMFN double ClearBillboardChainChain(double bb_chain_ptr, double index)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->clearChain(index);

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


GMFN double SetBillboardChainQueryFlags(double bb_chain_ptr, double flags)
{
   Ogre::BillboardChain *bb_chain = ConvertFromGMPointer<Ogre::BillboardChain*>(bb_chain_ptr);

   if (bb_chain == NULL)
      return FALSE;

   bb_chain->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}

#endif
