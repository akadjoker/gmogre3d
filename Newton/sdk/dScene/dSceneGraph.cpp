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


#include "dPluginStdafx.h"
#include "dScene.h"
#include "dNodeInfo.h"
#include "dCameraNodeInfo.h"
#include "dSceneNodeInfo.h"
#include "dSceneGraph.h"




dGraphNode::dGraphNode ()
	:m_lru (0),  m_nodeInfo(NULL), m_parents(), m_children()
{
}

dGraphNode::dGraphNode (const dGraphNode& node)
//	:dList<neGraphEdge>(), m_lru (0)
	:m_lru (0),  m_nodeInfo(NULL), m_parents(), m_children()
{
	_ASSERTE (0);
}

dGraphNode::~dGraphNode ()
{
	_ASSERTE (0);
}

void dGraphNode::SetNode(dNodeInfo* newInfo)
{
	m_nodeInfo->Release();
	m_nodeInfo = newInfo;
	m_nodeInfo->AddRef();
}

dSceneGraph::dSceneGraph(dNodeInfo* rootInfo)
	:dTree<dGraphNode, unsigned>(), m_lru (0)
{
	m_rootNode = AddNode (rootInfo, NULL);
	rootInfo->Release();
}

dSceneGraph::dSceneGraph(const dSceneGraph& me)
	:dTree<dGraphNode, unsigned>(), m_lru (0)
{
	// add all nodes from me,  
	Iterator iter (me);
	for (iter.Begin(); iter; iter ++) {
		dGraphNode& srcNode = iter.GetNode()->GetInfo();
		AddNode (srcNode.m_nodeInfo, NULL);
	}

	//now connect all edges
	for (iter.Begin(); iter; iter ++) {
		dGraphNode& srcNode = iter.GetNode()->GetInfo();
		dGraphNode& myNode = Find(srcNode.m_nodeInfo->GetUniqueID())->GetInfo();

		for (dGraphNode::dLink::dListNode* srcEdge = srcNode.m_children.GetFirst(); srcEdge; srcEdge = srcEdge->GetNext()) {
			dGraphNode& srcLinkNode = srcEdge->GetInfo()->GetInfo();
			dTreeNode* myLinkNode = Find(srcLinkNode.m_nodeInfo->GetUniqueID());
			//myNode.m_children.Append(srcEdge->GetInfo());
			myNode.m_children.Append(myLinkNode);
		}

		for (dGraphNode::dLink::dListNode* srcEdge = srcNode.m_parents.GetFirst(); srcEdge; srcEdge = srcEdge->GetNext()) {
			dGraphNode& srcLinkNode = srcEdge->GetInfo()->GetInfo();
			dTreeNode* myLinkNode = Find(srcLinkNode.m_nodeInfo->GetUniqueID());
			//myNode.m_parents.Append(srcEdge->GetInfo());
			myNode.m_parents.Append(myLinkNode);
		}
	}

	m_rootNode = Find(me.GetRootNode()->GetInfo().GetNode()->GetUniqueID());
}

dSceneGraph::~dSceneGraph(void)
{
	Cleanup();
}

void dSceneGraph::Cleanup()
{
	Iterator iter (*this);
	for (iter.Begin(); iter; iter ++) {
		dGraphNode& info = (*iter);
		//info.RemoveAll();
		info.m_parents.RemoveAll();
		info.m_children.RemoveAll();
		info.m_nodeInfo->Release();
		info.m_nodeInfo = NULL;
	}
	RemoveAll();
	m_rootNode = NULL;
}

int dSceneGraph::GetLRU()
{
	m_lru ++;
	return m_lru;
}

dSceneGraph::dTreeNode* dSceneGraph::GetRootNode() const
{
	return m_rootNode;
}

bool dSceneGraph::HasLinkToRoot (dTreeNode* node)
{

	int stack;
	char parentEdge[NE_GRAPH_MAX_STACK_DEPTH];
	dTreeNode* pool[NE_GRAPH_MAX_STACK_DEPTH];

	pool[0] = node;
	stack = 1;

	int lru = GetLRU();
	node->GetInfo().SetLRU (lru);

	while (stack) {
		stack --;
		node = pool[stack];
		if (node == m_rootNode) {
			return true;
		}

		int index = 0;
		for (index = stack - 1; (index >= 0) && parentEdge[index]; index --);
		if ((index >= 0) && !parentEdge[index]) {
			index ++;
			_ASSERTE (index <= stack);
		}
		
		for (dGraphNode::dLink::dListNode* link = node->GetInfo().m_children.GetFirst(); link; link = link->GetNext()){
			dGraphNode& info = link->GetInfo()->GetInfo();
			if (info.GetLRU() != lru) {

				info.SetLRU(lru);
				if (index >= 0) {
					pool[stack] = pool[index];
					parentEdge[stack] = parentEdge[index];

					pool[index] = link->GetInfo();
					parentEdge[index] = 0;
					index ++;
				} else {
					pool[stack] = link->GetInfo();
					parentEdge[stack] = 0;
				}
				stack ++;
				_ASSERTE (stack < (sizeof (parentEdge) / sizeof (parentEdge[0])));
			}
		}

		for (dGraphNode::dLink::dListNode* link = node->GetInfo().m_parents.GetFirst(); link; link = link->GetNext()){
			dGraphNode& info = link->GetInfo()->GetInfo();
			if (info.GetLRU() != lru) {
				info.SetLRU(lru);
				pool[stack] = link->GetInfo();
				parentEdge[stack] = 1;
				stack ++;
				_ASSERTE (stack < (sizeof (parentEdge) / sizeof (parentEdge[0])));
			}
		}
	}
	return false;
}

dSceneGraph::dTreeNode* dSceneGraph::AddNode (dNodeInfo* info, dTreeNode* parent)
{
	dTreeNode* child = Insert(info->GetUniqueID());
	dGraphNode& node = child->GetInfo();
	node.m_nodeInfo = info;
	info->AddRef();

	if (parent) {
		parent->GetInfo().m_children.Append(child);
		child->GetInfo().m_parents.Append(parent);
	}
	return child;
}

void dSceneGraph::AddEdge (dTreeNode* parent, dTreeNode* child)
{
	dGraphNode& parentNode = parent->GetInfo();
	dGraphNode& childNode = child->GetInfo();

	dGraphNode::dLink::dListNode* parentLink = NULL;
	dGraphNode::dLink::dListNode* childLink = NULL;

	for (childLink = childNode.m_parents.GetFirst(); childLink; childLink = childLink->GetNext()) {
		if (childLink->GetInfo() == parent) {
			for (parentLink = parentNode.m_children.GetFirst(); parentLink; parentLink = parentLink->GetNext()){
				if (parentLink->GetInfo() == child) {
					break;
				}
			}
			break;
		}
	}

	_ASSERTE ((parentLink && childLink) || (!parentLink && !childLink));
	if ((!parentLink && !childLink)) {
		parentNode.m_children.Append(child);
		childNode.m_parents.Append(parent);
	}
}

void dSceneGraph::UnlinkEdge (dTreeNode* node1, dTreeNode* node2)
{
_ASSERTE (0);
/*
	dGraphNode& info1 = node1->GetInfo();
	dGraphNode& info2 = node2->GetInfo();

	dGraphNode::dListNode* link1 = NULL;
	dGraphNode::dListNode* link2 = NULL;
	for (link1 = info1.GetFirst(); link1; link1 = link1->GetNext()){
		if (link1->GetInfo().GetNode() == node2) {
			for (link2 = info2.GetFirst(); link2; link2 = link2->GetNext()) {
				if (link2->GetInfo().GetNode() == node1) {
					break;
				}
			}
			break;
		}
	}

	_ASSERTE ((link1 && link2) || (!link1 && !link2));
	if (link1 && link2) {
		info1.Remove(link1);
		info2.Remove(link2);
	}
*/
}

void dSceneGraph::DeleteEdge (dTreeNode* node1, dTreeNode* node2)
{
	dGraphNode& info1 = node1->GetInfo();
	dGraphNode& info2 = node2->GetInfo();

	for (dGraphNode::dLink::dListNode* link1 = info1.m_children.GetFirst(); link1; link1 = link1->GetNext()){
		if (link1->GetInfo() == node2) {
			for (dGraphNode::dLink::dListNode* link2 = info2.m_parents.GetFirst(); link2; link2 = link2->GetNext()) {
				if (link2->GetInfo() == node1) {
					info1.m_children.Remove(link1);
					info2.m_parents.Remove(link2);

					if (!HasLinkToRoot (node1)) {
						_ASSERTE (node1 != m_rootNode);
						DeleteNode (node1);
					}
					if (!HasLinkToRoot (node2)) {
						_ASSERTE (node2 != m_rootNode);
						DeleteNode (node2);
					}
					return;
				}
			}
		}
	}

	for (dGraphNode::dLink::dListNode* link1 = info1.m_parents.GetFirst(); link1; link1 = link1->GetNext()){
		if (link1->GetInfo() == node2) {
			for (dGraphNode::dLink::dListNode* link2 = info2.m_children.GetFirst(); link2; link2 = link2->GetNext()) {
				if (link2->GetInfo() == node1) {
					info1.m_parents.Remove(link1);
					info2.m_children.Remove(link2);

					if (!HasLinkToRoot (node1)) {
						_ASSERTE (node1 != m_rootNode);
						DeleteNode (node1);
					}
					if (!HasLinkToRoot (node2)) {
						_ASSERTE (node2 != m_rootNode);
						DeleteNode (node2);
					}
					return;
				}
			}
		}
	}
}

void dSceneGraph::DeleteNode (dTreeNode* node)
{
_ASSERTE (0);
/*
	dList<dTreeNode*> childrenList;
	dTree<dTreeNode*, const dNodeInfo*> deleteList;
	dGraphNode& info = node->GetInfo();
	deleteList.Insert(node, node->GetKey());
	while (info.GetFirst()) {
		dTreeNode* twinNode = info.GetFirst()->GetInfo().GetNode();
		childrenList.Append (twinNode);
		dGraphNode& twinInfo = twinNode->GetInfo();
		for (dGraphNode::dListNode* link = twinInfo.GetFirst(); link; link = link->GetNext()){
			if (link->GetInfo().GetNode() == node) {
				twinInfo.Remove (link);
				break;
			}
		}
		info.Remove(info.GetFirst());
	}

	
	for (dList<dTreeNode*>::dListNode* ptr = childrenList.GetFirst(); ptr; ptr = ptr->GetNext()){
		dTreeNode* childNode = ptr->GetInfo();
		//dGraphNode& info = childNode->GetInfo();

//		if (info.GetLRU() != lru) {
		int stack = 1;
		char parentEdge[NE_GRAPH_MAX_STACK_DEPTH];
		dTreeNode* pool[NE_GRAPH_MAX_STACK_DEPTH];

		int lru = GetLRU();
		pool[0] = childNode;
		node->GetInfo().SetLRU (lru);
		bool listIsDangling = true;
		dList<dTreeNode*> danglingNodes;

		while (stack) {
			stack --;
			dTreeNode* node = pool[stack];
			if (node == m_rootNode) {
				listIsDangling = false;
				break;
			}
			danglingNodes.Append(node);

			for (dGraphNode::dListNode* link = node->GetInfo().GetFirst(); link; link = link->GetNext()){
				dGraphNode& info = link->GetInfo().GetNode()->GetInfo();
				if (info.GetLRU() != lru) {
					info.SetLRU(lru);
					int index = stack;
					char state = link->GetInfo().IsParent() ? 1 : 0;
					for (index = stack; (index > 0) && (parentEdge[index - 1] > state) ; index --) {
						pool[index] = pool[index - 1];
						parentEdge[index] = parentEdge[index - 1];
					}
					parentEdge[index] = state;
					pool[index] = link->GetInfo().GetNode();
					stack ++;
					_ASSERTE (stack < (sizeof (parentEdge) / sizeof (parentEdge[0])));
				}
			}
		}

		if (listIsDangling) {
			for (dList<dTreeNode*>::dListNode* first = danglingNodes.GetFirst(); first; first = first->GetNext()) {
				deleteList.Insert(first->GetInfo(), first->GetInfo()->GetKey());
			}

		}
		danglingNodes.RemoveAll();
		
	}
	
	dTree<dTreeNode*, const dNodeInfo*>::Iterator iter (deleteList);
	for (iter.Begin(); iter; iter ++) {
		dTreeNode* node = (*iter);
		if (Find(node->GetKey())) {
			dGraphNode& info = node->GetInfo();
			info.RemoveAll();
			info.m_nodeInfo->Release();
			info.m_nodeInfo = NULL;
			Remove (node);
		}
	}
*/
}


void dSceneGraph::Serialize (TiXmlElement* parentNode)
{
	// save scenes nodes
	TiXmlElement* nodes = new TiXmlElement ("nodes");
	parentNode->LinkEndChild(nodes);

	
	dTree<int, dTreeNode*> enumerator;

	int index = 0;
	Iterator iter (*this);
	for (iter.Begin(); iter; iter ++) {
		dTreeNode* node = iter.GetNode();
		dNodeInfo* info = node->GetInfo().GetNode();
		enumerator.Insert (index, node);
		index ++;
	}
	nodes->SetAttribute("count", index);

	for (iter.Begin(); iter; iter ++) {
		
		dTreeNode* node = iter.GetNode();
		dNodeInfo* info = node->GetInfo().GetNode();
		int indexList[1024];
		char text[1024 * 32];
		TiXmlElement* infoNode = node->GetInfo().GetNode()->Serialize(nodes);
		_ASSERTE (infoNode);

		int nodeCount = 0;
		for (dGraphNode::dLink::dListNode* edgeNode = node->GetInfo().m_parents.GetFirst(); edgeNode; edgeNode = edgeNode->GetNext()) {
			dTree<int, dTreeNode*>::dTreeNode* edge = enumerator.Find (edgeNode->GetInfo());
			_ASSERTE (edge);
//			if (edge) {
				indexList[nodeCount] = edge->GetInfo();
				nodeCount ++;
				_ASSERTE (nodeCount < (sizeof (indexList) / sizeof (indexList[0])));
//			}
		}
		if (nodeCount) {
			dIntArrayToString (indexList, nodeCount, text, sizeof (text));
			TiXmlElement* parent = new TiXmlElement ("parentNodes");
			parent->SetAttribute("count", nodeCount);
			parent->SetAttribute("indices", text);
			infoNode->LinkEndChild(parent);
		}
		
		nodeCount = 0;
		for (dGraphNode::dLink::dListNode* edgeNode = node->GetInfo().m_children.GetFirst(); edgeNode; edgeNode = edgeNode->GetNext()) {
			dTree<int, dTreeNode*>::dTreeNode* edge = enumerator.Find (edgeNode->GetInfo());
			_ASSERTE (edge);
//			if (edge) {
				indexList[nodeCount] = edge->GetInfo();
				nodeCount ++;
				_ASSERTE (nodeCount < (sizeof (indexList) / sizeof (indexList[0])));
//			}
		}
		if (nodeCount) {
			dIntArrayToString (indexList, nodeCount, text, sizeof (text));
			TiXmlElement* parent = new TiXmlElement ("childrenNodes");
			parent->SetAttribute("count", nodeCount);
			parent->SetAttribute("indices", text);
			infoNode->LinkEndChild(parent);
		}

	}
}

bool dSceneGraph::Deserialize (TiXmlElement* nodes, int revision)
{
	Cleanup();
	int count;
	nodes->Attribute("count", &count);

	dScene* world = (dScene*) this;
	for (TiXmlElement* element = (TiXmlElement*) nodes->FirstChild(); element; element = (TiXmlElement*) element->NextSibling()) {
		const char* className = element->Value();
		dNodeInfo* info = dNodeInfo::CreateFromClassName (className, world);
		_ASSERTE (info);
		info->Deserialize(element, revision);
		AddNode (info, NULL);
		info->Release();
	}

	int baseIndex = Minimum()->GetKey();
	int baseIndexCount = baseIndex;
	for (TiXmlElement* element = (TiXmlElement*) nodes->FirstChild(); element; element = (TiXmlElement*) element->NextSibling()) {
		dTreeNode* myNode = Find (baseIndexCount);
		baseIndexCount ++;
		_ASSERTE (myNode);
		dGraphNode& node = myNode->GetInfo();

		TiXmlElement* parentNodes = (TiXmlElement*) element->FirstChild ("parentNodes");
		if (parentNodes) {
			int count;
			parentNodes->Attribute("count", &count);
			const char* indices = parentNodes->Attribute ("indices");

			const char* ptr = indices;
			for (int i = 0; i < count; i ++) {
				char index[128];
				sscanf (ptr, "%s", index);
				ptr = strstr (ptr, index);
				ptr += strlen (index); 
				int parentIndex = atoi (index);

				dTreeNode* parentNode = Find(parentIndex + baseIndex);
				_ASSERTE (parentNode);
				node.m_parents.Append(parentNode);
			}
		} else {
			_ASSERTE (!m_rootNode);
			m_rootNode = myNode;
		}


		TiXmlElement* childrenNodes = (TiXmlElement*) element->FirstChild ("childrenNodes");
		if (childrenNodes) {
			int count;
			childrenNodes->Attribute("count", &count);
			const char* indices = childrenNodes->Attribute ("indices");

			const char* ptr = indices;
			for (int i = 0; i < count; i ++) {
				char index[128];
				sscanf (ptr, "%s", index);
				ptr = strstr (ptr, index);
				ptr += strlen (index); 
				int childIndex = atoi (index);

				dTreeNode* childNode = Find(childIndex + baseIndex);
				_ASSERTE (childNode);
				node.m_children.Append(childNode);
			}
		}
	}

	return true;
}

void dSceneGraph::SerializeBinary (FILE* file)
{
_ASSERTE (0);
/*
	// save scenes nodes

	int index = 0;
	dTree<int, dTreeNode*> enumerator;

	Iterator iter (*this);
	for (iter.Begin(); iter; iter ++) {
		enumerator.Insert (index ++, iter.GetNode());
	}
//	nodes->SetAttribute("count", index);

	fprintf (file, "nodes\n");
	fwrite (&index, 1, sizeof (int), file);
	for (iter.Begin(); iter; iter ++) {
		int indexList[1024];
		dTreeNode* node = iter.GetNode();

		int nodeCount = 0;
//		TiXmlElement* infoNode = node->GetInfo().GetNode()->Serialize(nodes);
		node->GetInfo().GetNode()->SerializeBinary(file);
		for (dGraphNode::dListNode* edgeNode = node->GetInfo().GetFirst(); edgeNode; edgeNode = edgeNode->GetNext()) {
			if (edgeNode->GetInfo().IsParent()) {
				indexList[nodeCount] = enumerator.Find (edgeNode->GetInfo().GetNode())->GetInfo();
				nodeCount ++;
				_ASSERTE (nodeCount < (sizeof (indexList) / sizeof (indexList[0])));
			}
		}

		if (nodeCount) {
//			char text[1024 * 32];
//			dIntArrayToString (indexList, nodeCount, text, sizeof (text));
//			TiXmlElement* parent = new TiXmlElement ("parentNodes");
//			parent->SetAttribute("count", nodeCount);
//			parent->SetAttribute("indices", text);
//			infoNode->LinkEndChild(parent);
			fprintf (file, "parentNodes\n");
			fwrite (&nodeCount, 1, sizeof (int), file);
			fwrite (indexList, nodeCount, sizeof (int), file);
		}


		nodeCount = 0;
		for (dGraphNode::dListNode* edgeNode = node->GetInfo().GetFirst(); edgeNode; edgeNode = edgeNode->GetNext()) {
			if (!edgeNode->GetInfo().IsParent()) {
				indexList[nodeCount] = enumerator.Find (edgeNode->GetInfo().GetNode())->GetInfo();
				nodeCount ++;
				_ASSERTE (nodeCount < (sizeof (indexList) / sizeof (indexList[0])));
			}
		}
		if (nodeCount) {
//			char text[1024 * 32];
//			dIntArrayToString (indexList, nodeCount, text, sizeof (text));
//			TiXmlElement* parent = new TiXmlElement ("childrenNodes");
//			parent->SetAttribute("count", nodeCount);
//			parent->SetAttribute("indices", text);
//			infoNode->LinkEndChild(parent);
			fprintf (file, "childrenNodes\n");
			fwrite (&nodeCount, 1, sizeof (int), file);
			fwrite (indexList, nodeCount, sizeof (int), file);
		}
	}
*/
}


