/////////////////////////////////////////////////////////////////////////////
// Name:        dBoneNodeInfo.h
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
#include "dBoneNodeInfo.h"

NE_IMPLEMENT_CLASS_NODE(dBoneNodeInfo);

dBoneNodeInfo::dBoneNodeInfo()
	:dSceneNodeInfo (), m_lengh (0.0f) 
{
	SetName ("boneNode");
}

dBoneNodeInfo::~dBoneNodeInfo(void)
{
}


/*

void dBoneNodeInfo::UpdateOOBB (dGeometryNodeInfo* geomInfo)
{
	if (geomInfo) {
		dVector euler (GetEulers ());
		dMatrix matrix (euler.m_x, euler.m_y, euler.m_z, GetPosition());
		dMatrix scaleMatrix (GetTransform() * matrix.Inverse());
		
		geomInfo->CalculateOOBBGizmo (scaleMatrix, m_editorMinOOBB, m_editorMaxOOBB);
	} else {
		// null will have a small OOBB for picking
		m_editorMinOOBB = dVector (-0.01f, -0.01f, -0.01f, -0.01f) ;	
		m_editorMaxOOBB = dVector ( 0.0f,   0.0f,   0.0f,   0.0f) ;	
	}
}

dFloat dBoneNodeInfo::RayCast (const dVector& p0, const dVector& p1) const
{
	// for now just calculate the OOBB ray cast
	dVector euler (GetEulers ());
	dMatrix matrix (euler.m_x, euler.m_y, euler.m_z, GetPosition());

	dVector localP0 (matrix.UntransformVector(p0));
	dVector localP1 (matrix.UntransformVector(p1)); 
	return dBoxRayCast (localP0, localP1, m_editorMinOOBB, m_editorMaxOOBB);
}





void dBoneNodeInfo::SerializeBinary (FILE* file) 
{
	fprintf (file, "%s\n%s\n", GetClassName(), GetName());
	_ASSERTE (0);
//	fwrite (&m_matrix[0][0], 1, sizeof (dMatrix), file);
}


void dBoneNodeInfo::DrawWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{
	_ASSERTE (world->GetInfoFromNode(myNode) == this);
#ifdef COMPILE_OPENGL
	dScene::dTreeNode* node = world->Find(this);
	dScene::dTreeNode* geomNode = world->FindChildByType(node, dGeometryNodeInfo::GetRttiType());
	if (geomNode) {

		glPushMatrix();
		dMatrix matrix (GetTransform());
		//glMultMatrix(&matrix[0][0]);
		glLoadMatrix(&matrix[0][0]);

		dGeometryNodeInfo* gemInfo = (dGeometryNodeInfo*) world->GetInfoFromNode(geomNode);
		gemInfo->DrawWireFrame(world, geomNode, workBuffer, worlfBufferInBytes);

		glPopMatrix();
	}
#endif
}


// draw scene in solid wire frame mode
void dBoneNodeInfo::DrawSolidWireFrame(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{
	_ASSERTE (world->GetInfoFromNode(myNode) == this);
#ifdef COMPILE_OPENGL
	
	dScene::dTreeNode* node = world->Find(this);
	dScene::dTreeNode* geomNode = world->FindChildByType(node, dGeometryNodeInfo::GetRttiType());
	if (geomNode) {

		glPushMatrix();
		dMatrix matrix (GetTransform());
		//glMultMatrix(&matrix[0][0]);
		glLoadMatrix(&matrix[0][0]);

		dGeometryNodeInfo* gemInfo = (dGeometryNodeInfo*) world->GetInfoFromNode(geomNode);
		gemInfo->DrawSolidWireFrame(world, geomNode, workBuffer, worlfBufferInBytes);

		glPopMatrix();
	}
#endif
}


// draw scene in Gouraud shaded normal textured mode 
void dBoneNodeInfo::DrawGouraudShaded(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes) const
{
	_ASSERTE (world->GetInfoFromNode(myNode) == this);
#ifdef COMPILE_OPENGL
	dScene::dTreeNode* node = world->Find(this);
	dScene::dTreeNode* geomNode = world->FindChildByType(node, dGeometryNodeInfo::GetRttiType());
	if (geomNode) {

		glPushMatrix();
		dMatrix matrix (GetTransform());
		//glMultMatrix(&matrix[0][0]);
		glLoadMatrix(&matrix[0][0]);

		dGeometryNodeInfo* gemInfo = (dGeometryNodeInfo*) world->GetInfoFromNode(geomNode);
		gemInfo->DrawGouraudShaded(world, geomNode, workBuffer, worlfBufferInBytes);

		glPopMatrix();
	}
#endif
}


// Draw selection gizmo
void dBoneNodeInfo::DrawGizmo(dScene* world, dScene::dTreeNode* myNode, const dVector& color, int* const workBuffer, int worlfBufferInBytes, dGizmoMode mode) const
{
	_ASSERTE (world->GetInfoFromNode(myNode) == this);
#ifdef COMPILE_OPENGL


	glDisable (GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glDisable (GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	dVector euler (GetEulers ());
	dMatrix matrix (euler.m_x, euler.m_y, euler.m_z, GetPosition());

	glPushMatrix();
	glLoadMatrix(&matrix[0][0]);


	switch (mode) 
	{
		case m_selection:
		{
			dFloat size = 0.5f;
			glBegin(GL_LINES);
			for (int i = 0; i < 3; i ++) {
				dVector p1 (0.0f, 0.0f, 0.0f, 1.0f);
				p1[i] = size;
				dVector color (0.0f, 0.0f, 0.0f, 0.0f) ;
				color[i] = 1.0f;
				glVertex3f(0.0f, 0.0f, 0.0f); // origin of the line
				glVertex3f(p1.m_x, p1.m_y, p1.m_z); // origin of the line
				glColor3f (color[0], color[1], color[2]);
			}
			glEnd();
			DrawOOBBGizmo (world, myNode);
		}

		case m_translation:
		case m_rotation:
			//_ASSERTE (0);

			DrawOOBBGizmo (world, myNode);
			break;
	}


	glPopMatrix();
#endif
}


void dBoneNodeInfo::DrawOOBBGizmo (dScene* world, dScene::dTreeNode* myNode) const
{
	_ASSERTE (world->GetInfoFromNode(myNode) == this);
#ifdef COMPILE_OPENGL
	
	dScene::dTreeNode* geomNode = world->FindChildByType(myNode, dGeometryNodeInfo::GetRttiType());
	if (geomNode) {
		dVector p[8];

//		dGeometryNodeInfo* info = (dGeometryNodeInfo*) world->GetInfoFromNode(geomNode);
//		dVector euler (GetEulers ());
//		dMatrix matrix (euler.m_x, euler.m_y, euler.m_z, GetPosition());
//		dMatrix scaleMatrix (GetTransform() * matrix.Inverse());
//		info->CalculateOOBBGizmo (scaleMatrix, p[0], p[4]);

		dFloat padding = 0.05f;
		p[0] = m_editorMinOOBB - dVector (padding, padding, padding, 1.0f);
		p[4] = m_editorMaxOOBB + dVector (padding, padding, padding, 1.0f);

		for (int i = 0; i < 3; i ++) {
			p[i + 1] = p[0];
			p[i + 1][i] = p[4][i];
			p[i + 5] = p[4];
			p[i + 5][i] = p[0][i];
		}

		dVector boxColor (1.0f, 1.0f, 0.0f, 0.0f);
		dFloat size = 0.25f;
		glBegin(GL_LINES);
		
		for (int i = 0; i < 8; i += 4) {
			// corner 0
			glVertex3f(p[i + 0].m_x, p[i + 0].m_y, p[i + 0].m_z); 
			glVertex3f(p[i + 0].m_x + size, p[i + 0].m_y, p[i + 0].m_z); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			glVertex3f(p[i + 0].m_x, p[i + 0].m_y, p[i + 0].m_z); 
			glVertex3f(p[i + 0].m_x, p[i + 0].m_y + size, p[i + 0].m_z); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);
			
			glVertex3f(p[i + 0].m_x, p[i + 0].m_y, p[i + 0].m_z); 
			glVertex3f(p[i + 0].m_x, p[i + 0].m_y, p[i + 0].m_z + size); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			// corner 1
			glVertex3f(p[i + 1].m_x, p[i + 1].m_y, p[i + 1].m_z); 
			glVertex3f(p[i + 1].m_x - size, p[i + 1].m_y, p[i + 1].m_z); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			glVertex3f(p[i + 1].m_x, p[i + 1].m_y, p[i + 1].m_z); 
			glVertex3f(p[i + 1].m_x, p[i + 1].m_y + size, p[i + 1].m_z); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			glVertex3f(p[i + 1].m_x, p[i + 1].m_y, p[i + 1].m_z); 
			glVertex3f(p[i + 1].m_x, p[i + 1].m_y, p[i + 1].m_z + size); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);


			// corner 2
			glVertex3f(p[i + 2].m_x, p[i + 2].m_y, p[i + 2].m_z); 
			glVertex3f(p[i + 2].m_x + size, p[i + 2].m_y, p[i + 2].m_z); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			glVertex3f(p[i + 2].m_x, p[i + 2].m_y, p[i + 2].m_z); 
			glVertex3f(p[i + 2].m_x, p[i + 2].m_y - size, p[i + 2].m_z); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			glVertex3f(p[i + 2].m_x, p[i + 2].m_y, p[i + 2].m_z); 
			glVertex3f(p[i + 2].m_x, p[i + 2].m_y, p[i + 2].m_z + size); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);


			// corner 3
			glVertex3f(p[i + 3].m_x, p[i + 3].m_y, p[i + 3].m_z); 
			glVertex3f(p[i + 3].m_x + size, p[i + 3].m_y, p[i + 3].m_z); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			glVertex3f(p[i + 3].m_x, p[i + 3].m_y, p[i + 3].m_z); 
			glVertex3f(p[i + 3].m_x, p[i + 3].m_y + size, p[i + 3].m_z); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			glVertex3f(p[i + 3].m_x, p[i + 3].m_y, p[i + 3].m_z); 
			glVertex3f(p[i + 3].m_x, p[i + 3].m_y, p[i + 3].m_z - size); 
			glColor3f (boxColor.m_x, boxColor.m_y, boxColor.m_z);

			size *= -1.0f;
		}
		glEnd();
	}

#endif
}
*/


TiXmlElement* dBoneNodeInfo::Serialize (TiXmlElement* parentNode)
{
	TiXmlElement* node = dSceneNodeInfo::Serialize (parentNode);

	node->SetValue (GetClassName());

	TiXmlElement* boneData = new TiXmlElement ("boneData");
	node->LinkEndChild(boneData);

	boneData->SetDoubleAttribute("lengh", m_lengh);

	return node;
}


bool dBoneNodeInfo::Deserialize (TiXmlElement* node, int revisionNumber) 
{
	dSceneNodeInfo::Deserialize (node, revisionNumber);

	SetName (node->Attribute("name"));

	TiXmlElement* boneData = (TiXmlElement*) node->FirstChild ("boneData");
	dStringToFloatArray (boneData->Attribute("lengh"), &m_lengh, 1);

	return true;
}

void dBoneNodeInfo::SerializeBinary (FILE* file)
{
}