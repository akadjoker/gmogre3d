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

#ifndef GMOGRE_MESH_H
#define GMOGRE_MESH_H

#include "GMOgre3D.h"


static Ogre::String mesh_name;
static Ogre::String mesh_group_name;
static Ogre::Real mesh_reduction_method;
static Ogre::Real mesh_reduction_value;


GMFN double CreateMesh(char *mesh_name, char *group = const_cast<char*>(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str()))
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().createManual(mesh_name, group);

   if (mesh.isNull())
      return FALSE;

   return TRUE;
}


GMFN double LoadMesh1(char *mesh, char *group = const_cast<char*>(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME.c_str()))
{
   mesh_name = mesh;
   mesh_group_name = group;

   return TRUE;
}


GMFN double LoadMesh2(double vertex_buffer_usage = Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY, double index_buffer_usage = Ogre::HardwareBuffer::HBU_STATIC_WRITE_ONLY, double disable_vertex_buffer_shadow = false, double disable_index_buffer_shadow = false)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().load(mesh_name, mesh_group_name, static_cast<Ogre::HardwareBuffer::Usage>((int)vertex_buffer_usage), static_cast<Ogre::HardwareBuffer::Usage>((int)index_buffer_usage), (disable_vertex_buffer_shadow == 0), (disable_index_buffer_shadow == 0));

   if (mesh.isNull())
      return FALSE;

   return TRUE;
}


GMFN double SetMeshSkeletonName(char *mesh_name, char *skeleton)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName(mesh_name);

   if (mesh.isNull())
      return FALSE;
  
   mesh->setSkeletonName(skeleton);

   return TRUE;
}


GMFN double SuggestMeshTangentVectorSourceCoordSet(char *mesh_name, double target_semantic)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName(mesh_name);

   if (mesh.isNull())
      return FALSE;

   unsigned short source_coord_set;
   unsigned short index;

   mesh->suggestTangentVectorBuildParams(static_cast<Ogre::VertexElementSemantic>((int)target_semantic), source_coord_set, index);

   return (double)source_coord_set;
}


GMFN double SuggestMeshTangentVectorIndex(char *mesh_name, double target_semantic)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName(mesh_name);

   if (mesh.isNull())
      return FALSE;

   unsigned short source_coord_set;
   unsigned short index;

   mesh->suggestTangentVectorBuildParams(static_cast<Ogre::VertexElementSemantic>((int)target_semantic), source_coord_set, index);

   return (double)index;
}


GMFN double BuildMeshTangentVectors1(char *mesh)
{
   mesh_name = mesh;

   return TRUE;
}


GMFN double BuildMeshTangentVectors2(double target_semantic, double source_coord_set, double index, double split_mirrored, double split_rotated)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName(mesh_name);

   if (mesh.isNull())
      return FALSE;
  
   mesh->buildTangentVectors(static_cast<Ogre::VertexElementSemantic>((int)target_semantic), source_coord_set, index, (split_mirrored != 0), (split_rotated != 0));

   return TRUE;
}


GMFN double SetMeshLODStrategy(char *name, double strategy)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName(name);

   if (mesh.isNull())
      return FALSE;

   Ogre::LodStrategy *lod_strategy;

   if (strategy == 1)
      lod_strategy = Ogre::LodStrategyManager::getSingleton().getStrategy("PixelCount");
   else
      lod_strategy = Ogre::LodStrategyManager::getSingleton().getStrategy("Distance");

   mesh->setLodStrategy(lod_strategy);

   return TRUE;
}


GMFN double GenerateMeshLODLevels1(char *mesh, double reduction_method, double reduction_value)
{
   mesh_name = mesh;
   mesh_reduction_method = reduction_method;
   mesh_reduction_value = reduction_value;

   return TRUE;
}


GMFN double GenerateMeshLODLevels2(double lod_value1, double lod_value2, double lod_value3, double lod_value4, double lod_value5, double lod_value6, double lod_value7, double lod_value8, double lod_value9, double lod_value10)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName(mesh_name);

   if (mesh.isNull())
      return FALSE;

   Ogre::Mesh::LodValueList lod_list;
   if (lod_value1 > 0.0)
      lod_list.push_back(lod_value1);
   if (lod_value2 > 0.0)
      lod_list.push_back(lod_value2);
   if (lod_value3 > 0.0)
      lod_list.push_back(lod_value3);
   if (lod_value4 > 0.0)
      lod_list.push_back(lod_value4);
   if (lod_value5 > 0.0)
      lod_list.push_back(lod_value5);
   if (lod_value6 > 0.0)
      lod_list.push_back(lod_value6);
   if (lod_value7 > 0.0)
      lod_list.push_back(lod_value7);
   if (lod_value8 > 0.0)
      lod_list.push_back(lod_value8);
   if (lod_value9 > 0.0)
      lod_list.push_back(lod_value9);
   if (lod_value10 > 0.0)
      lod_list.push_back(lod_value10);

   mesh->generateLodLevels(lod_list, static_cast<Ogre::ProgressiveMesh::VertexReductionQuota>((int)mesh_reduction_method), mesh_reduction_value);

   return TRUE;
}


GMFN double CreateMeshManualLODLevel(char *mesh_name, double lod_distance, char *lod_mesh_name)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName(mesh_name);

   if (mesh.isNull())
      return FALSE;

   mesh->createManualLodLevel(lod_distance, lod_mesh_name);

   return TRUE;
}


GMFN double ExportMeshToFile(char *mesh_name, char *mesh_filename)
{
   Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName(mesh_name);

   if (mesh.isNull())
      return FALSE;

   Ogre::MeshSerializer ser;
   ser.exportMesh(mesh.getPointer(), mesh_filename);

   return TRUE;
}

#endif
