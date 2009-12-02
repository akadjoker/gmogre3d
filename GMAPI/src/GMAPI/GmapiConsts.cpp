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

  Copyright 2009 (C) Snake (http://www.sgames.ovh.org)
***************************************************************************/


#include "GmapiConsts.h"

namespace gm {
  const unsigned long GM_VERSION_INCOMPATIBLE = 0;
  const unsigned long GM_VERSION_61           = 61;
  const unsigned long GM_VERSION_70           = 70;

  const unsigned long GMAPI_INITIALIZATION_SUCCESS = 0;
  const unsigned long GMAPI_INITIALIZATION_FAILED  = 1;
  const unsigned long GMAPI_ALREADY_INITIALIZED    = 2;

  const char* GM70_ADDRESS_ARRAY_SWAP_BYTES                     = (char*) 0x005CA768;
  const void* GM61_ADDRESS_CURRENT_ROOM_PTR                     = (void*) 0x0055D2F0;
  const void* GM70_ADDRESS_CURRENT_ROOM_PTR                     = (void*) 0x005AF2F4;
  const PGMVARIABLELIST* GM61_ADDRESS_GLOBAL_VARIABLE_LIST_PTR = (PGMVARIABLELIST*) 0x0055DBF8;
  const PGMVARIABLELIST* GM70_ADDRESS_GLOBAL_VARIABLE_LIST_PTR = (PGMVARIABLELIST*) 0x00589720;
  const PGMFUNCTIONINFOSTORAGE GM61_ADDRESS_ARRAY_GMFUNCTIONS  = (PGMFUNCTIONINFOSTORAGE) 0x00538550;
  const PGMFUNCTIONINFOSTORAGE GM70_ADDRESS_ARRAY_GMFUNCTIONS  = (PGMFUNCTIONINFOSTORAGE) 0x00589744;
  const PGMSURFACE* GM61_ADDRESS_ARRAY_SURFACES                = (PGMSURFACE*) 0x0055D148;
  const PGMSURFACE* GM70_ADDRESS_ARRAY_SURFACES                = (PGMSURFACE*) 0x005AF14C;
  const PGMTEXTURE* GM61_ADDRESS_ARRAY_TEXTURES                = (PGMTEXTURE*) 0x0055D228;
  const PGMTEXTURE* GM70_ADDRESS_ARRAY_TEXTURES                = (PGMTEXTURE*) 0x005AF22C;
  const int* GM61_ADDRESS_ARRAYSIZE_SURFACES                    = (int*) 0x005379E4;
  const int* GM70_ADDRESS_ARRAYSIZE_SURFACES                    = (int*) 0x00587A54;
  const PGMSPRITESTORAGE GM61_ADDRESS_STORAGE_SPRITES          = (PGMSPRITESTORAGE) 0x00537A40;
  const PGMSPRITESTORAGE GM70_ADDRESS_STORAGE_SPRITES          = (PGMSPRITESTORAGE) 0x00587AB0;
  const PGMBACKGROUNDSTORAGE GM61_ADDRESS_STORAGE_BACKGROUNDS  = (PGMBACKGROUNDSTORAGE) 0x00537A4C;
  const PGMBACKGROUNDSTORAGE GM70_ADDRESS_STORAGE_BACKGROUNDS  = (PGMBACKGROUNDSTORAGE) 0x00587ABC;
  const PGMSCRIPTSTORAGE GM61_ADDRESS_STORAGE_SCRIPTS          = (PGMSCRIPTSTORAGE) 0x0053853C;
  const PGMSCRIPTSTORAGE GM70_ADDRESS_STORAGE_SCRIPTS          = (PGMSCRIPTSTORAGE) 0x00589730;
  const PGMDIRECT3DINFO GM61_ADDRESS_STORAGE_D3D               = (PGMDIRECT3DINFO) 0x005379F0;
  const PGMDIRECT3DINFO GM70_ADDRESS_STORAGE_D3D               = (PGMDIRECT3DINFO) 0x00587A60;
  const PGMSOUNDSTORAGE GM61_ADDRESS_SOUND_STORAGE             = (PGMSOUNDSTORAGE) 0x00537850;
  const PGMSOUNDSTORAGE GM70_ADDRESS_SOUND_STORAGE             = (PGMSOUNDSTORAGE) 0x005878C0;

  const DWORD* GM61_ADDRESS_TRUNNER_INSTANCE                    = (DWORD*) 0x00535414;
  const DWORD* GM61_ADDRESS_TDEBUG_INSTANCE                     = (DWORD*) 0x005678C4;
  const DWORD* GM70_ADDRESS_TRUNNER_INSTANCE                    = (DWORD*) 0x00585414;
  const DWORD* GM70_ADDRESS_TDEBUG_INSTANCE                     = (DWORD*) 0x005BAB04;
  const DWORD* GM70_ADDRESS_TSCORE_INSTANCE                     = (DWORD*) 0x005AF49C;

  const PGMINSTANCE* GMAPI_CURRENT_INSTANCE_PTR                = (PGMINSTANCE*) 0x00400804;

  const char* STR_GMAPI_ERROR = "GMAPI error";
  const char* STR_GMAPI_DEBUG = "Debug info";
  const char* STR_NO_ACCESS = "<Unable to access resource>";

  const char* EXC_UNKNOWN = "Unexpected error occured.";
  const char* EXC_SPRITENOTEXISTS = "Trying to access non existing sprite.";
  const char* EXC_BACKGROUNDNOTEXISTS = "Trying to access non existing background.";
  const char* EXC_SCRIPTNOTEXISTS = "Trying to access non existing script.";
  const char* EXC_SOUNDNOTEXISTS = "Trying to access non existing sound.";
  const char* EXC_SURFACENOTEXISTS = "Trying to access non existing surface.";
  const char* EXC_INVALIDSUBIMAGE = "Trying to access invalid sprite subimage.";

  const char* GM_FUNCTION_NAMES[] = {
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
    "sprite_add_alpha",
    "sprite_replace",
    "sprite_replace_alpha",
    "sprite_create_from_screen",
    "sprite_add_from_screen",
    "sprite_create_from_surface",
    "sprite_add_from_surface",
    "sprite_delete",
    "sprite_set_alpha_from_sprite",
    "sound_add",
    "sound_replace",
    "sound_delete",
    "background_duplicate",
    "background_assign",
    "background_add",
    "background_add_alpha",
    "background_replace",
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

  const int GM_FUNCTION_COUNT = sizeof( GM_FUNCTION_NAMES ) / sizeof( char* );

  const int self = -1;
  const int other = -2;
  const int all = -3;
  const int noone = -4;
  const int global = -5;
  const int local = -7;
  const double pi = 3.14159265;
  const int ev_create = 0;
  const int ev_destroy = 1;
  const int ev_step = 3;
  const int ev_alarm = 2;
  const int ev_keyboard = 5;
  const int ev_mouse = 6;
  const int ev_collision = 4;
  const int ev_other = 7;
  const int ev_draw = 8;
  const int ev_keypress = 9;
  const int ev_keyrelease = 10;
  const int ev_left_button = 0;
  const int ev_right_button = 1;
  const int ev_middle_button = 2;
  const int ev_no_button = 3;
  const int ev_left_press = 4;
  const int ev_right_press = 5;
  const int ev_middle_press = 6;
  const int ev_left_release = 7;
  const int ev_right_release = 8;
  const int ev_middle_release = 9;
  const int ev_mouse_enter = 10;
  const int ev_mouse_leave = 11;
  const int ev_mouse_wheel_up = 60;
  const int ev_mouse_wheel_down = 61;
  const int ev_global_left_button = 50;
  const int ev_global_right_button = 51;
  const int ev_global_middle_button = 52;
  const int ev_global_left_press = 53;
  const int ev_global_right_press = 54;
  const int ev_global_middle_press = 55;
  const int ev_global_left_release = 56;
  const int ev_global_right_release = 57;
  const int ev_global_middle_release = 58;
  const int ev_joystick1_left = 16;
  const int ev_joystick1_right = 17;
  const int ev_joystick1_up = 18;
  const int ev_joystick1_down = 19;
  const int ev_joystick1_button1 = 21;
  const int ev_joystick1_button2 = 22;
  const int ev_joystick1_button3 = 23;
  const int ev_joystick1_button4 = 24;
  const int ev_joystick1_button5 = 25;
  const int ev_joystick1_button6 = 26;
  const int ev_joystick1_button7 = 27;
  const int ev_joystick1_button8 = 28;
  const int ev_joystick2_left = 31;
  const int ev_joystick2_right = 32;
  const int ev_joystick2_up = 33;
  const int ev_joystick2_down = 34;
  const int ev_joystick2_button1 = 36;
  const int ev_joystick2_button2 = 37;
  const int ev_joystick2_button3 = 38;
  const int ev_joystick2_button4 = 39;
  const int ev_joystick2_button5 = 40;
  const int ev_joystick2_button6 = 41;
  const int ev_joystick2_button7 = 42;
  const int ev_joystick2_button8 = 43;
  const int ev_outside = 0;
  const int ev_boundary = 1;
  const int ev_game_start = 2;
  const int ev_game_end = 3;
  const int ev_room_start = 4;
  const int ev_room_end = 5;
  const int ev_no_more_lives = 6;
  const int ev_animation_end = 7;
  const int ev_end_of_path = 8;
  const int ev_no_more_health = 9;
  const int ev_close_button = 30;
  const int ev_user0 = 10;
  const int ev_user1 = 11;
  const int ev_user2 = 12;
  const int ev_user3 = 13;
  const int ev_user4 = 14;
  const int ev_user5 = 15;
  const int ev_user6 = 16;
  const int ev_user7 = 17;
  const int ev_user8 = 18;
  const int ev_user9 = 19;
  const int ev_user10 = 20;
  const int ev_user11 = 21;
  const int ev_user12 = 22;
  const int ev_user13 = 23;
  const int ev_user14 = 24;
  const int ev_user15 = 25;
  const int ev_step_normal = 0;
  const int ev_step_begin = 1;
  const int ev_step_end = 2;
  const int vk_nokey = 0;
  const int vk_anykey = 1;
  const int vk_enter = 13;
  const int vk_return = 13;
  const int vk_shift = 16;
  const int vk_control = 17;
  const int vk_alt = 18;
  const int vk_escape = 27;
  const int vk_space = 32;
  const int vk_backspace = 8;
  const int vk_tab = 9;
  const int vk_pause = 19;
  const int vk_printscreen = 44;
  const int vk_left = 37;
  const int vk_right = 39;
  const int vk_up = 38;
  const int vk_down = 40;
  const int vk_home = 36;
  const int vk_end = 35;
  const int vk_delete = 46;
  const int vk_insert = 45;
  const int vk_pageup = 33;
  const int vk_pagedown = 34;
  const int vk_f1 = 112;
  const int vk_f2 = 113;
  const int vk_f3 = 114;
  const int vk_f4 = 115;
  const int vk_f5 = 116;
  const int vk_f6 = 117;
  const int vk_f7 = 118;
  const int vk_f8 = 119;
  const int vk_f9 = 120;
  const int vk_f10 = 121;
  const int vk_f11 = 122;
  const int vk_f12 = 123;
  const int vk_numpad0 = 96;
  const int vk_numpad1 = 97;
  const int vk_numpad2 = 98;
  const int vk_numpad3 = 99;
  const int vk_numpad4 = 100;
  const int vk_numpad5 = 101;
  const int vk_numpad6 = 102;
  const int vk_numpad7 = 103;
  const int vk_numpad8 = 104;
  const int vk_numpad9 = 105;
  const int vk_divide = 111;
  const int vk_multiply = 106;
  const int vk_subtract = 109;
  const int vk_add = 107;
  const int vk_decimal = 110;
  const int vk_lshift = 160;
  const int vk_lcontrol = 162;
  const int vk_lalt = 164;
  const int vk_rshift = 161;
  const int vk_rcontrol = 163;
  const int vk_ralt = 165;
  const int mb_any = -1;
  const int mb_none = 0;
  const int mb_left = 1;
  const int mb_right = 2;
  const int mb_middle = 3;
  const int c_aqua = 16776960;
  const int c_black = 0;
  const int c_blue = 16711680;
  const int c_dkgray = 4210752;
  const int c_fuchsia = 16711935;
  const int c_gray = 8421504;
  const int c_green = 32768;
  const int c_lime = 65280;
  const int c_ltgray = 12632256;
  const int c_maroon = 128;
  const int c_navy = 8388608;
  const int c_olive = 32896;
  const int c_purple = 8388736;
  const int c_red = 255;
  const int c_silver = 12632256;
  const int c_teal = 8421376;
  const int c_white = 16777215;
  const int c_yellow = 65535;
  const int c_orange = 4235519;
  const int fa_left = 0;
  const int fa_center = 1;
  const int fa_right = 2;
  const int fa_top = 0;
  const int fa_middle = 1;
  const int fa_bottom = 2;
  const int pr_pointlist = 1;
  const int pr_linelist = 2;
  const int pr_linestrip = 3;
  const int pr_trianglelist = 4;
  const int pr_trianglestrip = 5;
  const int pr_trianglefan = 6;
  const int bm_normal = 0;
  const int bm_add = 1;
  const int bm_max = 2;
  const int bm_subtract = 3;
  const int bm_zero = 1;
  const int bm_one = 2;
  const int bm_src_color = 3;
  const int bm_inv_src_color = 4;
  const int bm_src_alpha = 5;
  const int bm_inv_src_alpha = 6;
  const int bm_dest_alpha = 7;
  const int bm_inv_dest_alpha = 8;
  const int bm_dest_color = 9;
  const int bm_inv_dest_color = 10;
  const int bm_src_alpha_sat = 11;
  const int cr_default = 0;
  const int cr_none = -1;
  const int cr_arrrow = -2;
  const int cr_cross = -3;
  const int cr_beam = -4;
  const int cr_size_nesw = -6;
  const int cr_size_ns = -7;
  const int cr_size_nwse = -8;
  const int cr_size_we = -9;
  const int cr_uparrow = -10;
  const int cr_hourglass = -11;
  const int cr_drag = -12;
  const int cr_nodrop = -13;
  const int cr_hsplit = -14;
  const int cr_vsplit = -15;
  const int cr_multidrag = -16;
  const int cr_sqlwait = -17;
  const int cr_no = -18;
  const int cr_appstart = -19;
  const int cr_help = -20;
  const int cr_handpoint = -21;
  const int cr_size_all = -22;
  const int se_none = 0;
  const int se_chorus = 1;
  const int se_echo = 2;
  const int se_flanger = 4;
  const int se_gargle = 8;
  const int se_reverb = 16;
  const int se_compressor = 32;
  const int se_equalizer = 64;
  const int fa_readonly = 1;
  const int fa_hidden = 2;
  const int fa_sysfile = 4;
  const int fa_volumeid = 8;
  const int fa_directory = 16;
  const int fa_archive = 32;
  const int ef_explosion = 0;
  const int ef_ring = 1;
  const int ef_ellipse = 2;
  const int ef_firework = 3;
  const int ef_smoke = 4;
  const int ef_smokeup = 5;
  const int ef_star = 6;
  const int ef_spark = 7;
  const int ef_flare = 8;
  const int ef_cloud = 9;
  const int ef_rain = 10;
  const int ef_snow = 11;
  const int pt_shape_pixel = 0;
  const int pt_shape_disk = 1;
  const int pt_shape_square = 2;
  const int pt_shape_line = 3;
  const int pt_shape_star = 4;
  const int pt_shape_circle = 5;
  const int pt_shape_ring = 6;
  const int pt_shape_sphere = 7;
  const int pt_shape_flare = 8;
  const int pt_shape_spark = 9;
  const int pt_shape_explosion = 10;
  const int pt_shape_cloud = 11;
  const int pt_shape_smoke = 12;
  const int ps_distr_linear = 0;
  const int ps_distr_gaussian = 1;
  const int ps_distr_invgaussian = 2;
  const int ps_shape_rectangle = 0;
  const int ps_shape_ellipse = 1;
  const int ps_shape_diamond = 2;
  const int ps_shape_line = 3;
  const int ps_force_constant = 0;
  const int ps_force_linear = 1;
  const int ps_force_quadratic = 2;
  const int ps_deflect_vertical = 0;
  const int ps_deflect_horizontal = 1;
  const int ps_change_all = 0;
  const int ps_change_shape = 1;
  const int ps_change_motion = 2;
  const int ty_real = 0;
  const int ty_string = 1;
  const int dll_cdecl = 0;
  const int dll_stdcall = 1;

}