#pragma once

namespace UFG
{
	class RoadNetworkSpawnPoint
	{
	public:
		RoadNetworkLane* mLane;
		RoadNetworkSubSegment* mSubSegment;
		f32 mSpawnTime;
		u32 mNumExpectedCars;

		/* Functions */

		bool CanSpawnCar() { return SDK_CALL_FUNC(bool, 0xD3140, void*)(this); }
		void Reset() { SDK_CALL_FUNC(void, 0xE0020, void*)(this); }
	};
}