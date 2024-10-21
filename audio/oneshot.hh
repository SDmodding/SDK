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
	};
	//SDK_ASSERT_SIZEOF(OneShot, 0x170);
}