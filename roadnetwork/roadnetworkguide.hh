#pragma once

namespace UFG
{
	class RoadNetworkLocation
	{
	public:
		f32 m_LaneT;
		RoadNetworkLane* m_CurrentLane;

		/* Functions */

		void Advance(f32 advanceDist, RoadNetworkLane* nextLane, RoadNetworkLane* laneAfterNext) { 
			SDK_CALL_FUNC(void, 0xD1E70, void*, f32, RoadNetworkLane*, RoadNetworkLane*)(this, advanceDist, nextLane, laneAfterNext);
		}
		void AttachToNetwork(RoadNetworkResource* roadNetwork, const qVector3& spawnPos, const qVector3* spawnHeading, u32 type) {
			SDK_CALL_FUNC(void, 0xD29C0, void*, RoadNetworkResource*, const qVector3&, const qVector3*, u32)(this, roadNetwork, spawnPos, spawnHeading, type);
		}
	};

	class RoadNetworkGuide : public qSafePointerNode<RoadNetworkGuide>, public qNode<RoadNetworkGuide>
	{
	public:
		RoadNetworkLocation m_TargetLocation;
		RoadNetworkLocation m_CurrentLocation;
		SimObject* m_SimObj;
		RoadNetworkLane* m_NextLane;
		RoadNetworkLane* m_LaneAfterNext;
		f32 m_FrontBoundary;
		f32 m_RearBoundary;
		f32 m_ObjectWidth;
		f32 m_SpeedLimit;
		f32 m_Curvature;
		qVector3 m_Position;
		f32 m_NextGuideDistance;
		f32 m_StopPointDistance;
		f32 m_AdvanceDistance;
		qSafePointer<RoadNetworkGuide> m_NextGuide;
		bool m_Attached;
		bool m_Parked;

		/* Impl Functions */

		SDK_INLINE RoadNetworkLocation* GetTargetLocation(RoadNetworkGuide* ripple) { return &m_TargetLocation; }
		SDK_INLINE bool IsCurrentLocationValid() { return m_CurrentLocation.m_CurrentLane; }
		SDK_INLINE bool NavigationInfoNeeded() { return !m_NextLane; }
		SDK_INLINE void SetLaneAfterNext(RoadNetworkLane* roadLane) { m_LaneAfterNext = roadLane;; }

		/* Functions */

		void AttachToNetwork(SimObject* simObj, RoadNetworkNode* node, const u32 lane, f32 laneT) { 
			SDK_CALL_FUNC(void, 0xD27F0, void*, SimObject*, RoadNetworkNode*, const u32, f32)(this, simObj, node, lane, laneT); 
		}
		bool CanChangeLane(u32 laneChangeDir) { return SDK_CALL_FUNC(bool, 0xD2FD0, void*, u32)(this, laneChangeDir); }
		void ChangeLane(u32 direction) { SDK_CALL_FUNC(void, 0xD3180, void*, u32)(this, direction); }
		bool ChangeLaneIfRoom(u32 direction) { return SDK_CALL_FUNC(bool, 0xD3350, void*, u32)(this, direction); }
		void FindNextGuide() { SDK_CALL_FUNC(void, 0xD4D90, void*)(this); }
		u32 GetChangeLaneIndex(u32 direction) { return SDK_CALL_FUNC(u32, 0xD5EF0, void*, u32)(this, direction); }

		// corners needs to be array of qVector[4] or more!
		void GetCornerRays(qVector3* corners, qVector3* p_left = 0) { SDK_CALL_FUNC(void, 0xD8270, void*, qVector3*, qVector3*)(this, corners, p_left); }
		f32 GetGap(RoadNetworkGuide* otherGuide) { return SDK_CALL_FUNC(f32, 0xD8AD0, void*, RoadNetworkGuide*)(this, otherGuide); }
		RoadNetworkConnection* GetNextConnection() { return SDK_CALL_FUNC(RoadNetworkConnection*, 0xDABB0, void*)(this); }
		bool IsBlockedInMergeLanes(RoadNetworkLane* roadLane) { return SDK_CALL_FUNC(bool, 0xDD9F0, void*, RoadNetworkLane*)(this, roadLane); }
		bool IsBlockedInOpposingLanes(RoadNetworkLane* roadLane) { return SDK_CALL_FUNC(bool, 0xDDCE0, void*, RoadNetworkLane*)(this, roadLane); }
		bool IsBlocking(const qVector3& pos) { return SDK_CALL_FUNC(bool, 0xDE100, void*, const qVector3&)(this, pos); }
		bool IsClearAfterIntersection(RoadNetworkLane* lane) { return SDK_CALL_FUNC(bool, 0xDE2B0, void*, RoadNetworkLane*)(this, lane); }
		bool IsSpaceToInsertIntoLane(RoadNetworkLane* lane) { return SDK_CALL_FUNC(bool, 0xDE910, void*, RoadNetworkLane*)(this, lane); }
		bool LaneChangeAvailable(u32* whichLanes) { return SDK_CALL_FUNC(bool, 0xDF310, void*, u32*)(this, whichLanes); }
		void Park() { SDK_CALL_FUNC(void, 0xDF7D0, void*)(this); }
		void RemoveFromNetwork() { SDK_CALL_FUNC(void, 0xDFFD0, void*)(this); }
		RoadNetworkLane* TryGetPossibleSharedDestination(u32 laneIndex, u32 laneFlags) { return SDK_CALL_FUNC(RoadNetworkLane*, 0xE0CA0, void*, u32, u32)(this, laneIndex, laneFlags); }
	};
}