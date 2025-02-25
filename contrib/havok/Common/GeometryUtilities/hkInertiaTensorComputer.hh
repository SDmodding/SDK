#pragma once

struct hkMassProperties
{
	f32 m_volume;
	f32 m_mass;
	hkVector4f m_centerOfMass;
	hkMatrix3f m_inertiaTensor;
};

struct hkMassElement
{
	hkMassProperties m_properties;
	hkTransformf m_transform;
};

class hkInertiaTensorComputer
{
public:
};