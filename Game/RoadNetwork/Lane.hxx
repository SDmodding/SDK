#pragma once

namespace UFG
{
	//============================================================

	class CRoadNetworkGuide;
	class CRoadNetworkSpawnPoint;

	//============================================================

	class CRoadNetworkLane
	{
	public:
		enum LaneStatus : uint8_t
		{
			RED = 0x0,
			YELLOW = 0x1,
			GREEN = 0x2,
		};

		qOffset64<CRoadNetworkNode> mNode;
		qOffset64<CRoadNetworkGate> mStartGate;
		qOffset64<CRoadNetworkGate> mEndGate;
		CRoadNetworkSpawnPoint* mSpawnPoint;
		float mSpawnT;
		uint16_t mLaneIndex;
		uint16_t mPathIndex;
		float mOffset;
		char mLaneFlags;
		char mDirection;

		UFG_PAD_ALIGN(0x2);

		float mStopPoint;
		char mNumOpposingLanes;
		char mNumMergeInLanes;
		char mNumMergeOutLanes;
		LaneStatus mStatus;
		qOffset64<qOffset64<CRoadNetworkLane>> mOpposingLanes;
		qOffset64<qOffset64<CRoadNetworkLane>> mMergeInLanes;
		qOffset64<qOffset64<CRoadNetworkLane>> mMergeOutLanes;
		qOffset64<CRoadNetworkConnection> mPrevConnection;
		qOffset64<CRoadNetworkConnection> mStartConnection;
		qOffset64<CRoadNetworkConnection> mEndConnection;
		qOffset64<CRoadNetworkConnection> mNextConnection;
		qList<CRoadNetworkGuide> mCars;

		UFG_INLINE qVector3* GetPos(qVector3* p_Result, float p_Length = 1.f)
		{
			return reinterpret_cast<qVector3*(__fastcall*)(void*, qVector3*, float)>(UFG_RVA(0xDB360))(this, p_Result, p_Length);
		}
	};
	UFG_ASSERT_CLASS(CRoadNetworkLane, 0x80);
}