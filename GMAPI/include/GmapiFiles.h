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
  GmapiFiles.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  int file_text_open_read( const CGMVariable& fname );
  int file_text_open_write( const CGMVariable& fname );
  int file_text_open_append( const CGMVariable& fname );
  void file_text_close( const int fileid );
  void file_text_write_string( const int fileid, const CGMVariable& str );
  void file_text_write_real( const int fileid, const double x );
  void file_text_writeln( const int fileid );
  CGMVariable file_text_read_string( const int fileid );
  double file_text_read_real( const int fileid );
  void file_text_readln( const int fileid );
  bool file_text_eof( const int fileid );
  bool file_exists( const CGMVariable& fname );
  void file_delete( const CGMVariable& fname );
  void file_rename( const CGMVariable& oldname, const CGMVariable& newname );
  void file_copy( const CGMVariable& fname, const CGMVariable& newname );
  bool directory_exists( const CGMVariable& dname );
  void directory_create( const CGMVariable& dname );
  CGMVariable file_find_first( const CGMVariable& mask, const int attr );
  CGMVariable file_find_next();
  void file_find_close();
  bool file_attributes( const CGMVariable& fname, const int attr );
  CGMVariable filename_name( const CGMVariable& fname );
  CGMVariable filename_path( const CGMVariable& fname );
  CGMVariable filename_dir( const CGMVariable& fname );
  CGMVariable filename_drive( const CGMVariable& fname );
  CGMVariable filename_ext( const CGMVariable& fname );
  CGMVariable filename_change_ext( const CGMVariable& fname, const CGMVariable& newext );
  int file_bin_open( const CGMVariable& fname, const int mod );
  void file_bin_rewrite( const int fileid );
  void file_bin_close( const int fileid );
  int file_bin_size( const int fileid );
  int file_bin_position( const int fileid );
  void file_bin_seek( const int fileid, const int pos );
  void file_bin_write_byte( const int fileid, const int byte );
  int file_bin_read_byte( const int fileid );
  void export_include_file( const CGMVariable& fname );
  void export_include_file_location( const CGMVariable& fname, const CGMVariable& location );
  void discard_include_file( const CGMVariable& fname );
  int parameter_count();
  CGMVariable parameter_string( const int n );
  CGMVariable environment_get_variable( const CGMVariable& name );
  void registry_write_string( const CGMVariable& name, const CGMVariable& str );
  void registry_write_real( const CGMVariable& name, const double x );
  CGMVariable registry_read_string( const CGMVariable& name );
  double registry_read_real( const CGMVariable& name );
  bool registry_exists( const CGMVariable& name );
  void registry_write_string_ext( const CGMVariable& key, const CGMVariable& name,
                                  const CGMVariable& str );
  void registry_write_real_ext( const CGMVariable& key, const CGMVariable& name,
                                const double x );
  CGMVariable registry_read_string_ext( const CGMVariable& key, const CGMVariable& name );
  double registry_read_real_ext( const CGMVariable& key, const CGMVariable& name );
  bool registry_exists_ext( const CGMVariable& key, const CGMVariable& name );
  void registry_set_root( const int root );
  void ini_open( const CGMVariable& name );
  void ini_close();
  CGMVariable ini_read_string( const CGMVariable& section, const CGMVariable& key,
                               const CGMVariable& default_ );
  double ini_read_real( const CGMVariable& section, const CGMVariable& key,
                        const double default_ );
  void ini_write_string( const CGMVariable& section, const CGMVariable& key,
                         const CGMVariable& value );
  void ini_write_real( const CGMVariable& section, const CGMVariable& key, const double value );
  bool ini_key_exists( const CGMVariable& section, const CGMVariable& key );
  bool ini_section_exists( const CGMVariable& section );
  void ini_key_delete( const CGMVariable& section, const CGMVariable& key );
  void ini_section_delete( const CGMVariable& section );
  void execute_program( const CGMVariable& prog, const CGMVariable& arg, const bool wait );
  void execute_shell( const CGMVariable& prog, const CGMVariable& arg );

}