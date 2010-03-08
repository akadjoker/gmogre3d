/* -------------------------------------------------------
Copyright (c) 2009 Alberto G. Salguero (agsh@ugr.es)

Permission is hereby granted, free of charge, to any
person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the
Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice
shall be included in all copies or substantial portions of
the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
------------------------------------------------------- */

#ifndef _BasicCameraModes_H_
#define _BasicCameraModes_H_

#include "CCSPrerequisites.h"

#include "CCSCameraControlSystem.h"

namespace CCS
{
	/**
	 * In this mode the camera position and orientation never change. 
	 */
    class DllExport FixedCameraMode : public CameraControlSystem::CameraMode 
	{
	public:

        FixedCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &fixedAxis = Ogre::Vector3::UNIT_Y) 
            : CameraControlSystem::CameraMode(cam)
			, mFixedAxis(fixedAxis)
            , mLastPosition(Ogre::Vector3::ZERO)
            , mLastOrientation(Ogre::Quaternion::IDENTITY)
            
        { };

        virtual ~FixedCameraMode(){};

        virtual bool init()
        {
            mCameraCS->setFixedYawAxis(true,mFixedAxis);
            mCameraCS->setAutoTrackingTarget(false);

            instantUpdate();

            return true;
        }

        virtual void update(const Ogre::Real &timeSinceLastFrame){};
        virtual void instantUpdate()
        {
            mCameraPosition = mLastPosition;
            mCameraOrientation = mLastOrientation;
        };

        // Specific methods

        inline virtual void setCameraPosition(Ogre::Vector3 pos)
        {
            mLastPosition = pos;
            mCameraPosition = pos;
        }

        inline virtual void setCameraOrientation(Ogre::Quaternion orient)
        {
            mLastOrientation = orient;
            mCameraOrientation = mLastOrientation;
        }

        inline virtual void setCameraOrientation(const Ogre::Radian roll, 
            const Ogre::Radian yaw, const Ogre::Radian pitch)
        {
            mLastOrientation = Ogre::Quaternion(roll,Ogre::Vector3::UNIT_Z) 
                            * Ogre::Quaternion(yaw,Ogre::Vector3::UNIT_Y)
                            * Ogre::Quaternion(pitch,Ogre::Vector3::UNIT_X);

            mCameraOrientation = mLastOrientation;
        }
		
    protected:
        Ogre::Vector3 mFixedAxis;
        Ogre::Vector3 mLastPosition;
        Ogre::Quaternion mLastOrientation;
	};

    //--------------------------------------------------------------------------------------------------------------------
	/**
	 * In this mode the camera position is fixed and the camera always 
	 * points to the target. 
	 */
    class DllExport FixedTrackingCameraMode : public FixedCameraMode 
	{
	public:

        FixedTrackingCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &fixedAxis = Ogre::Vector3::UNIT_Y) 
            : FixedCameraMode(cam,fixedAxis)
        { };

        virtual ~FixedTrackingCameraMode(){};

        virtual bool init()
        {
            mCameraCS->setFixedYawAxis(true,mFixedAxis);
            mCameraCS->setAutoTrackingTarget(true);

            instantUpdate();

            return true;
        }
		    
	};

    //--------------------------------------------------------------------------------------------------------------------
	/**
	 * In this mode the camera follows the target. The second parameter is the relative position
     * to the target. The orientation of the camera is fixed by a yaw axis (UNIT_Y by default). 
	 */
    class DllExport ChaseCameraMode : public CameraControlSystem::CameraModeWithTightness, public CameraControlSystem::CollidableCamera 
	{
	public:

        ChaseCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &relativePositionToCameraTarget
			, const Ogre::Vector3 &fixedAxis = Ogre::Vector3::UNIT_Y) 
            : CameraControlSystem::CameraModeWithTightness(cam)	
			, CameraControlSystem::CollidableCamera(cam)
            , mFixedAxis(fixedAxis)
			, mRelativePositionToCameraTarget(relativePositionToCameraTarget)
            
        {
            mTightness = 0.01;
        };

        virtual ~ChaseCameraMode(){};

        virtual bool init()
        {
            setFixedYawAxis(true, mFixedAxis);
            mCameraCS->setAutoTrackingTarget(true);

			this->collisionDelegate = newCollisionDelegate(this
				, &CollidableCamera::DefaultCollisionDetectionFunction);

            instantUpdate();

            return true;
        }

        virtual void update(const Ogre::Real &timeSinceLastFrame)
        {           
			if(mCameraCS->getTargetSceneNode())
			{
				Ogre::Vector3 cameraCurrentPosition = mCameraCS->getCameraPosition();
				Ogre::Vector3 cameraFinalPositionIfNoTightness = mCameraCS->getCameraTargetPosition() 
					+ mCameraCS->getCameraTargetOrientation() * mRelativePositionToCameraTarget;

				Ogre::Vector3 diff = (cameraFinalPositionIfNoTightness - cameraCurrentPosition) * mTightness;
				mCameraPosition += diff;

				if(mCollisionsEnabled)
				{
					mCameraPosition = collisionDelegate(mCameraCS->getCameraTargetPosition(), mCameraPosition);
				}
			}
        }

        virtual void instantUpdate()
        {
			if(mCameraCS->getTargetSceneNode())
			{
				mCameraPosition = mCameraCS->getCameraTargetPosition() 
					+ mCameraCS->getCameraTargetOrientation() * mRelativePositionToCameraTarget;

				if(mCollisionsEnabled)
				{
					mCameraPosition = collisionDelegate(mCameraCS->getCameraTargetPosition(), mCameraPosition);
				}
			}
        }

        // Specific methods

        inline virtual void setCameraRelativePosition(Ogre::Vector3 posRelativeToCameraTarget)
        {
            mRelativePositionToCameraTarget = posRelativeToCameraTarget;
            instantUpdate();
        }

        inline virtual void setFixedYawAxis(bool useFixedAxis, const Ogre::Vector3 &fixedAxis = Ogre::Vector3::ZERO)
        {
            mFixedAxis = mFixedAxis;
            mCameraCS->setFixedYawAxis(true,mFixedAxis);
        }
		
    protected:
        Ogre::Vector3 mFixedAxis;
        Ogre::Vector3 mRelativePositionToCameraTarget;
	};

    //--------------------------------------------------------------------------------------------------------------------
	/**
	 * This mode is similar to "Chase" camera mode but the camera orientation is not fixed by
     * a yaw axis. The camera orientation will be the same as the target.
	 */
    class DllExport ChaseFreeYawAxisCameraMode : public ChaseCameraMode 
	{
	public:

        ChaseFreeYawAxisCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &relativePositionToCameraTarget
            , Ogre::Quaternion rotation) 
            : ChaseCameraMode(cam, relativePositionToCameraTarget)
        {
            mRotationOffset = rotation;
        }

        ChaseFreeYawAxisCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &relativePositionToCameraTarget
			, const Ogre::Radian roll, const Ogre::Radian yaw, const Ogre::Radian pitch) 
            : ChaseCameraMode(cam, relativePositionToCameraTarget)
        {
            mRotationOffset = Ogre::Quaternion(roll,Ogre::Vector3::UNIT_Z) 
                            * Ogre::Quaternion(yaw,Ogre::Vector3::UNIT_Y)
                            * Ogre::Quaternion(pitch,Ogre::Vector3::UNIT_X);
        }

        virtual ~ChaseFreeYawAxisCameraMode(){};

        virtual bool init()
        {
            ChaseCameraMode::setFixedYawAxis(false);
            mCameraCS->setAutoTrackingTarget(false);

			this->collisionDelegate = newCollisionDelegate(this
				, &CollidableCamera::DefaultCollisionDetectionFunction);

            instantUpdate();

            return true;
        }

        virtual void update(const Ogre::Real &timeSinceLastFrame)
        {            
            // Update camera position
            ChaseCameraMode::update(timeSinceLastFrame);

            // Update camera orientation
            mCameraOrientation = mCameraCS->getCameraTargetOrientation() * mRotationOffset;
        }

        virtual void instantUpdate()
        {
			if(mCameraCS->getTargetSceneNode())
			{
				// Update camera position
				ChaseCameraMode::instantUpdate();

				// Update camera orientation
				mCameraOrientation = mCameraCS->getCameraTargetOrientation() * mRotationOffset;
			}
        }

        // Specific methods

        inline virtual void setCameraRelativePosition(Ogre::Vector3 posRelativeToCameraTarget
            , Ogre::Quaternion rotation)
        {
            mRelativePositionToCameraTarget = posRelativeToCameraTarget;

            mRotationOffset = rotation;

            instantUpdate();
        }

        inline virtual void setCameraRelativePosition(Ogre::Vector3 posRelativeToCameraTarget
            , const Ogre::Radian roll, const Ogre::Radian yaw, const Ogre::Radian pitch)
        {
            mRelativePositionToCameraTarget = posRelativeToCameraTarget;

            mRotationOffset = Ogre::Quaternion(roll,Ogre::Vector3::UNIT_Z) 
                            * Ogre::Quaternion(yaw,Ogre::Vector3::UNIT_Y)
                            * Ogre::Quaternion(pitch,Ogre::Vector3::UNIT_X);

            instantUpdate();
        }
		
    protected:
        Ogre::Quaternion mRotationOffset;
	};

    //--------------------------------------------------------------------------------------------------------------------
	/**
	 * In this mode the camera node is attached to the target node as a child.
	 */
    class DllExport AttachedCameraMode : public CameraControlSystem::CameraMode
	{
	public:

        AttachedCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &relativePositionToCameraTarget
            , Ogre::Quaternion rotation) 
            : CameraMode(cam)
            , mRotation(rotation)
            , mRelativePositionToCameraTarget(relativePositionToCameraTarget)
        { }

        AttachedCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &relativePositionToCameraTarget, 
            const Ogre::Radian roll, const Ogre::Radian yaw, const Ogre::Radian pitch) 
            : CameraMode(cam)
            , mRelativePositionToCameraTarget(relativePositionToCameraTarget)
        {
            mRotation = Ogre::Quaternion(roll,Ogre::Vector3::UNIT_Z) 
                * Ogre::Quaternion(yaw,Ogre::Vector3::UNIT_Y)
                * Ogre::Quaternion(pitch,Ogre::Vector3::UNIT_X);
        }

        virtual ~AttachedCameraMode(){};

        virtual bool init()
        {
            mCameraCS->setFixedYawAxis(false);
            mCameraCS->setAutoTrackingTarget(false);

            mCameraPreviousParentSceneNode = mCameraCS->getCameraSceneNode()->getParent();
            mCameraPreviousParentSceneNode->removeChild(mCameraCS->getCameraSceneNode());
            mCameraCS->getTargetSceneNode()->addChild(mCameraCS->getCameraSceneNode());
            
            mCameraPosition = mRelativePositionToCameraTarget;
            
            mCameraOrientation = mRotation;

            instantUpdate();

            return true;
        }

        virtual void stop()
        {
            mCameraCS->getCameraSceneNode()->getParent()->removeChild(mCameraCS->getCameraSceneNode());
            mCameraPreviousParentSceneNode->addChild(mCameraCS->getCameraSceneNode());
        }

        virtual void update(const Ogre::Real &timeSinceLastFrame) { }
        virtual void instantUpdate() { }

    protected:
        Ogre::Quaternion mRotation;
        Ogre::Vector3 mRelativePositionToCameraTarget;
        Ogre::Node* mCameraPreviousParentSceneNode; 

	};

	//--------------------------------------------------------------------------------------------------------------------
	/**
	 * This is basically an attached camera mode with the posibility of hide 
	 * or show the focus of the scene
	 */
    class DllExport FirstPersonCameraMode : public AttachedCameraMode
	{
	public:

        FirstPersonCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &relativePositionToCameraTarget
            , Ogre::Quaternion rotation)
			: AttachedCameraMode(cam, relativePositionToCameraTarget,rotation)
            , mCharacterVisible(true)
        { }

        FirstPersonCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &relativePositionToCameraTarget
            , const Ogre::Radian roll, const Ogre::Radian yaw, const Ogre::Radian pitch) 
			: AttachedCameraMode(cam, relativePositionToCameraTarget,roll,yaw,pitch)
            , mCharacterVisible(true)
        { }

        virtual ~FirstPersonCameraMode(){};

		virtual bool init()
        {
			AttachedCameraMode::init();

            mCameraCS->getTargetSceneNode()->setVisible(mCharacterVisible);
            
            return true;
        }

		virtual void stop()
        {
			AttachedCameraMode::stop();

            mCameraCS->getTargetSceneNode()->setVisible(true);
        }

		// Specific methods

        void setCharacterVisible(bool value)
        {            
            mCharacterVisible = value;
        }

	protected:
		bool mCharacterVisible;
	};

    //--------------------------------------------------------------------------------------------------------------------
	/**
	 * In this mode the camera is constrained to the limits of a plane. 
	 * The camera always points to the target, perpendicularly to the plane.
	 */
    class DllExport PlaneBindedCameraMode : public CameraControlSystem::CameraModeWithTightness 
	{
	public:

        PlaneBindedCameraMode(CameraControlSystem* cam, Ogre::Plane &plane, const Ogre::Vector3 &fixedAxis = Ogre::Vector3::UNIT_Y) 
            : CameraControlSystem::CameraModeWithTightness(cam)
			, mFixedAxis(fixedAxis)
			, mPlane(plane)
        {
            mTightness = 1;
        };

        virtual ~PlaneBindedCameraMode(){};

        virtual bool init()
        {
            mCameraCS->setFixedYawAxis(true,mFixedAxis);
            mCameraCS->setAutoTrackingTarget(true);

            instantUpdate();

            return true;
        }

        virtual void update(const Ogre::Real &timeSinceLastFrame)
        {
            Ogre::Real distance = mPlane.getDistance(mCameraCS->getCameraTargetPosition());

            Ogre::Vector3 cameraCurrentPosition = mCameraCS->getCameraPosition();
            Ogre::Vector3 cameraFinalPositionIfNoTightness = mCameraCS->getCameraTargetPosition() -
                mPlane.normal.normalisedCopy() * distance;

            Ogre::Vector3 diff = (cameraFinalPositionIfNoTightness - cameraCurrentPosition) * mTightness;
            mCameraPosition += diff;
        };

        virtual void instantUpdate()
        {
            Ogre::Real distance = mPlane.getDistance(mCameraCS->getCameraTargetPosition());
            mCameraPosition = mCameraCS->getCameraTargetPosition() - 
                mPlane.normal.normalisedCopy() * distance;
        };
		
    protected:
        Ogre::Vector3 mFixedAxis;
        Ogre::Plane mPlane;
	};

    //--------------------------------------------------------------------------------------------------------------------
	/**
	 * In this mode the camera points to a given position (the "focus") 
	 * throuh the target. The camera orientation is fixed by a yaw axis.
	 */
    class DllExport ThroughTargetCameraMode : public CameraControlSystem::CameraMode 
	{
	public:

        ThroughTargetCameraMode(CameraControlSystem* cam, Ogre::Real margin, bool inverse = false
            , Ogre::Vector3 focusPos = Ogre::Vector3::ZERO, const Ogre::Vector3 &fixedAxis = Ogre::Vector3::UNIT_Y) 
            : CameraControlSystem::CameraMode(cam)
			, mFixedAxis(fixedAxis)
			, mMargin(margin)
            , mInverse(inverse)
        { };

        virtual ~ThroughTargetCameraMode(){};

        virtual bool init()
        {
            mCameraCS->setFixedYawAxis(true,mFixedAxis);
            mCameraCS->setAutoTrackingTarget(true);

            instantUpdate();

            return true;
        }

        virtual void update(const Ogre::Real &timeSinceLastFrame)
        {
            instantUpdate();
        };

        virtual void instantUpdate()
        {
            if(mCameraCS->hasCameraTarget())
            {
                if(!mInverse)
                {
                    Ogre::Vector3 focusToTarget = mCameraCS->getCameraTargetPosition() - mFocusPos;
                    mCameraPosition = mCameraCS->getCameraTargetPosition() + 
                        focusToTarget.normalisedCopy() * mMargin;
                }
                else
                {
                    Ogre::Vector3 focusToTarget = mCameraCS->getCameraTargetPosition() - mFocusPos;
                    mCameraPosition = mFocusPos - 
                        focusToTarget.normalisedCopy() * mMargin;
                }
            }
        };

        // Specific methods

        inline virtual void setCameraFocusPosition(Ogre::Vector3 pos)
        { 
            mFocusPos = pos; 
            init();
        };
		
    protected:
        Ogre::Vector3 mFixedAxis;
        Ogre::Vector3 mFocusPos;
        Ogre::Real mMargin;
        bool mInverse;
	};

    //--------------------------------------------------------------------------------------------------------------------
	/**
	 * In this camera mode the position of the camera is chosen to be 
	 * the closest to the target of a given list. The camera orientation 
	 * is fixed by a yaw axis.
	 */
    class DllExport ClosestToTargetCameraMode : public FixedTrackingCameraMode 
	{
	public:

        ClosestToTargetCameraMode(CameraControlSystem* cam, Ogre::Real timeInterval = 1
            , const Ogre::Vector3 &fixedAxis = Ogre::Vector3::UNIT_Y) 
            : FixedTrackingCameraMode(cam, fixedAxis)
			, mTimeInterval(timeInterval)
            , mTime(timeInterval)
        { };

        virtual ~ClosestToTargetCameraMode(){};

        virtual void update(const Ogre::Real &timeSinceLastFrame)
        {
            instantUpdate();
            return;

            mTime -= timeSinceLastFrame;

            if(mTime < 0)
            {
                instantUpdate();
                mTime = mTimeInterval;
            }
        };

        virtual void instantUpdate()
        {
            if(mCameraCS->hasCameraTarget())
            {
                Ogre::Real minDistance = std::numeric_limits<float>::max();
                Ogre::Vector3 targetPosition = mCameraCS->getCameraTargetPosition();

                std::vector<Ogre::Vector3>::const_iterator it;
                std::vector<Ogre::Vector3>::const_iterator closest;
                for(it = mPositionsList.begin(); it != mPositionsList.end(); ++it)
                {
                    Ogre::Vector3 vector_i = ((Ogre::Vector3)(*it));
                    Ogre::Real distance = (vector_i - targetPosition).length();
                    if( distance < minDistance)
                    {
                        closest = it;
                        minDistance = distance;
                    }
                }

                mCameraPosition = (Ogre::Vector3)(*closest);
            }
        };

        // Specific methods

        inline virtual void addCameraPosition(Ogre::Vector3 &pos)
        { 
            mPositionsList.push_back(pos); 
            init();
        };
		
    protected:
        std::vector<Ogre::Vector3> mPositionsList;
        Ogre::Real mTimeInterval;
        Ogre::Real mTime;
        bool mInverse;
	};

    //--------------------------------------------------------------------------------------------------------------------
	/**
	 * In this mode the camera is controlled by the user. In this mode the 
	 * target is always seen from the same point of view.
	 */
    class DllExport FixedDirectionCameraMode : public CameraControlSystem::CameraModeWithTightness 
	{
	public:

        FixedDirectionCameraMode(CameraControlSystem* cam, const Ogre::Vector3 &direction, const Ogre::Real distance
			, const Ogre::Vector3 &fixedAxis = Ogre::Vector3::UNIT_Y) 
            : CameraControlSystem::CameraModeWithTightness(cam)
			, mFixedAxis(fixedAxis)
            , mDistance(distance)
			, mDirection(direction.normalisedCopy())            
        {
            mTightness = 1;
        };

        virtual ~FixedDirectionCameraMode(){};

        virtual bool init()
        {
            mCameraCS->setFixedYawAxis(true, mFixedAxis);
            mCameraCS->setAutoTrackingTarget(true);

            instantUpdate();

            return true;
        }

        virtual void update(const Ogre::Real &timeSinceLastFrame)
        {            
            Ogre::Vector3 cameraCurrentPosition = mCameraCS->getCameraPosition();
            Ogre::Vector3 cameraFinalPositionIfNoTightness = mCameraCS->getCameraTargetPosition() 
                - mDirection * mDistance;

            Ogre::Vector3 diff = (cameraFinalPositionIfNoTightness - cameraCurrentPosition) * mTightness;
            mCameraPosition += diff;
        }

        virtual void instantUpdate()
        {
            mCameraPosition = mCameraCS->getCameraTargetPosition() 
                - mDirection * mDistance;
        }

        // Specific methods

        inline virtual void setDirection(Ogre::Vector3 direction)
        {
            mDirection = direction.normalisedCopy();
            instantUpdate();
        }

        inline virtual void setDistance(Ogre::Real distance)
        {
            mDistance = distance;
            instantUpdate();
        }
		
    protected:
        Ogre::Vector3 mFixedAxis;
        Ogre::Real mDistance;
        Ogre::Vector3 mDirection;
	};
}

#endif
