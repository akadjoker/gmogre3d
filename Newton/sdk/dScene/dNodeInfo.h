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

#ifndef _D_NODEINFO_H_
#define _D_NODEINFO_H_

#include "dScene.h"

#define NE_MAX_NAME_SIZE	64


class dNodeInfo;
typedef  dNodeInfo* (*CreateInfoMetaFunction) (dScene* world);	

#define NE_DEFINE_CLASS_NODE(className,baseClass)	\
	dAddRtti(baseClass);							\
	virtual dNodeInfo* MakeCopy () const			\
	{												\
		return new className(*this);				\
	}												\
	virtual const char* GetClassName ()				\
	{												\
		return #className;							\
	}												\
	virtual const char* GetBaseClassName ()			\
	{												\
		return #baseClass;							\
	}												\
	static dNodeInfo* MetaFunction(dScene* world)	\
	{												\
		return new className(world);				\
	}												\
	static neRegisterMetaClass m_registerClassAgent;


#define NE_IMPLEMENT_CLASS_NODE(className)	\
	dInitRtti(className);					\
	static className::neRegisterMetaClass m_registerClassAgent (#className, className::MetaFunction);



class dNodeInfo: public dClassInfo
{
	public:

	enum dGizmoMode
	{
		m_selection,
		m_translation,
		m_rotation,
		m_scale
	};

	enum dGizmoHandle
	{
		m_noHandle,
		m_xHandle,
		m_yHandle,
		m_zHandle,
		m_xyHandle,
		m_yzHandle,
		m_zxHandle,
		m_xyzHandle
	};

	class neRegisterMetaClass
	{	
		public:
		neRegisterMetaClass (const char* className, CreateInfoMetaFunction function);
	};

	dNodeInfo();
	dNodeInfo(const dNodeInfo& me);
	virtual ~dNodeInfo(void);
	virtual dNodeInfo* MakeCopy () const = 0;

	virtual const char* GetName () const;
	virtual void SetName (const char* name);
	
	virtual void SerializeBinary (FILE* file) = 0;
	virtual TiXmlElement* Serialize (TiXmlElement* parentNode) = 0; 
	virtual bool Deserialize (TiXmlElement* node, int revisionNumber) = 0;

	// draw scene in wire frame mode
	virtual void DrawWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in solid wire frame mode
	virtual void DrawSolidWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in Gouraud shaded 
	virtual void DrawGouraudShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// draw scene in using shaders 
	virtual void DrawShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const;

	// Draw selection gizmo
	virtual void DrawGizmo(dScene* world, dScene::dTreeNode* myNode, const dMatrix& coordinaSystem, const dVector& color, int* const workBuffer, int worlfBufferInBytes, dGizmoMode mode, dFloat size) const;
	virtual dGizmoHandle GetHighlightedGizmoHandle(dScene* world, dScene::dTreeNode* myNode, const dMatrix& coordinaSystem, const dVector& screenPosition, dGizmoMode mode, dFloat size) const;
	virtual void DrawGizmoHandle(dScene* world, const dMatrix& coordinaSystem, dGizmoMode mode, dGizmoHandle handle, const dVector& color, dFloat size) const;

	virtual dVector ScreenToWorld(const dVector& screenPoint) const;

	virtual unsigned GetUniqueID() const {return m_uniqueID;}


	static dNodeInfo* CreateFromClassName (const char* className, dScene* world);

	dAddRtti(dClassInfo);

	protected:

	char m_name[NE_MAX_NAME_SIZE];

	private:
	unsigned m_uniqueID;
	static unsigned m_uniqueIDCounter;
	static dTree<CreateInfoMetaFunction, int>& GetCreationFunctionMap(); 
};





#endif