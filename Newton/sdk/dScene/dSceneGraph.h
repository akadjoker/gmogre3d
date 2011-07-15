/////////////////////////////////////////////////////////////////////////////
// Name:        dSceneGraph.h
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

#ifndef _D_SCENE_GRAPH_H_
#define _D_SCENE_GRAPH_H_

class dNodeInfo;
class dGraphNode;
#define NE_GRAPH_MAX_STACK_DEPTH	2048

//class dSceneGraph: public dTree<dGraphNode, const dNodeInfo*>
class dSceneGraph: public dTree<dGraphNode, unsigned>
{
	public:
	dSceneGraph(dNodeInfo* rootInfo);
	dSceneGraph(const dSceneGraph& me);
	~dSceneGraph(void);

	dTreeNode* GetRootNode() const;
	dTreeNode* AddNode (dNodeInfo* info, dTreeNode* parent);
	void DeleteNode (dTreeNode* node);

	void AddEdge (dTreeNode* node1, dTreeNode* node2);
	void DeleteEdge (dTreeNode* node1, dTreeNode* node2);

	void UnlinkEdge (dTreeNode* node1, dTreeNode* node2);
	bool HasLinkToRoot (dTreeNode* node); 

	void Serialize (TiXmlElement* parentNode);
	bool Deserialize (TiXmlElement* parentNode, int revision);
	void SerializeBinary (FILE* file);

	int GetLRU();

	private:
	void Cleanup();

	int m_lru;
	dTreeNode* m_rootNode;
	friend class dGraphNode;
};


//class dGraphNode: public dList<neGraphEdge>
class dGraphNode
{
	class dLink: public dList<dSceneGraph::dTreeNode*>
	{
		friend class dScene;
		friend class dGraphNode;
		friend class dSceneGraph;
	};
	public:
	dGraphNode ();
	dGraphNode (const dGraphNode& node);
	~dGraphNode ();

	dNodeInfo* GetNode() const {return m_nodeInfo;}
	void SetNode(dNodeInfo* newInfo);

	void SetLRU (int lru) {m_lru = lru;}
	int GetLRU () const { return m_lru;}

	private:
	int m_lru;
	dNodeInfo* m_nodeInfo;
	dLink m_parents;
	dLink m_children;
	friend class dScene;
	friend class dSceneGraph;
};


#endif