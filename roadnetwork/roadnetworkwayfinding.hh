#pragma once

namespace UFG
{
	class RoadNetworkWayfindingNode
	{
	public:
		u32 mFirstEdgeIndex;
		u32 mNumEdges;
	};

	class RoadNetworkWayfindingEdge
	{
	public:
		u32 mNode1Index;
		u32 mNode2Index;
	};

	class RoadNetworkWayfindingList
	{
	public:
		u32 mNumEdges;
		qOffset64<RoadNetworkWayfindingEdge*> mEdgeList;
		u32 mNumNodes;
		qOffset64<RoadNetworkWayfindingNode*> mNodeList;
		qOffset64<u32*> mNodeEdges;

		/* Functions */

		RoadNetworkWayfindingEdge* GetEdge(u32 index) { return SDK_CALL_FUNC(RoadNetworkWayfindingEdge*, 0xD8790, void*, u32)(this, index); }
		RoadNetworkWayfindingNode* GetNode(u32 index) { return SDK_CALL_FUNC(RoadNetworkWayfindingNode*, 0xDAE90, void*, u32)(this, index); }
		u32 GetNodeEdge(u32 node_index, u32 which_edge) { return SDK_CALL_FUNC(u32, 0xDAEC0, void*, u32, u32)(this, node_index, which_edge); }
	};
}