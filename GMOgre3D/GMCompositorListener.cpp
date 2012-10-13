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

#include "stdafx.h"
#include "GMCompositorListener.h"
#include "GM_API.h"


GMCompositorListener::GMCompositorListener()
:  mNotifyMaterialSetupCallback(-1),
   mNotifyMaterialRenderCallback(-1)
{
}


void GMCompositorListener::notifyMaterialSetup(Ogre::uint32 pass_id, Ogre::MaterialPtr &mat)
{
   // Call our GM script to handle this callback
   if (mNotifyMaterialSetupCallback >= 0)
   {
      GM_script_execute(mNotifyMaterialSetupCallback, (double)pass_id, mat->getName());
   }
}


void GMCompositorListener::notifyMaterialRender(Ogre::uint32 pass_id, Ogre::MaterialPtr &mat)
{
   // Call our GM script to handle this callback
   if (mNotifyMaterialRenderCallback >= 0)
   {
      GM_script_execute(mNotifyMaterialRenderCallback, (double)pass_id, mat->getName());
   }
}


void GMCompositorListener::SetNotifyMaterialSetupCallback(int func)
{
   mNotifyMaterialSetupCallback = func;
}


void GMCompositorListener::SetNotifyMaterialRenderCallback(int func)
{
   mNotifyMaterialRenderCallback = func;
}
