/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.


    please note that the "boost" library files included here are not of my creation, refer to those files and boost.org for information.


        by Walaber
        some changes by melven

*/

#ifndef _INCLUDE_OGRENEWT_BODY
#define _INCLUDE_OGRENEWT_BODY

#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_MaterialID.h"
#include "OgreNewt_Collision.h"


// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{

/*
    CLASS DEFINITION:

        Body

    USE:
        this class represents a NewtonBody rigid body!
*/
//! main class for all Rigid Bodies in the system.
class _OgreNewtExport Body : public _DestructorCallback<Body>
{
public:
    //! custom force callback.
    /*!
        this function is called from within the OgreNewt::World::update() command when applying forces to Rigid Bodies, such as
        gravity, etc.

        You can set this as the custom force callback for a body by using the setCustomForceCallback() function.
        Using boost::function means OgreNewt can now accept pointers to member functions of specific classes.
    */
    typedef boost::function<void(OgreNewt::Body*, float timeStep, int threadIndex)> ForceCallback;


    //! node update notify.
    /*
		this function pointer, when set, is called from updateNode to notify the application 
		the this node the function is controlling has being modified.
		The application can use this function to re calculate relative position of child nodes, or any other depended transform.

		You can set this as the by using the setnNodeUpdateNotify() function.
		Using boost::function means OgreNewt can now accept pointers to member functions of specific classes.
    */
    typedef boost::function<void(OgreNewt::Body*)> NodeUpdateNotifyCallback;


#if 0
	//! custom transform callback.
    /*!
        This function is called from within the OgreNewt::World::update() command for all Rigid Bodies, after all collision and
        forces have been resolved.  this command is intended to allow the user to align a visual object with the new position and
        orientation of the rigid body.  OgreNewt has a general transform callback built-in for use with Ogre.  however you can 
        create your own for special cases.  you are passed a quaternion (orientation) and vector (position) of the rigid body
        in world space.
    */
    //typedef boost::function<void(OgreNewt::Body*, const Ogre::Quaternion&, const Ogre::Vector3&, int threadIndex)> TransformCallback;
	//typedef boost::function<void(OgreNewt::Body*, int threadIndex)> TransformCallback;
#endif
    

    //! buoyancy plane callback
    /*!
        this function is a user-defined function that supplies Newton with the plane equation for the surface of the liquid when
        applying buoyancy forces.  the user should create their own function for this, that returns an Ogre::Plane based on their
        own criteria.  you get a pointer to the OgreNewt::Body, and it's current orientation and location to boot.  note that this
        callback will be called for each collision primitive in the body (if it is a compound collision).  if you want to
        ignore buoyancy for this collision primitive, just return false from the function.  otherwise, fill the "retPlane" with your
        liquid surface plane, and return true to apply buoyancy to the primitive.
    */
    typedef boost::function<bool(int, OgreNewt::Body*, const Ogre::Quaternion&, const Ogre::Vector3&, Ogre::Plane&)> buoyancyPlaneCallback;

    //! constructor.
    /*!
        creates a Rigid Body in an OgreNewt::World, based on a specific collision shape.
        \param W pointer to the OgreNewt::World/
        \param col pointer to an OgreNewt::Collision object that represents the shape of the rigid body.
        \param bodytype simple integer value used to identify the type of rigid body, useful for determining bodies in callbacks.
    */
    Body( const World* W, const OgreNewt::CollisionPtr& col, int bodytype = 0 );

    //! destructor
    ~Body();

    //! set user data to connect this class to another.
    /*!
        you can use this to store a pointer to a parent class, etc.  then inside one of the many callbacks, you can get the pointer
        using this "userData" system.
    */
#ifndef OGRENEWT_NO_OGRE_ANY
    void setUserData( const Ogre::Any& data ) { m_userdata = data; }
#else
    void setUserData( void* data ) { m_userdata = data; }
#endif

    //! retrieve pointer to previously set user data.
#ifndef OGRENEWT_NO_OGRE_ANY
    const Ogre::Any& getUserData() const { return m_userdata; }
#else
    void* getUserData() const { return m_userdata; }
#endif

    //! get a pointer to the NewtonBody object
    /*!
        this is the NewtonBody used by the Newton SDK.  in most cases you shouldn't need to access this.
    */
    NewtonBody* getNewtonBody() const { return m_body; }

    //! get a pointer to the attached Node.
    /*!
        if you have "attached" an Ogre::Node to this body, this retrieves the node.
    */
    Ogre::Node* getOgreNode() const { return m_node; }

    //! get a pointer to the OgreNewt::World this body belongs to.
    const OgreNewt::World* getWorld() const { return m_world; }

    //! set the type for this body.
    /*!
        this sets the "type" for the body, which can also be set in the constructor.
        \param type integer value to represent the type of body, e.g. "FLOOR" or "CANON BALL", etc. used for differentation in material callbacks.
    */
    void setType( int type ) { m_type = type; }

    //! get the type set for this body.
    int getType() const { return m_type; }

    //! attach this body to an Ogre::Node*
    /*!
        This is an easy way to connect a Rigid Body with an Ogre::Node.  this automatically sets up a standard Transform callback when you call this.  after calling this, the Ogre::Node will have its position orientation updated to that of the Rigid Body each time you call World::update(), and the body has moved during the update.
    */
    void attachNode( Ogre::Node* node );

    //! set a standard gravity callback for this body to use.
    /*!
        This sets a very basic force callback for this body, that simply applies a standard 9,8m/s^2 gravity force to the body.
        in most cases you will need more forces acting on your Rigid Bodies, which you accomplish through custom force callbacks.
    */
    void setStandardForceCallback();

    //! set a custom force callback for this body to use.
    /*
        This specifies a custom callback to use for applying forces to a body.  if you are using a standard non-member function, or a static member function, you can simply pass a pointer to the function here.. like this:
        setCustomForceAndTorqueCallback( &myCallbackFunction );

        If you want to bind to a class member, you also need to pass a pointer to the class itself, using the boost::bind system, like so:
        setCustomForceAndTorqueCallback( boost::bind( &MyClass::myCallback, (MyClass*)classInstance, _1 ) );  (from outside the class) or:
        setCustomForceAndTorqueCallback( boost::bind( &MyClass::myCallback, this, _1 ) );  (from inside the class).

        You can also use:
        setCustomForceAndTorqueCallback<>( &MyClass::myCallback, (MyClass*)classInstance );  (from outside the class) or:
        setCustomForceAndTorqueCallback<>( &MyClass::myCallback, this );  (from inside the class).
        Note: Notice the "<>" after the function name.
    */
    void setCustomForceAndTorqueCallback( ForceCallback callback );
    template<class c> void setCustomForceAndTorqueCallback( boost::function<void(c*, Body*, float, int)> callback, c *instancedClassPointer )
    {
        setCustomForceAndTorqueCallback( boost::bind(callback, instancedClassPointer, _1, _2, _3) );
    }

    //! remove any force callbacks.
    void removeForceAndTorqueCallback() { NewtonBodySetForceAndTorqueCallback( m_body, NULL );  m_forcecallback = NULL; }

	//! returns correct force-torque callback
	ForceCallback getForceTorqueCallback()
	{
		return m_forcecallback;
	}


    //! set a custom node update notify.
    /*
		set a function pointer to be called for function nodeUpdate when the application desires to be notified that this node is bing updated.
		Control joints like the vehicle an drag dolls use the function to calculate the correct matrix of wheels and body parts.  
    */
	void setNodeUpdateNotify (NodeUpdateNotifyCallback callback );
    template<class c> void setNodeUpdateNotify (boost::function<void(c*, OgreNewt::Body*)> callback, c *instancedClassPointer )
    {
        setNodeUpdateNotify( boost::bind(callback, instancedClassPointer, _1) );
    }

    //! remove any transform callbacks.
    void removeNodeUpdateNotify() { m_nodeupdatenotifycallback = NULL;}


    //! position and orient the body arbitrarily.
    /*!
        generally in a physics engine you shouldn't directly set the location/rotation of a Body, because this defies physics laws.  this command exists to set up bodies initially.
        \param orient quaternion representing body orientation in world space.
        \param pos vector representing body position in world space. 
        \param threadIndex only set the thread-index if you don't want the node to be updated immediatly but queued (Ogre doesn't support modifying nodes from several threads)
    */
    void setPositionOrientation( const Ogre::Vector3& pos, const Ogre::Quaternion& orient , int threadIndex = -1);

    //! set the mass and inertia for the body.
    /*!
        Set the mass of the Rigid Body.  Inertia is also set here.  Inertia represents a body's "resistance" to rotation around the 3 primary axis.  OgreNewt has a few utility functions that can help you calculate these values based on several primitive shapes.
        \param mass real value for the body mass
        \param inertia vector representing body moment of inertia
    */
    void setMassMatrix( Ogre::Real mass, const Ogre::Vector3& inertia );

    //! set the body's center of mass
    /*!
        Set a new center of mass for the body that is different than the current, without offsetting the body.
        You can use this to adjust the center of mass of a body at runtime.
    */
    void setCenterOfMass( const Ogre::Vector3& centerOfMass ) { NewtonBodySetCentreOfMass( m_body, &centerOfMass.x ); }

    //! get the center of mass.
    /*!
        returns the current center of mass, as an offset from the original origin when the body was created.
    */
    Ogre::Vector3 getCenterOfMass() const;

    //! freeze the rigid body.
    /*!
        this command "freezes" the Rigid Body, removing it from the active simulation list.  it will "unfreeze" if another body comes in contact with it, or you "unfreeze" it.
        \sa unFreeze()
    */
   void freeze() { NewtonBodySetFreezeState( m_body, 1 ); }

    //! unfreeze the rigid body.
    /*!
        \sa freeze()
    */
    void unFreeze() { NewtonBodySetFreezeState( m_body, 0 ); }

    //! is the body freezed?
    bool isFreezed() { return NewtonBodyGetFreezeState( m_body ) != 0; }
            
    //! set the material for the body
    /*!
        Materials are an extremely powerful way to control body behavior. first create a new MaterialID object, and then pass a pointer
        to apply that material to the body. 
        \param ID pointer to an OgreNewt::MaterialID object to use as the material for the body.
    */
    void setMaterialGroupID( const MaterialID* ID ) { m_matid = ID; NewtonBodySetMaterialGroupID( m_body, m_matid->getID() ); }
    
    //! prevents fast moving bodies from "tunneling" through other bodies.
    /*!
        continuous collision is an advanced feature that prevents fast moving bodies from "tunneling" (missing collision) with other bodies.  there 
        is a performance hit envolved, so this feature should only be used for bodies that have a high likelyhood of tunneling.
        
        note that continuous collision can also be set on a per-material basis via the MaterialPair class.
    */
    void setContinuousCollisionMode( unsigned state ) { NewtonBodySetContinuousCollisionMode( m_body, state ); }

    //! set whether all parent/children pairs connected to this body should be allowed to collide.
    void setJointRecursiveCollision( unsigned state ) { NewtonBodySetJointRecursiveCollision( m_body, state ); }

    //! set an arbitrary omega for the body.
    /*!
        again, setting velocity/omega directly for a body in realtime is not recommended for proper physics behavior.  this function is intended to be used to setup a Body initially.
        \param omega vector representing the desired omega (rotational velocity)
    */
    void setOmega( const Ogre::Vector3& omega ) { NewtonBodySetOmega( m_body, &omega.x ); }

    //! set an arbitrary velocity for the body.
    /*!
        again, setting velocity/omega directly for a body in realtime is not recommended for proper physics behavior.  this function is intended to be used to setup a Body initially.
        \param vel vector representing the desired velocity.
    */
    void setVelocity( const Ogre::Vector3& vel ) { NewtonBodySetVelocity( m_body, &vel.x ); }

    //! set the linear damping for the body.
    void setLinearDamping( Ogre::Real damp ) { NewtonBodySetLinearDamping( m_body, (float)damp ); }

    //! set the angular damping for the body.
    void setAngularDamping( const Ogre::Vector3& damp ) { NewtonBodySetAngularDamping( m_body, &damp.x ); }

    //! set the collision that represents the shape of the body
    /*!
        This can be used to change the collision shape of a body mid-simulation.  for example making the collision for a character smaller when crouching, etc.
        \param col pointer to the new OgreNewt::Collision shape.
    */
    void setCollision( const OgreNewt::CollisionPtr& col );

    //! set whether the body should "sleep" when equilibruim is reached.
    /*!
        user-controlled bodies should disable sleeping, because frozen bodies' callbacks are not called... so a callback that implements motion based on user input will not be called!
    */
    void setAutoSleep( int flag ) { NewtonBodySetAutoSleep ( m_body, flag); }

    //! get whether the body should "sleep" when equilibrium is reached.
    int getAutoSleep() { return NewtonBodyGetAutoSleep( m_body ); }

    //! set the factors that cause a body to "freeze" when equilibrium reached.
    //void setFreezeThreshold( Ogre::Real speed, Ogre::Real omega, int framecount ) { NewtonBodySetFreezeTreshold( m_body, (float)speed, (float)omega, framecount ); }

    //! get a pointer to the OgreNewt::Collision for this body
    const OgreNewt::CollisionPtr& getCollision() const;

    //! get a pointer to the Material assigned to this body.
    const OgreNewt::MaterialID* getMaterialGroupID() const;

    //! returns current setting for this body.
    int getContinuousCollisionMode() const { return NewtonBodyGetContinuousCollisionMode( m_body ); }

    //! returns current setting for this body.
    int getJointRecursiveCollision() const { return NewtonBodyGetJointRecursiveCollision( m_body ); }

    //! get position and orientation in form of an Ogre::Vector(position) and Ogre::Quaternion(orientation)
    void getPositionOrientation( Ogre::Vector3& pos, Ogre::Quaternion& orient ) const;

	//! returns body position
	Ogre::Vector3 getPosition() const;

	//! returns body orientation
	Ogre::Quaternion getOrientation() const;

	//! get the node position and orientation in form of an Ogre::Vector(position) and Ogre::Quaternion(orientation)
    /*!
        this function should be used for calculating Render matrix render or anything related to render time
    */
	void getVisualPositionOrientation( Ogre::Vector3& pos, Ogre::Quaternion& orient ) const;

	//! return body visual position
	Ogre::Vector3 getVisualPosition() const;

	//! returns body visual orientation
	Ogre::Quaternion getVisualOrientation() const;


    //! get the axis-aligned bounding box for this body.
    Ogre::AxisAlignedBox getAABB() const;

    //! get Ogre::Real(mass) and Ogre::Vector3(inertia) of the body.
    void getMassMatrix( Ogre::Real& mass, Ogre::Vector3& inertia ) const;

    //! get invert mass + inertia for the body.
    void getInvMass( Ogre::Real& mass, Ogre::Vector3& inertia ) const;

    //! get omega of the body. in global space. 
    Ogre::Vector3 getOmega() const;

    //! get velocity of the body. in global coordinates.
    Ogre::Vector3 getVelocity() const;

    //! get the force acting on the body.
    Ogre::Vector3 getForce() const;

    //! get the torque acting on the body.
    Ogre::Vector3 getTorque() const;

    //! get the linear acceleration due to forces acting on the body.
    Ogre::Vector3 getForceAcceleration() const;

    //! get the rotational acceleration due to torque acting on the body.
    Ogre::Vector3 getTorqueAcceleration() const;

    //! get linear damping
    Ogre::Real getLinearDamping() const { return (Ogre::Real)NewtonBodyGetLinearDamping( m_body ); }

    //! get angular damping
    Ogre::Vector3 getAngularDamping() const;

    //! calculate force needed for given velocity
    Ogre::Vector3 calculateInverseDynamicsForce(Ogre::Real timestep, Ogre::Vector3 desiredVelocity);

    //! get the freeze threshold
    //void getFreezeThreshold( Ogre::Real& speed, Ogre::Real& omega ) const { NewtonBodyGetFreezeTreshold( m_body, &speed, &omega ); }

    //! add an impulse (relative change in velocity) to a body.  values are in world coordinates.
    void addImpulse( const Ogre::Vector3& deltav, const Ogre::Vector3& posit ) { NewtonBodyAddImpulse( m_body, &deltav.x, &posit.x ); }

    //! add force to the body.  
    /*!
        this function is only valid inside a ForceCallback function!
    */
    void addForce( const Ogre::Vector3& force ) { NewtonBodyAddForce( m_body, &force.x ); }

    //! add torque to the body.
    /*!
        this function is only valid inside a ForceCallback function!
    */
    void addTorque( const Ogre::Vector3& torque ) { NewtonBodyAddTorque( m_body, &torque.x ); }

    //! set the force for a body.
    /*!
        this function is only valid inside a ForceCallback function!
    */
    void setForce( const Ogre::Vector3& force ) { NewtonBodySetForce( m_body, &force.x ); }

    //! set the torque for a body.
    /*!
        this function is only valid inside a ForceCallback function!
    */
    void setTorque( const Ogre::Vector3& torque ) { NewtonBodySetTorque( m_body, &torque.x ); }


    //! apply a buoyancy force to the body.
    /*!
        buoyancy is one of the more powerful and overlooked features of the Newton physics system.  you can of course
        simulate floating objects, and even lighter-than-air objects like balloons, etc.
        \param fluidDensity density of the fluid.
        \param fluidLinearViscosity how much the fluid slows linear motion
        \param fluidAngularViscosity how much the fluid slows rotational motion
        \param gravity vector representing world gravity.
        \param buoyancyPlaneCallback user function that returns the plane equation for the fluid at the current location. pass NULL to assume the body is fully immersed in fluid.  see the setCustomForceAndTorqueCallback() docs to info on how to bind class member functions.
    */
    void addBouyancyForce( Ogre::Real fluidDensity, Ogre::Real fluidLinearViscosity , Ogre::Real fluidAngularViscosity , const Ogre::Vector3& gravity, buoyancyPlaneCallback callback );
    template<class c> void addBouyancyForce( Ogre::Real fluidDensity, Ogre::Real fluidLinearViscosity , Ogre::Real fluidAngularViscosity , const Ogre::Vector3& gravity, boost::function<bool(c*, int, Body*, const Ogre::Quaternion&, const Ogre::Vector3&, Ogre::Plane&)> callback, c *instancedClassPointer )
    {
        addBouyancyForce( fluidDensity, fluidLinearViscosity, fluidAngularViscosity, gravity, boost::bind(callback, instancedClassPointer, _1, _2, _3, _4, _5) );
    }


    //! use this function to iterate through all bodies
    Body* getNext() const;



    //! helper function that adds a force (and resulting torque) to an object in global cordinates.
    /*!
        this function is only valid inside a ForceCallback function!
        \param force vector representing force, in global space
        \param pos vector representing location of force, in global space
    */
    void addGlobalForce( const Ogre::Vector3& force, const Ogre::Vector3& pos );

	//! helper function that adds a force (and resulting torque) to an object in global cordinates called from anywhere.
    /*!
        this function can also be called outside ForceCallback function, the calls are accumulated and
		applied in the callback.
        \param force vector representing force, in global space
        \param pos vector representing location of force, in global space
    */
    void addGlobalForceAccumulate( const Ogre::Vector3& force, const Ogre::Vector3& pos );

    // helper function that adds a force (and resulting torque) to an object in local coordinates.
    /*!
        this function is only valid inside a ForceCallback function!
        \param force vector representing force, in local space of the body
        \param pos vector representing locatino of force, in local space of the body
    */
    void addLocalForce( const Ogre::Vector3& force, const Ogre::Vector3& pos );

    //! Returns the Collisiontype for the Collision from this Body
    /*!
     * usually it is also possible to get this via: body->getCollision()->getCollisionPrimitiveType()
    */
    CollisionPrimitiveType getCollisionPrimitiveType() const { return Collision::getCollisionPrimitiveType(getNewtonCollision()); }

    //! Returns the Newton Collision for this Body
    /*!
     * usually it is also possible to get this via: body->getCollision()
    */
    NewtonCollision *getNewtonCollision() const { return NewtonBodyGetCollision( m_body ); }

#if 0
    //! Call this to signify that the position/orientation of the attached node needs to be updated
    /*!
     * This function actually adds this body to a list of bodies that need to be updated. This is done automaticalle after the next world update
     * using the updateNode method.
     * This function is needed for multithreading support
     * \param forceNodeUpdate even request an update if there's already an update request
    */
    void requestNodeUpdate(int threadIndex, bool forceNodeUpdate = false);

    //! Return if an node update was requested
    bool isNodeUpdateNeeded() const {return m_nodeupdateneeded;}
#endif

	//! Return if an node update was requested
	bool isNodeUpdateNeeded() const {return m_nodeupdateneeded;}

	//! Set this body to for visual node update
	void SetNodeUpdateState(bool state) {m_nodeupdateneeded = state;}

    //! update the position of the node (if attached) and sets m_nodeupdateneeded to false
    void updateNode(Ogre::Real interpolatParam);

protected:

    NewtonBody*                     m_body;
    OgreNewt::CollisionPtr          m_collision;
    const MaterialID*               m_matid;
    const World*                    m_world;

	std::vector<std::pair<Ogre::Vector3, Ogre::Vector3>> m_accumulatedGlobalForces;

	Ogre::Vector3					m_nodePosit;
	Ogre::Vector3					m_curPosit;
	Ogre::Vector3					m_prevPosit;
	Ogre::Quaternion				m_nodeRotation;
	Ogre::Quaternion				m_curRotation;
	Ogre::Quaternion				m_prevRotation;
	
    
#ifndef OGRENEWT_NO_OGRE_ANY
    Ogre::Any                       m_userdata;
#else
    void*                           m_userdata;
#endif
    
    int                             m_type;
    Ogre::Node*                     m_node;
    bool                            m_nodeupdateneeded;

    ForceCallback                   m_forcecallback;

	buoyancyPlaneCallback           m_buoyancycallback;
	NodeUpdateNotifyCallback        m_nodeupdatenotifycallback;

private:

    static void _CDECL newtonDestructor( const NewtonBody* body );

    static void _CDECL newtonTransformCallback( const NewtonBody* body, const float* matrix, int threadIndex );
    static void _CDECL newtonForceTorqueCallback( const NewtonBody* body, float timestep, int threadIndex );

    static int _CDECL newtonBuoyancyCallback( const int collisionID, void* context, const float* globalSpaceMatrix, float* globalSpacePlane );

    // standard gravity force callback.
    static void standardForceCallback( Body* me, float timeStep, int threadIndex );

};




}

#endif
// _INCLUDE_OGRENEWT_BODY

