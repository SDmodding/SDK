#pragma once

class hkMatrix3f;

class hkUFloat8
{
public:
	i8 m_value;
};

class hkHalf
{
public:
	i16 m_value;

	SDK_INLINE hkHalf() {}
	SDK_INLINE hkHalf(const f32& f) { this->operator=(f); }

	SDK_INLINE hkHalf& operator=(const f32& f)
	{
		int t = ((const int*)&f)[0];
		m_value = i16(t >> 16);
		return *this;
	}

	SDK_INLINE f32 getFloat32() const
	{
		union
		{
			int i;
			float f;
		} u;
		u.i = (m_value << 16);
		return u.f;
	}
};

class hkVector4f
{
public:
	__m128 m_quad;

	hkVector4f() {}
	hkVector4f(f32 a, f32 b, f32 c, f32 d = 0.f) { m_quad = _mm_setr_ps(a, b, c, d); }

	void set(f32 a, f32 b, f32 c, f32 d = 0.f) { m_quad = _mm_setr_ps(a, b, c, d); }

	void setRotatedDir(const hkMatrix3f& a, const hkVector4f& b) { SDK_CALL_FUNC(void, 0xC56EB0, void*, const hkMatrix3f&, const hkVector4f&)(this, a, b); }

	f32 operator[](int i) const { return m_quad.m128_f32[i]; }

	hkVector4f& operator*(f32 f)
	{
		m_quad = _mm_mul_ps(m_quad, _mm_set_ps1(f));
		return *this;
	}

	void operator*=(f32 f)
	{
		m_quad = _mm_mul_ps(m_quad, _mm_set_ps1(f));
	}
};
typedef hkVector4f hkVector4;

class hkMatrix3f
{
public:
	hkVector4f m_col0;
	hkVector4f m_col1;
	hkVector4f m_col2;
};
typedef hkMatrix3f hkMatrix3;

class hkRotationf : public hkMatrix3f
{
public:
};

class hkQuaternionf
{
public:
	hkVector4f m_vec;
};

class hkTransformf
{
public:
	hkRotationf m_rotation;
	hkVector4f m_translation;
};

class hkQsTransformf
{
public:
	hkVector4f m_translation;
	hkQuaternionf m_rotation;
	hkVector4f m_scale;
};

class hkSweptTransformf
{
public:
	hkVector4f m_centerOfMass0;
	hkVector4f m_centerOfMass1;
	hkQuaternionf m_rotation0;
	hkQuaternionf m_rotation1;
	hkVector4f m_centerOfMassLocal;
};