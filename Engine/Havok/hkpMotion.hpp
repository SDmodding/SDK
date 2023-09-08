#pragma once

class hkpMotion : public hkReferencedObject
{
public:
	enum MotionType : uint8_t
	{
		MOTION_INVALID = 0x0,
		MOTION_DYNAMIC = 0x1,
		MOTION_SPHERE_INERTIA = 0x2,
		MOTION_BOX_INERTIA = 0x3,
		MOTION_KEYFRAMED = 0x4,
		MOTION_FIXED = 0x5,
		MOTION_THIN_BOX_INERTIA = 0x6,
		MOTION_CHARACTER = 0x7,
		MOTION_MAX_ID = 0x8,
	};
	MotionType m_type;

	UFG_PAD(0x12F);
	/*char m_deactivationIntegrateCounter;
	unsigned __int16 m_deactivationNumInactiveFrames[2];
	__declspec(align(16)) hkMotionState m_motionState;
	hkVector4f m_inertiaAndMassInv;
	hkVector4f m_linearVelocity;
	hkVector4f m_angularVelocity;
	hkVector4f m_deactivationRefPosition[2];
	unsigned int m_deactivationRefOrientation[2];
	hkpMaxSizeMotion* m_savedMotion;
	unsigned __int16 m_savedQualityTypeIndex;
	hkHalf m_gravityFactor;*/

	void SetRotation(hkQuaternionf* p_Rotation)
	{
		reinterpret_cast<void(_fastcall*)(void*, hkQuaternionf*)>(UFG_RVA(0xD60700))(this, p_Rotation);
	}
};

typedef hkpMotion hkpKeyframedRigidMotion;
typedef hkpKeyframedRigidMotion hkpMaxSizeMotion;