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
  GmapiConsts.cpp
  - Constants used by GMAPI

  Copyright 2009-2010 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/

#include "GmapiConsts.h"

namespace gm {
  unsigned long const GM_VERSION_INCOMPATIBLE = 0;
  unsigned long const GM_VERSION_61           = 61;
  unsigned long const GM_VERSION_70           = 70;
  unsigned long const GM_VERSION_80           = 80;

  unsigned long const GMAPI_INITIALIZATION_SUCCESS = 0;
  unsigned long const GMAPI_INITIALIZATION_FAILED  = 1;
  unsigned long const GMAPI_ALREADY_INITIALIZED    = 2;

  const char* const GM70_ADDRESS_PTR_SWAPTABLE                 = (const char*) 0x005CA768;
  const char* const GM80_ADDRESS_PTR_SWAPTABLE                 = (const char*) 0x006DCF28;
  void** const GM61_ADDRESS_PTR_CURRENTROOM                    = (void**) 0x0055D2F0;
  void** const GM70_ADDRESS_PTR_CURRENTROOM                    = (void**) 0x005AF2F4;
  void** const GM80_ADDRESS_PTR_CURRENTROOM                    = (void**) 0x006C73C4;
  int* const GM61_ADDRESS_PTR_ROOMCOUNT                        = (int*) 0x00537B3C;
  int* const GM70_ADDRESS_PTR_ROOMCOUNT                        = (int*) 0x00587BB4;
  int* const GM80_ADDRESS_PTR_ROOMCOUNT                        = (int*) 0x0058D4D8;

  PGMVARIABLELIST* const GM61_ADDRESS_PTR_GLOBALVARLIST        = (PGMVARIABLELIST*) 0x0055DBF8;
  PGMVARIABLELIST* const GM70_ADDRESS_PTR_GLOBALVARLIST        = (PGMVARIABLELIST*) 0x00589720;
  PGMVARIABLELIST* const GM80_ADDRESS_PTR_GLOBALVARLIST        = (PGMVARIABLELIST*) 0x0058F124;

  int* const GM61_ADDRESS_ARRAY_ROOMIDS                        = (int*) 0x0055D2F0;
  int* const GM70_ADDRESS_ARRAY_ROOMIDS                        = (int*) 0x005AF330;
  int* const GM80_ADDRESS_ARRAY_ROOMIDS                        = (int*) 0x006C73F4;
  PGMFUNCTIONINFOSTORAGE const GM61_ADDRESS_ARRAY_GMFUNCTIONS  = (PGMFUNCTIONINFOSTORAGE) 0x00538550;
  PGMFUNCTIONINFOSTORAGE const GM70_ADDRESS_ARRAY_GMFUNCTIONS  = (PGMFUNCTIONINFOSTORAGE) 0x00589744;
  PGMFUNCTIONINFOSTORAGE const GM80_ADDRESS_ARRAY_GMFUNCTIONS  = (PGMFUNCTIONINFOSTORAGE) 0x0058F148;
  PGMSURFACE* const GM61_ADDRESS_ARRAY_SURFACES                = (PGMSURFACE*) 0x0055D148;
  PGMSURFACE* const GM70_ADDRESS_ARRAY_SURFACES                = (PGMSURFACE*) 0x005AF14C;
  PGMSURFACE* const GM80_ADDRESS_ARRAY_SURFACES                = (PGMSURFACE*) 0x006C7240;
  PGMTEXTURE* const GM61_ADDRESS_ARRAY_TEXTURES                = (PGMTEXTURE*) 0x0055D228;
  PGMTEXTURE* const GM70_ADDRESS_ARRAY_TEXTURES                = (PGMTEXTURE*) 0x005AF22C;
  PGMTEXTURE* const GM80_ADDRESS_ARRAY_TEXTURES                = (PGMTEXTURE*) 0x006C7320;
  int* const GM61_ADDRESS_ARRAYSIZE_SURFACES                   = (int*) 0x005379E4;
  int* const GM70_ADDRESS_ARRAYSIZE_SURFACES                   = (int*) 0x00587A54;
  int* const GM80_ADDRESS_ARRAYSIZE_SURFACES                   = (int*) 0x0058D378;

  PGMSPRITESTORAGE const GM61_ADDRESS_STORAGE_SPRITES          = (PGMSPRITESTORAGE) 0x00537A40;
  PGMSPRITESTORAGE const GM70_ADDRESS_STORAGE_SPRITES          = (PGMSPRITESTORAGE) 0x00587AB0;
  PGMSPRITESTORAGE const GM80_ADDRESS_STORAGE_SPRITES          = (PGMSPRITESTORAGE) 0x0058D3D4;  
  PGMBACKGROUNDSTORAGE const GM61_ADDRESS_STORAGE_BACKGROUNDS  = (PGMBACKGROUNDSTORAGE) 0x00537A4C;
  PGMBACKGROUNDSTORAGE const GM70_ADDRESS_STORAGE_BACKGROUNDS  = (PGMBACKGROUNDSTORAGE) 0x00587ABC;
  PGMBACKGROUNDSTORAGE const GM80_ADDRESS_STORAGE_BACKGROUNDS  = (PGMBACKGROUNDSTORAGE) 0x0058D3E0;
  PGMSCRIPTSTORAGE const GM61_ADDRESS_STORAGE_SCRIPTS          = (PGMSCRIPTSTORAGE) 0x0053853C;
  PGMSCRIPTSTORAGE const GM70_ADDRESS_STORAGE_SCRIPTS          = (PGMSCRIPTSTORAGE) 0x00589730;
  PGMSCRIPTSTORAGE const GM80_ADDRESS_STORAGE_SCRIPTS          = (PGMSCRIPTSTORAGE) 0x0058F134;
  PGMDIRECT3DDATA const GM61_ADDRESS_STORAGE_DIRECTX           = (PGMDIRECT3DDATA) 0x005379F0;
  PGMDIRECT3DDATA const GM70_ADDRESS_STORAGE_DIRECTX           = (PGMDIRECT3DDATA) 0x00587A60;
  PGMDIRECT3DDATA const GM80_ADDRESS_STORAGE_DIRECTX           = (PGMDIRECT3DDATA) 0x0058D384;
  PGMSOUNDSTORAGE const GM61_ADDRESS_STORAGE_SOUNDS            = (PGMSOUNDSTORAGE) 0x00537850;
  PGMSOUNDSTORAGE const GM70_ADDRESS_STORAGE_SOUNDS            = (PGMSOUNDSTORAGE) 0x005878C0;
  PGMSOUNDSTORAGE const GM80_ADDRESS_STORAGE_SOUNDS            = (PGMSOUNDSTORAGE) 0x0058CDE0;
  PGMFONTSTORAGE const GM61_ADDRESS_STORAGE_FONTS              = (PGMFONTSTORAGE) 0x005385B0;
  PGMFONTSTORAGE const GM70_ADDRESS_STORAGE_FONTS              = (PGMFONTSTORAGE) 0x005896F8;
  PGMFONTSTORAGE const GM80_ADDRESS_STORAGE_FONTS              = (PGMFONTSTORAGE) 0x0058F0F0;
  PGMPARTICLESTORAGE const GM61_ADDRESS_STORAGE_PARTICLES      = (PGMPARTICLESTORAGE) 0x00537BB8;
  PGMPARTICLESTORAGE const GM70_ADDRESS_STORAGE_PARTICLES      = (PGMPARTICLESTORAGE) 0x00587C30;
  PGMPARTICLESTORAGE const GM80_ADDRESS_STORAGE_PARTICLES      = (PGMPARTICLESTORAGE) 0x0058D5A4;

  HWND** const GM61_ADDRESS_FORM_TRUNNER                       = (HWND**) 0x00535414;
  HWND** const GM70_ADDRESS_FORM_TRUNNER                       = (HWND**) 0x00585414;
  HWND** const GM80_ADDRESS_FORM_TRUNNER                       = (HWND**) 0x0058D2FC;
  HWND** const GM61_ADDRESS_FORM_TDEBUG                        = (HWND**) 0x005678C4;
  HWND** const GM70_ADDRESS_FORM_TDEBUG                        = (HWND**) 0x005BAB04;
  HWND** const GM80_ADDRESS_FORM_TDEBUG                        = (HWND**) 0x006D2A84;
  HWND** const GM70_ADDRESS_FORM_TSCORE                        = (HWND**) 0x005AF49C;
  HWND** const GM80_ADDRESS_FORM_TSCORE                        = (HWND**) 0x006C74C0;

  int* const GM61_ADDRESS_PROPERTY_GAMEID                      = (int*) 0x0055D2D0;
  int* const GM70_ADDRESS_PROPERTY_GAMEID                      = (int*) 0x005AF2D4;
  int* const GM80_ADDRESS_PROPERTY_GAMEID                      = (int*) 0x006C73A4;
  const char** const GM61_ADDRESS_PROPERTY_TEMPDIRECTORY       = (const char**) 0x00539E44;
  const char** const GM70_ADDRESS_PROPERTY_TEMPDIRECTORY       = (const char**) 0x0058BE48;
  const char** const GM80_ADDRESS_PROPERTY_TEMPDIRECTORY       = (const char**) 0x00593814;
  int* const GM61_ADDRESS_PROPERTY_FPS                         = (int*) 0x0055D310;
  int* const GM70_ADDRESS_PROPERTY_FPS                         = (int*) 0x005AF314;
  int* const GM80_ADDRESS_PROPERTY_FPS                         = (int*) 0x006C73E4;
  int* const GM61_ADDRESS_PROPERTY_ROOM                        = (int*) 0x0055D2F4;
  int* const GM70_ADDRESS_PROPERTY_ROOM                        = (int*) 0x005AF2F8;
  int* const GM80_ADDRESS_PROPERTY_ROOM                        = (int*) 0x006C73C8;
  int* const GM61_ADDRESS_PROPERTY_SCORE                       = (int*) 0x00537AE4;
  int* const GM70_ADDRESS_PROPERTY_SCORE                       = (int*) 0x00587B5C;
  int* const GM80_ADDRESS_PROPERTY_SCORE                       = (int*) 0x0058D480;
  int* const GM61_ADDRESS_PROPERTY_LIVES                       = (int*) 0x00537AF4;
  int* const GM70_ADDRESS_PROPERTY_LIVES                       = (int*) 0x00587B6C;
  int* const GM80_ADDRESS_PROPERTY_LIVES                       = (int*) 0x0058D490;
  double* const GM61_ADDRESS_PROPERTY_HEALTH                   = (double*) 0x00537B00;
  double* const GM70_ADDRESS_PROPERTY_HEALTH                   = (double*) 0x00587B78;
  double* const GM80_ADDRESS_PROPERTY_HEALTH                   = (double*) 0x0058D49C;
  bool* const GM61_ADDRESS_PROPERTY_SHOWSCORE                  = (bool*) 0x00537AE8;
  bool* const GM70_ADDRESS_PROPERTY_SHOWSCORE                  = (bool*) 0x00587B60;
  bool* const GM80_ADDRESS_PROPERTY_SHOWSCORE                  = (bool*) 0x0058D484;
  bool* const GM61_ADDRESS_PROPERTY_SHOWLIVES                  = (bool*) 0x00537AF8;
  bool* const GM70_ADDRESS_PROPERTY_SHOWLIVES                  = (bool*) 0x00587B70;
  bool* const GM80_ADDRESS_PROPERTY_SHOWLIVES                  = (bool*) 0x0058D494;
  bool* const GM61_ADDRESS_PROPERTY_SHOWHEALTH                 = (bool*) 0x00537B08;
  bool* const GM70_ADDRESS_PROPERTY_SHOWHEALTH                 = (bool*) 0x00587B80;
  bool* const GM80_ADDRESS_PROPERTY_SHOWHEALTH                 = (bool*) 0x0058D4A4;
  int* const GM61_ADDRESS_PROPERTY_EVENTTYPE                   = (int*) 0x0055D304;
  int* const GM70_ADDRESS_PROPERTY_EVENTTYPE                   = (int*) 0x005AF308;
  int* const GM80_ADDRESS_PROPERTY_EVENTTYPE                   = (int*) 0x006C73D8;
  int* const GM61_ADDRESS_PROPERTY_EVENTNUMBER                 = (int*) 0x0055D308;
  int* const GM70_ADDRESS_PROPERTY_EVENTNUMBER                 = (int*) 0x005AF30C;
  int* const GM80_ADDRESS_PROPERTY_EVENTNUMBER                 = (int*) 0x006C73DC;
  int* const GM61_ADDRESS_PROPERTY_EVENTOBJECT                 = (int*) 0x0055D300;
  int* const GM70_ADDRESS_PROPERTY_EVENTOBJECT                 = (int*) 0x005AF304;
  int* const GM80_ADDRESS_PROPERTY_EVENTOBJECT                 = (int*) 0x006C73D4;
  int* const GM61_ADDRESS_PROPERTY_EVENTACTION                 = (int*) 0x0055D30C;
  int* const GM70_ADDRESS_PROPERTY_EVENTACTION                 = (int*) 0x005AF310;
  int* const GM80_ADDRESS_PROPERTY_EVENTACTION                 = (int*) 0x006C73E0;
  const char** const GM61_ADDRESS_PROPERTY_ERRORLAST           = (const char**) 0x005385A0;
  const char** const GM70_ADDRESS_PROPERTY_ERRORLAST           = (const char**) 0x00589784;
  const char** const GM80_ADDRESS_PROPERTY_ERRORLAST           = (const char**) 0x0058F198;
  bool* const GM61_ADDRESS_PROPERTY_ERROROCCURED               = (bool*) 0x005385A4;
  bool* const GM70_ADDRESS_PROPERTY_ERROROCCURED               = (bool*) 0x00589788;
  bool* const GM80_ADDRESS_PROPERTY_ERROROCCURED               = (bool*) 0x0058F19C;
  int* const GM61_ADDRESS_PROPERTY_KEYBOARDKEY                 = (int*) 0x0055D4DC;
  int* const GM70_ADDRESS_PROPERTY_KEYBOARDKEY                 = (int*) 0x005B06E4;
  int* const GM80_ADDRESS_PROPERTY_KEYBOARDKEY                 = (int*) 0x006C8670;
  int* const GM61_ADDRESS_PROPERTY_KEYBOARDLASTKEY             = (int*) 0x0055D4D8;
  int* const GM70_ADDRESS_PROPERTY_KEYBOARDLASTKEY             = (int*) 0x005B06E0;
  int* const GM80_ADDRESS_PROPERTY_KEYBOARDLASTKEY             = (int*) 0x006C866C;
  const char** const GM61_ADDRESS_PROPERTY_KEYBOARDSTRING      = (const char**) 0x0055D4D4;
  const char** const GM70_ADDRESS_PROPERTY_KEYBOARDSTRING      = (const char**) 0x005B06DC;
  const char** const GM80_ADDRESS_PROPERTY_KEYBOARDSTRING      = (const char**) 0x006C8668;
  int* const GM61_ADDRESS_PROPERTY_MOUSEBUTTON                 = (int*) 0x0055D7E4;
  int* const GM70_ADDRESS_PROPERTY_MOUSEBUTTON                 = (int*) 0x005B09EC;
  int* const GM80_ADDRESS_PROPERTY_MOUSEBUTTON                 = (int*) 0x006C8978;
  int* const GM61_ADDRESS_PROPERTY_MOUSELASTBUTTON             = (int*) 0x0055D7E0;
  int* const GM70_ADDRESS_PROPERTY_MOUSELASTBUTTON             = (int*) 0x005B09E8;
  int* const GM80_ADDRESS_PROPERTY_MOUSELASTBUTTON             = (int*) 0x006C8974;
  int* const GM61_ADDRESS_PROPERTY_VIEWCURRENT                 = (int*) 0x00537B10;
  int* const GM70_ADDRESS_PROPERTY_VIEWCURRENT                 = (int*) 0x00587B88;
  int* const GM80_ADDRESS_PROPERTY_VIEWCURRENT                 = (int*) 0x0058D4AC;
  int* const GM70_ADDRESS_PROPERTY_TRANSITIONKIND              = (int*) 0x00587B58;
  int* const GM80_ADDRESS_PROPERTY_TRANSITIONKIND              = (int*) 0x0058D47C;
  int* const GM70_ADDRESS_PROPERTY_TRANSITIONSTEPS             = (int*) 0x0058971C;
  int* const GM80_ADDRESS_PROPERTY_TRANSITIONSTEPS             = (int*) 0x0058F120;
  int* const GM70_ADDRESS_PROPERTY_CURSORSPRITE                = (int*) 0x00587B90;
  int* const GM80_ADDRESS_PROPERTY_CURSORSPRITE                = (int*) 0x0058D4B4;

  PGMINSTANCE* const GMAPI_ADDRESS_PTR_CURRENTINSTANCE         = (PGMINSTANCE*) 0x00400804;
  PGMINSTANCE* const GMAPI_ADDRESS_PTR_OTHERINSTANCE           = (PGMINSTANCE*) 0x00400808;

  void* const GM70_ADDRESS_PATCH_IDENTIFIERTYPECHECKING        = (void*) 0x0052D361;
  void* const GM80_ADDRESS_PATCH_IDENTIFIERTYPECHECKING        = (void*) 0x005294F9;

  BYTE const GM70_PATCH_IDENTIFIERTYPECHECKING[] = {
    0xC7, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0x8B, 0x35,
    0x48, 0x97, 0x58, 0x00, 0x4E, 0x85, 0xF6, 0x7C, 
    0x62, 0x46, 0x33, 0xDB, 0x8D, 0x45, 0xF4, 0x8B,
    0xD3, 0x03, 0xD2, 0x8D, 0x14, 0x92, 0x8B, 0x0D,
    0x44, 0x97, 0x58, 0x00, 0x8D, 0x14, 0xD1, 0xE8,
    0x7F, 0x7E, 0xED, 0xFF, 0x8B, 0x45, 0xF4, 0x8B,
    0x55, 0xFC, 0xE8, 0x1C, 0x80, 0xED, 0xFF, 0x75,
    0x04, 0x89, 0x1F, 0xEB, 0x36, 0x43, 0x4E, 0x75,
    0xD3, 0x8B, 0x45, 0xFC, 0xE8, 0x5A, 0xFB, 0xFF,
    0xFF, 0x05, 0xA0, 0x86, 0x01, 0x00, 0x89, 0x07,
    0x81, 0x3F, 0xA0, 0x86, 0x01, 0x00, 0x7D, 0x1B,
    0x8B, 0x45, 0xFC, 0xE8, 0x93, 0x47, 0xFF, 0xFF, 
    0x05, 0x20, 0xA1, 0x07, 0x00, 0x89, 0x07, 0x81,
    0x3F, 0x20, 0xA1, 0x07, 0x00, 0x7D, 0x04
  };

  BYTE const GM80_PATCH_IDENTIFIERTYPECHECKING[] = {
    0xC7, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0x8B, 0x35,
    0x4C, 0xF1, 0x58, 0x00, 0x4E, 0x85, 0xF6, 0x7C,
    0x5E, 0x46, 0x33, 0xDB, 0x8D, 0x45, 0xF4, 0x8B,
    0xD3, 0x03, 0xD2, 0x8D, 0x14, 0x92, 0x8B, 0x0D,
    0x48, 0xF1, 0x58, 0x00, 0x8D, 0x14, 0xD1, 0xE8,
    0x73, 0xC6, 0xED, 0xFF, 0x8B, 0x45, 0xF4, 0x8B,
    0x55, 0xFC, 0xE8, 0x14, 0xC8, 0xED, 0xFF, 0x75,
    0x04, 0x89, 0x1F, 0xEB, 0x36, 0x43, 0x4E, 0x75,
    0xD3, 0x8B, 0x45, 0xFC, 0xE8, 0x22, 0xFB, 0xFF,
    0xFF, 0x05, 0xA0, 0x86, 0x01, 0x00, 0x89, 0x07,
    0x81, 0x3F, 0xA0, 0x86, 0x01, 0x00, 0x7D, 0x1B,
    0x8B, 0x45, 0xFC, 0xE8, 0xE7, 0x43, 0xFF, 0xFF,
    0x05, 0x20, 0xA1, 0x07, 0x00, 0x89, 0x07, 0x81,
    0x3F, 0x20, 0xA1, 0x07, 0x00, 0x7D, 0x04
  };

  int const GM_PATCHSIZE_IDENTIFIERTYPECHECKING = sizeof( GM70_PATCH_IDENTIFIERTYPECHECKING );

  const char* const STR_GMAPI_ERROR =    "GMAPI error";
  const char* const STR_GMAPI_DEBUG =    "Debug info";
  const char* const STR_GMAPI_NOACCESS = "<Unable to access resource>";

  const char* const STR_EXC_UNKNOWN =                 "Unexpected error occured.";
  const char* const STR_EXC_SPRITENOTEXISTS =         "Trying to access non existing sprite.";
  const char* const STR_EXC_BACKGROUNDNOTEXISTS =     "Trying to access non existing background.";
  const char* const STR_EXC_SCRIPTNOTEXISTS =         "Trying to access non existing script.";
  const char* const STR_EXC_SOUNDNOTEXISTS =          "Trying to access non existing sound.";
  const char* const STR_EXC_SURFACENOTEXISTS =        "Trying to access non existing surface.";
  const char* const STR_EXC_INVALIDSUBIMAGE =         "Trying to access invalid sprite subimage.";
  const char* const STR_EXC_PARTICLESYSTEMNOTEXISTS = "Trying to access non existing particle system.";
  const char* const STR_EXC_PARTICLETYPENOTEXISTS =   "Trying to access non existing particle type.";
  const char* const STR_EXC_FONTNOTEXISTS =           "Trying to access non existing font.";
  const char* const STR_EXC_DEFLECTORNOTEXISTS =      "Trying to access non existing particle deflector.";
  const char* const STR_EXC_CHANGERNOTEXISTS =        "Trying to access non existing particle changer.";
  const char* const STR_EXC_DESTROYERNOTEXISTS =      "Trying to access non existing particle destroyer.";
  const char* const STR_EXC_EMITTERNOTEXISTS =        "Trying to access non existing particle emitter.";
  const char* const STR_EXC_ATTRACTORNOTEXISTS =      "Trying to access non existing particle attractor.";

  const char* const GM_FUNCTION_NAMES[] = {
    "show_message",
    "show_message_ext",
    "show_question",
    "get_integer",
    "get_string",
    "message_background",
    "message_alpha",
    "message_button",
    "message_button_font",
    "message_text_font",
    "message_input_font",
    "message_input_color",
    "message_mouse_color",
    "message_caption",
    "message_position",
    "message_size",
    "show_menu",
    "show_menu_pos",
    "get_color",
    "get_open_filename",
    "get_save_filename",
    "get_directory",
    "get_directory_alt",
    "splash_show_video",
    "splash_show_text",
    "splash_show_image",
    "splash_show_web",
    "splash_set_main",
    "splash_set_scale",
    "splash_set_cursor",
    "splash_set_color",
    "splash_set_caption",
    "splash_set_fullscreen",
    "splash_set_border",
    "splash_set_size",
    "splash_set_adapt",
    "splash_set_top",
    "splash_set_interrupt",
    "splash_set_stop_key",
    "splash_set_stop_mouse",
    "splash_set_position",
    "splash_set_close_button",
    "show_info",
    "load_info",
    "show_error",
    "highscore_show",
    "highscore_set_background",
    "highscore_set_border",
    "highscore_set_font",
    "highscore_set_colors",
    "highscore_set_strings",
    "highscore_show_ext",
    "highscore_clear",
    "highscore_add",
    "highscore_add_current",
    "highscore_value",
    "highscore_name",
    "draw_highscore",
    "mplay_init_ipx",
    "mplay_init_tcpip",
    "mplay_init_modem",
    "mplay_init_serial",
    "mplay_connect_status",
    "mplay_end",
    "mplay_ipaddress",
    "mplay_session_create",
    "mplay_session_find",
    "mplay_session_name",
    "mplay_session_join",
    "mplay_session_mode",
    "mplay_session_status",
    "mplay_session_end",
    "mplay_player_find",
    "mplay_player_name",
    "mplay_player_id",
    "mplay_data_write",
    "mplay_data_read",
    "mplay_data_mode",
    "mplay_message_send",
    "mplay_message_send_guaranteed",
    "mplay_message_receive",
    "mplay_message_id",
    "mplay_message_value",
    "mplay_message_player",
    "mplay_message_name",
    "mplay_message_count",
    "mplay_message_clear",
    "ds_set_precision",
    "ds_list_create",
    "ds_list_destroy",
    "ds_list_clear",
    "ds_list_copy",
    "ds_list_size",
    "ds_list_empty",
    "ds_list_add",
    "ds_list_insert",
    "ds_list_replace",
    "ds_list_delete",
    "ds_list_find_index",
    "ds_list_find_value",
    "ds_list_sort",
    "ds_list_shuffle",
    "ds_list_write",
    "ds_list_read",
    "ds_stack_create",
    "ds_stack_destroy",
    "ds_stack_clear",
    "ds_stack_copy",
    "ds_stack_size",
    "ds_stack_empty",
    "ds_stack_push",
    "ds_stack_pop",
    "ds_stack_top",
    "ds_stack_write",
    "ds_stack_read",
    "ds_queue_create",
    "ds_queue_destroy",
    "ds_queue_clear",
    "ds_queue_copy",
    "ds_queue_size",
    "ds_queue_empty",
    "ds_queue_enqueue",
    "ds_queue_dequeue",
    "ds_queue_head",
    "ds_queue_tail",
    "ds_queue_write",
    "ds_queue_read",
    "ds_map_create",
    "ds_map_destroy",
    "ds_map_clear",
    "ds_map_copy",
    "ds_map_size",
    "ds_map_empty",
    "ds_map_add",
    "ds_map_replace",
    "ds_map_delete",
    "ds_map_exists",
    "ds_map_find_value",
    "ds_map_find_previous",
    "ds_map_find_next",
    "ds_map_find_first",
    "ds_map_find_last",
    "ds_map_write",
    "ds_map_read",
    "ds_priority_create",
    "ds_priority_destroy",
    "ds_priority_clear",
    "ds_priority_copy",
    "ds_priority_size",
    "ds_priority_empty",
    "ds_priority_add",
    "ds_priority_change_priority",
    "ds_priority_find_priority",
    "ds_priority_delete_value",
    "ds_priority_delete_min",
    "ds_priority_find_min",
    "ds_priority_delete_max",
    "ds_priority_find_max",
    "ds_priority_write",
    "ds_priority_read",
    "ds_grid_create",
    "ds_grid_destroy",
    "ds_grid_delete",
    "ds_grid_copy",
    "ds_grid_resize",
    "ds_grid_width",
    "ds_grid_height",
    "ds_grid_clear",
    "ds_grid_set",
    "ds_grid_add",
    "ds_grid_multiply",
    "ds_grid_set_region",
    "ds_grid_add_region",
    "ds_grid_multiply_region",
    "ds_grid_set_disk",
    "ds_grid_add_disk",
    "ds_grid_multiply_disk",
    "ds_grid_set_grid_region",
    "ds_grid_add_grid_region",
    "ds_grid_multiply_grid_region",
    "ds_grid_get",
    "ds_grid_get_sum",
    "ds_grid_get_max",
    "ds_grid_get_min",
    "ds_grid_get_mean",
    "ds_grid_get_disk_sum",
    "ds_grid_get_disk_min",
    "ds_grid_get_disk_max",
    "ds_grid_get_disk_mean",
    "ds_grid_value_exists",
    "ds_grid_value_x",
    "ds_grid_value_y",
    "ds_grid_value_disk_exists",
    "ds_grid_value_disk_x",
    "ds_grid_value_disk_y",
    "ds_grid_shuffle",
    "ds_grid_write",
    "ds_grid_read",
    "place_free",
    "place_empty",
    "place_meeting",
    "place_snapped",
    "move_random",
    "move_snap",
    "move_wrap",
    "move_towards_point",
    "move_bounce_solid",
    "move_bounce_all",
    "move_contact_solid",
    "move_contact_all",
    "move_outside_solid",
    "move_outside_all",
    "distance_to_point",
    "distance_to_object",
    "position_empty",
    "position_meeting",
    "path_start",
    "path_end",
    "mp_linear_step",
    "mp_linear_step_object",
    "mp_potential_step",
    "mp_potential_step_object",
    "mp_potential_settings",
    "mp_linear_path",
    "mp_linear_path_object",
    "mp_potential_path",
    "mp_potential_path_object",
    "mp_grid_create",
    "mp_grid_destroy",
    "mp_grid_clear_all",
    "mp_grid_clear_cell",
    "mp_grid_clear_rectangle",
    "mp_grid_add_cell",
    "mp_grid_add_rectangle",
    "mp_grid_add_instances",
    "mp_grid_path",
    "mp_grid_draw",
    "collision_point",
    "collision_rectangle",
    "collision_circle",
    "collision_ellipse",
    "collision_line",
    "instance_find",
    "instance_exists",
    "instance_number",
    "instance_position",
    "instance_nearest",
    "instance_furthest",
    "instance_place",
    "instance_create",
    "instance_copy",
    "instance_destroy",
    "instance_change",
    "position_destroy",
    "position_change",
    "instance_deactivate_all",
    "instance_deactivate_object",
    "instance_deactivate_region",
    "instance_activate_all",
    "instance_activate_object",
    "instance_activate_region",
    "room_goto",
    "room_goto_previous",
    "room_goto_next",
    "room_restart",
    "room_previous",
    "room_next",
    "game_end",
    "game_restart",
    "game_save",
    "game_load",
    "transition_define",
    "transition_exists",
    "event_perform",
    "event_perform_object",
    "event_user",
    "event_inherited",
    "show_debug_message",
    "variable_global_exists",
    "variable_local_exists",
    "variable_global_get",
    "variable_global_array_get",
    "variable_global_array2_get",
    "variable_local_get",
    "variable_local_array_get",
    "variable_local_array2_get",
    "variable_global_set",
    "variable_global_array_set",
    "variable_global_array2_set",
    "variable_local_set",
    "variable_local_array_set",
    "variable_local_array2_set",
    "set_program_priority",
    "set_application_title",
    "sound_play",
    "sound_loop",
    "sound_stop",
    "sound_stop_all",
    "sound_isplaying",
    "sound_volume",
    "sound_global_volume",
    "sound_fade",
    "sound_pan",
    "sound_background_tempo",
    "sound_set_search_directory",
    "sound_effect_set",
    "sound_effect_chorus",
    "sound_effect_echo",
    "sound_effect_flanger",
    "sound_effect_gargle",
    "sound_effect_reverb",
    "sound_effect_compressor",
    "sound_effect_equalizer",
    "sound_3d_set_sound_position",
    "sound_3d_set_sound_velocity",
    "sound_3d_set_sound_distance",
    "sound_3d_set_sound_cone",
    "cd_init",
    "cd_present",
    "cd_number",
    "cd_playing",
    "cd_paused",
    "cd_track",
    "cd_length",
    "cd_track_length",
    "cd_position",
    "cd_track_position",
    "cd_play",
    "cd_stop",
    "cd_pause",
    "cd_resume",
    "cd_set_position",
    "cd_set_track_position",
    "cd_open_door",
    "cd_close_door",
    "MCI_command",
    "script_execute",
    "execute_string",
    "execute_file",
    "external_define",
    "external_call",
    "external_free",
    "sprite_set_offset",
    "sprite_set_bbox_mode",
    "sprite_set_bbox",
    "sprite_set_precise",
    "sprite_duplicate",
    "sprite_assign",
    "sprite_merge",
    "sprite_add",
    "sprite_add_sprite",
    "sprite_add_alpha",
    "sprite_replace",
    "sprite_replace_sprite",
    "sprite_replace_alpha",
    "sprite_create_from_screen",
    "sprite_add_from_screen",
    "sprite_create_from_surface",
    "sprite_add_from_surface",
    "sprite_delete",
    "sprite_set_alpha_from_sprite",
    "sprite_collision_mask",
    "sound_add",
    "sound_replace",
    "sound_delete",
    "background_duplicate",
    "background_assign",
    "background_add",
    "background_add_background",
    "background_add_alpha",
    "background_replace",
    "background_replace_background",
    "background_replace_alpha",
    "background_create_color",
    "background_create_gradient",
    "background_create_from_screen",
    "background_create_from_surface",
    "background_delete",
    "background_set_alpha_from_background",
    "font_add",
    "font_add_sprite",
    "font_replace",
    "font_replace_sprite",
    "font_delete",
    "path_set_kind",
    "path_set_closed",
    "path_set_precision",
    "path_add",
    "path_delete",
    "path_duplicate",
    "path_assign",
    "path_append",
    "path_add_point",
    "path_insert_point",
    "path_change_point",
    "path_delete_point",
    "path_clear_points",
    "path_reverse",
    "path_mirror",
    "path_flip",
    "path_rotate",
    "path_scale",
    "path_shift",
    "timeline_add",
    "timeline_delete",
    "timeline_moment_add",
    "timeline_moment_clear",
    "timeline_clear",
    "object_set_sprite",
    "object_set_solid",
    "object_set_visible",
    "object_set_depth",
    "object_set_persistent",
    "object_set_mask",
    "object_set_parent",
    "object_add",
    "object_delete",
    "object_event_add",
    "object_event_clear",
    "room_set_width",
    "room_set_height",
    "room_set_caption",
    "room_set_persistent",
    "room_set_code",
    "room_set_background_color",
    "room_set_background",
    "room_set_view",
    "room_set_view_enabled",
    "room_add",
    "room_duplicate",
    "room_assign",
    "room_instance_add",
    "room_instance_clear",
    "room_tile_add",
    "room_tile_add_ext",
    "room_tile_clear",
    "sprite_exists",
    "sprite_get_name",
    "sprite_get_number",
    "sprite_get_width",
    "sprite_get_height",
    "sprite_get_transparent",
    "sprite_get_smooth",
    "sprite_get_preload",
    "sprite_get_xoffset",
    "sprite_get_yoffset",
    "sprite_get_bbox_left",
    "sprite_get_bbox_right",
    "sprite_get_bbox_top",
    "sprite_get_bbox_bottom",
    "sprite_get_bbox_mode",
    "sprite_get_precise",
    "sprite_save",
    "sprite_save_strip",
    "sound_exists",
    "sound_get_name",
    "sound_get_kind",
    "sound_get_preload",
    "sound_discard",
    "sound_restore",
    "background_exists",
    "background_get_name",
    "background_get_width",
    "background_get_height",
    "background_get_transparent",
    "background_get_smooth",
    "background_get_preload",
    "background_save",
    "font_exists",
    "font_get_name",
    "font_get_fontname",
    "font_get_bold",
    "font_get_italic",
    "font_get_first",
    "font_get_last",
    "path_exists",
    "path_get_name",
    "path_get_length",
    "path_get_kind",
    "path_get_closed",
    "path_get_precision",
    "path_get_number",
    "path_get_point_x",
    "path_get_point_y",
    "path_get_point_speed",
    "path_get_x",
    "path_get_y",
    "path_get_speed",
    "script_exists",
    "script_get_name",
    "script_get_text",
    "timeline_exists",
    "timeline_get_name",
    "object_exists",
    "object_get_name",
    "object_get_sprite",
    "object_get_solid",
    "object_get_visible",
    "object_get_depth",
    "object_get_persistent",
    "object_get_mask",
    "object_get_parent",
    "object_is_ancestor",
    "room_exists",
    "room_get_name",
    "draw_sprite",
    "draw_sprite_stretched",
    "draw_sprite_tiled",
    "draw_sprite_part",
    "draw_background",
    "draw_background_stretched",
    "draw_background_tiled",
    "draw_background_part",
    "draw_sprite_ext",
    "draw_sprite_stretched_ext",
    "draw_sprite_tiled_ext",
    "draw_sprite_part_ext",
    "draw_sprite_general",
    "draw_background_ext",
    "draw_background_stretched_ext",
    "draw_background_tiled_ext",
    "draw_background_part_ext",
    "draw_background_general",
    "draw_clear",
    "draw_clear_alpha",
    "draw_point",
    "draw_line",
    "draw_line_width",
    "draw_rectangle",
    "draw_roundrect",
    "draw_triangle",
    "draw_circle",
    "draw_ellipse",
    "draw_set_circle_precision",
    "draw_arrow",
    "draw_button",
    "draw_path",
    "draw_healthbar",
    "draw_set_color",
    "draw_set_alpha",
    "draw_get_color",
    "draw_get_alpha",
    "make_color_rgb",
    "make_color_hsv",
    "color_get_red",
    "color_get_green",
    "color_get_blue",
    "color_get_hue",
    "color_get_saturation",
    "color_get_value",
    "merge_color",
    "draw_getpixel",
    "screen_save",
    "screen_save_part",
    "draw_set_font",
    "draw_set_halign",
    "draw_set_valign",
    "draw_text",
    "draw_text_ext",
    "string_width",
    "string_height",
    "string_width_ext",
    "string_height_ext",
    "draw_text_transformed",
    "draw_text_ext_transformed",
    "draw_text_color",
    "draw_text_ext_color",
    "draw_text_transformed_color",
    "draw_text_ext_transformed_color",
    "draw_point_color",
    "draw_line_color",
    "draw_line_width_color",
    "draw_rectangle_color",
    "draw_roundrect_color",
    "draw_triangle_color",
    "draw_circle_color",
    "draw_ellipse_color",
    "draw_primitive_begin",
    "draw_vertex",
    "draw_vertex_color",
    "draw_primitive_end",
    "sprite_get_texture",
    "background_get_texture",
    "texture_preload",
    "texture_set_priority",
    "texture_get_width",
    "texture_get_height",
    "draw_primitive_begin_texture",
    "draw_vertex_texture",
    "draw_vertex_texture_color",
    "texture_set_interpolation",
    "texture_set_blending",
    "texture_set_repeat",
    "draw_set_blend_mode",
    "draw_set_blend_mode_ext",
    "surface_create",
    "surface_free",
    "surface_exists",
    "surface_get_width",
    "surface_get_height",
    "surface_get_texture",
    "surface_set_target",
    "surface_reset_target",
    "surface_getpixel",
    "surface_save",
    "surface_save_part",
    "draw_surface",
    "draw_surface_stretched",
    "draw_surface_tiled",
    "draw_surface_part",
    "draw_surface_ext",
    "draw_surface_stretched_ext",
    "draw_surface_tiled_ext",
    "draw_surface_part_ext",
    "draw_surface_general",
    "surface_copy",
    "surface_copy_part",
    "tile_add",
    "tile_delete",
    "tile_exists",
    "tile_get_x",
    "tile_get_y",
    "tile_get_left",
    "tile_get_top",
    "tile_get_width",
    "tile_get_height",
    "tile_get_depth",
    "tile_get_visible",
    "tile_get_xscale",
    "tile_get_yscale",
    "tile_get_background",
    "tile_get_blend",
    "tile_get_alpha",
    "tile_set_position",
    "tile_set_region",
    "tile_set_background",
    "tile_set_visible",
    "tile_set_depth",
    "tile_set_scale",
    "tile_set_blend",
    "tile_set_alpha",
    "tile_layer_hide",
    "tile_layer_show",
    "tile_layer_delete",
    "tile_layer_shift",
    "tile_layer_find",
    "tile_layer_delete_at",
    "tile_layer_depth",
    "display_get_width",
    "display_get_height",
    "display_get_colordepth",
    "display_get_frequency",
    "display_set_size",
    "display_set_colordepth",
    "display_set_frequency",
    "display_set_all",
    "display_test_all",
    "display_reset",
    "display_mouse_get_x",
    "display_mouse_get_y",
    "display_mouse_set",
    "window_set_visible",
    "window_get_visible",
    "window_set_fullscreen",
    "window_get_fullscreen",
    "window_set_showborder",
    "window_get_showborder",
    "window_set_showicons",
    "window_get_showicons",
    "window_set_stayontop",
    "window_get_stayontop",
    "window_set_sizeable",
    "window_get_sizeable",
    "window_set_caption",
    "window_get_caption",
    "window_set_cursor",
    "window_get_cursor",
    "window_set_color",
    "window_get_color",
    "window_set_region_scale",
    "window_get_region_scale",
    "window_set_position",
    "window_set_size",
    "window_set_rectangle",
    "window_center",
    "window_default",
    "window_get_x",
    "window_get_y",
    "window_get_width",
    "window_get_height",
    "window_mouse_get_x",
    "window_mouse_get_y",
    "window_mouse_set",
    "window_set_region_size",
    "window_get_region_width",
    "window_get_region_height",
    "window_view_mouse_get_x",
    "window_view_mouse_get_y",
    "window_view_mouse_set",
    "window_views_mouse_get_x",
    "window_views_mouse_get_y",
    "window_views_mouse_set",
    "screen_redraw",
    "screen_refresh",
    "set_automatic_draw",
    "set_synchronization",
    "screen_wait_vsync",
    "window_handle",
    "keyboard_set_map",
    "keyboard_get_map",
    "keyboard_unset_map",
    "keyboard_check",
    "keyboard_check_pressed",
    "keyboard_check_released",
    "keyboard_check_direct",
    "keyboard_get_numlock",
    "keyboard_set_numlock",
    "keyboard_key_press",
    "keyboard_key_release",
    "keyboard_clear",
    "io_clear",
    "io_handle",
    "keyboard_wait",
    "mouse_check_button",
    "mouse_check_button_pressed",
    "mouse_check_button_released",
    "mouse_wheel_up",
    "mouse_wheel_down",
    "mouse_clear",
    "mouse_wait",
    "joystick_exists",
    "joystick_name",
    "joystick_axes",
    "joystick_buttons",
    "joystick_has_pov",
    "joystick_direction",
    "joystick_check_button",
    "joystick_xpos",
    "joystick_ypos",
    "joystick_zpos",
    "joystick_rpos",
    "joystick_upos",
    "joystick_vpos",
    "joystick_pov",
    "file_text_open_read",
    "file_text_open_write",
    "file_text_open_append",
    "file_text_close",
    "file_text_write_string",
    "file_text_write_real",
    "file_text_writeln",
    "file_text_read_string",
    "file_text_read_real",
    "file_text_readln",
    "file_text_eof",
    "file_text_eoln",
    "file_exists",
    "file_delete",
    "file_rename",
    "file_copy",
    "directory_exists",
    "directory_create",
    "file_find_first",
    "file_find_next",
    "file_find_close",
    "file_attributes",
    "filename_name",
    "filename_path",
    "filename_dir",
    "filename_drive",
    "filename_ext",
    "filename_change_ext",
    "file_bin_open",
    "file_bin_rewrite",
    "file_bin_close",
    "file_bin_size",
    "file_bin_position",
    "file_bin_seek",
    "file_bin_write_byte",
    "file_bin_read_byte",
    "export_include_file",
    "export_include_file_location",
    "discard_include_file",
    "parameter_count",
    "parameter_string",
    "environment_get_variable",
    "disk_free",
    "disk_size",
    "registry_write_string",
    "registry_write_real",
    "registry_read_string",
    "registry_read_real",
    "registry_exists",
    "registry_write_string_ext",
    "registry_write_real_ext",
    "registry_read_string_ext",
    "registry_read_real_ext",
    "registry_exists_ext",
    "registry_set_root",
    "ini_open",
    "ini_close",
    "ini_read_string",
    "ini_read_real",
    "ini_write_string",
    "ini_write_real",
    "ini_key_exists",
    "ini_section_exists",
    "ini_key_delete",
    "ini_section_delete",
    "execute_program",
    "execute_shell",
    "effect_create_below",
    "effect_create_above",
    "effect_clear",
    "part_type_create",
    "part_type_destroy",
    "part_type_exists",
    "part_type_clear",
    "part_type_shape",
    "part_type_sprite",
    "part_type_size",
    "part_type_scale",
    "part_type_orientation",
    "part_type_color1",
    "part_type_color2",
    "part_type_color3",
    "part_type_color_mix",
    "part_type_color_rgb",
    "part_type_color_hsv",
    "part_type_alpha1",
    "part_type_alpha2",
    "part_type_alpha3",
    "part_type_blend",
    "part_type_life",
    "part_type_step",
    "part_type_death",
    "part_type_speed",
    "part_type_direction",
    "part_type_gravity",
    "part_system_create",
    "part_system_destroy",
    "part_system_exists",
    "part_system_clear",
    "part_system_draw_order",
    "part_system_depth",
    "part_system_position",
    "part_system_automatic_update",
    "part_system_automatic_draw",
    "part_system_update",
    "part_system_drawit",
    "part_particles_create",
    "part_particles_create_color",
    "part_particles_clear",
    "part_particles_count",
    "part_emitter_create",
    "part_emitter_destroy",
    "part_emitter_destroy_all",
    "part_emitter_exists",
    "part_emitter_clear",
    "part_emitter_region",
    "part_emitter_burst",
    "part_emitter_stream",
    "part_attractor_create",
    "part_attractor_destroy",
    "part_attractor_destroy_all",
    "part_attractor_exists",
    "part_attractor_clear",
    "part_attractor_position",
    "part_attractor_force",
    "part_destroyer_create",
    "part_destroyer_destroy",
    "part_destroyer_destroy_all",
    "part_destroyer_exists",
    "part_destroyer_clear",
    "part_destroyer_region",
    "part_deflector_destroy",
    "part_deflector_destroy_all",
    "part_deflector_exists",
    "part_deflector_clear",
    "part_deflector_region",
    "part_deflector_kind",
    "part_deflector_friction",
    "part_changer_create",
    "part_changer_destroy",
    "part_changer_destroy_all",
    "part_changer_exists",
    "part_changer_clear",
    "part_changer_region",
    "part_changer_types",
    "part_changer_kind",
    "d3d_start",
    "d3d_end",
    "d3d_set_hidden",
    "d3d_set_perspective",
    "d3d_set_depth",
    "d3d_primitive_begin",
    "d3d_vertex",
    "d3d_vertex_color",
    "d3d_primitive_end",
    "d3d_draw_block",
    "d3d_draw_cylinder",
    "d3d_draw_cone",
    "d3d_draw_ellipsoid",
    "d3d_draw_wall",
    "d3d_draw_floor",
    "d3d_set_projection",
    "d3d_set_projection_ext",
    "d3d_set_projection_ortho",
    "d3d_set_projection_perspective",
    "d3d_transform_set_identity",
    "d3d_transform_set_translation",
    "d3d_transform_set_scaling",
    "d3d_transform_set_rotation_x",
    "d3d_transform_set_rotation_y",
    "d3d_transform_set_rotation_z",
    "d3d_transform_set_rotation_axis",
    "d3d_transform_add_translation",
    "d3d_transform_add_scaling",
    "d3d_transform_add_rotation_x",
    "d3d_transform_add_rotation_y",
    "d3d_transform_add_rotation_z",
    "d3d_transform_add_rotation_axis",
    "d3d_transform_stack_clear",
    "d3d_transform_stack_empty",
    "d3d_transform_stack_push",
    "d3d_transform_stack_pop",
    "d3d_transform_stack_top",
    "d3d_transform_stack_discard",
    "d3d_set_fog",
    "d3d_set_lighting",
    "d3d_set_shading",
    "d3d_light_define_direction",
    "d3d_light_define_point",
    "d3d_light_enable",
    "d3d_vertex_normal",
    "d3d_vertex_normal_color",
    "d3d_vertex_normal_texture",
    "d3d_vertex_normal_texture_color",
    "d3d_model_create",
    "d3d_model_destroy",
    "d3d_model_clear",
    "d3d_model_save",
    "d3d_model_load",
    "d3d_model_draw",
    "d3d_model_primitive_begin",
    "d3d_model_vertex",
    "d3d_model_vertex_color",
    "d3d_model_vertex_texture",
    "d3d_model_vertex_texture_color",
    "d3d_model_vertex_normal",
    "d3d_model_vertex_normal_color",
    "d3d_model_vertex_normal_texture",
    "d3d_model_vertex_normal_texture_color",
    "d3d_model_primitive_end",
    "d3d_model_block",
    "d3d_model_cylinder",
    "d3d_model_cone",
    "d3d_model_ellipsoid",
    "d3d_model_wall",
    "d3d_model_floor"
  };

  int const GM_FUNCTION_COUNT = sizeof( GM_FUNCTION_NAMES ) / sizeof( char* );

  int const self = -1;
  int const other = -2;
  int const all = -3;
  int const noone = -4;
  int const global = -5;
  int const local = -7;
  double const pi = 3.1415926535897932384626433832795;
  int const ev_create = 0;
  int const ev_destroy = 1;
  int const ev_step = 3;
  int const ev_alarm = 2;
  int const ev_keyboard = 5;
  int const ev_mouse = 6;
  int const ev_collision = 4;
  int const ev_other = 7;
  int const ev_draw = 8;
  int const ev_keypress = 9;
  int const ev_keyrelease = 10;
  int const ev_trigger = 11;
  int const ev_left_button = 0;
  int const ev_right_button = 1;
  int const ev_middle_button = 2;
  int const ev_no_button = 3;
  int const ev_left_press = 4;
  int const ev_right_press = 5;
  int const ev_middle_press = 6;
  int const ev_left_release = 7;
  int const ev_right_release = 8;
  int const ev_middle_release = 9;
  int const ev_mouse_enter = 10;
  int const ev_mouse_leave = 11;
  int const ev_mouse_wheel_up = 60;
  int const ev_mouse_wheel_down = 61;
  int const ev_global_left_button = 50;
  int const ev_global_right_button = 51;
  int const ev_global_middle_button = 52;
  int const ev_global_left_press = 53;
  int const ev_global_right_press = 54;
  int const ev_global_middle_press = 55;
  int const ev_global_left_release = 56;
  int const ev_global_right_release = 57;
  int const ev_global_middle_release = 58;
  int const ev_joystick1_left = 16;
  int const ev_joystick1_right = 17;
  int const ev_joystick1_up = 18;
  int const ev_joystick1_down = 19;
  int const ev_joystick1_button1 = 21;
  int const ev_joystick1_button2 = 22;
  int const ev_joystick1_button3 = 23;
  int const ev_joystick1_button4 = 24;
  int const ev_joystick1_button5 = 25;
  int const ev_joystick1_button6 = 26;
  int const ev_joystick1_button7 = 27;
  int const ev_joystick1_button8 = 28;
  int const ev_joystick2_left = 31;
  int const ev_joystick2_right = 32;
  int const ev_joystick2_up = 33;
  int const ev_joystick2_down = 34;
  int const ev_joystick2_button1 = 36;
  int const ev_joystick2_button2 = 37;
  int const ev_joystick2_button3 = 38;
  int const ev_joystick2_button4 = 39;
  int const ev_joystick2_button5 = 40;
  int const ev_joystick2_button6 = 41;
  int const ev_joystick2_button7 = 42;
  int const ev_joystick2_button8 = 43;
  int const ev_outside = 0;
  int const ev_boundary = 1;
  int const ev_game_start = 2;
  int const ev_game_end = 3;
  int const ev_room_start = 4;
  int const ev_room_end = 5;
  int const ev_no_more_lives = 6;
  int const ev_animation_end = 7;
  int const ev_end_of_path = 8;
  int const ev_no_more_health = 9;
  int const ev_close_button = 30;
  int const ev_user0 = 10;
  int const ev_user1 = 11;
  int const ev_user2 = 12;
  int const ev_user3 = 13;
  int const ev_user4 = 14;
  int const ev_user5 = 15;
  int const ev_user6 = 16;
  int const ev_user7 = 17;
  int const ev_user8 = 18;
  int const ev_user9 = 19;
  int const ev_user10 = 20;
  int const ev_user11 = 21;
  int const ev_user12 = 22;
  int const ev_user13 = 23;
  int const ev_user14 = 24;
  int const ev_user15 = 25;
  int const ev_step_normal = 0;
  int const ev_step_begin = 1;
  int const ev_step_end = 2;
  int const vk_nokey = 0;
  int const vk_anykey = 1;
  int const vk_enter = 13;
  int const vk_return = 13;
  int const vk_shift = 16;
  int const vk_control = 17;
  int const vk_alt = 18;
  int const vk_escape = 27;
  int const vk_space = 32;
  int const vk_backspace = 8;
  int const vk_tab = 9;
  int const vk_pause = 19;
  int const vk_printscreen = 44;
  int const vk_left = 37;
  int const vk_right = 39;
  int const vk_up = 38;
  int const vk_down = 40;
  int const vk_home = 36;
  int const vk_end = 35;
  int const vk_delete = 46;
  int const vk_insert = 45;
  int const vk_pageup = 33;
  int const vk_pagedown = 34;
  int const vk_f1 = 112;
  int const vk_f2 = 113;
  int const vk_f3 = 114;
  int const vk_f4 = 115;
  int const vk_f5 = 116;
  int const vk_f6 = 117;
  int const vk_f7 = 118;
  int const vk_f8 = 119;
  int const vk_f9 = 120;
  int const vk_f10 = 121;
  int const vk_f11 = 122;
  int const vk_f12 = 123;
  int const vk_numpad0 = 96;
  int const vk_numpad1 = 97;
  int const vk_numpad2 = 98;
  int const vk_numpad3 = 99;
  int const vk_numpad4 = 100;
  int const vk_numpad5 = 101;
  int const vk_numpad6 = 102;
  int const vk_numpad7 = 103;
  int const vk_numpad8 = 104;
  int const vk_numpad9 = 105;
  int const vk_divide = 111;
  int const vk_multiply = 106;
  int const vk_subtract = 109;
  int const vk_add = 107;
  int const vk_decimal = 110;
  int const vk_lshift = 160;
  int const vk_lcontrol = 162;
  int const vk_lalt = 164;
  int const vk_rshift = 161;
  int const vk_rcontrol = 163;
  int const vk_ralt = 165;
  int const mb_any = -1;
  int const mb_none = 0;
  int const mb_left = 1;
  int const mb_right = 2;
  int const mb_middle = 3;
  int const c_aqua = 16776960;
  int const c_black = 0;
  int const c_blue = 16711680;
  int const c_dkgray = 4210752;
  int const c_fuchsia = 16711935;
  int const c_gray = 8421504;
  int const c_green = 32768;
  int const c_lime = 65280;
  int const c_ltgray = 12632256;
  int const c_maroon = 128;
  int const c_navy = 8388608;
  int const c_olive = 32896;
  int const c_purple = 8388736;
  int const c_red = 255;
  int const c_silver = 12632256;
  int const c_teal = 8421376;
  int const c_white = 16777215;
  int const c_yellow = 65535;
  int const c_orange = 4235519;
  int const fa_left = 0;
  int const fa_center = 1;
  int const fa_right = 2;
  int const fa_top = 0;
  int const fa_middle = 1;
  int const fa_bottom = 2;
  int const pr_pointlist = 1;
  int const pr_linelist = 2;
  int const pr_linestrip = 3;
  int const pr_trianglelist = 4;
  int const pr_trianglestrip = 5;
  int const pr_trianglefan = 6;
  int const bm_normal = 0;
  int const bm_add = 1;
  int const bm_max = 2;
  int const bm_subtract = 3;
  int const bm_zero = 1;
  int const bm_one = 2;
  int const bm_src_color = 3;
  int const bm_inv_src_color = 4;
  int const bm_src_alpha = 5;
  int const bm_inv_src_alpha = 6;
  int const bm_dest_alpha = 7;
  int const bm_inv_dest_alpha = 8;
  int const bm_dest_color = 9;
  int const bm_inv_dest_color = 10;
  int const bm_src_alpha_sat = 11;
  int const cr_default = 0;
  int const cr_none = -1;
  int const cr_arrrow = -2;
  int const cr_cross = -3;
  int const cr_beam = -4;
  int const cr_size_nesw = -6;
  int const cr_size_ns = -7;
  int const cr_size_nwse = -8;
  int const cr_size_we = -9;
  int const cr_uparrow = -10;
  int const cr_hourglass = -11;
  int const cr_drag = -12;
  int const cr_nodrop = -13;
  int const cr_hsplit = -14;
  int const cr_vsplit = -15;
  int const cr_multidrag = -16;
  int const cr_sqlwait = -17;
  int const cr_no = -18;
  int const cr_appstart = -19;
  int const cr_help = -20;
  int const cr_handpoint = -21;
  int const cr_size_all = -22;
  int const se_none = 0;
  int const se_chorus = 1;
  int const se_echo = 2;
  int const se_flanger = 4;
  int const se_gargle = 8;
  int const se_reverb = 16;
  int const se_compressor = 32;
  int const se_equalizer = 64;
  int const fa_readonly = 1;
  int const fa_hidden = 2;
  int const fa_sysfile = 4;
  int const fa_volumeid = 8;
  int const fa_directory = 16;
  int const fa_archive = 32;
  int const ef_explosion = 0;
  int const ef_ring = 1;
  int const ef_ellipse = 2;
  int const ef_firework = 3;
  int const ef_smoke = 4;
  int const ef_smokeup = 5;
  int const ef_star = 6;
  int const ef_spark = 7;
  int const ef_flare = 8;
  int const ef_cloud = 9;
  int const ef_rain = 10;
  int const ef_snow = 11;
  int const pt_shape_pixel = 0;
  int const pt_shape_disk = 1;
  int const pt_shape_square = 2;
  int const pt_shape_line = 3;
  int const pt_shape_star = 4;
  int const pt_shape_circle = 5;
  int const pt_shape_ring = 6;
  int const pt_shape_sphere = 7;
  int const pt_shape_flare = 8;
  int const pt_shape_spark = 9;
  int const pt_shape_explosion = 10;
  int const pt_shape_cloud = 11;
  int const pt_shape_smoke = 12;
  int const pt_shape_snow = 13;
  int const ps_distr_linear = 0;
  int const ps_distr_gaussian = 1;
  int const ps_distr_invgaussian = 2;
  int const ps_shape_rectangle = 0;
  int const ps_shape_ellipse = 1;
  int const ps_shape_diamond = 2;
  int const ps_shape_line = 3;
  int const ps_force_constant = 0;
  int const ps_force_linear = 1;
  int const ps_force_quadratic = 2;
  int const ps_deflect_vertical = 0;
  int const ps_deflect_horizontal = 1;
  int const ps_change_all = 0;
  int const ps_change_shape = 1;
  int const ps_change_motion = 2;
  int const ty_real = 0;
  int const ty_string = 1;
  int const dll_cdecl = 0;
  int const dll_stdcall = 1;

}
