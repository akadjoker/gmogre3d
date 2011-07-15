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

#ifndef _D_MATERIAL_NODE_H_
#define _D_MATERIAL_NODE_H_

#include "dNodeInfo.h"


class dMaterialNodeInfo: public dNodeInfo
{
	public:
	NE_DEFINE_CLASS_NODE(dMaterialNodeInfo,dNodeInfo)

	dMaterialNodeInfo();
	dMaterialNodeInfo(dScene* world);
	dMaterialNodeInfo(int id);
	virtual ~dMaterialNodeInfo(void);

	virtual int GetId () const {return m_id;}

	virtual void SetAmbientTextId(int id) {m_ambientTexId = id;}
	virtual void SetDiffuseTextId(int id) {m_diffuseTexId = id;}
	virtual void SetSpecularTextId(int id) {m_specularTexId = id;}
	virtual void SetEmissiveTextId(int id) {m_emissiveTexId = id;}

	virtual int GetAmbientTextId() const {return m_ambientTexId;}
	virtual int GetDiffuseTextId() const {return m_diffuseTexId;}
	virtual int GetSpecularTextId() const {return m_specularTexId;}
	virtual int GetEmissiveTextId() const {return m_emissiveTexId;}



	virtual void SetAmbientColor(const dVector& color) {m_ambientColor = color;}
	virtual void SetDiffuseColor(const dVector& color) {m_diffuseColor = color;}
	virtual void SetSpecularColor(const dVector& color) {m_specularColor = color;}
	virtual void SetEmissiveColor(const dVector& color) {m_emissiveColor = color;}
	virtual void SetShininess(dFloat power) {m_shininess = power;}
	virtual void SetOpacity(dFloat value) {m_opacity = value;}

	virtual const dVector& GetAmbientColor() const {return m_ambientColor;}
	virtual const dVector& GetDiffuseColor() const {return m_diffuseColor;}
	virtual const dVector& GetSpecularColor() const {return m_specularColor;}
	virtual const dVector& GetEmissiveColor() const {return m_emissiveColor;}
	virtual dFloat GetShininess() const {return m_shininess;}
	virtual dFloat GetOpacity() const {return m_opacity;}




	protected:
	virtual void SerializeBinary (FILE* file);
	virtual TiXmlElement* Serialize (TiXmlElement* parentNode); 
	virtual bool Deserialize (TiXmlElement* node, int revisionNumber);

	dVector m_ambientColor;
	dVector m_diffuseColor;
	dVector m_specularColor;
	dVector m_emissiveColor;
	dFloat m_shininess;
	dFloat m_opacity;
	int m_ambientTexId;
	int m_diffuseTexId;
	int m_specularTexId;
	int m_emissiveTexId;
	int m_id;
	friend class dScene;
};





#endif