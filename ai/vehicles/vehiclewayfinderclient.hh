#pragma once

namespace UFG
{
	class RoadNetworkGuide;

	class VehicleWayFinderClient : public WayFinderClient
	{
	public:
		u32 m_RoadNetworkType;
		u32 m_LaneFlags;
		RoadNetworkGuide* m_RoadGuide;
		bool m_AllowFootPaths;
	};
	SDK_ASSERT_SIZEOF(VehicleWayFinderClient, 0x448);
}