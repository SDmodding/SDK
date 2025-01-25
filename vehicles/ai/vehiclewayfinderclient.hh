#pragma once

namespace UFG
{
	class VehicleWayFinderClient : public WayFinderClient
	{
	public:
		u32 m_RoadNetworkType;
		u32 m_LaneFlags;
		RoadNetworkGuide* m_RoadGuide;
		bool m_AllowFootPaths;

		/* Functions */

		bool CanGo(WayGraph* graph, u16 from_edge, u16 to_edge, u16 thru_node) {  return SDK_CALL_FUNC(bool, 0x647990, void*, WayGraph*, u16, u16, u16)(this, graph, from_edge, to_edge, thru_node); }
		bool CanTurnAround() { return SDK_CALL_FUNC(bool, 0x647A70, void*)(this); }
		qVector3 GetDirection() { return SDK_CALL_FUNC(qVector3, 0x64DA50, void*)(this); }
		qVector3 GetPosition() { return SDK_CALL_FUNC(qVector3, 0x64EF40, void*)(this); }
		u16 GetWayEdge(WayGraph* graph) { return SDK_CALL_FUNC(u16, 0x651220, void*, WayGraph*)(this, graph); }
		u16 GetWayNode(WayGraph* graph) { return SDK_CALL_FUNC(u16, 0x6512A0, void*, WayGraph*)(this, graph); }
		void ResetWay() { SDK_CALL_FUNC(void, 0x6582B0, void*)(this); }
		void SetLaneFlagsFromGuide(RoadNetworkGuide* guide) { SDK_CALL_FUNC(void, 0x6594F0, void*, RoadNetworkGuide*)(this, guide); }
		void SetRoadNetworkType(u32 type) { SDK_CALL_FUNC(void, 0x659900, void*, u32)(this, type); }
	};
	SDK_ASSERT_SIZEOF(VehicleWayFinderClient, 0x448);
}