#pragma once

class hkpVehicleTransmission : public hkReferencedObject
{
public:
	struct TransmissionOutput
	{
		f32 m_transmissionRPM;
		f32 m_mainTransmittedTorque;
		f32* m_wheelsTransmittedTorque;
		s8 m_numWheelsTramsmittedTorque;
		hkBool m_isReversing;
		s8 m_currentGear;
		hkBool m_delayed;
		f32 m_clutchDelayCountdown;
	};

	virtual void calcTransmission(const f32 deltaTime, const hkpVehicleInstance* vehicle, TransmissionOutput& transmissionOut) = 0;
};

class hkpVehicleDefaultTransmission : public hkpVehicleTransmission
{
public:
	f32 m_downshiftRPM;
	f32 m_upshiftRPM;
	f32 m_primaryTransmissionRatio;
	f32 m_clutchDelayTime;
	f32 m_reverseGearRatio;
	hkArray<f32> m_gearsRatio;
	hkArray<f32> m_wheelsTorqueRatio;
};