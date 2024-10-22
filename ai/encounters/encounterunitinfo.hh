#pragma once

namespace UFG
{
	class EncounterUnitContext
	{
	public:
		SimObject* mpSimObject;
		SimObject* mpVehicle;
		f32 mWaterContextTimer;
		bool mIsOnFootRaw;
		bool mIsInsideInterior;
		bool mIsInWater;
		bool mIsOnFootHeuristic;
		bool mIsOnMeshHeuristic;
		bool mOpenFired;
		bool mOpenFiredWithHostage;
	};
	SDK_ASSERT_SIZEOF(EncounterUnitContext, 0x20);
}