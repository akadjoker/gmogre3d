/////////////////////////////////////////////////////////////////////////////
// Name:        dTextureNodeInfo.h
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
#include "dTextureNodeInfo.h"


NE_IMPLEMENT_CLASS_NODE(dTextureNodeInfo);

dTextureNodeInfo::dTextureNodeInfo()
	:dNodeInfo (), m_id (0), m_internalUsage(-1) 
{

}

dTextureNodeInfo::dTextureNodeInfo(dScene* world)
	:dNodeInfo (), m_id (0), m_internalUsage(-1) 
{
	SetName ("texture");
}

dTextureNodeInfo::dTextureNodeInfo(const char* pathName)
	:dNodeInfo (), m_internalUsage(-1) 
{
	SetName ("texture");
	SetPathName (pathName);
}

dTextureNodeInfo::~dTextureNodeInfo(void)
{
	if (m_internalUsage != -1)  {
		_ASSERTE (0);
	}
}

void dTextureNodeInfo::SetPathName (const char* path)
{
	strncpy (m_path, path, sizeof (m_path));
	m_id = dCRC (dGetNameFromPath (path));
}


TiXmlElement* dTextureNodeInfo::Serialize (TiXmlElement* parentNode)
{
	TiXmlElement* node = new TiXmlElement (GetClassName());
	parentNode->LinkEndChild(node);

	node->SetAttribute("name", GetName());
	node->SetAttribute("path", m_path);

	return node;
}

bool dTextureNodeInfo::Deserialize (TiXmlElement* node, int revisionNumber) 
{
	SetName (node->Attribute("name"));
//	strncpy (m_path, node->Attribute ("path"), sizeof (m_path));
	SetPathName (node->Attribute ("path"));

	return true;
}

void dTextureNodeInfo::SerializeBinary (FILE* file) 
{
	fprintf (file, "%s\n%s\n", GetClassName(), GetName());

	fwrite (&m_id, 1, sizeof (int), file);
	fprintf (file, "%s\n", m_path);
}
