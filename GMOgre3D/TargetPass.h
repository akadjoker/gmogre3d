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

#ifndef GMOGRE_TARGET_PASS_H
#define GMOGRE_TARGET_PASS_H

#include "GMOgre3D.h"


GMFN double SetTargetPassInputMode(double pass_ptr, double mode)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);
   
   if (pass == NULL)
      return FALSE;

   pass->setInputMode(static_cast<Ogre::CompositionTargetPass::InputMode>((int)mode));

   return TRUE;
}


GMFN double SetTargetPassOutputName(double pass_ptr, char *name)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);
   
   if (pass == NULL)
      return FALSE;

   pass->setOutputName(name);

   return TRUE;
}


GMFN double EnableTargetPassOnlyInitial(double pass_ptr, double enabled)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setOnlyInitial((enabled != 0));

   return TRUE;
}


GMFN double SetTargetPassVisibilityMask(double pass_ptr, double mask)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setVisibilityMask(mask);

   return TRUE;
}


GMFN double SetTargetPassLODBias(double pass_ptr, double bias)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setLodBias(bias);

   return TRUE;
}


GMFN double SetTargetPassMaterialScheme(double pass_ptr, char *scheme)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setMaterialScheme(scheme);

   return TRUE;
}


GMFN double EnableTargetPassShadows(double pass_ptr, double enable)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setShadowsEnabled((enable != 0));

   return TRUE;
}


GMFN double CreateCompositionPass(double pass_ptr)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);

   if (pass == NULL)
      return 0;

   Ogre::CompositionPass *p = NULL;
   
   TRY
      p = pass->createPass();
   CATCH("CreateCompositionPass")
   return ConvertToGMPointer(p);
}


GMFN double GetCompositionPass(double pass_ptr, double pass_index)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);
   
   if (pass == NULL)
      return 0;

   return ConvertToGMPointer(pass->getPass(pass_index));
}


GMFN double GetNumCompositionPasses(double pass_ptr)
{
   Ogre::CompositionTargetPass *pass = ConvertFromGMPointer<Ogre::CompositionTargetPass *>(pass_ptr);
   
   if (pass == NULL)
      return 0;

   return pass->getNumPasses();
}

#endif
