#pragma once

class hkpVehicleTransmission : public hkReferencedObject
{
public:
};

class hkpVehicleDefaultTransmission : public hkpVehicleTransmission
{
public:
	/// The RPM of the engine the transmission shifts down.
	float m_downshiftRPM;

	/// The RPM of the engine the transmission shifts up. Note: m_upshiftRpm > m_downshiftRpm.
	float m_upshiftRPM;

	/// An extra factor to the gear ratio.
	float m_primaryTransmissionRatio;

	/// The time needed [seconds] to shift a gear.
	float m_clutchDelayTime;

	/// The back gear ratio.
	float m_reverseGearRatio;

	/// The ratio of the forward gears.
	hkArray<float> m_gearsRatio;

	/// The transmission ratio for every wheel
	hkArray<float> m_wheelsTorqueRatio;
};