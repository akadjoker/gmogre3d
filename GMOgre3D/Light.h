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

#ifndef GMOGRE_LIGHT_H
#define GMOGRE_LIGHT_H

#include "GMOgre3D.h"

static Ogre::String light_entity_bone_name;
static double light_id;
static double light_entity_id;


GMFN double CreateLight()
{
   if (mSceneMgr == NULL)
      return FALSE;

   Ogre::Light *light = NULL;
   
   TRY
      light = mSceneMgr->createLight(GenerateUniqueName());
   CATCH("CreateLight")

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

   light->setPosition(ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double SetLightDirection(double light_ptr, double x, double z, double y)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setDirection(ConvertFromGMAxis(x, y, z));

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

   light->setAttenuation((Ogre::Real)range, (Ogre::Real)constant, (Ogre::Real)linear, (Ogre::Real)quadratic);

   return TRUE;
}


GMFN double GetLightAttenuationRange(double light_ptr)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return 0;

   return light->getAttenuationRange();
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

   light->setSpotlightRange(Ogre::Degree((Ogre::Real)inner_angle), Ogre::Degree((Ogre::Real)outer_angle), (Ogre::Real)falloff);

   return TRUE;
}


GMFN double EnableLightCastShadows(double light_ptr, double enable)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setCastShadows((enable != 0));

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


GMFN double AttachLightToEntityBone1(double light_ptr, double entity_ptr, char *bone_name)
{
   light_id = light_ptr;
   light_entity_id = entity_ptr;
   light_entity_bone_name = bone_name;

   return TRUE;
}


GMFN double AttachLightToEntityBone2(double x, double y, double z, double yaw, double pitch, double roll)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_id);

   if (light == NULL)
      return FALSE;

   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(light_entity_id);

   if (entity == NULL)
      return FALSE;

   entity->attachObjectToBone(light_entity_bone_name, light, Euler(Ogre::Degree(ConvertFromGMYaw(yaw + 90)), Ogre::Degree((Ogre::Real)pitch), Ogre::Degree((Ogre::Real)roll)), ConvertFromGMAxis(x, y, z));

   return TRUE;
}


GMFN double DetachLightFromEntityBone(double light_ptr, double entity_ptr)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;
   
   Ogre::Entity *entity = ConvertFromGMPointer<Ogre::Entity*>(entity_ptr);

   if (entity == NULL)
      return FALSE;
   
   entity->detachObjectFromBone(light->getName());

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


GMFN double SetLightMask(double light_ptr, double flags)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setLightMask((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetLightVisibilityFlags(double light_ptr, double flags)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setVisibilityFlags((Ogre::uint)flags);

   return TRUE;
}


GMFN double SetLightRenderQueueGroup(double light_ptr, double type)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   light->setRenderQueueGroup(static_cast<Ogre::RenderQueueGroupID>((int)type));

   return TRUE;
}


GMFN double SetLightUserData(double light_ptr, char *key, double data)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   if (key == NULL)
      light->getUserObjectBindings().setUserAny(Ogre::Any(data));
   else
      light->getUserObjectBindings().setUserAny(key, Ogre::Any(data));

   return TRUE;
}


GMFN double GetLightUserData(double light_ptr, char *key)
{
   Ogre::Light *light = ConvertFromGMPointer<Ogre::Light*>(light_ptr);

   if (light == NULL)
      return FALSE;

   if (key == NULL)
      return Ogre::any_cast<double>(light->getUserObjectBindings().getUserAny());
   else
      return Ogre::any_cast<double>(light->getUserObjectBindings().getUserAny(key));
}

#endif
