#pragma once

namespace UFG
{
	//============================================================

	class CRoadNetworkWayfindingEdge;

	//============================================================

	class CRoadNetworkWayfindingNode;

	//============================================================

	class CRoadNetworkWayfindingList
	{
	public:
		uint32_t mNumEdges;
		qOffset64<CRoadNetworkWayfindingEdge> mEdgeList;
		uint32_t mNumNodes;
		qOffset64<CRoadNetworkWayfindingNode> mNodeList;
		qOffset64<unsigned long> mNodeEdges;
	};
	UFG_ASSERT_CLASS(CRoadNetworkWayfindingList, 0x28);
}