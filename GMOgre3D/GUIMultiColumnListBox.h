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

#ifndef GMOGRE_GUI_MULTI_COLUMN_LIST_BOX_H
#define GMOGRE_GUI_MULTI_COLUMN_LIST_BOX_H

#include "GMOgre3D.h"
#include "GM_API.h"

// CEGUI includes
#include "GUIWindow.h"
#include "CEGUIInputEvent.h"
#include "CEGUIWindow.h"
#include "CEGUIWindowManager.h"
#include "CEGUISchemeManager.h"
#include "CEGUIFontManager.h"
#include "elements/CEGUIMultiColumnList.h"
#include "elements/CEGUIListBoxTextItem.h"


GMFN double AddGUIMultiColumnListBoxColumn(double gui_list_box_ptr, char *text, double width)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(list_box);
   if (data == NULL)
      return FALSE;

   if (data->m_metrics_mode == Ogre::GMM_RELATIVE)
      list_box->addColumn(text, list_box->getColumnCount(), cegui_reldim(width));
   else
      list_box->addColumn(text, list_box->getColumnCount(), cegui_absdim(width));

   return TRUE;
}


GMFN double RemoveGUIMultiColumnListBoxColumn(double gui_list_box_ptr, double index)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->removeColumn(index);

   return TRUE;
}


GMFN double AddGUIMultiColumnListBoxRow(double gui_list_box_ptr, double row_id)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   list_box->addRow(row_id);

   return (list_box->getRowCount() - 1);
}


GMFN double RemoveGUIMultiColumnListBoxRow(double gui_list_box_ptr, double index)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->removeRow(index);

   return TRUE;
}


GMFN double GetGUIMultiColumnListBoxRowID(double gui_list_box_ptr, double index)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return 0;

   return list_box->getRowID(index);
}


GMFN double GetGUIMultiColumnListBoxIndexFromID(double gui_list_box_ptr, double row_id)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   return list_box->getRowWithID(row_id);
}


GMFN double SetGUIMultiColumnListBoxRowText(double gui_list_box_ptr, double row_index, char *text, double column_index)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   CEGUI::ListboxTextItem *item = OGRE_NEW CEGUI::ListboxTextItem(text, 0, 0, false, true);

   OgreCEGUIWindowData *data = (OgreCEGUIWindowData *)list_box->getUserData();
   
   if (data != NULL)
   {
      if (!data->m_selection_brush_imageset.empty() && !data->m_selection_brush_image.empty())
         item->setSelectionBrushImage(data->m_selection_brush_imageset, data->m_selection_brush_image);
   }

   list_box->setItem(item, CEGUI::MCLGridRef(row_index, column_index));

   return TRUE;
}


GMFN double GetGUIMultiColumnListBoxRowCount(double gui_list_box_ptr)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return 0;

   return list_box->getRowCount();
}


GMFN double ClearGUIMultiColumnListBoxRows(double gui_list_box_ptr)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->resetList();

   return TRUE;
}


GMFN double ClearGUIMultiColumnListBoxSelections(double gui_list_box_ptr)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->clearAllSelections();

   return TRUE;
}


GMFN double GetGUIMultiColumnListBoxSelectedCount(double gui_list_box_ptr)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   return list_box->getSelectedCount();
}


GMFN double IsGUIMultiColumnListBoxRowSelected(double gui_list_box_ptr, double index)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   return list_box->isItemSelected(CEGUI::MCLGridRef(index, 0));
}


GMFN double GetGUIMultiColumnListBoxFirstSelectedRow(double gui_list_box_ptr)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   for (size_t x = 0; x < list_box->getRowCount(); x++)
      if (list_box->isItemSelected(CEGUI::MCLGridRef(x, 0)))
         return x;

   return -1;
}


GMFN double GetGUIMultiColumnListBoxNextSelectedRow(double gui_list_box_ptr, double index)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return -1;

   for (size_t x = index + 1; x < list_box->getRowCount(); x++)
      if (list_box->isItemSelected(CEGUI::MCLGridRef(x, 0)))
         return x;

   return -1;
}


GMFN double SelectGUIMultiColumnListBoxRow(double gui_list_box_ptr, double index, double select)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->setItemSelectState(CEGUI::MCLGridRef(index, 0), (select != 0));

   return TRUE;
}


GMFN double EnableGUIMultiColumnListBoxColumnDragging(double gui_list_box_ptr, double enable)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->setUserColumnDraggingEnabled((enable != 0));

   return TRUE;
}


GMFN double EnableGUIMultiColumnListBoxColumnSizing(double gui_list_box_ptr, double enable)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->setUserColumnSizingEnabled((enable != 0));

   return TRUE;
}


GMFN double EnableGUIMultiColumnListBoxUserSorting(double gui_list_box_ptr, double enable)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->setUserSortControlEnabled((enable != 0));

   return TRUE;
}


GMFN double SetGUIMultiColumnListBoxSelectionBrushImage(double gui_list_box_ptr, char *imageset, char *image)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(list_box);

   if (data != NULL)
   {
      data->m_selection_brush_imageset = imageset;
      data->m_selection_brush_image = image;

      for (size_t x = 0; x < list_box->getRowCount(); x++)
      {
         for (size_t y = 0; y < list_box->getColumnCount(); y++)
         {
            CEGUI::ListboxItem *item = list_box->getItemAtGridReference(CEGUI::MCLGridRef(x, y));
            if (item != NULL)
               item->setSelectionBrushImage(data->m_selection_brush_imageset, data->m_selection_brush_image);
         }
      }
   }

   return TRUE;
}


GMFN double SetGUIMultiColumnListBoxSelectionMode(double gui_list_box_ptr, double type)
{
   CEGUI::MultiColumnList *list_box = ConvertFromGMPointer<CEGUI::MultiColumnList*>(gui_list_box_ptr);

   if (list_box == NULL)
      return FALSE;

   list_box->setSelectionMode(static_cast<CEGUI::MultiColumnList::SelectionMode>((int)type));

   return TRUE;
}


bool PerformMultiColumnListBoxWindowEventCallback(const CEGUI::WindowEventArgs& args, CEGUI::String event_name)
{
   OgreCEGUIWindowData *data = GetGUIWindowData(args.window);
   if (data == NULL)
      return FALSE;

   std::map<std::string, int>::iterator iter = data->m_callback_map.find(std::string(event_name.c_str()));

   if (iter == data->m_callback_map.end())
      return false;

   // Call our GM script to handle this event
   GM_VALUE ret = GM_script_execute(iter->second, static_cast<double>(reinterpret_cast<intptr_t>(args.window)));

   return (GetGMRealValue(ret) != 0);
}


bool EventMultiColumnListBoxSelectionChanged(const CEGUI::EventArgs &args) { return PerformMultiColumnListBoxWindowEventCallback(static_cast<const CEGUI::WindowEventArgs&>(args), CEGUI::MultiColumnList::EventSelectionChanged); }


GMFN double SetGUIMultiColumnListBoxEventCallback(double gui_window_ptr, char *event_name, double func)
{
   CEGUI::Window *win = ConvertFromGMPointer<CEGUI::Window*>(gui_window_ptr);

   if (win == NULL)
      return FALSE;

   OgreCEGUIWindowData *data = GetGUIWindowData(win);
   if (data == NULL)
      return FALSE;

   data->m_callback_map[std::string(event_name)] = func;

   CEGUI::String evt_name = event_name;

   if (evt_name == CEGUI::MultiColumnList::EventSelectionChanged)
      win->subscribeEvent(event_name, CEGUI::Event::Subscriber(&EventMultiColumnListBoxSelectionChanged));

   return TRUE;
}

#endif
