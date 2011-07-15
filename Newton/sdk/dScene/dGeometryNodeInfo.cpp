/////////////////////////////////////////////////////////////////////////////
// Name:        dGeometryNodeInfo.h
// Purpose:     
// Author:      Julio Jerez
// Modified by: 
// Created:     22/05/2010 08:02:08
// RCS-ID:      
// Copyright:   Copyright (c) <2010> <Newton Game Dynamics>
// License:     
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// 
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely
/////////////////////////////////////////////////////////////////////////////


#include "dPluginStdafx.h"
#include "dScene.h"
#include "dGeometryNodeInfo.h"
#include "dTextureNodeInfo.h"
#include "dMaterialNodeInfo.h"

NE_IMPLEMENT_CLASS_NODE(dGeometryNodeInfo);


dGeometryNodeInfo::dGeometryNodeInfo()
	:dNodeInfo (), m_matrix (GetIdentityMatrix())
{
}

dGeometryNodeInfo::dGeometryNodeInfo(dScene* world)
	:dNodeInfo (), m_matrix (GetIdentityMatrix())
{
}


dGeometryNodeInfo::dGeometryNodeInfo(const dGeometryNodeInfo& me)
	:dNodeInfo (me), m_matrix (me.m_matrix)
{
}

dGeometryNodeInfo::~dGeometryNodeInfo(void)
{
}

const dMatrix& dGeometryNodeInfo::GetPivotMatrix () const
{
	return m_matrix;
}

void dGeometryNodeInfo::SetPivotMatrix (const dMatrix& matrix)
{
	m_matrix = matrix;
}


void dGeometryNodeInfo::BakeTransform (const dMatrix& transform)
{
	_ASSERTE (0);
/*
	dVector scale; 
	dMatrix stretchMatrix;

//	dMatrix matrix (m_matrix * transform);
//	matrix.PolarDecomposition (m_matrix, scale, stretchMatrix);
//	matrix = dMatrix (GetIdentityMatrix(), scale, stretchMatrix);
	dMatrix matrix (transform.Inverse4x4() * m_matrix * transform);
	matrix.PolarDecomposition (m_matrix, scale, stretchMatrix);
	matrix = dMatrix (GetIdentityMatrix(), scale, stretchMatrix) * transform;

	int pointCount = NewtonMeshGetPointCount (m_mesh); 
	int pointStride = NewtonMeshGetPointStrideInByte (m_mesh) / sizeof (dFloat);
	dFloat* const points = NewtonMeshGetPointArray (m_mesh); 
	matrix.TransformTriplex(points, pointStride * sizeof (dFloat), points, pointStride * sizeof (dFloat), pointCount);

	dMatrix rotation (matrix.Inverse4x4().Transpose() * matrix);
	rotation.m_posit = dVector (0.0f, 0.0f, 0.0f, 1.0f);
	rotation.TransformTriplex(&points[3], pointStride * sizeof (dFloat), &points[3], pointStride * sizeof (dFloat), pointCount);
//	for (int i = 0; i < pointCount; i ++) {
//		dVector n (points[i * pointStride + 3], points[i * pointStride + 3 + 4], points[i * pointStride + 3 + 5], 0.0f);
//		n = n.Scale (1.0f / dSqrt (n % n));
//		points[i * pointStride + 3 + 3] = n[0];
//		points[i * pointStride + 3 + 4] = n[1];
//		points[i * pointStride + 3 + 5] = n[2];
//	}

	int vertexCount = NewtonMeshGetVertexCount (m_mesh); 
	int vertexStride = NewtonMeshGetVertexStrideInByte (m_mesh) / sizeof (dFloat);
	dFloat* const vertex = NewtonMeshGetVertexArray (m_mesh); 
	matrix.TransformTriplex(vertex, vertexStride * sizeof (dFloat), vertex, vertexStride * sizeof (dFloat), vertexCount);
*/
}


