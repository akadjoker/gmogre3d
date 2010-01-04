/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/

#ifndef _INCLUDE_OGRENEWT_CONVEXCAST
#define _INCLUDE_OGRENEWT_CONVEXCAST


#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_CollisionPrimitives.h"

// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{
//! general convexcast
/*!
    General class representing a convexcast query in the Newton world.  this class should be inherited to create specific convexcast behavior.
*/
class _OgreNewtExport Convexcast
{
public:

    //! constructor
    Convexcast();
    
    //! destuctor.
    virtual ~Convexcast();

    //! performs the convexcast.
    /*!
        call after creating the object.
        \param world pointer to the OgreNewt::World
        \param col pointer to a convex collision shape used for the cast
        \param startpt starting point of ray in global space
        \param colori orientation of the collision in global space
        \param endpt ending point of ray in global space
        \param maxcontactscount maximum number of contacts that should be saved,
               set to 0 if you only need the distance to the first intersection
    */
    void go( const OgreNewt::World* world, const OgreNewt::ConvexCollisionPtr& col, const Ogre::Vector3& startpt, const Ogre::Quaternion &colori, const Ogre::Vector3& endpt, int maxcontactscount, int threadIndex);

    //! user callback pre-filter function.
    /*!
        This function is an optional pre-filter to completely ignore specific bodies during the raycast.
        return false from this function to ignore this body, return true (default) to accept it.
    */
    virtual bool userPreFilterCallback( OgreNewt::Body* body ) { return true; }

protected:

        //! list that stores the results of the convex-cast
        NewtonWorldConvexCastReturnInfo *mReturnInfoList;

        //! the real length of the list
        int mReturnInfoListLength;

        //! the actual maximum length of the list (number of elements memory has been reserved for)
        int mReturnInfoListSize;

        //! distance in [0,1] to first contact
        Ogre::Real mFirstContactDistance;

private:

    //! callback used for running the raycast prefilter... used internally
    static unsigned _CDECL newtonConvexcastPreFilter( const NewtonBody* body, const NewtonCollision* collision, void* userData );
};




//! Basic implementation of the convexcast
/*!
    This class is provided for general convexcast use.  it returns information about the body hit by the convexcast
*/
class _OgreNewtExport BasicConvexcast : public Convexcast
{
public:
    //! simple class that represents a single convexcast contact
    class _OgreNewtExport ConvexcastContactInfo
    {
    public:
        //Ogre::Real              mDistance;                  //!< dist from point1 of the raycast, in range [0,1].
        OgreNewt::Body*         mBody;                      //!< pointer to body intersected with
        int                     mCollisionID;               //!< collision ID of the primitive hit by the ray (for compound collision bodies)
        Ogre::Vector3           mContactNormal;             //!< normal of intersection.
        Ogre::Vector3           mContactNormalOnHitPoint;   //!< surface normal at the surface of the hit body
        Ogre::Vector3           mContactPoint;              //!< point of the contact in global space
        Ogre::Real              mContactPenetration;        //!< contact penetration at collision point

        ConvexcastContactInfo();
        ~ConvexcastContactInfo();
    };


    //! empty constructor
    BasicConvexcast();

    //! constructor
    /*!
        performs a raycast, then the results can be queried from the object after creation.
        \param world pointer to the OgreNewt::World
        \param col pointer to a convex collision shape used for the cast
        \param startpt starting point of ray in global space
        \param colori orientation of the collision in global space
        \param endpt ending point of ray in global space
        \param maxcontactscount maximum number of contacts that should be saved        
    */
    BasicConvexcast( const OgreNewt::World* world, const OgreNewt::ConvexCollisionPtr& col, const Ogre::Vector3& startpt, const Ogre::Quaternion &colori, const Ogre::Vector3& endpt, int maxcontactscount, int threadIndex);

    //! destuctor.
    ~BasicConvexcast();

    // ------------------------------------------------------
    // the following functions can be used to retrieve information about the bodies collided by the convexcast.
    
    //! how many bodies did we hit? if maxcontactscount is to small, this value will be smaller too!
    int calculateBodyHitCount() const;

        //! how many contacts do we have
        int getContactsCount() const;

    //! retrieve the raycast info for a specific hit.
    ConvexcastContactInfo getInfoAt( int hitnum ) const;

        //! retrieve the distance to the first contact (in range [0,1] from startpt to endpt)
        Ogre::Real getDistanceToFirstHit() const;
};


}    // end NAMESPACE OgreNewt
    




#endif    // _INCLUDE_OGRENEWT_RAYCAST

