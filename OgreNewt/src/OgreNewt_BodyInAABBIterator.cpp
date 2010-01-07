#include "OgreNewt_stdafx.h"
#include "OgreNewt_BodyInAABBIterator.h"
#include "OgreNewt_World.h"


namespace OgreNewt
{


BodyInAABBIterator::BodyInAABBIterator(const OgreNewt::World* world) :
    m_world(world),
    m_callback(NULL)
{
}

void BodyInAABBIterator::go( const Ogre::AxisAlignedBox &aabb, IteratorCallback callback, void* userdata) const
{
    m_callback = callback;
    NewtonWorldForEachBodyInAABBDo(m_world->getNewtonWorld(), &aabb.getMinimum().x, &aabb.getMaximum().x, BodyInAABBIterator::newtonIterator, userdata);
}


void _CDECL BodyInAABBIterator::newtonIterator( const NewtonBody* newtonBody, void* userData)
{
    const OgreNewt::Body* body = (const OgreNewt::Body*) NewtonBodyGetUserData(newtonBody);
    const NewtonWorld* newtonWorld = NewtonBodyGetWorld(newtonBody);
    const OgreNewt::World* world = (const OgreNewt::World*) NewtonWorldGetUserData(newtonWorld);

    world->getBodyInAABBIterator().m_callback(body, userData);
}


}

