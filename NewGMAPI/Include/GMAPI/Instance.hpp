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
#ifndef GMAPI_INSTANCE_HPP
#define GMAPI_INSTANCE_HPP
#include "Dll.hpp"
namespace gm
{ 
    /**@defgroup instances Instances
     * @brief Objects and functions for working with GM instances.
     */
    ///@{
    class Variables;
    class Variable;
    /**@brief The GM instance structure.*/
    struct Instance
    {
        char _pad0000[4];
        int id;
        char _pad0008[8];//0xFFFFFFFF 0x00000000
        double image_index;
        double image_speed;
        double image_xscale;
        double image_yscale;
        double image_angle;
        double image_alpha;
        char _pad0040[8];//00ffffff ffffffff
        char _pad0048[8];//00000000 00000000
        double x;
        double y;
        double xstart;
        double ystart;
        double xprevious;
        double yprevious;
        double direction;
        double speed;
        double friction;
        double gravity_direction;
        double gravity;
        char _pad00A8[8];//25.0 ?
        char _pad00B0[8];//0584fbe6 c045a690
        char _pad00B8[8];//fffe7960 fffe7960
        char _pad00C0[8];//fffe7960 fffe7960
        char _pad00C8[1];//00 boolean?
        char solid;
        char persistent;
        char _pad00CB[1];//01 boolean?
        unsigned object_index;
        char _pad00D0[4];//changes between runs, pointer?
        int alarm[12];
        Variables *vars;//user variables pointer
        char _pad0108[8];//00000000 ffffffff
        char _pad0110[8];//00000000 00000000
        char _pad0118[8];//00000000 00000000
        double path_speed;
        double path_scale;
        double path_orientation;
        char _pad138[8];//00000000 00000000
        char _pad140[8];//00000000 00000000
        char _pad148[8];//00000000 00000000
        char _pad150[8];//00000000 00000000
        double timeline_position;
        double timeline_speed;
        //possibly more
    };
    
    /**Gets the current GM instance.*/
    GMAPI_DLL Instance *getSelf();
    /**Gets the current GM other instance.*/
    GMAPI_DLL Instance *getOther();
    /**Sets the current GM instance. Note that this only effects DLL's using
     * this API, and upon returning to GM, GM will use the original instance.
     */
    GMAPI_DLL void setSelf(Instance *self);
    /**Sets the current GM other instance.*/
    GMAPI_DLL void setOther(Instance *other);
    
    /**@brief Stores the current GM self and other instances, and restores them
     * when this object goes out of scope.
     */
    class PreserveState
    {
    public:
        PreserveState()
        {
            self  = getSelf();
            other = getOther();
        }
        ~PreserveState()
        {
            setSelf(self);
            setOther(other);
        }
    private:
        Instance *self, *other;
    };
    ///@}
}
#endif
