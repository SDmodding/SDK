#pragma once

namespace UFG
{
	class SubTargetingLocationDynamic
	{
	public:
		enum DynamicConditionEnum
		{
			DYNAMIC_CONDITION_INVALID,
			DYNAMIC_CONDITION_ALWAYS,
			DYNAMIC_CONDITION_HAS_DRIVER,
			DYNAMIC_CONDITION_HAS_PASSENGER,
			DYNAMIC_CONDITION_HAS_PASSENGER2,
			DYNAMIC_CONDITION_HAS_PASSENGER3,
			DYNAMIC_CONDITION_HAS_PASSENGER4,
			NUM_DYNAMIC_CONDITION_TYPES
		};

		struct SubTargetingLocationWithCondition
		{
			DynamicConditionEnum m_eDynamicCondition;
			SubTargetingLocation* m_pSubTargetingLocation;
		};

		qFixedArray<SubTargetingLocationWithCondition, 6> m_SubTargetingLocationsWithConditions;
	};
	SDK_ASSERT_SIZEOF(SubTargetingLocationDynamic, 0x68);
}