#pragma once
#define UFG_DIALOGBOX_OPTION_HASH	0xB00B
#define UFG_DIALOGBOX_FLASHFILE		"DialogBox"
#define UFG_DIALOGBOX_TOP_LAYER		0xFFFFFFFF

namespace UFG
{
	namespace ScreenOverlay
	{
		UFG_INLINE void* Get()
		{
			return *reinterpret_cast<void**>(UFG_RVA(0x2430D38));
		}

		UFG_INLINE void ShowCurtains(float p_fFadeInTime, bool p_bMuteAudio)
		{
			reinterpret_cast<void(__fastcall*)(float, bool)>(UFG_RVA(0x60D3C0))(p_fFadeInTime, p_bMuteAudio);
		}

		UFG_INLINE void HideCurtains(float p_fFadeOutTime, bool p_bUseNonLinearFade)
		{
			reinterpret_cast<void(__fastcall*)(float, bool)>(UFG_RVA(0x5ECCA0))(p_fFadeOutTime, p_bUseNonLinearFade);
		}

		UFG_INLINE void YouDied()
		{
			reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x61F620))();
		}
	}

	namespace ScreenDialogBox
	{
		UFG_INLINE void InfoStart(const char* p_szBodyText, bool p_bFullscreen = true, const char* p_szFlashFile = UFG_DIALOGBOX_FLASHFILE)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, const char*, bool, const char*)>(UFG_RVA(0x61FB90))(nullptr, "", p_szBodyText, p_bFullscreen, p_szFlashFile);
		}
		
		UFG_INLINE void InfoEnd()
		{
			reinterpret_cast<void(__fastcall*)(void*, DWORD)>(UFG_RVA(0xA31600))(*(uintptr_t**)UFG_RVA(0x249C1C0), UFG_DIALOGBOX_TOP_LAYER);
		}

		UFG_INLINE void OneButton(const char* p_szBodyText, const char* p_szOptionText, bool p_bFullscreen = true, uint32_t p_uOptionHash = UFG_DIALOGBOX_OPTION_HASH, const char* p_szFlashFile = UFG_DIALOGBOX_FLASHFILE)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, const char*, const char*, uint32_t, bool, const char*)>(UFG_RVA(0x61F500))(nullptr, "", p_szBodyText, p_szOptionText, p_uOptionHash, p_bFullscreen, p_szFlashFile);
		}

		UFG_INLINE void TwoButton(const char* p_szBodyText, const char* p_szOption1, const char* p_szOption2, bool p_bFullscreen = true, uint32_t p_uOptionHash = UFG_DIALOGBOX_OPTION_HASH, const char* p_szFlashFile = UFG_DIALOGBOX_FLASHFILE)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, const char*, const char*, uint32_t, const char*, uint32_t, uint32_t, bool, const char*)>(UFG_RVA(0x61F970))(nullptr, "", p_szBodyText, p_szOption1, p_uOptionHash, p_szOption2, p_uOptionHash + 1, 0, p_bFullscreen, p_szFlashFile);
		}

		UFG_INLINE void ThreeButton(const char* p_szBodyText, const char* p_szOption1, const char* p_szOption2, const char* p_szOption3, uint32_t p_uOptionHash = UFG_DIALOGBOX_OPTION_HASH, const char* p_szFlashFile = UFG_DIALOGBOX_FLASHFILE)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, const char*, const char*, uint32_t, const char*, uint32_t, const char*, uint32_t, uint32_t, const char*)>(UFG_RVA(0x61F820))(nullptr, "", p_szBodyText, p_szOption1, p_uOptionHash, p_szOption2, p_uOptionHash + 1, p_szOption3, p_uOptionHash + 2, 0, p_szFlashFile);
		}
	}

	namespace ScreenMissionComplete
	{
		UFG_INLINE void Actiate(qSymbol p_qGamesliceType, qSymbol p_qGamesliceSubType, const char* p_szCaption, bool p_bShowXPTutorial)
		{ 
			reinterpret_cast<void(__fastcall*)(qSymbol*, qSymbol*, const char*, bool)>(UFG_RVA(0x5D10C0))(&p_qGamesliceType, &p_qGamesliceSubType, p_szCaption, p_bShowXPTutorial);
		}

		UFG_INLINE void ClearRacers() 
		{ 
			reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5D5860))(); 
		}

		UFG_INLINE void ClearRewards() 
		{ 
			reinterpret_cast<void(__fastcall*)()>(UFG_RVA(0x5D5900))(); 
		}

		UFG_INLINE void FillRacerInfo(qArray<qString>* p_arrRacerNames) 
		{ 
			reinterpret_cast<void(__fastcall*)(qArray<qString>*)>(UFG_RVA(0x5D8360))(p_arrRacerNames);
		}
	}
}
