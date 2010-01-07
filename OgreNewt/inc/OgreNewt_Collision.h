/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_COLLISION
#define _INCLUDE_OGRENEWT_COLLISION


#include "OgreNewt_Prerequisites.h"


// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{


enum _OgreNewtExport CollisionPrimitiveType
{
    BoxPrimitiveType                =   SERIALIZE_ID_BOX,
    ConePrimitiveType               =   SERIALIZE_ID_CONE,
    EllipsoidPrimitiveType          =   SERIALIZE_ID_SPHERE,
    CapsulePrimitiveType            =   SERIALIZE_ID_CAPSULE,
    CylinderPrimitiveType           =   SERIALIZE_ID_CYLINDER,
    CompoundCollisionPrimitiveType  =   SERIALIZE_ID_COMPOUND,
    ConvexHullPrimitiveType         =   SERIALIZE_ID_CONVEXHULL,
    ConvexHullModifierPrimitiveType =   SERIALIZE_ID_CONVEXMODIFIER,
    ChamferCylinderPrimitiveType    =   SERIALIZE_ID_CHAMFERCYLINDER,
    TreeCollisionPrimitiveType      =   SERIALIZE_ID_TREE,
    NullPrimitiveType               =   SERIALIZE_ID_NULL,
    HeighFieldPrimitiveType         =   SERIALIZE_ID_HEIGHTFIELD,
    ScenePrimitiveType              =   SERIALIZE_ID_SCENE
};

/*
    CLASS DEFINITION:

        Collision

    USE:
        this class represents a NewtonCollision, which is the newton structure
        for collision geometry.
*/
//! represents a shape for collision detection
class _OgreNewtExport Collision
{
public:

    //! constructor
    Collision( const World* world );

	//! constructor
	Collision( const Collision& shape);

	//! constructor
	Collision( const NewtonCollision* collision, const World* world);


    //! destructor
    virtual ~Collision();

    //! retrieve the Newton pointer
    /*!
        retrieves the pointer to the NewtonCollision object.
    */
    const NewtonCollision* getNewtonCollision() const { return m_col; }

    /*!
        Returns the Newton world this collision belongs to.
    */
    const World* getWorld() const {return m_world;}

//    this is not possible any more (since newton 2.04), you can only set the id when creating the collision
//    //! set a user ID for collision callback identification
//    /*!
//        you can set different IDs for each piece in a compound collision object, and then use these IDs in a collision callback to
//        determine which part is currently colliding.
//    */
//    void setUserID( unsigned id ) const { NewtonCollisionSetUserID( m_col, id); }

    //! get user ID, for collision callback identification
    unsigned getUserID() const { return NewtonCollisionGetUserID( m_col ); }

    //! make unique
    void makeUnique();

    //! get the Axis-Aligned Bounding Box for this collision shape.
    /*!
     * \warning The returned AABB can be too large! If you need an AABB that fits exactly use the OgreNewt::CollisionTools::CalculateFittingAABB function
    */
    Ogre::AxisAlignedBox getAABB( const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY, const Ogre::Vector3& pos = Ogre::Vector3::ZERO ) const;

    //! Returns the Collisiontype for this Collision
    CollisionPrimitiveType getCollisionPrimitiveType() const { return getCollisionPrimitiveType( m_col ); } 

    //! Returns the Collisiontype for the given Newton-Collision
    static CollisionPrimitiveType getCollisionPrimitiveType(const NewtonCollision *col);

    //! friend functions for the Serializer
    friend class OgreNewt::CollisionSerializer;
    //friend void CollisionSerializer::exportCollision(const CollisionPtr& collision, const Ogre::String& filename);
    //friend CollisionPtr CollisionSerializer::importCollision(Ogre::DataStreamPtr& stream, OgreNewt::World* world);

protected:

    NewtonCollision* m_col;
    const World* m_world;

};



//! represents a collision shape that is explicitly convex.
class _OgreNewtExport ConvexCollision : public Collision
{
public:
    //! constructor
    ConvexCollision( const World* world );

	//! constructor
	ConvexCollision(const Collision& convexShape);

	//! constructor
	ConvexCollision(const ConvexCollision& convexShape);

    //! destructor
    ~ConvexCollision();

    //! calculate the volume of the collision shape, useful for buoyancy calculations.
    Ogre::Real calculateVolume() const { return (Ogre::Real)NewtonConvexCollisionCalculateVolume( m_col ); }

    //! calculate the moment of inertia for this collision primitive, along with the theoretical center-of-mass for this shape.
    void calculateInertialMatrix( Ogre::Vector3& inertia, Ogre::Vector3& offset ) const { NewtonConvexCollisionCalculateInertialMatrix( m_col, &inertia.x, &offset.x ); }

    //! returns true, if the collision is a trigger-volume
    bool isTriggerVolume() const { return NewtonCollisionIsTriggerVolume(m_col) != 0; }

    //! set collision as trigger-volume
    /*!
       if a collision is marked as a trigger-volume, there's no calculation of contacts, so
       this acts like an accurate aabb test
    */    
    void setAsTriggerVolume(bool trigger) { NewtonCollisionSetAsTriggerVolume(m_col, (int)trigger); }
};


#ifdef OGRENEWT_NO_COLLISION_SHAREDPTR
typedef Collision* CollisionPtr;
typedef ConvexCollision* ConvexCollisionPtr;
#else
typedef boost::shared_ptr<Collision> CollisionPtr;
typedef boost::shared_ptr<ConvexCollision> ConvexCollisionPtr;
#endif




//! represents a scalable collision shape.
class _OgreNewtExport ConvexModifierCollision : public ConvexCollision
{
public:
    //! constructor
    /*!
      Create a 'blank' box collision object.  Can be used for CollisionSerializer::importCollision
      \param world pointer to the OgreNewt::World
    */
    ConvexModifierCollision( const OgreNewt::World* world );

    //! constructor
    ConvexModifierCollision( const OgreNewt::World* world, const OgreNewt::ConvexCollisionPtr col, int id );

    //! destructor
    ~ConvexModifierCollision();

    //! apply a scalar matrix to the collision
    void setScalarMatrix( const Ogre::Matrix4& mat ) const;

    //! get the scalar matrix for the collision
    Ogre::Matrix4 getScalarMatrix() const;

};


}   // end NAMESPACE OgreNewt

#endif
// _INCLUDE_OGRENEWT_COLLISION

