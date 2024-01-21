#pragma once

namespace UFG
{
	class CSimObjectPropertiesComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		eSimObjectTypeEnum m_eSimObjectType;

		UFG_PAD(0x4);

		void* m_pSubTargetingProfile;
		uint8_t m_BitField[8];

		UFG_PAD(0x30);
	};
	UFG_ASSERT_CLASS(CSimObjectPropertiesComponent, 0x98);
}