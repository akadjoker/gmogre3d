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
#include "ResourceListener.h"
//#include "GMOgre3D.h"
#include "GMAPI.h"


GMResourceListener::GMResourceListener()
:  mResourceOperationCompletedCallback(-1)
{
}


void GMResourceListener::operationCompleted(Ogre::BackgroundProcessTicket ticket, const Ogre::BackgroundProcessResult &result)
{
   // Call our GM script to handle this callback
   if (mResourceOperationCompletedCallback >= 0)
   {
      gm::CGMVariable args[2];
      args[0].Set(result.error);
      args[1].Set(result.message.c_str());

      gm::CGMVariable &ret = gm::script_execute(mResourceOperationCompletedCallback, args, 2);  
   }
}


void GMResourceListener::SetResourceOperationCompleted(int func)
{
   mResourceOperationCompletedCallback = func;
}
