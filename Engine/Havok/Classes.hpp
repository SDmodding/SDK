#pragma once
#include <xmmintrin.h>

struct hkVector4f
{
	__m128 m_quad;

	hkVector4f()
	{
		m_quad = _mm_set_ps(0.f, 0.f, 0.f, 0.f);
	}

	hkVector4f(float x, float y, float z, float w = 0.f)
	{
		m_quad = _mm_set_ps(w, z, y, x);
	}

	hkVector4f(UFG::qVector3& m_Vector3)
	{
		m_quad = _mm_set_ps(0.f, m_Vector3.z, m_Vector3.y, m_Vector3.x);
	}

	void Set(float x, float y, float z, float w)
	{
		m_quad = _mm_set_ps(w, z, y, x);
	}
};

struct hkQuaternionf
{
	hkVector4f m_vec;

	void SetAxisAngle(hkVector4f* p_Axis, float p_Angle)
	{
		reinterpret_cast<void(__fastcall*)(void*, hkVector4f*, float)>(UFG_RVA(0xC57910))(this, p_Axis, p_Angle);
	}
};
