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

#ifndef GMOGRE_RECTANGLE2D_H
#define GMOGRE_RECTANGLE2D_H

#include "GMOgre3D.h"



GMFN double CreateRectangle2D(bool include_tex_coords = true)
{
   Ogre::Rectangle2D *rect2d = NULL;
   
   TRY
      rect2d = OGRE_NEW Ogre::Rectangle2D(include_tex_coords);

      Ogre::SceneNode *parent_node = mSceneMgr->getRootSceneNode()->createChildSceneNode(GenerateUniqueName());
      parent_node->attachObject(rect2d);

      Ogre::AxisAlignedBox aabInf;
      aabInf.setInfinite();
      rect2d->setBoundingBox(aabInf);
      rect2d->setLightMask(0);
   CATCH("CreateRectangle2D")
 
   return ConvertToGMPointer(rect2d);
}


GMFN double DestroyRectangle2D(double rect2d_ptr)
{
   Ogre::Rectangle2D *rect2d = ConvertFromGMPointer<Ogre::Rectangle2D*>(rect2d_ptr);

   if (rect2d == NULL)
      return FALSE;

   Ogre::SceneNode *parent_node = rect2d->getParentSceneNode();
   if (parent_node)
      mSceneMgr->destroySceneNode(parent_node);

   delete rect2d;

   return TRUE;
}


GMFN double SetRectangle2DMaterial(double rect2d_ptr, char *mat_name)
{
   Ogre::Rectangle2D *rect2d = ConvertFromGMPointer<Ogre::Rectangle2D*>(rect2d_ptr);

   if (rect2d == NULL)
      return FALSE;

   rect2d->setMaterial(mat_name);

   return TRUE;
}


GMFN double SetRectangle2DCorners(double rect2d_ptr, double left, double top, double right, double bottom)
{
   Ogre::Rectangle2D *rect2d = ConvertFromGMPointer<Ogre::Rectangle2D*>(rect2d_ptr);

   if (rect2d == NULL)
      return FALSE;

   rect2d->setCorners(left, top, right, bottom, false);

   return TRUE;
}


GMFN double ShowRectangle2D(double rect2d_ptr)
{
   Ogre::Rectangle2D *rect2d = ConvertFromGMPointer<Ogre::Rectangle2D*>(rect2d_ptr);

   if (rect2d == NULL)
      return FALSE;

   rect2d->setVisible(true);

   return TRUE;
}


GMFN double HideRectangle2D(double rect2d_ptr)
{
   Ogre::Rectangle2D *rect2d = ConvertFromGMPointer<Ogre::Rectangle2D*>(rect2d_ptr);

   if (rect2d == NULL)
      return FALSE;

   rect2d->setVisible(false);

   return TRUE;
}


GMFN double SetRectangle2DRenderQueueGroup(double rect2d_ptr, double type)
{
   Ogre::Rectangle2D *rect2d = ConvertFromGMPointer<Ogre::Rectangle2D*>(rect2d_ptr);

   if (rect2d == NULL)
      return FALSE;

   rect2d->setRenderQueueGroup(static_cast<Ogre::RenderQueueGroupID>((int)type));

   return TRUE;
}

#endif
