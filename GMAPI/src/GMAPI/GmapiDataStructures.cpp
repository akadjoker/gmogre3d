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
  GmapiDataStructures.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiDataStructures.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  int ds_list_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_ds_list_create );
    GM_RETURN_INT;
  }

  void ds_list_destroy( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_list_destroy );
  }

  void ds_list_clear( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_list_clear );
  }

  void ds_list_copy( const int id, const int source ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source };

    GM_NORMAL_CALL( id_ds_list_copy );
  }

  int ds_list_size( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_list_size );
    GM_RETURN_INT;
  }

  bool ds_list_empty( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_list_empty );
    return ((int) result.real) & 1;
  }

  void ds_list_add( const int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val };

    GM_NORMAL_CALL( id_ds_list_add );
  }

  void ds_list_insert( const int id, const int pos, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, pos, val };

    GM_NORMAL_CALL( id_ds_list_insert );
  }

  void ds_list_replace( const int id, const int pos, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, pos, val };

    GM_NORMAL_CALL( id_ds_list_replace );
  }

  void ds_list_delete( const int id, const int pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, pos };

    GM_NORMAL_CALL( id_ds_list_delete );
  }

  int ds_list_find_index( const int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val };

    GM_NORMAL_CALL( id_ds_list_find_index );
    GM_RETURN_INT;
  }

  CGMVariable ds_list_find_value( const int id, const int pos ) {
    GM_VAR_RESULT;
    GM_ARGS{ id, pos };

    GM_NORMAL_CALL( id_ds_list_find_value );

    GM_RETURN_VAR;
  }

  void ds_list_sort( const int id, const bool ascend ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, ascend };

    GM_NORMAL_CALL( id_ds_list_sort );
  }

  void ds_list_shuffle( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_list_shuffle );
  }

  CGMVariable ds_list_write( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_list_write );

    GM_RETURN_VAR;
  }

  void ds_list_read( const int id, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, str };

    GM_NORMAL_CALL( id_ds_list_read );
  }

  int ds_stack_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_ds_stack_create );
    GM_RETURN_INT;
  }

  void ds_stack_destroy( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_stack_destroy );
  }

  void ds_stack_clear( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_stack_clear );
  }

  void ds_stack_copy( const int id, const int source ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source };

    GM_NORMAL_CALL( id_ds_stack_copy );
  }

  int ds_stack_size( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_stack_size );
    GM_RETURN_INT;
  }

  bool ds_stack_empty( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_stack_empty );
    return ((int) result.real) & 1;
  }

  void ds_stack_push( const int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val };

    GM_NORMAL_CALL( id_ds_stack_push );
  }

  CGMVariable ds_stack_pop( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_stack_pop );
    GM_RETURN_VAR;
  }

  CGMVariable ds_stack_top( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_stack_top );
    GM_RETURN_VAR;
  }

  CGMVariable ds_stack_write( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_stack_write );
    GM_RETURN_VAR;
  }

  void ds_stack_read( const int id, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, str };

    GM_NORMAL_CALL( id_ds_stack_read );
  }

  int ds_queue_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_ds_queue_create );
    GM_RETURN_INT;
  }

  void ds_queue_destroy( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_queue_destroy );
  }

  void ds_queue_clear( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_queue_clear );
  }

  void ds_queue_copy( const int id, const int source ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source };

    GM_NORMAL_CALL( id_ds_queue_copy );
  }

  int ds_queue_size( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_queue_size );
    GM_RETURN_INT;
  }

  bool ds_queue_empty( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_queue_empty );
    return ((int) result.real) & 1;
  }

  void ds_queue_enqueue( const int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val };

    GM_NORMAL_CALL( id_ds_queue_enqueue );
  }

  CGMVariable ds_queue_dequeue( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_queue_dequeue );
    GM_RETURN_VAR;
  }

  CGMVariable ds_queue_head( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_queue_head );
    GM_RETURN_VAR;
  }

  CGMVariable ds_queue_tail( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_queue_tail );
    GM_RETURN_VAR;
  }


  CGMVariable ds_queue_write( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_queue_write );
    GM_RETURN_VAR;
  }

  void ds_queue_read( const int id, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, str };

    GM_NORMAL_CALL( id_ds_queue_read );
  }

  int ds_map_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_ds_map_create );
    GM_RETURN_INT;
  }

  void ds_map_destroy( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_map_destroy );
  }

  void ds_map_clear( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_map_clear );
  }

  void ds_map_copy( const int id, const int source ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source };

    GM_NORMAL_CALL( id_ds_map_copy );
  }

  int ds_map_size( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_map_size );
    GM_RETURN_INT;
  }

  bool ds_map_empty( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_map_empty );
    return ((int) result.real) & 1;
  }

  void ds_map_add( const int id, const CGMVariable& key, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, key, val };

    GM_NORMAL_CALL( id_ds_map_add );
  }

  void ds_map_replace( const int id, const CGMVariable& key, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, key, val };

    GM_NORMAL_CALL( id_ds_map_replace );
  }

  void ds_map_delete( const int id, const CGMVariable& key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, key };

    GM_NORMAL_CALL( id_ds_map_delete );
  }

  void ds_map_exists( const int id, const CGMVariable& key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, key };

    GM_NORMAL_CALL( id_ds_map_exists );
  }

  CGMVariable ds_map_find_value( const int id, const CGMVariable& key ) {
    GM_VAR_RESULT;
    GM_ARGS{ id, key };

    GM_NORMAL_CALL( id_ds_map_find_value );
    GM_RETURN_VAR;
  }

  CGMVariable ds_map_find_previous( const int id, const CGMVariable& key ) {
    GM_VAR_RESULT;
    GM_ARGS{ id, key };

    GM_NORMAL_CALL( id_ds_map_find_previous );
    GM_RETURN_VAR;
  }

  CGMVariable ds_map_find_next( const int id, const CGMVariable& key ) {
    GM_VAR_RESULT;
    GM_ARGS{ id, key };

    GM_NORMAL_CALL( id_ds_map_find_next );
    GM_RETURN_VAR;
  }

  CGMVariable ds_map_find_first( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_map_find_first );
    GM_RETURN_VAR;
  }

  CGMVariable ds_map_find_last( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_map_find_last );
    GM_RETURN_VAR;
  }

  CGMVariable ds_map_write( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_map_write );

    GM_RETURN_VAR;
  }

  void ds_map_read( const int id, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, str };

    GM_NORMAL_CALL( id_ds_map_read );
  }

  int ds_priority_create() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_ds_priority_create );
    GM_RETURN_INT;
  }

  void ds_priority_destroy( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_destroy );
  }

  void ds_priority_clear( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_clear );
  }

  void ds_priority_copy( const int id, const int source ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source };

    GM_NORMAL_CALL( id_ds_priority_copy );
  }

  int ds_priority_size( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_size );
    GM_RETURN_INT;
  }

  bool ds_priority_empty( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_empty );
    return ((int) result.real) & 1;
  }

  void ds_priority_add( const int id, const CGMVariable& val, const int prio ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val, prio };

    GM_NORMAL_CALL( id_ds_priority_add );
  }

  void ds_priority_change_priority( const int id, const CGMVariable& val,
                                    const int prio ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val, prio };

    GM_NORMAL_CALL( id_ds_priority_change_priority );
  }

  int ds_priority_find_priority( const int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val };

    GM_NORMAL_CALL( id_ds_priority_find_priority );

    GM_RETURN_INT;
  }

  void ds_priority_delete_value( const int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val };

    GM_NORMAL_CALL( id_ds_priority_delete_value );
  }

  CGMVariable ds_priority_delete_min( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_delete_min );
    GM_RETURN_VAR;
  }

  CGMVariable ds_priority_find_min( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_find_min );
    GM_RETURN_VAR;
  }

  CGMVariable ds_priority_delete_max( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_delete_max );
    GM_RETURN_VAR;
  }

  CGMVariable ds_priority_find_max( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_find_max );
    GM_RETURN_VAR;
  }

  CGMVariable ds_priority_write( const int id ) {
    GM_VAR_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_priority_write );
    GM_RETURN_VAR;
  }

  void ds_priority_read( const int id, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, str };

    GM_NORMAL_CALL( id_ds_priority_read );
  }

  int ds_grid_create( const int w, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ w, h };

    GM_NORMAL_CALL( id_ds_grid_create );
    GM_RETURN_INT;
  }

  void ds_grid_delete( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_grid_delete );
  }

  void ds_grid_copy( const int id, const int source ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source };

    GM_NORMAL_CALL( id_ds_grid_copy );
  }

  void ds_grid_resize( const int id, const int w, const int h ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, w, h };

    GM_NORMAL_CALL( id_ds_grid_resize );
  }

  int ds_grid_width( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_grid_width );
    GM_RETURN_INT;
  }

  int ds_grid_height( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_grid_height );
    GM_RETURN_INT;
  }

  void ds_grid_clear( const int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, val };

    GM_NORMAL_CALL( id_ds_grid_clear );
  }

  void ds_grid_set( const int id, const int x, const int y, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, val };

    GM_NORMAL_CALL( id_ds_grid_set );
  }

  void ds_grid_add( const int id, const int x, const int y, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, val };

    GM_NORMAL_CALL( id_ds_grid_add );
  }

  void ds_grid_multiply( const int id, const int x, const int y, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x, y, val };

    GM_NORMAL_CALL( id_ds_grid_multiply );
  }

  void ds_grid_set_region( const int id, const int x1, const int y1, const int x2,
                           const int y2, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2, val };

    GM_NORMAL_CALL( id_ds_grid_set_region );
  }

  void ds_grid_add_region( const int id, const int x1, const int y1, const int x2,
                           const int y2, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2, val };

    GM_NORMAL_CALL( id_ds_grid_add_region );
  }

  void ds_grid_multiply_region( const int id, const int x1, const int y1, const int x2,
                                const int y2, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2, val };

    GM_NORMAL_CALL( id_ds_grid_multiply_region );
  }

  void ds_grid_set_disk( const int id, const int xm, const int ym, const int r,
                         const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r, val };

    GM_NORMAL_CALL( id_ds_grid_set_disk );
  }

  void ds_grid_add_disk( const int id, const int xm, const int ym, const int r,
                         const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r, val };

    GM_NORMAL_CALL( id_ds_grid_add_disk );
  }

  void ds_grid_multiply_disk( const int id, const int xm, const int ym, const int r,
                         const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r, val };

    GM_NORMAL_CALL( id_ds_grid_multiply_disk );
  }

  void ds_grid_set_grid_region( const int id, const int source, const int x1, const int y1,
                                const int x2, const int y2, const int xpos, const int ypos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source, x1, y1, x2, y2, xpos, ypos };

    GM_NORMAL_CALL( id_ds_grid_set_grid_region );
  }

  void ds_grid_add_grid_region( const int id, const int source, const int x1, const int y1,
                                const int x2, const int y2, const int xpos, const int ypos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source, x1, y1, x2, y2, xpos, ypos };

    GM_NORMAL_CALL( id_ds_grid_add_grid_region );
  }

  void ds_grid_multiply_grid_region( const int id, const int source, const int x1, const int y1,
                                     const int x2, const int y2, const int xpos, const int ypos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, source, x1, y1, x2, y2, xpos, ypos };

    GM_NORMAL_CALL( id_ds_grid_multiply_grid_region );
  }

  CGMVariable ds_grid_get( const int id, const int x, const int y ) {
    GM_VAR_RESULT;
    GM_ARGS{ id, x, y };

    GM_NORMAL_CALL( id_ds_grid_get );
    GM_RETURN_VAR;
  }

  double ds_grid_get_sum( const int id, const int x1, const int y1, const int x2,
                          const int y2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2 };

    GM_NORMAL_CALL( id_ds_grid_get_sum );
    GM_RETURN_REAL;
  }

  double ds_grid_get_max( const int id, const int x1, const int y1, const int x2,
                          const int y2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2 };

    GM_NORMAL_CALL( id_ds_grid_get_max );
    GM_RETURN_REAL;
  }

  double ds_grid_get_min( const int id, const int x1, const int y1, const int x2,
                          const int y2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2 };

    GM_NORMAL_CALL( id_ds_grid_get_min );
    GM_RETURN_REAL;
  }

  double ds_grid_get_mean( const int id, const int x1, const int y1, const int x2,
                           const int y2 ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2 };

    GM_NORMAL_CALL( id_ds_grid_get_mean );
    GM_RETURN_REAL;
  }

  double ds_grid_get_disk_sum( const int id, const int xm, const int ym, const int r ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r };

    GM_NORMAL_CALL( id_ds_grid_get_disk_sum );
    GM_RETURN_REAL;
  }

  double ds_grid_get_disk_min( const int id, const int xm, const int ym, const int r ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r };

    GM_NORMAL_CALL( id_ds_grid_get_disk_min );
    GM_RETURN_REAL;
  }

  double ds_grid_get_disk_max( const int id, const int xm, const int ym, const int r ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r };

    GM_NORMAL_CALL( id_ds_grid_get_disk_max );
    GM_RETURN_REAL;
  }

  double ds_grid_get_disk_mean( const int id, const int xm, const int ym, const int r ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r };

    GM_NORMAL_CALL( id_ds_grid_get_disk_mean );
    GM_RETURN_REAL;
  }

  bool ds_grid_value_exists( const int id, const int x1, const int y1, const int x2,
                             const int y2, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2, val };

    GM_NORMAL_CALL( id_ds_grid_value_exists );
    GM_RETURN_BOOL;
  }

  int ds_grid_value_x( const int id, const int x1, const int y1, const int x2,
                       const int y2, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2, val };

    GM_NORMAL_CALL( id_ds_grid_value_x );
    GM_RETURN_INT;
  }

  int ds_grid_value_y( const int id, const int x1, const int y1, const int x2,
                       const int y2, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, x1, y1, x2, y2, val };

    GM_NORMAL_CALL( id_ds_grid_value_y );
    GM_RETURN_INT;
  }

  bool ds_grid_value_disk_exists( const int id, const int xm, const int ym, const int r,
                                  const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r, val };

    GM_NORMAL_CALL( id_ds_grid_value_disk_exists );
    GM_RETURN_BOOL;
  }

  int ds_grid_value_disk_x( const int id, const int xm, const int ym, const int r,
                             const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r, val };

    GM_NORMAL_CALL( id_ds_grid_value_disk_x );
    GM_RETURN_INT;
  }

  int ds_grid_value_disk_y( const int id, const int xm, const int ym, const int r,
                             const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, xm, ym, r, val };

    GM_NORMAL_CALL( id_ds_grid_value_disk_y );
    GM_RETURN_INT;
  }

  void ds_grid_shuffle( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_grid_shuffle );
  }

  void ds_grid_write( const int id ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id };

    GM_NORMAL_CALL( id_ds_grid_write );
  }

  void ds_grid_read( const int id, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ id, str };

    GM_NORMAL_CALL( id_ds_grid_read );
  }

  void ds_set_precision( const double prec ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ prec };

    GM_NORMAL_CALL( id_ds_set_precision );
  }

}