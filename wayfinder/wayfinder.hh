#pragma once

namespace UFG
{
	enum WayStarSearchState
	{
		WAYSTAR_SEARCHING,
		WAYSTAR_FULL_WAY,
		WAYSTAR_PART_WAY,
		WAYSTAR_NO_WAY
	};

	class WayFinder;
	class WayFinderClient;

	class WayStarNode : public qNode<WayStarNode>
	{
	public:
		u16 m_WayEdge;
		u16 m_WayNode;
		WayStarNode* m_ParentNode;
		f32 m_ActualCost;
		f32 m_EstimatedCost;
	};
	SDK_ASSERT_SIZEOF(WayStarNode, 0x28);

	class WayStarSearch : public qNode<WayStarSearch>
	{
	public:
		WayStarSearchState m_SearchState;
		WayStarNode* m_SolutionNode;
		WayStarNode* m_TurnAroundNode;
		int m_NumServices;
		int m_NumSteps;
		f32 m_SearchTime;
		WayFinder* m_WayFinder;
		WayFinderClient* m_WayFinderClient;
		u16 m_GoalWayNode;
		u16 m_GoalWayEdge;
		qVector3 m_GoalPosition;
		qList<WayStarNode> m_OpenNodes;
		qList<WayStarNode> m_ClosedNodes;

		/* Virtual Functions */

		virtual ~WayStarSearch() = 0;

		/* Functions */

		f32 Service(f32 time_limit_ms) { return SDK_CALL_FUNC(f32, 0xE2DF0, void*, f32)(this, time_limit_ms); }
		void AddOpenNode(WayStarNode* to_add) { SDK_CALL_FUNC(void, 0xE2780, void*, WayStarNode*)(this, to_add); }
	};

	class WayGraph
	{
	public:
		virtual ~WayGraph() = 0;
		virtual int GetNumNodes() = 0;
		virtual u32 GetNumNodeEdges(u16 node) = 0;
		virtual u16 GetNodeEdge(u16 node, u32 whichEdge) = 0;
		virtual int GetNumEdges() = 0;
		virtual bool GetEdgeNode(WayFinderClient* client, qVector3* position, const qVector3& direction, u16& edge, int& which_end) = 0;
		virtual u16 GetEdgeNode(u16 edge, int which_end) = 0;
		virtual bool GetEdge(WayFinderClient* client, qVector3* position, u16& edge) = 0;
		virtual bool IsEdge(u16 node) = 0;
		virtual qVector3 GetNodePosition(u16 node) = 0;
		virtual qVector3 GetEdgePosition(u16 edge, int which_end) = 0;
		virtual f32 GetEdgeLength(u16 edge) = 0;
	};

	class WayFinder
	{
	public:
		WayGraph* m_WayGraph;
		qList<WayStarSearch> m_WayStarSearches;

		/* Functions */

		void Service(f32 time_limit_ms) { SDK_CALL_FUNC(void, 0xE2D10, void*, f32)(this, time_limit_ms); }

		WayStarSearch* FindWay(WayFinderClient* client, const qVector3& goal_position, const qVector3* p_goal_direction = 0) {
			return SDK_CALL_FUNC(WayStarSearch*, 0xE2980, void*, WayFinderClient*, const qVector3&, const qVector3*)(this, client, goal_position, p_goal_direction);
		}

		void Cancel(WayFinderClient* client) { SDK_CALL_FUNC(void, 0xE27D0, void*, WayFinderClient*)(this, client); }
	};

	class WayFinderClient
	{
	public:
		u16 m_CurrWayEdge;
		u16 m_CurrWayNode;
		qVector3 m_CurrPos;
		qVector3 m_CurrDir;
		u16 m_NumWayEdges;
		u16 m_WayEdges[512];
		u16 m_CurrEdgeIndex;
		bool m_WayStartsWithTurnAround;

		/* Virtual Functions */

		virtual ~WayFinderClient() = 0;
	};
	SDK_ASSERT_SIZEOF(WayFinderClient, 0x430);
}