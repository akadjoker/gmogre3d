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

#ifndef GMOGRE_COMPOSITION_PASS_H
#define GMOGRE_COMPOSITION_PASS_H

#include "GMOgre3D.h"


GMFN double SetCompositionPassType(double pass_ptr, double type)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);
   
   if (pass == NULL)
      return FALSE;

   pass->setType(static_cast<Ogre::CompositionPass::PassType>((int)type));

   return TRUE;
}


GMFN double SetCompositionPassIdentifier(double pass_ptr, double id)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);
   
   if (pass == NULL)
      return FALSE;

   pass->setIdentifier((Ogre::uint32)id);

   return TRUE;
}


GMFN double SetCompositionPassMaterial(double pass_ptr, char *mat_name)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setMaterialName(mat_name);

   return TRUE;
}


GMFN double SetCompositionPassFirstRenderQueue(double pass_ptr, double id)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setFirstRenderQueue((Ogre::uint8)id);

   return TRUE;
}


GMFN double SetCompositionPassLastRenderQueue(double pass_ptr, double id)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setLastRenderQueue((Ogre::uint8)id);

   return TRUE;
}


GMFN double SetCompositionPassClearBuffers(double pass_ptr, double val)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setClearBuffers((Ogre::uint32)val);

   return TRUE;
}


GMFN double SetCompositionPassClearDepth(double pass_ptr, double depth)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setClearDepth((Ogre::Real)depth);

   return TRUE;
}


GMFN double SetCompositionPassClearColor(double pass_ptr, double clr, double alpha)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setClearColour(Ogre::ColourValue(GetRedFromGMColor(clr), GetGreenFromGMColor(clr), GetBlueFromGMColor(clr), (float)alpha));

   return TRUE;
}


GMFN double SetCompositionPassClearStencil(double pass_ptr, double val)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setClearStencil((Ogre::uint32)val);

   return TRUE;
}


GMFN double EnableCompositionPassStencilCheck(double pass_ptr, double enable)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setStencilCheck((enable != 0));

   return TRUE;
}


GMFN double SetCompositionPassStencilFunction(double pass_ptr, double func)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setStencilFunc(static_cast<Ogre::CompareFunction>((int)func));

   return TRUE;
}


GMFN double SetCompositionPassStencilRefValue(double pass_ptr, double val)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setStencilRefValue((Ogre::uint32)val);

   return TRUE;
}


GMFN double SetCompositionPassStencilMask(double pass_ptr, double val)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setStencilMask((Ogre::uint32)val);

   return TRUE;
}


GMFN double SetCompositionPassStencilFailOperation(double pass_ptr, double op)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setStencilFailOp(static_cast<Ogre::StencilOperation>((int)op));

   return TRUE;
}


GMFN double SetCompositionPassStencilFailDepthOperation(double pass_ptr, double op)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setStencilDepthFailOp(static_cast<Ogre::StencilOperation>((int)op));

   return TRUE;
}


GMFN double SetCompositionPassStencilPassOperation(double pass_ptr, double op)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setStencilPassOp(static_cast<Ogre::StencilOperation>((int)op));

   return TRUE;
}


GMFN double EnableCompositionPassTwoSidedOperation(double pass_ptr, double enable)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setStencilTwoSidedOperation((enable != 0));

   return TRUE;
}


GMFN double SetCompositionPassInput(double pass_ptr, double id, char *tex_name, double mrt_index)
{
   Ogre::CompositionPass *pass = ConvertFromGMPointer<Ogre::CompositionPass *>(pass_ptr);

   if (pass == NULL)
      return FALSE;

   pass->setInput((size_t)id, tex_name, (size_t)mrt_index);

   return TRUE;
}

#endif
