#pragma once

namespace UFG
{
	class AISidewalkNode_Game;
	class AISidewalkEdge_Game;
	class AISidewalkSectionResource;

	template <typename T>
	class SidewalkCommonHandle : public qTypedResourceHandle<RTypeUID_AISidewalkSectionResource, AISidewalkSectionResource>
	{
	public:
		u16 mIndex;
		u16 mIsEdgeHandle;
		u32 mObjUID;
		T* mPtr;
	};

	class AISidewalkNode_Game
	{
	public:
		qVector3 mPos;
		u32 mObjId;
		u32 mCellId;
		f32 mRadius;
		qOffset64<qOffset64<SidewalkCommonHandle<AISidewalkEdge_Game>*>*> mConnections;
		u16 mConnectionsCount;
		u16 mActive;
	};

	class AISidewalkEdge_Game
	{
	public:
		enum EdgeFlags
		{
			EdgeFlags_None = 0,
			EdgeFlags_StartActive = (1 << 0),
			EdgeFlags_Active = (1 << 1),
			EdgeFlags_Crosswalk = (1 << 2),
			EdgeFlags_AllowForwardTraversal = (1 << 3),
			EdgeFlags_AllowBackwardTraversal = (1 << 4),
			EdgeFlags_Degenerate = (1 << 5),
			EdgeFlags_Interior = (1 << 6),
			EdgeFlags_Error = (1 << 7),

			NUM_EDGE_FLAGS = 8,

			EdgeFlags_All = 0xFF,
			EdgeFlags_SearchableMask = 0xFC,
		};


		qOffset64<SidewalkCommonHandle<AISidewalkNode_Game>*> mpStartNodeHandle;
		qOffset64<SidewalkCommonHandle<AISidewalkNode_Game>*> mpEndNodeHandle;
		u32 mObjId;
		u32 mCellId;
		u32 mFlags;
		qVector3 mOutlineVerts[4];
		u16 mLineSegmentCheckID;
		u16 dummy;
	};

	class AISidewalkSectionResource : public qResourceData
	{
	public:
		u32 mSectionVisId;
		u16 mNodeHandleCount;
		u16 mEdgeHandleCount;
		u32 mNodeCount;
		u32 mEdgeCount;
		qOffset64<AISidewalkNode_Game*> mNodes;
		qOffset64<SidewalkCommonHandle<AISidewalkNode_Game>*> mNodeHandles;
		qOffset64<AISidewalkEdge_Game*> mEdges;
		qOffset64<SidewalkCommonHandle<AISidewalkEdge_Game>*> mEdgeHandles;
	};
}