#pragma once

class hkpMotion : public hkReferencedObject
{
public:
	enum MotionType
	{
		MOTION_INVALID,
		MOTION_DYNAMIC,
		MOTION_SPHERE_INERTIA,
		MOTION_BOX_INERTIA,
		MOTION_KEYFRAMED,
		MOTION_FIXED,
		MOTION_THIN_BOX_INERTIA,
		MOTION_CHARACTER,
		MOTION_MAX_ID
	};

	hkEnum<MotionType, u8> m_type;
	u8 m_deactivationIntegrateCounter;
	u16 m_deactivationNumInactiveFrames[2];
	hkMotionState m_motionState;
	hkVector4f m_inertiaAndMassInv;
	hkVector4f m_linearVelocity;
	hkVector4f m_angularVelocity;
	hkVector4f m_deactivationRefPosition[2];
	u32 m_deactivationRefOrientation[2];
	class hkpMaxSizeMotion* m_savedMotion;
	u16 m_savedQualityTypeIndex;
	hkHalf m_gravityFactor;

	/* Virtual Functions */

	virtual void setMass(const hkSimdFloat32& mass) = 0;
	virtual void setMass(f32 mass) = 0; // -> Calls setMassInv(1.f / mass)
	virtual void setMassInv(const hkSimdFloat32& massInv) = 0;
	virtual void setMassInv(f32 massInv) = 0;

	// TODO: Impl rest of the virtual functions if needed...
};