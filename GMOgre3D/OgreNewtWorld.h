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

#ifndef OGRE_NEWT_WORLD_H
#define OGRE_NEWT_WORLD_H

#include "OgreNewtBody.h"
#include "OgreNewt_World.h"
#include "OgreNewtContact.h"


class OgreNewtWorld
{
public:
   OgreNewtWorld(Ogre::Real desiredFps = 100.0f, int maxUpdatesPerFrames = 2);
   ~OgreNewtWorld();

   void update( Ogre::Real t_step );

   void invalidateCache();
 
   const OgreNewt::MaterialID* getDefaultMaterialID() const;

   void destroyAllBodies();

   void setSolverModel( int model );
   void setFrictionModel( int model);
   void setPlatformArchitecture( int mode );

   void setThreadCount(int threads);
   void setWorldSize( const Ogre::Vector3& min, const Ogre::Vector3& max );

   OgreNewt::Debugger& getDebugger() const;

   OgreNewt::World *getOgreNewtWorld();

   void setWorldGravity(Ogre::Vector3 vec);
   Ogre::Vector3 getWorldGravity();

   void setGMLeaveWorldFunc(int func);
   int getGMLeaveWorldFunc();

   void addBodyLeftWorld(OgreNewtBody* body);
   void removeBodyLeftWorld(OgreNewtBody* body);

   void addContact(OgreNewtContact &contact);

protected:
   OgreNewt::World *m_world;
   void *m_userdata;
   int m_gm_leave_world_func;
   std::vector<OgreNewtBody*> m_bodies_left_world;
   Ogre::Vector3 m_default_gravity;
   HANDLE m_mutex;
   std::vector<OgreNewtContact> m_contacts;
};

#endif
