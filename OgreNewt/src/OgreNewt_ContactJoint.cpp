#include "OgreNewt_stdafx.h"
#include "OgreNewt_ContactJoint.h"
#include "OgreNewt_World.h"


namespace OgreNewt
{


ContactJoint::ContactJoint(const NewtonJoint* contactJoint)
{
    m_contactjoint = contactJoint;
}


ContactJoint::~ContactJoint()
{
}


Contact ContactJoint::getFirstContact()
{
    Contact contact(NewtonContactJointGetFirstContact(m_contactjoint), this);
    return contact;
}


MaterialPair* ContactJoint::getMaterialPair()
{
    Body* body0 = getBody0();
    Body* body1 = getBody1();
    const World* world = body0->getWorld();

    return (MaterialPair*) NewtonMaterialGetUserData(world->getNewtonWorld(), body0->getMaterialGroupID()->getID(), body1->getMaterialGroupID()->getID());
}



Contact::Contact(void* contact, ContactJoint* parent)
{
    m_parent = parent;
    m_contact = contact;
    m_material = NULL;
    if( contact )
    {
        m_material = NewtonContactGetMaterial(contact);
    }
}

Contact::~Contact()
{
}

Contact Contact::getNext() const
{
    Contact contact( NewtonContactJointGetNextContact(m_parent->_getNewtonContactJoint(), m_contact), m_parent);
    return contact;
}

Ogre::Vector3 Contact::getForce() const 
{
    Ogre::Vector3 force;
    NewtonMaterialGetContactForce( m_material, &force.x );
    return force;
}

void Contact::remove()
{
    if (m_parent != NULL && m_contact != NULL)
        NewtonContactJointRemoveContact(m_parent->_getNewtonContactJoint(), m_contact);
    m_parent = NULL;
    m_material = NULL;
    m_contact = NULL;
}


}

