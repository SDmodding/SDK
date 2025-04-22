#pragma once

namespace UFG
{
	class WayTraversal
	{
	public:
		WayGraph* pWayGraph;
		qList<WayTraversalSearch> lSearches;
	};

	class WayTraversalClient : public VehicleWayFinderClient
	{
	public:
		u16 nWayNodes;
		u16 aWayNodes[512];
	};
	SDK_ASSERT_SIZEOF(WayTraversalClient, 0x850);

	class WayTraversalSearch : public qNode<WayTraversalSearch>
	{
	public:
		WayStarSearchState nState;
		WayStarNode* pCandidates[512];
		int nCandidates;
		int nServices;
		int nSteps;
		f32 fSearchTime;
		WayTraversal* pFinder;
		WayTraversalClient* pClient;
		u16 nGoalNode;
		u16 nGoalEdge;
		qVector3 vSourcePosition;
		qVector3 vClosestPosition;
		qVector3 vGoalDirection;
		f32 fGoalMinRadius;
		f32 fGoalMaxRadius;
		qList<WayStarNode> lOpen;
		qList<WayStarNode> lClosed;

		virtual ~WayTraversalSearch() = 0;
	};
	SDK_ASSERT_SIZEOF(WayTraversalSearch, 0x1090);
}