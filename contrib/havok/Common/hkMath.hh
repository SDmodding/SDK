#pragma once

class hkMatrix3f;

class hkUFloat8
{
public:
	i8 m_value;

	SDK_SINLINE u16 getEncodedFloat(u8 index) { return SDK_CALL_FUNC(u16, 0xC56E80, u8)(index); }

	hkUFloat8& operator=(f32 fv) { return SDK_CALL_FUNC(hkUFloat8&, 0x12FE590, void*, f32&)(this, fv); }
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
	f32& operator[](int i) { return m_quad.m128_f32[i]; }

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
typedef hkVector4f* hkVector4Parameter;

class hkVector4ComparisonMask
{
public:
	enum Mask
	{
		INDEX_W = 3,	// Index of the w component
		INDEX_Z = 2,
		INDEX_Y = 1,
		INDEX_X = 0,

		MASK_NONE = 0x0,				// 0000
		MASK_W = (1 << INDEX_W),		// 0001
		MASK_Z = (1 << INDEX_Z),		// 0010
		MASK_ZW = (MASK_Z | MASK_W),	// 0011

		MASK_Y = (1 << INDEX_Y),		// 0100
		MASK_YW = (MASK_Y | MASK_W),	// 0101
		MASK_YZ = (MASK_Y | MASK_Z),	// 0110
		MASK_YZW = (MASK_YZ | MASK_W),	// 0111

		MASK_X = (1 << INDEX_X),		// 1000
		MASK_XW = (MASK_X | MASK_W),	// 1001
		MASK_XZ = (MASK_X | MASK_Z),	// 1010
		MASK_XZW = (MASK_XZ | MASK_W),	// 1011

		MASK_XY = (MASK_X | MASK_Y),	// 1100
		MASK_XYW = (MASK_XY | MASK_W),	// 1101
		MASK_XYZ = (MASK_XY | MASK_Z),	// 1110
		MASK_XYZW = (MASK_XY | MASK_ZW)	// 1111
	};
};

class hkVector4fComparison : public hkVector4ComparisonMask
{
public:
	__m128 m_mask;
};
typedef hkVector4fComparison hkVector4Comparison;
typedef hkVector4fComparison* hkVector4fComparisonParameter;
typedef hkVector4fComparisonParameter hkVector4ComparisonParameter;

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

	void setIdentity()
	{
		m_rotation.m_col0.set(1.f, 0.f, 0.f, 1.f);
		m_rotation.m_col1.set(0.f, 1.f, 0.f, 1.f);
		m_rotation.m_col2.set(0.f, 0.f, 1.f, 1.f);
		m_translation.set(0.f, 0.f, 0.f);
	}
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

class hkSimdFloat32
{
public:
	__m128 m_real;

	hkSimdFloat32() {}
};