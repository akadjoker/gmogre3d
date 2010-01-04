#include "OgreNewt_stdafx.h"
#include "OgreNewt_stdafx.h"
#include "OgreNewt_Vehicle.h"
#include "OgreNewt_Tools.h"


#if 0
namespace OgreNewt
{
////////////////////////////////////////////////////////
// TIRE FUNCTIONS

    // constructor
    Vehicle::Tire::Tire( OgreNewt::Vehicle* vehicle, Ogre::Quaternion localorient, Ogre::Vector3 localpos, Ogre::Vector3 pin,
                Ogre::Real mass, Ogre::Real width, Ogre::Real radius, Ogre::Real susShock, Ogre::Real susSpring, Ogre::Real susLength, int colID)
    {
        m_vehicle = vehicle;
        m_node = NULL;
        
        float matrix[16];

        OgreNewt::Converters::QuatPosToMatrix( localorient, localpos, matrix );

        m_tireid = NewtonVehicleAddTire ( m_vehicle->getNewtonVehicle(), matrix, &pin.x, mass, width, radius, 
               susShock, susSpring, susLength, this, colID );

    }


    // destructor
    Vehicle::Tire::~Tire()
    {
        // remove the tire from the vehicle.
        NewtonVehicleRemoveTire( m_vehicle->getNewtonVehicle(), m_tireid );

    }

    void Vehicle::Tire::updateNode()
    {
        if (!m_node)
            return;

        Ogre::Quaternion orient;
        Ogre::Vector3 pos;

        getPositionOrientation( orient, pos );
        m_node->setOrientation( orient );
        m_node->setPosition( pos );
    }

    void Vehicle::Tire::getPositionOrientation( Ogre::Quaternion& orient, Ogre::Vector3& pos )
    {
        float matrix[16];

        NewtonVehicleGetTireMatrix( m_vehicle->getNewtonVehicle(), m_tireid, matrix );
        OgreNewt::Converters::MatrixToQuatPos( matrix, orient, pos );
    }



///////////////////////////////////////////////////////////////////
// VEHICLE FUNCTIONS

    Vehicle::~Vehicle()
    {
        // destroy the joint!
        if(m_vehicle)
        {
            if (NewtonJointGetUserData(m_vehicle))
            {
                NewtonJointSetDestructor( m_vehicle, NULL );
                NewtonDestroyJoint( m_chassis->getWorld()->getNewtonWorld(), m_vehicle );
            }
        }
        
    }



    void Vehicle::init( OgreNewt::Body* chassis, const Ogre::Vector3& updir )
    {
        // setup the basic vehicle.
        m_chassis = chassis;

        m_vehicle = NewtonConstraintCreateVehicle (chassis->getWorld()->getNewtonWorld(), &updir.x, chassis->getNewtonBody() );

        // set the user data
        NewtonJointSetUserData( m_vehicle, this );
        NewtonJointSetDestructor( m_vehicle, newtonDestructor );

        //set the tire callback.
        NewtonVehicleSetTireCallback( m_vehicle, newtonCallback );

        //now call the user setup function
        setup();

    }

    void Vehicle::destroy()
    {
        // don't let newton call the destructor.
        NewtonJointSetDestructor( m_vehicle, NULL );

        // destroy the chassis.
        if (m_chassis)
            delete m_chassis;

        // joint is now destroyed.
        m_vehicle = NULL;
    }

    // get first tire.
    const OgreNewt::Vehicle::Tire* Vehicle::getFirstTire() const
    {
        Vehicle::Tire* tire = NULL;
        void* id = 0;

        id = NewtonVehicleGetFirstTireID( m_vehicle );

        if (id)
            tire = (Vehicle::Tire*)NewtonVehicleGetTireUserData( m_vehicle, id );

        return tire;
    }

    // get next tire.
    const OgreNewt::Vehicle::Tire* Vehicle::getNextTire( Vehicle::Tire* current_tire ) const
    {
        Vehicle::Tire* tire = NULL;
        void* id = 0;

        id = NewtonVehicleGetNextTireID( m_vehicle, (void*)current_tire->getNewtonID() );

        if (id)
            tire = (Vehicle::Tire*)NewtonVehicleGetTireUserData( m_vehicle, id );

        return tire;
    }


    // Newton callback.
    void _CDECL Vehicle::newtonCallback( const NewtonJoint* me )
    {
        OgreNewt::Vehicle* vehicle;

        vehicle = (Vehicle*)NewtonJointGetUserData( me );

        vehicle->userCallback();
    }

    void _CDECL Vehicle::newtonDestructor( const NewtonJoint* me )
    {
        Vehicle* vehicle;

        vehicle = (Vehicle*)NewtonJointGetUserData( me );

        NewtonJointSetDestructor( me, NULL );
        NewtonJointSetUserData( me, NULL );

        delete vehicle;
    }

}   // end NAMESPACE OgreNewt

#endif

