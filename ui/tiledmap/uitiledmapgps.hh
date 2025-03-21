#pragma once

namespace UFG
{
	class MiniMapWayFinderClient : public WayFinderClient
	{
	public:
		int m_LastLaneIndex;
		bool m_AllowFootPaths;
		bool m_RestrictedMode;
		i8 m_LaneFlags;

		/* Functions */

		bool CanGo(const WayGraph* graph, u16 from_edge, u16 to_edge, u16 thru_node) {
			return SDK_CALL_FUNC(bool, 0xBE6B0, void*, const WayGraph*, u16, u16, u16)(this, graph, from_edge, to_edge, thru_node);
		}

		f32 GetEdgeLength(const WayGraph* wayGraph, u16 wayEdge) { return SDK_CALL_FUNC(f32, 0xC0F40, void*, const WayGraph*, u16)(this, wayGraph, wayEdge); }
		void ResetWay() { SDK_CALL_FUNC(void, 0xCA410, void*)(this); }
	};

	class UITiledMapGPS
	{
	public:
		f32 mGPS_UpdatePeriod;
		bool mOnlyShowInVehicles;
		bool mChanged;
		bool mDestChanged;
		bool mActive;
		bool mVisible;
		bool mInVehicle;
		bool mNoDestination;
		bool mUsePlayerSourcePos;
		bool mInteriorActive;
		bool mIsManualMapDest;
		f32 mUpdateTimer;
		u32 mMaxNumSplinePoints;
		qVector3 mSourcePos;
		qVector3 mSourceDir;
		qVector3 mDestinationPos;
		qVector3 mDestinationDir;
		MiniMapWayFinderClient mWayFinderClient;
		qArray<qVector3> mSplinePoints;
		u32 mNumSplinePoints;
		RoadNetworkLane* mTrueDirectionIntersectionLane;
		bool mTrueDirectionHighwayRamp;
		u32 mTrueDirectionEdgeCount;
		qSafePointer<SimComponent, HudComponent> mTrackingTarget;

		/* Static Functions */

		SDK_SINLINE UITiledMapGPS* Instance() { return SDK_VAR_GET(UITiledMapGPS*, 0x24310A0); }

		/* Impl Functions */

		SDK_INLINE void SetActive(bool value) { mChanged |= mActive != value; mActive = value; }
		SDK_INLINE void SetVisible(bool value) { mChanged |= mVisible != value; mVisible = value; }
		SDK_INLINE void UsePlayerSourcePosition() { mUsePlayerSourcePos = 1; }

		/* Functions */

		bool AddSplinePoint(const RoadNetworkLane* roadLane, f32 laneT) { return SDK_CALL_FUNC(bool, 0xBE470, void*, const RoadNetworkLane*, f32)(this, roadLane, laneT); }
		void DoGenerateSpline() { SDK_CALL_FUNC(void, 0xBEEF0, void*)(this); }
		f32 GetApproxAltitude(const qVector3& pos) { return SDK_CALL_FUNC(f32, 0xC0CE0, const qVector3&)(pos); }
		f32 GetPathLength() { return SDK_CALL_FUNC(f32, 0xC44C0, void*)(this); }
		void HandleArrivedAtManualMapDestination() { SDK_CALL_FUNC(void, 0xC4B20, void*)(this); }
		void HandleScreenInit(UIScreen* screen) { SDK_CALL_FUNC(void, 0xC4D70, void*, UIScreen*)(this, screen); }
		void Initialize() { SDK_CALL_FUNC(void, 0xC5B60, void*)(this); }
		bool IsVisible() { return SDK_CALL_FUNC(bool, 0xC5E30, void*)(this); }

		void PlotRoadLane(const RoadNetworkLane* roadLane, f32 startLaneT, f32 endLaneT, bool plotFirstPoint) {
			SDK_CALL_FUNC(void, 0xC6230, void*, const RoadNetworkLane*, f32, f32, bool)(this, roadLane, startLaneT, endLaneT, plotFirstPoint);
		}

		void PopulateWorldMap(UITiledMapGPS* clone) { SDK_CALL_FUNC(void, 0xC66A0, void*, UITiledMapGPS*)(this, clone); }
		void SetDestination(const qVector3& dest, bool isManualMapDest) { SDK_CALL_FUNC(void, 0xCA6F0, void*, const qVector3&, bool)(this, dest, isManualMapDest); }
		void SetTrackingTarget(HudComponent* target) { SDK_CALL_FUNC(void, 0xCB7A0, void*, HudComponent*)(this, target); }
		void SetWayfinderIgnoreAlleys(bool ignore) { SDK_CALL_FUNC(void, 0xCB8E0, void*, bool)(this, ignore); }
		void Update(f32 elapsed, UIScreen* screen, const UITiledMapMath& geo) { SDK_CALL_FUNC(void, 0xCC6A0, void*, f32, UIScreen*, const UITiledMapMath&)(this, elapsed, screen, geo); }
		void UpdatePlayerPos() { SDK_CALL_FUNC(void, 0xCE080, void*)(this); }
		void UpdateRace() { SDK_CALL_FUNC(void, 0xCE300, void*)(this); }
		void UpdateTrueDirection() { SDK_CALL_FUNC(void, 0xCE520, void*)(this); }
	};
}