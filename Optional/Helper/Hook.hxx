#pragma once

namespace SDK
{
	namespace Helper
	{
		typedef void(__fastcall* m_tInitGameSystemsHook)();
		struct InitGameSystemsHook_t
		{
			bool m_Initialized = false;
			m_tInitGameSystemsHook m_oOriginal = nullptr;

			InitGameSystemsHook_t(m_tInitGameSystemsHook p_Function)
			{
				uintptr_t m_Address = UFG_RVA(0x422691);
				if (*reinterpret_cast<uint8_t*>(m_Address) == 0x48)
					m_oOriginal = *reinterpret_cast<m_tInitGameSystemsHook*>(m_Address + 0x2);

				uint8_t m_ShellCode[] = { 0x48, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xD0 };

				DWORD m_OldProtect = 0x0;
				if (!VirtualProtect(reinterpret_cast<void*>(m_Address), sizeof(m_ShellCode), PAGE_EXECUTE_READWRITE, &m_OldProtect))
					return;

				*reinterpret_cast<void**>(&m_ShellCode[2]) = p_Function;
				memcpy(reinterpret_cast<void*>(m_Address), m_ShellCode, sizeof(m_ShellCode));

				VirtualProtect(reinterpret_cast<void*>(m_Address), sizeof(m_ShellCode), m_OldProtect, &m_OldProtect);
				m_Initialized = true;
			}

			__inline void CallOriginal()
			{
				if (m_oOriginal)
					m_oOriginal();
			}
		};
	}
}