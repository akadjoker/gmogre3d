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
  GmapiMultiplayer.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  void mplay_init_ipx();
  void mplay_init_tcpip( const CGMVariable& addr );
  void mplay_init_modem( const CGMVariable& initstr, const CGMVariable& phonenr );
  void mplay_init_serial( const int portno, const double baudrate, const double stopbits,
                          const int parity, const int flow );
  int mplay_connect_status();
  void mplay_end();
  CGMVariable mplay_ipaddress();

  bool mplay_session_create( const CGMVariable& sesname, const int playnumb, 
                             const CGMVariable& playername );
  int mplay_session_find();
  CGMVariable mplay_session_name( const int numb );
  bool mplay_session_join( const int numb, const CGMVariable& playername );
  void mplay_session_mode( const bool move );
  int mplay_session_status();
  void mplay_session_end();

  int mplay_player_find();
  CGMVariable mplay_player_name( const int numb );
  int mplay_player_id( const int numb );

  void mplay_data_write( const int ind, const CGMVariable& val );
  CGMVariable mplay_data_read( const int ind );
  void mplay_data_mode( const bool guar );

  void mplay_message_send( const CGMVariable& player, const int id, const CGMVariable& val );
  void mplay_message_send_guaranteed( const CGMVariable& player, const int id,
                                      const CGMVariable& val );
  bool mplay_message_receive( const CGMVariable& player );
  int mplay_message_id();
  CGMVariable mplay_message_value();
  CGMVariable mplay_message_player();
  CGMVariable mplay_message_name();
  int mplay_message_count( const CGMVariable& player );
  void mplay_message_clear( const CGMVariable& player );

};