#include "OgreNewt_stdafx.h"
#include "OgreNewt_stdafx.h"
#include "OgreNewt_World.h"
#include "OgreNewt_MaterialID.h"
#include "OgreNewt_Body.h"
#include "OgreNewt_BodyInAABBIterator.h"

#pragma warning(disable:4355)

namespace OgreNewt
{


// Constructor
World::World(Ogre::Real desiredFps, int maxUpdatesPerFrames) :
    m_bodyInAABBIterator(this)
{
#ifndef WIN32
    pthread_mutex_init(&m_ogreMutex, 0);
#endif
	
	setUpdateFPS(desiredFps, maxUpdatesPerFrames);
    m_limits = Ogre::AxisAlignedBox(Ogre::Vector3(-100,-100,-100), Ogre::Vector3(100,100,100));

    m_world = NewtonCreate();

    if (!m_world)
    {
        // world not created!
    }

    NewtonWorldSetUserData( m_world, this );


    // create the default ID.
    m_defaultMatID = new OgreNewt::MaterialID( this, NewtonMaterialGetDefaultGroupID( m_world ) );

    m_leaveCallback = NULL;

	m_defaultAngularDamping = Ogre::Vector3(0.1f, 0.1f, 0.1f);
	m_defaultLinearDamping = 0.1f;

    m_debugger = new Debugger(this);

	// set the default solve mode to be iterative the fastest
	setSolverModel (SM_FASTEST);

	// use the more advanced hardware in the system
	Ogre::String description;
	setPlatformArchitecture (3);
	getPlatformArchitecture (description);


	// set one tread by default
	setThreadCount(1);
	
}

// Destructor
World::~World()
{
    if (m_debugger)
    {
        delete m_debugger;
        m_debugger = NULL;
    }

    if (m_defaultMatID)
    {
        delete m_defaultMatID;
        m_defaultMatID = NULL;
    }

    if (m_world)
    {
        NewtonDestroy( m_world );
        m_world = NULL;
    }
}


void World::setUpdateFPS(Ogre::Real desiredFps, int maxUpdatesPerFrames)
{

	if (maxUpdatesPerFrames < 1) {
		maxUpdatesPerFrames = 1;
	}

	if (maxUpdatesPerFrames > 10) {
		maxUpdatesPerFrames = 10;
	}

	m_maxTicksPerFrames = maxUpdatesPerFrames;
	m_updateFPS = desiredFps;

	m_timestep = 1.0f / desiredFps;
	if (m_timestep > 1.0f / 10.0f) {
		// recalculate the iteration count to met the desire fps 
		m_maxTicksPerFrames += ceilf (m_timestep / (1.0f / 60.0f));

		m_timestep = 1.0 / 10.0f;
		m_updateFPS = 10;
	}

	if (m_timestep < 1.0f / 1000.0f) {
		m_timestep = 1.0 / 1000.0f;
		m_updateFPS = 1000;
	}

	m_invTimestep = 1.0f / m_timestep;
	m_timeAcumulator = m_timestep;
}

// Set allocators
void World::SetAllocators (NewtonAllocMemory newtonAlloc, NewtonFreeMemory newtonFree)
{
	NewtonSetMemorySystem (newtonAlloc, newtonFree);
}

void World::setThreadCount(int threads) 
{
	// clean up all pending bodies for update
	for( BodyVectorVector::iterator it = m_bodyUpdateNodeRequests.begin(); it != m_bodyUpdateNodeRequests.end(); it++ )
	{
		for( BodyVector::iterator body = it->begin(); body != it->end(); body++ )
		{

			(*body)->SetNodeUpdateState (false);
		}
		it->clear();
	}

	 NewtonSetThreadsCount (m_world, threads) ;
	
	 // resize the update queue 
	 m_bodyUpdateNodeRequests.resize(getThreadCount());
}


void World::addBodyUpdateNodeRequest( int threadIndex, OgreNewt::Body* body ) const
{
	body->SetNodeUpdateState (true);
	m_bodyUpdateNodeRequests.at(threadIndex).push_back(body);
}

// update
int World::update( Ogre::Real t_step )
{
	int realUpdates = 0;

	// clean up all pending bodies for update
	for( BodyVectorVector::iterator it = m_bodyUpdateNodeRequests.begin(); it != m_bodyUpdateNodeRequests.end(); it++ )
	{
		for( BodyVector::iterator body = it->begin(); body != it->end(); body++ )
		{

			(*body)->SetNodeUpdateState (false);
		}
		it->clear();
	}


#ifdef _DEBUG
//	Ogre::LogManager::getSingleton().logMessage("   Newton Frame Listener... m_elapsed: "+Ogre::StringConverter::toString( t_step)+
//		"  m_update:"+Ogre::StringConverter::toString(m_update));
#endif

	// clamp thE step if necessary
	if (t_step > (m_timestep * m_maxTicksPerFrames)) {
		t_step = m_timestep * m_maxTicksPerFrames;
	}

	// advance the accumulator;
	m_timeAcumulator += t_step;
	while (m_timeAcumulator >= m_timestep) {
		NewtonUpdate (m_world, m_timestep);
		m_timeAcumulator -= m_timestep;
		realUpdates++;
	}

#ifdef _DEBUG
//	Ogre::LogManager::getSingleton().logMessage("   Newton updates this loop: "+Ogre::StringConverter::toString(count));
#endif


	Ogre::Real param = m_timeAcumulator * m_invTimestep;
//param = 1.0f;

	for( BodyVectorVector::iterator it = m_bodyUpdateNodeRequests.begin(); it != m_bodyUpdateNodeRequests.end(); it++ )
	{
		for( BodyVector::iterator body = it->begin(); body != it->end(); body++ )
		{
			(*body)->updateNode(param);
		}
	}

	return realUpdates;
}




void World::setWorldSize( const Ogre::Vector3& min, const Ogre::Vector3& max )
{
    NewtonSetWorldSize( m_world, (float*)&min.x, (float*)&max.x );
    m_limits = Ogre::AxisAlignedBox(min, max);
}

void World::setWorldSize( const Ogre::AxisAlignedBox& box )
{
    NewtonSetWorldSize( m_world, (float*)&box.getMinimum(), (float*)&box.getMaximum() );
    m_limits = box;
}

void World::setLeaveWorldCallback( LeaveWorldCallback callback )
{
    if (!m_leaveCallback)
    {
        NewtonSetBodyLeaveWorldEvent( m_world, World::newtonLeaveWorld );
    }

    if (callback)
    {
        m_leaveCallback = callback;
    }
    else
    {
        NewtonSetBodyLeaveWorldEvent( m_world, NULL );
        m_leaveCallback = NULL;
    }
}

void _CDECL World::newtonLeaveWorld( const NewtonBody* body, int threadIndex )
{
    OgreNewt::World* me = (OgreNewt::World*)NewtonWorldGetUserData( NewtonBodyGetWorld( body ) );

    if (me->m_leaveCallback)
    {
        OgreNewt::Body* b = (OgreNewt::Body*)NewtonBodyGetUserData( body );
        me->m_leaveCallback( b, threadIndex );
    }
}

Body* World::getFirstBody() const
{
    NewtonBody* body = NewtonWorldGetFirstBody( m_world );
    if( body )
        return (Body*) NewtonBodyGetUserData(body);

    return NULL;
}


// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------


}

