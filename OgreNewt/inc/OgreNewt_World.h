/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven
*/
#ifndef _INCLUDE_OGRENEWT_WORLD
#define _INCLUDE_OGRENEWT_WORLD

#ifndef WIN32
#include <pthread.h>
#endif

#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_BodyInAABBIterator.h"
#include "OgreNewt_Debugger.h"

//! main namespace.
/*!
    This is the main namespace for the OgreNewt library.  all classes are included in this namespace.
*/
namespace OgreNewt
{


//! represents a physics world.
/*!
    this class represents a NewtonWorld, which is the basic space in which physics elements can exist.  It can have various Rigid Bodies, connected by joints, and other constraints.
*/
class _OgreNewtExport World
{

public:

    //! physics solver mode.
    /*!
        you can adjust the accuracy of the solver (and therefore the speed of the solver) using these, or a simple int >= 2.  a value >= 2 represents the number of passes you want the engine to take when attempting to reconcile joints.
    */
    enum SolverModelMode 
    { 
        SM_EXACT = 0,   /*!< the most accurate simulation. */
        SM_FASTEST = 1, /*!< still accurate, but faster. */
		SM_MEDIUM = 4, /*!< more accurate, stronger joints, but still liner */
		SM_SLOW = 8, /*!< even more accurate, stronger joints, but still linear */
		SM_RIDICULUS = 16 /*!< you better use teh quadric solver*/
    };

    //! friction solver mode.
    /*!
        like the physics solver mode, these options allow you to reduce the accuracy of the friction model in exchange for speed.
    */
    enum FrictionModelMode 
    { 
        FM_EXACT = 0,   /*!< exact friction model (default). */
        FM_ADAPTIVE = 1 /*!< adaptive friction mode. (faster but less accurate) */
    };

	//! platform mode
	/*!
		This function allows the application to configure the Newton to take advantage for specific hardware architecture in the same platform.
		
		PF_DETERMINISTIC_UNOPTIMIZED = 0 - force the hardware lower common denominator for the running platform.
		PF_OPTIMIZED = 1 - will try to use common floating point enhancement like spacial instruction set on the specific architecture. This mode made lead to result that differ from mode 1 and 2 as the accumulation round off errors maybe different.
		PF_BEST_POSSIBLE = 2 - the engine will try to use the best possible hardware setting found in the current platform this is the default configuration. This mode made lead to result that differ from mode 1 and 2 as the accumulation round off errors maybe different.
		
		The only hardware mode guarantee to work is mode 0. all other are only hints to the engine, for example setting mode 1 will take not effect on CPUs without specially floating point instructions set.
	*/
	enum PlatformArchitecture
	{
		PF_DETERMINISTIC_UNOPTIMIZED = 0,
		PF_COMMON_OPTIMIZED = 1,
		PF_BEST_POSSIBLE = 2
	};

    //! leave world callback.
    /*!
        this function is called when a body leaves the OgreNewt::World.  you can use this to destroy bodies that have left the scene,
        or re-position them, reflect them, do whatever you want.

        callback binding to member classes is exactly the same as the various callbacks for the Body class.
    */
    typedef boost::function<void(OgreNewt::Body*, int threadIndex)> LeaveWorldCallback;

public:
    //! Standard Constructor, creates the world.
	World(Ogre::Real desiredFps = 100.0f, int maxUpdatesPerFrames = 5);

    //! Standard Destructor, destroys the world.
    ~World();       

	//! Set the newton world allocators, 
	/*!
	    Is is no necessary to call this function allocations default to malloc and free but if an application  
		then it must call this once before the creation of any Newton world
	*/
	static void SetAllocators (NewtonAllocMemory newtonAlloc, NewtonFreeMemory newtonFree);
	
    //! update the world by the specified time_step.
    /*!
        this function is clamped between values representing fps [60,600].  if you pass a smaller value, it is internally clamped to 60fps.  likewise a value higher than 600fps is treated as 600fs.

        \param t_step Real value representing the time elapsed in seconds.
		\return How many times was the actual physics updated
    */
    int update( Ogre::Real t_step );   

    //! invalidate internal cache
    /*!
        this function completely resets the cache that Newton uses to improve simulation performance.  This is useful for situations where you have reset the simulation to a previous point in time, or reset all bodies,
        and do not want the state of the world from the previous frame affecting the next frame.
    */
    void invalidateCache() { NewtonInvalidateCache( m_world ); }

    //! set simulation frames per and max updated per updates 
    /*!
		this function set the update rate of the simulation 
		plus the maximum number of update per frame the simulation can execute in order to catch up. 
    */
    void setUpdateFPS(Ogre::Real desiredFps, int maxUpdatesPerFrames);

	//! returns desired update frames per second
	/*!
		\return desired update rate
	*/
	Ogre::Real getUpdateFPS() const { return m_updateFPS; }

	//! sets default linear damping
	/*!
		default damping is used when creating new bodies and changing this applies only to bodies
		created after calling this method. default damping is also timestep-dependant, the value you
		set here is for 60fps and scales down if using larger physics update rate.

		\param defaultLinearDamping Ogre::Real default linear damping to use
	*/
	void setDefaultLinearDamping(Ogre::Real defaultLinearDamping) { m_defaultLinearDamping = defaultLinearDamping; }

	//! return default linear damping
	/*!
		\return default linear damping
	*/
	Ogre::Real getDefaultLinearDamping() const { return m_defaultLinearDamping; }

	//! sets default angular damping
	/*!
		default damping is used when creating new bodies and changing this applies only to bodies
		created after calling this method. default damping is also timestep-dependant, the value you
		set here is for 60fps and scales down if using larger physics update rate.

		\param defaultLinearDamping Ogre::Real default linear damping to use
	*/
	void setDefaultAngularDamping(Ogre::Vector3 defaultAngularDamping) { m_defaultAngularDamping = defaultAngularDamping; }

	//! return default angular damping
	/*!
		\return default angular damping
	*/
	Ogre::Vector3 getDefaultAngularDamping() const { return m_defaultAngularDamping; }

    //! retrieves a pointer to the NewtonWorld
    /*!
        in most cases you shouldn't need this... but in case you want to implement something not yet in the library, you can use this to get a pointer to the NewtonWorld object.
        \return pointer to NewtonWorld
    */
    const NewtonWorld* getNewtonWorld() const { return m_world; }

    //! get the default materialID object.
    /*!
        when you create a world, a default material is created, which is by default applied to all new rigid bodies.  you might need this pointer when assigning material callbacks, etc.
        \return pointer to a MaterialID* representing the default material.
    */
    const MaterialID* getDefaultMaterialID() const { return m_defaultMatID; }   // get pointer to default material ID object.

    //! remove all bodies from the world.
    /*!
        destroys all Rigid Bodies and Joints in the world. the bodies are properly deleted, so don't try and access any pointers you have lying around!
    */
    void destroyAllBodies() { NewtonDestroyAllBodies( m_world ); }

    //! set the physics solver model
    /*!
        setting the solver model allows sacrificing accuracy and realism for speed, good for games, etc.  for a more detailed description of how to use this function, see the Newton documentation.
        \param model int representing the physics model.  you can also pass the enum values I've included.
        \sa SolverModelMode
    */
    void setSolverModel( int model ) { NewtonSetSolverModel( m_world, model ); }

    //! set the physics friction model
    /*!
        setting the friction model allows sacrificing accuracy and realism for speed, good for games, etc. for a more detailed description of how to use this function, see the Newton documentation.
        \param model int representing friction model.  you can also pass the enum values I've included.
        \sa FrictionModelMode
    */
    void setFrictionModel( int model) { NewtonSetFrictionModel( m_world, model ); }

    //! specify a specific architecture to use for physics calculations.
    /*!
        Setting to a specific architecture can allow for deterministic physics calculations on systems with different cpus,
        which is particularly useful for multiplayer systems where deterministic physics are absolutely vital.
    */
    void setPlatformArchitecture( int mode ) { NewtonSetPlatformArchitecture( m_world, mode ); }

    //! get the architecture used for physics calculations.
    /*!
        \param description returns a description-string for the currently used mode
        \return int representing the current mode
    */
    int getPlatformArchitecture(Ogre::String& description) { char desc[265]; int mode = NewtonGetPlatformArchitecture( m_world, desc ); description = desc; return mode;}

    //! get the number of bodies in the simulation.
    /*!
        returns the number of bodies in the simulation.
    */
    int getBodyCount() const { return NewtonWorldGetBodyCount( m_world ); }

    //! get the number of constaints in the simulation
    int getConstraintCount() const {return NewtonWorldGetConstraintCount( m_world ); }

    //! multithread settings
    void setMultithreadSolverOnSingleIsland( int mode ) { NewtonSetMultiThreadSolverOnSingleIsland( m_world, mode ); }

    //! get multithread settings
    int getMultithreadSolverOnSingleIsland( ) const { return NewtonGetMultiThreadSolverOnSingleIsland( m_world ); }

    //! set the number of threads for the physics simulation to use, don't do this while world update
    void setThreadCount(int threads);

    //! get the number of threads the simulation is using.
    int getThreadCount() const { return NewtonGetThreadsCount( m_world ); }

    //! notify an entrance to a critical section of code.
    void criticalSectionLock() const { NewtonWorldCriticalSectionLock( m_world ); }

    //! notify the exit of a critical section of code.
    void criticalSectionUnlock() const { NewtonWorldCriticalSectionUnlock( m_world ); }

    //! set minimum framerate
    void setMinimumFrameRate( Ogre::Real frame ) { NewtonSetMinimumFrameRate( m_world, frame ); }

    //! set the newton world size
    /*!
        setting the world size is very important for a efficient simulation.  although basic collisions will work outside the world limits, other things like raycasting will not work outside the world limits.
        \param min minimum point of the world.
        \param max maximum point of the world.
    */
    void setWorldSize( const Ogre::Vector3& min, const Ogre::Vector3& max );

    /*!
        \param box bos describing the size of the world.
    */
    void setWorldSize( const Ogre::AxisAlignedBox& box );

    /*!
        get the world limits.
    */
    Ogre::AxisAlignedBox getWorldSize() { return m_limits; }

    //! get the Newton SDK version.
    int getVersion() const { return NewtonWorldGetVersion( m_world ); }

    //! set the leave world callback
    /*!
        sets the callback to be used when a Body leaves the World limits.
    */
    void setLeaveWorldCallback( LeaveWorldCallback callback );
    template<class c> void setLeaveWorldCallback( boost::function<void(c*, Body*, int)> callback, c *instancedClassPointer )
    {
        setLeaveWorldCallback( boost::bind(callback, instancedClassPointer, _1, _2) );
    }


    //! updates only the collision of the world and call the callback functions if necessary, can be used for an collision only system
    void collisionUpdate() { NewtonCollisionUpdate( m_world ); }
    //! to iterate through all bodies call this function and then use body->getNext()
    Body* getFirstBody() const;

    /*
    //! to iterate through all material-pairs use this function and then call matPair->getNext()
    MaterialGroupID* getFirstMaterialGroupID();
    */

    //! get a bodyInAABBIterator for this world
    const BodyInAABBIterator& getBodyInAABBIterator() const {return m_bodyInAABBIterator;}

    //! get the debugger for this world
    /*!
     * the debugger needs to be initialized (Debugger::init(...) ) in order to work correctly
    */
    Debugger& getDebugger() const {return *m_debugger;}

    //! adds an update request for the body, this means that after the next world update the function body->updateNode will be called, if the bodie needs updating
	void addBodyUpdateNodeRequest( int threadIndex, OgreNewt::Body* body ) const ;


#ifndef WIN32
    //! notify an entrance to a critical section of code concerning Ogre (and only concerning Ogre!)
    /*!
     * This function is only used in OgreNewt and can be used by the user, it is independent of Ogre's own thread support...
    */
    void ogreCriticalSectionLock() const { pthread_mutex_lock(&m_ogreMutex); }

    //! notify the exit of a critical section of code concerning Ogre (and only concerning Ogre!)
    /*!
     * This function is only used in OgreNewt and can be used by the user, it is independent of Ogre's own thread support...
    */
    void ogreCriticalSectionUnlock() const { pthread_mutex_unlock(&m_ogreMutex); }

    //! notify an entrance to a critical section of code concerning Ogre (and only concerning Ogre!)
    /*!
     * This function is only used in OgreNewt and can be used by the user, it is independent of Ogre's own thread support...
     * \return true if not already locked
    */
    // bool ogreCriticalSectionTryLock() const { return (EBUSY != pthread_mutex_trylock(&m_ogreMutex)); }
#endif

protected:
    
	int m_maxTicksPerFrames;
	Ogre::Real m_timestep;
	Ogre::Real m_invTimestep;
	Ogre::Real m_timeAcumulator;
	Ogre::Real m_updateFPS;

	Ogre::Vector3 m_defaultAngularDamping;
	Ogre::Real m_defaultLinearDamping;

    NewtonWorld* m_world;
    MaterialID* m_defaultMatID;

    LeaveWorldCallback m_leaveCallback;

    BodyInAABBIterator m_bodyInAABBIterator;

    typedef std::vector< OgreNewt::Body* > BodyVector;
    typedef std::vector< BodyVector > BodyVectorVector;
	mutable BodyVectorVector m_bodyUpdateNodeRequests;

    mutable Debugger* m_debugger;

#ifndef WIN32
    mutable pthread_mutex_t m_ogreMutex;
#endif

private:

    static void _CDECL newtonLeaveWorld( const NewtonBody* body, int threadIndex );

    Ogre::AxisAlignedBox m_limits;
};

}

    
#endif
// _INCLUDE_OGRENEWT_WORLD


