#pragma once

namespace UFG
{
	namespace SimObjectUtility
	{
		UFG_INLINE void Teleport(SimObject* p_SimObject, const qMatrix44& p_Matrix)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, const qMatrix44&)>(UFG_RVA(0x556870))(p_SimObject, p_Matrix);
		}

		UFG_INLINE void SetPosition(SimObject* p_SimObject, float p_X, float p_Y, float p_Z)
		{
			qMatrix44 m_Matrix = p_SimObject->m_pTransformNodeComponent->mWorldTransform;
			{
				m_Matrix.v3.x = p_X;
				m_Matrix.v3.y = p_Y;
				m_Matrix.v3.z = p_Z;
			}

			Teleport(p_SimObject, m_Matrix);
		}

		UFG_INLINE void SetPosition(SimObject* p_SimObject, const qVector3& p_Position)
		{
			qMatrix44 m_Matrix = p_SimObject->m_pTransformNodeComponent->mWorldTransform;
			m_Matrix.v3 = { p_Position.x, p_Position.y, p_Position.z, 1.f };
			Teleport(p_SimObject, m_Matrix);
		}

		UFG_INLINE void ResetState(SimObject* p_SimObject, bool p_KeepItems, bool p_DeleteItems)
		{ 
			reinterpret_cast<void(__fastcall*)(void*, bool, bool)>(UFG_RVA(0x54A8D0))(p_SimObject, p_KeepItems, p_DeleteItems);
		}
	}
}