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
	};
}