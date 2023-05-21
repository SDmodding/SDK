#pragma once
#define UFG_DIALOGBOX_OPTION_HASH	0xB00B
#define UFG_DIALOGBOX_FLASHFILE		"DialogBox"
#define UFG_DIALOGBOX_TOP_LAYER		0xFFFFFFFF

namespace UFG
{
	namespace ScreenOverlay
	{
		void* Get()
		{
			return *reinterpret_cast<void**>(UFG_RVA(0x2430D38));
		}

		void ShowCurtains(float fadeInTime, bool bMuteAudio)
		{
			reinterpret_cast<void(__fastcall*)(float, bool)>(UFG_RVA(0x60D3C0))(fadeInTime, bMuteAudio);
		}

		void HideCurtains(float fadeOutTime, bool bUseNonLinearFade)
		{
			reinterpret_cast<void(__fastcall*)(float, bool)>(UFG_RVA(0x5ECCA0))(fadeOutTime, bUseNonLinearFade);
		}

		void YouDied()
		{
			reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x61F620))();
		}
	}

	namespace ScreenDialogBox
	{
		void InfoStart(const char* bodyText, bool fullscreen = true, const char* flashFile = UFG_DIALOGBOX_FLASHFILE)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, const char*, bool, const char*)>(UFG_RVA(0x61FB90))(nullptr, "", bodyText, fullscreen, flashFile);
		}
		
		void InfoEnd()
		{
			reinterpret_cast<void(__fastcall*)(void*, DWORD)>(UFG_RVA(0xA31600))(*(uintptr_t**)UFG_RVA(0x249C1C0), UFG_DIALOGBOX_TOP_LAYER);
		}

		void OneButton(const char* bodyText, const char* optionText, bool fullscreen = true, uint32_t m_OptionHash = UFG_DIALOGBOX_OPTION_HASH, const char* flashFile = UFG_DIALOGBOX_FLASHFILE)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, const char*, const char*, uint32_t, bool, const char*)>(UFG_RVA(0x61F500))(nullptr, "", bodyText, optionText, m_OptionHash, fullscreen, flashFile);
		}

		void TwoButton(const char* bodyText, const char* option1Text, const char* option2Text, bool fullscreen = true, uint32_t m_OptionHash = UFG_DIALOGBOX_OPTION_HASH, const char* flashFile = UFG_DIALOGBOX_FLASHFILE)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, const char*, const char*, uint32_t, const char*, uint32_t, uint32_t, bool, const char*)>(UFG_RVA(0x61F970))(nullptr, "", bodyText, option1Text, m_OptionHash, option2Text, m_OptionHash + 1, 0, fullscreen, flashFile);
		}

		void ThreeButton(const char* bodyText, const char* option1Text, const char* option2Text, const char* option3Text, uint32_t m_OptionHash = UFG_DIALOGBOX_OPTION_HASH, const char* flashFile = UFG_DIALOGBOX_FLASHFILE)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, const char*, const char*, uint32_t, const char*, uint32_t, const char*, uint32_t, uint32_t, const char*)>(UFG_RVA(0x61F820))(nullptr, "", bodyText, option1Text, m_OptionHash, option2Text, m_OptionHash + 1, option3Text, m_OptionHash + 2, 0, flashFile);
		}
	}

	namespace ScreenMissionComplete
	{
		void Actiate(qSymbol gamesliceType, qSymbol gamesliceSubType, const char* caption, bool show_xp_tutorial) 
		{ 
			reinterpret_cast<void(__fastcall*)(qSymbol*, qSymbol*, const char*, bool)>(UFG_RVA(0x5D10C0))(&gamesliceType, &gamesliceSubType, caption, show_xp_tutorial);
		}

		void ClearRacers() { reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5D5860))(); }

		void ClearRewards() { reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5D5900))(); }

		void FillRacerInfo(qArray<qString>* racerNames) { reinterpret_cast<void(__fastcall*)(qArray<qString>*)>(UFG_RVA(0x5D8360))(racerNames); }
	}
}
