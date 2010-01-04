/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_BASICJOINTS
#define _INCLUDE_OGRENEWT_BASICJOINTS

#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_Joint.h"


// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{

	//! Ball and Socket joint.
	/*!
	simple ball and socket joint, with limits.
	*/
	class _OgreNewtExport BallAndSocket : public Joint
	{

	public:
		//! constructor
		/*!
		\param child pointer to the child rigid body.
		\param parent pointer to the parent rigid body. pass NULL to make the world itself the parent (aka a rigid joint)
		\param pos position of the joint in global space
		*/
		BallAndSocket( const OgreNewt::Body* child, const OgreNewt::Body* parent, const Ogre::Vector3& pos );

		//! destructor.
		~BallAndSocket();

#if 0
		//! retrieve the current joint angle
		Ogre::Vector3 getJointAngle() const;

		//! retrieve the current joint omega
		Ogre::Vector3 getJointOmega() const;

		//! retrieve the current joint force.
		/*!
		This can be used to find the "stress" on the joint.  you can do special effects like break the joint if the force exceedes some value, etc.
		*/
		Ogre::Vector3 getJointForce() const;

		//! set limits for the joints rotation
		/*!
		\param pin pin direction in global space
		\param maxCone max angle for "swing" (in radians)
		\param maxTwist max angle for "twist"  (in radians)
		*/
		void setLimits( const Ogre::Vector3& pin, Ogre::Radian maxCone, Ogre::Radian maxTwist ) const { NewtonBallSetConeLimits( m_joint, &pin.x, (float)maxCone.valueRadians(), (float)maxTwist.valueRadians() ); }
#endif

	};



	//! hinge joint.
	/*!
	simple hinge joint.  implement motors/limits through a callback.
	*/
	class _OgreNewtExport Hinge : public Joint
	{

	public:

		//! constructor
		/*!
		\param child pointer to the child rigid body.
		\param parent pointer to the parent rigid body. pass NULL to make the world itself the parent (aka a rigid joint)
		\param pin direction of the joint pin in global space
		*/
		Hinge (const OgreNewt::Body* child, const OgreNewt::Body* parent, const Ogre::Vector3& pos, const Ogre::Vector3& pin );

		//! destructor
		~Hinge();

		//! enable hinge limits.
		void enableLimits(bool state);

		//! set minimum and maximum hinge limits.
		void setLimits(Ogre::Radian minAngle, Ogre::Radian maxAngle);

		//! get the relative joint angle around the hinge pin.
		Ogre::Real getJointAngle () const;

		//! get the relative joint angle around the hinge pin.
		Ogre::Real getJointAngulatVelocity () const;

		//! get the joint pin in global space
		Ogre::Vector3 getJointPin () const;
	};


	//! slider joint.
	/*!
	simple slider joint.  implement motors/limits through a callback.
	*/
	class _OgreNewtExport Slider : public Joint
	{

		public:

		//! constructor
		/*!
		\param child pointer to the child rigid body.
		\param parent pointer to the parent rigid body. pass NULL to make the world itself the parent (aka a rigid joint)
		\param pin direction of the joint pin in global space
		*/
		Slider(const OgreNewt::Body* child, const OgreNewt::Body* parent, const Ogre::Vector3& pos, const Ogre::Vector3& pin );

		//! destructor.
		~Slider();

		//! enable limits.
		void enableLimits(bool state);

		//! set minimum and maximum stops limits.
		void setLimis(Ogre::Real minStopDist, Ogre::Real maxStopDist);
	};


#if 0
	//! this class represents a Universal joint.
	/*!
	simple universal joint.  implement motors/limits through a callback.
	*/
	class _OgreNewtExport Universal : public Joint
	{

	public:

		//! custom universal callback function.
		/*!
		use the setCallback() function to assign your custom function to the joint.
		*/
		typedef void(*UniversalCallback)( Universal* me );

		//! constructor
		/*!
		\param world pointer to the OgreNewt::World
		\param child pointer to the child rigid body.
		\param parent pointer to the parent rigid body. pass NULL to make the world itself the parent (aka a rigid joint)
		\param pos position of the joint in global space
		\param pin0 direction of the first axis of rotation in global space
		\param pin1 direction of the second axis of rotation in global space
		*/
		Universal( const World* world, const OgreNewt::Body* child, const OgreNewt::Body* parent, const Ogre::Vector3& pos, const Ogre::Vector3& pin0, const Ogre::Vector3& pin1 );

		//! destructor
		~Universal();

		//! get the angle around pin0.
		Ogre::Radian getJointAngle0() const { return Ogre::Radian(NewtonUniversalGetJointAngle0( m_joint )); }

		//! get the angle around pin1.
		Ogre::Radian getJointAngle1() const { return Ogre::Radian(NewtonUniversalGetJointAngle1( m_joint )); }

		//! get the rotational velocity around pin0.
		Ogre::Real getJointOmega0() const { return (Ogre::Real)NewtonUniversalGetJointOmega0( m_joint ); }

		//! get the rotational velocity around pin1.
		Ogre::Real getJointOmega1() const { return (Ogre::Real)NewtonUniversalGetJointOmega1( m_joint ); }

		//! get the force on the joint.
		Ogre::Vector3 getJointForce() const;

		//! set a custom callback for controlling this joint.
		/*!
		Joint callbacks allow you to make complex joint behavior such as limits or motors.  just make a custom static function that
		accepts a pointer to a OgreNewt::BasicJoints::Universal as the single parameter.  this function will be called automatically every
		time you upate the World.
		*/
		void setCallback( UniversalCallback callback ) { m_callback = callback; }

		////////// CALLBACK COMMANDS ///////////
		// the following commands are only valid from inside a hinge callback function

		//! set the acceleration around a particular pin.
		/*
		this function can only be called from within a custom callback.
		\param accel desired acceleration
		\param axis which pin to use (0 or 1)
		*/
		void setCallbackAccel( Ogre::Real accel, unsigned axis );

		//! set the minimum friction around a particular pin
		/*
		this function can only be called from within a custom callback.
		\param min minimum friction
		\param axis which pin to use (0 or 1)
		*/
		void setCallbackFrictionMin( Ogre::Real min, unsigned axis );

		//! set the maximum friction around a particular pin.
		/*
		this function can only be called from within a custom callback.
		\param max maximum friction
		\param axis which pin to use (0 or 1)
		*/
		void setCallbackFrictionMax( Ogre::Real max, unsigned axis );

		//! get the current phsics timestep.
		/*
		this function can only be called from within a custom callback.
		*/
		Ogre::Real getCallbackTimestep() const;

		//! calculate the acceleration neccesary to stop the joint at the specified angle on pin 0.
		/*!
		For implementing joint limits.
		This command is only valid when used inside a custom  callback.
		*/
		Ogre::Real calculateStopAlpha0( Ogre::Real angle ) const;

		//! calculate the acceleration neccesary to stop the joint at the specified angle on pin 1.
		/*!
		For implementing joint limits.
		This command is only valid when used inside a custom  callback.
		*/
		Ogre::Real calculateStopAlpha1( Ogre::Real angle ) const;

	protected:

		//! newton callback.  used internally.
		static unsigned _CDECL newtonCallback( const NewtonJoint* universal, NewtonHingeSliderUpdateDesc* desc );

		UniversalCallback m_callback;
		NewtonHingeSliderUpdateDesc* m_desc;

		unsigned m_retval;
	};



	//! UpVector joint.
	/*!
	simple upvector joint.  upvectors remove all rotation except for a single pin.  useful for character controllers, etc.
	*/
	class _OgreNewtExport UpVector : public Joint
	{

	public:
		//! constructor
		/*
		\param world pointer to the OgreNewt::World.
		\param body pointer to the body to apply the upvector to.
		\param pin direction of the upvector in global space.
		*/
		UpVector( const World* world, const Body* body, const Ogre::Vector3& pin );

		//! destructor
		~UpVector();

		//! set the pin direction.
		/*
		by calling this function in realtime, you can effectively "animate" the pin.
		*/
		void setPin( const Ogre::Vector3& pin ) const { NewtonUpVectorSetPin( m_joint, &pin.x ); }

		//! get the current pin direction.
		Ogre::Vector3 getPin() const;
	};



	//! namespace for pre-built custom joints
	namespace PrebuiltCustomJoints
	{

		//! Custom2DJoint class
		/*!
		This class represents a joint that limits movement to a plane, and rotation only around the normal of that
		plane.  This can be used to create simple 2D simulations.  it also supports limits and acceleration for spinning.
		This joint has been used in a few projects, but is not 100% fully-tested.
		*/
		class _OgreNewtExport Custom2DJoint : public OgreNewt::CustomJoint
		{
		public:
			//! constructor
			Custom2DJoint( const OgreNewt::Body* body, const Ogre::Vector3& pin );

			//! destructor
			~Custom2DJoint() {}

			//! overloaded function that applies the actual constraint.
			void submitConstraint( Ogre::Real timeStep, int threadIndex );

			//! get the current angle of the joint.
			Ogre::Radian getAngle() const { return mAngle; }

			//! set rotational limits for the joint.
			void setLimits( Ogre::Degree min, Ogre::Degree max ) { mMin = min, mMax = max; }

			//! sets whether to enable limits or not for the joint.
			void setLimitsOn( bool onoff ) { mLimitsOn = onoff; }

			//! returns whether limits are turned on or off for the joint.
			bool getLimitsOn() const { return mLimitsOn; }

			//! adds rotational acceleration to the joint (like a motor)
			void addAccel( Ogre::Real accel ) { mAccel = accel; }

			//! resets the joint angle to 0.  this simply sets the internal variable to zero.
			//! you might want to call this for example after resetting a body.
			void resetAngle() { mAngle = Ogre::Radian(0.0f); }

			//! get the pin.
			Ogre::Vector3 getPin() { return mPin; }

		private:
			Ogre::Vector3 mPin;
			Ogre::Quaternion mLocalOrient0, mLocalOrient1;
			Ogre::Vector3 mLocalPos0, mLocalPos1;

			Ogre::Radian mAngle;

			Ogre::Radian mMin;
			Ogre::Radian mMax;

			bool mLimitsOn;

			Ogre::Real mAccel;
		};

		//! CustomFixedJoint
		/*!
		This joint implements a fully fixed joint, which removes all DOF, creating a completely fixed connection between bodies.
		This is probably the most expensive kind of joint, and should only be used when really needed.
		*/
		class _OgreNewtExport CustomRigidJoint : public OgreNewt::CustomJoint
		{
		public:
			CustomRigidJoint( OgreNewt::Body* child, OgreNewt::Body* parent, Ogre::Vector3 dir, Ogre::Vector3 pos);
			~CustomRigidJoint();

			void submitConstraint( Ogre::Real timeStep, int threadIndex );

		private:
			Ogre::Vector3 mLocalPos0;
			Ogre::Vector3 mLocalPos1;

			Ogre::Quaternion mLocalOrient0;
			Ogre::Quaternion mLocalOrient1;
		};

		//! CustomDryRollingFriction
		/*!
		* This joint is usefully to simulate the rolling friction of a rolling ball over a flat surface.
		* Normally this is not important for non spherical objects, but for games like poll, pinball, bolling, golf
		* or any other where the movement of balls is the main objective the rolling friction is a real big problem.
		*/
		/* // not tested yet
		class _OgreNewtExport CustomDryRollingFriction : public OgreNewt::CustomJoint
		{
		public:
		CustomDryRollingFriction( OgreNewt::Body* child, Ogre::Real radius, Ogre::Real rollingFrictionCoefficient );
		~CustomDryRollingFriction();

		void submitConstraint( Ogre::Real timestep, int threadIndex );

		private:
		Ogre::Real mFrictionCoefficient;
		Ogre::Real mFrictionTorque;
		OgreNewt::Body* mChild;
		};
		*/

	}   // end NAMESPACE PrebuiltCustomJoints

#endif


	//! Kinematic controller joint.
	/*!
	simple Kinematic controller. used it to make a simple object follow a path or a position.
	*/
	class _OgreNewtExport KinematicController : public Joint
	{

		public:

		//! constructor
		/*!
		\param child pointer to the controlled rigid body.
		\param attachment point in global space
		*/
		KinematicController(const OgreNewt::Body* child, const Ogre::Vector3& pos);

		//! destructor.
		~KinematicController();

		//! enable limits. 
		/*!
		\param mode 1 at like control by position and rotation, 0 control rotation only
		*/
		void setPickingMode (int mode);

		//! set the linear acceleration the joint can take before the joint is violated . 
		/*!
		\param accel maximum acceleration at the attachment point
		*/
		void setMaxLinearFriction(Ogre::Real accel); 

		//! set the angular acceleration the joint can take before the joint is violated . 
		/*!
		\param alpha maximum acceleration at the attachment point
		*/
		void setMaxAngularFriction(Ogre::Real alpha); 

		//! set the position part of the attachment matrix
		/*!
		\param position new destination position in global space
		*/
		void setTargetPosit (const Ogre::Vector3& position);

		//! set the orientation part of the attachment matrix
		/*!
		\param rotation new destination position in global space
		*/
		void setTargetRotation (const Ogre::Quaternion& rotation); 

		//! set the position and orientation part of the attachment matrix
		/*!
		\param position new destination position in global space
		\param rotation new destination position in global space
		*/
		void setTargetMatrix (const Ogre::Vector3& position, const Ogre::Quaternion& rotation); 

		//! set the position and orientation part of the attachment matrix
		/*!
		\param position new destination position in global space
		\param rotation new destination position in global space
		*/
		void getTargetMatrix (Ogre::Vector3& position, Ogre::Quaternion& rotation) const;

	};

}   // end NAMESPACE OgreNewt

#endif
// _INCLUDE_OGRENEWT_BASICJOINTS

