/////////////////////////////////////////////////////////////////////////////
// Name:        dScene.h
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

#ifndef _D_WORLD_H_
#define _D_WORLD_H_
#include "dSceneGraph.h"


#define NE_MAX_LAYERS	8

class dCameraNodeInfo;
class dRootNodeInfo;


enum neFileRevision
{
	m_currentRevision = 100,
};


class dScene: public dSceneGraph
{
public:
//	dScene();
	dScene(NewtonWorld* newton);
	dScene(const dScene& me);
	virtual ~dScene(void);
	
	virtual dTreeNode* GetRootNode() const;
	virtual dTreeNode* CreateSceneNode(dTreeNode* parent);
	virtual dTreeNode* CreateMeshNode(dTreeNode* parent);
	virtual dTreeNode* CreateSkinModifierNode(dTreeNode* parent);
	virtual dTreeNode* CreateMaterialNode (dTreeNode* parent, int id);
	virtual dTreeNode* CreateTextureNode (const char* pathName);

	virtual dTreeNode* CreateNode (const char* className, dTreeNode* parent);

	virtual void AddReference(dTreeNode* parent, dTreeNode* child);
	virtual void RemoveReference(dTreeNode* node1, dTreeNode* node2);

	virtual dTreeNode* GetFirstNode () const;
	virtual dTreeNode* GetNextNode (dTreeNode* node) const;
	virtual dTreeNode* FindNode (dNodeInfo* info) const;

	
	virtual void* GetFirstChild(dTreeNode* parentNode) const;
	virtual void* GetNextChild(dTreeNode* parentNode, void* link) const;

	virtual void* GetFirstParent(dTreeNode* childNode) const;
	virtual void* GetNextParent(dTreeNode* childNode, void* link) const;

	//virtual bool IsParentLink (void* link) const;
	virtual dTreeNode* GetNodeFromLink (void* child) const;

	virtual dNodeInfo* GetInfoFromNode(dTreeNode* node) const;
	virtual dNodeInfo* GetInstanceInfoFromNode(dTreeNode* node);
	
	virtual dTreeNode* FindCameraNode(int camIndex) const;
	virtual dTreeNode* FindTextureByTextId(dTreeNode* parentNode, int textId) const;
	virtual dTreeNode* FindChildByType(dTreeNode* parentNode, int type) const;
	virtual dTreeNode* FindParentByType(dTreeNode* child, int type) const;

	virtual NewtonWorld* GetNewtonWorld() const {return m_newton;}

	virtual void DeleteNode (dTreeNode* node);
//	void UnlinkNode (dTreeNode* node);
	virtual void MergeScene (dScene* scene);

	virtual void Serialize (const char* fileName);
	virtual bool Deserialize (const char* fileName);
	virtual void SerializeBinary (const char* fileName);

	virtual void UpdateAllOOBB ();
	virtual dTreeNode* RayCast (const dVector& p0, const dVector& p1) const;


	virtual void BakeSceneNodeTransform (dTreeNode* neSceneNode, dMatrix& matrix) const;
	virtual void BakeSceneNodeTransformRecursive (dTreeNode* neSceneNode, dMatrix& matrix) const;


	virtual void MergeDuplicateTextures();

	void SetNodeLRU (dTreeNode* node, int lru);
	int GetNodeLRU (dTreeNode* node) const;


	protected:
	dTreeNode* AddNode(dNodeInfo* sceneInfo, dTreeNode* parent);

	NewtonWorld* m_newton;
};

#endif