#include "stdafx.h"
#include "OgreNewtWorld.h"
#include "LockMutex.h"
#include <GMAPI.h>


Ogre::Vector3 ConvertFromGMAxis2(double x, double y, double z)
{
   return Ogre::Vector3((Ogre::Real)x, (Ogre::Real)y, (Ogre::Real)z);
}


static void _CDECL LeaveWorldCallback(const NewtonBody* body, int threadIndex)
{
   OgreNewt::Body *bod = (OgreNewt::Body*)NewtonBodyGetUserData(body);
   OgreNewtBody *newton_body = (OgreNewtBody *)bod->getUserData();
   OgreNewtWorld *newton_world = (OgreNewtWorld*)NewtonWorldGetUserData(bod->getWorld()->getNewtonWorld());

   newton_world->addBodyLeftWorld(newton_body);
}


OgreNewtWorld::OgreNewtWorld(Ogre::Real desiredFps, int maxUpdatesPerFrames)
{
   m_world = OGRE_NEW OgreNewt::World(desiredFps, maxUpdatesPerFrames);

   m_default_gravity = Ogre::Vector3(0, -9.81, 0); // Default to earth gravity
   m_world->setPlatformArchitecture(2);
   NewtonWorldSetUserData(m_world->getNewtonWorld(), this);

   m_gm_leave_world_func = -1;

   m_mutex = CreateMutex(NULL, FALSE, NULL);
}


OgreNewtWorld::~OgreNewtWorld()
{
   delete m_world;
}


void OgreNewtWorld::update( Ogre::Real t_step )
{
   // Execute Body Left World callbacks
   if (m_gm_leave_world_func != -1)
   {
      LockMutex lm(m_mutex);

      std::vector<OgreNewtBody*>::iterator body_iter = m_bodies_left_world.begin();

      while (body_iter != m_bodies_left_world.end())
      {
         // Call our GM script to handle this leave world callback
         gm::CGMVariable args[1];
         args[0].Set(static_cast<double>(reinterpret_cast<intptr_t>(*body_iter)));
         gm::script_execute(m_gm_leave_world_func, args, 1);

         body_iter++;
      }

      m_bodies_left_world.clear();
   }

   if (m_contacts.size() > 0)
   {
      LockMutex lm(m_mutex);

      std::vector<OgreNewtContact>::iterator contact_iter = m_contacts.begin();
      while (contact_iter != m_contacts.end())
      {
         OgreNewtContact contact = *contact_iter;

         // Call our GM script to handle this leave world callback
         gm::CGMVariable args[6];
         args[0].Set(static_cast<double>(reinterpret_cast<intptr_t>(contact.m_body1)));
         args[1].Set(static_cast<double>(reinterpret_cast<intptr_t>(contact.m_body2)));
         args[2].Set(contact.m_speed);
         args[3].Set(ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).x);
         args[4].Set(ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).z);
         args[5].Set(ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).y);

         gm::script_execute(contact.m_function, args, 6);

         contact_iter++;
      }

      m_contacts.clear();
   }

   m_world->update(t_step);
} 


void OgreNewtWorld::invalidateCache()
{
   m_world->invalidateCache();
}


const OgreNewt::MaterialID* OgreNewtWorld::getDefaultMaterialID() const
{
   return m_world->getDefaultMaterialID();
} 


void OgreNewtWorld::destroyAllBodies()
{
   m_world->destroyAllBodies();
}


void OgreNewtWorld::setSolverModel( int model )
{
   m_world->setSolverModel(model);
}


void OgreNewtWorld::setFrictionModel( int model)
{
   m_world->setFrictionModel(model);
}


void OgreNewtWorld::setPlatformArchitecture( int mode )
{
   m_world->setPlatformArchitecture(mode);
}


void OgreNewtWorld::setThreadCount(int threads)
{
   m_world->setThreadCount(threads);
}


void OgreNewtWorld::setWorldSize( const Ogre::Vector3& min, const Ogre::Vector3& max )
{
   m_world->setWorldSize(min, max);
}


OgreNewt::Debugger& OgreNewtWorld::getDebugger() const
{
   return m_world->getDebugger();
}


OgreNewt::World *OgreNewtWorld::getOgreNewtWorld()
{
   return m_world;
}


void OgreNewtWorld::setWorldGravity(Ogre::Vector3 vec)
{
   LockMutex lm(m_mutex);

   m_default_gravity = vec;
}


Ogre::Vector3 OgreNewtWorld::getWorldGravity()
{
   return m_default_gravity;
}


void OgreNewtWorld::setGMLeaveWorldFunc(int func)
{
   LockMutex lm(m_mutex);

   if (func == -1)
      NewtonSetBodyLeaveWorldEvent(m_world->getNewtonWorld(), NULL);
   else
      NewtonSetBodyLeaveWorldEvent(m_world->getNewtonWorld(), LeaveWorldCallback);

   m_gm_leave_world_func = func;
}


int OgreNewtWorld::getGMLeaveWorldFunc()
{
   return m_gm_leave_world_func;
}


void OgreNewtWorld::addBodyLeftWorld(OgreNewtBody* body)
{
   LockMutex lm(m_mutex);

   m_bodies_left_world.push_back(body);
}


void OgreNewtWorld::removeBodyLeftWorld(OgreNewtBody* body)
{
   LockMutex lm(m_mutex);

   std::vector<OgreNewtBody*>::iterator body_iter = m_bodies_left_world.begin();

   while (body_iter != m_bodies_left_world.end())
   {
      if (*body_iter == body)
         body_iter = m_bodies_left_world.erase(body_iter);
      else
         body_iter++;
   }
}


void OgreNewtWorld::addContact(OgreNewtContact &contact)
{
   LockMutex lm(m_mutex);

   m_contacts.push_back(contact);
}
