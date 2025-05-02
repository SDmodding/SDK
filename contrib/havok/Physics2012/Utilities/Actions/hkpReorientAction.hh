#pragma once

class hkpReorientAction : public hkpUnaryAction
{
public:
	hkVector4f m_rotationAxis;
	hkVector4f m_upAxis;
	f32 m_strength;
	f32 m_damping;

	/* Constructors */

	void ctor() { SDK_CALL_FUNC(void, 0xE12FE0, void*)(this); }
	void ctor(hkpRigidBody* body, const hkVector4f& rotationAxis, const hkVector4f& upAxis, f32 strength = 1.f, f32 damping = 0.1f) {
		SDK_CALL_FUNC(void, 0xE13020, void*, hkpRigidBody*, const hkVector4f&, const hkVector4f&, f32, f32)(this, body, rotationAxis, upAxis, strength, damping);
	}
};