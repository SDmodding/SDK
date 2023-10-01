#pragma once

class hkpBoxShape : public hkpConvexShape
{
public:
	hkVector4f m_halfExtents;

	hkpBoxShape(hkVector4f m_HalfExtents, float m_Radius)
	{
		reinterpret_cast<void(__fastcall*)(void*, hkVector4f, float)>(UFG_RVA(0xCF1C40))(this, m_HalfExtents, m_Radius);
	}

	bool CastRay(hkpShapeRayCastInput* m_Input, hkpShapeRayCastOutput* m_Output)
	{
		bool m_Result = false;
		reinterpret_cast<void(__fastcall*)(void*, bool*, hkpShapeRayCastInput*, hkpShapeRayCastOutput*)>(UFG_RVA(0xCF1E60))(this, &m_Result, m_Input, m_Output);
		return m_Result;
	}
};