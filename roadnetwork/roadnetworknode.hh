#pragma once

namespace UFG
{
	class RoadNetworkGate;
	class RoadNetworkLane;
	class RoadNetworkNode;
	class RoadNetworkSpawnPoint;
	class RoadNetworkSubSegment;

	class RoadNetworkNodeModification : public qNode<RoadNetworkNodeModification>
	{
	public:
		qArray<u32> mLaneFlagsCollection;
		RoadNetworkNode* mNode;
	};

	class RoadNetworkConnection
	{
	public:
		u32 mNumLanes;
		qOffset64<qOffset64<RoadNetworkLane*>*> mLaneList;
		qOffset64<RoadNetworkConnection*> mConnection;
		qOffset64<RoadNetworkGate*> mGate;
	};

	class RoadNetworkGate
	{
	public:
		qOffset64<RoadNetworkNode*> mNode;
		qOffset64<RoadNetworkNode*> mConnectedNode;
		qOffset64<RoadNetworkGate*> mConnectedGate;
		qVector3 mPosition;
		qVector3 mDirection;
		u32 mNumIncomingConnections;
		qOffset64<qOffset64<RoadNetworkConnection*>*> mIncomingConnection;
		u32 mNumOutgoingConnections;
		qOffset64<qOffset64<RoadNetworkConnection*>*> mOutgoingConnection;
		RoadNetworkSpawnPoint* mSpawnPoint;
	};

	class RoadNetworkNode
	{
	public:
		enum RoadNetworkType
		{
			Traffic,
			Tram,
			Ferry,
			Ocean,
			NumRoadNetworkTypes
		};

		enum Turn
		{
			Straight,
			Slight,
			Major,
			NumTurnTypes
		};

		enum Type
		{
			Segment,
			Intersection,
		};

		qEnum<Type, u16> mType;
		u16 mActive;
		u32 mNameHash;
		u32 mDataHash;
		qVector3 mPosition;
		u32 mIndex;
		qOffset64<qBezierPathCollectionMemImaged*> mPathCollection;
		i8 mNumLanes;
		i8 mNumGates;
		i8 mNumIncomingConnections;
		i8 mNumOutgoingConnections;
		qOffset64<qOffset64<RoadNetworkLane*>*> mLane;
		qOffset64<qOffset64<RoadNetworkGate*>*> mGates;
		qOffset64<qOffset64<RoadNetworkConnection*>*> mIncomingConnections;
		qOffset64<qOffset64<RoadNetworkConnection*>*> mOutgoingConnections;
		qList<RoadNetworkNodeModification> mModifications;
	};

	class RoadNetworkLane
	{
	public:
		enum LaneChangeDirection
		{
			NoChange,
			RightLane,
			LeftLane,
			EitherLane
		};

		enum LaneFlags
		{
			None,
			MissionVehicles = (1 << 0),
			AmbientTraffic = (1 << 1),
			Emergency = (1 << 2),
			NotTraffic = (1 << 3),
			Transit = (1 << 4),
			MissionVehicleWayfind = (1 << 5),
			GPS = (1 << 6),
			Any = (1 << 15),
		};

		enum LaneStatus
		{
			RED,
			YELLOW,
			GREEN
		};

		qOffset64<RoadNetworkNode*> mNode;
		qOffset64<RoadNetworkGate*> mStartGate;
		qOffset64<RoadNetworkGate*> mEndGate;
		RoadNetworkSpawnPoint* mSpawnPoint;
		f32 mSpawnT;
		u16 mLaneIndex;
		u16 mPathIndex;
		f32 mOffset;
		i8 mLaneFlags;
		i8 mDirection;
		u16 mPad1;
		f32 mStopPoint;
		i8 mNumOpposingLanes;
		i8 mNumMergeInLanes;
		i8 mNumMergeOutLanes;
		qEnum<LaneStatus, u8> mStatus;
		qOffset64<qOffset64<RoadNetworkLane*>*> mOpposingLanes;
		qOffset64<qOffset64<RoadNetworkLane*>*> mMergeInLanes;
		qOffset64<qOffset64<RoadNetworkLane*>*> mMergeOutLanes;
		qOffset64<RoadNetworkConnection*> mPrevConnection;
		qOffset64<RoadNetworkConnection*> mStartConnection;
		qOffset64<RoadNetworkConnection*> mEndConnection;
		qOffset64<RoadNetworkConnection*> mNextConnection;
		qList<RoadNetworkGuide> mCars;
	};

	class RoadNetworkSegment : public RoadNetworkNode
	{
	public:
		struct RoadSegmentBits
		{
			u32 bWayFinderNoPlayer : 1;
			u32 bWayFinderNoVehicle : 1;
			u32 bGpsRestricted : 1;
			u32 bGpsOnly : 1;
			u32 bNoTraffic : 1;
			u32 bBuildVisibleRoadNetworkByGrid : 1;
			u32 bExtendBeyondVisibleAreaLimit : 1;
			u32 nPadding : 25;
		};

		u32 mPropertyID1;
		u32 mPropertyID2;
		qPropertySet* mpPropertySetCached;
		u32 mParkingPropertyID2;
		qList<RoadNetworkSubSegment> mSubSegmentCollection;
		qEnum<RoadNetworkNode::RoadNetworkType, u32> mRoadNetworkType;
		qVector3 mMin;
		qVector3 mMax;
		f32 mSpeedLimit;
		RoadSegmentBits mBits;
	};

	class RoadNetworkSubSegment : public qNode<RoadNetworkSubSegment>
	{
	public:
		enum Status
		{
			Status_NotVisible,
			Status_Visible,
			Status_Prefered,
			Status_BlockedOwner,
			Status_Owner
		};

		RoadNetworkSegment* mParentNode;
		qVector3 mPosition;
		f32 mLength;
		u16 mActive;
		u16 mIndex;
		qEnum<Status, i16> mStatus;
		int mNumSpawnPoints;
		qVector3 mBeginPos;
		qVector3 mEndPos;
		f32* mBeginTCollection;
		f32* mEndTCollection;
		u16 mNumParkingSpots;
		qList<class ParkingSpot> mParkingSpotCollection;
	};
}