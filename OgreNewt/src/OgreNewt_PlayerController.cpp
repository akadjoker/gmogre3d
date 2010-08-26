#include "OgreNewt_stdafx.h"
#include "OgreNewt_Body.h"
#include "OgreNewt_World.h"
#include "OgreNewt_Tools.h"
#include "OgreNewt_CollisionPrimitives.h"
#include "OgreNewt_PlayerController.h"
#include "CustomPlayerController.h"


namespace OgreNewt
{

	PlayerController::PlayerController(OgreNewt::Body * child, Ogre::Real stairHeight, Ogre::Real maxSlope, Ogre::Real kinematicCushion) 
		:Joint()
	{
		dMatrix globalFrame (GetIdentityMatrix());
		globalFrame.m_front = dVector (0.0f, 1.0f,  0.0f, 0.0f);        // up direction in global Space 
		globalFrame.m_up    = dVector (0.0f, 0.0f, -1.0f, 0.0f);        // ogre front dir is the -z direction
		globalFrame.m_right = globalFrame.m_front * globalFrame.m_up;  // strafing direction in global Space 

		// create a newton player controller
		CustomPlayerController* controller;
		controller = new CustomPlayerController (globalFrame, child->getNewtonBody(), stairHeight, kinematicCushion);
      controller->SetMaxSlope(Ogre::Degree(maxSlope).valueRadians());
		SetSupportJoint(controller);
	}

	PlayerController::~PlayerController()
	{

		for (std::vector<DebugInfo>::iterator it (m_debugInfo.begin()); it != m_debugInfo.end(); it++) {
			DebugInfo& info = (*it);

			if (info.m_node->getParent()) {
				info.m_node->getParent()->removeChild(info.m_node);
			}
			info.m_node->detachAllObjects();

	//		delete info.m_node;
			delete info.m_visualDebug;

			info.m_node = NULL;
			info.m_visualDebug = NULL;
		}
		m_debugInfo.clear();
	}

	void PlayerController::getVelocity(Ogre::Real& forwardSpeed, Ogre::Real& sideSpeed, Ogre::Radian& heading) const
	{
		dFloat dir;

		dir = 0.0f;
		sideSpeed = 0.0f;
		forwardSpeed = 0.0f;
		CustomPlayerController* joint = (CustomPlayerController*) m_joint;
		if (joint) {
			joint->GetVelocity (forwardSpeed, sideSpeed, dir);
		}

		heading = dir;
	}

	void PlayerController::setVelocity(Ogre::Real forwardSpeed, Ogre::Real sideSpeed, Ogre::Radian heading)
	{
		CustomPlayerController* joint = (CustomPlayerController*) m_joint;
		if (joint) {
			joint->SetVelocity (forwardSpeed, sideSpeed, heading.valueRadians());
		}
	}

	//! get the Paley height
	Ogre::Real PlayerController::getPlayerHeight() const
	{
		Ogre::Real height = 0.0f;
		CustomPlayerController* joint = (CustomPlayerController*) m_joint;
		if (joint) {
			height = joint->GetPlayerHeight();
		}
		return height;
	}

   void PlayerController::setStairHeight(Ogre::Real height)
   {
      CustomPlayerController* joint = (CustomPlayerController*) m_joint;
		if (joint) {
			joint->SetPlayerStairHeight(height);
		}
   }

   void PlayerController::setPlayerState(Ogre::uint32 state)
   {
      CustomPlayerController* joint = (CustomPlayerController*) m_joint;
		if (joint) {
         joint->SetPlayerState((CustomPlayerController::PlayerState)state);
		}
   }

   Ogre::uint32 PlayerController::getPlayerState()
   {
      CustomPlayerController* joint = (CustomPlayerController*) m_joint;
		if (joint) {
         return (Ogre::uint32)joint->GetPlayerState();
		}
      return 0;
   }

   void PlayerController::addImpulse(Ogre::Real xdelta, Ogre::Real ydelta, Ogre::Real zdelta, bool jump)
   {
      CustomPlayerController* joint = (CustomPlayerController*) m_joint;
		if (joint) {
         joint->AddImpulse(xdelta, ydelta, zdelta, jump);
		}
   }

	void PlayerController::showDebugData(Ogre::SceneNode* debugRootNode)
	{
		Body* playerBody = getBody0();
		CustomPlayerController* joint = (CustomPlayerController*) m_joint;

		Ogre::Vector3 pos;
		Ogre::Quaternion orient;

	//	playerBody->getPositionOrientation(pos, orient);
		playerBody->getVisualPositionOrientation (pos, orient);
		dMatrix matrix (dQuaternion (orient.w, orient.x, orient.y, orient.z), dVector (pos.x, pos.y, pos.z, 1.0f));

		if (!m_debugInfo.size()) {
			DebugInfo newInfo;
			std::ostringstream oss;
			Ogre::Vector3 pos;
			Ogre::Quaternion orient;

			OgreNewt::Debugger& debug(playerBody->getWorld()->getDebugger());

			oss << "__OgreNewt__Debugger__Lines__" << joint->GetSensorShape() << "__";
			newInfo.m_visualDebug = new Ogre::ManualObject(oss.str());
			newInfo.m_node = debugRootNode->createChildSceneNode();
			newInfo.m_playershape = (void*) joint->GetSensorShape();

			OgreNewt::Collision sensorCollision (joint->GetSensorShape(), playerBody->getWorld());
			debug.buildDebugObjectFromCollision(newInfo.m_visualDebug, Ogre::ColourValue(1, 0, 0, 1), sensorCollision);

			newInfo.m_node->attachObject(newInfo.m_visualDebug);

			// append this debug info to the array
			m_debugInfo.push_back(newInfo);


			oss << "__OgreNewt__Debugger__Lines__" << joint->GetStairStepShape() << "__";
			newInfo.m_visualDebug = new Ogre::ManualObject(oss.str());
			newInfo.m_node = debugRootNode->createChildSceneNode();
			newInfo.m_playershape = (void*) joint->GetSensorShape();

			OgreNewt::Collision stairCollision (joint->GetStairStepShape(), playerBody->getWorld());
			debug.buildDebugObjectFromCollision(newInfo.m_visualDebug, Ogre::ColourValue(1, 1, 0, 1), stairCollision);

			newInfo.m_node->attachObject(newInfo.m_visualDebug);

			// append this debug info to the array
			m_debugInfo.push_back(newInfo);
		}


		DebugInfo& shapeInfo = m_debugInfo[0];
		shapeInfo.m_node->setPosition(pos);
		shapeInfo.m_node->setOrientation (orient);
		if (!shapeInfo.m_node->getParent()) {
			debugRootNode->addChild(shapeInfo.m_node);
		}

		pos.y += joint->GetPlayerStairHeight();
		DebugInfo& stairInfo = m_debugInfo[1];
		stairInfo.m_node->setPosition(pos);
		stairInfo.m_node->setOrientation (orient);
		if (!stairInfo.m_node->getParent()) {
			debugRootNode->addChild(stairInfo.m_node);
		}
	}

}   // end NAMESPACE OgreNewt

