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

#ifndef GMOGRE_SPRITE_H
#define GMOGRE_SPRITE_H

#include "GMOgre3D.h"


GMFN double CreateSprite(char *mat_name, double width, double height, double metrics)
{
   OgreSprite *sprite = NULL;
   
   TRY
      sprite = OGRE_NEW OgreSprite;

      sprite->SetMaterial(mat_name);
      sprite->SetMetrics(metrics);
      sprite->SetDimensions(width, height);
   CATCH("CreateSprite")

   return ConvertToGMPointer(sprite);
}


GMFN double DestroySprite(double sprite_ptr)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   delete sprite;

   return TRUE;
}


GMFN double SetSpriteMaterial(double sprite_ptr, char *mat_name)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   sprite->SetMaterial(mat_name);

   return TRUE;
}


GMFN double SetSpriteMetrics(double sprite_ptr, double type)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   sprite->SetMetrics(type);

   return TRUE;
}


GMFN double SetSpriteDimensions(double sprite_ptr, double width, double height)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   sprite->SetDimensions(width, height);

   return TRUE;
}


GMFN double SetSpritePosition(double sprite_ptr, double x, double y)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   sprite->SetPosition(x, y);

   return TRUE;
}


GMFN double SetSpriteScale(double sprite_ptr, double x, double y)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   sprite->SetScale(x, y);

   return TRUE;
}


GMFN double RotateSprite(double sprite_ptr, double degrees)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   sprite->Rotate(degrees);

   return TRUE;
}


GMFN double ShowSprite(double sprite_ptr)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   sprite->Show();

   return TRUE;
}


GMFN double HideSprite(double sprite_ptr)
{
   OgreSprite *sprite = ConvertFromGMPointer<OgreSprite*>(sprite_ptr);

   if (sprite == NULL)
      return FALSE;

   sprite->Hide();

   return TRUE;
}

#endif
