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

#ifndef GMOGRE_SIMPLE_SPLINE_H
#define GMOGRE_SIMPLE_SPLINE_H

#include "GMOgre3D.h"


GMFN double CreateSimpleSpline()
{
   Ogre::SimpleSpline *spline = new Ogre::SimpleSpline;

   return ConvertToGMPointer(spline);
}


GMFN double DestroySimpleSpline(double spline_ptr)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   delete spline;

   return TRUE;
}


GMFN double AddSimpleSplinePoint(double spline_ptr, double x, double z, double y)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   spline->addPoint(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double GetSimpleSplineNumPoints(double spline_ptr)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return 0;

   return spline->getNumPoints();
}


GMFN double GetSimpleSplinePoint(double spline_ptr, double index)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   if (spline->getNumPoints() <= (unsigned short)index)
      return FALSE;

   Ogre::Vector3 vec = spline->getPoint((unsigned int)index);

   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double ClearSimpleSpline(double spline_ptr)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   spline->clear();

   return TRUE;
}


GMFN double UpdateSimpleSplinePoint(double spline_ptr, double index, double x, double z, double y)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   spline->updatePoint(index, Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double GetSimpleSplineInterpolate(double spline_ptr, double t)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   Ogre::Vector3 vec = spline->interpolate(t);

   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double GetSimpleSplineInterpolateFrom(double spline_ptr, double from_index, double t)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   Ogre::Vector3 vec = spline->interpolate(from_index, t);

   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double EnableSimpleSplineAutoCalculate(double spline_ptr, double enable)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   spline->setAutoCalculate((enable != 0));

   return TRUE;
}


GMFN double RecalcSimpleSplineTangent(double spline_ptr)
{
   Ogre::SimpleSpline *spline = ConvertFromGMPointer<Ogre::SimpleSpline*>(spline_ptr);

   if (spline == NULL)
      return FALSE;

   spline->recalcTangents();

   return TRUE;
}

#endif
