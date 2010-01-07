/* 
    OgreNewt Library

    Ogre implementation of Newton Game Dynamics SDK

    OgreNewt basically has no license, you may use any or all of the library however you desire... I hope it can help you in any way.

        by Walaber
        some changes by melven

*/
#ifndef _INCLUDE_OGRENEWT_RAYCASTVEHICLE
#define _INCLUDE_OGRENEWT_RAYCASTVEHICLE


#include "OgreNewt_Prerequisites.h"
#include "OgreNewt_Joint.h"



namespace OgreNewt
{

//! Represents a wheeled vehicle
/*!
    this class represents a basic vehicle, meant to be inherited by the user, with functionality added.
*/
    class _OgreNewtExport RayCastVehicle: public Joint
    {
		public:

		//! constructor
		RayCastVehicle(OgreNewt::Body* carBody, int maxTiresCount);

		//! destructor
		virtual ~RayCastVehicle();


		//! add and independent suspension tire to the car body
        /*
            The ray cast car does uses rigid bodies to simulates tires, therefore tire movement is no emergent physical behavior 
			instead is come for the interpretation for the empirical equations of the steady state tires curves.
            \param userData. a companion application data, usually a scene node for discrete vehicle, or a body node for single mesh vehicles.
            \param localPosition local orientation of the tire (in the space of the chassis rigid body)
            \param mass mass of the tire
			\param radius radis of the tire
            \param width width of the tire
			\param friction friction of the tire when  tire is spinning free.
            \param susShock spring damper coefficient
            \param susSpring spring strength
			\param susLength spring length
            \param useConvexCast when the tire use convex cats or ray cast
        */
		void AddSingleSuspensionTire (void *userData, const Ogre::Vector3& localPosition, 
									  Ogre::Real mass, Ogre::Real radius, Ogre::Real width, Ogre::Real friction,
									  Ogre::Real susLength, Ogre::Real susSpring, Ogre::Real susShock, bool useConvexCast = true);

		//! get current tire count
		int GetTiresCount() const;

		//! Method for setting the Visual matrix of the Node or Bone owning the geometry of this tire
		/*!
			the end application must define this function in order to set the transformation matrix for vehicle tires
			\param tireUserData Node or Bone controlling this tire
			\param transformMatrixInGlobalScape new transform in global scale
		*/
		virtual void setTireTransform (void* tireUserData, const Ogre::Matrix4& transformMatrixInGlobalScape) const {}


		//! show joint visual debugging data
		/*! 
			implement its own version of visual debugging
			\param debugRootNode root node for all debug display data
		*/
		virtual void showDebugData(Ogre::SceneNode* debugRootNode);


#if 0
        //! basic vehicle tire.
        /*!
            secondary class: Tire.  this represents a basic tire.  you add tires by simply creating new tire objects, they are attached to the vehicle object you pass to the constructor.
        */
        class _OgreNewtExport Tire
        {
        public:
            //! overloaded constructor.
            /*
                this is the all-important constructor.
                \param vehicle the parent vehicle to which you want to add this tire.
                \param localorient local orientation of the tire (in the space of the chassis rigid body)
                \param localpos local orientation of the tire (in the space of the chassis rigid body)
                \param pin direction of the pin (axle) in the space of the tire
                \param mass mass of the tire
                \param width width of the tire
                \param radius radis of the tire
                \param susShock spring damper coefficient
                \param susSpring spring strength
                \param susLength spring length
                \param colID collision ID used to determine collision in material callbacks.
            */
            Tire( OgreNewt::Vehicle* vehicle, Ogre::Quaternion localorient, Ogre::Vector3 localpos, Ogre::Vector3 pin,
                Ogre::Real mass, Ogre::Real width, Ogre::Real radius, Ogre::Real susShock, Ogre::Real susSpring, Ogre::Real susLength, int colID = 0);

            //! destructor.
            virtual ~Tire();

            //! attach a scenenode to the tire!
            void attachToNode( Ogre::SceneNode* node ) { m_node = node; }

            //! update the position of the tire.  this must be called to update the attached scene node to the position of the tire!
            void updateNode();

            //! get the Newton ID for this tire.
            const void* getNewtonID() const { return m_tireid; }

            //! get the parent vehicle.
            OgreNewt::Vehicle* getVehicle() const { return m_vehicle; }

            //! get Ogre::SceneNode.
            Ogre::SceneNode* getOgreNode() const { return m_node; }

            //////////////////////////////////////////////////////////////////////
            // Newton functions
            
            //! is the tire airborne?
            int isAirBorne() const { return NewtonVehicleTireIsAirBorne( m_vehicle->getNewtonVehicle(), m_tireid ); }

            //! has the tire lost side grip?
            int lostSideGrip() const { return NewtonVehicleTireLostSideGrip( m_vehicle->getNewtonVehicle(), m_tireid ); }

            //! has the tire lost traction?
            int lostTraction() const { return NewtonVehicleTireLostTraction( m_vehicle->getNewtonVehicle(), m_tireid ); }

            //! get the rotational velocity of the tire
            Ogre::Real getOmega() const { return (Ogre::Real)NewtonVehicleGetTireOmega( m_vehicle->getNewtonVehicle(), m_tireid ); }

            //! get the load on the tire (along the suspension normal )
            Ogre::Real getNormalLoad() const { return (Ogre::Real)NewtonVehicleGetTireNormalLoad( m_vehicle->getNewtonVehicle(), m_tireid ); }

            //! get the current steering angle for this tire
            Ogre::Radian getSteeringAngle() const { return Ogre::Radian( NewtonVehicleGetTireSteerAngle( m_vehicle->getNewtonVehicle(), m_tireid ) ); }

            //! get the lateral speed of the tire (sideways)
            Ogre::Real getLateralSpeed() const { return NewtonVehicleGetTireLateralSpeed( m_vehicle->getNewtonVehicle(), m_tireid ); }

            //! get the longitudinal speed of the tire (forward/backward)
            Ogre::Real getLongitudinalSpeed() const { return NewtonVehicleGetTireLongitudinalSpeed( m_vehicle->getNewtonVehicle(), m_tireid ); }

            //! get the location and orientation of the tire (in global space).
            void getPositionOrientation( Ogre::Quaternion& orient, Ogre::Vector3& pos );

            //! set the torque for this tire.  this must be called in the tire callback!
            void setTorque( Ogre::Real torque ) const { NewtonVehicleSetTireTorque( m_vehicle->getNewtonVehicle(), m_tireid, torque ); }

            //! set the steering angle for the tire.  this must be called in the tire callback.
            void setSteeringAngle( Ogre::Radian angle ) const { NewtonVehicleSetTireSteerAngle( m_vehicle->getNewtonVehicle(), m_tireid, angle.valueRadians() ); }

            //! calculate the max brake acceleration to stop the tires.
            Ogre::Real calculateMaxBrakeAcceleration() const { return (Ogre::Real)NewtonVehicleTireCalculateMaxBrakeAcceleration( m_vehicle->getNewtonVehicle(), m_tireid ); }

            //! set the brake acceleration
            void setBrakeAcceleration( Ogre::Real accel, Ogre::Real limit ) const { NewtonVehicleTireSetBrakeAcceleration( m_vehicle->getNewtonVehicle(), m_tireid, (float)accel, (float)limit ); }

            //! max side slip speed
            void setMaxSideSlipSpeed( Ogre::Real speed ) const { NewtonVehicleSetTireMaxSideSleepSpeed( m_vehicle->getNewtonVehicle(), m_tireid, (float)speed ); }

            //! set side slip coefficient
            void setSideSlipCoefficient( Ogre::Real coefficient ) const { NewtonVehicleSetTireSideSleepCoeficient( m_vehicle->getNewtonVehicle(), m_tireid, (float)coefficient ); }

            //! max longitudinal slip speed
            void setMaxLongitudinalSlipSpeed( Ogre::Real speed ) const { NewtonVehicleSetTireMaxLongitudinalSlideSpeed( m_vehicle->getNewtonVehicle(), m_tireid, (float)speed ); }

            //! set longitudinal slip coefficient
            void setLongitudinalSlipCoefficient( Ogre::Real coefficient ) const { NewtonVehicleSetTireLongitudinalSlideCoeficient( m_vehicle->getNewtonVehicle(), m_tireid, (float)coefficient ); }




        protected:
            OgreNewt::Vehicle* m_vehicle;
            void* m_tireid;

            Ogre::SceneNode* m_node;

        };


        //! constructor
        Vehicle() { m_vehicle = NULL; }

        //! destructor
        virtual ~Vehicle();

        //! initialize the vehicle
        /*!
            this function should be called to initialize the vehicle, assigning it's main chassis rigid body.  the function
            also calls the virtual function "setup" which the user should implement to add tires to the vehicle.
            \param chassis pointer to the OgreNewt::Body to use as the chassis.
            \param updir unit vector signifying which direction is "up" in your world.  used for suspension.
        */
        void init( OgreNewt::Body* chassis, const Ogre::Vector3& updir );

        //! destroy the vehicle, including chassis Body.
        void destroy(); 

        //! setup the tires.
        /*!
            this is a virtual function that must be implemented by the user.  you should add and balance all tires in this function.
        */
        virtual void setup() = 0;

        //! user callback for controlling the vehicle
        /*!
            callback called each frame.  inside this callback you can add torque and steering to the tires to control the vehicle.
        */
        virtual void userCallback() {}

        //! get the chassis body.
        OgreNewt::Body* getChassisBody() const { return m_chassis; }

        //! get the NewtonJoint for the vehicle.
        NewtonJoint* getNewtonVehicle()  const { return m_vehicle; }

        //////////////////////////////////////////////////////////////
        // Newton Vehicle functions.

        //! reset the vehicle (stop all tires)
        void reset() const { NewtonVehicleReset( m_vehicle ); }

        //! get a pointer to the first tire
        /*!
            This can be used with the getNextTire function to iterate through all tires in the vehicle.  see examples for more info.
            should only be called from inside the userCallback() function.
        */
        const OgreNewt::Vehicle::Tire* getFirstTire() const;

        //! get a pointer to the next tire in the vehicle.
        /*!
            This can be used with the getFirstTire function to iterate through all tires in the vehicle.  see examples for more info.
            should only be called from inside the userCallback() function.
        */
        const OgreNewt::Vehicle::Tire* getNextTire( OgreNewt::Vehicle::Tire* current_tire ) const;


    protected:

        OgreNewt::Body* m_chassis;

    private:
        //! callback for newton... it calls the userCallback() function for you.
        static void _CDECL newtonCallback( const NewtonJoint* me );

        static void _CDECL newtonDestructor( const NewtonJoint* me );

        NewtonJoint* m_vehicle;
#endif        
		protected:
		//! plug a transform notification callback to be called each time the body transformation is changed   
		/* 
			this function calculates the transformation of each of the tire relative to the parent body   
		*/
		void setTireTransformCallback (OgreNewt::Body* me);


		//! debug display information   
		struct DebugInfo 
		{
			void* m_tirePointer;
			Ogre::SceneNode* m_node;
			Ogre::ManualObject* m_visualDebug;
		};
		std::vector<DebugInfo> m_debugInfo;

    };


#endif


}   // end NAMESPACE OgreNewt




