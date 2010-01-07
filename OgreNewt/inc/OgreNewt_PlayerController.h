/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by melven

*/
#ifndef _INCLUDE_OGRENEWT_PLAYERCONTROLLER
#define _INCLUDE_OGRENEWT_PLAYERCONTROLLER


#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_Joint.h"
#include "OgreNewt_RayCast.h"
#include "OgreNewt_Body.h"


namespace OgreNewt
{
	//! PlayerController
	/*!
	this class implements a player-controller based on the code of the CustomPlayerController-class in the Newton-CustomJoints library
	*/
	class _OgreNewtExport PlayerController : public Joint
	{
		public:
		//! constructor
		/*!
		* \param localFrame this is the player frame in global Space (x: side, y: up, -z forward)
		*/
         PlayerController(OgreNewt::Body* child, Ogre::Real stairHeight, Ogre::Real max_slope = 30.0f, Ogre::Real kinematicCushion = 1.0f/64.0f);
		virtual ~PlayerController();

		//! get currently set velocity
		void getVelocity(Ogre::Real &forwardSpeed, Ogre::Real& sideSpeed, Ogre::Radian& heading) const;

		//! set the characters velocity, the -Speed-values can be negative, sideSpeed positive means move to the right, heading is in absolute space
		void setVelocity(Ogre::Real forwardSpeed, Ogre::Real sideSpeed, Ogre::Radian heading);

		//! get the Player height
		Ogre::Real getPlayerHeight() const; 

		protected:
		//! show joint visual debugging data
		/*! 
			implement its own version of visual debugging
		*/
		virtual void showDebugData(Ogre::SceneNode* debugRootNode);


		struct DebugInfo 
		{
			void* m_playershape;
			Ogre::SceneNode* m_node;
			Ogre::ManualObject* m_visualDebug;
		};
		std::vector<DebugInfo> m_debugInfo;

	};

}   // end NAMESPACE OgreNewt


#endif  // _INCLUDE_OGRENEWT_PLAYERCONTROLLER

