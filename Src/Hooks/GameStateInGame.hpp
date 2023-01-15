#pragma once

#include "../Callbacks/OnGameUpdate.hpp"

namespace Hook
{
	namespace GameStateInGame
	{
		typedef void(__fastcall* m_tOnUpdate)(void*, float);
		m_tOnUpdate m_oOnUpdate;

		void __fastcall OnUpdate(void* rcx, float m_fRealTimeDelta)
		{
			m_oOnUpdate(rcx, m_fRealTimeDelta);

			Callback::OnGameUpdate();
		}
	}
}