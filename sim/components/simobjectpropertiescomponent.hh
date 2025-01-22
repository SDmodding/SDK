#pragma once

namespace UFG
{
	class SimObjectPropertiesComponent : public SimComponent, public qNode<SimObjectPropertiesComponent>
	{
	public:
		enum { _TypeUID = 0xB2000001 };

		eSimObjectTypeEnum m_eSimObjectType;
		SubTargetingProfile* m_pSubTargetingProfile;
		qStaticBitField<7> m_BitField;
		qList<SimObjectFlagSetTask> m_FlagSetLists[2];
		qArray<qSymbol> m_ClassTypeListArray;

		/* Functions */

		void AddSimObjectFlagSetTask(eSimObjectFlagEnum eSimObjectFlag, SimObjectFlagSetTask* pSimObjectFlagSetTask) { 
			SDK_CALL_FUNC(void, 0x5213D0, void*, eSimObjectFlagEnum, SimObjectFlagSetTask*)(this, eSimObjectFlag, pSimObjectFlagSetTask); 
		}
		void UpdateCachedValues() { SDK_CALL_FUNC(void, 0x55E740, void*)(this); }
		bool isFlagSet(eSimObjectFlagEnum eSimObjectFlag) { return SDK_CALL_FUNC(bool, 0x56AA40, void*, eSimObjectFlagEnum)(this, eSimObjectFlag); }
	};
	SDK_ASSERT_SIZEOF(SimObjectPropertiesComponent, 0x98);
}