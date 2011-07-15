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

#include "CCSCameraControlSystem.h"

namespace CCS
{
	CameraControlSystem::CameraControlSystem(Ogre::SceneManager* sm, Ogre::String name, Ogre::Camera* camera
		, bool recalculateOnTargetMoving)
		: mSceneMgr(sm)
        , mName(name)
        , mTargetNode(NULL)
		, mTargetNodeListener(NULL)
		, mRecalculateOnTargetMoving(recalculateOnTargetMoving)
		, mCurrentCameraMode(NULL)
		
	{
        mCameraNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (mName+"SceneNode");

        // Create our camera if it wasn't passed as a parameter
	    if (camera == NULL)
		{
		    mCamera = mSceneMgr->createCamera (mName);
		    mOwnCamera = true;
	    }
	    else 
        {
		    mCamera = camera;
		    mOwnCamera = false;
	    }

        // reset to default parameters
        mCamera->setPosition(Ogre::Vector3::ZERO);
        mCamera->setOrientation(Ogre::Quaternion::IDENTITY);

	    // ... and attach the Ogre camera to the camera node
	    mCameraNode->attachObject (mCamera);
	}

	CameraControlSystem::CameraControlSystem(Ogre::SceneManager* sm, Ogre::String name, Ogre::SceneNode* customCameraSceneNode
		, bool recalculateOnTargetMoving)
		: mSceneMgr(sm)
        , mName(name)
        , mTargetNode(NULL)
		, mTargetNodeListener(NULL)
		, mRecalculateOnTargetMoving(recalculateOnTargetMoving)
		, mCurrentCameraMode(NULL)
	{
        mCameraNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (mName+"SceneNode");
		mOwnCamera = false;	    
	    mCameraNode->addChild(customCameraSceneNode);
	}

	CameraControlSystem::~CameraControlSystem()
	{
		if(mTargetNode && mTargetNode->getListener())
		{
			delete mTargetNode->getListener();
			mTargetNode->setListener(NULL);
		}

		mCameraNode->setAutoTracking(false);
		mCameraNode->removeAllChildren();
	    mCameraNode->detachAllObjects();
	    if (mOwnCamera)
	    	mSceneMgr->destroyCamera(mCamera);
	    mSceneMgr->destroySceneNode (mCameraNode);
	}

	void CameraControlSystem::deleteAllCameraModes()
	{
		std::map<Ogre::String, CameraMode*>::const_iterator it;
        for(it = mCameraModes.begin(); it != mCameraModes.end(); ++it)
        {
            delete (*it).second;
        }
        mCameraModes.clear();
        mCurrentCameraMode = NULL;
	}

	void CameraControlSystem::update(const Ogre::Real& timeSinceLastFrame)
	{
		mTimeSinceLastFrameLastUpdate = timeSinceLastFrame;

		if(mCurrentCameraMode)
        {
            mCurrentCameraMode->update(timeSinceLastFrame);
            mCameraNode->setPosition(mCurrentCameraMode->getCameraPosition());
            mCameraNode->setOrientation(mCurrentCameraMode->getCameraOrientation());
        }
	}

	void CameraControlSystem::setCameraTarget(Ogre::SceneNode* targetNode)
	{		
		if(mTargetNode && mTargetNode->getListener())
		{
			delete mTargetNode->getListener();
			mTargetNode->setListener(NULL);
		}

		if(mCurrentCameraMode)
        {
            mCurrentCameraMode->stop();
        }

        mTargetNode = targetNode;

		if(mCurrentCameraMode)
        {
            mCurrentCameraMode->init();
        }

		if(mRecalculateOnTargetMoving && mTargetNode)
		{
			mTargetNodeListener = new NodeListener(this);
			mTargetNode->setListener(mTargetNodeListener);
		}
	}

    void CameraControlSystem::setCurrentCameraMode(CameraMode* cameraMode)
    {
        if(mCurrentCameraMode)
        {
            mCurrentCameraMode->stop();
        }
        mCurrentCameraMode = cameraMode;
        mCurrentCameraMode->init();
        mCameraNode->setPosition(mCurrentCameraMode->getCameraPosition());
        mCameraNode->setOrientation(mCurrentCameraMode->getCameraOrientation());
    }
	
    CameraControlSystem::CameraMode* CameraControlSystem::getCameraMode(Ogre::String name)
    {
        if(mCameraModes.find(name) != mCameraModes.end())
        {
            return mCameraModes[name]; 
        }
        return NULL;
    }

    Ogre::String CameraControlSystem::getCameraModeName(CameraControlSystem::CameraMode* camMode)
    {
        std::map<Ogre::String, CameraMode*>::const_iterator it;
        for(it = mCameraModes.begin(); it != mCameraModes.end(); ++it)
        {
            if((*it).second == camMode)
            {
                return (*it).first;
            }
        }

        return "";
    }

    CameraControlSystem::CameraMode* CameraControlSystem::getNextCameraMode()
    {
        std::map<Ogre::String, CameraMode*>::const_iterator it;
        for(it = mCameraModes.begin(); it != mCameraModes.end(); ++it)
        {
            if(mCurrentCameraMode == (*it).second)
            {               
                it++;
                if(it != mCameraModes.end())
                {
                    return (*it).second;
                }
                else
                {
                    break;
                }
            }
        }

        it = mCameraModes.begin();
        return (*it).second;
    }

	void CameraControlSystem::setAutoTrackingTarget(bool autoTracking)
    {
        if(mTargetNode)
        {
            mCameraNode->setAutoTracking(autoTracking, mTargetNode);
        }
        else
        {
            mCameraNode->setAutoTracking(autoTracking);
        }
    }

	Ogre::Vector3 CameraControlSystem::CollidableCamera::DefaultCollisionDetectionFunction(Ogre::Vector3 cameraTargetPosition, Ogre::Vector3 cameraPosition)
	{
		Ogre::Vector3 finalCameraPosition (cameraPosition.x, cameraPosition.y, cameraPosition.z);

		Ogre::Vector3 origin = cameraTargetPosition;		
		Ogre::Vector3 direction = (cameraPosition - cameraTargetPosition);
		Ogre::Real maxDistance = direction.length();
		direction = direction.normalisedCopy();
		Ogre::RaySceneQuery *raySceneQuery = mCameraCS2->getSceneManager()->createRayQuery(Ogre::Ray(origin, direction));

		Ogre::RaySceneQueryResult &result = raySceneQuery->execute();
		Ogre::RaySceneQueryResult::iterator itr = result.begin();

		bool intersect = false;
        Ogre::Real minDistance = std::numeric_limits<Ogre::Real>::max();
		while (itr != result.end() /*&& !intersect*/)
		{
			if(itr->distance < maxDistance
                && itr->distance < minDistance // take the shorter
				&& itr->movable->getParentSceneNode() != mCameraCS2->getCameraSceneNode()
				&& itr->movable->getParentSceneNode() != mCameraCS2->getTargetSceneNode())
			{
                minDistance = itr->distance;
				intersect = true;
				if(itr->worldFragment)
				{
					finalCameraPosition = itr->worldFragment->singleIntersection;
				}
				else //if(itr->movable)
				{					
					finalCameraPosition = origin + (direction * itr->distance);
				}
			}
			itr++;
		}

		mCameraCS2->getSceneManager()->destroyQuery(raySceneQuery);

		return finalCameraPosition;
	}
}
