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

#ifdef OLD_GMAPI

#include "GM_API.h"

extern int mRotationMode;

extern Ogre::Vector3 ConvertFromGMAxis(double x, double y, double z);
extern Ogre::Vector3 ConvertToGMAxis(double x, double z, double y);
extern Ogre::Vector3 ConvertToGMAxis(const Ogre::Vector3 &vec);


gm::CGMAPI *mGMAPI = NULL;
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
   unsigned long result = 0;
   mGMAPI = gm::CGMAPI::Create( &result );

   return (mGMAPI != NULL);
}


BOOL IsGMInitialized()
{
   if (mGMAPI != 0)
      return TRUE;

   return FALSE;
}


GM_INSTANCE *GetGMInstance(int id)
{
   return mGMAPI->GetInstancePtr(id);
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
   GM_VALUE gm_args[1];

   gm_args[0] = val1;
   return gm::script_execute(script_id, gm_args, 1);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2)
{
   GM_VALUE gm_args[2];

   gm_args[0] = val1;
   gm_args[1] = val2;
   return gm::script_execute(script_id, gm_args, 2);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3)
{
   GM_VALUE gm_args[3];

   gm_args[0] = val1;
   gm_args[1] = val2;
   gm_args[2] = val3;

   return gm::script_execute(script_id, gm_args, 3);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4)
{
   GM_VALUE gm_args[4];

   gm_args[0] = val1;
   gm_args[1] = val2;
   gm_args[2] = val3;
   gm_args[3] = val4;

   return gm::script_execute(script_id, gm_args, 4);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5)
{
   GM_VALUE gm_args[5];

   gm_args[0] = val1;
   gm_args[1] = val2;
   gm_args[2] = val3;
   gm_args[3] = val4;
   gm_args[4] = val5;

   return gm::script_execute(script_id, gm_args, 5);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6)
{
   GM_VALUE gm_args[6];

   gm_args[0] = val1;
   gm_args[1] = val2;
   gm_args[2] = val3;
   gm_args[3] = val4;
   gm_args[4] = val5;
   gm_args[5] = val6;

   return gm::script_execute(script_id, gm_args, 6);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6, GM_VALUE val7)
{
   GM_VALUE gm_args[7];

   gm_args[0] = val1;
   gm_args[1] = val2;
   gm_args[2] = val3;
   gm_args[3] = val4;
   gm_args[4] = val5;
   gm_args[5] = val6;
   gm_args[6] = val7;

   return gm::script_execute(script_id, gm_args, 7);
}

GM_VALUE GM_script_execute(int script_id, GM_VALUE val1, GM_VALUE val2, GM_VALUE val3, GM_VALUE val4, GM_VALUE val5, GM_VALUE val6, GM_VALUE val7, GM_VALUE val8)
{
   GM_VALUE gm_args[8];

   gm_args[0] = val1;
   gm_args[1] = val2;
   gm_args[2] = val3;
   gm_args[3] = val4;
   gm_args[4] = val5;
   gm_args[5] = val6;
   gm_args[6] = val7;
   gm_args[7] = val8;

   return gm::script_execute(script_id, gm_args, 8);
}


void AcquireGMVectorGlobals()
{
   if (!IsGMInitialized())
      return;

   static int symbolVectorX = mGMAPI->GetSymbolID("vector_resx");
   static int symbolVectorY = mGMAPI->GetSymbolID("vector_resy");
   static int symbolVectorZ = mGMAPI->GetSymbolID("vector_resz");

   GM_VARIABLE* varArray = (GM_VARIABLE*) mGMAPI->GetGlobalVariableListPtr()->variables;
   int varCount = mGMAPI->GetGlobalVariableListPtr()->count;
   int acquiredCount = 0;
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].symbolId == symbolVectorX)
      {
         mVectorX = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolVectorY)
      {
         mVectorY = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolVectorZ)
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

   static int symbolEulerYaw = mGMAPI->GetSymbolID("euler_yaw");
   static int symbolEulerPitch = mGMAPI->GetSymbolID("euler_pitch");
   static int symbolEulerRoll = mGMAPI->GetSymbolID("euler_roll");

   GM_VARIABLE* varArray = (GM_VARIABLE*) mGMAPI->GetGlobalVariableListPtr()->variables;
   int varCount = mGMAPI->GetGlobalVariableListPtr()->count;
   int acquiredCount = 0;
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].symbolId == symbolEulerYaw)
      {
         mEulerYaw = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolEulerPitch)
      {
         mEulerPitch = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolEulerRoll)
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

   static int symbolMatrix00 = mGMAPI->GetSymbolID("matrix_00");
   static int symbolMatrix01 = mGMAPI->GetSymbolID("matrix_01");
   static int symbolMatrix02 = mGMAPI->GetSymbolID("matrix_02");
   static int symbolMatrix03 = mGMAPI->GetSymbolID("matrix_03");

   static int symbolMatrix10 = mGMAPI->GetSymbolID("matrix_10");
   static int symbolMatrix11 = mGMAPI->GetSymbolID("matrix_11");
   static int symbolMatrix12 = mGMAPI->GetSymbolID("matrix_12");
   static int symbolMatrix13 = mGMAPI->GetSymbolID("matrix_13");

   static int symbolMatrix20 = mGMAPI->GetSymbolID("matrix_20");
   static int symbolMatrix21 = mGMAPI->GetSymbolID("matrix_21");
   static int symbolMatrix22 = mGMAPI->GetSymbolID("matrix_22");
   static int symbolMatrix23 = mGMAPI->GetSymbolID("matrix_23");

   static int symbolMatrix30 = mGMAPI->GetSymbolID("matrix_30");
   static int symbolMatrix31 = mGMAPI->GetSymbolID("matrix_31");
   static int symbolMatrix32 = mGMAPI->GetSymbolID("matrix_32");
   static int symbolMatrix33 = mGMAPI->GetSymbolID("matrix_33");

   GM_VARIABLE* varArray = (GM_VARIABLE*) mGMAPI->GetGlobalVariableListPtr()->variables;
   int varCount = mGMAPI->GetGlobalVariableListPtr()->count;
   int acquiredCount = 0;
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].symbolId == symbolMatrix00)
      {
         mMatrix00 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix01)
      {
         mMatrix01 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix02)
      {
         mMatrix02 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix03)
      {
         mMatrix03 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix10)
      {
         mMatrix10 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix11)
      {
         mMatrix11 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix12)
      {
         mMatrix12 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix13)
      {
         mMatrix13 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix20)
      {
         mMatrix20 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix21)
      {
         mMatrix21 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix22)
      {
         mMatrix22 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix23)
      {
         mMatrix23 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix30)
      {
         mMatrix30 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix31)
      {
         mMatrix31 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix32)
      {
         mMatrix32 = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolMatrix33)
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

   static int symbolElampsedFrameMS = mGMAPI->GetSymbolID("elapsed_frame_ms");

   GM_VARIABLE* varArray = (GM_VARIABLE*) mGMAPI->GetGlobalVariableListPtr()->variables;
   int varCount = mGMAPI->GetGlobalVariableListPtr()->count;
      
   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].symbolId == symbolElampsedFrameMS)
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
         symbolPosition = mGMAPI->GetSymbolID(gminst->sGlobalPosition.c_str());
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
         symbolOrientation = mGMAPI->GetSymbolID(gminst->sGlobalOrientation.c_str());
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
         symbolScale = mGMAPI->GetSymbolID(gminst->sGlobalScale.c_str());
         mGlobalSymbols[gminst->sGlobalScale] = symbolScale;
      }
      else
         symbolScale = iter->second;
   }
   else
      acquiredCount++;

   GM_VARIABLE* varArray = (GM_VARIABLE*) mGMAPI->GetGlobalVariableListPtr()->variables;
   int varCount = mGMAPI->GetGlobalVariableListPtr()->count;

   for (int i = 0; i < varCount; i++)
   {
      if (varArray[i].symbolId == symbolPosition)
      {
         gminst->pGlobalPosition = (GM_VARIABLE*)(varArray + i);
         return;
      }
      else if (varArray[i].symbolId == symbolOrientation)
      {
         gminst->pGlobalOrientation = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolScale)
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
   static int symbolZ = mGMAPI->GetSymbolID("z");
   static int symbolYaw = mGMAPI->GetSymbolID("yaw");
   static int symbolPitch = mGMAPI->GetSymbolID("pitch");
   static int symbolRoll = mGMAPI->GetSymbolID("roll");
   static int symbolScaleX = mGMAPI->GetSymbolID("scalex");
   static int symbolScaleY = mGMAPI->GetSymbolID("scaley");
   static int symbolScaleZ = mGMAPI->GetSymbolID("scalez");

   GM_VARIABLE* varArray = gminst->mGMInstancePtr->variableListPtr->variables;
   int varCount = gminst->mGMInstancePtr->variableListPtr->count;
   int acquiredCount = 0;

   for ( int i = 0; i < varCount; i++ )
   {
      if (varArray[i].symbolId == symbolZ)
      {
         gminst->pZ = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolYaw)
      {
         gminst->pYaw = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolPitch)
      {
         gminst->pPitch = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolRoll)
      {
         gminst->pRoll = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolScaleX)
      {
         gminst->pScaleX = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolScaleY)
      {
         gminst->pScaleY = (GM_VARIABLE*)(varArray + i);
         acquiredCount++;
      }
      else if (varArray[i].symbolId == symbolScaleZ)
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
      *mVectorX = v.x;
      *mVectorY = v.y;
      *mVectorZ = v.z;
   }
}


Ogre::Vector3 RetrieveGMGlobalArray(GM_VARIABLE *pVariable, int index)
{
   Ogre::Vector3 vec;
   GM_VARIABLE &globalArray = *pVariable;

   if (index == 0)
      vec[0] = (Ogre::Real)globalArray;
   else
      vec[0] = (Ogre::Real)globalArray[0][index];
   vec[1] = (Ogre::Real)globalArray[1][index];
   vec[2] = (Ogre::Real)globalArray[2][index];

   return vec;
}


Ogre::Vector3 SetGMGlobalArray(GM_VARIABLE *pVariable, int index, Ogre::Vector3 vec)
{
   GM_VARIABLE &globalArray = *pVariable;

   if (index == 0)
      globalArray = vec[0];
   else
      globalArray[0][index] = vec[0];
   globalArray[1][index] = vec[1];
   globalArray[2][index] = vec[2];

   return vec;
}

double GetGMRealValue(GM_VALUE &val)
{
   return val.real();
}


double GetGMRealVariable(GM_VARIABLE &var)
{
   return var.real;
}


void SetGMVariable(GM_VARIABLE &var, double val)
{
   var = val;
}


void SetGMVariable(GM_VARIABLE &var, std::string val)
{
   var = val;
}

#endif
