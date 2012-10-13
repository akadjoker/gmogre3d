/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2010 Robert Geiman
                   <robgeiman@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
--------------------------------------------------------------------------------
*/
#pragma once

#ifndef GM_API_H
#define GM_API_H

#if defined(OLD_GMAPI)
   #include <../GMAPI/GMAPI/GMAPI.h>
   #define GM_VARIABLE gm::GMVARIABLE
   #define GM_INSTANCE gm::GMINSTANCE
   #define GM_VALUE gm::CGMVariable
   #pragma comment(lib, "GMAPI.lib")
#elif defined(NEW_GMAPI)
   #include <../NewGMAPI/Include/GMAPI.hpp>
   #define GM_VARIABLE gm::Variable
   #define GM_INSTANCE gm::Instance
   #define GM_VALUE gm::Value
   #pragma comment(lib, "../lib/NewGMAPI.lib")
#endif

#include "OgreNewtBody.h"
#include "PerfTimer.h"

struct GMInstance
{
   GMInstance()
   {
      BodyAttached = false;
      GMInstanceAttached = false;
      mGMInstanceID = 0;
      mGMInstancePtr = NULL;
      mBody = NULL;

      pGlobalPosition = NULL;
      pGlobalOrientation = NULL;
	   pGlobalScale = NULL;

      iGlobalPositionIndex = 0;
      iGlobalOrientationIndex = 0;
      iGlobalScaleIndex = 0;
   }

   bool BodyAttached;
   bool GMInstanceAttached;
   bool GMPositionVariableAttached;
   bool GMOrientationVariableAttached;
   bool GMScaleVariableAttached;

   int mGMInstanceID;
   GM_INSTANCE *mGMInstancePtr;
   OgreNewtBody *mBody;

	GM_VARIABLE *pX;
	GM_VARIABLE *pY;
	GM_VARIABLE *pZ;
   GM_VARIABLE *pYaw;
	GM_VARIABLE *pPitch;
	GM_VARIABLE *pRoll;
	GM_VARIABLE *pScaleX;
	GM_VARIABLE *pScaleY;
	GM_VARIABLE *pScaleZ;

   // Global variables

   GM_VARIABLE *pGlobalPosition;
   GM_VARIABLE *pGlobalOrientation;
	GM_VARIABLE *pGlobalScale;

   Ogre::String sGlobalPosition;
   Ogre::String sGlobalOrientation;
   Ogre::String sGlobalScale;

   unsigned int iGlobalPositionIndex;
   unsigned int iGlobalOrientationIndex;
   unsigned int iGlobalScaleIndex;

	double mLastX;
	double mLastY;
	double mLastZ;
	double mLastYaw;
	double mLastPitch;
	double mLastRoll;
	double mLastScaleX;
	double mLastScaleY;
	double mLastScaleZ;
};

//extern gm::CGMAPI *mGMAPI;
extern GM_VARIABLE *mVectorX;
extern GM_VARIABLE *mVectorY;
extern GM_VARIABLE *mVectorZ;
extern GM_VARIABLE *mEulerYaw;
extern GM_VARIABLE *mEulerPitch;
extern GM_VARIABLE *mEulerRoll;
extern GM_VARIABLE *mMatrix00;
extern GM_VARIABLE *mMatrix01;
extern GM_VARIABLE *mMatrix02;
extern GM_VARIABLE *mMatrix03;
extern GM_VARIABLE *mMatrix10;
extern GM_VARIABLE *mMatrix11;
extern GM_VARIABLE *mMatrix12;
extern GM_VARIABLE *mMatrix13;
extern GM_VARIABLE *mMatrix20;
extern GM_VARIABLE *mMatrix21;
extern GM_VARIABLE *mMatrix22;
extern GM_VARIABLE *mMatrix23;
extern GM_VARIABLE *mMatrix30;
extern GM_VARIABLE *mMatrix31;
extern GM_VARIABLE *mMatrix32;
extern GM_VARIABLE *mMatrix33;
extern GM_VARIABLE *mElapsedFrameMS;
extern GM_VARIABLE *mArrayOne;
extern GM_VARIABLE *mArrayTwo;
extern int xsymbol;

extern CPerfTimer mPerfTimer;
extern double mLastFrameTime;

typedef std::map<Ogre::String, int> GlobalSymbolMap;
extern GlobalSymbolMap mGlobalSymbols;


void GM_event_perform_object(int obj, int type, int numb);
GM_VALUE GM_script_execute(int script_id);
GM_VALUE GM_script_execute(int script_id, GM_VALUE val1);
GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2);
GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3);
GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4);
GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5);
GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6);
GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6, GM_VALUE val7);
GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6, GM_VALUE val7, GM_VALUE val8);

BOOL InitializeGM(double function_address_ptr);
BOOL IsGMInitialized();
GM_INSTANCE *GetGMInstance(int id);

double GetGMRealValue(GM_VALUE &val);
double GetGMRealVariable(GM_VARIABLE &var);
void SetGMVariable(GM_VARIABLE &var, double val);
void SetGMVariable(GM_VARIABLE &var, std::string val);

void AcquireGMVectorGlobals();
void AcquireGMEulerGlobals();
void AcquireGMMatrixGlobals();
void AcquireGMElapsedMSGlobal();
void AcquireGMGlobalVariablePointer(GMInstance *gminst);
void AcquireGMLocalVariablePointers(GMInstance *gminst);
void SetGMVectorGlobals(Ogre::Vector3 vec);
Ogre::Vector3 RetrieveGMGlobalArray(GM_VARIABLE *pVariable, int index);
Ogre::Vector3 SetGMGlobalArray(GM_VARIABLE *pVariable, int index, Ogre::Vector3 vec);

#endif
