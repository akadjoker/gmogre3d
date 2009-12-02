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
  GmapiResources.h
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#pragma once
#include "GmapiInternal.h"

namespace gm {

  void sound_play( const int index );
  void sound_loop( const int index );
  void sound_stop( const int index );
  void sound_stop_all();
  bool sound_isplaying( const int index );

  void sound_volume( const int index, const double value );
  void sound_global_volume( const double value );
  void sound_fade( const int index, const double value, const int time );
  void sound_pan( const int index, const double value );
  void sound_background_tempo( const double factor );

  void sound_set_search_directory( const CGMVariable& dir );

  void sound_effect_set( const int snd, const int effect );
  void sound_effect_chorus( const int snd, const double wetdry, const double depth,
                            const double feedback, const double frequency, const int wave,
                            const int delay, const double phase );
  void sound_effect_echo( const int snd, const double wetdry, const double feedback,
                          const int leftdelay, const int rightdelay, const bool pandelay );
  void sound_effect_flanger( const int snd, const double wetdry, const double depth, 
                             const double feedback, const double frequency, const int wave,
                             const int delay, const double phase );
  void sound_effect_gargle( const int snd, const double rate, const int wave );
  void sound_effect_reverb( const int snd, const double gain, const double mix, 
                            const double time, const double ratio );
  void sound_effect_compressor( const int snd, const double gain, const double attack,
                                const double release, const double threshold,
                                const double ratio, const double delay );
  void sound_effect_equalizer( const int snd, const double center, const double bandwidth,
                               const double gain );

  void sound_3d_set_sound_position( const int snd, const double x, const double y,
                                    const double z );
  void sound_3d_set_sound_velocity( const int snd, const double x, const double y,
                                    const double z );
  void sound_3d_set_sound_distance( const int snd, const double mindist, const double maxdist );
  void sound_3d_set_sound_cone( const int snd, const double x, const double y, 
                                const double z, const double anglein, const double angleout,
                                const double voloutside );

  void cd_init();
  bool cd_present();
  int cd_number();
  bool cd_playing();
  bool cd_paused();
  int cd_track();
  int cd_length();
  int cd_track_length( const int n );
  int cd_position();
  int cd_track_position();
  void cd_play( const int first, const int last );
  void cd_stop();
  void cd_pause();
  void cd_resume();
  int cd_set_position( const int pos );
  void cd_set_track_position( const int pos );
  void cd_open_door();
  void cd_close_door();

  CGMVariable MCI_command( const CGMVariable& str );

}
