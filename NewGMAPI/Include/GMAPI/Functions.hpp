/* Copyright (c) 2011-2012 William Newbery
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
 */

/**@defgroup gm_functions GM Functions & Constants
 * @brief All the builtin GM functions.
 */
#include "Functions/computing_things_clipboard.hpp"
#include "Functions/computing_things_dates.hpp"
#include "Functions/computing_things_real.hpp"
#include "Functions/computing_things_string.hpp"
#include "Functions/dll.hpp"
#include "Functions/ds_grid.hpp"
#include "Functions/ds_list.hpp"
#include "Functions/ds_map.hpp"
#include "Functions/ds_priority_queue.hpp"
#include "Functions/ds_queue.hpp"
#include "Functions/ds_stack.hpp"
#include "Functions/gameplay_collision_checking.hpp"
#include "Functions/gameplay_deactivating_instances.hpp"
#include "Functions/gameplay_events.hpp"
#include "Functions/gameplay_instances.hpp"
#include "Functions/gameplay_misc.hpp"
#include "Functions/gameplay_motion_planning.hpp"
#include "Functions/gameplay_paths.hpp"
#include "Functions/gameplay_rooms.hpp"
#include "Functions/gameply_timing.hpp"
#include "Functions/graphics_display.hpp"
#include "Functions/graphics_draw_advanced.hpp"
#include "Functions/graphics_draw_backgrounds.hpp"
#include "Functions/graphics_draw_shapes.hpp"
#include "Functions/graphics_draw_sprites.hpp"
#include "Functions/graphics_draw_text.hpp"
#include "Functions/graphics_repaint.hpp"
#include "Functions/graphics_surfaces.hpp"
#include "Functions/graphics_tiles.hpp"
#include "Functions/graphics_views.hpp"
#include "Functions/graphics_window.hpp"
#include "Functions/highscore.hpp"
#include "Functions/message_box.hpp"
#include "Functions/resources_backgrounds.hpp"
#include "Functions/resources_fonts.hpp"
#include "Functions/resources_objects.hpp"
#include "Functions/resources_paths.hpp"
#include "Functions/resources_rooms.hpp"
#include "Functions/resources_scripts.hpp"
#include "Functions/resources_sounds.hpp"
#include "Functions/resources_sprites.hpp"
#include "Functions/resources_timelines.hpp"
#include "Functions/ui.hpp"
#include "Functions/ui_joystick.hpp"
#include "Functions/ui_keyboard.hpp"
#include "Functions/ui_mouse.hpp"
#include "Functions/particles.hpp"
#include "Functions/d3d.hpp"
