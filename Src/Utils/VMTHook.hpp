#pragma once
#include <windows.h>
#include <vector>

namespace VMTHook
{
	struct _HookInfo
	{
		uintptr_t* m_pAddress;
		void* m_pOriginal;

		_HookInfo() { }
		_HookInfo(uintptr_t* address, void* original)
		{ 
			m_pAddress = address;
			m_pOriginal = original;
		}
	};
	std::vector<_HookInfo> m_Hooks;

	void Replace(uintptr_t* m_pAddress, void* m_pHook, void** m_pOriginal = nullptr)
	{
		if (m_pOriginal) *m_pOriginal = reinterpret_cast<void*>(*m_pAddress);

		DWORD m_dOldProtect = 0x0;
		if (VirtualProtect(m_pAddress, sizeof(void*), PAGE_EXECUTE_READWRITE, &m_dOldProtect))
		{
			*m_pAddress = reinterpret_cast<uintptr_t>(m_pHook);
			VirtualProtect(m_pAddress, sizeof(void*), m_dOldProtect, &m_dOldProtect);
		}
	}

	void Add(void* m_pVTable, unsigned int m_uIndex, void* m_pHook, void** m_pOriginal = nullptr)
	{
		uintptr_t* m_pAddress = reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(m_pVTable) + sizeof(void*) * m_uIndex);

		m_Hooks.emplace_back(m_pAddress, reinterpret_cast<void*>(*m_pAddress));

		Replace(m_pAddress, m_pHook, m_pOriginal);
	}

	void Restore()
	{
		for (auto Hook : m_Hooks)
			Replace(Hook.m_pAddress, Hook.m_pOriginal);
	}
}