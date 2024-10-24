#pragma once

class hkMatrix3f;

class hkVector4f
{
public:
	__m128 m_quad;

	hkVector4f() {}
	hkVector4f(f32 a, f32 b, f32 c, f32 d) { m_quad = _mm_setr_ps(a, b, c, d); }

	void set(f32 a, f32 b, f32 c, f32 d) { m_quad = _mm_setr_ps(a, b, c, d); }

	void setRotatedDir(const hkMatrix3f& a, const hkVector4f& b) { SDK_CALL_FUNC(void, 0xC56EB0, void*, const hkMatrix3f&, const hkVector4f&)(this, a, b); }
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