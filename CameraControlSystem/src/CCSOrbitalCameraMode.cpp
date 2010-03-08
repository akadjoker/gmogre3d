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

#include "CCSOrbitalCameraMode.h"

bool CCS::OrbitalCameraMode::init()
{
	ChaseFreeYawAxisCameraMode::init();

    mCameraCS->setFixedYawAxis(false);
    mCameraCS->setAutoTrackingTarget(false);

    mRotHorizontal = mInitialRotHorizontal;
    mRotVertical = mInitialRotVertical;
    mZoom = mInitialZoom;

    return true;
}

void CCS::OrbitalCameraMode::update(const Ogre::Real &timeSinceLastFrame)
{
	ChaseFreeYawAxisCameraMode::update(timeSinceLastFrame);

	mRotVertical += mRotVerticalDisplacement * timeSinceLastFrame * mRotationFactor;
	mRotHorizontal += mRotHorizontalDisplacement * timeSinceLastFrame * mRotationFactor;
	mZoom += mZoomDisplacement * timeSinceLastFrame * mZoomFactor;

	Ogre::Quaternion offsetVertical(mRotVertical,Ogre::Vector3::UNIT_X);
    Ogre::Quaternion offsetHorizontal(mRotHorizontal,Ogre::Vector3::UNIT_Y);

	mCameraOrientation = mCameraOrientation * offsetHorizontal * offsetVertical;
	mCameraPosition += mCameraOrientation * Ogre::Vector3(0,0,mZoom);

	mRotVerticalDisplacement = 0;
	mRotHorizontalDisplacement = 0;
	mZoomDisplacement = 0;

	if(mCollisionsEnabled)
	{
		mCameraPosition = collisionDelegate(mCameraCS->getCameraTargetPosition(), mCameraPosition);
	}
}
