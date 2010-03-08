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

#ifndef GMOGRE_RIBBON_TRAIL_H
#define GMOGRE_RIBBON_TRAIL_H

#include "GMOgre3D.h"

GMFN double CreateRibbonTrail()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::RibbonTrail *ribbon_trail = NULL;
   
   TRY
      ribbon_trail = mSceneMgr->createRibbonTrail(GenerateUniqueName());

      if (ribbon_trail == NULL)
         return FALSE;
   CATCH("CreateRibbonTrail")

   return ConvertToGMPointer(ribbon_trail);
}


GMFN double DestroyRibbonTrail(double ribbon_trail_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   mSceneMgr->destroyRibbonTrail(ribbon_trail);

   return TRUE;
}


GMFN double AddRibbonTrailNode(double ribbon_trail_ptr, double node_ptr)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   Ogre::Node *node = ConvertFromGMPointer<Ogre::Node*>(node_ptr);

   if (node == NULL)
      return FALSE;

   ribbon_trail->addNode(node);

   return TRUE;
}


GMFN double RemoveRibbonTrailNode(double ribbon_trail_ptr, double node_ptr)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   Ogre::Node *node = ConvertFromGMPointer<Ogre::Node*>(node_ptr);

   if (node == NULL)
      return FALSE;

   ribbon_trail->removeNode(node);

   return TRUE;
}


GMFN double GetRibbonTrailChainIndexForNode(double ribbon_trail_ptr, double node_ptr)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return 0;

   Ogre::Node *node = ConvertFromGMPointer<Ogre::Node*>(node_ptr);

   if (node == NULL)
      return 0;

   return ribbon_trail->getChainIndexForNode(node);
}


GMFN double SetRibbonTrailTrailLength(double ribbon_trail_ptr, double len)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setTrailLength(len);

   return TRUE;
}


GMFN double SetRibbonTrailInitialColor(double ribbon_trail_ptr, double chain_index, double color, double alpha)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setInitialColour(chain_index, Ogre::ColourValue(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha));

   return TRUE;
}


GMFN double SetRibbonTrailColorChange(double ribbon_trail_ptr, double chain_index, double color_per_second, double alpha_per_second)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setColourChange(chain_index, Ogre::ColourValue(GetRedFromGMColor(color_per_second), GetGreenFromGMColor(color_per_second), GetBlueFromGMColor(color_per_second), alpha_per_second));

   return TRUE;
}


GMFN double SetRibbonTrailInitialWidth(double ribbon_trail_ptr, double chain_index, double width)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setInitialWidth(chain_index, width);

   return TRUE;
}


GMFN double SetRibbonTrailWidthChange(double ribbon_trail_ptr, double chain_index, double width_delta_per_second)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setWidthChange(chain_index, width_delta_per_second);

   return TRUE;
}


GMFN double GetRibbonTrailMaxChainElements(double ribbon_trail_ptr)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return 0;

   return ribbon_trail->getMaxChainElements();
}


GMFN double EnableRibbonTrailUseTextureCoords(double ribbon_trail_ptr, double enable)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setUseTextureCoords((enable != 0));

   return TRUE;
}


GMFN double SetRibbonTrailTextureCoordDirection(double ribbon_trail_ptr, double type)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setTextureCoordDirection(static_cast<Ogre::RibbonTrail::TexCoordDirection>((int)type));

   return TRUE;
}


GMFN double SetRibbonTrailOtherTextureCoordRange(double ribbon_trail_ptr, double start, double end)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setOtherTextureCoordRange(start, end);

   return TRUE;
}


GMFN double EnableRibbonTrailUseVertexColours(double ribbon_trail_ptr, double enable)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setUseVertexColours((enable != 0));

   return TRUE;
}


GMFN double EnableRibbonTrailDynamic(double ribbon_trail_ptr, double enable)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setDynamic((enable != 0));

   return TRUE;
}


GMFN double AddRibbonTrailChainElement(double ribbon_trail_ptr, double chain_index, double x, double z, double y, double width, double tex_coord, double clr, double alpha)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;
   
   Ogre::BillboardChain::Element element;
   element.position = ConvertFromGMAxis(x, y, z);
   element.width = width;
   element.texCoord = tex_coord;
   element.colour = Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), alpha);
   
   ribbon_trail->addChainElement(chain_index, element);

   return TRUE;
}


GMFN double RemoveRibbonTrailChainElement(double ribbon_trail_ptr, double chain_index)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->removeChainElement(chain_index);

   return TRUE;
}


GMFN double UpdateRibbonTrailChainElement(double ribbon_trail_ptr, double chain_index, double element_index, double x, double z, double y, double width, double tex_coord, double clr, double alpha)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;
   
   Ogre::BillboardChain::Element element;
   element.position = ConvertFromGMAxis(x, y, z);
   element.width = width;
   element.texCoord = tex_coord;
   element.colour = Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), alpha);
  
   ribbon_trail->updateChainElement(chain_index, element_index, element);

   return TRUE;
}


GMFN double GetRibbonTrailNumChainElements(double ribbon_trail_ptr, double chain_index)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return 0;

   return ribbon_trail->getNumChainElements(chain_index);
}


GMFN double SetRibbonTrailMaxChainElements(double ribbon_trail_ptr, double max_elements)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setMaxChainElements(max_elements);

   return TRUE;
}


GMFN double SetRibbonTrailNumberOfChains(double ribbon_trail_ptr, double num_chains)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setNumberOfChains(num_chains);

   return TRUE;
}


GMFN double ClearRibbonTrailChain(double ribbon_trail_ptr, double chain_index)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->clearChain(chain_index);

   return TRUE;
}


GMFN double ClearRibbonTrailAllChains(double ribbon_trail_ptr)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->clearAllChains();

   return TRUE;
}


GMFN double SetRibbonTrailMaterial(double ribbon_trail_ptr, char *name)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;

   ribbon_trail->setMaterialName(name);

   return TRUE;
}


GMFN double AttachRibbonTrailToSceneNode(double ribbon_trail_ptr, double scene_node_ptr)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->attachObject(ribbon_trail);

   return TRUE;
}


GMFN double DetachRibbonTrailFromSceneNode(double ribbon_trail_ptr, double scene_node_ptr)
{
   Ogre::RibbonTrail *ribbon_trail = ConvertFromGMPointer<Ogre::RibbonTrail*>(ribbon_trail_ptr);

   if (ribbon_trail == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->detachObject(ribbon_trail);

   return TRUE;
}

#endif
