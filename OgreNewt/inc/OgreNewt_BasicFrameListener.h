/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.


        by Walaber
        some changes by melven



        "BasicFrameListener"

        this is a simple Ogre FrameListener that will update the Newton world you supply it
        with, at a desired framerate, using a simple time-slicer.  this means the simulation
        should run at the same speed regardless of the actual framerate.  set the update_framerate
        to a higher value for a more accurate simluation.

        NOTE: update_framerate must be a value between [60,600]
*/

#ifndef _INCLUDE_OGRENEWT_BASICFRAMELISTENER
#define _INCLUDE_OGRENEWT_BASICFRAMELISTENER

#include "OgreNewt_Prerequisites.h"

namespace OgreNewt
{


//! simple frame listener to update the physics.
/*!
    updates the Newton World at the specified rate, with time-slicing, and
    also implements a simple debug view, press F3 to render Newto world with lines in 3D view.
*/
    class _OgreNewtExport BasicFrameListener : public Ogre::FrameListener
{
protected:
    OgreNewt::World* m_World;

//    int desired_framerate;
//    Ogre::Real m_update, m_elapsed;


public:
    BasicFrameListener(Ogre::RenderWindow* win, OgreNewt::World* W, int update_framerate = 60);
    ~BasicFrameListener(void);

    bool frameStarted(const Ogre::FrameEvent &evt);
};



}   // end NAMESPACE OgreNewt

#endif /* _INCLUDE_OGRENEWT_BASICFRAMELISTENER */

