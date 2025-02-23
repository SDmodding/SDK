#pragma once

namespace UFG
{
	class HkAudioEntityComponent : public SimComponent, public AudioEntity
	{
	public:
		enum { _TypeUID = 0xD2000001 };
	};
	SDK_ASSERT_SIZEOF(HkAudioEntityComponent, 0x180);
}