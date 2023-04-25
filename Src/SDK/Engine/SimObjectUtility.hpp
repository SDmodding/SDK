#pragma once

namespace UFG
{
	namespace SimObjectUtility
	{
		void Teleport(CSimObject* m_pSimObject, qMatrix44* m_pPos) { reinterpret_cast<void(__fastcall*)(void*, qMatrix44*)>(UFG_RVA(0x556870))(m_pSimObject, m_pPos); }

		void SetPosition(CSimObject* m_pSimObject, float m_X, float m_Y, float m_Z)
		{
			qMatrix44 m_Matrix = m_pSimObject->m_pTransformNodeComponent->mWorldTransform;

			m_Matrix.v3.x = m_X;
			m_Matrix.v3.y = m_Y;
			m_Matrix.v3.z = m_Z;

			Teleport(m_pSimObject, &m_Matrix);
		}

		void SetPosition(CSimObject* m_pSimObject, qVector3& m_Pos)
		{
			qMatrix44 m_Matrix = m_pSimObject->m_pTransformNodeComponent->mWorldTransform;

			m_Matrix.v3.x = m_Pos.x;
			m_Matrix.v3.y = m_Pos.y;
			m_Matrix.v3.z = m_Pos.z;

			Teleport(m_pSimObject, &m_Matrix);
		}

		void SetPosition(CSimObject* m_pSimObject, qVector4& m_Pos)
		{
			qMatrix44 m_Matrix = m_pSimObject->m_pTransformNodeComponent->mWorldTransform;

			m_Matrix.v3 = m_Pos;

			Teleport(m_pSimObject, &m_Matrix);
		}

		void SetRotation(CSimObject* m_SimObject, qVector3& m_Rot)
		{
			qMatrix44 m_Matrix = m_SimObject->m_pTransformNodeComponent->mWorldTransform;
			m_Matrix.SetRotation(m_Rot);

			Teleport(m_SimObject, &m_Matrix);
		}

		// Don't use please
		void SetYaw(CSimObject* m_pSimObject, float m_fYaw)
		{
			qMatrix44 m_Matrix = m_pSimObject->m_pTransformNodeComponent->mWorldTransform;

			m_fYaw = (m_fYaw / 57.295779513082320876798154814105f);

			m_Matrix.v0.x = cosf(m_fYaw);
			m_Matrix.v0.y = sinf(m_fYaw);

			m_Matrix.v1.x = -m_Matrix.v0.y;
			m_Matrix.v1.y = m_Matrix.v0.x;

			Teleport(m_pSimObject, &m_Matrix);
		}
	}
}