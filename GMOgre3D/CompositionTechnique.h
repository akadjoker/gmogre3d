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

#ifndef GMOGRE_COMPOSITION_TECHNIQUE_H
#define GMOGRE_COMPOSITION_TECHNIQUE_H

#include "GMOgre3D.h"


static Ogre::String comp_tech_tex_def_name;


GMFN double CreateCompositionTechniqueTextureDefinition1(char *name)
{
   comp_tech_tex_def_name = name;

   return TRUE;
}


GMFN double CreateCompositionTechniqueTextureDefinition2(double technique_ptr, double width, double height, double pixel_format)
{
   Ogre::CompositionTechnique *tech = ConvertFromGMPointer<Ogre::CompositionTechnique *>(technique_ptr);

   if (tech == NULL)
      return 0;

   Ogre::CompositionTechnique::TextureDefinition *def = tech->createTextureDefinition(comp_tech_tex_def_name);
   def->width = width;
   def->height = height;
   def->formatList.push_back(static_cast<Ogre::PixelFormat>((int)pixel_format));

   return ConvertToGMPointer(def);
}


GMFN double GetCompositionTechniqueTextureDefinition(double technique_ptr, double def_index)
{
   Ogre::CompositionTechnique *tech = ConvertFromGMPointer<Ogre::CompositionTechnique *>(technique_ptr);
   
   if (tech == NULL)
      return 0;

   return ConvertToGMPointer(tech->getTextureDefinition(def_index));
}


GMFN double GetNumCompositionTechniqueTextureDefinitions(double technique_ptr)
{
   Ogre::CompositionTechnique *tech = ConvertFromGMPointer<Ogre::CompositionTechnique *>(technique_ptr);
   
   if (tech == NULL)
      return 0;

   return tech->getNumTextureDefinitions();
}


GMFN double CreateCompositionTechniqueTargetPass(double technique_ptr)
{
   Ogre::CompositionTechnique *tech = ConvertFromGMPointer<Ogre::CompositionTechnique *>(technique_ptr);

   if (tech == NULL)
      return 0;

   Ogre::CompositionTargetPass *pass = tech->createTargetPass();

   return ConvertToGMPointer(pass);
}


GMFN double GetCompositionTechniqueTargetPass(double technique_ptr, double pass_index)
{
   Ogre::CompositionTechnique *tech = ConvertFromGMPointer<Ogre::CompositionTechnique *>(technique_ptr);
   
   if (tech == NULL)
      return 0;

   return ConvertToGMPointer(tech->getTargetPass(pass_index));
}


GMFN double GetNumCompositionTechniqueTargetPasses(double technique_ptr)
{
   Ogre::CompositionTechnique *tech = ConvertFromGMPointer<Ogre::CompositionTechnique *>(technique_ptr);
   
   if (tech == NULL)
      return 0;

   return tech->getNumTargetPasses();
}

#endif
