#include "OgreNewt_stdafx.h"
#include "OgreNewt_World.h"
#include "OgreNewt_Body.h"
#include "OgreNewt_BasicJoints.h"

#include "CustomHinge.h"
#include "CustomSlider.h"
#include "CustomBallAndSocket.h"
#include "CustomUpVector.h"
#include "CustomKinematicController.h"

#ifdef __APPLE__
#   include <Ogre/OgreLogManager.h>
#   include <Ogre/OgreStringConverter.h>
#else
#   include <OgreLogManager.h>
#   include <OgreStringConverter.h>
#endif




namespace OgreNewt
{


BallAndSocket::BallAndSocket( const OgreNewt::Body* child, const OgreNewt::Body* parent, const Ogre::Vector3& pos ) : Joint()
{
	NewtonCustomJoint* suppportJoint;

	// make the joint matrix 
	dMatrix pinsAndPivoFrame (GetIdentityMatrix());
	pinsAndPivoFrame.m_posit = dVector (pos.x, pos.y, pos.z, 1.0f);

	// crate a Newton Custom joint and set it at the support joint	
	suppportJoint = new CustomBallAndSocket(pinsAndPivoFrame, child->getNewtonBody(), parent ? parent->getNewtonBody() : NULL);
	SetSupportJoint(suppportJoint);
}

BallAndSocket::~BallAndSocket()
{
    // nothing, the ~Joint() function will take care of us.
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
Hinge::Hinge (const OgreNewt::Body* child, const OgreNewt::Body* parent, const Ogre::Vector3& pos, const Ogre::Vector3& pin ) : Joint()
{
	NewtonCustomJoint* suppportJoint;

	// make the joint matrix 
	dVector dir (pin.x, pin.y, pin.z, 0.0f);
	dMatrix pinsAndPivoFrame (dgGrammSchmidt(dir));
	pinsAndPivoFrame.m_posit = dVector (pos.x, pos.y, pos.z, 1.0f);

	// crate a Newton Custom joint and set it at the support joint	
	suppportJoint = new CustomHinge (pinsAndPivoFrame, child->getNewtonBody(), parent ? parent->getNewtonBody() : NULL);
	SetSupportJoint(suppportJoint);

	m_constraintType = CONSTRAINT_NONE;
	m_lastConstraintType = CONSTRAINT_NONE;
	m_desiredOmega = 0.0f;
	m_desiredAngle = 0.0f;
	m_motorStrength = 0.5f;
	m_motorTorque = 0.0f;
	m_motorMinFriction = 0.0f;
	m_motorMaxFriction = 0.0f;
	m_brakeMaxForce = 0.0f;
}

Hinge::~Hinge()
{
}


void Hinge::enableLimits(bool state)
{
	CustomHinge* joint = (CustomHinge*) GetSupportJoint();
	joint->EnableLimits(state);
}


void Hinge::setLimits(Ogre::Radian minAngle, Ogre::Radian maxAngle)
{
	CustomHinge* joint = (CustomHinge*) GetSupportJoint();

	joint->SetLimis(minAngle.valueRadians(), maxAngle.valueRadians());
}

void Hinge::setDesiredOmega(Ogre::Radian omega, Ogre::Real strength)
{
	m_desiredOmega = omega;
	m_motorStrength = strength;
	
	m_constraintType = CONSTRAINT_OMEGA;
}

void Hinge::setTorque(Ogre::Real torque)
{
	m_motorTorque = torque;
	m_desiredOmega = 0.0f;
	
	m_torqueOn = true;
}

void Hinge::setDesiredAngle(Ogre::Radian angle, Ogre::Real minFriction, Ogre::Real maxFriction)
{
	m_desiredAngle = angle;
	m_motorMinFriction = minFriction;
	m_motorMaxFriction = maxFriction;
	
	m_constraintType = CONSTRAINT_ANGLE;
}

void Hinge::setBrake(Ogre::Real maxForce)
{
	m_brakeMaxForce = maxForce;
	m_constraintType = CONSTRAINT_BRAKE;
}

Ogre::Radian Hinge::getJointAngle () const
{
	CustomHinge* joint = (CustomHinge*) GetSupportJoint();

	return Ogre::Radian(joint->GetJointAngle());
}

Ogre::Radian Hinge::getJointAngularVelocity () const
{
	CustomHinge* joint = (CustomHinge*) GetSupportJoint();

	return Ogre::Radian(joint->GetJointOmega());
}

Ogre::Vector3 Hinge::getJointPin () const
{
	CustomHinge* joint = (CustomHinge*) GetSupportJoint();
	dVector pin (joint->GetPinAxis());

	return Ogre::Vector3 (pin.m_x, pin.m_y, pin.m_z);

}

void Hinge::submitConstraint(Ogre::Real timestep, int threadindex)
{
	if (m_constraintType == CONSTRAINT_BRAKE)
	{
		Ogre::Vector3 pin (getJointPin());
		
		addAngularRow (Ogre::Radian(0), pin);
		setRowStiffness(1.0f);

		if (m_brakeMaxForce > 0.0f)
		{
			setRowMinimumFriction(-m_brakeMaxForce);
			setRowMaximumFriction(m_brakeMaxForce);
		}
	}
	else if (m_constraintType == CONSTRAINT_OMEGA)
	{
		Ogre::Radian relativeOmega = (m_desiredOmega - getJointAngularVelocity()) * m_motorStrength;

		Ogre::Real acceleration = relativeOmega.valueRadians() / timestep;
		Ogre::Vector3 pin (getJointPin());

		addAngularRow (Ogre::Radian (0.0f), pin);
		setRowAcceleration (acceleration);
	}
	else if (m_constraintType == CONSTRAINT_ANGLE)
	{
		Ogre::Radian relativeAngle = getJointAngle() - m_desiredAngle;

		Ogre::Vector3 pin (getJointPin());
		
		addAngularRow (relativeAngle, pin);
		setRowStiffness(1.0f);

		if (m_motorMinFriction < 0.0f)
		{
			setRowMinimumFriction(m_motorMinFriction);
		}
		
		if (m_motorMaxFriction > 0.0f)
		{
			setRowMaximumFriction(m_motorMaxFriction);
		}
	}

	if (m_torqueOn)
	{
		if (getBody0() != NULL)
		{
			Ogre::Vector3 pin (getJointPin());

			getBody0()->addTorque(pin * m_motorTorque);

			if (getBody1() != NULL)
			{
				getBody1()->addTorque(pin * -m_motorTorque);
			}
		}
	}

	m_lastConstraintType = m_constraintType;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////



Slider::Slider(const OgreNewt::Body* child, const OgreNewt::Body* parent, const Ogre::Vector3& pos, const Ogre::Vector3& pin ) : Joint()
{
	NewtonCustomJoint* suppportJoint;

	// make the joint matrix 
	dVector dir (pin.x, pin.y, pin.z, 0.0f);
	dMatrix pinsAndPivoFrame (dgGrammSchmidt(dir));
	pinsAndPivoFrame.m_posit = dVector (pos.x, pos.y, pos.z, 1.0f);

	// crate a Newton Custom joint and set it at the support joint	
	suppportJoint = new CustomSlider (pinsAndPivoFrame, child->getNewtonBody(), parent ? parent->getNewtonBody() : NULL);
	SetSupportJoint(suppportJoint);
}

Slider::~Slider()
{
}


void Slider::enableLimits(bool state)
{
	CustomSlider* joint = (CustomSlider*) GetSupportJoint();
	joint->EnableLimits(state);
}


void Slider::setLimis(Ogre::Real minStopDist, Ogre::Real maxStopDist)
{
	CustomSlider* joint = (CustomSlider*) GetSupportJoint();
	joint->SetLimis(minStopDist, maxStopDist);
}


UpVector::UpVector( const Body* body, const Ogre::Vector3& pin ) : Joint() ,m_pin(pin.normalisedCopy())
{
   dVector dPin(m_pin.x, m_pin.y, m_pin.z, 1.0f);
   CustomUpVector* support_joint = new CustomUpVector(dPin, body->getNewtonBody());
   SetSupportJoint(support_joint);
}

UpVector::~UpVector()
{
}

void UpVector::setPin( const Ogre::Vector3& pin )
{
   CustomUpVector* up_vector = static_cast<CustomUpVector*>(m_joint);
   m_pin = pin.normalisedCopy();
   dVector dPin(m_pin.x, m_pin.y, m_pin.z, 1.0f);
   up_vector->SetPinDir(dPin);
}

const Ogre::Vector3& UpVector::getPin() const
{
   return m_pin;
}


KinematicController::KinematicController(const OgreNewt::Body* child, const Ogre::Vector3& pos)
{
	NewtonCustomJoint* suppportJoint;

	// make the joint matrix 
	dVector attachement (pos.x, pos.y, pos.z, 0.0f);

	// crate a Newton Custom joint and set it at the support joint	
	suppportJoint = new CustomKinematicController (child->getNewtonBody(), attachement);
	SetSupportJoint(suppportJoint);
}

KinematicController::~KinematicController()
{
}

void KinematicController::setPickingMode (int mode)
{
	CustomKinematicController* joint = (CustomKinematicController*) GetSupportJoint();
	joint->SetPickMode(mode);
}

void KinematicController::setMaxLinearFriction(dFloat accel)
{
	CustomKinematicController* joint = (CustomKinematicController*) GetSupportJoint();
	joint->SetMaxLinearFriction(accel);
}

void KinematicController::setMaxAngularFriction(dFloat alpha)
{
	CustomKinematicController* joint = (CustomKinematicController*) GetSupportJoint();
	joint->SetMaxAngularFriction(alpha);
}


void KinematicController::setTargetPosit (const Ogre::Vector3& position)
{
	dVector posit (position.x, position.y, position.z, 0.0f);
	CustomKinematicController* joint = (CustomKinematicController*) GetSupportJoint();
	joint->SetTargetPosit(posit);
}

void KinematicController::setTargetRotation (const Ogre::Quaternion& rotation)
{
	dQuaternion rotat (rotation.w, rotation.x, rotation.y, rotation.z) ;

	CustomKinematicController* joint = (CustomKinematicController*) GetSupportJoint();
	joint->SetTargetRotation(rotat);
}


void KinematicController::setTargetMatrix (const Ogre::Vector3& position, const Ogre::Quaternion& rotation)
{
	dMatrix matrix;
	OgreNewt::Converters::QuatPosToMatrix (rotation, position, &matrix[0][0]);
	
	CustomKinematicController* joint = (CustomKinematicController*) GetSupportJoint();
	joint->SetTargetMatrix(matrix);
}

void KinematicController::getTargetMatrix (Ogre::Vector3& position, Ogre::Quaternion& rotation) const
{
	CustomKinematicController* joint = (CustomKinematicController*) GetSupportJoint();
	dMatrix matrix (joint->GetTargetMatrix());

	OgreNewt::Converters::MatrixToQuatPos (&matrix[0][0], rotation, position);
}



#if 0
Ogre::Vector3 Slider::getJointForce() const
{
    Ogre::Vector3 ret;

    NewtonSliderGetJointForce( m_joint, &ret.x );

    return ret;
}

unsigned _CDECL Slider::newtonCallback( const NewtonJoint* slider, NewtonHingeSliderUpdateDesc* desc )
{
    Slider* me = (Slider*)NewtonJointGetUserData( slider );

    me->m_desc = desc;
    me->m_retval = 0;

    if (me->m_callback)
        (*me->m_callback)( me );

    me->m_desc = NULL;

    return me->m_retval;
}


/////// CALLBACK FUNCTIONS ///////
void Slider::setCallbackAccel( Ogre::Real accel )
{
    if (m_desc)
    {
        m_retval = 1;
        m_desc->m_accel = (float)accel;
    }
}

void Slider::setCallbackFrictionMin( Ogre::Real min )
{
    if (m_desc)
    {
        m_retval = 1;
        m_desc->m_minFriction = (float)min;
    }
}

void Slider::setCallbackFrictionMax( Ogre::Real max )
{
    if (m_desc)
    {
        m_retval = 1;
        m_desc->m_maxFriction = (float)max;
    }
}

Ogre::Real Slider::getCallbackTimestep() const
{
    if (m_desc)
        return (Ogre::Real)m_desc->m_timestep;
    else
        return 0.0;
}

Ogre::Real Slider::calculateStopAccel( Ogre::Real dist ) const
{
    if (m_desc)
        return (Ogre::Real)NewtonSliderCalculateStopAccel( m_joint, m_desc, (float)dist );
    else
        return 0.0;
}



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////



Universal::Universal( const World* world, const OgreNewt::Body* child, const OgreNewt::Body* parent, const Ogre::Vector3& pos, const Ogre::Vector3& pin0, const Ogre::Vector3& pin1 ) : Joint()
{
    m_world = world;

    if (parent)
    {
        m_joint = NewtonConstraintCreateUniversal( world->getNewtonWorld(), &pos.x, &pin0.x, &pin1.x,
                                                child->getNewtonBody(), parent->getNewtonBody() );
    }
    else
    {
        m_joint = NewtonConstraintCreateUniversal( world->getNewtonWorld(), &pos.x, &pin0.x, &pin1.x,
                                                child->getNewtonBody(), NULL );
    }

    NewtonJointSetUserData( m_joint, this );
    NewtonJointSetDestructor( m_joint, destructor );
    NewtonUniversalSetUserCallback( m_joint, newtonCallback );

    m_callback = NULL;
}

Universal::~Universal()
{
}

Ogre::Vector3 Universal::getJointForce() const
{
    Ogre::Vector3 ret;

    NewtonUniversalGetJointForce( m_joint, &ret.x );

    return ret;
}

unsigned _CDECL Universal::newtonCallback( const NewtonJoint* universal, NewtonHingeSliderUpdateDesc* desc )
{
    Universal* me = (Universal*)NewtonJointGetUserData( universal );

    me->m_desc = desc;
    me->m_retval = 0;

    if (me->m_callback)
        (*me->m_callback)( me );

    me->m_desc = NULL;

    return me->m_retval;
}


/////// CALLBACK FUNCTIONS ///////
void Universal::setCallbackAccel( Ogre::Real accel, unsigned int axis )
{
    if (axis > 1) { return; }

    if (m_desc)
    {
        m_retval |= axis;
        m_desc[axis].m_accel = (float)accel;
    }
}

void Universal::setCallbackFrictionMax( Ogre::Real max, unsigned int axis )
{
    if (axis > 1) { return; }

    if (m_desc)
    {
        m_retval |= axis;
        m_desc[axis].m_maxFriction = (float)max;
    }
}

void Universal::setCallbackFrictionMin( Ogre::Real min, unsigned int axis )
{
    if (axis > 1) { return; }

    if (m_desc)
    {
        m_retval |= axis;
        m_desc[axis].m_minFriction = (float)min;
    }
}

Ogre::Real Universal::getCallbackTimestep() const
{
    if (m_desc)
        return (Ogre::Real)m_desc->m_timestep;
    else
        return 0.0;
}

Ogre::Real Universal::calculateStopAlpha0( Ogre::Real angle ) const
{
    if (m_desc)
        return (Ogre::Real)NewtonUniversalCalculateStopAlpha0( m_joint, m_desc, (float)angle );
    else
        return 0.0;
}

Ogre::Real Universal::calculateStopAlpha1( Ogre::Real angle ) const
{
    if (m_desc)
        return (Ogre::Real)NewtonUniversalCalculateStopAlpha1( m_joint, m_desc, (float)angle );
    else
        return 0.0;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////



UpVector::UpVector( const World* world, const Body* body, const Ogre::Vector3& pin )
{
    m_world = world;

    m_joint = NewtonConstraintCreateUpVector( world->getNewtonWorld(), &pin.x, body->getNewtonBody() );

    NewtonJointSetUserData( m_joint, this );
    NewtonJointSetDestructor( m_joint, destructor );

}

UpVector::~UpVector()
{
}

Ogre::Vector3 UpVector::getPin() const
{
    Ogre::Vector3 ret;

    NewtonUpVectorGetPin( m_joint, &ret.x );

    return ret;
}


#endif







#if 0

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


namespace PrebuiltCustomJoints
{

Custom2DJoint::Custom2DJoint(const OgreNewt::Body* body, const Ogre::Vector3& pin ) : CustomJoint( 4, body, NULL )
{
    mPin = pin;
    Ogre::Quaternion bodyorient;
    Ogre::Vector3 bodypos;

    body->getPositionOrientation( bodypos, bodyorient );

    pinAndDirToLocal( bodypos, pin, mLocalOrient0, mLocalPos0, mLocalOrient1, mLocalPos1 );

    // initialize variables
    mMin = mMax = Ogre::Degree(0);
    mLimitsOn = false;
    mAccel = 0.0f;

}


void Custom2DJoint::submitConstraint( Ogre::Real timeStep, int threadIndex )
{
    // get the global orientations.
    Ogre::Quaternion globalOrient0, globalOrient1;
    Ogre::Vector3 globalPos0, globalPos1;

    localToGlobal( mLocalOrient0, mLocalPos0, globalOrient0, globalPos0, 0 );
    localToGlobal( mLocalOrient1, mLocalPos1, globalOrient1, globalPos1, 1 );

    // calculate all main 6 vectors.
    Ogre::Vector3 bod0X = globalOrient0 * Ogre::Vector3( Ogre::Vector3::UNIT_X );
    Ogre::Vector3 bod0Y = globalOrient0 * Ogre::Vector3( Ogre::Vector3::UNIT_Y );
    Ogre::Vector3 bod0Z = globalOrient0 * Ogre::Vector3( Ogre::Vector3::UNIT_Z );
    
    Ogre::Vector3 bod1X = globalOrient1 * Ogre::Vector3( Ogre::Vector3::UNIT_X );
    Ogre::Vector3 bod1Y = globalOrient1 * Ogre::Vector3( Ogre::Vector3::UNIT_Y );
    Ogre::Vector3 bod1Z = globalOrient1 * Ogre::Vector3( Ogre::Vector3::UNIT_Z );

#ifdef _DEBUG
    Ogre::LogManager::getSingletonPtr()->logMessage(" Submit Constraint   bod0X:"+Ogre::StringConverter::toString( bod0X )+
        "   bod1X:"+Ogre::StringConverter::toString( bod1X ) );
#endif
    
    // ---------------------------------------------------------------
    // first add a linear row to keep the body on the plane.
    addLinearRow( globalPos0, globalPos1, bod0X );

    // have we strayed from the plane along the normal?
    Ogre::Plane thePlane( bod0X, globalPos0 );
    Ogre::Real stray = thePlane.getDistance( globalPos1 );
    if (stray > 0.0001f)
    {
        // we have strayed, apply acceleration to move back to 0 in one timestep.
        Ogre::Real accel = (stray / timeStep);
        if (thePlane.getSide( globalPos1 ) == Ogre::Plane::NEGATIVE_SIDE) { accel = -accel; }

        setRowAcceleration( accel );
    }

    // see if the main axis (pin) has wandered off.
    Ogre::Vector3 latDir = bod0X.crossProduct( bod1X );
    Ogre::Real latMag = latDir.squaredLength();

    if (latMag > 1.0e-6f)
    {
        // has wandered a bit, we need to correct.  first find the angle off.
        latMag = Ogre::Math::Sqrt( latMag );
        latDir.normalise();
        Ogre::Radian angle = Ogre::Math::ASin( latMag );

        // ---------------------------------------------------------------
        addAngularRow( angle, latDir );

        // ---------------------------------------------------------------
        // secondary correction for stability.
        Ogre::Vector3 latDir2 = latDir.crossProduct( bod1X );
        addAngularRow( Ogre::Radian(0.0f), latDir2 );
    }
    else
    {
        // ---------------------------------------------------------------
        // no major change, just add 2 simple constraints.
        addAngularRow( Ogre::Radian(0.0f), bod1Y );
        addAngularRow( Ogre::Radian(0.0f), bod1Z );
    }

    // calculate the current angle.
    Ogre::Real cos = bod0Y.dotProduct( bod1Y );
    Ogre::Real sin = (bod0Y.crossProduct( bod1Y )).dotProduct( bod0X );

    mAngle = Ogre::Math::ATan2( sin, cos );

    if (mLimitsOn)
    {
        if (mAngle > mMax)
        {
            Ogre::Radian diff = mAngle - mMax;

            addAngularRow( diff, bod0X );
            setRowStiffness( 1.0f );
        }
        else if (mAngle < mMin)
        {
            Ogre::Radian diff = mAngle - mMin;

            addAngularRow( diff, bod0X );
            setRowStiffness( 1.0f );
        }
    }
    else
    {
        if (mAccel != 0.0f)
        {
            addAngularRow( Ogre::Radian(0.0f), bod0X );
            setRowAcceleration( mAccel );

            mAccel = 0.0f;
        }
    }
    
}


CustomRigidJoint::CustomRigidJoint(OgreNewt::Body *child, OgreNewt::Body *parent, Ogre::Vector3 dir, Ogre::Vector3 pos) : OgreNewt::CustomJoint(6,child,parent)
{
    // calculate local offsets.
    pinAndDirToLocal( pos, dir, mLocalOrient0, mLocalPos0, mLocalOrient1, mLocalPos1 );
}

CustomRigidJoint::~CustomRigidJoint()
{
}

void CustomRigidJoint::submitConstraint( Ogre::Real timeStep, int threadIndex )
{
    // get globals.
    Ogre::Vector3 globalPos0, globalPos1;
    Ogre::Quaternion globalOrient0, globalOrient1;

    localToGlobal( mLocalOrient0, mLocalPos0, globalOrient0, globalPos0, 0 );
    localToGlobal( mLocalOrient1, mLocalPos1, globalOrient1, globalPos1, 1 );

    // apply the constraints!
    addLinearRow( globalPos0, globalPos1, globalOrient0 * Ogre::Vector3::UNIT_X );
    addLinearRow( globalPos0, globalPos1, globalOrient0 * Ogre::Vector3::UNIT_Y );
    addLinearRow( globalPos0, globalPos1, globalOrient0 * Ogre::Vector3::UNIT_Z );

    // now find a point off 10 units away.
    globalPos0 = globalPos0 + (globalOrient0 * (Ogre::Vector3::UNIT_X * 10.0f));
    globalPos1 = globalPos1 + (globalOrient1 * (Ogre::Vector3::UNIT_X * 10.0f));

    // apply the constraints!
    addLinearRow( globalPos0, globalPos1, globalOrient0 * Ogre::Vector3::UNIT_Y );
    addLinearRow( globalPos0, globalPos1, globalOrient0 * Ogre::Vector3::UNIT_Z );

    Ogre::Vector3 xdir0 = globalOrient0 * Ogre::Vector3::UNIT_X;
    Ogre::Vector3 xdir1 = globalOrient1 * Ogre::Vector3::UNIT_X;

    Ogre::Radian angle = Ogre::Math::ACos( xdir0.dotProduct( xdir1 ) );
    addAngularRow( angle, globalOrient0 * Ogre::Vector3::UNIT_X );
}

/*
CustomDryRollingFriction::CustomDryRollingFriction( OgreNewt::Body* child, Ogre::Real radius, Ogre::Real rollingFrictionCoefficient ) :
    OgreNewt::CustomJoint(1, child, NULL),
    mChild(child)
{
    Ogre::Real mass;
    Ogre::Vector3 inertia;

    child->getMassMatrix( mass, inertia );

    mFrictionCoefficient =  rollingFrictionCoefficient;
    mFrictionTorque = inertia.x * radius;
}

CustomDryRollingFriction::~CustomDryRollingFriction()
{
}


// copied from CustomDryRollingFriction joint in newton
void CustomDryRollingFriction::submitConstraint( Ogre::Real timestep, int threadIndex )
{
    Ogre::Vector3 omega;
    Ogre::Real omegaMag;
    Ogre::Real torqueFriction;


    omega = mChild->getOmega();
    omegaMag = omega.length();

    if( omegaMag > 0.1f )
    {
        addAngularRow(Ogre::Radian(0), omega.normalisedCopy());
        setRowAcceleration( -omegaMag/timestep );
        torqueFriction = mFrictionTorque*mFrictionCoefficient;
        setRowMinimumFriction(-torqueFriction);
        setRowMaximumFriction(torqueFriction);
    }
    else
    {
        mChild->setOmega(omega*0.2f);
    }

}
*/


}   // end NAMESPACE PrebuiltCustomJoints


#endif


}   // end NAMESPACE OgreNewt

