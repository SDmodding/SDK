#pragma once

class hkpVehicleInstance : public hkpUnaryAction
{
public:
	hkpVehicleData* m_data;
	hkpVehicleDriverInput* m_driverInput;
	hkpVehicleSteering* m_steering;
	hkpVehicleEngine* m_engine;
	hkpVehicleTransmission* m_transmission;
	hkpVehicleBrake* m_brake;
	hkpVehicleSuspension* m_suspension;
	hkpVehicleAerodynamics* m_aerodynamics;
	hkpVehicleWheelCollide* m_wheelCollide;
	hkpTyremarksInfo* m_tyreMarks;
	hkpVehicleVelocityDamper* m_velocityDamper;
	hkpVehicleSimulation* m_vehicleSimulation;

	struct WheelInfo
	{
		hkContactPoint m_contactPoint;
		float m_contactFriction;
		hkpRigidBody* m_contactBody;
		unsigned int m_contactShapeKey[8];
		hkVector4f m_hardPointWs;
		hkVector4f m_rayEndPointWs;
		float m_currentSuspensionLength;
		hkVector4f m_suspensionDirectionWs;
		hkVector4f m_spinAxisChassisSpace;
		hkVector4f m_spinAxisWs;
		hkQuaternionf m_steeringOrientationChassisSpace;
		float m_spinVelocity;
		float m_noSlipIdealSpinVelocity;
		float m_spinAngle;
		float m_skidEnergyDensity;
		float m_sideForce;
		float m_forwardSlipVelocity;
		float m_sideSlipVelocity;
	};
	hkArray<WheelInfo> m_wheelsInfo;

	hkpVehicleDriverInputStatus* m_deviceStatus;
	hkArray<bool> m_isFixed;
	float m_wheelsTimeSinceMaxPedalInput;
	bool m_tryingToReverse;
	float m_torque;
	float m_rpm;
	float m_mainSteeringAngle;
	float m_mainSteeringAngleAssumingNoReduction;
	hkArray<float> m_wheelsSteeringAngle;
	bool m_isReversing;
	int8_t m_currentGear;
	bool m_delayed;
	float m_clutchDelayCountdown;

	__inline float CalcKMPH()
	{
		return reinterpret_cast<float(__fastcall*)(void*)>(UFG_RVA(0xE27510))(this);
	}

	__inline float CalcMPH()
	{
		return reinterpret_cast<float(__fastcall*)(void*)>(UFG_RVA(0xE27590))(this);
	}
};