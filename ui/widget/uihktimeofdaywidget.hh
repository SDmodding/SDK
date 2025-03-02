#pragma once

namespace UFG
{
	class UIHKTimeOfDayWidget
	{
	public:
		enum eLightingConditions
		{
			LIGHTING_INVALID,
			LIGHTING_MORNING,
			LIGHTING_AFTERNOON,
			LIGHTING_EVENING,
			NUM_LIGHTING_CONDITIONS
		};

		eLightingConditions mLightingConditions;
	};
}