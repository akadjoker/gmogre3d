#include "OgreNewt_stdafx.h"
#include "OgreNewt_MaterialID.h"
#include "OgreNewt_World.h"

namespace OgreNewt
{

    
MaterialID::MaterialID( const World* world )
{
    m_world = world;
    id = NewtonMaterialCreateGroupID( m_world->getNewtonWorld() );
}

MaterialID::MaterialID( const World* world, int ID )
{
    m_world = world;
    id = ID;
}


MaterialID::~MaterialID()
{
}



}

