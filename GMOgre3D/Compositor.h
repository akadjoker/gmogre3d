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

#ifndef GMOGRE_COMPOSITOR_H
#define GMOGRE_COMPOSITOR_H

#include "GMOgre3D.h"


GMFN char *GetCompositorByName(char *name)
{
   // This is just a convienence function to allow users to use the same
   // standard for retrieving script objects (fonts, materials, overlay, etc)
   // the same way.  In this case the ID really IS the name, but for other
   // script types it may be an actual object pointer.

   return name;
}


GMFN double CreateCompositor(char *name, char *group = const_cast<char*>(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str()))
{
   Ogre::CompositorPtr com = Ogre::CompositorManager::getSingleton().create(name, group, true);

   return TRUE;
}


GMFN double DestroyCompositor(char *name)
{
   CompositorListenerMap::iterator iter = mCompositorListener.find(name);
   if (iter != mCompositorListener.end())
   {
      delete iter->second;
      mCompositorListener.erase(iter);
   }

   Ogre::CompositorManager::getSingleton().remove(name);

   return TRUE;
}


GMFN double LoadCompositor(char *name)
{
   Ogre::CompositorPtr com = Ogre::CompositorManager::getSingleton().getByName(name);
   
   if (com.isNull())
      return FALSE;
   
   com->load();

   return TRUE;
}


GMFN double UnloadCompositor(char *name)
{
   Ogre::CompositorPtr com = Ogre::CompositorManager::getSingleton().getByName(name);
   
   if (com.isNull())
      return FALSE;
   
   com->unload();

   return TRUE;
}


GMFN double AddCompositorToViewport(char *name, double viewport_ptr)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   Ogre::CompositorManager::getSingleton().addCompositor(view, name);

   return TRUE;
}


GMFN double RemoveCompositorFromViewport(char *name, double viewport_ptr)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   Ogre::CompositorManager::getSingleton().removeCompositor(view, name);

   return TRUE;
}


GMFN double EnableCompositorInViewport(char *name, double viewport_ptr, double enable)
{
   Ogre::Viewport *view = ConvertFromGMPointer<Ogre::Viewport*>(viewport_ptr);

   if (view == NULL)
      return FALSE;

   Ogre::CompositorManager::getSingleton().setCompositorEnabled(view, name, (enable != 0));

   return TRUE;
}


GMFN double CreateCompositorTechnique(char *name)
{
   Ogre::CompositorPtr com = Ogre::CompositorManager::getSingleton().getByName(name);

   if (com.isNull())
      return 0;

   Ogre::CompositionTechnique *tech = NULL;

   TRY
      tech = com->createTechnique();
   CATCH("CreateCompositorTechnique")

   return ConvertToGMPointer(tech);
}


GMFN double GetCompositorTechnique(char *name, double technique_index)
{
   Ogre::CompositorPtr com = Ogre::CompositorManager::getSingleton().getByName(name);
   
   if (com.isNull())
      return 0;

   return ConvertToGMPointer(com->getTechnique((size_t)technique_index));
}


GMFN double GetNumCompositorTechniques(char *name)
{
   Ogre::CompositorPtr com = Ogre::CompositorManager::getSingleton().getByName(name);
   
   if (com.isNull())
      return 0;

   return com->getNumTechniques();
}


GMFN double SetCompositorMaterialSetupCallback(char *name, double func)
{
   Ogre::CompositorPtr com = Ogre::CompositorManager::getSingleton().getByName(name);
   
   if (com.isNull())
      return 0;

   GMCompositorListener *cl = NULL;

   CompositorListenerMap::iterator iter = mCompositorListener.find(name);
   if (iter != mCompositorListener.end())
      cl = iter->second;
   else
   {
      GMCompositorListener *cl = OGRE_NEW GMCompositorListener;
      mCompositorListener[name] = cl;
   }

   cl->SetNotifyMaterialSetupCallback((int)func);

   return TRUE;
}


GMFN double SetCompositorMaterialRenderCallback(char *name, double func)
{
   Ogre::CompositorPtr com = Ogre::CompositorManager::getSingleton().getByName(name);
   
   if (com.isNull())
      return 0;

   GMCompositorListener *cl = NULL;

   CompositorListenerMap::iterator iter = mCompositorListener.find(name);
   if (iter != mCompositorListener.end())
      cl = iter->second;
   else
   {
      GMCompositorListener *cl = OGRE_NEW GMCompositorListener;
      mCompositorListener[name] = cl;
   }

   cl->SetNotifyMaterialRenderCallback((int)func);

   return TRUE;
}

#endif
