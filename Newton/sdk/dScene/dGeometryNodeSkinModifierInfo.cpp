/////////////////////////////////////////////////////////////////////////////
// Name:        dGeometryNodeSkinModifierInfo.h
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
#include "dMeshNodeInfo.h"
#include "dSceneNodeInfo.h"
#include "dGeometryNodeModifierInfo.h"
#include "dGeometryNodeSkinModifierInfo.h"

NE_IMPLEMENT_CLASS_NODE(dGeometryNodeSkinModifierInfo);

dGeometryNodeSkinModifierInfo::dGeometryNodeSkinModifierInfo()
	:dGeometryNodeModifierInfo (), 
	 m_boneCount(0),
	 m_vertexCount(0),
	 m_shapeBindMatrix(GetIdentityMatrix()), 
	 m_vertexWeights(NULL),
	 m_boneBindingMatrix(NULL),
	 m_boneWeightIndex(NULL)
{
	SetName ("Skin Modifier");
}

dGeometryNodeSkinModifierInfo::dGeometryNodeSkinModifierInfo(dScene* world)
	:dGeometryNodeModifierInfo (),
	 m_boneCount(0),
	 m_vertexCount(0),
	 m_shapeBindMatrix(GetIdentityMatrix()), 
	 m_vertexWeights(NULL),
	 m_boneBindingMatrix(NULL),
	 m_boneWeightIndex(NULL)
{
	SetName ("Skin Modifier");
}


dGeometryNodeSkinModifierInfo::dGeometryNodeSkinModifierInfo(const dGeometryNodeSkinModifierInfo& me)
	:dGeometryNodeModifierInfo (me),
	 m_boneCount(0),
	 m_vertexCount(0),
	 m_shapeBindMatrix(GetIdentityMatrix()), 
	 m_vertexWeights(NULL),
	 m_boneBindingMatrix(NULL),
	 m_boneWeightIndex(NULL)
{
	_ASSERTE (0);
	SetName ("Skin Modifier");
}

dGeometryNodeSkinModifierInfo::~dGeometryNodeSkinModifierInfo(void)
{
	if (m_vertexWeights) {
		delete[] m_vertexWeights;
	}
	if (m_boneBindingMatrix) {
		delete[] m_boneBindingMatrix;
	}
	if (m_boneWeightIndex) {
		delete[] m_boneWeightIndex;
	}
}


//void dGeometryNodeSkinModifierInfo::BakeTransform (const dMatrix& transform)
//{
//	_ASSERTE (0);
//}



void dGeometryNodeSkinModifierInfo::SkinMesh(dScene::dTreeNode* skinNode, dScene* scene, dBoneVertexWeightData* skinData, int skinDataCount)  
{
	_ASSERTE (scene->GetInfoFromNode(skinNode) == this);

	if (m_vertexWeights) {
		delete[] m_vertexWeights;
	}
	if (m_boneWeightIndex) {
		delete[] m_boneWeightIndex;
	}

	if (m_boneBindingMatrix) {
		delete[] m_boneBindingMatrix;
	}

	while (scene->GetFirstChild(skinNode)) {
		dScene::dTreeNode* bone = scene->GetNodeFromLink(scene->GetFirstChild(skinNode));
		_ASSERTE (bone);
		scene->RemoveReference (skinNode, bone);
	}

	dScene::dTreeNode* meshNode = scene->FindParentByType(skinNode, dMeshNodeInfo::GetRttiType());
	_ASSERTE (meshNode);

	dMeshNodeInfo* meshInfo = (dMeshNodeInfo*) scene->GetInfoFromNode (meshNode);
	NewtonMesh* mesh = meshInfo->GetMesh();

//	int vertexCount = NewtonMeshGetVertexCount(mesh);
	m_vertexCount = NewtonMeshGetVertexCount(mesh);

	m_vertexWeights = new dVector[m_vertexCount];
	m_boneWeightIndex = new dBoneWeightIndex[m_vertexCount];
	memset (m_vertexWeights, 0, m_vertexCount * sizeof (dVector));
	memset (m_boneWeightIndex, 0, m_vertexCount * sizeof (dBoneWeightIndex));

	int skinBoneCount = 0;
	dTree<int,dScene::dTreeNode*> boneMap;
	for (int i = 0; i < skinDataCount; i ++) {
		_ASSERTE (skinData[i].m_weight > 0.0f);
		dScene::dTreeNode* bone = skinData[i].m_boneNode;
		dTree<int,dScene::dTreeNode*>::dTreeNode* node = boneMap.Find(bone);
		if (!node){
			node = boneMap.Insert(skinBoneCount, bone);
			scene->AddReference(skinNode, bone);
			skinBoneCount ++;
		}

		int vertexIndex = skinData[i].m_vertexIndex;
		for (int j = 0; j < 4; j ++) {
			if (m_vertexWeights[vertexIndex][j] == 0.0f) {
				_ASSERTE (node && node->GetInfo() >= 0);
				m_vertexWeights[vertexIndex][j] = skinData[i].m_weight;
				m_boneWeightIndex[vertexIndex].m_index[j] = node->GetInfo();
				break;
			}
		}
	}

	m_boneCount = skinBoneCount;
	m_boneBindingMatrix = new dMatrix [skinBoneCount];

	dScene::dTreeNode* parentBone = scene->FindParentByType(meshNode, dSceneNodeInfo::GetRttiType());
	_ASSERTE (parentBone);
	dSceneNodeInfo* sceneNode = (dSceneNodeInfo*) scene->GetInfoFromNode(parentBone);
	m_shapeBindMatrix = meshInfo->m_matrix * sceneNode->GetTransform();
	int index = 0;
	for (void* boneLink = scene->GetFirstChild(skinNode); boneLink; boneLink = scene->GetNextChild(skinNode, boneLink)) {
		dScene::dTreeNode* boneNode = scene->GetNodeFromLink(boneLink);
		dSceneNodeInfo* sceneInfo = (dSceneNodeInfo*) scene->GetInfoFromNode(boneNode);
		dMatrix matrix (sceneInfo->GetTransform());
		m_boneBindingMatrix[index] = matrix.Inverse4x4();
		index ++;
	}
}

TiXmlElement* dGeometryNodeSkinModifierInfo::Serialize (TiXmlElement* parentNode)
{
	TiXmlElement* node = new TiXmlElement (GetClassName());
	parentNode->LinkEndChild(node);

	node->SetAttribute("name", GetName());

	TiXmlElement* vertexCount = new TiXmlElement ("vertexCount");
	node->LinkEndChild(vertexCount);
	vertexCount->SetAttribute("count", m_vertexCount);

	TiXmlElement* matrix = new TiXmlElement ("bindingMatrix");
	node->LinkEndChild(matrix);
	char matrixText[1024];
	dFloatArrayToString (&m_shapeBindMatrix[0][0], 16, matrixText, sizeof (matrixText));
	matrix->SetAttribute("float16", matrixText);

	int bufferSize = (m_boneCount * sizeof (dFloat) * 16 + m_vertexCount * sizeof (dFloat) * 4) * 7;
	char* buffer = new char[(m_boneCount * sizeof (dFloat) * 16 + m_vertexCount * sizeof (dFloat) * 4) * 7];

	TiXmlElement* bindMatrices = new TiXmlElement ("bonesBindMatrices");
	node->LinkEndChild(bindMatrices);

	dFloatArrayToString (&m_shapeBindMatrix[0][0], m_boneCount * 16, buffer, bufferSize);
	bindMatrices->SetAttribute("count", m_boneCount);
	bindMatrices->SetAttribute("float16", buffer);

	int weightCount = 0;
	for (int i = 0; i < m_vertexCount; i ++) {
		for (int j = 0; j < 4; j ++) {
			weightCount += (m_vertexWeights[i][j] > 0.0f) ? 1 : 0;
		}
	}

	int count = 0;
	dFloat* weights = new dFloat[weightCount];
	int* vertexIndex = new int[weightCount];
	int* boneIndex = new int[weightCount];
	for (int i = 0; i < m_vertexCount; i ++) {
		for (int j = 0; j < 4; j ++) {
			if (m_vertexWeights[i][j] > 0.0f) {
				weights[count] = m_vertexWeights[i][j];
				vertexIndex[count] = i;
				boneIndex[count] = m_boneWeightIndex[i].m_index[j];
				count++;
			}
		}
	}

	_ASSERTE (count == weightCount);

	TiXmlElement* vertexWeight = new TiXmlElement ("vertexWeights");
	node->LinkEndChild(vertexWeight);
	
	vertexWeight->SetAttribute("count", weightCount);

	TiXmlElement* vIndices = new TiXmlElement ("vertexIndices");
	vertexWeight->LinkEndChild(vIndices);
	dIntArrayToString (vertexIndex, weightCount, buffer, bufferSize);
	vIndices->SetAttribute("indices", buffer);

	TiXmlElement* bIndices = new TiXmlElement ("boneIndices");
	vertexWeight->LinkEndChild(bIndices);
	dIntArrayToString (boneIndex, weightCount, buffer, bufferSize);
	bIndices->SetAttribute("indices", buffer);

	TiXmlElement* vWeights = new TiXmlElement ("weights");
	vertexWeight->LinkEndChild(vWeights);
	dFloatArrayToString (weights, weightCount, buffer, bufferSize);
	vWeights->SetAttribute("floats", buffer);

	delete[] boneIndex;
	delete[] vertexIndex;
	delete[] weights;
	delete[] buffer;
	return node;
}

bool dGeometryNodeSkinModifierInfo::Deserialize (TiXmlElement* node, int revisionNumber)
{
	SetName (node->Attribute("name"));

	TiXmlElement* vertexCount = (TiXmlElement*) node->FirstChild ("vertexCount");
	vertexCount->Attribute("count", &m_vertexCount);

	TiXmlElement* matrixNode = (TiXmlElement*) node->FirstChild ("bindingMatrix");
	dStringToFloatArray (matrixNode->Attribute("float16"), &m_shapeBindMatrix[0][0], 16);

	TiXmlElement* bindMatrices = (TiXmlElement*) node->FirstChild ("bonesBindMatrices");
	bindMatrices->Attribute("count", &m_boneCount);

	m_boneBindingMatrix = new dMatrix[m_boneCount];
	dStringToFloatArray (bindMatrices->Attribute("float16"), &m_boneBindingMatrix[0][0][0], 16 * m_boneCount);

	int weightCount = 0; 
	TiXmlElement* vertexWeight = (TiXmlElement*) node->FirstChild ("vertexWeights");
	vertexWeight->Attribute("count", &weightCount);

	int* boneIndex = new int[weightCount];
	int* vertexIndex = new int[weightCount];
	dFloat* weights = new dFloat[weightCount];

	TiXmlElement* vIndices = (TiXmlElement*) vertexWeight->FirstChild ("vertexIndices");
	dStringToIntArray (vIndices->Attribute("indices"), vertexIndex, weightCount);

	TiXmlElement* bIndices = (TiXmlElement*) vertexWeight->FirstChild ("boneIndices");
	dStringToIntArray (bIndices->Attribute("indices"), boneIndex, weightCount);

	TiXmlElement* vWeights = (TiXmlElement*) vertexWeight->FirstChild ("weights");
	dStringToFloatArray (vWeights->Attribute("floats"), weights, weightCount);

	m_vertexWeights = new dVector[m_vertexCount];
	m_boneWeightIndex = new dBoneWeightIndex[m_vertexCount];
	memset (m_vertexWeights, 0, m_vertexCount * sizeof (dVector));
	memset (m_boneWeightIndex, 0, m_vertexCount * sizeof (dBoneWeightIndex));

	for (int i = 0; i < weightCount; i ++) {
		int index = vertexIndex[i];
		for (int j = 0; j < 4; j ++) {
			if (m_vertexWeights[index][j] == 0.0f) {
				m_vertexWeights[index][j] = weights[i];
				m_boneWeightIndex[index].m_index[j] = boneIndex[i];
				break;
			}
		}
	}

	delete[] boneIndex;
	delete[] vertexIndex;
	delete[] weights;
	return true;
}