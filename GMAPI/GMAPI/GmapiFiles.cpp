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
  GmapiFiles.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiFiles.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  int file_text_open_read( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_file_text_open_read );
    GM_RETURN_INT;
  }

  int file_text_open_write( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_file_text_open_write );
    GM_RETURN_INT;
  }

  int file_text_open_append( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_file_text_open_append );
    GM_RETURN_INT;
  }

  void file_text_close( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_text_close );
  }

  void file_text_write_string( int fileid, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid, str };

    GM_NORMAL_CALL( id_file_text_write_string );
  }

  void file_text_write_real( int fileid, double x ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid, x };

    GM_NORMAL_CALL( id_file_text_write_real );
  }

  void file_text_writeln( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_text_writeln );
  }

  CGMVariable file_text_read_string( int fileid ) {
    GM_VAR_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_text_read_string );
    GM_RETURN_VAR;
  }

  double file_text_read_real( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_text_read_real );
    GM_RETURN_REAL;
  }

  void file_text_readln( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_text_readln );
  }

  bool file_text_eof( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_text_eof );
    GM_RETURN_BOOL;
  }

  bool file_text_eoln( int file ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ file };

    GM_NORMAL_CALL( id_file_text_eoln );
    GM_RETURN_BOOL;
  }

  bool file_exists( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_file_exists );
    GM_RETURN_BOOL;
  }

  void file_delete( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_file_delete );
  }

  void file_rename( const CGMVariable& oldname, const CGMVariable& newname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ oldname, newname };

    GM_NORMAL_CALL( id_file_rename );
  }

  void file_copy( const CGMVariable& fname, const CGMVariable& newname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, newname };

    GM_NORMAL_CALL( id_file_copy );
  }

  bool directory_exists( const CGMVariable& dname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dname };

    GM_NORMAL_CALL( id_directory_exists );
    GM_RETURN_BOOL;
  }

  void directory_create( const CGMVariable& dname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dname };

    GM_NORMAL_CALL( id_directory_create );
  }

  CGMVariable file_find_first( const CGMVariable& mask, int attr ) {
    GM_VAR_RESULT;
    GM_ARGS{ mask, attr };

    GM_NORMAL_CALL( id_file_find_first );
    GM_RETURN_VAR;
  }

  CGMVariable file_find_next() {
    GM_VAR_RESULT;

    GM_VOID_CALL( id_file_find_next );
    GM_RETURN_VAR;
  }

  void file_find_close() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_file_find_close );
  }

  bool file_attributes( const CGMVariable& fname, int attr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, attr };

    GM_NORMAL_CALL( id_file_attributes );
    GM_RETURN_BOOL;
  }

  CGMVariable filename_name( const CGMVariable& fname ) {
    GM_VAR_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_filename_name );
    GM_RETURN_VAR;
  }

  CGMVariable filename_path( const CGMVariable& fname ) {
    GM_VAR_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_filename_path );
    GM_RETURN_VAR;
  }

  CGMVariable filename_dir( const CGMVariable& fname ) {
    GM_VAR_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_filename_dir );
    GM_RETURN_VAR;
  }

  CGMVariable filename_drive( const CGMVariable& fname ) {
    GM_VAR_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_filename_drive );
    GM_RETURN_VAR;
  }

  CGMVariable filename_ext( const CGMVariable& fname ) {
    GM_VAR_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_filename_ext );
    GM_RETURN_VAR;
  }

  CGMVariable filename_change_ext( const CGMVariable& fname, const CGMVariable& newext ) {
    GM_VAR_RESULT;
    GM_ARGS{ fname, newext };

    GM_NORMAL_CALL( id_filename_change_ext );
    GM_RETURN_VAR;
  }

  int file_bin_open( const CGMVariable& fname, int mod ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, mod };

    GM_NORMAL_CALL( id_file_bin_open );
    GM_RETURN_INT;
  }

  void file_bin_rewrite( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_bin_rewrite );
  }

  void file_bin_close( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_bin_close );
  }

  int file_bin_size( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_bin_size );
    GM_RETURN_INT;
  }

  int file_bin_position( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_bin_position );
    GM_RETURN_INT;
  }

  void file_bin_seek( int fileid, int pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid, pos };

    GM_NORMAL_CALL( id_file_bin_seek );
  }

  void file_bin_write_byte( int fileid, int byte ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid, byte };

    GM_NORMAL_CALL( id_file_bin_write_byte );
  }

  int file_bin_read_byte( int fileid ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fileid };

    GM_NORMAL_CALL( id_file_bin_read_byte );
    GM_RETURN_INT;
  }

  void export_include_file( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_export_include_file );
  }

  void export_include_file_location( const CGMVariable& fname, const CGMVariable& location ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname, location };

    GM_NORMAL_CALL( id_export_include_file_location );
  }

  void discard_include_file( const CGMVariable& fname ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ fname };

    GM_NORMAL_CALL( id_discard_include_file );
  }

  int parameter_count() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_parameter_count );
    GM_RETURN_INT;
  }

  CGMVariable parameter_string( int n ) {
    GM_VAR_RESULT;
    GM_ARGS{ n };

    GM_NORMAL_CALL( id_parameter_string );
    GM_RETURN_VAR;
  }

  CGMVariable environment_get_variable( const CGMVariable& name ) {
    GM_VAR_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_environment_get_variable );
    GM_RETURN_VAR;
  }

  double disk_size( const CGMVariable& drive ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ drive };

    GM_NORMAL_CALL( id_disk_size );
    GM_RETURN_REAL;
  }

  double disk_free( const CGMVariable& drive ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ drive };

    GM_NORMAL_CALL( id_disk_free );
    GM_RETURN_REAL;
  }

  void registry_write_string( const CGMVariable& name, const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, str };

    GM_NORMAL_CALL( id_registry_write_string );
  }

  void registry_write_real( const CGMVariable& name, double x ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name, x };

    GM_NORMAL_CALL( id_registry_write_real );
  }

  CGMVariable registry_read_string( const CGMVariable& name ) {
    GM_VAR_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_registry_read_string );
    GM_RETURN_VAR;
  }

  double registry_read_real( const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_registry_read_real );
    GM_RETURN_REAL;
  }

  bool registry_exists( const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_registry_exists );
    GM_RETURN_BOOL;
  }

  void registry_write_string_ext( const CGMVariable& key, const CGMVariable& name,
                                  const CGMVariable& str ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key, name, str };

    GM_NORMAL_CALL( id_registry_write_string_ext );
  }

  void registry_write_real_ext( const CGMVariable& key, const CGMVariable& name, double x ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key, name, x };

    GM_NORMAL_CALL( id_registry_write_real_ext );
  }

  CGMVariable registry_read_string_ext( const CGMVariable& key, const CGMVariable& name ) {
    GM_VAR_RESULT;
    GM_ARGS{ key, name };

    GM_NORMAL_CALL( id_registry_read_string_ext );
    GM_RETURN_VAR;
  }

  double registry_read_real_ext( const CGMVariable& key, const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key, name };

    GM_NORMAL_CALL( id_registry_read_real_ext );
    GM_RETURN_REAL;
  }

  bool registry_exists_ext( const CGMVariable& key, const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ key, name };

    GM_NORMAL_CALL( id_registry_exists_ext );
    GM_RETURN_BOOL;
  }

  void registry_set_root( int root ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ root };

    GM_NORMAL_CALL( id_registry_set_root );
  }

  void ini_open( const CGMVariable& name ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ name };

    GM_NORMAL_CALL( id_ini_open );
  }

  void ini_close() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_ini_close );
  }

  CGMVariable ini_read_string( const CGMVariable& section, const CGMVariable& key,
                               const CGMVariable& default_ ) {
    GM_VAR_RESULT;
    GM_ARGS{ section, key, default_ };

    GM_NORMAL_CALL( id_ini_read_string );
    GM_RETURN_VAR;
  }

  double ini_read_real( const CGMVariable& section, const CGMVariable& key,
                        double default_ ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ section, key, default_ };

    GM_NORMAL_CALL( id_ini_read_real );
    GM_RETURN_REAL;
  }

  void ini_write_string( const CGMVariable& section, const CGMVariable& key,
                         const CGMVariable& value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ section, key, value };

    GM_NORMAL_CALL( id_ini_write_string );
  }

  void ini_write_real( const CGMVariable& section, const CGMVariable& key, double value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ section, key, value };

    GM_NORMAL_CALL( id_ini_write_real );
  }

  bool ini_key_exists( const CGMVariable& section, const CGMVariable& key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ section, key };

    GM_NORMAL_CALL( id_ini_key_exists );
    GM_RETURN_BOOL;
  }

  bool ini_section_exists( const CGMVariable& section ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ section };

    GM_NORMAL_CALL( id_ini_section_exists );
    GM_RETURN_BOOL;
  }

  void ini_key_delete( const CGMVariable& section, const CGMVariable& key ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ section, key };

    GM_NORMAL_CALL( id_ini_key_delete );
  }

  void ini_section_delete( const CGMVariable& section ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ section };

    GM_NORMAL_CALL( id_ini_section_delete );
  }

  void execute_program( const CGMVariable& prog, const CGMVariable& arg, bool wait ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ prog, arg, wait };

    GM_NORMAL_CALL( id_execute_program );
  }

  void execute_shell( const CGMVariable& prog, const CGMVariable& arg ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ prog, arg };

    GM_NORMAL_CALL( id_execute_shell );
  }

}