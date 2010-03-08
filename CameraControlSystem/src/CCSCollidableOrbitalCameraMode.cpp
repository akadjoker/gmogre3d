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

#include "CCSCollidableOrbitalCameraMode.h"

bool CCS::CollidableOrbitalCameraMode::init()
{
	OrbitalCameraMode::init();

	this->collisionDelegate = newCollisionDelegate(this
			, &CollidableOrbitalCameraMode::DefaultCollisionDetectionFunction);

    return true;
}

void CCS::CollidableOrbitalCameraMode::update(const Ogre::Real &timeSinceLastFrame)
{
	OrbitalCameraMode::update(timeSinceLastFrame);

	mCameraPosition = collisionDelegate(mCameraCS->getCameraTargetPosition(), mCameraPosition);
}

Ogre::Vector3 CCS::CollidableOrbitalCameraMode::DefaultCollisionDetectionFunction(Ogre::Vector3 cameraTargetPosition, Ogre::Vector3 cameraPosition)
{
	Ogre::Vector3 finalCameraPosition (cameraPosition.x, cameraPosition.y, cameraPosition.z);

	Ogre::RaySceneQuery *raySceneQuery = mCameraCS->getSceneManager()->createRayQuery(Ogre::Ray(cameraTargetPosition, cameraPosition));

	// Perform the scene query
	Ogre::RaySceneQueryResult &result = raySceneQuery->execute();
	Ogre::RaySceneQueryResult::iterator itr = result.begin();

	// Get the results, set the camera height
	if (itr != result.end() && itr->worldFragment)
	{
		finalCameraPosition = itr->worldFragment->singleIntersection;				
	}

	mCameraCS->getSceneManager()->destroyQuery(raySceneQuery);

	return finalCameraPosition;
}
