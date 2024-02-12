#pragma once

namespace UFG
{
	class qVector4
	{
	public:
		float x, y, z, w;

		qVector4()
		{
			x = y = z = w = 0.f;
		}

		qVector4(float f0, float f1, float f2, float f3)
		{
			x = f0; y = f1; z = f2; w = f3;
		}

		// Operators
		UFG_INLINE bool operator==(const qVector4& m_Other) { return (x == m_Other.x && y == m_Other.y && z == m_Other.z && w == m_Other.w); }
		UFG_INLINE bool operator!=(const qVector4& m_Other) { return (x != m_Other.x || y != m_Other.y || z != m_Other.z || w != m_Other.w); }

		UFG_INLINE qVector4 operator+(const qVector4& m_Other) { return { x + m_Other.x, y + m_Other.y, z + m_Other.z, w + m_Other.w }; }
		UFG_INLINE void operator+=(const qVector4& m_Other) { x += m_Other.x; y += m_Other.y; z += m_Other.z; w += m_Other.w; }

		UFG_INLINE qVector4 operator-(const qVector4& m_Other) { return { x - m_Other.x, y - m_Other.y, z - m_Other.z, w - m_Other.w }; }
		UFG_INLINE void operator-=(const qVector4& m_Other) { x -= m_Other.x; y -= m_Other.y; z -= m_Other.z; w -= m_Other.w; }

		UFG_INLINE qVector4 operator*(float m_Value) { return { x * m_Value, y * m_Value, z * m_Value, w * m_Value }; }
		UFG_INLINE void operator*=(float m_Value) { x *= m_Value; y *= m_Value; z *= m_Value; w *= m_Value; }

		UFG_INLINE qVector4 operator/(float m_Value) { return { x / m_Value, y / m_Value, z / m_Value, w / m_Value }; }
		UFG_INLINE void operator/=(float m_Value) { x /= m_Value; y /= m_Value; z /= m_Value; ; w /= m_Value; }

		UFG_INLINE qVector4 operator-() { return { -x, -y, -z, -w }; }

		UFG_INLINE operator qVector3() { return qVector3(x, y, z); }

		// Funcs
		UFG_INLINE qVector3 ToVector3() { this->operator UFG::qVector3(); }

		UFG_INLINE float DotProduct(const qVector4& m_Other) 
		{ 
			return (x * m_Other.x + y * m_Other.y + z * m_Other.z); 
		}
	};
}