#include "stdafx.h"
#include "OgreNewtWorld.h"


NewtonContactCallback::NewtonContactCallback(OgreNewt::MaterialPair* mat_pair, unsigned int function)
:  mMaterialPair(mat_pair),
   mFunction(function)
{
}


NewtonContactCallback::~NewtonContactCallback()
{
}


int NewtonContactCallback::onAABBOverlap( OgreNewt::Body* body0, OgreNewt::Body* body1, int threadIndex )
{
   // If we set a callback we ALWAYS want to process hits
   return 1;
}


void NewtonContactCallback::contactsProcess( OgreNewt::ContactJoint &contactJoint, Ogre::Real timeStep, int threadIndex )
{
   int contact_count = contactJoint.getContactCount();

   OgreNewt::Contact contact = contactJoint.getFirstContact();
   OgreNewt::Contact best_contact = contact;
   Ogre::Real fastest_contact_speed = contact.getNormalSpeed();

   for (int x = 0; x < contact_count; x++)
   {
      Ogre::Real speed = contact.getNormalSpeed();

      if (speed > fastest_contact_speed)
         best_contact = contact;

      contact = contact.getNext();
   }

   OgreNewtContact newton_contact;
   Ogre::Vector3 norm;

   newton_contact.m_body1 = (OgreNewtBody*)best_contact.getBody0()->getUserData();
   newton_contact.m_body2 = (OgreNewtBody*)best_contact.getBody1()->getUserData();
   newton_contact.m_speed = best_contact.getNormalSpeed();
   best_contact.getPositionAndNormal(newton_contact.m_position, norm);

   newton_contact.m_function = mFunction;

   OgreNewtWorld *newton_world = (OgreNewtWorld*)NewtonWorldGetUserData(best_contact.getBody0()->getWorld()->getNewtonWorld());
   newton_world->addContact(newton_contact);
}
