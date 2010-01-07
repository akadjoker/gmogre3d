#include "OgreNewt_stdafx.h"
#include "OgreNewt_MaterialPair.h"
#include "OgreNewt_ContactJoint.h"

namespace OgreNewt
{

 
MaterialPair::MaterialPair( const World* world, const MaterialID* mat1, const MaterialID* mat2 )
{
    m_world = world;
    id0 = mat1;
    id1 = mat2;
    m_contactcallback = NULL;
}

MaterialPair::~MaterialPair()
{
}


void MaterialPair::setContactCallback( OgreNewt::ContactCallback* callback )
{
    m_contactcallback = callback;
    if( callback )
    {
        NewtonMaterialSetCollisionCallback( m_world->getNewtonWorld(), id0->getID(), id1->getID(), this,
            collisionCallback_onAABBOverlap,
            collisionCallback_contactsProcess);
    }
    else
    {
        NewtonMaterialSetCollisionCallback( m_world->getNewtonWorld(), id0->getID(), id1->getID(), NULL,
            NULL,
            NULL);
    }
}


int _CDECL MaterialPair::collisionCallback_onAABBOverlap( const NewtonMaterial* material, const NewtonBody* newtonBody0, const NewtonBody* newtonBody1, int threadIndex )
{
    MaterialPair* me;
    me = (MaterialPair*)NewtonMaterialGetMaterialPairUserData( material );

    Body* body0 = (OgreNewt::Body*)NewtonBodyGetUserData( newtonBody0 );
    Body* body1 = (OgreNewt::Body*)NewtonBodyGetUserData( newtonBody1 );

    return me->m_contactcallback->onAABBOverlap( body0, body1, threadIndex );
}

void _CDECL MaterialPair::collisionCallback_contactsProcess(const NewtonJoint *newtonContactJoint, float timestep, int threadIndex )
{
    ContactJoint contactJoint(newtonContactJoint);

    MaterialPair* me = contactJoint.getMaterialPair();
    
    if( me != NULL )
    {
        ( me->m_contactcallback->contactsProcess )(contactJoint, timestep, threadIndex);
    }
}


}

