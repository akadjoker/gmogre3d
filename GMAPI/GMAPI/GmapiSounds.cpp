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

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiSounds.h"
#include "GmapiMacros.h"
#include "GmapiConsts.h"

namespace gm {

  void sound_play( int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_play );
  }

  void sound_loop( int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_loop );
  }

  void sound_stop( int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_stop );
  }

  void sound_stop_all() {
    GM_NORMAL_RESULT;

    GM_VOID_CALL( id_sound_stop_all );
  }

  bool sound_isplaying( int index ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index };

    GM_NORMAL_CALL( id_sound_isplaying );
    GM_RETURN_BOOL;
  }

  void sound_volume( int index, double value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index, value };

    GM_NORMAL_CALL( id_sound_volume );
  }

  void sound_global_volume( double value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ value };

    GM_NORMAL_CALL( id_sound_global_volume );
  }

  void sound_fade( int index, double value, int time ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index, value, time };

    GM_NORMAL_CALL( id_sound_fade );
  }

  void sound_pan( int index, double value ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ index, value };

    GM_NORMAL_CALL( id_sound_pan );
  }

  void sound_background_tempo( double factor ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ factor };

    GM_NORMAL_CALL( id_sound_background_tempo );
  }

  void sound_set_search_directory( const CGMVariable& dir ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ dir };

    GM_NORMAL_CALL( id_sound_set_search_directory );
  }

  void sound_effect_set( int snd, int effect ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, effect };

    GM_NORMAL_CALL( id_sound_effect_set );
  }

  void sound_effect_chorus( int snd, double wetdry, double depth,
                            double feedback, double frequency, int wave,
                            int delay, double phase ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, wetdry, depth, feedback, frequency, wave, delay, phase };

    GM_NORMAL_CALL( id_sound_effect_chorus );
  }

  void sound_effect_echo( int snd, double wetdry, double feedback,
                          int leftdelay, int rightdelay, bool pandelay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, wetdry, feedback, leftdelay, rightdelay, pandelay };

    GM_NORMAL_CALL( id_sound_effect_echo );
  }

  void sound_effect_flanger( int snd, double wetdry, double depth,
                             double feedback, double frequency, 
                             int wave, int delay, double phase ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, wetdry, depth, feedback, frequency, wave, delay, phase };

    GM_NORMAL_CALL( id_sound_effect_flanger );
  }

  void sound_effect_gargle( int snd, double rate, int wave ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, rate, wave };

    GM_NORMAL_CALL( id_sound_effect_gargle );
  }

  void sound_effect_reverb( int snd, double gain, double mix,
                            double time, double ratio ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, gain, mix, time, ratio };

    GM_NORMAL_CALL( id_sound_effect_reverb );
  }

  void sound_effect_compressor( int snd, double gain, double attack,
                                double release, double threshold,
                                double ratio, double delay ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, gain, attack, release, threshold, ratio, delay };

    GM_NORMAL_CALL( id_sound_effect_compressor );
  }

  void sound_effect_equalizer( int snd, double center, double bandwidth,
                               double gain ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, center, bandwidth, gain };

    GM_NORMAL_CALL( id_sound_effect_equalizer );
  }

  void sound_3d_set_sound_position( int snd, double x, double y,
                                    double z ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, x, y, z };

    GM_NORMAL_CALL( id_sound_3d_set_sound_position );
  }

  void sound_3d_set_sound_velocity( int snd, double x, double y,
                                    double z ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, x, y, z };

    GM_NORMAL_CALL( id_sound_3d_set_sound_velocity );
  }

  void sound_3d_set_sound_distance( int snd, double mindist,
                                    double maxdist ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ snd, mindist, maxdist };

    GM_NORMAL_CALL( id_sound_3d_set_sound_distance );
  }

  void sound_3d_set_sound_cone( int snd, double x, double y,
                                double z, double anglein, double angleout,
                                double voloutside ) {
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

  int cd_track_length( int n ) {
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

  void cd_play( int first, int last ) {
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

  void cd_set_position( int pos ) {
    GM_NORMAL_RESULT;
    GM_ARGS{ pos };

    GM_NORMAL_CALL( id_cd_set_position );
  }

  void cd_set_track_position( int pos ) {
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
