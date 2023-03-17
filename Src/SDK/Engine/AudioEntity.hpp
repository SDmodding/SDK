#pragma once

namespace UFG
{
	class CAudioEntity
	{
	public:
		bool IsPlaying(uint32_t m_EventID)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x147CD0))(this, m_EventID);
		}

		bool CreateAndPlayEvent(uint32_t eventId, void* pInitParams = nullptr, uint32_t fadeInDurationMs = 0, void* externalSourceInfo = nullptr)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, uint32_t, void*, uint32_t, void*)>(UFG_RVA(0x1440B0))(this, eventId, pInitParams, fadeInDurationMs, externalSourceInfo);
		}

		bool CreateAndPlayEvent(const char* m_String)
		{
			uint32_t m_EventID = reinterpret_cast<uint32_t(__fastcall*)(const char*)>(UFG_RVA(0x143890))(m_String);
			return CreateAndPlayEvent(m_EventID);
		}

		void StopAndForgetEvent(uint32_t m_EventID, float m_MS = 0.f)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t, float)>(UFG_RVA(0x14CCC0))(this, m_EventID, m_MS);
		}
	};

	namespace AudioEntity
	{
		// There is multiple AudioEntities initalized but we use NISAudio, but we could technically allocate own one if we need.
		CAudioEntity* Get()
		{
			return *reinterpret_cast<CAudioEntity**>(UFG_RVA(0x242E568));
		}
	}
}