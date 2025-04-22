#pragma once

namespace UFG
{
	class WheeledVehicleManager
	{
	public:
		enum LaneTendency
		{
			Random,
			TowardVisibleAreaSubject,
			AwayFromVisibleAreaSubject
		};

		enum VehicleJob
		{
			Traffic,
			Transit,
			Taxi,
			Emergency
		};

		struct RoadSpawningRecord : qNode<RoadSpawningRecord>
		{
			f32 m_SpawnWeight;
			u32 m_MaxNumCarsToSpawn;
			u32 m_NumCarsToSpawn;
			RoadNetworkSubSegment* m_pSubSegment;
		};

		WheeledVehicleNavigationData* m_NavigationData;
		RoadNetworkVisibleArea* m_VisibleArea;
		TrueDirectionManager* m_TrueDirectionManager;
		bool m_ReinitializeQueued;
		float m_SecondsQueued;
		qSafePointer<SimComponent, TrafficRegion> mCurrentTrafficRegion;
		qSymbol m_TrafficSetOverride;
		SensorPhantom* mSpawnSensor;
		SimObject* m_SimObject;
		qArray<qSymbol, 0>* m_RoadPropertyCollection;
		qSafePointer<SimObject> mCarsWithDeletionPending[100];
		u32 mTotalNumParkedCarsCreated;
		u32 mNumParkedCars;
		qSafePointerWithCallbacks<SimObject, SimObjectVehicle> mParkedCar[100];
		u32 mTotalNumTrafficCarsCreated;
		u32 mNumTrafficCars;
		qSafePointerWithCallbacks<SimObject, SimObjectVehicle> mTrafficCar[100];
		qArray<RoadSpawningRecord> mSpawningRecordCollection;
		qArray<RoadSpawningRecord> mParkingSpawningRecordCollection;
		LaneTendency mSpawningLaneTendency;
		f32 mPercentageSpawningInFavouredLane;
		f32 mSpawnPointExpectedCarsTimer;
		u32 mCurrentSpawnIndex;
		qArray<qPropertySet*> mSpawningSelectionArray;
		bool m_PlaceTransitVehiclePending;
		bool m_PlaceTransitVehicleReady;
		u32 m_PlaceTransitVehicleFrames;
		bool m_TrueDirectionUpdateEnabled;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x2090515> mUpdateTrafficRegionEnabled;
		SDK_VINLINE qGlobalVar<bool, 0x2090516> mTrafficCarSpawningEnabled;
		SDK_VINLINE qGlobalVar<bool, 0x2090517> mParkedCarSpawningEnabled;
		SDK_VINLINE qGlobalVar<bool, 0x2090524> m_TrafficSpawningUpdatesEnabled;
		SDK_VINLINE qGlobalVar<bool, 0x2433B2B> m_TrafficSystemLocked;

		/* Static Functions */

		SDK_SINLINE WheeledVehicleManager* Instance() { return SDK_VAR_GET(WheeledVehicleManager*, 0x2433B10); }
		SDK_SINLINE void ApplyDefaultMaxCars() { SDK_CALL_FUNC(void, 0x644EF0)(); }

		SDK_SINLINE void EnableParkedCarSpawning(bool enable) { mParkedCarSpawningEnabled = enable; }
		SDK_SINLINE void EnableTrafficSpawningUpdates(bool enable) { m_TrafficSpawningUpdatesEnabled = enable; }
		SDK_SINLINE void SetTrafficSystemLocked(bool locked) { m_TrafficSystemLocked = locked; }

		SDK_SINLINE void ResetMaxParkedCars() { SDK_CALL_FUNC(void, 0x6581D0)(); }
		SDK_SINLINE void ResetMaxTrafficCars() { SDK_CALL_FUNC(void, 0x6581E0)(); }
		SDK_SINLINE void SetMaxParkedCars(u32 maxNumCars) { SDK_CALL_FUNC(void, 0x6595B0, u32)(maxNumCars); }
		SDK_SINLINE void SetMaxTrafficCars(u32 maxNumCars) { SDK_CALL_FUNC(void, 0x6595D0, u32)(maxNumCars); }
		SDK_SINLINE void SetTrafficDensityScale(f32 scaleFactor) { SDK_CALL_FUNC(void, 0x6599A0, f32)(scaleFactor); }

		/* Impl Functions */

		SDK_INLINE bool IsTrueDirectionUpdateEnabled() { return m_TrueDirectionUpdateEnabled; }
		SDK_INLINE void SetTrueDirectionUpdateEnabled(bool isEnabled) { m_TrueDirectionUpdateEnabled = isEnabled; }

		/* Functions */

		void ActivateSubSegments(qArray<RoadNetworkSubSegment*>& activateSubSegments) { SDK_CALL_FUNC(void, 0x6445D0, void*, qArray<RoadNetworkSubSegment*>&)(this, activateSubSegments); }
		void AttachTrafficAI(SimObjectVehicle* pCar) { SDK_CALL_FUNC(void, 0x645360, void*, SimObjectVehicle*)(this, pCar); }

		void CalculateVehicleDistribution(qArray<RoadNetworkSubSegment*>& subSegments, int numCarsAvailable) {
			SDK_CALL_FUNC(void, 0x647510, void*, qArray<RoadNetworkSubSegment*>&, int)(this, subSegments, numCarsAvailable);
		}

		bool CheckSpawnLocationSimple(const qVector3& position) { return SDK_CALL_FUNC(bool, 0x648380, void*, const qVector3&)(this, position); }
		qPropertySet* ChooseAmbientParkedVehicle(u32 roadType) { return SDK_CALL_FUNC(qPropertySet*, 0x648400, void*, u32)(this, roadType); }
		qPropertySet* ChooseAmbientVehicle(u32 roadType, VehicleJob vehicleJobType) { return SDK_CALL_FUNC(qPropertySet*, 0x6484D0, void*, u32, VehicleJob)(this, roadType, vehicleJobType); }
		qPropertySet* ChooseWeightedEntryFromSpawningList() { return SDK_CALL_FUNC(qPropertySet*, 0x648E10, void*)(this); }

		void CreateParkedCarsOnSubSegment(RoadNetworkSubSegment* subSegment, u32 numParkedCars) {
			SDK_CALL_FUNC(void, 0x64A200, void*, RoadNetworkSubSegment*, u32)(this, subSegment, numParkedCars);
		}

		SimObjectVehicle* CreateParkedWheeledVehicle(qPropertySet* vehiclePropSet, ParkingSpot* spot) {
			return SDK_CALL_FUNC(SimObjectVehicle*, 0x64A440, void*, qPropertySet*, ParkingSpot*)(this, vehiclePropSet, spot);
		}

		void CreateTrafficCarsOnSubSegment(RoadNetworkSubSegment* subSegment, u32 numCars) { SDK_CALL_FUNC(void, 0x64A510, void*, RoadNetworkSubSegment*, u32)(this, subSegment, numCars); }
		SimObjectVehicle* CreateWheeledVehicle(qPropertySet* vehiclePropSet) { return SDK_CALL_FUNC(SimObjectVehicle*, 0x64A820, void*, qPropertySet*)(this, vehiclePropSet); }
		void DestroyAllNonParkedWheeledVehicles() { SDK_CALL_FUNC(void, 0x64AB10, void*)(this); }
		void DestroyAllWheeledVehicles() { SDK_CALL_FUNC(void, 0x64ADF0, void*)(this); }
		void DestroyCarsOnRoad(RoadNetworkNode* node) { SDK_CALL_FUNC(void, 0x64B080, void*, RoadNetworkNode*)(this, node); }
		void DestroyParkedCarsOnSubSegment(RoadNetworkSubSegment* subSegment) { SDK_CALL_FUNC(void, 0x64B1A0, void*, RoadNetworkSubSegment*)(this, subSegment); }
		u32 DestroyParkedVehiclesInRange(const qVector3& pos, f32 radius) { return SDK_CALL_FUNC(u32, 0x64B2F0, void*, const qVector3&, f32)(this, pos, radius); }
		void DestroyQueuedVehicles() { SDK_CALL_FUNC(void, 0x64B4D0, void*)(this); }
		u32 DestroyTrafficVehiclesInRange(const qVector3& pos, f32 radius) { return SDK_CALL_FUNC(u32, 0x64B540, void*, const qVector3&, f32)(this, pos, radius); }

		void DestroyTrafficVehiclesOnSubSegment(RoadNetworkSubSegment* subSegment, bool queueForDeletion, RoadNetworkLane* specificLane) {
			SDK_CALL_FUNC(void, 0x64B740, void*, RoadNetworkSubSegment*, bool, RoadNetworkLane*)(this, subSegment, queueForDeletion, specificLane);
		}

		void DestroyVehiclesOutsideVisibleArea() { SDK_CALL_FUNC(void, 0x64B900, void*)(this); }

		void DestroyWheeledVehiclesInNISBoundingVolume(const qVector3& aabbMin, const qVector3& aabbMax) {
			SDK_CALL_FUNC(void, 0x64BA90, void*, const qVector3&, const qVector3&)(this, aabbMin, aabbMax);
		}

		void EnableTrafficSystem(bool enable) { SDK_CALL_FUNC(void, 0x64C710, void*, bool)(this, enable); }
		TrafficRegion* GetClosestTrafficRegion() { return SDK_CALL_FUNC(TrafficRegion*, 0x64D8B0, void*)(this); }

		qSymbol GetCurrentTrafficSet()
		{
			qProxy<qSymbol> res;
			return *SDK_CALL_FUNC(qSymbol*, 0x64D9D0, void*, qSymbol*)(this, &res);
		}

		u32 GetNumTrams() { return SDK_CALL_FUNC(u32, 0x64EB70, void*)(this); }
		void InitGlobalData() { SDK_CALL_FUNC(void, 0x651430, void*)(this); }
		void InitLevelData() { SDK_CALL_FUNC(void, 0x6517B0, void*)(this); }
		bool IsNearPlayerVehicleGuide(const qVector3& pos) { return SDK_CALL_FUNC(bool, 0x651DC0, const qVector3&)(pos); }

		bool IsSpawnCollisionOnMergeLane(RoadNetworkLane* mergeLane, RoadNetworkLane* targetRoadLane, f32 targetLaneT, const qVector3& targetPos, f32 targetRear, f32 targetFront) {
			return SDK_CALL_FUNC(bool, 0x651F30, RoadNetworkLane*, RoadNetworkLane*, f32, const qVector3&, f32, f32)(mergeLane, targetRoadLane, targetLaneT, targetPos, targetRear, targetFront);
		}

		bool IsVehicleJobMatch(qPropertySet* vehiclePropSet, VehicleJob jobType) { return SDK_CALL_FUNC(bool, 0x652120, void*, qPropertySet*, VehicleJob)(this, vehiclePropSet, jobType); }

		bool IsVehicleSpawnCollision(qPropertySet* vehiclePropSet, RoadNetworkLane* targetRoadLane, f32 targetLaneT) {
			return SDK_CALL_FUNC(bool, 0x652200, qPropertySet*, RoadNetworkLane*, f32)(vehiclePropSet, targetRoadLane, targetLaneT);
		}

		void ParkedCarBeingDeleted(SimObject* pDeletedCar) { SDK_CALL_FUNC(void, 0x657780, void*, SimObject*)(this, pDeletedCar); }
		void QueueDeletion(SimObject* pCarToDelete) { SDK_CALL_FUNC(void, 0x657B50, void*, SimObject*)(this, pCarToDelete); }
		void Reinitialize() { SDK_CALL_FUNC(void, 0x657E10, void*)(this); }
		void ReleaseGlobalData() { SDK_CALL_FUNC(void, 0x657EE0, void*)(this); }
		void RemoveWheeledVehicleFromList(SimObjectVehicle* object) { SDK_CALL_FUNC(void, 0x658080, void*, SimObjectVehicle*)(this, object); }
		void ResetTrafficSystem() { SDK_CALL_FUNC(void, 0x658210, void*)(this); }
		bool SensorContainsObject() { return SDK_CALL_FUNC(bool, 0x658400, void*)(this); }
		bool SensorContainsObjectConditional(const qVector3& position) { return SDK_CALL_FUNC(bool, 0x658470, void*, const qVector3&)(this, position); }
		bool ShouldSpawnOnSubSegment(RoadNetworkSubSegment* subSegment) { return SDK_CALL_FUNC(bool, 0x65A140, void*, RoadNetworkSubSegment*)(this, subSegment); }

		bool SpawnLocationContainsObjectConditional(qPropertySet* vehiclePropSet, const qVector3& position) {
			return SDK_CALL_FUNC(bool, 0x65A610, void*, qPropertySet*, const qVector3&)(this, vehiclePropSet, position);
		}

		void SpawnParkedCars(qArray<RoadNetworkSubSegment*>& subSegments) { SDK_CALL_FUNC(void, 0x65A6F0, void*, qArray<RoadNetworkSubSegment*>&)(this, subSegments); }

		SimObject* SpawnParkedVehicle(qPropertySet* vehiclePropSet, ParkingSpot* spot) {
			return SDK_CALL_FUNC(SimObject*, 0x65AA50, void*, qPropertySet*, ParkingSpot*)(this, vehiclePropSet, spot);
		}

		void SpawnTrafficCarOnSpawnPoint(RoadNetworkSpawnPoint* spawnPoint) { SDK_CALL_FUNC(void, 0x65AC20, void*, RoadNetworkSpawnPoint*)(this, spawnPoint); }

		SimObject* SpawnTrafficVehicle(qPropertySet* vehiclePropSet, RoadNetworkNode* node, u32 lane, f32 t) {
			return SDK_CALL_FUNC(SimObject*, 0x65AC90, void*, qPropertySet*, RoadNetworkNode*, u32, f32)(this, vehiclePropSet, node, lane, t);
		}

		void TrafficCarBeingDeleted(SimObject* pDeletedCar) { SDK_CALL_FUNC(void, 0x65ED80, void*, SimObject*)(this, pDeletedCar); }
		void Update(f32 seconds) { SDK_CALL_FUNC(void, 0x65FA60, void*, f32)(this, seconds); }
		void UpdateSpawnPointExpectedCars() { SDK_CALL_FUNC(void, 0x6634E0, void*)(this); }
		void UpdateSpawnPoints(f32 seconds) { SDK_CALL_FUNC(void, 0x663810, void*, f32)(this, seconds); }
		bool UpdateTrafficSet() { return SDK_CALL_FUNC(bool, 0x665070, void*)(this); }
		void UpdateVehicleFade(SimObjectGame* vehicleObj) { SDK_CALL_FUNC(void, 0x665120, void*, SimObjectGame*)(this, vehicleObj); }
		void UpdateVehicleFades() { SDK_CALL_FUNC(void, 0x6653B0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(WheeledVehicleManager, 0x3C18);
}