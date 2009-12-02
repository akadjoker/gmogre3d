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

#ifndef GMOGRE_RESOURCE_H
#define GMOGRE_RESOURCE_H

#include "GMOgre3D.h"


GMFN double AddResourceLocation(char *name, char *type, char *group)
{
   if (mRoot == NULL)
      return FALSE;

   Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, type, group);

   return TRUE;
}


GMFN double RemoveResourceLocation(char *name, char *group)
{
   if (mRoot == NULL)
      return FALSE;

   Ogre::ResourceGroupManager::getSingleton().removeResourceLocation(name, group);

   return TRUE;
}


GMFN double InitializeAllResourceGroups()
{
   try
   {
      if (mRoot == NULL)
         return FALSE;

      Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
   }
   catch(Ogre::Exception& e)
   {
      LogError(e.what());
      return FALSE;
   }
   catch(std::exception &e)
   {
      LogError(e.what());
      return FALSE;
   }
   catch(...)
   {
      LogError("An unknown error has occurred starting the Ogre3D engine!");
      return FALSE;
   }

   return TRUE;
}


GMFN double LoadResourceGroup(char *group)
{
   if (mRoot == NULL)
      return FALSE;

   Ogre::ResourceGroupManager::getSingleton().loadResourceGroup(group);

   return TRUE;
}


GMFN double UnloadResourceGroup(char *group)
{
   if (mRoot == NULL)
      return FALSE;

   Ogre::ResourceGroupManager::getSingleton().unloadResourceGroup(group, true);
   Ogre::ResourceGroupManager::getSingleton().unloadUnreferencedResourcesInGroup(group, true);

   return TRUE;
}


GMFN double DestroyResourceGroup(char *group)
{
   if (mRoot == NULL)
      return FALSE;

   Ogre::ResourceGroupManager::getSingleton().destroyResourceGroup(group);

   return TRUE;
}

#endif
