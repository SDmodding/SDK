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