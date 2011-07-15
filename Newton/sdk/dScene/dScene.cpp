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


#include "dPluginStdafx.h"
#include "dScene.h"
#include "dCameraNodeInfo.h"
#include "dRootNodeInfo.h"
#include "dSceneNodeInfo.h"
#include "dMeshNodeInfo.h"
#include "dTextureNodeInfo.h"
#include "dMaterialNodeInfo.h"
#include "dGeometryNodeSkinModifierInfo.h"

// this constructor is for the editor only
/*
dScene::dScene()
	:dSceneGraph(new dRootNodeInfo()), m_newton (NULL)
{
	// create one camera for each view port
	dTreeNode* root = GetRootNode();
	for (int i = 0; i < 4; i ++) {
		dNodeInfo* camera = new dCameraNodeInfo(i);
		AddNode (camera, root);
		camera->Release();
	}
}
*/

dScene::dScene(NewtonWorld* newton)
	:dSceneGraph(new dRootNodeInfo()), m_newton (newton)
{
	// create one camera for each view port
	dTreeNode* root = GetRootNode();
	for (int i = 0; i < 4; i ++) {
		dNodeInfo* camera = new dCameraNodeInfo(i);
		AddNode (camera, root);
		camera->Release();
	}
}

dScene::dScene(const dScene& me)
	:dSceneGraph(me), m_newton (me.m_newton)
{
}

dScene::~dScene(void)
{
}

dScene::dTreeNode* dScene::GetRootNode() const
{
	return dSceneGraph::GetRootNode();
}

void dScene::AddReference(dTreeNode* parent, dTreeNode* child)
{
	 AddEdge (parent, child);
}

void dScene::RemoveReference(dTreeNode* node1, dTreeNode* node2)
{
	DeleteEdge (node1, node2);
}

dScene::dTreeNode* dScene::CreateNode (const char* className, dTreeNode* parent)
{
	dTreeNode* node = NULL;
	dNodeInfo* info = dNodeInfo::CreateFromClassName (className, this);
	if (info) {
		node = AddNode(info, parent);
		info->Release();
	}
	return node;
}


dScene::dTreeNode* dScene::CreateSceneNode(dTreeNode* parent)
{
//	dNodeInfo* info = new dSceneNodeInfo();
//	dTreeNode* node = AddNode(info, parent);
//	info->Release();
//	return node;
	return CreateNode ("dSceneNodeInfo", parent);
}

dScene::dTreeNode* dScene::CreateMeshNode(dTreeNode* parent)
{
	// for some reason the mesh class does not get registered if I do not make a reference to it
	dNodeInfo* info = new dMeshNodeInfo(NewtonMeshCreate(m_newton));
	dTreeNode* node = AddNode(info, parent);
	info->Release();
	return node;
}

dScene::dTreeNode* dScene::CreateSkinModifierNode(dTreeNode* parent)
{
	// for some reason the mesh class does not get registered if I do not make a reference to it
	//	return CreateNode ("dGeometryNodeSkinModifierInfo", parent);

	dNodeInfo* info = new dGeometryNodeSkinModifierInfo();
	dTreeNode* node = AddNode(info, parent);
	info->Release();
	return node;
}

dScene::dTreeNode* dScene::CreateMaterialNode (dTreeNode* parent, int id)
{
//	dNodeInfo* info = new dMaterialNodeInfo(id);
//	dTreeNode* node = AddNode(info, parent);
//	info->Release();
//	return node;
	dTreeNode* node = CreateNode ("dMaterialNodeInfo", parent);
	((dMaterialNodeInfo*) GetInfoFromNode(node))->m_id = id;
	return node;
}

dScene::dTreeNode* dScene::CreateTextureNode (const char* pathName)
{
	dTreeNode* root = GetRootNode();

	// see if this texture is already exist
	unsigned crc = dCRC (dGetNameFromPath(pathName));
	for (void* ptr = GetFirstChild(root); ptr; ptr = GetNextChild(root, ptr)) {
		dNodeInfo* info = GetInfoFromNode(GetNodeFromLink (ptr));
		if (info->IsType(dTextureNodeInfo::GetRttiType())) {
			dTextureNodeInfo* texture = (dTextureNodeInfo*) info;
			if (crc == unsigned (texture->GetId())) {
				// we found a texture, return the node
				return GetNodeFromLink (ptr);
			}
		}
	}

	// texture is new make a new texture
//	dNodeInfo* info = new dTextureNodeInfo(pathName);
//	dTreeNode* node = AddNode(info, GetRootNode());
//	info->Release();
//	return node;
	dTreeNode* node = CreateNode ("dTextureNodeInfo", root);
	((dTextureNodeInfo*) GetInfoFromNode(node))->SetPathName (pathName);
	return node;
}

dScene::dTreeNode* dScene::AddNode(dNodeInfo* sceneInfo, dTreeNode* parent)
{
	dTreeNode* node = dSceneGraph::AddNode (sceneInfo, parent);
	return node;
}

dScene::dTreeNode* dScene::GetFirstNode () const
{
	Iterator iter (*this);
	iter.Begin();
	return iter.GetNode();
}

dScene::dTreeNode* dScene::FindNode (dNodeInfo* info) const
{
	return Find (info->GetUniqueID());
}

dScene::dTreeNode* dScene::GetNextNode (dTreeNode* node) const
{
	Iterator iter (*this);
	iter.Set (node);
	iter++;
	return iter.GetNode();
}


void* dScene::GetFirstChild(dTreeNode* parentNode) const
{
	dGraphNode& root = parentNode->GetInfo();
	return root.m_children.GetFirst();
}

void* dScene::GetNextChild(dTreeNode* parentNode, void* link) const
{
	dGraphNode::dLink::dListNode* node = (dGraphNode::dLink::dListNode*) link;
	return node->GetNext();
}

void* dScene::GetFirstParent(dTreeNode* childNode) const
{
	dGraphNode& root = childNode->GetInfo();
	return root.m_parents.GetFirst();
}

void* dScene::GetNextParent(dTreeNode* childNode, void* link) const
{
	dGraphNode::dLink::dListNode* node = (dGraphNode::dLink::dListNode*) link;
	return node->GetNext();
}


dScene::dTreeNode* dScene::GetNodeFromLink (void* child) const
{
	dGraphNode::dLink::dListNode* node = (dGraphNode::dLink::dListNode*) child;
	return node->GetInfo();
}

dNodeInfo* dScene::GetInfoFromNode(dTreeNode* node) const
{	
	return node->GetInfo().GetNode();
}

dNodeInfo* dScene::GetInstanceInfoFromNode(dTreeNode* node)
{
	_ASSERTE (0);
	return NULL;
//	dNodeInfo* copy = node->GetInfo().GetNode()->MakeCopy();
//	node->GetInfo().SetNode(copy);
//	copy->Release();
//	ReplaceKey (node, copy);
//	return copy;
}

dScene::dTreeNode* dScene::FindCameraNode(int camIndex) const
{
	int index = 0;
	dTreeNode* camera = NULL;

	dTreeNode* rootNode = GetRootNode();
	for (void* child = GetFirstChild (rootNode); child; child = GetNextChild(rootNode, child)) {
		dTreeNode* camNode = GetNodeFromLink (child);

		dNodeInfo* info = GetInfoFromNode(camNode);
		if (info->IsType(dCameraNodeInfo::GetRttiType())) {
			if (index < camIndex) {
				index ++;
			} else {
				camera = camNode;
				break;
			}
		}
	}
	_ASSERTE (camera);
	_ASSERTE (GetInfoFromNode(camera)->IsType(dCameraNodeInfo::GetRttiType()));
	return camera;
}

dScene::dTreeNode* dScene::FindTextureByTextId(dTreeNode* parentNode, int textId) const
{
	for (void* ptr = GetFirstChild(parentNode); ptr; ptr = GetNextChild(parentNode, ptr)) {
		dScene::dTreeNode* node = GetNodeFromLink(ptr);
		dNodeInfo* info = GetInfoFromNode(node);
		if (info->IsType(dTextureNodeInfo::GetRttiType())) {
			if (((dTextureNodeInfo*) info)->GetId() == textId) {
				return node;
			}
		}
	}
	return NULL;
}


dScene::dTreeNode* dScene::FindChildByType(dTreeNode* parentNode, int type) const
{
	for (void* child = GetFirstChild (parentNode); child; child = GetNextChild(parentNode, child)) {
		dTreeNode* tmpNode = GetNodeFromLink (child);
		dNodeInfo* info = GetInfoFromNode(tmpNode);
		if (info->IsType(type)) {
			return tmpNode;
		}
	}
	return NULL;
}

dScene::dTreeNode* dScene::FindParentByType(dTreeNode* childNode, int type) const
{
	for (void* parent = GetFirstParent(childNode); parent; parent = GetNextChild(childNode, parent)) {
		dTreeNode* tmpNode = GetNodeFromLink (parent);
		dNodeInfo* info = GetInfoFromNode(tmpNode);
		if (info->IsType(type)) {
			return tmpNode;
		}
	}
	return NULL;
}


void dScene::BakeSceneNodeTransform (dTreeNode* sceneNode, dMatrix& matrix) const
{
	_ASSERTE (0);
/*
	_ASSERTE (GetInfoFromNode(sceneNode)->IsType(dSceneNodeInfo::GetRttiType()));

	dSceneNodeInfo* sceneInfo = (dSceneNodeInfo*) GetInfoFromNode(sceneNode);
	sceneInfo->BakeTransform (matrix);

	for (void* ptr = GetFirstChild(sceneNode); ptr; ptr = GetNextChild(sceneNode, ptr)) {
		dTreeNode* geomNode = GetNodeFromLink(ptr);
		if (GetInfoFromNode(geomNode)->IsType(dGeometryNodeInfo::GetRttiType())) {
			dGeometryNodeInfo* geom = (dGeometryNodeInfo*)GetInfoFromNode(geomNode);
			geom->BakeTransform(matrix);
		}
	}
*/
}

void dScene::BakeSceneNodeTransformRecursive (dTreeNode* sceneNode, dMatrix& matrix) const
{
	_ASSERTE (0);
/*
	BakeSceneNodeTransform (sceneNode, matrix);
	for (void* ptr = GetFirstChild(sceneNode); ptr; ptr = GetNextChild(sceneNode, ptr)) {
		sceneNode = GetNodeFromLink(ptr);
		if (GetInfoFromNode(sceneNode)->IsType(dSceneNodeInfo::GetRttiType())) {
			BakeSceneNodeTransformRecursive (sceneNode, matrix);
		}
	}
*/
}



void dScene::Serialize (const char* fileName)
{
	TiXmlDocument asciifile;
	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
	asciifile.LinkEndChild (decl);

	TiXmlElement* parentNode = new TiXmlElement ("alchemedia");
	asciifile.LinkEndChild(parentNode);

	// save the file description and version
	TiXmlElement* header = new TiXmlElement ("header");
	parentNode->LinkEndChild(header);

	// save configuration for the main frame window
	header->SetAttribute ("description", "alchemedia file format");
	header->SetAttribute ("revision", m_currentRevision);

	// save file content
	dSceneGraph::Serialize (parentNode);

	// save the file
	asciifile.SaveFile (fileName);
}

bool dScene::Deserialize (const char* fileName)
{
	// apply last Configuration
	TiXmlDocument doc (fileName);
	doc.LoadFile();

	bool state = true;
	const TiXmlElement* root = doc.RootElement();
	if (root && doc.FirstChild ("alchemedia") ){

		TiXmlElement* root = (TiXmlElement*) doc.FirstChild ("alchemedia");
		_ASSERTE (root);

		TiXmlElement* header = (TiXmlElement*) root->FirstChild ("header");
		_ASSERTE (header);

		int revision;
		header->Attribute("revision", &revision);
		
		TiXmlElement* nodes = (TiXmlElement*) root->FirstChild ("nodes");
		_ASSERTE (nodes);

		state =  dSceneGraph::Deserialize (nodes, revision);
	}
	return state;
}

void dScene::SerializeBinary(const char* fileName)
{
	_ASSERTE (0);

/*
	FILE* file = fopen (fileName, "wb");
	if (file) {
		fprintf (file, "alchemedia\n");
		fprintf (file, "header\n");
		fprintf (file, "description: alchemedia file format\n");
		fprintf (file, "revision\n");
		int revision = m_currentRevision;
		fwrite (&revision, 1, sizeof (int), file);

		dSceneGraph::SerializeBinary (file);

		fclose (file);
	}
*/
}


void dScene::MergeScene (dScene* scene)
{
	dTree<dTreeNode*,dTreeNode*> map;
	Iterator iter (*scene);
	map.Insert(GetRootNode(), scene->GetRootNode());
	for (iter.Begin(); iter; iter ++) {
		dTreeNode* node = iter.GetNode();
		dNodeInfo* info = scene->GetInfoFromNode(node);
		if (!(info->IsType(dCameraNodeInfo::GetRttiType()) || info->IsType(dRootNodeInfo::GetRttiType()))) {
			_ASSERTE (!Find (info->GetUniqueID()));
			dTreeNode* newNode = AddNode (info, NULL);
			map.Insert(newNode, node);
		}
	}

	//now connect all edges
	dTree<dTreeNode*,dTreeNode*>::Iterator mapIter (map);
	for (mapIter.Begin(); mapIter; mapIter ++) {
		dTreeNode* srcNode = mapIter.GetKey();
		dGraphNode& srcInfoHeader = mapIter.GetNode()->GetInfo()->GetInfo();
		for (void* ptr = scene->GetFirstChild (srcNode); ptr; ptr = scene->GetNextChild(srcNode, ptr)) {
			dTreeNode* srcLinkNode = scene->GetNodeFromLink(ptr);

			dTree<dTreeNode*,dTreeNode*>::dTreeNode* mapSaved = map.Find(srcLinkNode);
			if (mapSaved) {
				dTreeNode* node = mapSaved->GetInfo();
				srcInfoHeader.m_children.Append(node);
			}
		}

		for (void* ptr = scene->GetFirstParent (srcNode); ptr; ptr = scene->GetNextParent(srcNode, ptr)) {
			dTreeNode* srcLinkNode = scene->GetNodeFromLink(ptr);

			dTree<dTreeNode*,dTreeNode*>::dTreeNode* mapSaved = map.Find(srcLinkNode);
			if (mapSaved) {
				dTreeNode* node = mapSaved->GetInfo();
				srcInfoHeader.m_parents.Append(node);
			}
		}

	}
}

void dScene::DeleteNode (dTreeNode* node)
{
	dSceneGraph::DeleteNode (node);
}

void dScene::MergeDuplicateTextures()
{
	dTreeNode* root = GetRootNode();

	for (void* ptr0 = GetFirstChild (root); ptr0; ptr0 = GetNextChild(root, ptr0)) {
		dTreeNode* texNode0 = GetNodeFromLink(ptr0);
		dNodeInfo* info = GetInfoFromNode(texNode0);
		if (info->IsType(dTextureNodeInfo::GetRttiType())) {
			dTextureNodeInfo* tex0 = (dTextureNodeInfo*) info;
			const char* texName0 = tex0->GetPathName();

			void* next = NULL;
			for (void* ptr1 = GetNextChild(root, ptr0); ptr1; ptr1 = next) {
				next = GetNextChild(root, ptr1);
				dTreeNode* texNode1 = GetNodeFromLink(ptr1);
				dNodeInfo* info1 = GetInfoFromNode(texNode1);
				if (info1->IsType(dTextureNodeInfo::GetRttiType())) {
					dTextureNodeInfo* tex1 = (dTextureNodeInfo*) info1;
					const char* texName1 = tex1->GetPathName();
					if (!stricmp(texName0, texName1)) {
						
						for (void* ptr3 = GetFirstChild(texNode1); ptr3; ptr3 = GetNextChild(texNode1, ptr3)) {
							dTreeNode* matNode = GetNodeFromLink(ptr3);
							dNodeInfo* info3 = GetInfoFromNode(matNode);
							if (info3->IsType(dMaterialNodeInfo::GetRttiType())) {
								AddReference(matNode, texNode0);
							}
						}
						DeleteNode(texNode1);
					}
				}
			}
		}
	}
}

void dScene::SetNodeLRU (dTreeNode* node, int lru) 
{
	node->GetInfo().SetLRU(lru);
}

int dScene::GetNodeLRU (dTreeNode* node) const 
{ 
	return node->GetInfo().GetLRU();
}


void dScene::UpdateAllOOBB ()
{
	Iterator iter (*this);
	for (iter.Begin(); iter; iter ++) {
		dTreeNode* node = iter.GetNode();
		dNodeInfo* info = GetInfoFromNode(node);
		if (info->IsType(dSceneNodeInfo::GetRttiType())){
			dSceneNodeInfo* sceneInfo = (dSceneNodeInfo*) GetInfoFromNode(node);
			dScene::dTreeNode* geomNode = FindChildByType(node, dGeometryNodeInfo::GetRttiType());
			dGeometryNodeInfo* geom = NULL;
			if (geomNode) {
				geom = (dGeometryNodeInfo*) GetInfoFromNode(geomNode);
			}
			sceneInfo->UpdateOOBB(geom);
		}
	}
}

dScene::dTreeNode* dScene::RayCast (const dVector& p0, const dVector& p1) const
{
	dFloat t = 1.2f;
	dTreeNode* sceneNode = NULL;
	dVector p2 (p1) ;
	Iterator iter (*this);
	for (iter.Begin(); iter; iter ++) {
		dTreeNode* node = iter.GetNode();
		dNodeInfo* info = GetInfoFromNode(node);
		if (info->IsType(dSceneNodeInfo::GetRttiType())){
			dSceneNodeInfo* sceneInfo = (dSceneNodeInfo*) GetInfoFromNode(node);
			dFloat t1 = sceneInfo->RayCast(p0, p2);
			if (t1 < t) {
				dScene::dTreeNode* geomNode = FindChildByType(node, dGeometryNodeInfo::GetRttiType());
				if (geomNode) {
					dMatrix matrix (sceneInfo->GetTransform().Inverse4x4());
					dVector q0 (matrix.RotateVector4x4(p0));
					dVector q1 (matrix.RotateVector4x4(p2));
					dGeometryNodeInfo* geom = (dGeometryNodeInfo*) GetInfoFromNode(geomNode);
					t1 = geom->RayCast(q0, q1);
				}
				if (t1 < t) {
					t = t1;
					p2 = p0 + (p2 - p0).Scale (t);
					sceneNode = node;
				}
			}
		}
	}
	
	return sceneNode;
}
