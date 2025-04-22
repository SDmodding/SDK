#pragma once

namespace UFG
{
	class RoadBlock : public qNode<RoadBlock>
	{
	public:
		RoadNetworkSegment* mSourceNode;
		RoadNetworkSegment* mDestinationNode;
		RoadNetworkNode* mTargetNode;
		RoadNetworkNodeModification* mModification;
	};

	class RoadNetworkGraph : public WayGraph
	{
	public:
		u32 mRoadNetworkType;
		RoadNetworkWayfindingList* pWayfindingList;
		RoadNetworkResource* pRoadNetworkResource;
	};

	class WheeledVehicleNavigationData
	{
	public:
		qProxy<RoadNetworkGraph> m_RoadNetworkGraph;
		qProxy<RoadNetworkGraph> m_TrafficGraph;
		qProxy<RoadNetworkGraph> m_TramGraph;
		qProxy<RoadNetworkGraph> m_FerryGraph;
		qProxy<RoadNetworkGraph> m_OceanGraph;
		WayFinder mTrafficWayFinder;
		WayFinder mTramWayFinder;
		WayFinder mFerryWayFinder;
		WayFinder mOceanWayFinder;
		qList<RoadBlock, RoadBlock, 1> m_RoadBlockList;
		bool m_Valid;

		/* Static Functions */

		SDK_SINLINE RoadNetworkResource* GetRoadNetwork() { return SDK_VAR_GET(RoadNetworkResource*, 0x2174A50); }

		/* Functions */

		void RemoveRoadBlocksAroundSegment(RoadNetworkSegment* segment) { SDK_CALL_FUNC(void, 0x658000, void*, RoadNetworkSegment*)(this, segment); }
		void InitGlobalData() { SDK_CALL_FUNC(void, 0x6514E0, void*)(this); }
		WayFinder* GetRoadWayFinder(VehicleWayFinderClient* client) { return SDK_CALL_FUNC(WayFinder*, 0x64F310, void*, VehicleWayFinderClient*)(this, client); }
		RoadNetworkGraph* GetRoadNetworkGraph(VehicleWayFinderClient* client) { return SDK_CALL_FUNC(RoadNetworkGraph*, 0x64F2A0, void*, VehicleWayFinderClient*)(this, client); }
		RoadNetworkGraph* GetRoadNetworkGraph(RoadNetworkNode::RoadNetworkType type) { return SDK_CALL_FUNC(RoadNetworkGraph*, 0x64F2E0, void*, RoadNetworkNode::RoadNetworkType)(this, type); }
		void AddRoadBlocksAroundSegment(RoadNetworkGate* segment) { SDK_CALL_FUNC(void, 0x644CC0, void*, RoadNetworkGate*)(this, segment); }
		void AddRoadBlock(RoadNetworkSegment* source, RoadNetworkSegment* dest) { SDK_CALL_FUNC(void, 0x644970, void*, RoadNetworkSegment*, RoadNetworkSegment*)(this, source, dest); }
	};
	SDK_ASSERT_SIZEOF(WheeledVehicleNavigationData, 0x118);
}