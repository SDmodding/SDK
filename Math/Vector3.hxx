#pragma once

namespace UFG
{
	class qVector3
	{
	public:
		float x, y, z;

		qVector3()
		{
			x = y = z = 0.f;
		}

		qVector3(float f0, float f1, float f2)
		{
			x = f0; y = f1; z = f2;
		}

		// Operators
		float& operator[](int m_Index) { return (&x)[m_Index]; }

		__forceinline bool operator==(qVector3& m_Other) { return (x == m_Other.x && y == m_Other.y && z == m_Other.z); }
		__forceinline bool operator!=(qVector3& m_Other) { return (x != m_Other.x || y != m_Other.y || z != m_Other.z); }

		__forceinline qVector3 operator+(qVector3 m_Other) { return { x + m_Other.x, y + m_Other.y, z + m_Other.z }; }
		__forceinline void operator+=(qVector3 m_Other) { x += m_Other.x; y += m_Other.y; z += m_Other.z; }

		__forceinline qVector3 operator-(qVector3 m_Other) { return { x - m_Other.x, y - m_Other.y, z - m_Other.z }; }
		__forceinline void operator-=(qVector3 m_Other) { x -= m_Other.x; y -= m_Other.y; z -= m_Other.z; }

		__forceinline qVector3 operator*(qVector3 m_Other) { return { x * m_Other.x, y * m_Other.y, z * m_Other.z }; }
		__forceinline void operator*=(qVector3 m_Other) { x *= m_Other.x; y *= m_Other.y; z *= m_Other.z; }

		__forceinline qVector3 operator*(float m_Value) { return { x * m_Value, y * m_Value, z * m_Value }; }
		__forceinline void operator*=(float m_Value) { x *= m_Value; y *= m_Value; z *= m_Value; }

		__forceinline qVector3 operator/(qVector3 m_Other) { return { x / m_Other.x, y / m_Other.y, z / m_Other.z }; }
		__forceinline void operator/=(qVector3 m_Other) { x /= m_Other.x; y /= m_Other.y; z /= m_Other.z; }

		__forceinline qVector3 operator/(float m_Value) { return { x / m_Value, y / m_Value, z / m_Value }; }
		__forceinline void operator/=(float m_Value) { x /= m_Value; y /= m_Value; z /= m_Value; }

		__forceinline qVector3 operator-() { return { -x, -y, -z }; }

		// Funcs
		float Length()
		{
			return sqrtf(x * x + y * y + z * z);
		}

		float DotProduct(qVector3& m_Other) { return x * m_Other.x + y * m_Other.y + z * m_Other.z; }
		qVector3 Cross(qVector3 m_Other) { return { y * m_Other.z - z * m_Other.y, z * m_Other.x - x * m_Other.z, x * m_Other.y - y * m_Other.x }; }

		void Normalize()
		{
			float m_Length = Length();
			operator/=(m_Length);
		}

		float DistTo(qVector3* m_Other)
		{
			qVector3 m_Delta(x - m_Other->x, y - m_Other->y, z - m_Other->z);
			return m_Delta.Length();
		}

		__inline float DistTo2D(qVector2* m_Other)
		{
			return reinterpret_cast<qVector2*>(this)->DistTo(m_Other);
		}

		__inline float DistTo2D(qVector3* m_Other)
		{
			return DistTo2D(reinterpret_cast<qVector2*>(m_Other));
		}

		void ConvertToRad()
		{
			x *= UFG_Deg2Rad_Mul;
			y *= UFG_Deg2Rad_Mul;
			z *= UFG_Deg2Rad_Mul;
		}

		void AngleVectors(qVector3* forward, qVector3* right, qVector3* up)
		{
			float sp = sinf(x);
			float cp = cosf(x);

			float sy = sinf(y);
			float cy = cosf(y);

			float sr = sinf(z);
			float cr = cosf(z);

			if (forward)
			{
				forward->x = cp * cy;
				forward->y = cp * sy;
				forward->z = -sp;
			}

			if (right)
			{
				right->x = (-1 * sr * sp * cy + -1 * cr * -sy);
				right->y = (-1 * sr * sp * sy + -1 * cr * cy);
				right->z = -1 * sr * cp;
			}

			if (up)
			{
				up->x = (cr * sp * cy + -sr * -sy);
				up->y = (cr * sp * sy + -sr * cy);
				up->z = cr * cp;
			}
		}

		void Angles2Vector()
		{
			float m_PitchSin = sinf(x);
			float m_PitchCos = cosf(x);

			float m_YawSin = sinf(y);
			float m_YawCos = cosf(y);

			x = m_YawCos * m_PitchCos;
			y = m_YawSin * m_PitchCos;
			z = m_PitchSin;
		}

		void DegAngles2Vector()
		{
			ConvertToRad();

			Angles2Vector();
		}

		void Vector2Angles()
		{
			float m_Pitch = asinf(y);
			float m_Yaw = atan2f(z, x);

			x = m_Pitch;
			y = m_Yaw;
			z = 0.f;
		}
	};
}