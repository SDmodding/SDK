#pragma once

namespace UFG
{
	class TargetingMap
	{
	public:
		u8 m_uNumValidTargetTypes;
		qFixedArray<u8, NUM_TARGET_TYPES> m_Map;
	};
	SDK_ASSERT_SIZEOF(TargetingMap, 0x64);
}