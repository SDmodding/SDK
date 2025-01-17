#pragma once

class hkpReorientAction : public hkpUnaryAction
{
public:
	hkVector4f m_rotationAxis;
	hkVector4f m_upAxis;
	f32 m_strength;
	f32 m_damping;
};