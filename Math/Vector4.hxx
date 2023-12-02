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
		__forceinline bool operator==(qVector4& m_Other) { return (x == m_Other.x && y == m_Other.y && z == m_Other.z && w == m_Other.w); }
		__forceinline bool operator!=(qVector4& m_Other) { return (x != m_Other.x || y != m_Other.y || z != m_Other.z || w != m_Other.w); }

		__forceinline qVector4 operator+(qVector4 m_Other) { return { x + m_Other.x, y + m_Other.y, z + m_Other.z, w + m_Other.w }; }
		__forceinline void operator+=(qVector4 m_Other) { x += m_Other.x; y += m_Other.y; z += m_Other.z; w += m_Other.w; }

		__forceinline qVector4 operator-(qVector4 m_Other) { return { x - m_Other.x, y - m_Other.y, z - m_Other.z, w - m_Other.w }; }
		__forceinline void operator-=(qVector4 m_Other) { x -= m_Other.x; y -= m_Other.y; z -= m_Other.z; w -= m_Other.w; }

		__forceinline qVector4 operator*(float m_Value) { return { x * m_Value, y * m_Value, z * m_Value, w * m_Value }; }
		__forceinline void operator*=(float m_Value) { x *= m_Value; y *= m_Value; z *= m_Value; w *= m_Value; }

		__forceinline qVector4 operator/(float m_Value) { return { x / m_Value, y / m_Value, z / m_Value, w / m_Value }; }
		__forceinline void operator/=(float m_Value) { x /= m_Value; y /= m_Value; z /= m_Value; ; w /= m_Value; }

		__forceinline qVector4 operator-() { return { -x, -y, -z, -w }; }

		// Funcs
		operator qVector3() { return qVector3(x, y, z); }
		qVector3 ToVector3() { return qVector3(x, y, z); }

		float DotProduct(qVector4& m_Other) { return x * m_Other.x + y * m_Other.y + z * m_Other.z; }
	};
}