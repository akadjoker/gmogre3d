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

#ifndef GMOGRE_BILLBOARD_SET_H
#define GMOGRE_BILLBOARD_SET_H

#include "GMOgre3D.h"


GMFN double CreateBillboardSet(double size = 20.0)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::BillboardSet *bb_set = mSceneMgr->createBillboardSet(GenerateUniqueName(), size);

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


GMFN double SetBillboardSetMaterial(double bb_set_ptr, char *mat_name)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet *>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;
   
   bb_set->setMaterialName(mat_name);

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


GMFN double SetBillboardSetQueryFlags(double bb_set_ptr, double flags)
{
   Ogre::BillboardSet *bb_set = ConvertFromGMPointer<Ogre::BillboardSet*>(bb_set_ptr);

   if (bb_set == NULL)
      return FALSE;

   bb_set->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}

#endif
