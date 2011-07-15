/////////////////////////////////////////////////////////////////////////////
// Name:        dBoneNodeInfo.h
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

#ifndef _D_BONE_NODE_H_
#define _D_BONE_NODE_H_


#include "dSceneNodeInfo.h"


class dBoneNodeInfo: public dSceneNodeInfo
{
	public:
	NE_DEFINE_CLASS_NODE(dBoneNodeInfo,dSceneNodeInfo)

	dBoneNodeInfo();
	dBoneNodeInfo(dScene* world) {}
	virtual ~dBoneNodeInfo(void);

//	virtual dMatrix GetTransform () const;
//	virtual void SetTransform (const dMatrix& matrix);
//	virtual dVector GetPosition () const;
//	virtual void SetPosition (const dVector& position);
//	virtual dVector GetEulers () const;
//	virtual void SetEulers (const dVector& angles);
//	virtual dVector GetScale () const;
//	virtual void SetScale (const dVector& scale);
//	virtual void BakeTransform (const dMatrix& transform);
//	virtual void UpdateOOBB (dGeometryNodeInfo* geomInfo);
//	virtual dFloat RayCast (const dVector& p0, const dVector& p1) const;

	// draw scene in wire frame mode
//	void DrawWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in solid wire frame mode
//	virtual void DrawSolidWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in Gouraud shaded normal textured mode 
//	virtual void DrawGouraudShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// Draw selection gizmo
//	virtual void DrawGizmo(dScene* world, dScene::dTreeNode* myNode, const dMatrix& coordinaSystem, const dVector& color, int* const workBuffer, int worlfBufferInBytes, dGizmoMode mode, dFloat size) const;


	protected:
	dFloat m_lengh;
//	void DrawOOBBGizmo (dScene* world, dScene::dTreeNode* myNode) const;


	virtual void SerializeBinary (FILE* file);
	virtual TiXmlElement* Serialize (TiXmlElement* parentNode); 
	virtual bool Deserialize (TiXmlElement* node, int revisionNumber);

};





#endif