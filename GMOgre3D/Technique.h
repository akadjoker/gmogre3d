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

#ifndef GMOGRE_TECHNIQUE_H
#define GMOGRE_TECHNIQUE_H

#include "GMOgre3D.h"


GMFN double SetTechniqueAmbientColor(double technique_ptr, double color)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);
   
   if (tech == NULL)
      return FALSE;

   tech->setAmbient(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color));

   return TRUE;
}


GMFN double SetTechniqueDiffuseColor(double technique_ptr, double color, double alpha)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);
   
   if (tech == NULL)
      return FALSE;

   tech->setDiffuse(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha);

   return TRUE;
}


GMFN double SetTechniqueSpecularColor(double technique_ptr, double color, double alpha)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);

   if (tech == NULL)
      return FALSE;

   tech->setSpecular(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha);

   return TRUE;
}


GMFN double SetTechniqueSelfIllumination(double technique_ptr, double color)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);

   if (tech == NULL)
      return FALSE;

   tech->setSelfIllumination(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color));

   return TRUE;
}


GMFN double SetTechniqueShininess(double technique_ptr, double shininess)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);

   if (tech == NULL)
      return FALSE;

   tech->setShininess(shininess);

   return TRUE;
}


GMFN double SetTechniqueLODIndex(double technique_ptr, double index)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);

   if (tech == NULL)
      return FALSE;

   tech->setLodIndex(index);

   return TRUE;
}


GMFN double CreateTechniquePass(double technique_ptr)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);

   if (tech == NULL)
      return 0;

   Ogre::Pass *pass = tech->createPass();

   return ConvertToGMPointer(pass);
}


GMFN double GetTechniquePass(double technique_ptr, double pass_index)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);
   
   if (tech == NULL)
      return 0;

   return ConvertToGMPointer(tech->getPass(pass_index));
}


GMFN double GetNumTechniquePasses(double technique_ptr)
{
   Ogre::Technique *tech = ConvertFromGMPointer<Ogre::Technique *>(technique_ptr);
   
   if (tech == NULL)
      return 0;

   return tech->getNumPasses();
}

#endif
