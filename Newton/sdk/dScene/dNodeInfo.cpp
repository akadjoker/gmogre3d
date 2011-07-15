/////////////////////////////////////////////////////////////////////////////
// Name:        dNodeInfo.h
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
#include "dNodeInfo.h"

dInitRtti(dNodeInfo);


unsigned dNodeInfo::m_uniqueIDCounter = 0;

dNodeInfo::neRegisterMetaClass::neRegisterMetaClass (const char* className, CreateInfoMetaFunction function)
{
	int crc = dCRC (className);
	dTree<CreateInfoMetaFunction, int>& map = dNodeInfo::GetCreationFunctionMap();
	map.Insert (function, crc);
}

dNodeInfo::dNodeInfo() 
	:dClassInfo() 
{
	m_name[0] = 0; 
	m_uniqueID = m_uniqueIDCounter;
	m_uniqueIDCounter ++;
}


dNodeInfo::dNodeInfo(const dNodeInfo& me)
	:dClassInfo(), m_uniqueID (me.m_uniqueID)
{
	SetName (me.m_name);
}

dNodeInfo::~dNodeInfo(void)
{
}

const char* dNodeInfo::GetName () const
{
	return m_name;
}

void dNodeInfo::SetName (const char* name)
{
	strncpy (m_name, name, NE_MAX_NAME_SIZE - 1);
}


dTree<CreateInfoMetaFunction, int>& dNodeInfo::GetCreationFunctionMap()
{
	static dTree<CreateInfoMetaFunction, int>map;
	return map;
}

dNodeInfo* dNodeInfo::CreateFromClassName (const char* className, dScene* world)
{
	int crc = dCRC (className);
	dTree<CreateInfoMetaFunction, int>& map = GetCreationFunctionMap();
	dTree<CreateInfoMetaFunction, int>::dTreeNode* node = map.Find(crc);
	if (node) {
		CreateInfoMetaFunction fnt = node->GetInfo();
		return fnt (world);
	}
	return NULL;
}

// draw scene in wire frame mode
void dNodeInfo::DrawWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const 
{
}


dVector dNodeInfo::ScreenToWorld(const dVector& screenPoint) const
{
#ifdef COMPILE_OPENGL
	//Retrieves the viewport and stores it in the variable
	// get a point on the display array of the windows
	GLint viewport[4]; 
	glGetIntegerv(GL_VIEWPORT, viewport); 


	dMatrix modelView;
	dMatrix projection;
	glGetFloatv(GL_PROJECTION_MATRIX, &projection[0][0]);
	glGetFloatv(GL_MODELVIEW_MATRIX, &modelView[0][0]);
	modelView = modelView * projection;
	modelView = modelView.Inverse4x4();

	dVector p (2.0f * (screenPoint.m_x - (dFloat)viewport[0]) / (dFloat)viewport[2] - 1.0f,
		2.0f * (((dFloat)viewport[3] - screenPoint.m_y) - (dFloat)viewport[1]) / (dFloat)viewport[3] - 1.0f,
		2.0f * screenPoint.m_z - 1.0f,
		1.0f);

	p = modelView.RotateVector4x4(p);

	dFloat w = 1.0f / p.m_w;;
	p.m_w = 1.0f;
	p.m_x *= w;
	p.m_y *= w;
	p.m_z *= w;
	return p;
#else
	return screenPoint;
#endif
}



// draw scene in solid wire frame mode
void dNodeInfo::DrawSolidWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{
}


// draw scene in Gouraud shaded 
void dNodeInfo::DrawGouraudShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{
}

void dNodeInfo::DrawShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{

}


void dNodeInfo::DrawGizmo(dScene* world, dScene::dTreeNode* myNode, const dMatrix& coordinaSystem, const dVector& color, int* const workBuffer, int worlfBufferInBytes, dGizmoMode mode, dFloat size) const
{

}


dNodeInfo::dGizmoHandle dNodeInfo::GetHighlightedGizmoHandle(dScene* world, dScene::dTreeNode* myNode, const dMatrix& coordinaSystem, const dVector& screenPosition, dGizmoMode mode, dFloat size) const
{
	return m_noHandle;
}

void dNodeInfo::DrawGizmoHandle(dScene* world, const dMatrix& coordinaSystem, dGizmoMode mode, dGizmoHandle handle, const dVector& color, dFloat size) const
{

}
