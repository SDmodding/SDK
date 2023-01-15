#pragma once

#include "GameStateInGame.hpp"
#include "HandleMessage.hpp"

#include "Present.hpp"
#include "WndProc.hpp"

#include "../3rdParty/MinHook.h"

namespace Hook
{
	void Init()
	{
		MH_Initialize();
		auto MH_AddHook = [](uintptr_t m_uFunction, void* m_pHook, void** m_pOriginal = nullptr)
		{
			void* m_pFunction = reinterpret_cast<void*>(m_uFunction);
			MH_CreateHook(m_pFunction, m_pHook, m_pOriginal);
			MH_EnableHook(m_pFunction);
		};

		VMTHook::Add(**reinterpret_cast<void***>(UFG::Global::DXGISwapChain), 8, Present, (void**)&m_oPresent);
		WndProc::m_oHook = WNDPROC(SetWindowLongPtrA(*UFG::Global::m_hWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&WndProc::Hook)));

		MH_AddHook(UFG_RVA(0x412240), GameStateInGame::OnUpdate, (void**)&GameStateInGame::m_oOnUpdate);
		MH_AddHook(UFG_RVA(0x6226D0), HandleMessage::ScreenDialogBox, (void**)&HandleMessage::m_oScreenDialogBox);
	}

	void Uninit()
	{
		VMTHook::Restore();
		SetWindowLongPtrA(*UFG::Global::m_hWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProc::m_oHook));

		MH_DisableHook(MH_ALL_HOOKS);
		MH_Uninitialize();
	}
}