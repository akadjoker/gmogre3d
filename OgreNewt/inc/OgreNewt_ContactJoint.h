/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by melven
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_CONTACTJOINT
#define _INCLUDE_OGRENEWT_CONTACTJOINT


#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_Body.h"

// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{


//! with this class you can iterate through all contacts
/*!
    this class must not be inherited or instantiated directly in any way, 
    it is passed as argument in the contacsProcess-function of the ContactCallback!
    for iterating through all contacts you can do something like this:
    for(Contact contact = contactJoint.getFirstContact(); contact; contact = contact.getNext())
        ...
*/
class _OgreNewtExport ContactJoint
{
public:

    //! constructor
    ContactJoint(const NewtonJoint* contactJoint);

    //! destructor
    ~ContactJoint();

    //! return the number of contacts
    int getContactCount() const { return NewtonContactJointGetContactCount( m_contactjoint ); }

    //! get the first contact
    Contact getFirstContact();

    //! get the first body
    OgreNewt::Body* getBody0() { return (OgreNewt::Body*) NewtonBodyGetUserData(NewtonJointGetBody0(m_contactjoint)); }

    //! get the second body
    OgreNewt::Body* getBody1() { return (OgreNewt::Body*) NewtonBodyGetUserData(NewtonJointGetBody1(m_contactjoint)); }

    //! get the newton ContactJoint
    const NewtonJoint* _getNewtonContactJoint() { return m_contactjoint; }

    //! get the MaterialPair with the basis material of this contact-joint
    /*!
        you shouldn't need to call this function, it's only used internally
    */
    MaterialPair* getMaterialPair();

protected:
    const NewtonJoint* m_contactjoint;
};



//! with the methods from this class you can set the behavior of each contac-point
/*!
    this class is for creating custom behavior between material GroupIDs.
    this class must not be inherited or instantiated directly in any way,
    you can obtain an object of this class in the contact-callback
    from the contactJoint and iterate through all contacts using the 
    getNext-function
*/
class _OgreNewtExport Contact
{
public:

    //! constructor
    Contact(void *contact, ContactJoint* parent);

    //! destructor
    ~Contact();

    //! return true, if this is not a valid contact (end of the contact-list!)
    operator bool() const { return m_contact != NULL; }

    //! get the next contact from the parent contact-joint
    Contact getNext() const;

    // basic contact control commands... they can only be used, if this is a valid contact ( !contact == false )

    //! get the first body
    OgreNewt::Body* getBody0() const { return (OgreNewt::Body*) NewtonBodyGetUserData( NewtonJointGetBody0( m_parent->_getNewtonContactJoint() ) ); }
    OgreNewt::Body* getBody1() const { return (OgreNewt::Body*) NewtonBodyGetUserData( NewtonJointGetBody1( m_parent->_getNewtonContactJoint() ) ); }

    //! get the face ID of a TreeCollision object
    unsigned getFaceAttribute() const { return NewtonMaterialGetContactFaceAttribute( m_material ); }

    //! get the Collision ID of a body currently colliding
    unsigned getBodyCollisionID( OgreNewt::Body* body ) const { return NewtonMaterialGetBodyCollisionID( m_material, body->getNewtonBody() ); }

    //! speed of the collision
    Ogre::Real getNormalSpeed() const { return (Ogre::Real)NewtonMaterialGetContactNormalSpeed( m_material ); }

    //! force of the collision
    /*!
        only valid for objects in a stable state (sitting on top of each other, etc)
    */
    Ogre::Vector3 getForce() const;

    //! get positoin and normal of the collision
    void getPositionAndNormal( Ogre::Vector3& pos, Ogre::Vector3& norm ) const { NewtonMaterialGetContactPositionAndNormal(m_material, &pos.x, &norm.x); }

    //! get the tangent vectors of the collision
    void getTangentDirections( Ogre::Vector3& dir0, Ogre::Vector3& dir1 ) const { NewtonMaterialGetContactTangentDirections(m_material, &dir0.x, &dir1.x); }

    //! get tangent speed of the collision
    Ogre::Real getTangentSpeed( int index ) const { return (Ogre::Real)NewtonMaterialGetContactTangentSpeed( m_material, index ); }

    //! set softness of the current contact
    void setSoftness( Ogre::Real softness ) { NewtonMaterialSetContactSoftness( m_material, (float)softness ); }

    //! set elasticity of the current contact
    void setElasticity( Ogre::Real elasticity ) { NewtonMaterialSetContactElasticity( m_material, (float)elasticity ); }

    //! set friction state of current contact
    void setFrictionState( int state, int index ) { NewtonMaterialSetContactFrictionState( m_material, state, index ); }

    //! set static friction for current contact
    void setFrictionCoef( Ogre::Real stat, Ogre::Real kinetic, int index ) { NewtonMaterialSetContactFrictionCoef( m_material, (float)stat, (float)kinetic, index ); }

    //! set tangent acceleration for contact
    void setTangentAcceleration( Ogre::Real accel, int index ) { NewtonMaterialSetContactTangentAcceleration( m_material, (float)accel, index ); }

    //! align tangent vectors with a user supplied direction
    void rotateTangentDirections( const Ogre::Vector3& dir ) { NewtonMaterialContactRotateTangentDirections( m_material, &dir.x ); }

    //! manually set the normal for the collision.
    void setNormalDirection( const Ogre::Vector3& dir ) { NewtonMaterialSetContactNormalDirection( m_material, &dir.x ); }

    //! manually set the acceleration along the collision normal.
    void setNormalAcceleration( Ogre::Real accel ) { NewtonMaterialSetContactNormalAcceleration( m_material, accel ); }

    //! removes the contact from the parent contact-joint, this means newton doesn't process this contact
    /*!
        use this function, when you want to ignore this specific contact, but you need to get the next contact before,
        because this will invalidate this class (set all pointers to zero!)
    */
    void remove();

    //! get the NewtonMaterial from this callback.
    NewtonMaterial* _getNewtonMaterial() { return m_material; }

protected:
    NewtonMaterial* m_material;
    void* m_contact;
    OgreNewt::ContactJoint* m_parent;
};


}   // end NAMESPACE OgreNewt

#endif
// _INCLUDE_OGRENEWT_CONTACTJOINT

