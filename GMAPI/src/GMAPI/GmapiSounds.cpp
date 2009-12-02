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
  GmapiSounds.cpp
  - Wrapped GM functions; Parser-generated code

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiSounds.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void sound_play( const int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_play );
  }

  void sound_loop( const int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_loop );
  }

  void sound_stop( const int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_stop );
  }

  void sound_stop_all() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_sound_stop_all );
  }

  bool sound_isplaying( const int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_isplaying );
    GM_RETURN_BOOL;
  }

  void sound_volume( const int index, const double value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index, value };

    GM_NORMAL_CALL( id_sound_volume );
  }

  void sound_global_volume( const double value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ value };

    GM_NORMAL_CALL( id_sound_global_volume );
  }

  void sound_fade( const int index, const double value, const int time ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index, value, time };

    GM_NORMAL_CALL( id_sound_fade );
  }

  void sound_pan( const int index, const double value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index, value };

    GM_NORMAL_CALL( id_sound_pan );
  }

  void sound_background_tempo( const double factor ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ factor };

    GM_NORMAL_CALL( id_sound_background_tempo );
  }

  void sound_set_search_directory( const CGMVariable& dir ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir };

    GM_NORMAL_CALL( id_sound_set_search_directory );
  }

  void sound_effect_set( const int snd, const int effect ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, effect };

    GM_NORMAL_CALL( id_sound_effect_set );
  }

  void sound_effect_chorus( const int snd, const double wetdry, const double depth,
                            const double feedback, const double frequency, const int wave,
                            const int delay, const double phase ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, wetdry, depth, feedback, frequency, wave, delay, phase };

    GM_NORMAL_CALL( id_sound_effect_chorus );
  }

  void sound_effect_echo( const int snd, const double wetdry, const double feedback,
                          const int leftdelay, const int rightdelay, const bool pandelay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, wetdry, feedback, leftdelay, rightdelay, pandelay };

    GM_NORMAL_CALL( id_sound_effect_echo );
  }

  void sound_effect_flanger( const int snd, const double wetdry, const double depth,
                             const double feedback, const double frequency, 
                             const int wave, const int delay, const double phase ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, wetdry, depth, feedback, frequency, wave, delay, phase };

    GM_NORMAL_CALL( id_sound_effect_flanger );
  }

  void sound_effect_gargle( const int snd, const double rate, const int wave ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, rate, wave };

    GM_NORMAL_CALL( id_sound_effect_gargle );
  }

  void sound_effect_reverb( const int snd, const double gain, const double mix,
                            const double time, const double ratio ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, gain, mix, time, ratio };

    GM_NORMAL_CALL( id_sound_effect_reverb );
  }

  void sound_effect_compressor( const int snd, const double gain, const double attack,
                                const double release, const double threshold,
                                const double ratio, const double delay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, gain, attack, release, threshold, ratio, delay };

    GM_NORMAL_CALL( id_sound_effect_compressor );
  }

  void sound_effect_equalizer( const int snd, const double center, const double bandwidth,
                               const double gain ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, center, bandwidth, gain };

    GM_NORMAL_CALL( id_sound_effect_equalizer );
  }

  void sound_3d_set_sound_position( const int snd, const double x, const double y,
                                    const double z ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, x, y, z };

    GM_NORMAL_CALL( id_sound_3d_set_sound_position );
  }

  void sound_3d_set_sound_velocity( const int snd, const double x, const double y,
                                    const double z ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, x, y, z };

    GM_NORMAL_CALL( id_sound_3d_set_sound_velocity );
  }

  void sound_3d_set_sound_distance( const int snd, const double mindist,
                                    const double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, mindist, maxdist };

    GM_NORMAL_CALL( id_sound_3d_set_sound_distance );
  }

  void sound_3d_set_sound_cone( const int snd, const double x, const double y,
                                const double z, const double anglein, const double angleout,
                                const double voloutside ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, x, y, z, anglein, angleout, voloutside };

    GM_NORMAL_CALL( id_sound_3d_set_sound_cone );
  }

  void cd_init() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_init );
  }

  bool cd_present() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_present );
    GM_RETURN_BOOL;
  }

  int cd_number() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_number );
    GM_RETURN_INT;
  }

  bool cd_playing() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_playing );
    GM_RETURN_BOOL;
  }

  bool cd_paused() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_paused );
    GM_RETURN_BOOL;
  }

  int cd_track() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_track );
    GM_RETURN_INT;
  }

  int cd_length() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_length );
    GM_RETURN_INT;
  }

  int cd_track_length( const int n ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ n };

    GM_NORMAL_CALL( id_cd_track_length );
    GM_RETURN_INT;
  }

  int cd_position() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_position );
    GM_RETURN_INT;
  }

  int cd_track_position() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_track_position );
    GM_RETURN_INT;
  }

  void cd_play( const int first, const int last ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ first, last };

    GM_NORMAL_CALL( id_cd_play );
  }

  void cd_stop() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_stop );
  }

  void cd_pause() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_pause );
  }

  void cd_resume() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_resume );
  }

  int cd_set_position( const int pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ pos };

    GM_NORMAL_CALL( id_cd_set_position );
    GM_RETURN_INT;
  }

  void cd_set_track_position( const int pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ pos };

    GM_NORMAL_CALL( id_cd_set_track_position );
  }

  void cd_open_door() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_open_door );
  }

  void cd_close_door() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_cd_close_door );
  }

  CGMVariable MCI_command( const CGMVariable& str ) {
    GM_VAR_RESULT;
    GM_ARGS{ str };

    GM_NORMAL_CALL( id_MCI_command );
    GM_RETURN_VAR;
  }

}
