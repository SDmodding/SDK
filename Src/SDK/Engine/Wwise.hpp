#pragma once

namespace UFG
{
	namespace WwiseInterface
	{
		// This does prepare MP3 properly but there is no way to play it.
		// Missing event called "play_mp3" might be not even worth recovering it besides finding way to load own banks.
		bool PrepareMP3(const char* m_FileName)
		{
			return reinterpret_cast<bool(__fastcall*)(const char*)>(UFG_RVA(0x14AC60))(m_FileName);
		}

		bool LoadFilePackage(qSymbol m_DeviceName, const char* m_PackageName, bool m_Localized = false, bool m_DLC = false)
		{
			return reinterpret_cast<bool(__fastcall*)(qSymbol*, const char*, bool, bool)>(UFG_RVA(0x148AF0))(&m_DeviceName, m_PackageName, m_Localized, m_DLC);
		}

		void UnloadFilePackage(const char* m_PackageName)
		{
			reinterpret_cast<void(__fastcall*)(const char*)>(UFG_RVA(0x14CF50))(m_PackageName);
		}
	}
}