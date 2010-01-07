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

#ifndef GMOGRE_PARTICLE_SYSTEM_H
#define GMOGRE_PARTICLE_SYSTEM_H

#include "GMOgre3D.h"


GMFN double CreateParticleSystem(char *name)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::ParticleSystem *part_sys = NULL;
   
   TRY
      part_sys = mSceneMgr->createParticleSystem(GenerateUniqueName(), name);

      if (part_sys == NULL)
         return FALSE;
   CATCH("CreateParticleSystem")

   return ConvertToGMPointer(part_sys);
}


GMFN double CreateEmptyParticleSystem(double quota, char *group)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::ParticleSystem *part_sys = NULL;
   
   TRY
      part_sys = mSceneMgr->createParticleSystem(GenerateUniqueName(), (size_t)quota, group);

      if (part_sys == NULL)
         return FALSE;
   CATCH("CreateEmptyParticleSystem")

   return ConvertToGMPointer(part_sys);
}


GMFN double DestroyParticleSystem(double part_sys_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   mSceneMgr->destroyParticleSystem(part_sys);

   return TRUE;
}


GMFN double SetParticleSystemMaterial(double part_sys_ptr, char *part_sys_name)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setMaterialName(part_sys_name);

   return TRUE;
}


GMFN double SetParticleSystemQuota(double part_sys_ptr, double quota)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setParticleQuota(quota);

   return TRUE;
}


GMFN double EnableParticleSystemIndividualCulling(double part_sys_ptr, double enable)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setCullIndividually((enable != 0));

   return TRUE;
}


GMFN double EnableParticleSystemSorting(double part_sys_ptr, double enable)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setSortingEnabled((enable != 0));

   return TRUE;
}


GMFN double EnableParticleSystemParticlesInLocalSpace(double part_sys_ptr, double enable)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setKeepParticlesInLocalSpace((enable != 0));

   return TRUE;
}


GMFN double SetParticleSystemNonVisibleTimeout(double part_sys_ptr, double timeout)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setNonVisibleUpdateTimeout(timeout);

   return TRUE;
}


GMFN double FastForwardParticleSystem(double part_sys_ptr, double time, double interval = 0.1)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->fastForward(time, interval);

   return TRUE;
}


GMFN double SetParticleSystemSpeedFactor(double part_sys_ptr, double speed)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setSpeedFactor(speed);

   return TRUE;
}


GMFN double SetParticleSystemIterationInterval(double part_sys_ptr, double interval)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setIterationInterval(interval);

   return TRUE;
}


GMFN double SetParticleSystemDimensions(double part_sys_ptr, double width, double height)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setDefaultDimensions(width, height);

   return TRUE;
}


GMFN double GetParticleSystemDefaultWidth(double part_sys_ptr)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return 0;

   return part_sys->getDefaultWidth();
}


GMFN double GetParticleSystemDefaultHeight(double part_sys_ptr)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   return part_sys->getDefaultHeight();
}


GMFN double AttachParticleSystemToSceneNode(double part_sys_ptr, double scene_node_ptr)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->attachObject(part_sys);

   return TRUE;
}


GMFN double DetachParticleSystemFromSceneNode(double part_sys_ptr, double scene_node_ptr)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->detachObject(part_sys);

   return TRUE;
}



GMFN double AddParticleSystemEmitter(double part_sys_ptr, double type)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return 0;

   Ogre::ParticleEmitter *emit = NULL;

   if (type == 0)
      emit = part_sys->addEmitter("Box");
   else if (type == 1)
      emit = part_sys->addEmitter("Cylinder");
   else if (type == 2)
      emit = part_sys->addEmitter("Ellipsoid");
   else if (type == 3)
      emit = part_sys->addEmitter("HollowEllipsoid");
   else if (type == 4)
      emit = part_sys->addEmitter("Point");
   else if (type == 5)
      emit = part_sys->addEmitter("Ring");

   return ConvertToGMPointer(emit);
}


GMFN double GetNumParticleSystemEmitters(double part_sys_ptr)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return 0;

   return part_sys->getNumEmitters();
}


GMFN double GetParticleSystemEmitter(double part_sys_ptr, double index)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return 0;

   Ogre::ParticleEmitter *emit = part_sys->getEmitter(index);

   return ConvertToGMPointer(emit);
}


GMFN double RemoveParticleSystemEmitter(double part_sys_ptr, double index)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->removeEmitter(index);

   return TRUE;
}


GMFN double RemoveAllParticleSystemEmitters(double part_sys_ptr)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->removeAllEmitters();

   return TRUE;
}


GMFN double SetParticleSystemRenderQueueGroup(double part_sys_ptr, double type)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setRenderQueueGroup(static_cast<Ogre::RenderQueueGroupID>((int)type));

   return TRUE;
}


GMFN double SetParticleSystemQueryFlags(double part_sys_ptr, double flags)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys_ptr);

   if (part_sys == NULL)
      return FALSE;

   part_sys->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}

/*
GMFN double AddParticleSystemAffector(double part_sys_ptr, char *name)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys);

   if (part_sys == NULL)
      return 0;

   Ogre::ParticleAffector *aff = part_sys->addAffector(aff);

   return ConvertToGMPointer(aff);
}


GMFN double GetNumParticleSystemAffectors(double part_sys_ptr)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys);

   if (part_sys == NULL)
      return 0;

   return part_sys->getNumAffectors();
}


GMFN double GetParticleSystemAffector(double part_sys_ptr, double index)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys);

   if (part_sys == NULL)
      return 0;

   Ogre::ParticleAffector *aff = part_sys->getAffector(index);

   return ConvertToGMPointer(aff);
}


GMFN double RemoveParticleSystemAffector(double part_sys_ptr, double index)
{
   Ogre::ParticleSystem *part_sys = ConvertFromGMPointer<Ogre::ParticleSystem*>(part_sys);

   if (part_sys == NULL)
      return FALSE;

   part_sys->removeAffector(index);

   return TRUE;
}
*/

#endif
