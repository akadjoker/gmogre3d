/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_MATERIALPAIR
#define _INCLUDE_OGRENEWT_MATERIALPAIR


#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_World.h"
#include "OgreNewt_ContactCallback.h"
#include "OgreNewt_MaterialID.h"

// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{


//! define interaction between materials
/*!
    this class represents a pair of Newton MaterialGroupIDs, which is 
    used to define interaction bewteen materials.
*/
class _OgreNewtExport MaterialPair
{
public:

    //! constructor
    /*!
        creates an object representing a pair of materials, and defining how they will interact.
        \param world pointer to the OgreNewt::World
        \param mat1 pointer to first materialID
        \param mat2 pointer to second materialID
    */
    MaterialPair( const World* world, const MaterialID* mat1, const MaterialID* mat2 );

    //! destructor
    ~MaterialPair();


    // set the default behavior for this material pair.

    //! set default softness for the material pair.
    void setDefaultSoftness( Ogre::Real softness ) const { NewtonMaterialSetDefaultSoftness( m_world->getNewtonWorld(), id0->getID(), id1->getID(), (float)softness ); }

    //! set default elasticity for the material pair.
    void setDefaultElasticity( Ogre::Real elasticity ) const { NewtonMaterialSetDefaultElasticity( m_world->getNewtonWorld(), id0->getID(), id1->getID(), (float)elasticity ); }

    //! set default collision for the material pair.
    void setDefaultCollidable( int state ) const { NewtonMaterialSetDefaultCollidable( m_world->getNewtonWorld(), id0->getID(), id1->getID(), state ); }

    //! set the default thickness for this material pair
    void setDefaultSurfaceThickness( float thickness ) const { NewtonMaterialSetSurfaceThickness( m_world->getNewtonWorld(), id0->getID(), id1->getID(), thickness ); }

    //! set default friction for the material pair.
    void setDefaultFriction( Ogre::Real stat, Ogre::Real kinetic ) const { NewtonMaterialSetDefaultFriction( m_world->getNewtonWorld(), id0->getID(), id1->getID(), (float)stat, (float)kinetic ); }

    //! set continuos collision on/off for this material pair
    /*!
        continuous collision mode is an advanced system used to prevent "tunelling", or objects passing through one an other when traveling at high velocities.  
        there is a performance hit involved, so this sould only be used when it is deemed necessary.
    */
    void setContinuousCollisionMode( int state ) const { NewtonMaterialSetContinuousCollisionMode( m_world->getNewtonWorld(), id0->getID(), id1->getID(), state ); }


    //! assign a custom collision callback.
    /*!
        ContactCallbacks allow for custom interaction between bodies of specific materials.
        \param callback pointer to a user-created ContactCallback object
    */
    void setContactCallback( OgreNewt::ContactCallback* callback );


protected:
    const MaterialID*   id0;
    const MaterialID*   id1;
    const World*        m_world;
    OgreNewt::ContactCallback *m_contactcallback;

private:
    //! internal function.
    static int _CDECL collisionCallback_onAABBOverlap( const NewtonMaterial* material, const NewtonBody* body0, const NewtonBody* body1, int threadIndex );
    //! internal function.
    static void _CDECL collisionCallback_contactsProcess(const NewtonJoint* contact, float timeStep, int threadIndex );


};


}   // end NAMESPACE OgreNewt

#endif
// _INCLUDE_OGRENEWT_MATERIALPAIR

