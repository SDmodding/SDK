#pragma once

class hkpVehicleData : public hkReferencedObject
{
public:
	struct WheelComponentParams
	{
		f32 m_radius;
		f32 m_mass;
		f32 m_width;
		f32 m_friction;
		f32 m_viscosityFriction;
		f32 m_maxFriction;
		f32 m_slipAngle;
		f32 m_forceFeedbackMultiplier;
		f32 m_maxContactBodyAcceleration;
		i8 m_axle;
	};

	hkVector4f m_gravity;
	i8 m_numWheels;
	hkRotationf m_chassisOrientation;
	f32 m_torqueRollFactor;
	f32 m_torquePitchFactor;
	f32 m_torqueYawFactor;
	f32 m_extraTorqueFactor;
	f32 m_maxVelocityForPositionalFriction;
	f32 m_chassisUnitInertiaYaw;
	f32 m_chassisUnitInertiaRoll;
	f32 m_chassisUnitInertiaPitch;
	f32 m_frictionEqualizer;
	f32 m_normalClippingAngleCos;
	f32 m_maxFrictionSolverMassRatio;
	hkArray<WheelComponentParams> m_wheelParams;
	hkArray<i8> m_numWheelsPerAxle;
	hkVector4f m_chassisFrictionInertiaInvDiag;
	hkBool m_alreadyInitialised;
};