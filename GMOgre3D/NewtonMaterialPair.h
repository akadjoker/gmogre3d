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

#ifndef GMOGRE_NEWTON_MATERIAL_PAIR
#define GMOGRE_NEWTON_MATERIAL_PAIR

#include "OgreNewt_MaterialID.h"
#include "OgreNewt_MaterialPair.h"


class NewtonMaterialPairCallback : public OgreNewt::ContactCallback
{
public:
   NewtonMaterialPairCallback(OgreNewt::MaterialPair* mat_pair, unsigned int function)
      : mMaterialPair(mat_pair), mFunction(function)
   {
   }

	~NewtonMaterialPairCallback()
   {
   }

    int onAABBOverlap( OgreNewt::Body* body0, OgreNewt::Body* body1, int threadIndex )
    {
       // If we set a callback we ALWAYS want to process hits
       return 1;
    }

    void contactsProcess( OgreNewt::ContactJoint &contactJoint, Ogre::Real timeStep, int threadIndex )
    {
       // Call our GM script to handle this contact
       gm::CGMVariable args[3];
       args[0].Set(ConvertToGMPointer((OgreNewt::Contact*)&contactJoint.getFirstContact()));
       args[1].Set(ConvertToGMPointer(contactJoint.getBody0()));
       args[2].Set(ConvertToGMPointer(contactJoint.getBody1()));

       gm::script_execute(mFunction, args, 3);
    }

private:
	OgreNewt::MaterialPair *mMaterialPair;
   unsigned int mFunction;
};


GMFN double CreateNewtonMaterialPair(double newton_world_ptr, double material1_ptr, double material2_ptr)
{
   OgreNewt::World *world = ConvertFromGMPointer<OgreNewt::World*>(newton_world_ptr);

   if (!world)
      return 0;

   OgreNewt::MaterialID *mat1 = ConvertFromGMPointer<OgreNewt::MaterialID*>(material1_ptr);

   if (!mat1)
      return FALSE;

   OgreNewt::MaterialID *mat2 = ConvertFromGMPointer<OgreNewt::MaterialID*>(material2_ptr);

   if (!mat2)
      return FALSE;

   OgreNewt::MaterialPair *mat_pair;

   TRY
      mat_pair = new OgreNewt::MaterialPair(world, mat1, mat2);
   CATCH("CreateNewtonMaterialPair")

   return ConvertToGMPointer(mat_pair);
}


GMFN double DestroyNewtonMaterialPair(double material_pair_ptr)
{
   OgreNewt::MaterialPair *mat_pair = ConvertFromGMPointer<OgreNewt::MaterialPair*>(material_pair_ptr);

   if (!mat_pair)
      return FALSE;

   delete mat_pair;

   return TRUE;
}


GMFN double SetNewtonMaterialPairDefaultSoftness(double material_pair_ptr, double softness)
{
   OgreNewt::MaterialPair *mat_pair = ConvertFromGMPointer<OgreNewt::MaterialPair*>(material_pair_ptr);

   if (!mat_pair)
      return FALSE;

   mat_pair->setDefaultSoftness(softness);

   return TRUE;
}


GMFN double SetNewtonMaterialPairDefaultElasticity(double material_pair_ptr, double elasticity)
{
   OgreNewt::MaterialPair *mat_pair = ConvertFromGMPointer<OgreNewt::MaterialPair*>(material_pair_ptr);

   if (!mat_pair)
      return FALSE;

   mat_pair->setDefaultElasticity(elasticity);

   return TRUE;
}


GMFN double EnableNewtonMaterialPairDefaultCollidable(double material_pair_ptr, double enable)
{
   OgreNewt::MaterialPair *mat_pair = ConvertFromGMPointer<OgreNewt::MaterialPair*>(material_pair_ptr);

   if (!mat_pair)
      return FALSE;

   mat_pair->setDefaultCollidable((enable != 0) ? 1 : 0);

   return TRUE;
}


GMFN double EnableNewtonMaterialPairContinuousCollision(double material_pair_ptr, double enable)
{
   OgreNewt::MaterialPair *mat_pair = ConvertFromGMPointer<OgreNewt::MaterialPair*>(material_pair_ptr);

   if (!mat_pair)
      return FALSE;

   mat_pair->setContinuousCollisionMode((enable != 0) ? 1 : 0);

   return TRUE;
}


GMFN double SetNewtonMaterialPairDefaultSurfaceThickness(double material_pair_ptr, double thickness)
{
   OgreNewt::MaterialPair *mat_pair = ConvertFromGMPointer<OgreNewt::MaterialPair*>(material_pair_ptr);

   if (!mat_pair)
      return FALSE;

   mat_pair->setDefaultSurfaceThickness(thickness);

   return TRUE;
}


GMFN double SetNewtonMaterialPairDefaultFriction(double material_pair_ptr, double static_friction, double kinetic_friction)
{
   OgreNewt::MaterialPair *mat_pair = ConvertFromGMPointer<OgreNewt::MaterialPair*>(material_pair_ptr);

   if (!mat_pair)
      return FALSE;

   mat_pair->setDefaultFriction(static_friction, kinetic_friction);

   return TRUE;
}


GMFN double SetNewtonMaterialPairContactCallback(double material_pair_ptr, double func)
{
   OgreNewt::MaterialPair *mat_pair = ConvertFromGMPointer<OgreNewt::MaterialPair*>(material_pair_ptr);

   if (!mat_pair)
      return FALSE;

   mat_pair->setContactCallback(new NewtonMaterialPairCallback(mat_pair, func));

   return TRUE;
}

#endif
