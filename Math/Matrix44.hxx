#pragma once

namespace UFG
{
	class qMatrix44
	{
	public:
		qVector4 v0; // Forward
		qVector4 v1; // Right
		qVector4 v2; // Up
		qVector4 v3; // Position

		UFG_INLINE qVector3 GetForward() { return v0; }
		UFG_INLINE qVector3 GetRight() { return v1; }
		UFG_INLINE qVector3 GetUp() { return v2; }

		void SetRotation(qVector3 m_Rotation)
		{
			m_Rotation *= UFG_Deg2Rad_Mul;

			float m_Pitch[2] = { cosf(m_Rotation.x), sinf(m_Rotation.x) };
			float m_Yaw[2] = { cosf(m_Rotation.y), sinf(m_Rotation.y) };
			float m_Roll[2] = { cosf(m_Rotation.z), sinf(m_Rotation.z) };

			v0 = { m_Yaw[0] * m_Pitch[0], m_Yaw[1] * m_Pitch[0], m_Pitch[1], 0.f };
			v1 = { m_Yaw[0] * m_Pitch[1] * m_Roll[1] - m_Yaw[1] * m_Roll[0], m_Yaw[1] * m_Pitch[1] * m_Roll[1] + m_Yaw[0] * m_Roll[0], -m_Pitch[0] * m_Roll[1], 0.f };
			v2 = { m_Yaw[0] * m_Pitch[1] * m_Roll[0] + m_Yaw[1] * m_Roll[1], m_Yaw[1] * m_Pitch[1] * m_Roll[0] - m_Yaw[0] * m_Roll[1], m_Pitch[0] * m_Roll[0], 0.f };
		}

		void GetRotationEuler(qVector3* p_Euler)
		{
			reinterpret_cast<void(__fastcall*)(UFG::qVector3*, UFG::qMatrix44*, bool)>(UFG_RVA(0x207700))(p_Euler, this, false);
		}

		void GetRotationEulerRad(qVector3* p_Euler)
		{
			GetRotationEuler(p_Euler);
			p_Euler->operator*=(UFG_Deg2Rad_Mul);
		}

		// Euler in Radians
		UFG_INLINE void SetRotationEuler(const qVector3& p_Euler)
		{
			reinterpret_cast<void(__fastcall*)(qMatrix44*, const qVector3&)>(UFG_RVA(0x18A6A0))(this, p_Euler);
		}

		// Use only if you know what you're doing!
		void SetCharacterYaw(float p_Degrees)
		{
			float m_Radians = UFG_Deg2Rad(p_Degrees);
			v0.x = cosf(m_Radians);
			v0.y = sinf(m_Radians);

			v1.x = -v0.y;
			v1.y = v0.x;
		}

		qVector3 ToVector3()
		{
			float sy = sqrtf(v0.x * v0.x + v1.x * v1.y);

			bool singular = sy < 1e-6f;

			qVector3 m_Ret;
			if (!singular)
			{
				m_Ret.x = atan2f(v2.y, v2.z);
				m_Ret.y = atan2f(-v2.x, sy);
				m_Ret.z = atan2f(v1.x, v0.x);
			}
			else
			{
				m_Ret.x = atan2f(-v1.z, v1.y);
				m_Ret.y = atan2f(-v2.x, sy);
				m_Ret.z = 0.f;
			}

			return m_Ret;
		}

		// Crashes on 'hkQsTransformf::get4x4ColumnMajor' for some odd reason.
		UFG_INLINE void BlendSlerp(qMatrix44* p_SourceA, qMatrix44* p_SourceB, float p_Weight)
		{
			reinterpret_cast<void(__fastcall*)(qMatrix44*, qMatrix44*, qMatrix44*, float)>(UFG_RVA(0x3A4A20))(this, p_SourceA, p_SourceB, p_Weight);
		}
	};
}