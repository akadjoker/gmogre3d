/////////////////////////////////////////////////////////////////////////////
// Name:        dMeshNodeInfo.h
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
#include "dTextureNodeInfo.h"
#include "dMaterialNodeInfo.h"
#include "dMeshNodeInfo.h"

NE_IMPLEMENT_CLASS_NODE(dMeshNodeInfo);



dMeshNodeInfo::dMeshNodeInfo()
	:dGeometryNodeInfo (NULL), m_mesh (NULL)
{

}

dMeshNodeInfo::dMeshNodeInfo(dScene* world)
	:dGeometryNodeInfo (world), m_mesh (NewtonMeshCreate(world->GetNewtonWorld()))
{
}

dMeshNodeInfo::dMeshNodeInfo(NewtonMesh* mesh)
	:dGeometryNodeInfo (), m_mesh (mesh)
{
	SetName ("mesh");
}

dMeshNodeInfo::dMeshNodeInfo(const dMeshNodeInfo& me)
	:dGeometryNodeInfo (me), m_mesh (NewtonMeshCreateFromMesh(me.m_mesh))
{
}

dMeshNodeInfo::~dMeshNodeInfo(void)
{
	if(m_mesh) {
		NewtonMeshDestroy(m_mesh);
	}
}


void dMeshNodeInfo::BeginBuild ()
{
	NewtonMeshBeginFace(m_mesh);
}

void dMeshNodeInfo::AddPolygon (int pointsCount, const neMeshInfoFlatPoint* const points, int materialID)
{
	NewtonMeshAddFace(m_mesh, pointsCount, &points[0].m_x, sizeof (neMeshInfoFlatPoint), materialID);
}

void dMeshNodeInfo::EndBuild ()
{
	NewtonMeshEndFace(m_mesh);
}

void dMeshNodeInfo::ConvertToTriangles()
{
	NewtonMeshTriangulate (m_mesh);
}

void dMeshNodeInfo::ConvertToPolygons()
{
	NewtonMeshPolygonize(m_mesh);
}


void dMeshNodeInfo::BakeTransform (const dMatrix& transform)
{
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
}

void dMeshNodeInfo::BuildFromVertexListIndexList(int faceCount, const int* const faceIndexCount, const int* faceMaterialIndex, 
	const dFloat* const vertex, int vertexStrideInBytes, const int* vertexIndex,
	const dFloat* const normal, int normalStrideInBytes, const int* normalIndex,
	const dFloat* const uv0, int uv0StrideInBytes, const int* uv0Index,
	const dFloat* const uv1, int uv1StrideInBytes, const int* uv1Index)
{
	NewtonMeshBuildFromVertexListIndexList(m_mesh, faceCount, faceIndexCount, faceMaterialIndex, 
		vertex, vertexStrideInBytes, vertexIndex,normal, normalStrideInBytes, normalIndex,
		uv0, uv0StrideInBytes, uv0Index, uv1, uv1StrideInBytes, uv1Index);
}



TiXmlElement* dMeshNodeInfo::Serialize (TiXmlElement* parentNode)
{
	TiXmlElement* node = new TiXmlElement (GetClassName());
	parentNode->LinkEndChild(node);

	node->SetAttribute("name", GetName());

	TiXmlElement* matrix = new TiXmlElement ("pivotMatrix");
	node->LinkEndChild(matrix);

	char matrixText[1024];
	dFloatArrayToString (&m_matrix[0][0], 16, matrixText, sizeof (matrixText));
	matrix->SetAttribute("float16", matrixText);


	TiXmlElement* pointElement = new TiXmlElement ("points");
	node->LinkEndChild(pointElement);


	int pointCount = NewtonMeshGetPointCount (m_mesh); 
	int pointStride = NewtonMeshGetPointStrideInByte (m_mesh) / sizeof (dFloat);
	dFloat* const points = NewtonMeshGetPointArray (m_mesh); 

	char* buffer = new char[pointCount * sizeof (dFloat) * 3 * 12];
	dFloat* packVertex = new dFloat [pointCount * 3];

	// pack the vertex Array
	int* vertexIndexList = new int [pointCount];
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 3 + 0] = points[i * pointStride + 0];
		packVertex[i * 3 + 1] = points[i * pointStride + 1];
		packVertex[i * 3 + 2] = points[i * pointStride + 2];
	}
	int count = dPackVertexArray (packVertex, 3, 3 * sizeof (dFloat), pointCount, vertexIndexList);
	dFloatArrayToString (packVertex, count * 3, buffer, pointCount * sizeof (dFloat) * 3 * 12);
	
	TiXmlElement* position = new TiXmlElement ("position");
	pointElement->LinkEndChild(position);
	position->SetAttribute("float3", count);
	position->SetAttribute("floats", buffer);

	// pack the normal array
	int* normalIndexList = new int [pointCount];
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 3 + 0] = points[i * pointStride + 3];
		packVertex[i * 3 + 1] = points[i * pointStride + 4];
		packVertex[i * 3 + 2] = points[i * pointStride + 5];
	}
	count = dPackVertexArray (packVertex, 3, 3 * sizeof (dFloat), pointCount, normalIndexList);
	dFloatArrayToString (packVertex, count * 3, buffer, pointCount * sizeof (dFloat) * 3 * 12);

	TiXmlElement* normal = new TiXmlElement ("normal");
	pointElement->LinkEndChild(normal);
	normal->SetAttribute("float3", count);
	normal->SetAttribute("floats", buffer);


	// pack the uv0 array
	int* uv0IndexList = new int [pointCount];
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 3 + 0] = points[i * pointStride + 6];
		packVertex[i * 3 + 1] = points[i * pointStride + 7];
		packVertex[i * 3 + 2] = 0.0f;
	}
	count = dPackVertexArray (packVertex, 3, 3 * sizeof (dFloat), pointCount, uv0IndexList);

	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 2 + 0] = packVertex[i * 3 + 0];
		packVertex[i * 2 + 1] = packVertex[i * 3 + 1];
	}
	dFloatArrayToString (packVertex, count * 2, buffer, pointCount * sizeof (dFloat) * 3 * 12);

	TiXmlElement* uv0 = new TiXmlElement ("uv0");
	pointElement->LinkEndChild(uv0);
	uv0->SetAttribute("float2", count);
	uv0->SetAttribute("floats", buffer);


	// pack the uv1 array
	int* uv1IndexList = new int [pointCount];
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 3 + 0] = points[i * pointStride + 8];
		packVertex[i * 3 + 1] = points[i * pointStride + 9];
		packVertex[i * 3 + 2] = 0.0f;
	}
	count = dPackVertexArray (packVertex, 3, 3 * sizeof (dFloat), pointCount, uv1IndexList);

	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 2 + 0] = packVertex[i * 3 + 0];
		packVertex[i * 2 + 1] = packVertex[i * 3 + 1];
	}
	dFloatArrayToString (packVertex, count * 2, buffer, pointCount * sizeof (dFloat) * 3 * 12);

	TiXmlElement* uv1 = new TiXmlElement ("uv1");
	pointElement->LinkEndChild(uv1);
	uv1->SetAttribute("float2", count);
	uv1->SetAttribute("floats", buffer);

	// save the polygon array
	int faceCount = NewtonMeshGetTotalFaceCount (m_mesh); 
	int indexCount = NewtonMeshGetTotalIndexCount (m_mesh); 

	int* faceArray = new int [faceCount];
	int* indexArray = new int [indexCount];
	int* materialIndexArray = new int [faceCount];
	int* remapedIndexArray = new int [indexCount];

	NewtonMeshGetFaces (m_mesh, faceArray, materialIndexArray, indexArray); 

	// save the faces vertex Count
	dIntArrayToString (faceArray, faceCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
	TiXmlElement* polygons = new TiXmlElement ("polygons");
	node->LinkEndChild(polygons);
	polygons->SetAttribute("count", faceCount);
	polygons->SetAttribute("faceIndexCount", buffer);

	dIntArrayToString (materialIndexArray, faceCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
	TiXmlElement* faceMaterial = new TiXmlElement ("faceMaterial");
	polygons->LinkEndChild(faceMaterial);
	faceMaterial->SetAttribute("index", buffer);

	for (int i = 0; i < indexCount; i ++) {
		int index = indexArray[i];
		remapedIndexArray[i] = vertexIndexList[index];
	}
	dIntArrayToString (remapedIndexArray, indexCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
	TiXmlElement* positionIndex = new TiXmlElement ("position");
	polygons->LinkEndChild(positionIndex);
	positionIndex->SetAttribute("index", buffer);


	for (int i = 0; i < indexCount; i ++) {
		int index = indexArray[i];
		remapedIndexArray[i] = normalIndexList[index];
	}
	dIntArrayToString (remapedIndexArray, indexCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
	TiXmlElement* normalIndex = new TiXmlElement ("normal");
	polygons->LinkEndChild(normalIndex);
	normalIndex->SetAttribute("index", buffer);


	for (int i = 0; i < indexCount; i ++) {
		int index = indexArray[i];
		remapedIndexArray[i] = uv0IndexList[index];
	}
	dIntArrayToString (remapedIndexArray, indexCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
	TiXmlElement* uv0Index = new TiXmlElement ("uv0");
	polygons->LinkEndChild(uv0Index);
	uv0Index->SetAttribute("index", buffer);


	for (int i = 0; i < indexCount; i ++) {
		int index = indexArray[i];
		remapedIndexArray[i] = uv1IndexList[index];
	}
	dIntArrayToString (remapedIndexArray, indexCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
	TiXmlElement* uv1Index = new TiXmlElement ("uv1");
	polygons->LinkEndChild(uv1Index);
	uv1Index->SetAttribute("index", buffer);

	delete[] remapedIndexArray;
	delete[] faceArray;
	delete[] indexArray;
	delete[] materialIndexArray;
	delete[] uv1IndexList;
	delete[] uv0IndexList;
	delete[] normalIndexList;
	delete[] vertexIndexList;
	delete[] packVertex;
	delete[] buffer;

	return node;
}

bool dMeshNodeInfo::Deserialize (TiXmlElement* node, int revisionNumber) 
{
	SetName (node->Attribute("name"));

	TiXmlElement* matrixNode = (TiXmlElement*) node->FirstChild ("pivotMatrix");
	dStringToFloatArray (matrixNode->Attribute("float16"), &m_matrix[0][0], 16);

	// load all the vertexData
	TiXmlElement* pointElement = (TiXmlElement*) node->FirstChild ("points");

	int positionCount;
	float* positions;
	TiXmlElement* positionsElement = (TiXmlElement*) pointElement->FirstChild ("position");
	positionsElement->Attribute("float3", &positionCount);
	positions = new dFloat[3 * positionCount];
	dStringToFloatArray (positionsElement->Attribute("floats"), positions, 3 * positionCount);

	int normalCount;
	float* normals;
	TiXmlElement* normalsElement = (TiXmlElement*) pointElement->FirstChild ("normal");
	normalsElement->Attribute("float3", &normalCount);
	normals = new dFloat[3 * normalCount];
	dStringToFloatArray (normalsElement->Attribute("floats"), normals, 3 * normalCount);

	int uv0Count;
	float* uv0;
	TiXmlElement* uv0Element = (TiXmlElement*) pointElement->FirstChild ("uv0");
	uv0Element->Attribute("float2", &uv0Count);
	uv0 = new dFloat[2 * uv0Count];
	dStringToFloatArray (uv0Element->Attribute("floats"), uv0, 2 * uv0Count);

	int uv1Count;
	float* uv1;
	TiXmlElement* uv1Element = (TiXmlElement*) pointElement->FirstChild ("uv1");
	uv1Element->Attribute("float2", &uv1Count);
	uv1 = new dFloat[2 * uv1Count];
	dStringToFloatArray (uv1Element->Attribute("floats"), uv1, 2 * uv1Count);

	//load face informations
	TiXmlElement* polygonsElement = (TiXmlElement*) node->FirstChild ("polygons");

	int faceCount;
	polygonsElement->Attribute("count", &faceCount);
	int* faceIndexCount = new int[faceCount];
	dStringToIntArray (polygonsElement->Attribute("faceIndexCount"), faceIndexCount, faceCount);

	int* faceMaterials = new int [faceCount]; 
	TiXmlElement* materialElement = (TiXmlElement*) polygonsElement->FirstChild ("faceMaterial");
	dStringToIntArray (materialElement->Attribute("index"), faceMaterials, faceCount);

	int indexCount = 0;
	for (int i = 0; i < faceCount; i ++) {
		indexCount += faceIndexCount[i];
	}

	int* positionVertexIndex = new int [indexCount]; 
	TiXmlElement* positionVertexIndexElement = (TiXmlElement*) polygonsElement->FirstChild ("position");
	dStringToIntArray (positionVertexIndexElement->Attribute("index"), positionVertexIndex, indexCount);

	int* normalVertexIndex = new int [indexCount]; 
	TiXmlElement* normalVertexIndexElement = (TiXmlElement*) polygonsElement->FirstChild ("normal");
	dStringToIntArray (normalVertexIndexElement->Attribute("index"), normalVertexIndex, indexCount);

	int* uv0VertexIndex = new int [indexCount]; 
	TiXmlElement* uv0VertexIndexElement = (TiXmlElement*) polygonsElement->FirstChild ("uv0");
	dStringToIntArray (uv0VertexIndexElement->Attribute("index"), uv0VertexIndex, indexCount);

	int* uv1VertexIndex = new int [indexCount]; 
	TiXmlElement* uv1VertexIndexElement = (TiXmlElement*) polygonsElement->FirstChild ("uv1");
	dStringToIntArray (uv1VertexIndexElement->Attribute("index"), uv1VertexIndex, indexCount);

/*
	int indexAcc = 0;
	BeginBuild();
	for (int i = 0; i < faceCount; i ++) {
		neMeshInfoFlatPoint face[128];
		int vertexCount = faceIndexCount[i];
		int materialIndex = faceMaterials[i];
		for (int j = 0; j < vertexCount; j ++) {
			int index;

			index = positionVertexIndex[indexAcc];
			face[j].m_x = positions[index * 3 + 0];
			face[j].m_y = positions[index * 3 + 1];
			face[j].m_z = positions[index * 3 + 2];

			index = normalVertexIndex[indexAcc];
			face[j].m_nx = normals[index * 3 + 0];
			face[j].m_ny = normals[index * 3 + 1];
			face[j].m_nz = normals[index * 3 + 2];

			index = uv0VertexIndex[indexAcc];
			face[j].m_u0 = uv0[index * 2 + 0];
			face[j].m_v1 = uv0[index * 2 + 1];

			index = uv1VertexIndex[indexAcc];
			face[j].m_u1 = uv1[index * 2 + 0];
			face[j].m_v1 = uv1[index * 2 + 1];
			indexAcc ++;
		}
		AddPolygon (vertexCount, face, materialIndex);
	}
	EndBuild();
	ConvertToPolygons();
*/
	BuildFromVertexListIndexList(faceCount, faceIndexCount, faceMaterials, 
								&positions[0], 3 * sizeof (dFloat), positionVertexIndex,
								&normals[0], 3 * sizeof (dFloat), normalVertexIndex,
								&uv0[0], 2 * sizeof (dFloat), uv0VertexIndex,
								&uv0[0], 2 * sizeof (dFloat), uv0VertexIndex);


	delete uv1VertexIndex;
	delete uv0VertexIndex;
	delete normalVertexIndex;
	delete positionVertexIndex;
	delete faceMaterials;
	delete faceIndexCount;
	delete uv1;	
	delete uv0;	
	delete normals;	
	delete positions;	
	return true;
}


void dMeshNodeInfo::SerializeBinary (FILE* file) 
{
	fprintf (file, "%s\n%s\n", GetClassName(), GetName());

	fwrite (&m_matrix[0][0], 1, sizeof (dMatrix), file);

	int pointCount = NewtonMeshGetPointCount (m_mesh); 
	int pointStride = NewtonMeshGetPointStrideInByte (m_mesh) / sizeof (dFloat);
	dFloat* const points = NewtonMeshGetPointArray (m_mesh); 

	dFloat* packVertex = new dFloat [pointCount * 3];

	// pack the vertex Array
	int* vertexIndexList = new int [pointCount];
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 3 + 0] = points[i * pointStride + 0];
		packVertex[i * 3 + 1] = points[i * pointStride + 1];
		packVertex[i * 3 + 2] = points[i * pointStride + 2];
	}
	int count = dPackVertexArray (packVertex, 3, 3 * sizeof (dFloat), pointCount, vertexIndexList);
//	dFloatArrayToString (packVertex, count * 3, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* position = new TiXmlElement ("position");
//	pointElement->LinkEndChild(position);
//	position->SetAttribute("float3", count);
//	position->SetAttribute("floats", buffer);
	fwrite (&count, 1, sizeof (int), file);
	fwrite (&packVertex, count, 3 * sizeof (dFloat), file);

	// pack the normal array
	int* normalIndexList = new int [pointCount];
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 3 + 0] = points[i * pointStride + 3];
		packVertex[i * 3 + 1] = points[i * pointStride + 4];
		packVertex[i * 3 + 2] = points[i * pointStride + 5];
	}
	count = dPackVertexArray (packVertex, 3, 3 * sizeof (dFloat), pointCount, normalIndexList);
//	dFloatArrayToString (packVertex, count * 3, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* normal = new TiXmlElement ("normal");
//	pointElement->LinkEndChild(normal);
//	normal->SetAttribute("float3", count);
//	normal->SetAttribute("floats", buffer);
	fwrite (&count, 1, sizeof (int), file);
	fwrite (&packVertex, count, 3 * sizeof (dFloat), file);


	// pack the uv0 array
	int* uv0IndexList = new int [pointCount];
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 3 + 0] = points[i * pointStride + 6];
		packVertex[i * 3 + 1] = points[i * pointStride + 7];
		packVertex[i * 3 + 2] = 0.0f;
	}
	count = dPackVertexArray (packVertex, 3, 3 * sizeof (dFloat), pointCount, uv0IndexList);
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 2 + 0] = packVertex[i * 3 + 0];
		packVertex[i * 2 + 1] = packVertex[i * 3 + 1];
	}
//	dFloatArrayToString (packVertex, count * 2, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* uv0 = new TiXmlElement ("uv0");
//	pointElement->LinkEndChild(uv0);
//	uv0->SetAttribute("float2", count);
//	uv0->SetAttribute("floats", buffer);
	fwrite (&count, 1, sizeof (int), file);
	fwrite (&packVertex, count, 2 * sizeof (dFloat), file);


	// pack the uv1 array
	int* uv1IndexList = new int [pointCount];
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 3 + 0] = points[i * pointStride + 8];
		packVertex[i * 3 + 1] = points[i * pointStride + 9];
		packVertex[i * 3 + 2] = 0.0f;
	}
	count = dPackVertexArray (packVertex, 3, 3 * sizeof (dFloat), pointCount, uv1IndexList);
	for (int i = 0; i < pointCount; i ++) {
		packVertex[i * 2 + 0] = packVertex[i * 3 + 0];
		packVertex[i * 2 + 1] = packVertex[i * 3 + 1];
	}
//	dFloatArrayToString (packVertex, count * 2, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* uv1 = new TiXmlElement ("uv1");
//	pointElement->LinkEndChild(uv1);
//	uv1->SetAttribute("float2", count);
//	uv1->SetAttribute("floats", buffer);
	fwrite (&count, 1, sizeof (int), file);
	fwrite (&packVertex, count, 2 * sizeof (dFloat), file);


	// save the polygon array
	int faceCount = NewtonMeshGetTotalFaceCount (m_mesh); 
	int indexCount = NewtonMeshGetTotalIndexCount (m_mesh); 

	int* faceArray = new int [faceCount];
	int* indexArray = new int [indexCount];
	int* materialIndexArray = new int [faceCount];
	int* remapedIndexArray = new int [indexCount];

	NewtonMeshGetFaces (m_mesh, faceArray, materialIndexArray, indexArray); 

	// save the faces vertex Count
//	dIntArrayToString (faceArray, faceCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* polygons = new TiXmlElement ("polygons");
//	node->LinkEndChild(polygons);
//	polygons->SetAttribute("count", faceCount);
//	polygons->SetAttribute("faceIndexCount", buffer);
	fwrite (&faceCount, 1, sizeof (int), file);
	fwrite (faceArray, faceCount, sizeof (int), file);

//	dIntArrayToString (materialIndexArray, faceCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* faceMaterial = new TiXmlElement ("faceMaterial");
//	polygons->LinkEndChild(faceMaterial);
//	faceMaterial->SetAttribute("index", buffer);
	fwrite (materialIndexArray, faceCount, sizeof (int), file);

	for (int i = 0; i < indexCount; i ++) {
		int index = indexArray[i];
		remapedIndexArray[i] = vertexIndexList[index];
	}
//	dIntArrayToString (remapedIndexArray, indexCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* positionIndex = new TiXmlElement ("position");
//	polygons->LinkEndChild(positionIndex);
//	positionIndex->SetAttribute("index", buffer);
	fwrite (&indexCount, 1, sizeof (int), file);
	fwrite (remapedIndexArray, indexCount, sizeof (int), file);

	for (int i = 0; i < indexCount; i ++) {
		int index = indexArray[i];
		remapedIndexArray[i] = normalIndexList[index];
	}
//	dIntArrayToString (remapedIndexArray, indexCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* normalIndex = new TiXmlElement ("normal");
//	polygons->LinkEndChild(normalIndex);
//	normalIndex->SetAttribute("index", buffer);
	fwrite (&indexCount, 1, sizeof (int), file);
	fwrite (remapedIndexArray, indexCount, sizeof (int), file);

	for (int i = 0; i < indexCount; i ++) {
		int index = indexArray[i];
		remapedIndexArray[i] = uv0IndexList[index];
	}
//	dIntArrayToString (remapedIndexArray, indexCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* uv0Index = new TiXmlElement ("uv0");
//	polygons->LinkEndChild(uv0Index);
//	uv0Index->SetAttribute("index", buffer);
	fwrite (&indexCount, 1, sizeof (int), file);
	fwrite (remapedIndexArray, indexCount, sizeof (int), file);


	for (int i = 0; i < indexCount; i ++) {
		int index = indexArray[i];
		remapedIndexArray[i] = uv1IndexList[index];
	}
//	dIntArrayToString (remapedIndexArray, indexCount, buffer, pointCount * sizeof (dFloat) * 3 * 12);
//	TiXmlElement* uv1Index = new TiXmlElement ("uv1");
//	polygons->LinkEndChild(uv1Index);
//	uv1Index->SetAttribute("index", buffer);
	fwrite (&indexCount, 1, sizeof (int), file);
	fwrite (remapedIndexArray, indexCount, sizeof (int), file);


	delete[] remapedIndexArray;
	delete[] faceArray;
	delete[] indexArray;
	delete[] materialIndexArray;
	delete[] uv1IndexList;
	delete[] uv0IndexList;
	delete[] normalIndexList;
	delete[] vertexIndexList;
	delete[] packVertex;
}


void dMeshNodeInfo::DrawWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{
	_ASSERTE (world->GetInfoFromNode(myNode) == this);

#ifdef COMPILE_OPENGL
	int bufferSize = (worlfBufferInBytes / sizeof (int)) / 2;
	int* buffer0 = &workBuffer[0];
	int* buffer1 = &workBuffer[bufferSize];

	int* doubleBufferPtr[2];
	doubleBufferPtr[0] = buffer0;
	doubleBufferPtr[1] = buffer1;


//	int vertexCount = NewtonMeshGetVertexCount(m_mesh);
	int stride = NewtonMeshGetVertexStrideInByte(m_mesh);
	float* vertexList = NewtonMeshGetVertexArray(m_mesh);

	glPushMatrix();
	glMultMatrix(&m_matrix[0][0]);

	glEnableClientState (GL_VERTEX_ARRAY);
	glVertexPointer (3, GL_FLOAT, stride, vertexList);

	
	int pointCount = 0;
	int bufferIndex = 0;
	int* buffer = doubleBufferPtr[bufferIndex];
	for (void* edge = NewtonMeshGetFirstEdge (m_mesh); edge; edge = NewtonMeshGetNextEdge (m_mesh, edge)) {
		NewtonMeshGetEdgeIndices (m_mesh, edge, &buffer[pointCount], &buffer[pointCount + 1]);
		pointCount += 2;
		if ((pointCount + 2) >= bufferSize) {
			glColor3f (color.m_x, color.m_y, color.m_z);
			glDrawElements (GL_LINES, pointCount, GL_UNSIGNED_INT, buffer);

			bufferIndex = (bufferIndex + 1) & 1;
			buffer = doubleBufferPtr[bufferIndex];
			pointCount = 0;
		}
	}
	if (pointCount) {
		glColor3f (color.m_x, color.m_y, color.m_z);
		glDrawElements (GL_LINES, pointCount, GL_UNSIGNED_INT, buffer);
	}
	glDisableClientState(GL_VERTEX_ARRAY);	// disable vertex arrays
	glPopMatrix();
#endif
}


// draw scene in solid wire frame mode
void dMeshNodeInfo::DrawSolidWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{
	_ASSERTE (world->GetInfoFromNode(myNode) == this);

#ifdef COMPILE_OPENGL
	int bufferSize = (worlfBufferInBytes / sizeof (int)) / 2;
	int* buffer0 = &workBuffer[0];
	int* buffer1 = &workBuffer[bufferSize];

	int* doubleBufferPtr[2];
	doubleBufferPtr[0] = buffer0;
	doubleBufferPtr[1] = buffer1;

//	int vertexCount = NewtonMeshGetVertexCount(m_mesh);
	int stride = NewtonMeshGetVertexStrideInByte(m_mesh);
	float* vertexList = NewtonMeshGetVertexArray(m_mesh);

	glPushMatrix();
	glMultMatrix(&m_matrix[0][0]);

	glEnableClientState (GL_VERTEX_ARRAY);
	glVertexPointer (3, GL_FLOAT, stride, vertexList);

	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	int pointCount = 0;
	int bufferIndex = 0;
	int* buffer = doubleBufferPtr[bufferIndex];
	for (void* face = NewtonMeshGetFirstFace (m_mesh); face; face = NewtonMeshGetNextFace (m_mesh, face)) {
		if (!NewtonMeshIsFaceOpen (m_mesh, face)) {
			int vertexCount = NewtonMeshGetFaceIndexCount (m_mesh, face);
			if ((pointCount + 3 * (vertexCount - 2)) >= bufferSize) {
				glColor3f (0.5f, 0.5f, 0.5f);
				glDrawElements (GL_TRIANGLES, pointCount, GL_UNSIGNED_INT, buffer);
				bufferIndex = (bufferIndex + 1) & 1;
				buffer = doubleBufferPtr[bufferIndex];
				pointCount = 0;
			}
			int indices[1024];
			NewtonMeshGetFaceIndices (m_mesh, face, indices);

			for (int i = 2; i < vertexCount; i ++) {
				buffer[pointCount + 0] = indices[0];
				buffer[pointCount + 1] = indices[i - 1];
				buffer[pointCount + 2] = indices[i];
				pointCount += 3;
			}
		}
	}
	if (pointCount) {
		glColor3f (0.5f, 0.5f, 0.5f);
		glDrawElements (GL_TRIANGLES, pointCount, GL_UNSIGNED_INT, buffer);
	}
	glDisableClientState(GL_VERTEX_ARRAY);	// disable vertex arrays
	glPopMatrix();
#endif
}

// draw scene in Gouraud shaded normal textured mode 
void dMeshNodeInfo::DrawGouraudShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{
	_ASSERTE (world->GetInfoFromNode(myNode) == this);

#ifdef COMPILE_OPENGL
	int bufferSize = (worlfBufferInBytes / sizeof (int)) / 2;
	int* buffer0 = &workBuffer[0];
	int* buffer1 = &workBuffer[bufferSize];

	int* doubleBufferPtr[2];
	doubleBufferPtr[0] = buffer0;
	doubleBufferPtr[1] = buffer1;

//	int vertexCount = NewtonMeshGetPointCount(m_mesh);
	int stride = NewtonMeshGetPointStrideInByte(m_mesh);
	float* vertexList = NewtonMeshGetPointArray(m_mesh);


	glPushMatrix();
	glMultMatrix(&m_matrix[0][0]);

	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_NORMAL_ARRAY);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);

	glVertexPointer (3, GL_FLOAT, stride, &vertexList[0]);
	glNormalPointer (GL_FLOAT, stride, &vertexList[3]);
	glTexCoordPointer (2, GL_FLOAT, stride, &vertexList[6]);


	int pointCount = 0;
	int bufferIndex = 0;
	int* buffer = doubleBufferPtr[bufferIndex];

	for (void* ptr = world->GetFirstChild(myNode); ptr; ptr = world->GetNextChild(myNode, ptr)) {
		dScene::dTreeNode* materialNode = world->GetNodeFromLink (ptr);
		dNodeInfo* info = world->GetInfoFromNode(materialNode);
		if (info->IsType(dMaterialNodeInfo::GetRttiType())) {
			dMaterialNodeInfo* material = (dMaterialNodeInfo*) info;

			glMaterialfv(GL_FRONT, GL_SPECULAR, &material->GetSpecularColor().m_x);
			glMaterialfv(GL_FRONT, GL_AMBIENT, &material->GetAmbientColor().m_x);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, &material->GetDiffuseColor().m_x);
			glMaterialfv(GL_FRONT, GL_EMISSION, &material->GetEmissiveColor().m_x);
			glMaterialf(GL_FRONT, GL_SHININESS, material->GetShininess());

			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

			dTextureNodeInfo* diffuseTex = NULL;
			dScene::dTreeNode* diffTexNode = world->FindTextureByTextId (materialNode, material->GetDiffuseTextId());
			if (diffTexNode){
				diffuseTex = (dTextureNodeInfo*) world->GetInfoFromNode(diffTexNode);
			}

			if (diffuseTex && (diffuseTex->GetInternalId() != -1)) {
				glEnable(GL_TEXTURE_2D);		
				glBindTexture(GL_TEXTURE_2D, GLuint (diffuseTex->GetInternalId()));
			} else {
				glDisable(GL_TEXTURE_2D);
			}

			int id = material->GetId();
			for (void* face = NewtonMeshGetFirstFace (m_mesh); face; face = NewtonMeshGetNextFace (m_mesh, face)) {

				if (!NewtonMeshIsFaceOpen (m_mesh, face)) {
					int materialID = NewtonMeshGetFaceMaterial (m_mesh, face);	
					if (materialID == id) {
						int vertexCount = NewtonMeshGetFaceIndexCount (m_mesh, face);
						if ((pointCount + 3 * (vertexCount - 2)) >= bufferSize) {
							glDrawElements (GL_TRIANGLES, pointCount, GL_UNSIGNED_INT, buffer);
							bufferIndex = (bufferIndex + 1) & 1;
							buffer = doubleBufferPtr[bufferIndex];
							pointCount = 0;
						}
						int indices[1024];
						NewtonMeshGetFacePointIndices (m_mesh, face, indices);

						for (int i = 2; i < vertexCount; i ++) {
							buffer[pointCount + 0] = indices[0];
							buffer[pointCount + 1] = indices[i - 1];
							buffer[pointCount + 2] = indices[i];
							pointCount += 3;
						}
					}
				}
			}

			if (pointCount) {
				glDrawElements (GL_TRIANGLES, pointCount, GL_UNSIGNED_INT, buffer);
				bufferIndex = (bufferIndex + 1) & 1;
				buffer = doubleBufferPtr[bufferIndex];
				pointCount = 0;
			}
		}
	}

	glDisableClientState(GL_VERTEX_ARRAY);	// disable vertex arrays
	glDisableClientState(GL_NORMAL_ARRAY);	// disable normal arrays
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);	// disable normal arrays

	glPopMatrix();
#endif
}

void dMeshNodeInfo::CalculateOOBBGizmo (const dMatrix& matrix, dVector& p0, dVector& p1) const
{
	p0 = dVector ( 1.0e10f,  1.0e10f,  1.0e10f, 1.0f);
	p1 = dVector (-1.0e10f, -1.0e10f, -1.0e10f, 1.0f);

	dMatrix tranform (m_matrix * matrix) ;

	int stride = NewtonMeshGetVertexStrideInByte(m_mesh) / sizeof(dFloat);
	float* const vertexList = NewtonMeshGetVertexArray(m_mesh);

	for (void* vertex = NewtonMeshGetFirstVertex(m_mesh); vertex; vertex = NewtonMeshGetNextVertex(m_mesh, vertex)) {
		int index = NewtonMeshGetVertexIndex(m_mesh, vertex) * stride;

		dVector p (vertexList[index + 0], vertexList[index + 1],  vertexList[index + 2],  1.0);
		p = tranform.TransformVector(p);
		p0.m_x = min (p.m_x, p0.m_x);
		p0.m_y = min (p.m_y, p0.m_y);
		p0.m_z = min (p.m_z, p0.m_z);

		p1.m_x = max (p.m_x, p1.m_x);
		p1.m_y = max (p.m_y, p1.m_y);
		p1.m_z = max (p.m_z, p1.m_z);
	}
}

dFloat dMeshNodeInfo::RayCast (const dVector& p0, const dVector& p1) const
{
	dVector q0 (m_matrix.UntransformVector(p0));
	dVector q1 (m_matrix.UntransformVector(p1));

	//	int vertexCount = NewtonMeshGetVertexCount(m_mesh);
	int strideInBytes = NewtonMeshGetVertexStrideInByte(m_mesh);
	float* const vertexList = NewtonMeshGetVertexArray(m_mesh);
	dFloat t = 1.2f;
	for (void* face = NewtonMeshGetFirstFace (m_mesh); face; face = NewtonMeshGetNextFace (m_mesh, face)) {
		if (!NewtonMeshIsFaceOpen (m_mesh, face)) {
			int indices[1024];
			int vertexCount = NewtonMeshGetFaceIndexCount (m_mesh, face);
			NewtonMeshGetFaceIndices (m_mesh, face, indices);

			dFloat t1 = dPolygonRayCast (q0, q1, vertexCount, vertexList, strideInBytes, indices);
			if (t1 < t) {
				t = t1;		
			}
		}
	}
	return t;
}