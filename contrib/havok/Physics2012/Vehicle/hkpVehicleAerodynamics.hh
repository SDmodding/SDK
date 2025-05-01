#pragma once

class hkpVehicleAerodynamics : public hkReferencedObject
{
public:
	struct AerodynamicsDragOutput
	{
		hkVector4f m_aerodynamicsForce;
		hkVector4f m_aerodynamicsTorque;
	};

	virtual void calcAerodynamics(const f32 deltaTime, const hkpVehicleInstance* vehicle, AerodynamicsDragOutput& dragInfoOut) = 0;
};

class hkpVehicleDefaultAerodynamics : public hkpVehicleAerodynamics
{
public:
	f32 m_airDensity;
	f32 m_frontalArea;
	f32 m_dragCoefficient;
	f32 m_liftCoefficient;
	hkVector4f m_extraGravityws;
};