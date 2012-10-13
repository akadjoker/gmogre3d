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

#ifndef GMOGRE_RESOURCE_H
#define GMOGRE_RESOURCE_H

#include "GMOgre3D.h"
#include "ResourceListener.h"


static bool use_background_loading = false;
static GMResourceListener resource_listener;

GMFN double AddResourceLocation(char *name, char *type, char *group)
{
   if (mRoot == NULL)
      return FALSE;

   TRY
      Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, type, group);
   CATCH("AddResourceLocation")

   return TRUE;
}


GMFN double RemoveResourceLocation(char *name, char *group)
{
   if (mRoot == NULL)
      return FALSE;

   TRY
      Ogre::ResourceGroupManager::getSingleton().removeResourceLocation(name, group);
   CATCH("RemoveResourceLocation")

   return TRUE;
}


GMFN double EnableResourceBackgroundLoading(double enable, double func)
{
   use_background_loading = (enable != 0.0);
   resource_listener.SetResourceOperationCompleted((int)func);

   return TRUE;
}


GMFN double InitializeResourceGroup(char *group)
{
   if (mRoot == NULL)
      return FALSE;

   TRY
      if (!use_background_loading)
         Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup(group);
      else
         return Ogre::ResourceBackgroundQueue::getSingleton().initialiseResourceGroup(group, &resource_listener);

   CATCH("InitializeResourceGroup")

   return TRUE;
}


GMFN double InitializeAllResourceGroups()
{
   if (mRoot == NULL)
      return FALSE;

   TRY
      Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
   CATCH("InitializeAllResourceGroups")

   return TRUE;
}


GMFN double LoadResourceGroup(char *group)
{
   if (mRoot == NULL)
      return FALSE;

   TRY
      Ogre::ResourceGroupManager::getSingleton().loadResourceGroup(group);
   CATCH("LoadResourceGroup")

   return TRUE;
}


GMFN double UnloadResourceGroup(char *group)
{
   if (mRoot == NULL)
      return FALSE;

   TRY
      Ogre::ResourceGroupManager::getSingleton().unloadResourceGroup(group, true);
      Ogre::ResourceGroupManager::getSingleton().unloadUnreferencedResourcesInGroup(group, true);
   CATCH("UnloadResourceGroup")

   return TRUE;
}


GMFN double IsResourceBackgroundProcessComplete(double process_id)
{
   if (mRoot == NULL)
      return FALSE;

   TRY
      if (use_background_loading)
         return Ogre::ResourceBackgroundQueue::getSingleton().isProcessComplete((Ogre::BackgroundProcessTicket)process_id);
   CATCH("IsResourceBackgroundProcessComplete")

   return FALSE;
}


GMFN double DestroyResourceGroup(char *group)
{
   if (mRoot == NULL)
      return FALSE;

   TRY
      Ogre::ResourceGroupManager::getSingleton().destroyResourceGroup(group);
   CATCH("DestroyResourceGroup")

   return TRUE;
}

#endif
