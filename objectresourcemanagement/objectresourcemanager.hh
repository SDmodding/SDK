#pragma once

namespace UFG
{
	class EntityTypeState
	{
	public:
		TrueCrowdResource::EntityType mEntityType;
		bool mUpdateRequired;
		bool mActive;
		bool mHasMinimumAmbienceRequirement;
		f32 mAmbientModelRatioTarget;
		f32 mAmbientModelRatio;
		f32 mAmbientTextureRatioTarget;
		f32 mAmbientTextureRatio;
		u32 mAvailableAmbientModelMemory;
		u32 mAvailableAmbientTextureMemory;
		void(__fastcall* mResourceUpdateCallback)();
		qArray<qSymbol> mRareSpawnPropertySets;
		qArray<bool> mRareSpawnIsReady;

		/* Constructor, Destructor */

		EntityTypeState() { SDK_CALL_FUNC(void, 0x436750, void*)(this); }
		~EntityTypeState() { SDK_CALL_FUNC(void, 0x437B90, void*)(this); }

		/* Static Functions */

		SDK_SINLINE void UpdateCharacterPreloads() { SDK_CALL_FUNC(void, 0x445BC0)(); }
		SDK_SINLINE void UpdatePropPreloads() { SDK_CALL_FUNC(void, 0x4466C0)(); }
		SDK_SINLINE void UpdateVehiclePreloads() { SDK_CALL_FUNC(void, 0x447530)(); }

		/* Functions */

		const qSymbol& GetSpawnableRareEntity() { return SDK_CALL_FUNC(const qSymbol&, 0x43DEA0, void*)(this); }
		void RareEntitySpawned(const qSymbol& spawnedEntity) { SDK_CALL_FUNC(void, 0x441240, void*, const qSymbol&)(this, spawnedEntity); }
	};

	class ObjectResourceManager
	{
	public:
		struct RareSpawnRecord : qNode<RareSpawnRecord>
		{
			qSymbol mPropertySetName;
			int mMaxConcurrentInstances;
			int mMaxSpawnsBeforeCycles;
			int mTotalNumInstancesSpawned;
			int mWeight;
			u64 mMinTimeBetweenSpawns;
			u64 mLastTimeAssetLoaded;
			u64 mLastTimeAssetSpawned;
			u64 mRequestTime;
			TrueCrowdSet::Instance mInstance;
		};

		ResourcePool mPool;
		EntityTypeState mEntityStates[3];
		qSymbol mCurrentSpawnset;
		qArray<qPropertySet*> mAmbientVehicles;
		qArray<qPropertySet*> mAvailableDrivers;
		qPropertySet* mDefaultDriver;
		qArray<RareSpawnRecord*> mRareSpawnList[3];
		qList<RareSpawnRecord> mEmptyRareSpawnList;

		/* Static Functions */

		SDK_SINLINE ObjectResourceManager* Instance() { return SDK_VAR_GET(ObjectResourceManager*, 0x24015E8); }
		SDK_SINLINE void PerformEmergencyDump() { SDK_CALL_FUNC(void, 0x43FAE0)(); }

		/* Impl Functions */

		SDK_INLINE bool HasQueue() { return (mPool.mQueued.size + mPool.mLoading.size) != 0; }

		/* Functions */

		bool CanSpawnAmbient(qPropertySet* propertySet, component_StreamedResource* dataPtr, bool preloadedOnly) {
			return SDK_CALL_FUNC(bool, 0x439850, void*, qPropertySet*, component_StreamedResource*, bool)(this, propertySet, dataPtr, preloadedOnly);
		}

		void ChangeObjectPriority(StreamedResourceComponent* resourceComponent, const qSymbol& newPriority) {
			SDK_CALL_FUNC(void, 0x439950, void*, StreamedResourceComponent*, const qSymbol&)(this, resourceComponent, newPriority);
		}

		qSymbol ChooseNewRareRequest(TrueCrowdResource::EntityType type) { return SDK_CALL_FUNC(qSymbol, 0x43A030, void*, TrueCrowdResource::EntityType)(this, type); }
		void FlushResources(bool forceFlush) { SDK_CALL_FUNC(void, 0x43CDC0, void*, bool)(this, forceFlush); }

		qPropertySet* GetAvailableDriver(qPropertyList* classPriorities, qPropertyList* classExclusions = 0) {
			return SDK_CALL_FUNC(qPropertySet*, 0x43D150, void*, qPropertyList*, qPropertyList*)(this, classPriorities, classExclusions);
		}

		u32 GetBytesRemainingToLoad() { return SDK_CALL_FUNC(u32, 0x43D4D0, void*)(this); }
		qPropertySet* GetRandomPropSetFromCurrentTrafficSet() { return SDK_CALL_FUNC(qPropertySet*, 0x43DDF0, void*)(this); }
		bool IsLoaded(qPropertySet* propertySet) { return SDK_CALL_FUNC(bool, 0x43F280, void*, qPropertySet*)(this, propertySet); }
		void PopulateAmbience() { SDK_CALL_FUNC(void, 0x43FB00, void*)(this); }
		void PreLoadCriticalResource(qPropertySet* propertySet) { SDK_CALL_FUNC(void, 0x43FBE0, void*, qPropertySet*)(this, propertySet); }
		void ReleaseAllAmbientPreloads() { SDK_CALL_FUNC(void, 0x441570, void*)(this); }
		void ReleaseCriticalResource(qPropertySet* propertySet) { SDK_CALL_FUNC(void, 0x441910, void*, qPropertySet*)(this, propertySet); }

		void RemoveAllUnwantedRareRequests(TrueCrowdResource::EntityType type, bool forceUnload) {
			SDK_CALL_FUNC(void, 0x441FD0, void*, TrueCrowdResource::EntityType, bool)(this, type, forceUnload);
		}
		
		PreloadRequest* RequestPreload(qPropertySet* propertySet, const qSymbol& priority, bool directRequest) {
			return SDK_CALL_FUNC(PreloadRequest*, 0x442790, void*, qPropertySet*, const qSymbol&, bool)(this, propertySet, priority, directRequest);
		}

		void ResetAllRarePreloadStatuses(TrueCrowdResource::EntityType type) { SDK_CALL_FUNC(void, 0x442CB0, void*, TrueCrowdResource::EntityType)(this, type); }
		void SetActiveAmbience(bool vehicles, bool characters) { SDK_CALL_FUNC(void, 0x443080, void*, bool, bool)(this, vehicles, characters); }
		void SetFragmentationReservePercentage(f32 percent) { SDK_CALL_FUNC(void, 0x443130, void*, f32)(this, percent); }
		void UnloadAmbientVehicles() { SDK_CALL_FUNC(void, 0x444630, void*)(this); }
		void Update(f32 deltaTime) { SDK_CALL_FUNC(void, 0x444680, void*, f32)(this, deltaTime); }
		void UpdateAvailableVehicles() { SDK_CALL_FUNC(void, 0x445850, void*)(this); }
		void UpdateCharacterPreloads() { SDK_CALL_FUNC(void, 0x445BD0, void*)(this); }
		void UpdatePropPreloads() { SDK_CALL_FUNC(void, 0x4466D0, void*)(this); }
		void UpdateRareObjectAvailability() { SDK_CALL_FUNC(void, 0x446B60, void*)(this); }
		void UpdateRareRequests() { SDK_CALL_FUNC(void, 0x446C90, void*)(this); }

		void UpdateRareSpawnResourcesFromPropertySet(TrueCrowdResource::EntityType type, qPropertySet* set) {
			SDK_CALL_FUNC(void, 0x446EF0, void*, TrueCrowdResource::EntityType, qPropertySet*)(this, type, set);
		}

		void UpdateVehiclePreloads() { SDK_CALL_FUNC(void, 0x447540, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(ObjectResourceManager, 0x208);
}