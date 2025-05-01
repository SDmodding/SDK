#pragma once

class hkpVehicleInstance : public hkpUnaryAction
{
public:
	struct WheelInfo
	{
		hkContactPoint m_contactPoint;
		f32 m_contactFriction;
		hkpRigidBody* m_contactBody;
		u32 m_contactShapeKey[8];
		hkVector4f m_hardPointWs;
		hkVector4f m_rayEndPointWs;
		f32 m_currentSuspensionLength;
		hkVector4f m_suspensionDirectionWs;
		hkVector4f m_spinAxisChassisSpace;
		hkVector4f m_spinAxisWs;
		hkQuaternionf m_steeringOrientationChassisSpace;
		f32 m_spinVelocity;
		f32 m_noSlipIdealSpinVelocity;
		f32 m_spinAngle;
		f32 m_skidEnergyDensity;
		f32 m_sideForce;
		f32 m_forwardSlipVelocity;
		f32 m_sideSlipVelocity;
	};

	class hkpVehicleData* m_data;
	class hkpVehicleDriverInput* m_driverInput;
	class hkpVehicleSteering* m_steering;
	class hkpVehicleEngine* m_engine;
	class hkpVehicleTransmission* m_transmission;
	class hkpVehicleBrake* m_brake;
	class hkpVehicleSuspension* m_suspension;
	class hkpVehicleAerodynamics* m_aerodynamics;
	hkpVehicleWheelCollide* m_wheelCollide;
	class hkpTyremarksInfo* m_tyreMarks;
	class hkpVehicleVelocityDamper* m_velocityDamper;
	class hkpVehicleSimulation* m_vehicleSimulation;
	hkArray<WheelInfo> m_wheelsInfo;
	class hkpVehicleDriverInputStatus* m_deviceStatus;
	hkArray<hkBool> m_isFixed;
	f32 m_wheelsTimeSinceMaxPedalInput;
	hkBool m_tryingToReverse;
	f32 m_torque;
	f32 m_rpm;
	f32 m_mainSteeringAngle;
	f32 m_mainSteeringAngleAssumingNoReduction;
	hkArray<f32> m_wheelsSteeringAngle;
	hkBool m_isReversing;
	s8 m_currentGear;
	hkBool m_delayed;
	f32 m_clutchDelayCountdown;
};