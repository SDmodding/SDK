#pragma once

namespace UFG
{
	class OneShotHandle;

	class OneShot : public AudioEntity, public qNode<OneShot>
	{
	public:
		AudioEventController m_controller;
		OneShotHandle* m_pOwnerHandle;
		u32 m_eventCount;

		/* Functions */

		bool Play(u32 eventId) { return SDK_CALL_FUNC(bool, 0x14A170, void*, u32)(this, eventId); }
		void Stop(int fadeOutMs, u32 eventId) { SDK_CALL_FUNC(void, 0x14CAF0, void*, int, u32)(this, fadeOutMs, eventId); }
	};
	//SDK_ASSERT_SIZEOF(OneShot, 0x170);
}