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

#ifndef GMOGRE_GPU_PROGRAM_PARAMETERS_H
#define GMOGRE_GPU_PROGRAM_PARAMETERS_H

#include "GMOgre3D.h"


static Ogre::String sGPUProgramParameterName;
static float iGPUProgramParameterValues[128];
static unsigned int iTotalGPUProgramParameterValues = 0;


GMFN double FindGPUProgramParametersNamedConstantDefinition(double gpu_prog_params_ptr, char *name)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   return (gpu_prog_params->_findNamedConstantDefinition(name) != NULL);
}


GMFN double ClearGPUProgramParametersNamedAutoConstant(double gpu_prog_params_ptr, char *name)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   gpu_prog_params->clearNamedAutoConstant(name);

   return TRUE;
}


GMFN double EnableGPUProgramParametersIgnoreMissingParams(double gpu_prog_params_ptr, double enable)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   gpu_prog_params->setIgnoreMissingParams((enable != 0));

   return TRUE;
}


GMFN double SetGPUProgramParametersNamedConstantReal1(double gpu_prog_params_ptr, char *name)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   sGPUProgramParameterName = name;

   return TRUE;
}


GMFN double SetGPUProgramParametersNamedConstantReal2(double gpu_prog_params_ptr, double count, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   float vals[8];
   vals[0] = val1;
   vals[1] = val2;
   vals[2] = val3;
   vals[3] = val4;
   vals[4] = val5;
   vals[5] = val6;
   vals[6] = val7;
   vals[7] = val8;

   gpu_prog_params->setNamedConstant(sGPUProgramParameterName, (float*)&vals, (size_t)count);

   return TRUE;
}


GMFN double QueueSetGPUProgramParametersNamedConstantReal(double gpu_prog_params_ptr, double count, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   if (count <= 1 && iTotalGPUProgramParameterValues < 128)
   {
      iGPUProgramParameterValues[iTotalGPUProgramParameterValues] = val1;
      iTotalGPUProgramParameterValues++;
   }
   if (count <= 2 && iTotalGPUProgramParameterValues < 128)
   {
      iGPUProgramParameterValues[iTotalGPUProgramParameterValues] = val2;
      iTotalGPUProgramParameterValues++;
   }
   if (count <= 3 && iTotalGPUProgramParameterValues < 128)
   {
      iGPUProgramParameterValues[iTotalGPUProgramParameterValues] = val3;
      iTotalGPUProgramParameterValues++;
   }
   if (count <= 4 && iTotalGPUProgramParameterValues < 128)
   {
      iGPUProgramParameterValues[iTotalGPUProgramParameterValues] = val4;
      iTotalGPUProgramParameterValues++;
   }
   if (count <= 5 && iTotalGPUProgramParameterValues < 128)
   {
      iGPUProgramParameterValues[iTotalGPUProgramParameterValues] = val5;
      iTotalGPUProgramParameterValues++;
   }
   if (count <= 6 && iTotalGPUProgramParameterValues < 128)
   {
      iGPUProgramParameterValues[iTotalGPUProgramParameterValues] = val6;
      iTotalGPUProgramParameterValues++;
   }
   if (count <= 7 && iTotalGPUProgramParameterValues < 128)
   {
      iGPUProgramParameterValues[iTotalGPUProgramParameterValues] = val7;
      iTotalGPUProgramParameterValues++;
   }
   if (count <= 8 && iTotalGPUProgramParameterValues < 128)
   {
      iGPUProgramParameterValues[iTotalGPUProgramParameterValues] = val8;
      iTotalGPUProgramParameterValues++;
   }

   return TRUE;
}


GMFN double ExecuteSetGPUProgramParametersNamedConstantReal(double gpu_prog_params_ptr, char *name)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   sGPUProgramParameterName = name;

   gpu_prog_params->setNamedConstant(sGPUProgramParameterName, (float*)&iGPUProgramParameterValues, (size_t)iTotalGPUProgramParameterValues);

   iTotalGPUProgramParameterValues = 0;

   return TRUE;
}


GMFN double SetGPUProgramParametersNamedConstantInt1(double gpu_prog_params_ptr, char *name)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   sGPUProgramParameterName = name;

   return TRUE;
}


GMFN double SetGPUProgramParametersNamedConstantInt2(double gpu_prog_params_ptr, double count, double val1, double val2, double val3, double val4, double val5, double val6, double val7, double val8)
{
   Ogre::GpuProgramParameters *gpu_prog_params = ConvertFromGMPointer<Ogre::GpuProgramParameters *>(gpu_prog_params_ptr);

   if (gpu_prog_params == NULL)
      return FALSE;

   int vals[8];
   vals[0] = (int)val1;
   vals[1] = (int)val2;
   vals[2] = (int)val3;
   vals[3] = (int)val4;
   vals[4] = (int)val5;
   vals[5] = (int)val6;
   vals[6] = (int)val7;
   vals[7] = (int)val8;

   gpu_prog_params->setNamedConstant(sGPUProgramParameterName, (int*)&vals, (size_t)count);

   return TRUE;
}

#endif
