/************************************************************************** 
  LICENSE:

    GMAPI is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    GMAPI is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with GMAPI; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301 USA
***************************************************************************/

/*************************************************************************
  GmapiDataStructures.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  void ds_set_precision( const double prec );

  int ds_list_create();
  void ds_list_destroy( const int id );

  void ds_list_clear( const int id );
  void ds_list_copy( const int id, const int source );
  int ds_list_size( const int id );
  bool ds_list_empty( const int id );

  void ds_list_add( const int id, const CGMVariable& val );
  void ds_list_insert( const int id, const int pos, const CGMVariable& val );
  void ds_list_replace( const int id, const int pos, const CGMVariable& val );
  void ds_list_delete( const int id, const int pos );

  int ds_list_find_index( const int id, const CGMVariable& val );
  CGMVariable ds_list_find_value( const int id, const int pos );

  void ds_list_sort( const int id, const int ascend );
  void ds_list_shuffle( const int id );

  CGMVariable ds_list_write( const int id );
  void ds_list_read( const int id, const CGMVariable& str );

  int ds_stack_create();
  void ds_stack_destroy( const int id );
  void ds_stack_clear( const int id );
  void ds_stack_copy( const int id, const int source );
  int ds_stack_size( const int id );
  bool ds_stack_empty( const int id );
  void ds_stack_push( const int id, const CGMVariable& val );
  CGMVariable ds_stack_pop( const int id );
  CGMVariable ds_stack_top( const int id );
  CGMVariable ds_stack_write( const int id );
  void ds_stack_read( const int id, const CGMVariable& str );

  int ds_queue_create();
  void ds_queue_destroy( const int id );
  void ds_queue_clear( const int id );
  void ds_queue_copy( const int id, const int source );
  int ds_queue_size( const int id );
  bool ds_queue_empty( const int id );
  void ds_queue_enqueue( const int id, const CGMVariable& val );
  CGMVariable ds_queue_dequeue( const int id );
  CGMVariable ds_queue_head( const int id );
  CGMVariable ds_queue_tail( const int id );
  CGMVariable ds_queue_write( const int id );
  void ds_queue_read( const int id, const CGMVariable& str );

  int ds_map_create();
  void ds_map_destroy( const int id );
  void ds_map_clear( const int id );
  void ds_map_copy( const int id, const int source );
  int ds_map_size( const int id );
  bool ds_map_empty( const int id );
  void ds_map_add( const int id, const CGMVariable& key, const CGMVariable& val );
  void ds_map_replace( const int id, const CGMVariable& key, const CGMVariable& val );
  void ds_map_delete( const int id, const CGMVariable& key );
  void ds_map_exists( const int id, const CGMVariable& key );
  CGMVariable ds_map_find_value( const int id, const CGMVariable& key );
  CGMVariable ds_map_find_previous( const int id, const CGMVariable& key );
  CGMVariable ds_map_find_next( const int id, const CGMVariable& key );
  CGMVariable ds_map_find_first( const int id );
  CGMVariable ds_map_find_last( const int id );
  CGMVariable ds_map_write( const int id );
  void ds_map_read( const int id, const CGMVariable& str );

  int ds_priority_create();
  void ds_priority_destroy( const int id );
  void ds_priority_clear( const int id );
  void ds_priority_copy( const int id, const int source );
  int ds_priority_size( const int id );
  bool ds_priority_empty( const int id );
  void ds_priority_add( const int id, const CGMVariable& val, const int prio );
  void ds_priority_change_priority( const int id, const CGMVariable& val,
                                    const int prio );
  int ds_priority_find_priority( const int id, const CGMVariable& val );
  void ds_priority_delete_value( const int id, const CGMVariable& val );
  CGMVariable ds_priority_delete_min( const int id );
  CGMVariable ds_priority_find_min( const int id );
  CGMVariable ds_priority_delete_max( const int id );
  CGMVariable ds_priority_find_max( const int id );
  CGMVariable ds_priority_write( const int id );
  void ds_priority_read( const int id, const CGMVariable& str );

  int ds_grid_create( const int w, const int h );
  void ds_grid_delete( const int id );
  void ds_grid_copy( const int id, const int source );
  void ds_grid_resize( const int id, const int w, const int h );
  int ds_grid_width( const int id );
  int ds_grid_height( const int id );
  void ds_grid_clear( const int id, const CGMVariable& val );
  void ds_grid_set( const int id, const int x, const int y, const CGMVariable& val );
  void ds_grid_add( const int id, const int x, const int y, const CGMVariable& val );
  void ds_grid_multiply( const int id, const int x, const int y, const CGMVariable& val );
  void ds_grid_set_region( const int id, const int x1, const int y1, const int x2,
                           const int y2, const CGMVariable& val );
  void ds_grid_add_region( const int id, const int x1, const int y1, const int x2,
                           const int y2, const CGMVariable& val );
  void ds_grid_multiply_region( const int id, const int x1, const int y1, const int x2,
                                const int y2, const CGMVariable& val );
  void ds_grid_set_disk( const int id, const int xm, const int ym, const int r,
                         const CGMVariable& val );
  void ds_grid_add_disk( const int id, const int xm, const int ym, const int r,
                         const CGMVariable& val );
  void ds_grid_multiply_disk( const int id, const int xm, const int ym, const int r,
                         const CGMVariable& val );
  void ds_grid_set_grid_region( const int id, const int source, const int x1, const int y1,
                                const int x2, const int y2, const int xpos, const int ypos );
  void ds_grid_add_grid_region( const int id, const int source, const int x1, const int y1,
                                const int x2, const int y2, const int xpos, const int ypos );
  void ds_grid_multiply_grid_region( const int id, const int source, const int x1, const int y1,
                                     const int x2, const int y2, const int xpos, const int ypos );
  CGMVariable ds_grid_get( const int id, const int x, const int y );
  double ds_grid_get_sum( const int id, const int x1, const int y1, const int x2,
                          const int y2 );
  double ds_grid_get_max( const int id, const int x1, const int y1, const int x2,
                          const int y2 );
  double ds_grid_get_min( const int id, const int x1, const int y1, const int x2,
                          const int y2 );
  double ds_grid_get_mean( const int id, const int x1, const int y1, const int x2,
                           const int y2 );
  double ds_grid_get_disk_sum( const int id, const int xm, const int ym, const int r );
  double ds_grid_get_disk_min( const int id, const int xm, const int ym, const int r );
  double ds_grid_get_disk_max( const int id, const int xm, const int ym, const int r );
  double ds_grid_get_disk_mean( const int id, const int xm, const int ym, const int r );
  double ds_grid_get_min( const int id, const int x1, const int y1, const int x2,
                          const int y2 );
  bool ds_grid_value_exists( const int id, const int x1, const int y1, const int x2,
                             const int y2, const CGMVariable& val );
  int ds_grid_value_x( const int id, const int x1, const int y1, const int x2,
                       const int y2, const CGMVariable& val );
  int ds_grid_value_y( const int id, const int x1, const int y1, const int x2,
                       const int y2, const CGMVariable& val );
  bool ds_grid_value_disk_exists( const int id, const int xm, const int ym, const int r,
                                  const CGMVariable& val );
  int ds_grid_value_disk_x( const int id, const int xm, const int ym, const int r,
                            const CGMVariable& val );
  int ds_grid_value_disk_y( const int id, const int xm, const int ym, const int r,
                            const CGMVariable& val );
  void ds_grid_shuffle( const int id );
  void ds_grid_write( const int id );
  void ds_grid_read( const int id, const CGMVariable& str );

}
