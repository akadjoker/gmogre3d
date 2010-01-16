#include "stdafx.h"
#include "OgreNewtBody.h"
#include "OgreNewtWorld.h"
#include "LockMutex.h"


void DefaultForceCallback(OgreNewt::Body* body, float timestep, int threadIndex)
{
   OgreNewtBody* newton_body = (OgreNewtBody*)body->getUserData();
   newton_body->applyForceAndTorque();
}


OgreNewtBody::OgreNewtBody(const OgreNewt::World* W, const OgreNewt::CollisionPtr& col, int bodytype)
{
   m_body = new OgreNewt::Body(W, col, bodytype);
   m_userdata = NULL;
   m_body->setUserData(this);
   m_override_gravity = false;

   m_mutex = CreateMutex(NULL, FALSE, NULL);

   m_queued_force = Ogre::Vector3(0, 0, 0);
   m_queued_torque = Ogre::Vector3(0, 0, 0);

   m_gm_force_and_torque_func = -1;
   m_body->setCustomForceAndTorqueCallback(DefaultForceCallback);
}


OgreNewtBody::~OgreNewtBody()
{
   OgreNewtWorld* newton_world = (OgreNewtWorld*)NewtonWorldGetUserData(m_body->getWorld()->getNewtonWorld());
   newton_world->removeBodyLeftWorld(this);

   delete m_body;
}


void OgreNewtBody::setUserData( void* data )
{
   m_userdata = data;
}


void* OgreNewtBody::getUserData() const
{
   return m_userdata;
}


void OgreNewtBody::setType( int type )
{
   m_body->setType(type);
}


int OgreNewtBody::getType() const
{
   return m_body->getType();
}


void OgreNewtBody::attachNode( Ogre::Node* node )
{
   m_body->attachNode(node);
}


Ogre::Node *OgreNewtBody::getOgreNode()
{
   return m_body->getOgreNode();
}


void OgreNewtBody::setStandardForceCallback()
{
   m_body->setStandardForceCallback();
}


void OgreNewtBody::setPositionOrientation( const Ogre::Vector3& pos, const Ogre::Quaternion& orient, int threadIndex)
{
   m_body->setPositionOrientation(pos, orient, threadIndex);
}


void OgreNewtBody::setMassMatrix( Ogre::Real mass, const Ogre::Vector3& inertia )
{
   m_body->setMassMatrix(mass, inertia);
}


void OgreNewtBody::setCenterOfMass( const Ogre::Vector3& centerOfMass )
{
   m_body->setCenterOfMass(centerOfMass);
}


Ogre::Vector3 OgreNewtBody::getCenterOfMass() const
{
   return m_body->getCenterOfMass();
}


void OgreNewtBody::freeze()
{
   m_body->freeze();
}


void OgreNewtBody::unFreeze()
{
   m_body->unFreeze();
}


void OgreNewtBody::setMaterialGroupID( const OgreNewt::MaterialID* ID )
{
   m_body->setMaterialGroupID(ID);
}


void OgreNewtBody::setContinuousCollisionMode( unsigned state )
{
   m_body->setContinuousCollisionMode(state);
}


void OgreNewtBody::setJointRecursiveCollision( unsigned state )
{
   m_body->setJointRecursiveCollision(state);
}


void OgreNewtBody::setOmega( const Ogre::Vector3& omega )
{
   m_body->setOmega(omega);
}


void OgreNewtBody::setVelocity( const Ogre::Vector3& vel )
{
   m_body->setVelocity(vel);
}


void OgreNewtBody::setLinearDamping( Ogre::Real damp )
{
   m_body->setLinearDamping(damp);
}


void OgreNewtBody::setAngularDamping( const Ogre::Vector3& damp )
{
   m_body->setAngularDamping(damp);
}


void OgreNewtBody::setAutoSleep( int flag )
{
   m_body->setAutoSleep(flag);
}


int OgreNewtBody::getAutoSleep()
{
   return m_body->getAutoSleep();
}


const OgreNewt::MaterialID* OgreNewtBody::getMaterialGroupID() const
{
   return m_body->getMaterialGroupID();
}


void OgreNewtBody::getPositionOrientation( Ogre::Vector3& pos, Ogre::Quaternion& orient ) const
{
   m_body->getPositionOrientation(pos, orient);
}


void OgreNewtBody::addImpulse( const Ogre::Vector3& deltav, const Ogre::Vector3& posit )
{
   m_body->addImpulse(deltav, posit);
}


void OgreNewtBody::addForce( const Ogre::Vector3& force )
{
   m_queued_force += force;
}


void OgreNewtBody::addTorque( const Ogre::Vector3& torque )
{
   m_queued_torque += torque;
}


void OgreNewtBody::setForce( const Ogre::Vector3& force )
{
   m_queued_force = force;
}


void OgreNewtBody::setTorque( const Ogre::Vector3& torque )
{
   m_queued_torque = torque;
}


void OgreNewtBody::addGlobalForce( const Ogre::Vector3& force, const Ogre::Vector3& pos )
{
   Ogre::Vector3 bodypos;
   Ogre::Quaternion bodyorient;
   getPositionOrientation( bodypos, bodyorient );

   Ogre::Vector3 localMassCenter = getCenterOfMass();
   Ogre::Vector3 globalMassCenter = bodypos + bodyorient * localMassCenter;

   Ogre::Vector3 topoint = pos - globalMassCenter;
   Ogre::Vector3 torque = topoint.crossProduct( force );

   m_queued_force = force;
   m_queued_torque = torque;
}


void OgreNewtBody::addLocalForce( const Ogre::Vector3& force, const Ogre::Vector3& pos )
{
   Ogre::Vector3 bodypos;
   Ogre::Quaternion bodyorient;

   getPositionOrientation( bodypos, bodyorient );

   Ogre::Vector3 globalforce = bodyorient * force;
   Ogre::Vector3 globalpoint = (bodyorient * pos) + bodypos;

   addGlobalForce(globalforce, globalpoint);
}


OgreNewt::Body *OgreNewtBody::getOgreNewtBody()
{
   return m_body;
}


void OgreNewtBody::EnableGravityOverride(bool enable)
{
   LockMutex lm(m_mutex);

   m_override_gravity = enable;
}


bool OgreNewtBody::IsGravityOverrideEnabled()
{
   return m_override_gravity;
}


void OgreNewtBody::setGravity(Ogre::Vector3 vec)
{
   LockMutex lm(m_mutex);

   m_gravity = vec;
}


Ogre::Vector3 OgreNewtBody::getGravity()
{
   return m_gravity;
}


void OgreNewtBody::setGMForceAndTorqueFunc(int func)
{
   LockMutex lm(m_mutex);

   m_gm_force_and_torque_func = func;
}


void OgreNewtBody::applyForceAndTorque()
{
   Ogre::Real mass;
   Ogre::Vector3 inertia;
   Ogre::Vector3 force;

   if (m_override_gravity)
      force = m_gravity;
   else
   {
      OgreNewtWorld* newton_world = (OgreNewtWorld*)NewtonWorldGetUserData(m_body->getWorld()->getNewtonWorld());
      newton_world->getWorldGravity();

      force = newton_world->getWorldGravity();      
   }

   // Apply world gravity force.
   m_body->getMassMatrix(mass, inertia);
   force *= mass;

   // Add any previously applied forces/torque
   m_body->addForce(force + m_queued_force);
   m_body->addTorque(m_queued_torque);

   m_queued_force = Ogre::Vector3(0, 0, 0);
   m_queued_torque = Ogre::Vector3(0, 0, 0);
}
