#pragma once

namespace UFG
{
	//============================================================
	// Structs that are used for RoadNetworkNode...

	struct qBezierKnot
	{
		qVector3 vIn;
		qVector3 vKnot;
		qVector3 vOut;
	};
	UFG_ASSERT_STRUCT(qBezierKnot, 0x24);

	struct qBezierLookup
	{
		float mSplineDistance;
	};
	UFG_ASSERT_STRUCT(qBezierLookup, 0x4);

	struct qBezierSplineMemImaged
	{
		uint32_t mNumKnots;
		float mLength;
		qOffset64<qBezierKnot> mKnotTable;
		qOffset64<qBezierLookup> mLookupTable;
	};
	UFG_ASSERT_STRUCT(qBezierSplineMemImaged, 0x18);

	struct qBezierPathMemImaged
	{
		uint32_t mNumSplines;
		float mLength;
		qOffset64<qOffset64<qBezierSplineMemImaged>> mSplineOffsetTable;
	};
	UFG_ASSERT_STRUCT(qBezierPathMemImaged, 0x10);

	struct qBezierPathCollectionMemImaged
	{
		uint32_t mNumPaths;
		qOffset64<qOffset64<qBezierPathMemImaged>> mPathOffsetTable;
	};
	UFG_ASSERT_STRUCT(qBezierPathCollectionMemImaged, 0x10);

	//============================================================

	class CRoadNetworkConnection;
	class CRoadNetworkGate;
	class CRoadNetworkLane;
	class CRoadNetworkNodeModification;

	//============================================================

	class CRoadNetworkNode
	{
	public:
		enum Type : uint16_t
		{
			Segment = 0x0,
			Intersection = 0x1,
		};

		enum RoadNetworkType : uint32_t
		{
			Traffic = 0x0,
			Tram = 0x1,
			Ferry = 0x2,
			Ocean = 0x3,
			NumRoadNetworkTypes = 0x4,
		};


		Type mType;
		uint16_t mActive;
		uint32_t mNameHash;
		uint32_t mDataHash;
		qVector3 mPosition;
		uint32_t mIndex;
		qOffset64<qBezierPathCollectionMemImaged> mPathCollection;
		char mNumLanes;
		char mNumGates;
		char mNumIncomingConnections;
		char mNumOutgoingConnections;
		qOffset64<qOffset64<CRoadNetworkLane>> mLanes;
		qOffset64<qOffset64<CRoadNetworkGate>> mGates;
		qOffset64<qOffset64<CRoadNetworkConnection>> mIncomingConnections;
		qOffset64<qOffset64<CRoadNetworkConnection>> mOutgoingConnections;
		qList<CRoadNetworkNodeModification> mModifications;

		UFG_INLINE CRoadNetworkLane* GetLane(uint32_t p_Index)
		{
			return reinterpret_cast<CRoadNetworkLane*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0xD94E0))(this, p_Index);
		}

		UFG_INLINE CRoadNetworkLane* GetClosestLane(const qVector3& p_Position)
		{
			return reinterpret_cast<CRoadNetworkLane*(__fastcall*)(void*, const qVector3&)>(UFG_RVA(0xD69B0))(this, p_Position);
		}
		
		UFG_INLINE qVector3* GetClosestPosition(qVector3* p_Result, const qVector3& p_Position, float* p_NearestT = nullptr)
		{
			return reinterpret_cast<qVector3*(__fastcall*)(void*, qVector3*, const qVector3&, float*)>(UFG_RVA(0xD70B0))(this, p_Result, p_Position, p_NearestT);
		}
	};
	UFG_ASSERT_CLASS(CRoadNetworkNode, 0x60);
}