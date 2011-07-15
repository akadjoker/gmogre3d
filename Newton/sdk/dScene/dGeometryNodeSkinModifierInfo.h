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

#ifndef _D_GEOMETRY_NODE_SKIN_MODIFIER_INFO_H_
#define _D_GEOMETRY_NODE_SKIN_MODIFIER_INFO_H_

#include "dNodeInfo.h"
#include "dGeometryNodeModifierInfo.h"

class dGeometryNodeSkinModifierInfo: public dGeometryNodeModifierInfo
{
	public:
	struct dBoneVertexWeightData
	{
		int m_vertexIndex;
		dFloat m_weight;
		dScene::dTreeNode* m_boneNode;
	};

	struct dBoneWeightIndex
	{
		int m_index[4];
	};


	NE_DEFINE_CLASS_NODE(dGeometryNodeSkinModifierInfo,dGeometryNodeModifierInfo)

	dGeometryNodeSkinModifierInfo();
	dGeometryNodeSkinModifierInfo(dScene* world);
	dGeometryNodeSkinModifierInfo(const dGeometryNodeSkinModifierInfo& me);
	virtual ~dGeometryNodeSkinModifierInfo(void);

//	virtual const dMatrix& GetPivotMatrix () const;
//	virtual void SetPivotMatrix (const dMatrix& matrix);
//	virtual void BakeTransform (const dMatrix& matrix);
//	virtual void CalculateOOBBGizmo (const dMatrix& matrix, dVector& p0, dVector& p1) const {};
//	virtual dFloat RayCast (const dVector& p0, const dVector& p1) const {return 1.0f;}

	virtual void SkinMesh(dScene::dTreeNode* myNode, dScene* world, dBoneVertexWeightData* skinData, int skinDataCount);  

	virtual void SerializeBinary (FILE* file) {};
	virtual TiXmlElement* Serialize (TiXmlElement* parentNode);
	virtual bool Deserialize (TiXmlElement* node, int revisionNumber);

	int m_boneCount;
	int m_vertexCount;
	dMatrix m_shapeBindMatrix;
	dVector* m_vertexWeights;
	dMatrix* m_boneBindingMatrix;
	dBoneWeightIndex* m_boneWeightIndex;
};





#endif