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
  GmapiMultiplayer.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiMultiplayer.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void mplay_init_ipx() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mplay_init_ipx );
  }

  void mplay_init_tcpip( const CGMVariable& addr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ addr };

    GM_NORMAL_CALL( id_mplay_init_tcpip );
  }

  void mplay_init_modem( const CGMVariable& initstr, const CGMVariable& phonenr ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ initstr, phonenr };

    GM_NORMAL_CALL( id_mplay_init_modem );
  }

  void mplay_init_serial( int portno, double baudrate, double stopbits, int parity, int flow ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ portno, baudrate, stopbits, parity, flow };

    GM_NORMAL_CALL( id_mplay_init_serial );
  }

  int mplay_connect_status() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mplay_connect_status );
    GM_RETURN_INT;
  }

  void mplay_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mplay_end );
  }

  CGMVariable mplay_ipaddress() {
    GM_VAR_RESULT;

    GM_VOID_CALL( id_mplay_ipaddress );
    GM_RETURN_VAR;
  }

  bool mplay_session_create( const CGMVariable& sesname, int playnumb, const CGMVariable& playername ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ sesname, playnumb, playername };

    GM_NORMAL_CALL( id_mplay_session_create );
    GM_RETURN_BOOL;
  }

  int mplay_session_find() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mplay_session_find );
    GM_RETURN_INT;
  }

  CGMVariable mplay_session_name( int numb ) {
    GM_VAR_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_mplay_session_name );
    GM_RETURN_VAR;
  }

  bool mplay_session_join( int numb, const CGMVariable& playername ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb, playername };

    GM_NORMAL_CALL( id_mplay_session_join );
    GM_RETURN_BOOL;
  }

  void mplay_session_mode( bool move ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ move };

    GM_NORMAL_CALL( id_mplay_session_mode );
  }

  int mplay_session_status() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mplay_session_status );
    GM_RETURN_INT;
  }

  void mplay_session_end() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mplay_session_end );
  }

  int mplay_player_find() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mplay_player_find );
    GM_RETURN_INT;
  }

  CGMVariable mplay_player_name( int numb ) {
    GM_VAR_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_mplay_player_name );
    GM_RETURN_VAR;
  }

  int mplay_player_id( int numb ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ numb };

    GM_NORMAL_CALL( id_mplay_player_id );
    GM_RETURN_INT;
  }

  void mplay_data_write( int ind, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ ind, val };

    GM_NORMAL_CALL( id_mplay_data_write );
  }

  CGMVariable mplay_data_read( int ind ) {
    GM_VAR_RESULT;
    GM_ARGS{ ind };

    GM_NORMAL_CALL( id_mplay_data_read );
    GM_RETURN_VAR;
  }

  void mplay_data_mode( bool guar ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ guar };

    GM_NORMAL_CALL( id_mplay_data_mode );
  }

  void mplay_message_send( const CGMVariable& player, int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ player, id, val };

    GM_NORMAL_CALL( id_mplay_message_send );
  }

  void mplay_message_send_guaranteed( const CGMVariable& player, int id, const CGMVariable& val ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ player, id, val };

    GM_NORMAL_CALL( id_mplay_message_send_guaranteed );
  }

  bool mplay_message_receive( const CGMVariable& player ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ player };

    GM_NORMAL_CALL( id_mplay_message_receive );
    GM_RETURN_BOOL;
  }

  int mplay_message_id() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_mplay_message_id );
    GM_RETURN_INT;
  }

  CGMVariable mplay_message_value() {
    GM_VAR_RESULT;

    GM_VOID_CALL( id_mplay_message_value );
    GM_RETURN_VAR;
  }

  CGMVariable mplay_message_player() {
    GM_VAR_RESULT;

    GM_VOID_CALL( id_mplay_message_player );
    GM_RETURN_VAR;
  }

  CGMVariable mplay_message_name() {
    GM_VAR_RESULT;

    GM_VOID_CALL( id_mplay_message_name );
    GM_RETURN_VAR;
  }

  int mplay_message_count( const CGMVariable& player ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ player };

    GM_NORMAL_CALL( id_mplay_message_count );
    GM_RETURN_INT;
  }

  void mplay_message_clear( const CGMVariable& player ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ player };

    GM_NORMAL_CALL( id_mplay_message_clear );
  }

}