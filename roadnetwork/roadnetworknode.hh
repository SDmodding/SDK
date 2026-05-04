#pragma once

namespace UFG
{
	class RoadNetworkGate;
	class RoadNetworkGuide;
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

		void GetValidLanes(u32 laneFlags, qArray<u32>& laneIDs) { SDK_CALL_FUNC(void, 0xDC5C0, void*, u32, qArray<u32>&)(this, laneFlags, laneIDs); }
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

		/* Functions */

		RoadNetworkLane* GetAnyLaneLeadingHereFromNode(RoadNetworkNode* targetNode) { return SDK_CALL_FUNC(RoadNetworkLane*, 0xD5A00, void*, RoadNetworkNode*)(this, targetNode); }
		RoadNetworkLane* GetAnyLaneLeadingToNode(RoadNetworkNode* targetNode) { return SDK_CALL_FUNC(RoadNetworkLane*, 0xD5B30, void*, RoadNetworkNode*)(this, targetNode); }
		RoadNetworkLane* GetFirstOutgoingLaneLeadingToNode(RoadNetworkNode* targetNode) { return SDK_CALL_FUNC(RoadNetworkLane*, 0xD8840, void*, RoadNetworkNode*)(this, targetNode); }
		RoadNetworkConnection* GetIncomingConnection(u32 index) { return SDK_CALL_FUNC(RoadNetworkConnection*, 0xD8D80, void*, u32)(this, index); }
		void GetLanesLeadingToNode(RoadNetworkNode* targetNode, RoadNetworkLane** laneList, u32* numLanes, u32 maxLanes, u32 laneFlags) { 
			SDK_CALL_FUNC(void, 0xD9D40, void*, RoadNetworkNode*, RoadNetworkLane**, u32*, u32, u32)(this, targetNode, laneList, numLanes, maxLanes, laneFlags);
		}
		RoadNetworkConnection* GetOutgoingConnection(u32 index) { return SDK_CALL_FUNC(RoadNetworkConnection*, 0xDB330, void*, u32)(this, index); }
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

		/* Impl Functions */

		SDK_INLINE u32 GetCenterLaneIndex() { return (mNumLanes - 1) / 2; }

		/* Functions*/

		RoadNetworkNodeModification* AddChangeLaneFlagsModification(qArray<u32>& laneFlags) { return SDK_CALL_FUNC(RoadNetworkNodeModification*, 0xD1740, void*, qArray<u32>&)(this, laneFlags); }
		void ApplyAllModifications() { SDK_CALL_FUNC(void, 0xD2370, void*)(this); }
		RoadNetworkLane* GetCenterLane() { return SDK_CALL_FUNC(RoadNetworkLane*, 0xD5EA0, void*)(this); }
		RoadNetworkLane* GetClosestLane(const qVector3& pos) { return SDK_CALL_FUNC(RoadNetworkLane*, 0xD69B0, void*, const qVector3&)(this, pos); }

		qVector3 GetClosestPosition(const qVector3& pos, f32* nearestT = 0)
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xD70B0, void*, qVector3*, const qVector3&, f32*)(this, &res, pos, nearestT); 
		}

		f32 GetClosestT(u32 laneIndex, const qVector3& position) { return SDK_CALL_FUNC(f32, 0xD81D0, void*, u32, const qVector3&)(this, laneIndex, position); }
		RoadNetworkLane* GetLane(const u32 index) { return SDK_CALL_FUNC(RoadNetworkLane*, 0xD94E0, void*, const u32)(this, index); }

		qVector3 GetNearestPos(const qVector3& pos, RoadNetworkLane** nearestLane, f32& nearestT)
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xDAA30, void*, qVector3*, const qVector3&, RoadNetworkLane**, f32&)(this, &res, pos, nearestLane, nearestT);
		}

		qVector3 GetNearestPos(const qVector3& pos, const qVector3& _heading, RoadNetworkLane** nearestLane, f32& nearestT)
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xDA430, void*, qVector3*, const qVector3&, const qVector3&, RoadNetworkLane**, f32&)(this, &res, pos, _heading, nearestLane, nearestT);
		}

		qVector3 GetPos(u32 laneIndex, f32 laneT)
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xDB470, void*, qVector3*, u32, f32)(this, &res, laneIndex, laneT);
		}

		qVector3 GetTangent(u32 laneIndex, f32 laneT)
		{
			qProxy<qVector3> res;
			return *SDK_CALL_FUNC(qVector3*, 0xDC020, void*, qVector3*, u32, f32)(this, &res, laneIndex, laneT);
		}

		bool IsConnectedToNode(RoadNetworkNode* roadNode) { return SDK_CALL_FUNC(bool, 0xDE3D0, void*, RoadNetworkNode*)(this, roadNode); }
		bool IsWater() { return SDK_CALL_FUNC(bool, 0xDEF20, void*)(this); }
		void RemoveModification(RoadNetworkNodeModification* modification) { SDK_CALL_FUNC(void, 0xE0000, void*, RoadNetworkNodeModification*)(this, modification); }
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

		enum LaneTurnDirection
		{
			Straight,
			LeftTurn,
			RightTurn
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

		// Index to Bezier Path Collection of node.
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

		/* Static Functions */

		SDK_SINLINE qVector3 GetOffsetPos(const qBezierSplineMemImaged* spline, f32 t, f32 offset) { return SDK_CALL_FUNC(qVector3, 0xDB180, const qBezierSplineMemImaged*, f32, f32)(spline, t, offset); }
		SDK_SINLINE bool GetOffsetPosAndTangent(const qBezierSplineMemImaged* spline, f32 t, f32 offset, qVector3& pos, qVector3& tangent) { 
			return SDK_CALL_FUNC(bool, 0xDB270, const qBezierSplineMemImaged*, f32, f32, qVector3&, qVector3&)(spline, t, offset, pos, tangent); 
		}

		/* Impl Functions */

		SDK_INLINE LaneStatus GetStatus() { return static_cast<LaneStatus>(mStatus.mValue); }
		SDK_INLINE bool IsFlagMatch(u32 laneFlags) { return mLaneFlags & laneFlags; }

		/* Functions */

		void AddCarGuide(RoadNetworkGuide* guide, bool spawned) { SDK_CALL_FUNC(void, 0xD1640, void*, RoadNetworkGuide*, bool)(this, guide, spawned); }
		f32 CalculateParkingOffset(const qVector3& position) { return SDK_CALL_FUNC(f32, 0xD2DA0, void*, const qVector3&)(this, position); }
		RoadNetworkGuide* GetClosestCarToStart() { return SDK_CALL_FUNC(RoadNetworkGuide*, 0xD5F50, void*)(this); }
		f32 GetClosestT(const qVector3& pos) { return SDK_CALL_FUNC(f32, 0xD8160, void*, const qVector3&)(this, pos); }
		LaneChangeDirection GetLaneDirection(RoadNetworkLane* otherLane) { return SDK_CALL_FUNC(LaneChangeDirection, 0xD9510, void*, RoadNetworkLane*)(this, otherLane); }
		f32 GetLength() { return SDK_CALL_FUNC(f32, 0xD9EE0, void*)(this); }
		qVector3 GetNearestPoint(const qVector3& pos, f32* laneT = 0) { return SDK_CALL_FUNC(qVector3, 0xDA3C0, void*, const qVector3&, f32*)(this, pos, laneT); }
		u32 GetNumberOfCarsInLaneAheadOfDistance(f32 d) { return SDK_CALL_FUNC(u32, 0xDAF70, void*, f32)(this, d); }
		qVector3 GetOffsetPos(f32 t, f32 offset) { return SDK_CALL_FUNC(qVector3, 0xDB0D0, void*, f32, f32)(this, t, offset); }

		qVector3 GetPos(f32 t) 
		{
			qVector3 res;
			return *SDK_CALL_FUNC(qVector3*, 0xDB360, void*, qVector3&, f32)(this, res, t); 
		}

		bool GetPosAndTangent(f32 t, qVector3& pos, qVector3& tangent) { return SDK_CALL_FUNC(bool, 0xDB4C0, void*, f32, qVector3&, qVector3&)(this, t, pos, tangent); }
		qVector3 GetPosNoOffset(f32 laneT) { return SDK_CALL_FUNC(qVector3, 0xDB570, void*, f32)(this, laneT); }
		LaneTurnDirection GetTurnDirection() { return SDK_CALL_FUNC(LaneTurnDirection, 0xDC430, void*)(this); }
		bool IsPermissive(bool checkCurrentPhaseOnly) { return SDK_CALL_FUNC(bool, 0xDE7A0, void*, bool)(this, checkCurrentPhaseOnly); }
		bool IsReversedInNode() { return SDK_CALL_FUNC(bool, 0xDE8A0, void*)(this); }
		bool LaneChangeAvailable(u32* whichLanes) { return SDK_CALL_FUNC(bool, 0xDF350, void*, u32*)(this, whichLanes); }
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

		// RoadID
		// Lookup each listProperty in RoadSet and check if it matches RoadID property
		u32 mPropertyID1;

		// RoadIDAdditional
		// Similar to 'mPropertyID1', but instead it searches listProperty called 'default-roadnetwork-additional-roadset'.
		// Used only to set 'BuildVisibleRoadNetworkByGrid' in mBits.
		u32 mPropertyID2;

		// Cached propertySet of mPropertyID1.
		qPropertySet* mpPropertySetCached;

		u32 mParkingPropertyID2;

		// Constructed while loaded as resource, based on center lane and bezier path length.
		qList<RoadNetworkSubSegment> mSubSegmentCollection;

		// Initialized from PropertySet if it has 'RoadNetworkType' property.
		qEnum<RoadNetworkType, u32> mRoadNetworkType;

		// World space AABB
		qVector3 mMin, mMax;

		// Defaults to 13.8 if its 0.0
		f32 mSpeedLimit;

		// All bits are reset when segment is loaded as resource.
		// They're set from PropertySet later on by 'WheeledVehicleNavigationData::InitGlobalData'.
		RoadSegmentBits mBits;

		/* Functions */

		void AddParkingSpot(ParkingSpot* spot) { SDK_CALL_FUNC(void, 0xD1CC0, void*, ParkingSpot*)(this, spot); }
		void CreateSubSegments() { SDK_CALL_FUNC(void, 0xD3F00, void*)(this); }
		qPropertySet* GetAdditionalRoadPropertySet() { return SDK_CALL_FUNC(qPropertySet*, 0xD5950, void*)(this); }
		RoadNetworkLane* GetClosestLaneToCenter(u32 index) { return SDK_CALL_FUNC(RoadNetworkLane*, 0xD69F0, void*, u32)(this, index); }
		RoadNetworkSubSegment* GetClosestSubSegment(RoadNetworkGate* gate) { return SDK_CALL_FUNC(RoadNetworkSubSegment*, 0xD80C0, void*, RoadNetworkGate*)(this, gate); }
		RoadNetworkSubSegment* GetClosestSubSegment(const qVector3& position) { return SDK_CALL_FUNC(RoadNetworkSubSegment*, 0xD7E20, void*, const qVector3&)(this, position); }
		f32 GetMatchingT(const u32 laneIndex, double t, const u32 otherLaneIndex) { return SDK_CALL_FUNC(f32, 0xD9F20, void*, const u32, double, const u32)(this, laneIndex, t, otherLaneIndex); }
		f32 GetRoadDensity() { return SDK_CALL_FUNC(f32, 0xDB6B0, void*)(this); }
		RoadNetworkType GetRoadNetworkType() { return SDK_CALL_FUNC(RoadNetworkType, 0xDB850, void*)(this); }
		qPropertySet* GetRoadPropertySet() { return SDK_CALL_FUNC(qPropertySet*, 0xDB8A0, void*)(this); }
		f32 GetTFromDistance(RoadNetworkLane* lane, f32 distance, f32 beginT, bool forward) { return SDK_CALL_FUNC(f32, 0xDBF30, void*, RoadNetworkLane*, f32, f32, bool)(this, lane, distance, beginT, forward); }
		bool IsWater() { return SDK_CALL_FUNC(bool, 0xDEFA0, void*)(this); }
		void RecalculateLaneOffset(u32 laneIndex) { SDK_CALL_FUNC(void, 0xDF800, void*, u32)(this, laneIndex); }
		void SetBitsFromRoadPropertySet() { SDK_CALL_FUNC(void, 0xE0200, void*)(this); }
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
		qList<ParkingSpot> mParkingSpotCollection;

		/* Impl Functions */

		SDK_INLINE f32 GetBeginT(u32 laneIndex) { return mBeginTCollection[laneIndex]; }
		SDK_INLINE f32 GetEndT(u32 laneIndex) { return mEndTCollection[laneIndex]; }

		/* Functions */

		void GetAvailableParkingSpots(qArray<ParkingSpot*>& availableParkingSpots) { SDK_CALL_FUNC(void, 0xD5CB0, void*, qArray<ParkingSpot*>&)(this, availableParkingSpots); }
		void GetGatesConnectedToSubSegment(qArray<RoadNetworkGate*>& gateCollection) { SDK_CALL_FUNC(void, 0xD8DB0, void*, qArray<RoadNetworkGate*>&)(this, gateCollection); }
		u32 GetNumAvailableParkingSpots() { return SDK_CALL_FUNC(u32, 0xDAF00, void*)(this); }
		bool IsWithinSubSegment(RoadNetworkLane* roadLane, f32 laneT) { return SDK_CALL_FUNC(bool, 0xDF000, void*, RoadNetworkLane*, f32)(this, roadLane, laneT); }
	};

	class RoadNetworkTrafficLightLocation
	{
	public:
		qVector3 mPosition;
		qVector3 mDirection;
		u32 mFlags;
		u32 mVehicleSignalEffect;
		u32 mPedestrianSignalEffect;
	};

	class RoadNetworkTrafficLight
	{
	public:
		qOffset64<RoadNetworkTrafficLightLocation*> mLocation;
	};

	class RoadNetworkTrafficLightPhase
	{
	public:
		u32 mIndex;
		f32 mGreenLightTime;
		f32 mYellowLightTime;
		u32 mNumProtectedLanes;
		u32 mNumPermissiveLanes;
		u32 mNumTrafficLights;
		RoadNetworkLane::LaneStatus mCurrentStatus;
		qOffset64<qOffset64<RoadNetworkLane*>*> mProtectedLanes;
		qOffset64<qOffset64<RoadNetworkLane*>*> mPermissiveLanes;
		qOffset64<qOffset64<RoadNetworkTrafficLight*>*> mTrafficLightCollection;
	};

	class RoadNetworkIntersectionModification : public RoadNetworkNodeModification
	{
	public:
		enum AllPhaseStatus
		{
			Normal_Behaviour,
			All_Red,
			All_Yellow,
			All_Green
		};

		AllPhaseStatus mAllPhaseStatus;
	};

	class RoadNetworkIntersection : public RoadNetworkNode
	{
	public:
		qOffset64<qOffset64<RoadNetworkTrafficLightLocation*>*> mTrafficLightLocations;
		i8 mNumTrafficLightLocations;
		i8 mIsMerged;

		// Defaults to 1
		i8 mEnableTimer;

		i8 mNumLightPhases;
		qOffset64<qOffset64<RoadNetworkTrafficLightPhase*>*> mLightPhases;
		u32 mCurrentPhaseIndex;
		f32 mTimer;
		qVector3 mAABBMin;
		qVector3 mAABBMax;

		/* Functions */

		void AddLanesToGateModification(u32 gateIndex, u32 flags) { SDK_CALL_FUNC(void, 0xD1940, void*, u32, u32)(this, gateIndex, flags); }
		void AddPhaseModification(RoadNetworkIntersectionModification::AllPhaseStatus status) { SDK_CALL_FUNC(void, 0xD1DF0, void*, RoadNetworkIntersectionModification::AllPhaseStatus)(this, status); }
		void ApplyModification(RoadNetworkNodeModification* modification) { SDK_CALL_FUNC(void, 0xD23F0, void*, RoadNetworkNodeModification*)(this, modification); }
		void EnableLanes(RoadNetworkTrafficLightPhase* phase, bool updateTrafficLightEffects) { SDK_CALL_FUNC(void, 0xD4590, void*, RoadNetworkTrafficLightPhase*, bool)(this, phase, updateTrafficLightEffects); }
		bool GetBuildVisibleRoadNetworkByGrid() { return SDK_CALL_FUNC(bool, 0xD5E30, void*)(this); }
		RoadNetworkGate* GetClosestGate(const qVector3& pos) { return SDK_CALL_FUNC(RoadNetworkGate*, 0xD5F70, void*, const qVector3&)(this, pos); }
		bool GetExtendBeyondVisibleAreaLimit() { return SDK_CALL_FUNC(bool, 0xD87C0, void*)(this); }
		f32 GetIntersectionRadius() { return SDK_CALL_FUNC(f32, 0xD8F60, void*)(this); }
		f32 GetRemainingGreenLightTime() { return SDK_CALL_FUNC(f32, 0xDB620, void*)(this); }
		RoadNetworkNode::RoadNetworkType GetRoadNetworkType() { return SDK_CALL_FUNC(RoadNetworkNode::RoadNetworkType, 0xDB7A0, void*)(this); }
		RoadNetworkTrafficLightPhase* GetTrafficLightPhase(u32 index) { return SDK_CALL_FUNC(RoadNetworkTrafficLightPhase*, 0xDC3F0, void*, u32)(this, index); }
		void InitializePhases() { SDK_CALL_FUNC(void, 0xDD970, void*)(this); }
		bool IsWater() { return SDK_CALL_FUNC(bool, 0xDEE50, void*)(this); }
	};
}