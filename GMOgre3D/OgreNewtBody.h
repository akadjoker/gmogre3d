/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2010 Robert Geiman
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

#ifndef OGRE_NEWT_BODY_H
#define OGRE_NEWT_BODY_H

#include "OgreNewt_Body.h"
#include "OgreNewt_World.h"


class OgreNewtBody
{
public:
   OgreNewtBody(const OgreNewt::World* W, const OgreNewt::CollisionPtr& col, int bodytype = 0);
   ~OgreNewtBody();

    void setUserData( char *key, void* data );
    void* getUserData(char *key) const;

    void setType( int type );
    int getType() const;

    void attachNode( Ogre::Node* node );
    Ogre::Node *getOgreNode();
    void setStandardForceCallback();

    void setCustomForceAndTorqueCallback( OgreNewt::Body::ForceCallback callback );

    void setPositionOrientation( const Ogre::Vector3& pos, const Ogre::Quaternion& orient , int threadIndex = -1);

    void setMassMatrix( Ogre::Real mass, const Ogre::Vector3& inertia );

    void setCenterOfMass( const Ogre::Vector3& centerOfMass );
    Ogre::Vector3 getCenterOfMass() const;
        
    void freeze();
    void unFreeze();

    void setMaterialGroupID( const OgreNewt::MaterialID* ID );
    
    void setContinuousCollisionMode( unsigned state );
    void setJointRecursiveCollision( unsigned state );

    void setOmega( const Ogre::Vector3& omega );
    void setVelocity( const Ogre::Vector3& vel );

    void setLinearDamping( Ogre::Real damp );
    void setAngularDamping( const Ogre::Vector3& damp );

    void setAutoSleep( int flag );
    int getAutoSleep();

    const OgreNewt::MaterialID* getMaterialGroupID() const;

    void getPositionOrientation( Ogre::Vector3& pos, Ogre::Quaternion& orient ) const;

    void addImpulse( const Ogre::Vector3& deltav, const Ogre::Vector3& posit );

    void addForce( const Ogre::Vector3& force );
    void addTorque( const Ogre::Vector3& torque );
    void setForce( const Ogre::Vector3& force );
    void setTorque( const Ogre::Vector3& torque );
    void addGlobalForce( const Ogre::Vector3& force, const Ogre::Vector3& pos );
    void addLocalForce( const Ogre::Vector3& force, const Ogre::Vector3& pos );

    OgreNewt::Body *getOgreNewtBody();

    void EnableGravityOverride(bool enable);
    bool IsGravityOverrideEnabled();
    void setGravity(Ogre::Vector3 vec);
    Ogre::Vector3 getGravity();

    void setGMForceAndTorqueFunc(int func);
    void applyForceAndTorque();

protected:
   OgreNewt::Body *m_body;
   std::map<Ogre::String, void *> m_userdata;
   int m_gm_force_and_torque_func;

   bool m_override_gravity;
   Ogre::Vector3 m_gravity;

   Ogre::Vector3 m_queued_force;
   Ogre::Vector3 m_queued_torque;

   HANDLE m_mutex;
};

#endif
