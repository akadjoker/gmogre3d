#include "stdafx.h"
#include "OgreNewtWorld.h"
#include "LockMutex.h"
#include "NewtonFrameListener.h"
#include "GM_API.h"


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


OgreNewtWorld::OgreNewtWorld(Ogre::Real desiredFps, int maxUpdatesPerFrames, Ogre::RenderWindow* win, Ogre::Root *root)
{
   m_world = OGRE_NEW OgreNewt::World(desiredFps, maxUpdatesPerFrames);

   if (m_root != NULL && win != NULL && desiredFps > 0)
   {
      m_newton_listener = OGRE_NEW NewtonFrameListener(win, this, (int)desiredFps);
      m_root = root;
      m_root->addFrameListener(m_newton_listener);
   }

   m_default_gravity = Ogre::Vector3(0, -9.81, 0); // Default to earth gravity
   m_world->setPlatformArchitecture(2);
   NewtonWorldSetUserData(m_world->getNewtonWorld(), this);

   m_gm_leave_world_func = -1;

   m_mutex = CreateMutex(NULL, FALSE, NULL);
}


OgreNewtWorld::~OgreNewtWorld()
{
   if (m_root != NULL && m_newton_listener != NULL)
   {
      m_root->removeFrameListener(m_newton_listener);
      OGRE_DELETE m_newton_listener;
   }

   delete m_world;
}


void OgreNewtWorld::update( Ogre::Real t_step )
{
   m_world->update(t_step);

   // Execute Body Left World callbacks
   if (m_gm_leave_world_func != -1)
   {
      LockMutex lm(m_mutex);

      std::vector<OgreNewtBody*>::iterator body_iter = m_bodies_left_world.begin();

      while (body_iter != m_bodies_left_world.end())
      {
         // Call our GM script to handle this leave world callback
         GM_script_execute(m_gm_leave_world_func, static_cast<double>(reinterpret_cast<intptr_t>(*body_iter)));

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
         GM_script_execute(contact.m_function, static_cast<double>(reinterpret_cast<intptr_t>(contact.m_body1)), static_cast<double>(reinterpret_cast<intptr_t>(contact.m_body2)), contact.m_speed, ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).x, ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).z, ConvertFromGMAxis2(contact.m_position.x, contact.m_position.z, contact.m_position.y).y);

         contact_iter++;
      }

      m_contacts.clear();
   }
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
