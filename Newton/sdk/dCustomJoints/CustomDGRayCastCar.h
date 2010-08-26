/* Copyright (c) <2009> <Newton Game Dynamics>
* 
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely
*/

// CustomDGRayCastCar.cpp: implementation of the CustomDGRayCastCar class.
// This raycast vehicle is currently a work in progress by Dave Gravel - 2009.
// Vehicle Raycast and convexCast Version 3.0b
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_CUSTOM_DGRAYCASTCAR_INCLUDED)
#define AFX_CUSTOM_DGRAYCASTCAR_INCLUDED

#include "NewtonCustomJoint.h"



// ray cast/convex cast contribution joint
class JOINTLIBRARY_API CustomDGRayCastCar: public NewtonCustomJoint  
{
public:

	struct NormalizeForceCurve
	{
		struct Node
		{
			dFloat m_slipRatio;
			dFloat m_normalizedForce;
		};

		NormalizeForceCurve ();
		~NormalizeForceCurve ();
		void InitalizeCurve (int points, dFloat* const steps, dFloat* const values);
		dFloat GetValue (dFloat param) const;

		dFloat GetMaxValue () const;

		int m_count;
		int m_maxCount;
		int m_optimalValue;
		Node* m_nodes;
	};

	struct Tire 
	{
		dVector m_localAxisInJointSpace;   // tire local axis of rotation 
		dVector m_harpointInJointSpace;	   // attachment point of this tire to the chassis 
		dVector m_contactPoint;			   // contact point in global space
		dVector m_contactNormal;           // contact normal in global space

		dVector m_tireForceAcc;			   // tire Force accumulator, due to suspension, tire toque, tire dynamics curves, and friction
		dVector m_tireAxelPositGlobal;	   // position of the tire center
		dVector m_tireAxelVelocGlobal;	   // linear velocity of tire center
		dVector m_lateralPinGlobal;		   // direction of the plane of rotation of the tire 
		dVector m_longitudinalPinGlobal;   // direction of motion of tire
		dVector m_hitBodyPointVelocity;    // instant velocity of the hit point at the Hit Body

		NewtonCollision* m_shape;          // collision shape of this tire 
		void* m_userData;                  // user data pointing to the visual tire
		NewtonBody* m_HitBody;			   // last rigid body the tire was over	
		
		dFloat m_posit;					   // parametric position for this tire (alway positive value between 0 and m_suspensionLength)
		dFloat m_suspensionLenght;		   // tire max spring suspension length 	
		dFloat m_spinAngle;                // current tire spin angle  
		dFloat m_steerAngle;               // current tire steering angle  
		dFloat m_springConst;			   // normalized spring Ks
		dFloat m_springDamper;			   // normalized spring Damper Kc
		dFloat m_angularVelocity;          // current tire spin velocity 
		dFloat m_breakForce;			   // tire break force
		dFloat m_torque;				   // tire toque
		dFloat m_groundFriction;		   // coefficient of friction of the ground surface
		dFloat m_tireLoad;				   // force generate by the suspension compression (must be alway positive)		
		dFloat m_mass;					   // tire Mass matrix
		dFloat m_width;					   // width of tire	
		dFloat m_radius;				   // tire Radius
		dFloat m_Ixx;					   // axis inertia
		dFloat m_IxxInv;                   // axis inertia
		dFloat m_rollingResistance;		   // coefficient of friction for tire rolling resistance
		int m_lateralForceIndex;
		int m_isBrakingForceIndex;
		int m_tireIsOnAir;				  // indicate of tire is airborne	
//		int m_tireIsConstrained;		  // indicate if the tire is in contact with the ground and rolling in constrained mode.	
		int	m_tireUseConvexCastMode;      // default to false (can be set to true for fast LOD cars)
	};


	CustomDGRayCastCar(int maxTireCount, const dMatrix& chassisMatrixInLocalSpace, NewtonBody* carBody);
	virtual ~CustomDGRayCastCar();

	dFloat GetSpeed() const;
	int GetTiresCount() const;

	Tire& GetTire (int index) const;
	dFloat GetTireParametricPosition (int index) const;
	dFloat GetTireRollingResistance (int index) const;
	dMatrix CalculateTireMatrix (int tire) const;
	dMatrix CalculateSuspensionMatrix (int tire, dFloat param) const;
	const dMatrix& GetChassisMatrixLocal () const;

	void SetTireBrake (int index, dFloat torque);
	void SetTireTorque (int index, dFloat torque);
	void SetTireSteerAngleForce (int index, dFloat angle, dFloat turnforce);

	// set and get the combined vehicle resistance to move due to tire rolling resistance, engine resistance, Transmit loses, etc
	void SetTireRollingResistance (int index, dFloat rollingResitanceCoeficicent);


	dFloat GenerateEngineTorque (dFloat value);
	dFloat GenerateTiresSteerAngle (dFloat value);
	dFloat GenerateTiresSteerForce (dFloat value);

	void AddSingleSuspensionTire (void* userData, const dVector& localPosition, 
								  dFloat mass, dFloat radius, dFloat with, dFloat friction, 
								  dFloat suspensionLenght, dFloat springConst, dFloat springDamper,	int castMode);

	void InitNormalizeTireLateralForce(int pointsCount, dFloat* const stepsAxis, dFloat* const normalizedForceValue)
	{
		m_normalizedLateralForce.InitalizeCurve(pointsCount, stepsAxis, normalizedForceValue);
	}

	void InitNormalizeTireLongitudinalForce (int pointsCount, dFloat* const stepsAxis, dFloat* const normalizedForceValue)
	{
		m_normalizedLongitudinalForce.InitalizeCurve(pointsCount, stepsAxis, normalizedForceValue);
	}

/*
	
	
	int GetVehicleOnAir() const;
	int GetTireOnAir(int index) const;
	
	

	virtual void SetBrake (dFloat torque);
	virtual void SetTorque (dFloat torque);
	virtual void SetSteering (dFloat angle);



	void SetTireMaxRPS (int tireIndex, dFloat maxTireRPS);


	const NewtonCollision* GetTiresShape (int tireIndex) const;
	

	//
	void SetVarTireMovePointForceFront (int index, dFloat distance);
	void SetVarTireMovePointForceRight (int index, dFloat distance);
	void SetVarTireMovePointForceUp (int index, dFloat distance);
	//
	void SetVarFixDeceleration (dFloat value);
	void SetVarChassisRotationLimit (dFloat value);
	void SetVarMaxSteerAngle (dFloat value);
	void SetVarMaxSteerRate (dFloat value);
	void SetVarMaxSteerForceRate (dFloat value);
	void SetVarMaxSteerForce (dFloat value);
	void SetVarMaxSteerSpeedRestriction (dFloat value);
	void SetVarMaxBrakeForce (dFloat value);
	void SetVarMaxTorque (dFloat value);
	void SetVarMaxTorqueRate (dFloat value);
	void SetVarEngineSteerDiv (dFloat value);
	void SetVarTireSuspenssionHardLimit (int index, dFloat value);
	void SetVarTireFriction (int index, dFloat value);
*/
protected:

	dFloat CalculateLongitudinalForce (int tireIndex, dFloat hubSpeed, dFloat tireLoad) const;

	static unsigned ConvexCastPrefilter(const NewtonBody* body, const NewtonCollision* collision, void* userData);
//	dFloat CalculateNormalizeForceVsSlipAngle (const Tire& tire, float slipAngle) const;
	void CalculateTireCollision (Tire& tire, const dMatrix& tireMatrix, int threadIndex) const;
	
//	static void IntegrateTires (const NewtonJoint* userJoint, dFloat timestep, int threadIndex);
//	void IntegrateTires (dFloat timestep, int threadIndex);

//	virtual void GetInfo (NewtonJointRecord* info) const;

	virtual void SubmitConstraints (dFloat timestep, int threadIndex);

	dMatrix m_localFrame;			// local coordinate system of the vehicle
	NormalizeForceCurve m_normalizedLateralForce;
	NormalizeForceCurve m_normalizedLongitudinalForce;

	Tire* m_tires;					// tires array
	int m_vehicleOnAir;				// indicate if the vehicle is flying or not
	int m_tiresCount;				// current number of tires
	dFloat m_mass;					// case chassis mass
	dFloat m_curSpeed;				// car current speed;
	dFloat m_steerAngle;
	dFloat m_maxSteerAngle;
	dFloat m_maxSteerRate;
	dFloat m_engineSteerDiv;
	dFloat m_maxSteerForce;
	dFloat m_maxBrakeForce;
	dFloat m_maxSteerForceRate;				
	dFloat m_maxSteerSpeedRestriction;
};

#endif
