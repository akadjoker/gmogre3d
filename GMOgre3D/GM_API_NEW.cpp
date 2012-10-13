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

#ifdef NEW_GMAPI

#include "GM_API.h"
#include "OgreStringConverter.h"

extern int mRotationMode;

extern Ogre::Vector3 ConvertFromGMAxis(double x, double y, double z);
extern Ogre::Vector3 ConvertToGMAxis(double x, double z, double y);
extern Ogre::Vector3 ConvertToGMAxis(const Ogre::Vector3 &vec);


BOOL mGMAPI_Initialized = FALSE;
GM_VARIABLE *mVectorX = NULL;
GM_VARIABLE *mVectorY = NULL;
GM_VARIABLE *mVectorZ = NULL;
GM_VARIABLE *mEulerYaw = NULL;
GM_VARIABLE *mEulerPitch = NULL;
GM_VARIABLE *mEulerRoll = NULL;
GM_VARIABLE *mMatrix00 = NULL;
GM_VARIABLE *mMatrix01 = NULL;
GM_VARIABLE *mMatrix02 = NULL;
GM_VARIABLE *mMatrix03 = NULL;
GM_VARIABLE *mMatrix10 = NULL;
GM_VARIABLE *mMatrix11 = NULL;
GM_VARIABLE *mMatrix12 = NULL;
GM_VARIABLE *mMatrix13 = NULL;
GM_VARIABLE *mMatrix20 = NULL;
GM_VARIABLE *mMatrix21 = NULL;
GM_VARIABLE *mMatrix22 = NULL;
GM_VARIABLE *mMatrix23 = NULL;
GM_VARIABLE *mMatrix30 = NULL;
GM_VARIABLE *mMatrix31 = NULL;
GM_VARIABLE *mMatrix32 = NULL;
GM_VARIABLE *mMatrix33 = NULL;
GM_VARIABLE *mElapsedFrameMS = NULL;
GM_VARIABLE *mArrayOne = NULL;
GM_VARIABLE *mArrayTwo = NULL;
int xsymbol = 0;

CPerfTimer mPerfTimer;
double mLastFrameTime;

GlobalSymbolMap mGlobalSymbols;

BOOL InitializeGM(double function_address_ptr)
{
   mGMAPI_Initialized = gm::init(function_address_ptr);

   return mGMAPI_Initialized;
}


BOOL IsGMInitialized()
{
   return mGMAPI_Initialized;
}


GM_INSTANCE *GetGMInstance(int id)
{
   return gm::getInstance(id);
}


void GM_event_perform_object(int obj, int type, int numb)
{
   gm::event_perform_object(obj, type, numb);
}

GM_VALUE GM_script_execute(int script_id)
{
   return gm::script_execute(script_id);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1)
{
   gm::Value args[] = {script_id, val1, gm::Value()};

   return gm::script_execute(2, args);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2)
{
   gm::Value args[] = {script_id, val1, val2, gm::Value()};

   return gm::script_execute(3, args);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3)
{
   gm::Value args[] = {script_id, val1, val2, val3, gm::Value()};

   return gm::script_execute(4, args);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4)
{
   gm::Value args[] = {script_id, val1, val2, val3, val4, gm::Value()};

   return gm::script_execute(5, args);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5)
{
   gm::Value args[] = {script_id, val1, val2, val3, val4, val5, gm::Value()};

   return gm::script_execute(6, args);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6)
{
   gm::Value args[] = {script_id, val1, val2, val3, val4, val5, val6, gm::Value()};

   return gm::script_execute(7, args);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6, GM_VALUE val7)
{
   gm::Value args[] = {script_id, val1, val2, val3, val4, val5, val6, val7, gm::Value()};

   return gm::script_execute(8, args);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6, GM_VALUE val7, GM_VALUE val8)
{
   gm::Value args[] = {script_id, val1, val2, val3, val4, val5, val6, val7, val8, gm::Value()};

   return gm::script_execute(9, args);
}


void AcquireGMVectorGlobals()
{
   if (!IsGMInitialized())
      return;

   static int symbolVectorX = gm::getVarId("vector_resx");
   static int symbolVectorY = gm::getVarId("vector_resy");
   static int symbolVectorZ = gm::getVarId("vector_resz");

   GM_VARIABLE* varArray = (GM_VARIABLE*) gm::userGlobals->getVars();
   int varCount = gm::userGlobals->getLen();
   int acquiredCount = 0;

   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].id == symbolVectorX)
      {
         mVectorX = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolVectorY)
      {
         mVectorY = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolVectorZ)
      {
         mVectorZ = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }

      if (acquiredCount >= 3)
         break;
   }
}

void AcquireGMEulerGlobals()
{
   if (!IsGMInitialized())
      return;

   static int symbolEulerYaw = gm::getVarId("euler_yaw");
   static int symbolEulerPitch = gm::getVarId("euler_pitch");
   static int symbolEulerRoll = gm::getVarId("euler_roll");

   GM_VARIABLE* varArray = (GM_VARIABLE*) gm::userGlobals->getVars();
   int varCount = gm::userGlobals->getLen();
   int acquiredCount = 0;
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].id == symbolEulerYaw)
      {
         mEulerYaw = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolEulerPitch)
      {
         mEulerPitch = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolEulerRoll)
      {
         mEulerRoll = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }

      if (acquiredCount >= 3)
         break;
   }
}

void AcquireGMMatrixGlobals()
{
   if (!IsGMInitialized())
      return;

   static int symbolMatrix00 = gm::getVarId("matrix_00");
   static int symbolMatrix01 = gm::getVarId("matrix_01");
   static int symbolMatrix02 = gm::getVarId("matrix_02");
   static int symbolMatrix03 = gm::getVarId("matrix_03");

   static int symbolMatrix10 = gm::getVarId("matrix_10");
   static int symbolMatrix11 = gm::getVarId("matrix_11");
   static int symbolMatrix12 = gm::getVarId("matrix_12");
   static int symbolMatrix13 = gm::getVarId("matrix_13");

   static int symbolMatrix20 = gm::getVarId("matrix_20");
   static int symbolMatrix21 = gm::getVarId("matrix_21");
   static int symbolMatrix22 = gm::getVarId("matrix_22");
   static int symbolMatrix23 = gm::getVarId("matrix_23");

   static int symbolMatrix30 = gm::getVarId("matrix_30");
   static int symbolMatrix31 = gm::getVarId("matrix_31");
   static int symbolMatrix32 = gm::getVarId("matrix_32");
   static int symbolMatrix33 = gm::getVarId("matrix_33");

   GM_VARIABLE* varArray = (GM_VARIABLE*) gm::userGlobals->getVars();
   int varCount = gm::userGlobals->getLen();
   int acquiredCount = 0;
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].id == symbolMatrix00)
      {
         mMatrix00 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix01)
      {
         mMatrix01 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix02)
      {
         mMatrix02 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix03)
      {
         mMatrix03 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix10)
      {
         mMatrix10 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix11)
      {
         mMatrix11 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix12)
      {
         mMatrix12 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix13)
      {
         mMatrix13 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix20)
      {
         mMatrix20 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix21)
      {
         mMatrix21 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix22)
      {
         mMatrix22 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix23)
      {
         mMatrix23 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix30)
      {
         mMatrix30 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix31)
      {
         mMatrix31 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix32)
      {
         mMatrix32 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolMatrix33)
      {
         mMatrix33 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }

      if (acquiredCount >= 16)
         break;
   }
}

void AcquireGMElapsedMSGlobal()
{
   if (!IsGMInitialized())
      return;

   static int symbolElampsedFrameMS = gm::getVarId("elapsed_frame_ms");

   GM_VARIABLE* varArray = (GM_VARIABLE*) gm::userGlobals->getVars();
   int varCount = gm::userGlobals->getLen();
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].id == symbolElampsedFrameMS)
      {
         mElapsedFrameMS = (GM_VARIABLE*)(varArray + i);
         break;
      }
   }
}

void AcquireGMGlobalVariablePointer(GMInstance *gminst)
{
   if (!IsGMInitialized())
      return;

   int symbolPosition = 0;
   int symbolOrientation = 0;
   int symbolScale = 0;

   gminst->pGlobalPosition = 0;
   gminst->pGlobalOrientation = 0;
   gminst->pGlobalScale = 0;

   int acquiredCount = 0;

   // Generate or find the symbol for this global variable
   if (gminst->GMPositionVariableAttached)
   {
      GlobalSymbolMap::iterator iter = mGlobalSymbols.find(gminst->sGlobalPosition);
      if (iter == mGlobalSymbols.end())
      {
         symbolPosition = gm::getVarId(gminst->sGlobalPosition.c_str());
         mGlobalSymbols[gminst->sGlobalPosition] = symbolPosition;
      }
      else
         symbolPosition = iter->second;
   }
   else
      acquiredCount++;

   if (gminst->GMOrientationVariableAttached)
   {
      GlobalSymbolMap::iterator iter = mGlobalSymbols.find(gminst->sGlobalOrientation);
      if (iter == mGlobalSymbols.end())
      {
         symbolOrientation = gm::getVarId(gminst->sGlobalOrientation.c_str());
         mGlobalSymbols[gminst->sGlobalOrientation] = symbolOrientation;
      }
      else
         symbolOrientation = iter->second;
   }
   else
      acquiredCount++;

   if (gminst->GMScaleVariableAttached)
   {
      GlobalSymbolMap::iterator iter = mGlobalSymbols.find(gminst->sGlobalScale);
      if (iter == mGlobalSymbols.end())
      {
         symbolScale = gm::getVarId(gminst->sGlobalScale.c_str());
         mGlobalSymbols[gminst->sGlobalScale] = symbolScale;
      }
      else
         symbolScale = iter->second;
   }
   else
      acquiredCount++;

   GM_VARIABLE* varArray = (GM_VARIABLE*) gm::userGlobals->getVars();
   int varCount = gm::userGlobals->getLen();

   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].id == symbolPosition)
      {
         gminst->pGlobalPosition = (GM_VARIABLE*)(varArray + i);
         return;
      }
      else if (varArray[i].id == symbolOrientation)
      {
         gminst->pGlobalOrientation = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolScale)
      {
         gminst->pGlobalScale = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }

      if (acquiredCount >= 3)
         break;
   }
}

void AcquireGMLocalVariablePointers(GMInstance *gminst)
{
   if (!IsGMInitialized())
      return;

   // This function acquires all needed local variables for a GM object.
   // We do it this way for two reasons:
   //   1) Previously acquired pointers are NOT guaranteed to be valid each frame
   //   2) Manually calling GetLocalVariablePtr for each variable is SLOW!
   static int symbolZ = gm::getVarId("z");
   static int symbolYaw = gm::getVarId("yaw");
   static int symbolPitch = gm::getVarId("pitch");
   static int symbolRoll = gm::getVarId("roll");
   static int symbolScaleX = gm::getVarId("scalex");
   static int symbolScaleY = gm::getVarId("scaley");
   static int symbolScaleZ = gm::getVarId("scalez");

   GM_VARIABLE* varArray = (GM_VARIABLE*) gminst->mGMInstancePtr->vars->getVars();
   int varCount = gminst->mGMInstancePtr->vars->getLen();
   int acquiredCount = 0;

   for ( int i = 0; i < varCount; i++ )
   {
      if (varArray[i].id == symbolZ)
      {
         gminst->pZ = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolYaw)
      {
         gminst->pYaw = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolPitch)
      {
         gminst->pPitch = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolRoll)
      {
         gminst->pRoll = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolScaleX)
      {
         gminst->pScaleX = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolScaleY)
      {
         gminst->pScaleY = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].id == symbolScaleZ)
      {
         gminst->pScaleZ = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }

      if (acquiredCount >= 7)
         break;
   }
}

void SetGMVectorGlobals(Ogre::Vector3 vec)
{
   Ogre::Vector3 v = ConvertToGMAxis(vec);

   AcquireGMVectorGlobals();
   if (mVectorX != NULL)
   {
      SetGMVariable(*mVectorX, v.x);
      SetGMVariable(*mVectorY, v.y);
      SetGMVariable(*mVectorZ, v.z);
   }
}


Ogre::Vector3 RetrieveGMGlobalArray(GM_VARIABLE *pVariable, int index)
{
   Ogre::Vector3 vec;
   GM_VARIABLE &globalArray = *pVariable;

   vec[0] = (Ogre::Real)GetGMRealValue(globalArray.getVal(0, index));
   vec[1] = (Ogre::Real)GetGMRealValue(globalArray.getVal(1, index));
   vec[2] = (Ogre::Real)GetGMRealValue(globalArray.getVal(2, index));

   return vec;
}


Ogre::Vector3 SetGMGlobalArray(GM_VARIABLE *pVariable, int index, Ogre::Vector3 vec)
{
   GM_VARIABLE &globalArray = *pVariable;

   globalArray.getValP(0, index)->setReal(vec[0]);
   globalArray.getValP(0, index)->setReal(vec[1]);
   globalArray.getValP(0, index)->setReal(vec[2]);

   return vec;
}

double GetGMRealValue(GM_VALUE &val)
{
   return val.getReal();
}


double GetGMRealVariable(GM_VARIABLE &var)
{
   return var.val.getReal();
}


void SetGMVariable(GM_VARIABLE &var, double val)
{
   var.val = val;
}


void SetGMVariable(GM_VARIABLE &var, std::string val)
{
   var.val = val;
}

#endif
