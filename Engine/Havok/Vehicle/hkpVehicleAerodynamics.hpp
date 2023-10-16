#pragma once

class hkpVehicleAerodynamics : public hkReferencedObject
{
public:

};

class hkpVehicleDefaultAerodynamics : public hkpVehicleAerodynamics
{
public:
	/// The density of the air that surrounds the vehicle, usually, 1.3 kg/m3.
	float m_airDensity;

	/// The frontal area, in m2, of the car.
	float m_frontalArea;

	/// The drag coefficient of the car.
	float m_dragCoefficient;

	/// The lift coefficient of the car (it can be either positive or negative).
	float m_liftCoefficient;

	/// An extra, fictional (non-physical) gravity force, to be applied to the body.
	hkVector4f m_extraGravityws;
};