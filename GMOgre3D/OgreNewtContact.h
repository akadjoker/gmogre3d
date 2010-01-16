/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2009 Robert Geiman
                   <robgeiman@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
--------------------------------------------------------------------------------
*/

#ifndef OGRE_NEWT_CONTACT_H
#define OGRE_NEWT_CONTACT_H

#include "OgreNewt_MaterialPair.h"


struct OgreNewtContact
{
   OgreNewtBody *m_body1;
   OgreNewtBody *m_body2;
   Ogre::Real m_speed;
   Ogre::Vector3 m_position;
   int m_function;
};


class NewtonContactCallback : public OgreNewt::ContactCallback
{
public:
   NewtonContactCallback(OgreNewt::MaterialPair* mat_pair, unsigned int function);
	~NewtonContactCallback();
   
   int onAABBOverlap( OgreNewt::Body* body0, OgreNewt::Body* body1, int threadIndex );
   void contactsProcess( OgreNewt::ContactJoint &contactJoint, Ogre::Real timeStep, int threadIndex );

private:
	OgreNewt::MaterialPair *mMaterialPair;
   unsigned int mFunction;
};

#endif
