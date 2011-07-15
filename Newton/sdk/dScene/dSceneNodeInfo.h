/////////////////////////////////////////////////////////////////////////////
// Name:        dSceneNodeInfo.h
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

#ifndef _D_SCENE_NODE_H_
#define _D_SCENE_NODE_H_

#include "dNodeInfo.h"

class dGeometryNodeInfo;

class dSceneNodeInfo: public dNodeInfo
{
	public:
	NE_DEFINE_CLASS_NODE(dSceneNodeInfo,dNodeInfo)

	dSceneNodeInfo();
	dSceneNodeInfo(dScene* world);
	virtual ~dSceneNodeInfo(void);

	virtual dMatrix GetTransform () const;
	virtual void SetTransform (const dMatrix& matrix);

	virtual dVector GetPosition () const;
	virtual void SetPosition (const dVector& position);

	virtual dVector GetEulers () const;
	virtual void SetEulers (const dVector& angles);

	virtual dVector GetScale () const;
	virtual void SetScale (const dVector& scale);

	virtual dVector GetColor () const;
	virtual void SetColor (const dVector& color); 


	virtual void BakeTransform (const dMatrix& transform);


	virtual void UpdateOOBB (dGeometryNodeInfo* geomInfo);
	virtual dFloat RayCast (const dVector& p0, const dVector& p1) const;

	// draw scene in wire frame mode
	void DrawWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in solid wire frame mode
	virtual void DrawSolidWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in Gouraud shaded normal textured mode 
	virtual void DrawGouraudShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// Draw selection gizmo
	virtual void DrawGizmo(dScene* world, dScene::dTreeNode* myNode, const dMatrix& coordinaSystem, const dVector& color, int* const workBuffer, int worlfBufferInBytes, dGizmoMode mode, dFloat size) const;
	virtual dGizmoHandle GetHighlightedGizmoHandle(dScene* world, dScene::dTreeNode* myNode, const dMatrix& coordinaSystem, const dVector& screenPosition, dGizmoMode mode, dFloat size) const;
	virtual void DrawGizmoHandle(dScene* world, const dMatrix& coordinaSystem, dGizmoMode mode, dGizmoHandle handle, const dVector& color, dFloat size) const;

	protected:


	virtual void SerializeBinary (FILE* file);
	virtual TiXmlElement* Serialize (TiXmlElement* parentNode); 
	virtual bool Deserialize (TiXmlElement* node, int revisionNumber);
	

	// the transformation of a node supports rotation, non uniform scaling and stretch
	// the full matrix is store as Ut * S * U * R * T
	// U is the a an orthogonal unit matrix and represent the principal axis of the the local scale applied to the child body
    // S is a diagonal matrix the represent the Scale
	dVector m_position;			// node location in global space
	dVector m_euler;			// orientation use to build matrix R: x = pitch, y = yaw, z = roll, 
	dVector m_scale;			// local scale: x = scale_x, y = scale_y, z = scale_z, 
	dMatrix m_eigenScaleAsis;   // principal axis for the scale values

	dVector m_solidColor;
	dVector m_editorMinOOBB;	// bounding Box of the body this bod cover in the scene
	dVector m_editorMaxOOBB;    // bounding Box of the body this bod cover in the scene
};





#endif