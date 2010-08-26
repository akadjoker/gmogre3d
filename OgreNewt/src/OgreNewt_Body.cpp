#include "OgreNewt_stdafx.h"
#include "OgreNewt_Body.h"
#include "OgreNewt_World.h"
#include "OgreNewt_Collision.h"
#include "OgreNewt_Tools.h"



namespace OgreNewt
{

    
Body::Body( const World* W, const OgreNewt::CollisionPtr& col, int bodytype ) 
{
    m_world = W;
    m_collision = col;
    m_type = bodytype;
    m_node = NULL;
    m_matid = NULL;
    
    m_userdata = NULL;

    m_forcecallback = NULL;
//  m_transformcallback = NULL;
    m_buoyancycallback = NULL;
	m_nodeupdatenotifycallback = NULL;

    m_nodeupdateneeded = false;

	m_nodePosit = Ogre::Vector3 (0.0f, 0.0f, 0.0f);
	m_curPosit = Ogre::Vector3 (0.0f, 0.0f, 0.0f);
	m_prevPosit = Ogre::Vector3 (0.0f, 0.0f, 0.0f);
	m_curRotation = Ogre::Quaternion::IDENTITY;
	m_prevRotation = Ogre::Quaternion::IDENTITY;
	m_nodeRotation = Ogre::Quaternion::IDENTITY;

    m_body = NewtonCreateBody( m_world->getNewtonWorld(), col->getNewtonCollision() ); 

    NewtonBodySetUserData( m_body, this );
    NewtonBodySetDestructorCallback( m_body, newtonDestructor );
	NewtonBodySetTransformCallback( m_body, newtonTransformCallback );

	setLinearDamping(m_world->getDefaultLinearDamping() * (60.0f / m_world->getUpdateFPS()));
	setAngularDamping(m_world->getDefaultAngularDamping() * (60.0f / m_world->getUpdateFPS()));
}

Body::~Body()
{
    if (m_body)
    {
        if (NewtonBodyGetUserData(m_body))
        {
            NewtonBodySetDestructorCallback( m_body, NULL );
            NewtonDestroyBody( m_world->getNewtonWorld(), m_body );
        }
    }
}

// destructor callback
void _CDECL Body::newtonDestructor( const NewtonBody* body )
{
    //newton wants to destroy the body.. so first find it.
    OgreNewt::Body* me;

    me = (OgreNewt::Body*)NewtonBodyGetUserData( body );

    // remove destructor callback
    NewtonBodySetDestructorCallback( body, NULL );
    // remove the user data
    NewtonBodySetUserData( body, NULL );

    //now delete the object.
    delete me;
}


// transform callback
void _CDECL Body::newtonTransformCallback( const NewtonBody* body, const float* matrix, int threadIndex )
{
	Ogre::Real dot;
    OgreNewt::Body* me;

    me = (OgreNewt::Body*) NewtonBodyGetUserData( body );
	
	me->m_prevPosit = me->m_curPosit;
	me->m_prevRotation = me->m_curRotation;
	me->m_curPosit = Ogre::Vector3(matrix[12], matrix[13], matrix[14]);		

	// use the rotation from the body
	NewtonBodyGetRotation (body, &me->m_curRotation.w);

	dot = me->m_prevRotation.Dot(me->m_curRotation);
	if (dot < 0.0f) {
		me->m_prevRotation = -1.0f * me->m_prevRotation;
	}

//	if (me->m_node) {
//	if (m_nodeupdateneeded && !forceNodeUpdate )
	if (!me->m_nodeupdateneeded) {
		me->m_world->addBodyUpdateNodeRequest( threadIndex, me);

		// me->m_transformcallback( me, threadIndex );
	}
//	}
}

    
void _CDECL Body::newtonForceTorqueCallback( const NewtonBody* body, float timeStep, int threadIndex )
{
    OgreNewt::Body* me = (OgreNewt::Body*)NewtonBodyGetUserData( body );

    if (me->m_forcecallback)
        me->m_forcecallback( me, timeStep, threadIndex );
}

void Body::standardForceCallback( OgreNewt::Body* me, float timestep, int threadIndex )
{
    //apply a simple gravity force.
    Ogre::Real mass;
    Ogre::Vector3 inertia;

    me->getMassMatrix(mass, inertia);
    Ogre::Vector3 force(0,-9.8,0);
    force *= mass;

    me->addForce( force );

	while (me->m_accumulatedGlobalForces.size() > 0)
	{
		std::pair<Ogre::Vector3, Ogre::Vector3> forceInfo = me->m_accumulatedGlobalForces.back();
		me->m_accumulatedGlobalForces.pop_back();

		me->addGlobalForce(forceInfo.first, forceInfo.second);
	}
}


int _CDECL Body::newtonBuoyancyCallback(const int collisionID, void *context, const float* globalSpaceMatrix, float* globalSpacePlane)
{
    OgreNewt::Body* me = (OgreNewt::Body*)context;

    
    Ogre::Quaternion orient;
    Ogre::Vector3 pos;

    OgreNewt::Converters::MatrixToQuatPos( globalSpaceMatrix, orient, pos );

    // call our user' function to get the plane.
    Ogre::Plane theplane;
    
    if (me->m_buoyancycallback(collisionID, me, orient, pos, theplane))
    {
        globalSpacePlane[0] = theplane.normal.x;
        globalSpacePlane[1] = theplane.normal.y;
        globalSpacePlane[2] = theplane.normal.z;

        globalSpacePlane[3] = theplane.d;

        return 1;
    }

    return 0;
}


// attachToNode
void Body::attachNode( Ogre::Node* node )
{
    m_node = node;
	updateNode(1.0f);
}

void Body::setPositionOrientation( const Ogre::Vector3& pos, const Ogre::Quaternion& orient, int threadIndex)
{
    if (m_body)
    {
        float matrix[16];

		// reset the previews Position and rotation for this body
		m_curPosit = pos;
		m_prevPosit = pos;
		m_curRotation = orient;
		m_prevRotation = orient;

        OgreNewt::Converters::QuatPosToMatrix( orient, pos, &matrix[0] );
        NewtonBodySetMatrix( m_body, &matrix[0] );

		updateNode(1.0f);

    }
}

// set mass matrix
void Body::setMassMatrix( Ogre::Real mass, const Ogre::Vector3& inertia )
{
    if (m_body)
        NewtonBodySetMassMatrix( m_body, (float)mass, (float)inertia.x, (float)inertia.y, (float)inertia.z );
}

// basic gravity callback
void Body::setStandardForceCallback()
{
    setCustomForceAndTorqueCallback( standardForceCallback );
}

// custom user force callback
void Body::setCustomForceAndTorqueCallback( ForceCallback callback )
{
    if (!m_forcecallback)
    {
        m_forcecallback = callback;
        NewtonBodySetForceAndTorqueCallback( m_body, newtonForceTorqueCallback );
    }
    else
    {
            m_forcecallback = callback;
    }

}

/*
// custom user force callback
void Body::setCustomTransformCallback( TransformCallback callback )
{
    if (!m_transformcallback)
    {
        m_transformcallback = callback;
        NewtonBodySetTransformCallback( m_body, newtonTransformCallback );
    }
    else
    {
            m_transformcallback = callback;
    }
}
*/

//set collision
void Body::setCollision( const OgreNewt::CollisionPtr& col )
{
    NewtonBodySetCollision( m_body, col->getNewtonCollision() );

    m_collision = col;
}

//get collision
const OgreNewt::CollisionPtr& Body::getCollision() const
{
    return m_collision;
}

//get material group ID
const OgreNewt::MaterialID* Body::getMaterialGroupID() const
{
    if (m_matid)
        return m_matid;
    else
        return m_world->getDefaultMaterialID();     
}


// get position and orientation
void Body::getPositionOrientation( Ogre::Vector3& pos, Ogre::Quaternion& orient ) const
{
//  Ogre::Real matrix[16];
//  NewtonBodyGetMatrix ( m_body, matrix );
//	NewtonBodyGetRotation ( m_body, &orient.w );
//	pos = Ogre::Vector3( matrix[12], matrix[13], matrix[14] );

	pos = m_curPosit;
	orient = m_curRotation;
}

Ogre::Vector3 Body::getPosition() const
{
	return m_curPosit;
}


Ogre::Quaternion Body::getOrientation() const
{
	return m_curRotation;
}

//! get the node position and orientation in form of an Ogre::Vector(position) and Ogre::Quaternion(orientation)
void Body::getVisualPositionOrientation( Ogre::Vector3& pos, Ogre::Quaternion& orient ) const
{
	pos = m_nodePosit;
	orient = m_nodeRotation;
}

Ogre::Vector3 Body::getVisualPosition() const
{
	return m_nodePosit;
}


Ogre::Quaternion Body::getVisualOrientation() const
{
	return m_nodeRotation;
}

Ogre::AxisAlignedBox Body::getAABB() const
{
//	Ogre::AxisAlignedBox ret;
//	Ogre::Vector3 min, max;
//	NewtonBodyGetAABB( m_body, &min.x, &max.x );
//	ret.setExtents( min, max );
//	return ret;
	return m_collision->getAABB(m_curRotation, m_curPosit);
}

void Body::getMassMatrix( Ogre::Real& mass, Ogre::Vector3& inertia ) const
{
    NewtonBodyGetMassMatrix( m_body, &mass, &inertia.x, &inertia.y, &inertia.z );
}

void Body::getInvMass( Ogre::Real& mass, Ogre::Vector3& inertia ) const
{
    NewtonBodyGetInvMass( m_body, &mass, &inertia.x, &inertia.y, &inertia.z );
}

Ogre::Vector3 Body::getOmega() const
{
    Ogre::Vector3 ret;
    NewtonBodyGetOmega( m_body, &ret.x );
    return ret;
}

Ogre::Vector3 Body::getVelocity() const
{
    Ogre::Vector3 ret;
    NewtonBodyGetVelocity( m_body, &ret.x );
    return ret;
}

Ogre::Vector3 Body::getForce() const
{
    Ogre::Vector3 ret;
    NewtonBodyGetForce( m_body, &ret.x );
    return ret;
}

Ogre::Vector3 Body::getTorque() const
{
    Ogre::Vector3 ret;
    NewtonBodyGetTorque( m_body, &ret.x );
    return ret;
}

Ogre::Vector3 Body::getForceAcceleration() const
{
    Ogre::Vector3 ret;
    NewtonBodyGetForceAcc( m_body, &ret.x );
    return ret;
}

Ogre::Vector3 Body::getTorqueAcceleration() const
{
    Ogre::Vector3 ret;
    NewtonBodyGetTorqueAcc( m_body, &ret.x );
    return ret;
}

Ogre::Vector3 Body::calculateInverseDynamicsForce(Ogre::Real timestep, Ogre::Vector3 desiredVelocity)
{
    Ogre::Vector3 ret;
    NewtonBodyCalculateInverseDynamicsForce(m_body, timestep, &desiredVelocity.x, &ret.x);

    return ret;
}


Ogre::Vector3 Body::getAngularDamping() const
{
    Ogre::Vector3 ret;
    NewtonBodyGetAngularDamping( m_body, &ret.x );
    return ret;
}

Ogre::Vector3 Body::getCenterOfMass() const
{
    Ogre::Vector3 ret;
    NewtonBodyGetCentreOfMass( m_body, &ret.x );
    return ret;
}

void Body::addBouyancyForce( Ogre::Real fluidDensity, Ogre::Real fluidLinearViscosity, Ogre::Real fluisAngularViscosity, const Ogre::Vector3& gravity, buoyancyPlaneCallback callback )
{
    // call the newton function.
    if (callback)
        m_buoyancycallback = callback;
    else
        m_buoyancycallback = NULL;

    NewtonBodyAddBuoyancyForce( m_body, fluidDensity, fluidLinearViscosity, fluisAngularViscosity,
        &gravity.x, newtonBuoyancyCallback, this );

    m_buoyancycallback = NULL;
}

void Body::addGlobalForce( const Ogre::Vector3& force, const Ogre::Vector3& pos )
{
    Ogre::Vector3 bodypos;
    Ogre::Quaternion bodyorient;
    getPositionOrientation( bodypos, bodyorient );

    Ogre::Vector3 localMassCenter = getCenterOfMass();
    Ogre::Vector3 globalMassCenter = bodypos + bodyorient * localMassCenter;

    Ogre::Vector3 topoint = pos - globalMassCenter;
    Ogre::Vector3 torque = topoint.crossProduct( force );

    addForce( force );
    addTorque( torque );
}

void Body::addGlobalForceAccumulate( const Ogre::Vector3& force, const Ogre::Vector3& pos )
{
	m_accumulatedGlobalForces.push_back(std::pair<Ogre::Vector3,Ogre::Vector3>(force, pos));
}

void Body::addLocalForce( const Ogre::Vector3& force, const Ogre::Vector3& pos )
{
    Ogre::Vector3 bodypos;
    Ogre::Quaternion bodyorient;

    getPositionOrientation( bodypos, bodyorient );

    Ogre::Vector3 globalforce = bodyorient * force;
    Ogre::Vector3 globalpoint = (bodyorient * pos) + bodypos;

    addGlobalForce( globalforce, globalpoint );
}

Body* Body::getNext() const
{
    NewtonBody* body = NewtonWorldGetNextBody( m_world->getNewtonWorld(), m_body );
    if( body )
        return (Body*) NewtonBodyGetUserData(body);

    return NULL;
}

void Body::setNodeUpdateNotify (NodeUpdateNotifyCallback callback ) 
{
	m_nodeupdatenotifycallback = callback;
}


void Body::updateNode(Ogre::Real interpolatParam)
{
	m_nodePosit = m_prevPosit + (m_curPosit - m_prevPosit) * interpolatParam;
	m_nodeRotation = Ogre::Quaternion::Slerp (interpolatParam, m_prevRotation, m_curRotation);

	if (m_node) {
		#ifndef WIN32
			m_world->ogreCriticalSectionLock();
		#endif
		m_node->setPosition(m_nodePosit);
		m_node->setOrientation(m_nodeRotation);

		if (m_nodeupdatenotifycallback) {
			m_nodeupdatenotifycallback (this);
		}

		#ifndef WIN32
			m_world->ogreCriticalSectionUnlock();
		#endif
	}
}


// --------------------------------------------------------------------------------------


}
