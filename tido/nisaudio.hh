#pragma once

namespace UFG
{
	class NISAudio : public AudioEntity
	{
	public:
		AudioEventController m_controller;

		/* Static Functions */

		SDK_SINLINE NISAudio* Instance() { return SDK_VAR_GET(NISAudio*, 0x242E568); }

		/* Functions */

		void Play(u32 eventId, const AudioEventInitParams* params = 0) { SDK_CALL_FUNC(void, 0x5A4CB0, void*, u32, const AudioEventInitParams*)(this, eventId, params); }
		void PlayNISCurtainEvent(u32 eventId) { SDK_CALL_FUNC(void, 0x5A6A30, void*, u32)(this, eventId); }
	};
}