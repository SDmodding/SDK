#pragma once
#include <xmmintrin.h>

typedef int8_t hkUFloat8;
typedef uint16_t hkHalf;

struct hkMatrix3f;

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

	float& operator[](int p_Index) { return m_quad.m128_f32[p_Index]; }

	void Set(float x, float y, float z, float w = 0.f)
	{
		m_quad = _mm_set_ps(w, z, y, x);
	}

	void SetRotatedDir(hkMatrix3f* p_Matrix, hkVector4f* p_Vector)
	{
		reinterpret_cast<void(__fastcall*)(hkVector4f*, hkMatrix3f*, hkVector4f*)>(UFG_RVA(0xC56EB0))(this, p_Matrix, p_Vector);
	}
};

struct hkContactPoint
{
	hkVector4f m_position;
	hkVector4f m_separatingNormal;
};

struct hkMatrix3f
{
	hkVector4f m_col0;
	hkVector4f m_col1;
	hkVector4f m_col2;
};
typedef hkMatrix3f hkRotationf;

struct hkTransformf
{
	hkRotationf m_rotation;
	hkVector4f m_translation;
};

struct hkQuaternionf
{
	hkVector4f m_vec;

	void SetAxisAngle(hkVector4f* p_Axis, float p_Angle)
	{
		reinterpret_cast<void(__fastcall*)(void*, hkVector4f*, float)>(UFG_RVA(0xC57910))(this, p_Axis, p_Angle);
	}
};

struct hkSweptTransformf
{
	hkVector4f m_centerOfMass0;
	hkVector4f m_centerOfMass1;
	hkQuaternionf m_rotation0;
	hkQuaternionf m_rotation1;
	hkVector4f m_centerOfMassLocal;
};

struct hkQsTransformf
{
	hkVector4f m_translation;
	hkQuaternionf m_rotation;
	hkVector4f m_scale;
};