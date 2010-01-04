/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_CONTACTCALLBACK
#define _INCLUDE_OGRENEWT_CONTACTCALLBACK


#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_ContactJoint.h"

// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{


//! custom contact behavior
/*!
    this class is for creating custom behavior between material GroupIDs.
    this class must be inherited, and the user functions created, and then
    added to a MaterialPair class.
*/
class _OgreNewtExport ContactCallback
{
public:

    //! constructor
    ContactCallback();

    //! destructor
    virtual ~ContactCallback();

    //! user-defined AABB-overlap function
    /*!
        this function is called when 2 bodies AABB overlap.  they have not yet collided, but *may* do so this loop.
        at this point, m_body0 and m_body1 are defined, but the contact isn't yet valid, so none of the member functions
        can be called yet.  they must be called from the contacsProcess() function.
        return 0 to ignore the collision, 1 to allow it.
    */
    virtual int onAABBOverlap( OgreNewt::Body* body0, OgreNewt::Body* body1, int threadIndex ) { return 1; }

    //! user-defined Process function
    /*!
        user process function.  it is called for each colliding pair of bodies. you can use
        the ContactJoint to iterate through all contact-points and change the "material" of each contact-point!
     */
    virtual void contactsProcess( OgreNewt::ContactJoint &contactJoint, Ogre::Real timeStep, int threadIndex ) { }
};


}   // end NAMESPACE OgreNewt

#endif
// _INCLUDE_OGRENEWT_CONTACTCALLBACK

