/////////////////////////////////////////////////////////////////////////////
// Name:        dCameraNodeInfo.h
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

#ifndef _D_CAMERA_NODE_INFO_H_
#define _D_CAMERA_NODE_INFO_H_


#include "dNodeInfo.h"


#define NE_RENDER_BUFFER_SIZE (16 * 1024)
class dScene;

class dCameraNodeInfo: public dNodeInfo
{
public:
	enum ProjectionModes
	{
		m_front,
		m_back,
		m_left,
		m_right,
		m_top,
		m_bottom,
		m_perspective,
		m_orthographic,
	};


	NE_DEFINE_CLASS_NODE(dCameraNodeInfo,dNodeInfo)

	dCameraNodeInfo();
	dCameraNodeInfo(dScene* world);
	dCameraNodeInfo(int viewportIndex);
	virtual ~dCameraNodeInfo(void);

	// Set the Camera Matrix
	void SetCameraMatrix(void);

	// Get/Set the view  mode for this camera
	ProjectionModes GetViewMode() const;
	void SetViewMode(ProjectionModes viewMode);
	
	// Set the projection matrix
	void SetProjectionMode(int width, int height);
	// draw the 2d construction grid with origin at point (0, 0, 0)
	void DrawConstructionGrid();

	// draw scene in wire frame mode
	virtual void DrawWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in solid wire frame mode
	virtual void DrawSolidWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in Gouraud shaded normal textured mode 
	virtual void DrawGouraudShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in using shaders 
	virtual void DrawShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes);


	// draw selection and coordinates gizmo
	void DrawGizmo(dScene* world, dScene::dTreeNode* myNode, const dMatrix& coordinaSystem, const dVector& color, int* const workBuffer, int worlfBufferInBytes, dGizmoMode mode, dFloat size) const;


	// Draw selection gizmo
//	virtual void DrawSelectionGizmo(dScene* world, dScene::dTreeNode* myNode, dScene::dTreeNode* GismoNode, int* const workBuffer, int maxSize) const;


private:
	virtual void SerializeBinary (FILE* file);
	virtual TiXmlElement* Serialize (TiXmlElement* parentNode); 
	virtual bool Deserialize (TiXmlElement* node, int revisionNumber);
	

	// save the projection mode
	ProjectionModes m_projectionMode;

	// camera focus point
	dVector m_pointOfInterest;
		
	// camera pitch angle
	dFloat m_roll;
	// camera yaw angle
	dFloat m_yaw;
	// distance form focus point
	dFloat m_distance;

	// horizontal size of the ortho graphics view port
	dFloat m_2dViewportSize;

	int m_viewportIndex;
};


#endif