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

#ifndef GMOGRE_NEWTON_CONTACT
#define GMOGRE_NEWTON_CONTACT

#include "OgreNewt_ContactJoint.h"


GMFN double GetNextNewtonContact(double contact_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   return ConvertToGMPointer(&contact->getNext());
}


GMFN double GetNewtonContactBodyCollisionID(double contact_ptr, double body_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   OgreNewt::Body *body = ConvertFromGMPointer<OgreNewt::Body*>(body_ptr);

   if (!body)
      return 0;

   return contact->getBodyCollisionID(body);
}


GMFN double GetNewtonContactNormalSpeed(double contact_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   return contact->getNormalSpeed();
}


GMFN double GetNewtonContactForce(double contact_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   Ogre::Vector3 vec = contact->getForce();

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double GetNewtonContactPosition(double contact_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   Ogre::Vector3 vec, vec2;
   contact->getPositionAndNormal(vec, vec2);

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double GetNewtonContactNormal(double contact_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   Ogre::Vector3 vec, vec2;
   contact->getPositionAndNormal(vec2, vec);

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double SetNewtonContactSoftness(double contact_ptr, double softness)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->setSoftness(softness);

   return TRUE;
}


GMFN double SetNewtonContactElasticity(double contact_ptr, double elasticity)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->setElasticity(elasticity);

   return TRUE;
}


GMFN double EnableNewtonContactFriction(double contact_ptr, double enable, double index)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->setFrictionState(((int)enable == 0 ? 0 : 1), (int)index);

   return TRUE;
}


GMFN double SetNewtonContactFrictionCoef(double contact_ptr, double static_coef, double kinetic_coef, double index)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->setFrictionCoef(static_coef, kinetic_coef, (int)index);

   return TRUE;
}


GMFN double GetNewtonContactPrimaryTangentDirection(double contact_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   Ogre::Vector3 vec, vec2;
   contact->getTangentDirections(vec, vec2);

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double GetNewtonContactSecondaryTangentDirection(double contact_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   Ogre::Vector3 vec, vec2;
   contact->getTangentDirections(vec2, vec);

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      *mVectorX = vec.x;
      *mVectorY = vec.z;
      *mVectorZ = vec.y;
   }

   return TRUE;
}


GMFN double GetNewtonContactTangentSpeed(double contact_ptr, double index)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return 0;

   return contact->getTangentSpeed((int)index);
}


GMFN double SetNewtonContactTangentAcceleration(double contact_ptr, double accel, double index)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->setTangentAcceleration(accel, (int)index);

   return TRUE;
}


GMFN double RotateNewtonContactTangentDirections(double contact_ptr, double x, double z, double y)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->rotateTangentDirections(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double SetNewtonContactNormalDirections(double contact_ptr, double x, double z, double y)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->setNormalDirection(Ogre::Vector3(x, y, z));

   return TRUE;
}


GMFN double SetNewtonContactNormalAcceleration(double contact_ptr, double accel)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->setNormalAcceleration(accel);

   return TRUE;
}


GMFN double RemoveNewtonContact(double contact_ptr)
{
   OgreNewt::Contact *contact = ConvertFromGMPointer<OgreNewt::Contact*>(contact_ptr);

   if (!contact)
      return FALSE;

   contact->remove();

   return TRUE;
}

#endif
