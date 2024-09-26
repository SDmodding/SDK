#pragma once

namespace UFG
{
	class SimObjectPropertiesComponent : public SimComponent
	{
	public:
		UFG_PAD(0x10);

		eSimObjectTypeEnum m_eSimObjectType;

		UFG_PAD(0x4);

		void* m_pSubTargetingProfile;
		uint8_t m_BitField[8];

		UFG_PAD(0x30);
	}; typedef SimObjectPropertiesComponent CSimObjectPropertiesComponent;
	UFG_ASSERT_CLASS(SimObjectPropertiesComponent, 0x98);
}