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

#ifndef GMOGRE_MATERIAL_H
#define GMOGRE_MATERIAL_H

#include "GMOgre3D.h"


GMFN char *GetMaterialByName(char *name)
{
   // This is just a convienence function to allow users to use the same
   // standard for retrieving script objects (fonts, materials, overlay, etc)
   // the same way.  In this case the ID really IS the name, but for other
   // script types it may be an actual object pointer.

   return name;
}


GMFN char *CreateMaterial(char *name, char *group = const_cast<char*>(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str()))
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().create(name, group, true);

   return name;
}


GMFN double DestroyMaterial(char *name)
{
   Ogre::MaterialManager::getSingleton().remove(name);

   return TRUE;
}


GMFN double LoadMaterial(char *name)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;
   
   mat->load();

   return TRUE;
}


GMFN double UnloadMaterial(char *name)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;
   
   mat->unload();

   return TRUE;
}


GMFN double EnableMaterialLighting(char *name, double enabled)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   mat->setLightingEnabled((enabled != 0));

   return TRUE;
}


GMFN double SetMaterialAmbientColor(char *name, double color)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   mat->setAmbient(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color));

   return TRUE;
}


GMFN double SetMaterialDiffuseColor(char *name, double color, double alpha)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   mat->setDiffuse(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha);

   return TRUE;
}


GMFN double SetMaterialSpecularColor(char *name, double color, double alpha)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);

   if (mat.isNull())
      return FALSE;

   mat->setSpecular(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color), alpha);

   return TRUE;
}


GMFN double SetMaterialSelfIllumination(char *name, double color)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);

   if (mat.isNull())
      return FALSE;

   mat->setSelfIllumination(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color));

   return TRUE;
}


GMFN double SetMaterialShininess(char *name, double shininess)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);

   if (mat.isNull())
      return FALSE;

   mat->setShininess(shininess);

   return TRUE;
}


GMFN double SetMaterialReceiveShadows(char *name, double enabled)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   mat->setReceiveShadows((enabled != 0));

   return TRUE;
}


GMFN double GetMaterialReceiveShadows(char *name)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   return mat->getReceiveShadows();
}


GMFN double SetMaterialLODLevels1(char *name, double lod1, double lod2, double lod3)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   mLODLevels.clear();

   if (lod1 > 0)
      mLODLevels.push_back(lod1);
   if (lod2 > 0)
      mLODLevels.push_back(lod2);
   if (lod3 > 0)
      mLODLevels.push_back(lod3);

   return TRUE;
}


GMFN double SetMaterialLODLevels2(char *name, double lod4, double lod5, double lod6)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   if (lod4 > 0)
      mLODLevels.push_back(lod4);
   if (lod5 > 0)
      mLODLevels.push_back(lod5);
   if (lod6 > 0)
      mLODLevels.push_back(lod6);

   return TRUE;
}


GMFN double SetMaterialLODLevels3(char *name, double lod7, double lod8, double lod9)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   if (lod7 > 0)
      mLODLevels.push_back(lod7);
   if (lod8 > 0)
      mLODLevels.push_back(lod8);
   if (lod9 > 0)
      mLODLevels.push_back(lod9);

   return TRUE;
}


GMFN double SetMaterialLODLevels4(char *name, double lod10, double lod11, double lod12)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return FALSE;

   if (lod10 > 0)
      mLODLevels.push_back(lod10);
   if (lod11 > 0)
      mLODLevels.push_back(lod11);
   if (lod12 > 0)
      mLODLevels.push_back(lod12);

   mat->setLodLevels(mLODLevels);

   return TRUE;
}


GMFN double CreateMaterialTechnique(char *name)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);

   if (mat.isNull())
      return 0;

   Ogre::Technique *tech = mat->createTechnique();

   return ConvertToGMPointer(tech);
}


GMFN double GetMaterialTechnique(char *name, double technique_index)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return 0;

   return ConvertToGMPointer(mat->getTechnique(technique_index));
}


GMFN double GetNumMaterialTechniques(char *name)
{
   Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().getByName(name);
   
   if (mat.isNull())
      return 0;

   return mat->getNumTechniques();
}


GMFN double SetDefaultMaterialTextureFiltering(double type)
{
   Ogre::MaterialManager::getSingleton().setDefaultTextureFiltering(static_cast<Ogre::TextureFilterOptions>((int)type));

   return TRUE;
}


GMFN double SetDefaultMaterialAnisotropy(double anisotropy)
{
   Ogre::MaterialManager::getSingleton().setDefaultAnisotropy(anisotropy);

   return TRUE;
}

#endif
