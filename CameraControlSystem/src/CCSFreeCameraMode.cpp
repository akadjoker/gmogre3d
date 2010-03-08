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

#include "CCSFreeCameraMode.h"

bool CCS::FreeCameraMode::init()
{
    mCameraCS->setFixedYawAxis(true,mFixedAxis);
    mCameraCS->setAutoTrackingTarget(false);

    mLongitudinalDisplacement = 0;
    mLateralDisplacement = 0;
    mVerticalDisplacement = 0;
    mStartingPosition = mCameraCS->getCameraPosition();
    
    mRotX = 0;
    mRotY = 0;

    instantUpdate();

    return true;
}

void CCS::FreeCameraMode::update(const Ogre::Real &timeSinceLastFrame)
{
    Ogre::Vector3 dirVector = mCameraCS->getOgreCamera()->getRealDirection();
    Ogre::Vector3 lateralVector = dirVector.crossProduct(mFixedAxis).normalisedCopy();
    Ogre::Vector3 upVector = -dirVector.crossProduct(lateralVector).normalisedCopy();

    Ogre::Vector3 displacement = ((dirVector * mLongitudinalDisplacement)
        + (upVector * mVerticalDisplacement)
        + (lateralVector * mLateralDisplacement)) * timeSinceLastFrame * mMoveFactor;

    mCameraPosition += displacement;

    Ogre::Quaternion offsetX(mRotY,Ogre::Vector3::UNIT_X);
    Ogre::Quaternion offsetY(mRotX,mFixedAxis);

	mCameraOrientation = offsetY * offsetX;

    mLongitudinalDisplacement = 0;
    mLateralDisplacement = 0;
    mVerticalDisplacement = 0;            
}
