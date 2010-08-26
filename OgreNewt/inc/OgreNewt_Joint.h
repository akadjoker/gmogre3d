/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_JOINT
#define _INCLUDE_OGRENEWT_JOINT



#include "OgreNewt_Prerequisites.h"

class NewtonCustomJoint; 

// OgreNewt namespace.  all functions and classes use this namespace.
namespace OgreNewt
{

	//! base class for all joints.
	/*!
	this class is inherited by all other specific joint types.
	*/
	//class _OgreNewtExport Joint : public _DestructorCallback<Joint>
	class _OgreNewtExport Joint
	{
		public:

		//! constructor
		Joint();

		//! destructor
		virtual ~Joint();

		//! get the pointer to the first rigid body
		Body* getBody0 () const;

		//! get the pointer to the first rigid body
		Body* getBody1 () const;


		//! must be define for a functioning joint.
		virtual void submitConstraint( Ogre::Real timeStep, int threadIndex ) {};

		//! show joint visual debugging data
		/*! 
			this function is called from the Debug display utility to show joint debug display information
			the function should be overridden by any derive class who wishes to show debug physics information for this joint in real time.
		*/
		virtual void showDebugData(Ogre::SceneNode* debugRootNode) {}


		protected:
		/*!
			These functions are for applications who want to extend existing joint or to create entire new joint from scratch
		*/

		//! 
		void addLinearRow( const Ogre::Vector3& pt0, const Ogre::Vector3& pt1, const Ogre::Vector3& dir ) const;

		//! 
		void addAngularRow( Ogre::Radian relativeAngleError, const Ogre::Vector3& dir ) const;

		//! 
		void addGeneralRow(const Ogre::Vector3& linear0, const Ogre::Vector3& angular0, const Ogre::Vector3& linear1, const Ogre::Vector3& angular1) const;

		//! 
		void setRowMinimumFriction( Ogre::Real friction ) const;

		//! 
		void setRowMaximumFriction( Ogre::Real friction ) const;

		//! 
		void setRowStiffness( Ogre::Real stiffness ) const;

		//! 
		void setRowAcceleration( Ogre::Real accel ) const;

		//! 
		void setRowSpringDamper(Ogre::Real springK, Ogre::Real springD) const;

		//! returns collision state
		/*!
		The collision state determines whether collision should be calculated between the parent and child bodies of the joint.
		\return integer value. 1 = collision on, 0 = collision off.
		*/
		int getCollisionState() const;

		//! sets the collision state
		/*!
		The collision state determines whether collision should be calculated between the parent and child bodies of the joint.
		\param state integer value. 1 = collision on, 0 = collision off.
		*/      
		void setCollisionState( int state ) const;

		//! get joint stiffness
		/*!
		Joint stiffness adjusts how much "play" the joint can have.  high stiffness = very small play, but more likely to become unstable.
		\return float representing joint stiffness in range [0,1]
		*/
		Ogre::Real getStiffness() const;

		//! set joint stiffness
		/*!
		Joint stiffness adjusts how much "play" the joint can have.  high stiffness = very small play, but more likely to become unstable.
		\param stiffness float representing joint stiffness in range [0,1]
		*/
		void setStiffness( Ogre::Real stiffness ) const;

	protected:

		//! joint destructor callback glue
		static void _CDECL destructorCallback (const NewtonCustomJoint* me);

		// ! submitConstraint callback glue
		static void _CDECL submitConstraintCallback ( const NewtonCustomJoint* me, dFloat timestep, int threadIndex );

		//! SetSupportJoint
		void SetSupportJoint (NewtonCustomJoint* supportJoint);

		//! GetSupportJoint
		NewtonCustomJoint* GetSupportJoint () const;

		NewtonCustomJoint* m_joint;
	};

	class _OgreNewtExport CustomJoint : public Joint
	{
	public:
		CustomJoint( unsigned int maxDOF, const OgreNewt::Body* child, const OgreNewt::Body* parent);
		virtual ~CustomJoint();

		void pinAndDirToLocal( const Ogre::Vector3& pinpt, const Ogre::Vector3& pindir, Ogre::Quaternion& localOrient0, Ogre::Vector3& localPos0, Ogre::Quaternion& localOrient1, Ogre::Vector3& localPos1 ) const;
		void localToGlobal( const Ogre::Quaternion& localOrient, const Ogre::Vector3& localPos, Ogre::Quaternion& globalOrient, Ogre::Vector3& globalPos, int bodyIndex ) const;
		void globalToLocal( const Ogre::Quaternion& globalOrient, const Ogre::Vector3& globalPos, Ogre::Quaternion& localOrient, Ogre::Vector3& localPos, int bodyIndex ) const;
		Ogre::Quaternion grammSchmidt( const Ogre::Vector3& pin ) const;

	protected:
		unsigned int m_maxDOF;

		const OgreNewt::Body* m_body0;
		const OgreNewt::Body* m_body1;
	};

}   // end NAMESPACE OgreNewt




// _INCLUDE_OGRENEWT_JOINT

#endif