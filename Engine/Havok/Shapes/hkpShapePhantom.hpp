#pragma once

class hkpShapePhantom : public hkpPhantom
{
public:
	UFG_PAD_ALIGN(0x8);

	hkMotionState m_motionState;

	void SetPosition(hkVector4f* p_Position, float p_ExtraTolerance)
	{
		reinterpret_cast<void(__fastcall*)(void*, hkVector4f*, float)>(UFG_RVA(0xD67510))(this, p_Position, p_ExtraTolerance);
	}
};