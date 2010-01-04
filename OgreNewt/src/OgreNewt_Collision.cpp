#include "OgreNewt_stdafx.h"
#include "OgreNewt_Collision.h"
#include "OgreNewt_World.h"
#include "OgreNewt_Tools.h"



namespace OgreNewt
{

    
Collision::Collision( const World* world ) : m_col(NULL)
{
    m_world = world;
}

Collision::Collision( const Collision& shape) : m_col(shape.m_col)
{
	m_world = shape.m_world;
	if (m_col) {
		NewtonAddCollisionReference (m_col);
	}
}

Collision::Collision(const NewtonCollision* collision, const World* world) : m_col((NewtonCollision*)collision)
{
	m_world = world;
	NewtonAddCollisionReference (m_col);
}

Collision::~Collision()
{
    if (m_world->getNewtonWorld() && m_col)
    {
        NewtonReleaseCollision( m_world->getNewtonWorld(), m_col );
    }
}


void Collision::makeUnique()
{
    NewtonCollisionMakeUnique( m_world->getNewtonWorld(), m_col );
}


Ogre::AxisAlignedBox Collision::getAABB( const Ogre::Quaternion& orient, const Ogre::Vector3& pos ) const
{
    Ogre::AxisAlignedBox box;
    
    if( m_col )
    {
//		float matrix[16];
//		Ogre::Vector3 min, max;
//		OgreNewt::Converters::QuatPosToMatrix( orient, pos, matrix );
//		NewtonCollisionCalculateAABB( m_col, matrix, &min.x, &max.x );
//		box = Ogre::AxisAlignedBox(min, max);

		OgreNewt::CollisionPtr ptr (new OgreNewt::Collision (*this));
		box = CollisionTools::CollisionCalculateFittingAABB (ptr, orient, pos );
    }
    return box;
}

CollisionPrimitiveType Collision::getCollisionPrimitiveType(const NewtonCollision *col)
{
    NewtonCollisionInfoRecord *info = new NewtonCollisionInfoRecord();

    NewtonCollisionGetInfo( col, info );

    return static_cast<CollisionPrimitiveType>(info->m_collisionType);
}



ConvexCollision::ConvexCollision( const OgreNewt::World* world ) : Collision( world )
{
}

ConvexCollision::ConvexCollision(const Collision& convexShape) : Collision (convexShape)
{
}

ConvexCollision::ConvexCollision(const ConvexCollision& convexShape) : Collision (convexShape)
{
}

ConvexCollision::~ConvexCollision()
{
}




ConvexModifierCollision::ConvexModifierCollision(const World* world) : ConvexCollision(world)
{
}

ConvexModifierCollision::ConvexModifierCollision(const World* world, const ConvexCollisionPtr col, int id) : ConvexCollision(world)
{
    m_col = NewtonCreateConvexHullModifier( world->getNewtonWorld(), col->getNewtonCollision(), id );
}

ConvexModifierCollision::~ConvexModifierCollision()
{
}

void ConvexModifierCollision::setScalarMatrix( const Ogre::Matrix4& mat ) const
{
    float matrix[16];
    OgreNewt::Converters::Matrix4ToMatrix( mat, matrix );

    if( m_col )
        NewtonConvexHullModifierSetMatrix( m_col, matrix ); 
}

Ogre::Matrix4 ConvexModifierCollision::getScalarMatrix() const
{
    float matrix[16];
    Ogre::Matrix4 mat;
    
    if( m_col )
    {
        NewtonConvexHullModifierGetMatrix( m_col, matrix );

        OgreNewt::Converters::MatrixToMatrix4( matrix, mat );
    }

    return mat;
}



}   // end NAMESPACE OgreNewt

