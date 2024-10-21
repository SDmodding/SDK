#pragma once

namespace UFG
{
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