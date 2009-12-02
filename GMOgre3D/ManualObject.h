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

#ifndef GMOGRE_MANUAL_OBJECT_H
#define GMOGRE_MANUAL_OBJECT_H

#include "GMOgre3D.h"


GMFN double CreateManualObject()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::ManualObject *man_obj = mSceneMgr->createManualObject(GenerateUniqueName());

   return ConvertToGMPointer(man_obj);
}


GMFN double DestroyManualObject(double man_obj_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   mSceneMgr->destroyManualObject(man_obj);

   return TRUE;
}


GMFN double SetManualObjectRenderQueueGroup(double man_obj_ptr, double type)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->setRenderQueueGroup(static_cast<Ogre::RenderQueueGroupID>((int)type));

   return TRUE;
}


GMFN double EnableManualObjectIdentityProjection(double man_obj_ptr, double enable)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->setUseIdentityProjection((enable != 0));

   return TRUE;
}


GMFN double EnableManualObjectIdentityView(double man_obj_ptr, double enable)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->setUseIdentityView((enable != 0));

   return TRUE;
}


GMFN double SetManualObjectQueryFlags(double man_obj_ptr, double flags)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetManualObjectBoundingBox(double man_obj_ptr, double mx, double mz, double my, double Mx, double Mz, double My)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->setBoundingBox(Ogre::AxisAlignedBox(mx, mz, my, Mx, Mz, My));

   return TRUE;
}


GMFN double EnableManualObjectDynamic(double man_obj_ptr, double enable)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->setDynamic((enable != 0));

   return TRUE;
}


GMFN double EstimateManualObjectVertexCount(double man_obj_ptr, double size)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->estimateVertexCount((size_t)size);

   return TRUE;
}


GMFN double BeginManualObjectSection(double man_obj_ptr, char *mat_name, double type)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;
   
   man_obj->begin(mat_name, static_cast<Ogre::RenderOperation::OperationType>((int)type));

   return TRUE;
}


GMFN double AddManualObjectPosition(double man_obj_ptr, double x, double z, double y)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->position(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double AddManualObjectNormal(double man_obj_ptr, double x, double z, double y)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->normal(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double AddManualObjectTriangle(double man_obj_ptr, double i1, double i2, double i3)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->triangle(i1, i2, i3);

   return TRUE;
}


GMFN double AddManualObjectQuad(double man_obj_ptr, double i1, double i2, double i3, double i4)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->quad(i1, i2, i3, i4);

   return TRUE;
}


GMFN double AddManualObjectTextureCoord1(double man_obj_ptr, double u)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->textureCoord(u);

   return TRUE;
}


GMFN double AddManualObjectTextureCoord2(double man_obj_ptr, double u, double v)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->textureCoord(u, v);

   return TRUE;
}


GMFN double AddManualObjectTextureCoord3(double man_obj_ptr, double u, double v, double w)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->textureCoord(u, v, w);

   return TRUE;
}


GMFN double AddManualObjectTextureCoord4(double man_obj_ptr, double x, double z, double y, double w)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->textureCoord(x, y, z, w);

   return TRUE;
}


GMFN double AddManualObjectColor(double man_obj_ptr, double clr, double alpha)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->colour(Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), alpha));

   return TRUE;
}


GMFN double AddManualObjectIndex(double man_obj_ptr, double index)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->index(index);

   return TRUE;
}


GMFN double EndManualObjectSection(double man_obj_ptr)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->end();

   return TRUE;
}


GMFN double ClearManualObject(double man_obj_ptr)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->clear();

   return TRUE;
}


GMFN double SetManualObjectMaterial(double man_obj_ptr, double index, char *mat_name)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->setMaterialName((size_t)index, mat_name);

   return TRUE;
}


GMFN double ConvertManualObjectToMesh(double man_obj_ptr, char *name, char *group)
{
   Ogre::ManualObject *man_obj = ConvertFromGMPointer<Ogre::ManualObject*>(man_obj_ptr);

   if (man_obj == NULL)
      return FALSE;

   man_obj->convertToMesh(name, group);

   return TRUE;
}

#endif
