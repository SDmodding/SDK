#pragma once

class hkMotionState
{
public:
	hkTransformf m_transform;
	hkSweptTransformf m_sweptTransform;
	hkVector4f m_deltaAngle;
	f32 m_objectRadius;
	hkHalf m_linearDamping;
	hkHalf m_angularDamping;
	hkHalf m_timeFactor;
	hkUFloat8 m_maxLinearVelocity;
	hkUFloat8 m_maxAngularVelocity;
	i8 m_deactivationClass;
};