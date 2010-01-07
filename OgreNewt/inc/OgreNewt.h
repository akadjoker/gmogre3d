/*
    OgreNewt library

    connects Ogre with the Newton Game Dynamics physics library


        by Walaber (http://walaber.com)
        some changes by melven

    main header file.

    current version:  2.07.1

        Newton version: at least 2.07 (beta)

        Ogre version: Shoggoth (1.6.x)

*/

#ifndef _INCLUDE_OGRENEWT_
#define _INCLUDE_OGRENEWT_


#include "OgreNewt_World.h"
#include "OgreNewt_Collision.h"
#include "OgreNewt_Body.h"
#include "OgreNewt_CollisionPrimitives.h"
#include "OgreNewt_CollisionSerializer.h"
#include "OgreNewt_MaterialID.h"
#include "OgreNewt_MaterialPair.h"
#include "OgreNewt_ContactCallback.h"
#include "OgreNewt_ContactJoint.h"
//#include "OgreNewt_Vehicle.h"
#include "OgreNewt_RayCastVehicle.h"
#include "OgreNewt_PlayerController.h"
#include "OgreNewt_RayCast.h"
#include "OgreNewt_ConvexCast.h"

#include "OgreNewt_Joint.h"
#include "OgreNewt_BasicJoints.h"

#include "OgreNewt_Tools.h"
#include "OgreNewt_BodyInAABBIterator.h"
#include "OgreNewt_Debugger.h"

/*! \mainpage OgreNewt Library version 2.07.0 (for newton version 2.07)

    \section into_sec Introduction

    OgreNewt is an OOP wrapper for integrating the Newton Dynamics Physics SDK with OGRE.

    \section problems Problems and missing features in this version

    Problems and missing features in this version
        - HeightFieldCollision
        - PlayerController not finished
        - player controller demo needs to be improved
        - this library supports the newton functions for multithreading but there are several functions/classes in this
          library itself, that are not thread safe (I don't need multiple threads)
        - the copied MovableText class (in Tools::OgreAddons) seems to have some graphics error (it's used
          to show the debugging information above each body)
        - I didn't test several features:
            - vehicle
            - joints
            - treecollision raycastcallback 


    \section new New in this version

    New in this version
        - added a destructor callback for OgreNewt::Joint and OgreNewt::Body (because these can be destroyed indirectly through newton callbacks!)
        - removed CollisionTools::CollisionCalculateAABB (because there's col->getAABB() ) and added a function to calculate the correct AABB
          CollisionTools::CollisionCalculateFittingAABB
        - ConvexCast:
            - added "NormalOnHitPoint"
        - added player controller demo
        - updated to newton 2.07 -- interface breaking changes!
            - added shape-id parameters for collisions (you need to set the shape id if you create the collision, cannot be changed later)
        - CustomJoint:
            - added globalToLocal function
            - feedbackCollector callback
        - first attempts to support multithreading
            - update the nodes of the bodies after the newton world update, because Ogre doesn't support multithreaded access to nodes
            - linux: added a pthread-mutex for Ogre in OgreNewt::World, so it can be used for access to Ogre from multiple threads
        - updated to newton 2.04 -- interface breaking changes (not compatible with newton 2.03!)
        - set the collision id when creating a collision
        - this version uses cmake > 2.6.2!
        - shared pointers for collisions, if you don't want to use shared pointers define OGRENEWT_NO_COLLISION_SHAREDPTR
        - uses Ogre::Any instead of void* as userdata, if you want to use void* define OGRENEWT_NO_OGRE_ANY
        - several interface-breaking changes:
            - the ContactCallback passes a ContactJoint as argument that can be used to iterate through all contacts
              (the callback is not called for each contact any more, but for each pair of colliding bodies!)
            - added a lots of new simple "iterators":
                - for Bodies use body = World->getFirstBody() and body = body->getNext()
                - for the 
            - BodyIterator renamed to BodyInAABBIterator, it does now only iterate through bodies in a specific AABB
            - removed "Singleton-classes", the debugger and the BodyInAABBIterator are now part of a World
              (call world->getDebugger() / world->getBodyInAABBIterator() to use these classes!)
        - added support for trigger-volumes (ConvexCollision::setAsTriggerVolume ...)
        - added support for convexcasts
            - more than one contacts are now supported (removed the hack that prevented a segfault due to an error in newton)
        - added additional debugging features:
            - raycast/convexcast debugging
            - information about each body as billboard above it
        - a lot of minor changes and functions added and renamed


    previous changes...
        - updated to Newton version 2.0!!  Many big improvements and changes to the library, and OgreNewt now supports it.
        - several interface-breaking changes:
            - updated to support multithreading support now native to Newton.
            - MomentOfInertia namespace and helper functions removed entirely.  Newton can now calculate inertia and center of
              mass automatically, use ConvexCollision::calculateInertialMatrix, and multiply by objects Mass.
            - Body::attachToNode has been renamed to attachNode, better implying the relationship between the body and the Ogre::Node.
            - BodyIterator class has been upgraded to use boost::function, allowing the same callback flexibility as other callbacks.

        - bug fix - fixed problem with TreeCollisionSceneParser that wasn't adjusting to different scales properly.
        - optimization - fixed several classes to only write debug data to the LOG when compiled in DEBUG mode:
            - Custom2DJonit
            - BasicFrameListener
        - added the concept of "face-winding" to all TreeCollision classes.  should not cause any breaking changes to code, but allows more flexibility to change the "direction" of a face in treecollisions.
        - OgreNewt and it's demos are now fully compatible with Ogre 1.4.x (Eihort).
        - Addition of script files for compiling under linux (Scons)
        - slight modification to the ContactCallback class to allow access to Newton structures from the outside.
        - some cosmetic changes to make the wrapper compile more easily under Linux and other non-windows platforms.
        - updated to work with the release version of Ogre dagon (1.2)
        - updated to work with version 1.53 of Newton
        - raycast now has an optional pre-filter to ignore specific bodies from the raycast.
        - various other clean-up!
        - moved callback system to much more OOP-friendly "boost::function" system.  callbacks can now be instance-specific member functions!
        - several other small fixes to project files, etc.
        - automatic convex hull generation system added to supplementary ragdoll class (see demo08).
        - documentation updated.
        - updated to Newton version 1.5
        - added this documentation!
        - added buoyancy functionality.
        - New Buoyancy demo.
        - New Ragdoll demo, using a seperate class to implement ragdoll functionality.
        - added basic classes for CustomJoints, and a simple demo showing how they work.
        - added several prebuilt custom joints, including pulleys and gears, and a general 2D joint.
        - added calculateInertialMatrix to ConvexCollision class.
        - added set/getCenterOfMass to Body class
        - changed angle-related functions in BasicJoint classes to use Ogre::Radian instead of Ogre::Real.
        - added ConvexModifierCollision class, which allows for arbitrarily scaled collision primitives.
        - added several low-level collision functions, see the CollisionTools namespace.
        - fixed errors causing run-time crash on Slider and Universal joints.
        - added LeaveWorldCallback functionality to World class.

    \section install Installation

    OgreNewt comes with a project for MSVC++ 7.1 and MSVC++ 8.0 (2005).  unfortunately I have no other IDE's or compilers setup on my system, so I
    cannot provide any other projects.  the MSVC solution should build out of the box, assuming you take a few things into
    consideration.

    unzip this in the ogreaddons directory alongside your "ogrenew" directory.  to compile correctly, it also assumes you have the Newton SDK installed in another
    directory alongside this one called "NewtonSDK".

    for example something like this:

    - c:/programming/Ogre/ogrenew                       <- ogre installation
    - c:/programming/Ogre/ogreaddons/OgreNewt           <- OgreNewt main directory.
    - c:/programming/NewtonSDK                          <- Newton SDK.
    - c:/programming/tinyxml                            <- tinyxml library (needed for ragdoll demo only)

    \section compiling Compiling

    OgreNewt compiles by default to a static library for linking to your project.  However you can also compile OgreNewt into a dynamic DLL on the 
    Windows platform by using the Debug_DLL and Release_DLL solution build configurations in the MSVC solutions.

    \section license License

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.


    well, that's about it!
    have fun!

    -walaber

*/

#endif

