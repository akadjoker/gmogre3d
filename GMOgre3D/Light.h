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

#ifndef GMOGRE_LIGHT_H
#define GMOGRE_LIGHT_H

#include "GMOgre3D.h"


GMFN double CreateLight()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Light *light = mSceneMgr->createLight(GenerateUniqueName());

   return ConvertToGMPointer(light);
}


GMFN double DestroyLight(double light_ptr)
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   mSceneMgr->destroyLight(light);

   return TRUE;
}


GMFN double SetLightPosition(double light_ptr, double x, double z, double y)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setPosition(x, y, z);

   return TRUE;
}


GMFN double SetLightDirection(double light_ptr, double x, double z, double y)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setDirection(x, y, z);

   return TRUE;
}


GMFN double SetLightType(double light_ptr, double type)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setType(static_cast<Ogre::Light::LightTypes>((int)type));

   return TRUE;
}


GMFN double SetLightAttenuation(double light_ptr, double range, double constant, double linear, double quadratic)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setAttenuation(range, constant, linear, quadratic);

   return TRUE;
}


GMFN double SetLightDiffuseColor(double light_ptr, double color)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setDiffuseColour(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color));

   return TRUE;
}


GMFN double SetLightSpecularColor(double light_ptr, double color)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setSpecularColour(GetRedFromGMColor(color), GetGreenFromGMColor(color), GetBlueFromGMColor(color));

   return TRUE;
}


GMFN double SetLightSpotlightRange(double light_ptr, double inner_angle, double outer_angle, double falloff = 1.0)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setSpotlightRange(Ogre::Degree(inner_angle), Ogre::Degree(outer_angle), falloff);

   return TRUE;
}


GMFN double AttachLightToSceneNode(double light_ptr, double scene_node_ptr)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->attachObject(light);

   return TRUE;
}


GMFN double DetachLightFromSceneNode(double light_ptr, double scene_node_ptr)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;
   
   Ogre::SceneNode *node = ConvertFromGMPointer<Ogre::SceneNode*>(scene_node_ptr);
   
   if (node == NULL)
      return FALSE;
   
   node->detachObject(light);

   return TRUE;
}


GMFN double SetLightQueryFlags(double light_ptr, double flags)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setQueryFlags((Ogre::uint)flags);

   return TRUE;
}

#endif
