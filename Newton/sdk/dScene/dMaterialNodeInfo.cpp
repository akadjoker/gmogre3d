/////////////////////////////////////////////////////////////////////////////
// Name:        dMaterialNodeInfo.h
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
#include "dMaterialNodeInfo.h"


NE_IMPLEMENT_CLASS_NODE(dMaterialNodeInfo);


dMaterialNodeInfo::dMaterialNodeInfo()
	:dNodeInfo (), 
	m_ambientColor (0.2f, 0.2f, 0.2f, 1.0f), m_diffuseColor(0.8f, 0.8f, 0.8f, 1.0f),
	m_specularColor (0.0f, 0.0f, 0.0f, 1.0f), m_shininess (0.0f), m_opacity (1.0f),
	m_id(0), 
	m_ambientTexId (-1), m_diffuseTexId (-1), m_specularTexId (-1), m_emissiveTexId(-1)
{
	SetName ("material");
}

dMaterialNodeInfo::dMaterialNodeInfo(dScene* world)
	:dNodeInfo (), 
	m_ambientColor (0.2f, 0.2f, 0.2f, 1.0f), m_diffuseColor(0.8f, 0.8f, 0.8f, 1.0f),
	m_specularColor (0.0f, 0.0f, 0.0f, 1.0f), m_shininess (0.0f), m_opacity (1.0f),
	m_id(0), 
	m_ambientTexId (-1), m_diffuseTexId (-1), m_specularTexId (-1), m_emissiveTexId(-1)
{
	SetName ("material");
}



dMaterialNodeInfo::dMaterialNodeInfo(int id)
	:dNodeInfo (), 
	m_ambientColor (0.2f, 0.2f, 0.2f, 1.0f), m_diffuseColor(0.8f, 0.8f, 0.8f, 1.0f),
	m_specularColor (0.0f, 0.0f, 0.0f, 1.0f), m_shininess (0.0f), m_opacity (1.0f),
	m_id(id), 
	m_ambientTexId (-1), m_diffuseTexId (-1), m_specularTexId (-1), m_emissiveTexId(-1)
{
	SetName ("material");
}

dMaterialNodeInfo::~dMaterialNodeInfo(void)
{
}



TiXmlElement* dMaterialNodeInfo::Serialize (TiXmlElement* parentNode)
{
	char buffer[1024];
	TiXmlElement* node = new TiXmlElement (GetClassName());
	parentNode->LinkEndChild(node);
	node->SetAttribute("name", GetName());
	node->SetAttribute("id", m_id);

	TiXmlElement* ambient = new TiXmlElement ("ambient");
	node->LinkEndChild(ambient);
	dFloatArrayToString(&m_ambientColor[0], 4, buffer, sizeof (buffer));
	ambient->SetAttribute("textureId", m_ambientTexId);
	ambient->SetAttribute("color", buffer);

	TiXmlElement* diffuse = new TiXmlElement ("diffuse");
	node->LinkEndChild(diffuse);
	dFloatArrayToString(&m_diffuseColor[0], 4, buffer, sizeof (buffer));
	diffuse->SetAttribute("textureId", m_diffuseTexId);
	diffuse->SetAttribute("color", buffer);

	TiXmlElement* specular = new TiXmlElement ("specular");
	node->LinkEndChild(specular);
	dFloatArrayToString(&m_specularColor[0], 4, buffer, sizeof (buffer));
	specular->SetAttribute("textureId", m_specularTexId);
	specular->SetAttribute("color", buffer);

	TiXmlElement* emissive = new TiXmlElement ("emissive");
	node->LinkEndChild(emissive);
	dFloatArrayToString(&m_emissiveColor[0], 4, buffer, sizeof (buffer));
	emissive->SetAttribute("textureId", m_emissiveTexId);
	emissive->SetAttribute("color", buffer);

	TiXmlElement* shininess = new TiXmlElement ("shininess");
	node->LinkEndChild(shininess);
	shininess->SetDoubleAttribute ("float", m_shininess);

	TiXmlElement* opacity = new TiXmlElement ("opacity");
	node->LinkEndChild(opacity);
	opacity->SetDoubleAttribute ("float", m_opacity);


	return node;
}

bool dMaterialNodeInfo::Deserialize (TiXmlElement* node, int revisionNumber) 
{
	SetName (node->Attribute("name"));
	node->Attribute("id", &m_id);

	TiXmlElement* ambient = (TiXmlElement*) node->FirstChild ("ambient");
	ambient->Attribute("textureId", &m_ambientTexId);
	dStringToFloatArray (ambient->Attribute("color"), &m_ambientColor[0], 4);

	TiXmlElement* diffuse = (TiXmlElement*) node->FirstChild ("diffuse");
	diffuse->Attribute("textureId", &m_diffuseTexId);
	dStringToFloatArray (diffuse->Attribute("color"), &m_diffuseColor[0], 4);

	TiXmlElement* specular = (TiXmlElement*) node->FirstChild ("specular");
	specular->Attribute("textureId", &m_specularTexId);
	dStringToFloatArray (specular->Attribute("color"), &m_specularColor[0], 4);

	TiXmlElement* emissive = (TiXmlElement*) node->FirstChild ("emissive");
	emissive->Attribute("textureId", &m_emissiveTexId);
	dStringToFloatArray (emissive->Attribute("color"), &m_emissiveColor[0], 4);

	TiXmlElement* shininess = (TiXmlElement*) node->FirstChild ("shininess");
	double value;
	shininess->Attribute("float", &value);
	m_shininess = dFloat (value);
	
	TiXmlElement* opacity = (TiXmlElement*) node->FirstChild ("opacity");
	opacity->Attribute("float", &value);
	m_opacity = dFloat (value);

	return true;
}


void dMaterialNodeInfo::SerializeBinary (FILE* file) 
{
	fprintf (file, "%s\n%s\n", GetClassName(), GetName());

//	node->SetAttribute("id", m_id);

	fwrite (&m_id, 1, sizeof (int), file);
	

//	TiXmlElement* ambient = new TiXmlElement ("ambient");
//	parentNode->LinkEndChild(ambient);
//	dFloatArrayToString(&m_ambientColor[0], 4, buffer, sizeof (buffer));
//	ambient->SetAttribute("textureId", m_ambientTexId);
//	ambient->SetAttribute("color", buffer);
	fwrite (&m_ambientTexId, 1, sizeof (int), file);
	fwrite (&m_ambientColor[0], 4, sizeof (dFloat), file);

//	TiXmlElement* diffuse = new TiXmlElement ("diffuse");
//	parentNode->LinkEndChild(diffuse);
//	dFloatArrayToString(&m_diffuseColor[0], 4, buffer, sizeof (buffer));
//	diffuse->SetAttribute("textureId", m_ambientTexId);
//	diffuse->SetAttribute("color", buffer);
	fwrite (&m_diffuseTexId, 1, sizeof (int), file);
	fwrite (&m_diffuseColor[0], 4, sizeof (dFloat), file);

//	TiXmlElement* specular = new TiXmlElement ("specular");
//	parentNode->LinkEndChild(specular);
//	dFloatArrayToString(&m_specularColor[0], 4, buffer, sizeof (buffer));
//	specular->SetAttribute("textureId", m_ambientTexId);
//	specular->SetAttribute("color", buffer);
	fwrite (&m_specularTexId, 1, sizeof (int), file);
	fwrite (&m_specularColor[0], 4, sizeof (dFloat), file);

//	TiXmlElement* emissive = new TiXmlElement ("emissive");
//	parentNode->LinkEndChild(emissive);
//	dFloatArrayToString(&m_emissiveColor[0], 4, buffer, sizeof (buffer));
//	emissive->SetAttribute("float4", buffer);
	fwrite (&m_emissiveTexId, 1, sizeof (int), file);
	fwrite (&m_emissiveColor[0], 4, sizeof (dFloat), file);

//	TiXmlElement* shininess = new TiXmlElement ("shininess");
//	parentNode->LinkEndChild(shininess);
//	shininess->SetDoubleAttribute ("float", m_shininess);
	fwrite (&m_shininess, 1, sizeof (dFloat), file);

//	TiXmlElement* opacity = new TiXmlElement ("opacity");
//	parentNode->LinkEndChild(opacity);
//	opacity->SetDoubleAttribute ("float", m_opacity);
	fwrite (&m_opacity, 1, sizeof (dFloat), file);
}