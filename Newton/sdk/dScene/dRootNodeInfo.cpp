/////////////////////////////////////////////////////////////////////////////
// Name:        dRootNodeInfo.h
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
#include "dRootNodeInfo.h"


NE_IMPLEMENT_CLASS_NODE(dRootNodeInfo);

dRootNodeInfo::dRootNodeInfo(dScene* world) 
{
	SetName ("rootNode");
}

dRootNodeInfo::dRootNodeInfo()
{
	SetName ("rootNode");
}

dRootNodeInfo::~dRootNodeInfo(void)
{
}



TiXmlElement* dRootNodeInfo::Serialize (TiXmlElement* parentNode)
{
	TiXmlElement* node = new TiXmlElement (GetClassName());
	parentNode->LinkEndChild(node);

	node->SetAttribute("name", GetName());

	return node;
}

bool dRootNodeInfo::Deserialize (TiXmlElement* node, int revisionNumber) 
{
	SetName (node->Attribute("name"));
	return true;
}

void dRootNodeInfo::SerializeBinary (FILE* file) 
{
	fprintf (file, "%s\n%s\n", GetClassName(), GetName());
}