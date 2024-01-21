#pragma once

namespace UFG
{
	class CAudioEntity
	{
	public:
		UFG_INLINE bool IsPlaying(uint32_t p_EventID)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x147CD0))(this, p_EventID);
		}

		UFG_INLINE bool CreateAndPlayEvent(uint32_t p_EventID, void* p_InitParams = nullptr, uint32_t p_FadeInDurationMS = 0, void* p_ExternalSourceInfo = nullptr)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, uint32_t, void*, uint32_t, void*)>(UFG_RVA(0x1440B0))(this, p_EventID, p_InitParams, p_FadeInDurationMS, p_ExternalSourceInfo);
		}

		UFG_INLINE void StopAndForgetEvent(uint32_t p_EventID, float m_MS = 0.f)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, float)>(UFG_RVA(0x14CCC0))(this, p_EventID, m_MS);
		}
	};

	class CHudAudio : public CAudioEntity
	{
	public:
		static UFG_INLINE CHudAudio* Instance()
		{
			return *reinterpret_cast<CHudAudio**>(UFG_RVA(0x2175ED0));
		}
	};

	class CNISAudio : public CAudioEntity
	{
	public:
		static UFG_INLINE CNISAudio* Instance() 
		{
			return *reinterpret_cast<CNISAudio**>(UFG_RVA(0x242E568));
		}
	};
}