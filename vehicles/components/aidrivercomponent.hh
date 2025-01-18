#pragma once

namespace UFG
{
	class AiDriverComponent : public VehicleDriverInterface, public qNode<AiDriverComponent>
	{
	public:
		enum { _TypeUID = 0xD8000003 };

		enum AmbientDriverType : i32
		{
			AmbientDriverType_None,
			AmbientDriverType_Placement,
			AmbientDriverType_Real
		};

		enum EStopStyle : i32
		{
			EStopStyle_Gradual,
			EStopStyle_Powerslide
		};

		struct TimeWindowResult
		{
			f32 fClosingSpeed;
			f32 fEarliest;
			f32 fLatest;
		};

		struct AvoidableOverlap : qNode<AvoidableOverlap>
		{
			bool m_CoChaser;
			int m_Generation;
			TimeWindowResult m_TimeWindow;
			CameraSubject* m_pAvoidableSubject;
			qVector3 m_CloseLimit;
			qVector3 m_RightRay;
			qVector3 m_LeftRay;
		};

		struct EscortInfo
		{
			CarAI::EEscortMode eEscortMode;
			f32 fDistanceSqrEnemyToObjectiveEnterAttackMode;
			f32 fDistanceSqrEnemyToObjectiveEnterEscortMode;
		};

		struct StopInfo
		{
			EStopStyle eStopStyle;
			f32 fSteeringOverride;
			bool bHasSteeringOverride : 1;
		};

		RebindingComponentHandle<RoadSpaceComponent> m_pRoadSpace;
		RebindingComponentHandle<VehicleSubjectComponent> m_pVehicleSubject;
		qSafePointer<VehicleSubjectComponent> m_pChaseVehicleSubject;
		qSafePointer<VehicleSubjectComponent> m_pEscortEnemyVehicleSubject;
		qSafePointer<VehicleSubjectComponent> m_pEscortObjectiveVehicleSubject;
		qPidControllerCore m_SteeringPid;
		qPidControllerCore m_ThrottlePid;
		DrivingTargetOffsetMover m_OffsetMover;
		LinearGraph<f32>* m_BrakingGraph;
		LinearGraph<f32>* m_CarGapGraph;
		AIdPtr<SSInvokedCoroutine> m_DriveToCoroutine;
		u32 m_DrivingMode;
		u32 m_DrivingRole;
		qPropertySet* m_DriverProfile;
		qSafePointer<SimObject> m_CatchupTarget;
		qPidControllerCore m_CatchupPid;
		f32 m_CatchupRangeBehind;
		f32 m_CatchupRangeAhead;
		f32 m_CatchupMaxSpeedUp;
		f32 m_CatchupMaxSlowDown;
		f32 m_CatchupOffset;
		f32 m_fDesiredSpeed;
		f32 m_fCurrentForwardSpeed;
		f32 m_fPreviousGasBrakes;
		f32 m_RoadSpeedLimit;
		qVector3 m_vSteerToPosition;
		f32 m_fSteeringScale;
		bool m_FollowDebug;
		bool m_AvoidanceDebug;
		CarCombat::Position m_DesiredOffset;
		CarCombat::Side m_Side;
		qVector3 m_vFollowOffsetActual;
		qVector3 m_vFollowOffsetDesired;
		f32 m_fFollowOffsetBlend;
		f32 m_fFollowOffsetTolerance;
		f32 m_fFollowDistance;
		f32 m_fTimeNearOffset;
		f32 m_fAttackTime;
		u64 m_iLastHighSpeedCollisionTimestamp;
		qNoise<f32> m_SteeringNoise;
		f32 m_fSteeringNoiseTimer;
		f32 m_fSteeringNoiseAmplitude;
		f32 m_fSteeringNoiseAmplitudeMin;
		bool mModeSteeringLockEnabled;
		f32 mModeSteeringLock;
		bool mModeGasBrakeLockEnabled;
		f32 mModeGasBrakeLock;
		bool m_bSteeringLock;
		f32 m_fSteeringLock;
		bool m_bGasBrakeLock;
		f32 m_fGasBrakeLock;
		f32 m_fReactionTime;
		HistoryBuffer<qVector2> m_SteeringGasBrakeHistory;
		f32 m_fAvoidSteerLimit;
		f32 m_fAvoidStopTimer;
		f32 m_fBrakeTimer;
		f32 m_fStuckTimer;
		f32 m_fReverseTimer;
		qVector3 m_vStuckPosition;
		f32 m_GettingUnstuckTimer;
		f32 m_BeenUnstuckTimer;
		f32 m_fPassingTimer;
		f32 m_fPassingBias;
		SensorPhantom* m_AvoidableSensor;
		int m_NumAvoidableOverlaps;
		qSafePointer<SimObject> m_CurrentAvoidable;
		bool m_BlockedByAvoidable;
		hkpSphereShape* m_pCastingSphere;
		hkpSimpleShapePhantom* m_pCastingPhantom;
		VehicleCombatStats m_CombatStats;
		CarCombat::Attack m_CurrentAttack;
		EscortInfo m_EscortInfo;
		bool m_bAvoidPeds;
		bool m_bAllowedToPass;
		bool m_bStayOffSidewalk;
		bool m_bRespectSpeedLimit;
		bool m_ObeyTrafficLights;
		bool m_bCanTurnAround;
		bool m_bSavedAvoidPeds;
		bool m_bTemporaryAllowedToPass;
		bool m_RoadRuleFlagsLocked;
		bool m_AiAttackEnabled;
		bool m_AiScriptControlled;
		u32 m_TempPassLaneChangeDirectionCode;
		bool m_bIgnoreArrivalDirection;
		bool m_bIsParked;
		bool m_IsAmbient;
		AmbientDriverType m_AmbientDriverType;
		f32 m_fSearchTimer;
		f32 mTargetWaitTimer;
		f32 m_RoadSpeedLimitScale;
		f32 m_DesiredSpeedLimit;
		bool m_AvoidObjectsEnabled;
		bool m_AvoidGeoEnabled;
		bool m_GoToSlowDownForDestination;
		bool m_GoToStopAtEnabled;
		qSafePointer<SimObject> m_PathingTarget;
		f32 m_FacingTargetAngle;
		f32 m_StopAtDist;
		bool m_StopAtUseDestinationDirection;
		StopInfo m_StopInfo;
		f32 m_StopDist;
		f32 m_fDelayedStopDecel;
		bool m_ResetStopDistOnStop;
		f32 m_fChaseSpeedLimit;
		f32 m_fRaceSpeedLimit;
		bool m_RaceWanderAtEnd;
		bool m_bDeniesHijack;
		bool m_bCreepingTowardEscortEnemy;
		bool m_CappingSpeedForStopPoint;
		bool m_CappingSpeedForNextGuide;

		/* Impl Functions */

		SDK_INLINE void ClearGasBrakeLock() { m_bGasBrakeLock = 0; }
		SDK_INLINE void ClearSteeringLock() { m_bSteeringLock = 0; }
		SDK_INLINE void ClearSteeringNoise() { m_fSteeringNoiseAmplitude = m_fSteeringNoiseAmplitudeMin = 0; }
		SDK_INLINE qPropertySet* GetDriverProfile() { return m_DriverProfile; }
		SDK_INLINE bool GetUnstuckFailed() { return m_GettingUnstuckTimer > 22.f; }
		SDK_INLINE bool IsAmbient() { return m_IsAmbient; }

		/* Functions */

		// void AddAvoidableOverlap(AvoidableOverlap,1,0>* list, CameraSubject* avoidable_subject, TimeWindowResult* time_window, bool co_chaser) { SDK_CALL_FUNC(void, 0x644800, void*, AvoidableOverlap,1,0>*, CameraSubject*, TimeWindowResult*, bool)(this, list, avoidable_subject, time_window, co_chaser); }
		void AddSteeringNoise(f32 amplitude) { SDK_CALL_FUNC(void, 0x644D90, void*, f32)(this, amplitude); }
		void AttachDriverProfile(SimObjectVehicle* sim_object_vehicle) { SDK_CALL_FUNC(void, 0x645140, void*, SimObjectVehicle*)(this, sim_object_vehicle); }
		void BeginAttack(CarCombat::Attack attack) { SDK_CALL_FUNC(void, 0x645600, void*, CarCombat::Attack)(this, attack); }
		void BeginPathingNavigation() { SDK_CALL_FUNC(void, 0x645690, void*)(this); }
		void ChangeLane(RoadNetworkLane::LaneChangeDirection direction) { SDK_CALL_FUNC(void, 0x647B00, void*, RoadNetworkLane::LaneChangeDirection)(this, direction); }
		u32 ChooseNextLane(RoadNetworkConnection* roadConnection, const qArray<u32>& validLanes) { 
			return SDK_CALL_FUNC(u32, 0x648A40, void*, RoadNetworkConnection*, const qArray<u32>&)(this, roadConnection, validLanes);
		}
		void ComputeAvoidanceLimits(const qVector3& my_position, const qVector3* avoid_hull, qVector3* left_limit, qVector3* right_limit, qVector3* close_limit) { 
			SDK_CALL_FUNC(void, 0x649960, void*, const qVector3&, const qVector3*, qVector3*, qVector3*, qVector3*)(this, my_position, avoid_hull, left_limit, right_limit, close_limit);
		}
		bool DepopulateVehicleOccupants() { return SDK_CALL_FUNC(bool, 0x64AAD0, void*)(this); }
		void EmergencyFixupForGround(qMatrix44& local_world) { SDK_CALL_FUNC(void, 0x64C030, void*, qMatrix44&)(this, local_world); }
		void EnableTemporaryPassing() { SDK_CALL_FUNC(void, 0x64C6E0, void*)(this); }
		void EndAttack() { SDK_CALL_FUNC(void, 0x64C7E0, void*)(this); }
		void EndPathingNavigation() { SDK_CALL_FUNC(void, 0x64C8E0, void*)(this); }
		// qVector3* ExtrapolateWithCurvature(qVector3* result, f32 time, CameraSubject* subject, RoadSpaceComponent* road_space, qVector3* new_velocity) { return SDK_CALL_FUNC(qVector3*, 0x64CBB0, void*, qVector3*, f32, CameraSubject*, RoadSpaceComponent*, qVector3*)(this, result, time, subject, road_space, new_velocity); }
		RoadNetworkLane* FindNextWayfindLane(RoadNetworkLane* currLane, RoadNetworkNode* nextPathSegment) { 
			return SDK_CALL_FUNC(RoadNetworkLane*, 0x64D1D0, void*, RoadNetworkLane*, RoadNetworkNode*)(this, currLane, nextPathSegment); 
		}
		RoadNetworkLane* FindWanderLaneAfterNext(RoadNetworkConnection* roadConn) { return SDK_CALL_FUNC(RoadNetworkLane*, 0x64D580, void*, RoadNetworkConnection*)(this, roadConn); }
		f32 GetAvoidanceFutureTime() { return SDK_CALL_FUNC(f32, 0x64D710, void*)(this); }
		f32 GetBumperGap() { return SDK_CALL_FUNC(f32, 0x64D730, void*)(this); }
		f32 GetCatchupBoost() { return SDK_CALL_FUNC(f32, 0x64D830, void*)(this); }
		qVector3 GetCombatOffset(int side, int index, bool isBoat) { return SDK_CALL_FUNC(qVector3, 0x64D960, int, int, bool)(side, index, isBoat); }
		u32* GetDriverProfileType() { return SDK_CALL_FUNC(u32*, 0x64DAC0, void*)(this); }
		SimObject* GetEscortEnemy() { return SDK_CALL_FUNC(SimObject*, 0x64E740, void*)(this); }
		RoadNetworkLane* GetLaneAtEdgeNum(u32 endEdgeIndex) { return SDK_CALL_FUNC(RoadNetworkLane*, 0x64E7B0, void*, u32)(this, endEdgeIndex); }
		f32 GetRoadHolding() { return SDK_CALL_FUNC(f32, 0x64F220, void*)(this); }
		f32 GetSpeedForNextGuide(f32 desiredSpeed) { return SDK_CALL_FUNC(f32, 0x64F570, void*, f32)(this, desiredSpeed); }
		f32 GetSpeedForStopPoint(f32 desiredSpeed) { return SDK_CALL_FUNC(f32, 0x64F710, void*, f32)(this, desiredSpeed); }
		f32 GetSpeedFromRoad(f32 speedLimit) { return SDK_CALL_FUNC(f32, 0x64F7B0, void*, f32)(this, speedLimit); }
		f32 GetTimeAtOffset(CarCombat::Position position) { return SDK_CALL_FUNC(f32, 0x650F90, void*, CarCombat::Position)(this, position); }
		void HandleCollision(SimObject* pAttackerSimObject, f32 damage, u32 dt) { SDK_CALL_FUNC(void, 0x651330, void*, SimObject*, f32, u32)(this, pAttackerSimObject, damage, dt); }
		bool IsBlockedByAvoidable(int avoidableSet) { return SDK_CALL_FUNC(bool, 0x651A50, void*, int)(this, avoidableSet); }
		bool IsBoat() { return SDK_CALL_FUNC(bool, 0x651B20, void*)(this); }
		bool IsInTrafficJam() { return SDK_CALL_FUNC(bool, 0x651B70, void*)(this); }
		bool IsJammed(RoadNetworkLane* roadLane, u32 numCarsForJam) { return SDK_CALL_FUNC(bool, 0x651CC0, RoadNetworkLane*, u32)(roadLane, numCarsForJam); }
		bool IsTaxi() { return SDK_CALL_FUNC(bool, 0x6520F0, void*)(this); }
		bool IsTransit() { return SDK_CALL_FUNC(bool, 0x652100, void*)(this); }
		bool LaneContainsPlayer(RoadNetworkGuide* guide) { return SDK_CALL_FUNC(bool, 0x652500, void*, RoadNetworkGuide*)(this, guide); }
		bool PopulateVehicleOccupants() { return SDK_CALL_FUNC(bool, 0x6579C0, void*)(this); }
		void RemoveFromRace(bool hideBlip) { SDK_CALL_FUNC(void, 0x657F50, void*, bool)(this, hideBlip); }
		qVector3 RotateSteerTo(const qVector3& steer_to, f32 steer_to_distance, f32 radians) { 
			return SDK_CALL_FUNC(qVector3, 0x6582E0, void*, const qVector3&, f32, f32)(this, steer_to, steer_to_distance, radians);
		}
		void SetAllowedToPass(bool allowed_to_pass) { SDK_CALL_FUNC(void, 0x658590, void*, bool)(this, allowed_to_pass); }
		void SetAvoidPeds(bool avoid_peds) { SDK_CALL_FUNC(void, 0x6585B0, void*, bool)(this, avoid_peds); }
		void SetCanTurnAround(bool can_turn_around) { SDK_CALL_FUNC(void, 0x6585D0, void*, bool)(this, can_turn_around); }
		void SetChaseTarget(SimObject* target) { SDK_CALL_FUNC(void, 0x6587A0, void*, SimObject*)(this, target); }
		void SetDrivingMode(u32 mode) { SDK_CALL_FUNC(void, 0x658B90, void*, u32)(this, mode); }
		void SetDrivingRole(u32 role) { SDK_CALL_FUNC(void, 0x658C90, void*, u32)(this, role); }
		void SetDrivingRoleByClassType() { SDK_CALL_FUNC(void, 0x658E30, void*)(this); }
		void SetEscortEnemy(SimObject* enemy) { SDK_CALL_FUNC(void, 0x659040, void*, SimObject*)(this, enemy); }
		void SetEscortObjective(SimObject* enemy) { SDK_CALL_FUNC(void, 0x659110, void*, SimObject*)(this, enemy); }
		void SetFollowDistance(f32 distance) { SDK_CALL_FUNC(void, 0x6591E0, void*, f32)(this, distance); }
		void SetFollowOffset(f32 x, f32 y, f32 tolerance) { SDK_CALL_FUNC(void, 0x659210, void*, f32, f32, f32)(this, x, y, tolerance); }
		void SetFollowOffset(CarCombat::Side side, CarCombat::Position position, f32 tolerance) { 
			SDK_CALL_FUNC(void, 0x6592E0, void*, CarCombat::Side, CarCombat::Position, f32)(this, side, position, tolerance); 
		}
		void SetFollowOffsetCustom(CarCombat::Side side, CarCombat::Position position, const qVector3& customOffset, f32 tolerance) {
			SDK_CALL_FUNC(void, 0x6593B0, void*, CarCombat::Side, CarCombat::Position, const qVector3&, f32)(this, side, position, customOffset, tolerance);
		}
		void SetGasBrakeLock(f32 gas_brake_lock) { SDK_CALL_FUNC(void, 0x6594A0, void*, f32)(this, gas_brake_lock); }
		void SetObeyTrafficLights(bool obeyTrafficLights) { SDK_CALL_FUNC(void, 0x659600, void*, bool)(this, obeyTrafficLights); }
		void SetParked(bool parked) { SDK_CALL_FUNC(void, 0x659620, void*, bool)(this, parked); }
		void SetRespectSpeedLimit(bool respect_speed_limit) { SDK_CALL_FUNC(void, 0x6598E0, void*, bool)(this, respect_speed_limit); }
		bool WarpToDestination() { return SDK_CALL_FUNC(bool, 0x665EB0, void*)(this); }
		void WarpToGotoDestination() { SDK_CALL_FUNC(void, 0x666130, void*)(this); }
	};
}