#pragma once

namespace UFG
{
	class RoadSpaceComponent : public SimComponent, public qNode<RoadSpaceComponent>
	{
	public:
		enum { _TypeUID = 0xDA000001 };

		struct RoadSpaceBits
		{
			u32 mDeleteIfNoChasers : 1;
			u32 mUseFormation : 1;
			u32 mSubjectContainsPlayer : 1;
			u32 mSlowDownForRaceCurvature : 1;
			u32 mPadding : 28;
		};

		qProxy<NavGuide> m_NavGuide;
		f32 m_DestNavRadius;
		qVector3 m_NavWanderDestPos;
		f32 m_NavWanderRadius;
		bool m_HasNavWanderCenter;
		qVector3 m_NavWanderCenter;
		RoadNetworkGuide mGuide;
		VehicleWayFinderClient mWayClient;
		qVector3 mDestinationPosition;
		qVector3 mDestinationDirection;
		RacePosition* m_pRacePosition;
		RacePosition* m_pRacePositionSteer;
		qSafePointer<SimObject> m_pChaseTarget;
		VehicleFormations* m_pChaseFormation;
		RebindingComponentHandle<CameraSubject> m_pSubject;
		qMatrix44 m_ChaseWorld;
		qMatrix44 m_WorldChase;
		f32 m_fChaseDistance;
		f32 m_fTrailDistance;
		f32 m_fChaseCurvature;
		f32 m_fChaseFailedTimer;
		CrumbTrail m_PositionTrail;
		u32 m_LaneFlags;
		bool m_NavGuideEnabled;
		RoadSpaceBits mBits;

		/* Static Functions */

		SDK_SINLINE qVector3 SteerTo(const qVector3& centre, f32 radius, const qVector3& point, const qVector3& ray) {
			return SDK_CALL_FUNC(qVector3, 0x65AE80, const qVector3&, f32, const qVector3&, const qVector3&)(centre, radius, point, ray);
		}

		/* Impl Functions */

		SDK_INLINE bool IsAttachedToRoadNetwork() { return mGuide.m_Attached; }
		SDK_INLINE bool IsNavGuideEnabled() { return m_NavGuideEnabled; }
		SDK_INLINE void SetLaneFlags(u32 flagMask) { m_LaneFlags = flagMask; }

		/* Functions */

		void AttachToRoadNetwork(const qVector3& position, const qVector3& forward) { SDK_CALL_FUNC(void, 0x6451F0, void*, const qVector3&, const qVector3&)(this, position, forward); }
		void AttachToRoadNetwork(bool consider_heading) { SDK_CALL_FUNC(void, 0x6452F0, void*, bool)(this, consider_heading); }
		qVector3 ChaseToWorld(const qVector3& position, const qVector3& p_direction) {
			return SDK_CALL_FUNC(qVector3, 0x647BD0, void*, const qVector3&, const qVector3&)(this, position, p_direction);
		}
		qVector3 ClampToRoad(const qVector3& initialPos, const qVector3& targetPos) {
			return SDK_CALL_FUNC(qVector3, 0x649040, void*, const qVector3&, const qVector3&)(this, initialPos, targetPos);
		}
		bool CleanupOnRaceDeleted() { return SDK_CALL_FUNC(bool, 0x6497D0, void*)(this); }
		void DetachFromRoadNetwork() { SDK_CALL_FUNC(void, 0x64C020, void*)(this); }
		void FindPath() { SDK_CALL_FUNC(void, 0x64D530, void*)(this); }
		void FlushRaceTrails() { SDK_CALL_FUNC(void, 0x64D630, void*)(this); }
		VehicleFormations* GetCarChaseTargetFormation() { return SDK_CALL_FUNC(VehicleFormations*, 0x64D7A0, void*)(this); }
		f32 GetFractionRaceComplete() { return SDK_CALL_FUNC(f32, 0x64E760, void*)(this); }
		qVector3 GetSteerTo(const qVector3& steer_to, f32 offset, f32 steer_to_distance) {
			return SDK_CALL_FUNC(qVector3, 0x64F8C0, void*, const qVector3&, f32, f32)(this, steer_to, offset, steer_to_distance);
		}
		qVector3 GetSteerToDestination(f32 steerToDistance, bool isBoat, bool useDirection) {
			return SDK_CALL_FUNC(qVector3, 0x64FB10, void*, f32, bool, bool)(this, steerToDistance, isBoat, useDirection);
		}
		qVector3 GetSteerToFollow(f32 steer_to_distance) { return SDK_CALL_FUNC(qVector3, 0x650130, void*, f32)(this, steer_to_distance); }
		qVector3 GetSteerToNavPath(const qVector3& defaultSteerTo, f32 steerToDist) { return SDK_CALL_FUNC(qVector3, 0x650740, void*, const qVector3&, f32)(this, defaultSteerTo, steerToDist); }
		qVector3 GetSteerToNavWanderDestination(const qVector3& defaultSteerTo, f32 steerToDist) {
			return SDK_CALL_FUNC(qVector3, 0x650A20, void*, const qVector3&, f32)(this, defaultSteerTo, steerToDist);
		}
		qVector3 GetSteerToRace(f32 steer_to_distance, f32* speed_limit, f32 vehicle_mass, bool is_boat) {
			return SDK_CALL_FUNC(qVector3, 0x650B40, void*, f32, f32*, f32, bool)(this, steer_to_distance, speed_limit, vehicle_mass, is_boat);
		}
		void MoveCarToRoadNetworkPosition(RoadNetworkLocation* location, bool snapToGround) { SDK_CALL_FUNC(void, 0x652860, void*, RoadNetworkLocation*, bool)(this, location, snapToGround); }
		void SetCarDestination(TransformNodeComponent* xform) { SDK_CALL_FUNC(void, 0x6586A0, void*, TransformNodeComponent*)(this, xform); }
		void SetCarDestination(const qMatrix44& matrix) { SDK_CALL_FUNC(void, 0x6585F0, void*, const qMatrix44&)(this, matrix); }
		void SetChaseTarget(SimObject* target) { SDK_CALL_FUNC(void, 0x6588B0, void*, SimObject*)(this, target); }
		void SetRaceTrail(RaceTrail* race_trail) { SDK_CALL_FUNC(void, 0x659740, void*, RaceTrail*)(this, race_trail); }
		void SetRaceTrailSteer(RaceTrail* race_trail) { SDK_CALL_FUNC(void, 0x6597F0, void*, RaceTrail*)(this, race_trail); }
		void SetupLaneFlags() { SDK_CALL_FUNC(void, 0x659A40, void*)(this); }
		void SnapToRoadNetwork() { SDK_CALL_FUNC(void, 0x65A5B0, void*)(this); }
		qVector3 WorldToChase(const qVector3& position) { return SDK_CALL_FUNC(qVector3, 0x6663F0, void*, const qVector3&)(this, position); }
	};
	SDK_ASSERT_SIZEOF(RoadSpaceComponent, 0x7A0);
}