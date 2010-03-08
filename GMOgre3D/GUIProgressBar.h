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

#ifndef GMOGRE_GUI_PROGRESS_BAR_H
#define GMOGRE_GUI_PROGRESS_BAR_H

#include "GMOgre3D.h"
#include <GMAPI.h>

// CEGUI includes
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIProgressBar.h"


GMFN double SetGUIProgressBarCurrentProgress(double gui_progress_bar_ptr, double progress)
{
   CEGUI::ProgressBar *progress_bar = ConvertFromGMPointer<CEGUI::ProgressBar*>(gui_progress_bar_ptr);

   if (progress_bar == NULL)
      return FALSE;

   progress_bar->setProgress(progress);

   return TRUE;
}


GMFN double GetGUIProgressBarCurrentProgress(double gui_progress_bar_ptr)
{
   CEGUI::ProgressBar *progress_bar = ConvertFromGMPointer<CEGUI::ProgressBar*>(gui_progress_bar_ptr);

   if (progress_bar == NULL)
      return 0;

   return progress_bar->getProgress();
}


GMFN double StepGUIProgressBar(double gui_progress_bar_ptr)
{
   CEGUI::ProgressBar *progress_bar = ConvertFromGMPointer<CEGUI::ProgressBar*>(gui_progress_bar_ptr);

   if (progress_bar == NULL)
      return FALSE;

   progress_bar->step();

   return TRUE;
}


GMFN double SetGUIProgressBarStepSize(double gui_progress_bar_ptr, double step)
{
   CEGUI::ProgressBar *progress_bar = ConvertFromGMPointer<CEGUI::ProgressBar*>(gui_progress_bar_ptr);

   if (progress_bar == NULL)
      return FALSE;

   progress_bar->setStepSize(step);

   return TRUE;
}

#endif
