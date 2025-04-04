#pragma once

namespace UFG
{
	SDK_VINLINE qGlobalVar<bool, 0x23DE418> sAmbientPedEnableLocked;

	class AILightWeightComponent;
	class CharacterOccupantComponent;
	class GroupComponent;
	class InterestPoint;
	class SpawnZone; /* Declared here! */

	enum eActiveZoneClass : s32
	{
		Always_Active,
		PreferActive_ExtraLow_Ok,
		PreferExtraLow_Proxy_Bad,
		PreferExtraLow_Proxy_Ok,
		PreferProxy_Inactive_Ok,
		Always_Inactive,
		Zone_Classes_Count
	};

	enum eHowSpawned : s32
	{
		FromScript,
		FromRegion,
		FromPoint,
		FromNetwork
	};

	enum ePedType : s32
	{
		AmbientPed,
		ScriptedPed
	};

	class ActiveSpawnSetInfo
	{
	public:
		qPropertySet* mpPropertySet;
		int mRefCount;
		int mPopulationPotential;
		f32 mPercentOfGlobalPopulation;
		bool mMediumPriorityOverride;
		qArray<qPropertySet*> mSpawnInfoArray;
		qArray<qPropertySet*> mRareSpawnInfoArray;
	};
	SDK_ASSERT_SIZEOF(ActiveSpawnSetInfo, 0x38);

	class PedSpawningInfo : public SimComponent, qNode<void**>, qNode<void*>, public qNode<PedSpawningInfo>
	{
	public:
		enum { _TypeUID = 0x6E000001 };

		enum eActiveStatus
		{
			Inactive,
			Active,
			ExtraLowPower,
			NormalSuspend,
			NetFull,
			NetProxy,
			eActiveStatus_Count,
		};

		enum eDrawList
		{
			DrawList_None,
			DrawList_Draw,
			DrawList_NoDraw,
		};

		enum eSuspendAction
		{
			SuspendAllowed = 0,
			NoSuspend = (1 << 0),
			LockActive = (1 << 1),
			DeleteOnSuspend = (1 << 2),
			DeleteNow = (1 << 3),
			CleanUpWhenDead = (1 << 4),
			LoanedToMission = (1 << 5),
			NoSuspendOption = -1,
		};

		SimObject* mProxySimObjectPtr;
		TransformNodeComponent* mProxyTransformNode;
		int mPedIndex;
		f32 mSuspendedTime;
		f32 mCulledTime;
		f32 mPrevCulledTime;
		qSafePointer<SpawnZone> mCreationSpawnZone;
		eActiveStatus mActiveStatus;
		PedSpawningInfo::eDrawList mDrawList;
		qSafePointerWithCallbacks<SimObjectCharacter> mSimObjectPtr;
		TransformNodeComponent* mTransformNodePtr;
		AILightWeightComponent* mProxyAIComponent;
		GroupComponent* mGroupComponent;
		struct NetworkComponent* mNetworkComponent;
		u32 mProxyOverDrawFrames;
		int mProxyModelHandleIndex;
		f32 mProxyTimeSinceLastAIUpdate;
		f32 mProxyTimeSinceLastFrameUpdate;
		f32 mProxyIndividualTimeScale;
		RebindingComponentHandle<CharacterOccupantComponent> mCharacterOccupantComponent;
		eActiveZoneClass mLocationClassification;
		bool mIsDead;
		qSymbol mLifetimeInstanceNameSymbol;
		TrueCrowdSet::Instance mTrueCrowdSignature;
		qSymbolUC mRigNameSymbol;
		qSymbol mPropSetSymbol;
		qSymbol mArchetypePropSetSymbol;
		qSymbol mFactionSymbol;
		u32 mNumAttachedProps;
		qSymbol mAttachedPropNames[4];
		u32 mCanSuspendScripted;
		f32 mDumpResourcePriorityScore;
		qSafePointer<SimComponent, InterestPoint> mUpgradePOI;
		int mLockActiveFrameCount;
		f32 mShouldCheckZoneInAreaTime;
		bool mIsNearDeactivatedZones;
		qVector3 mSuspendedPos;
		u32 mRestoreAttempts;
		u32 mBlipActive;
		eHowSpawned mHowSpawned;
		qVector3 mSpawnLocation;
		f32 mSpawnTime;
		bool mTeleportOnResumeRequired;
		bool mPhysicsLoadedForLocation;
		qVector3 mCurrentLocation;
		qVector3 mLocationInCameraSpace;
		f32 mDistInCameraSpace;
		f32 mBiasedDist;
		CullInfo* mCullInfo;
		CullResults* mCullResults;
		ePedType mPedType;
		u32 mStatusChangedFrame;

		/* Functions */

		void RemoveProps() { SDK_CALL_FUNC(void, 0x4157B0, void*)(this); }
		void Reset(bool preserveProxies) { SDK_CALL_FUNC(void, 0x415820, void*, bool)(this, preserveProxies); }
	};
	SDK_ASSERT_SIZEOF(PedSpawningInfo, 0x338);

	class PedSpawnManager
	{
	public:
		int mNumAmbientCurrentlyActive;
		int mNumAmbientCurrentlySuspended;
		int mTargetNumActive;
		f32 mUpdateDelta;
		f32 mTimeOfLastEnableCheck;
		int mNumberSpawnedSoFar;
		eHowSpawned mSpawningModeNow;
		f32 mLastTraversalTime;
		u32 mLastTraversalFrameCount;
		int mMode;
		qProxy<PedSpawningInfo> mAmbientPed[260];
		qProxy<PedSpawningInfo> mScriptedPed[120];
		ActiveSpawnSetInfo mActiveSpawnSets[40];
		int mPedSpawnHistoryIndex;
		u32 mNetRecycleCounter;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x207AE69> msAmbientSpawningEnable;
		SDK_VINLINE qGlobalVar<bool, 0x207AE6A> msAmbientStatusCheckEnable;
		SDK_VINLINE qGlobalVar<bool, 0x207AE6B> msScriptedStatusCheckEnable;
		SDK_VINLINE qGlobalVar<int, 0x207AE6C> msCheckStatusMode;
		SDK_VINLINE qGlobalVar<bool, 0x207AEB8> msProxyPedsEnabled;
		SDK_VINLINE qGlobalVar<f32, 0x207AED0> msPedDensityScaleCopSystemAdjust;
		SDK_VINLINE qGlobalVar<f32, 0x207AED4> msPedDensityScaleSpawnPointAdjust;
		SDK_VINLINE qGlobalVar<int, 0x207AF0C> msTargetPedCount;
		SDK_VINLINE qGlobalVar<f32, 0x207B21C> msBasePedsPerSquareMetre;
		SDK_VINLINE qGlobalVar<bool, 0x23DC652> msDryFireNearSpawnZones;
		SDK_VINLINE qGlobalVar<bool, 0x23DE286> msResourcesSuspended;
		SDK_VINLINE qGlobalVar<bool, 0x23DE287> msRestoreWeiOnPhysicsLoad;

		SDK_VINLINE qGlobalPVar<SimObjectCharacter*, 0x23DE330> msLastRegistered;
		SDK_VINLINE qGlobalPVar<PedSpawningInfo*, 0x23DE338> msLastRegisteredPedInfo;
		SDK_VINLINE qGlobalPVar<PedSpawningInfo*, 0x23DE340> msPedInfoForLocalZoneChecks;

		SDK_VINLINE qGlobalVar<int, 0x23DE348> msNumDeadAmbientPeds;
		SDK_VINLINE qGlobalVar<int, 0x23DE34C> msNumDeadScriptedPeds;

		/* Virtual Functions */

		virtual void DrawDebugInfo(void*) = 0;
		virtual void OnAttach(SimObject*) = 0;
		virtual void OnDetach() = 0;

		/* Static Functions */

		SDK_SINLINE PedSpawnManager* Instance() { return SDK_VAR_GET(PedSpawnManager*, 0x23DC610); }

		SDK_SINLINE bool AquireOwnership(SimObjectCharacter* _a_pObj, bool bAmbient, bool loaning_to_mission_script, int creation_zone_index) {
			return SDK_CALL_FUNC(bool, 0x407C90, SimObjectCharacter*, bool, bool, int)(_a_pObj, bAmbient, loaning_to_mission_script, creation_zone_index);
		}

		SDK_SINLINE void FreeSpawnZone(SpawnZone* ptr) { SDK_CALL_FUNC(void, 0x40BA90, SpawnZone*)(ptr); }
		SDK_SINLINE void LoadPedDensityTable() { SDK_CALL_FUNC(void, 0x40E300)(); }
		SDK_SINLINE void ReducePedsWithSpecificModel(TrueCrowdModel* model, bool allowForcedRemoval) { SDK_CALL_FUNC(void, 0x414210, TrueCrowdModel*, bool)(model, allowForcedRemoval); }
		SDK_SINLINE bool SpawnsQueued() { return SDK_CALL_FUNC(bool, 0x417830)(); }
		SDK_SINLINE void ToggleResourceResolution() { SDK_CALL_FUNC(void, 0x417CB0, )(); }

		/* Impl Functions */

		SDK_INLINE void AdjustCopSystemDensityModifier(f32 d) { msPedDensityScaleCopSystemAdjust = d; }
		SDK_INLINE void AdjustPedDensity(f32 d) { msBasePedsPerSquareMetre = d * 0.032f; }
		SDK_INLINE void AdjustSpawnPointDensityModifier(f32 d) { msPedDensityScaleSpawnPointAdjust = d; }
		SDK_INLINE void DisableProxyPeds() { msProxyPedsEnabled = 0; }
		SDK_INLINE void DryFireNearSpawnZones() { msDryFireNearSpawnZones = 1; }
		SDK_INLINE void EnableProxyPeds() { msProxyPedsEnabled = 1; }

		SDK_INLINE void SetAmbientSpawningEnable(bool b)
		{
			msAmbientSpawningEnable = b;
			msCheckStatusMode = 1;
		}

		SDK_INLINE void SetScriptedStatusCheckEnable(bool b) { msScriptedStatusCheckEnable = b; }
		SDK_INLINE void SetTargetPedCount(int targetPedCount) { msTargetPedCount = (targetPedCount == -1 ? 42 : targetPedCount); }

		/* Functions */

		void AddZoneToThugSpawningExceptionsArrary(SpawnZone* pZone) { SDK_CALL_FUNC(void, 0x4075A0, void*, SpawnZone*)(this, pZone); }

		void ChangeActiveStatus(PedSpawningInfo::eActiveStatus targetPedStatus, PedSpawningInfo& pedInfo) {
			SDK_CALL_FUNC(void, 0x408260, void*, PedSpawningInfo::eActiveStatus, PedSpawningInfo&)(this, targetPedStatus, pedInfo);
		}

		bool ChangeActiveStatusOfSimObj(PedSpawningInfo::eActiveStatus targetPedStatus, SimObject* simObj, const char* file, int line) {
			return SDK_CALL_FUNC(bool, 0x408300, void*, PedSpawningInfo::eActiveStatus, SimObject*, const char*, int)(this, targetPedStatus, simObj, file, line);
		}

		void ChangeStatusToActive(PedSpawningInfo& pedInfo) { SDK_CALL_FUNC(void, 0x408460, void*, PedSpawningInfo&)(this, pedInfo); }
		void ChangeStatusToExtraLowPower(PedSpawningInfo& pedInfo) { SDK_CALL_FUNC(void, 0x4085E0, void*, PedSpawningInfo&)(this, pedInfo); }
		void ChangeStatusToInactive(PedSpawningInfo& pedInfo) { SDK_CALL_FUNC(void, 0x408850, void*, PedSpawningInfo&)(this, pedInfo); }
		void CheckActiveStatusOfPeds() { SDK_CALL_FUNC(void, 0x408940, void*)(this); }

		PedSpawningInfo::eActiveStatus CheckAmbientActiveStatus(PedSpawningInfo& pedInfo, f32 elapsedTime) {
			return SDK_CALL_FUNC(PedSpawningInfo::eActiveStatus, 0x409340, void*, PedSpawningInfo&, f32)(this, pedInfo, elapsedTime);
		}

		void CollectAllSpawnInfos(qPropertyList* list, qArray<qPropertySet*>& spawnInfoArray) {
			SDK_CALL_FUNC(void, 0x4094A0, void*, qPropertyList*, qArray<qPropertySet*>&)(this, list, spawnInfoArray);
		}

		void CollectInfoForOne(PedSpawningInfo& info, qMatrix44* camWorldView, f32 elapsedTime) {
			SDK_CALL_FUNC(void, 0x409610, void*, PedSpawningInfo&, qMatrix44*, f32)(this, info, camWorldView, elapsedTime);
		}

		void CollectPedInfo(f32 elapsedTime) { SDK_CALL_FUNC(void, 0x409990, void*, f32)(this, elapsedTime); }
		void DeInit() { SDK_CALL_FUNC(void, 0x40A600, void*)(this); }

		void DeleteAmbientPedsFromNISBoundingVolume(const qVector3& aabbMin, const qVector3& aabbMax) {
			SDK_CALL_FUNC(void, 0x40A770, void*, const qVector3&, const qVector3&)(this, aabbMin, aabbMax);
		}

		void DeletePedsFromDeactivatedRegions() { SDK_CALL_FUNC(void, 0x40AB40, void*)(this); }
		void ExamineActiveZones() { SDK_CALL_FUNC(void, 0x40AF60, void*)(this); }
		void ExamineInactiveZones() { SDK_CALL_FUNC(void, 0x40B1D0, void*)(this); }
		PedSpawningInfo* FindPedInfoFromSimObject(SimObject* simObj) { return SDK_CALL_FUNC(PedSpawningInfo*, 0x40B4E0, void*, SimObject*)(this, simObj); }

		PedSpawningInfo* FindPedToRepurposeForVehicle(qPropertyList* classPriorities, qPropertyList* classExclusions) {
			return SDK_CALL_FUNC(PedSpawningInfo*, 0x40B550, void*, qPropertyList*, qPropertyList*)(this, classPriorities, classExclusions);
		}

		u32 FindPedsToRepurpose(int indexOfRequiredSpawnSet, u32 how_many_needed, bool isHighPriority) {
			return SDK_CALL_FUNC(u32, 0x40B740, void*, int, u32, bool)(this, indexOfRequiredSpawnSet, how_many_needed, isHighPriority);
		}

		void FrameRateThrottle() { SDK_CALL_FUNC(void, 0x40B960, void*)(this); }

		eActiveZoneClass GetActiveZoneFromPoint(const qVector3& raw_pos, PedSpawningInfo::eActiveStatus current_status) {
			return SDK_CALL_FUNC(eActiveZoneClass, 0x40BAB0, void*, const qVector3&, PedSpawningInfo::eActiveStatus)(this, raw_pos, current_status);
		}

		SimObjectCharacter* GetAmbientPedForVehicle(qPropertyList* classPriorities, qPropertyList* classExclusions, PedSpawningInfo** newPedInfo) {
			return SDK_CALL_FUNC(SimObjectCharacter*, 0x40BC30, void*, qPropertyList*, qPropertyList*, PedSpawningInfo**)(this, classPriorities, classExclusions, newPedInfo);
		}

		void GetGroupCandidates(PedSpawningInfo* pPed, qFixedArray<PedSpawningInfo*, 10>& closePeds, const qVector3& pos, f32 radius) {
			SDK_CALL_FUNC(void, 0x40C030, void*, PedSpawningInfo*, qFixedArray<PedSpawningInfo*, 10>&, const qVector3&, f32)(this, pPed, closePeds, pos, radius);
		}

		PedSpawningInfo::eActiveStatus GetIdealActiveStatus(PedSpawningInfo& info) { return SDK_CALL_FUNC(PedSpawningInfo::eActiveStatus, 0x40C1E0, void*, PedSpawningInfo&)(this, info); }

		void GetNewNearestFromArray(PedSpawningInfo** arrayOfInfo, u32& index, f32& dist, int how_many_needed) {
			SDK_CALL_FUNC(void, 0x40C5D0, void*, PedSpawningInfo**, u32&, f32&, int)(this, arrayOfInfo, index, dist, how_many_needed);
		}

		void Init() { SDK_CALL_FUNC(void, 0x40D080, void*)(this); }
		bool IsPedValidForSet(int indexOfRequiredSpawnSet, PedSpawningInfo& pedInfo) { return SDK_CALL_FUNC(bool, 0x40DD00, void*, int, PedSpawningInfo&)(this, indexOfRequiredSpawnSet, pedInfo); }

		bool IsValidPedForRepurpose(PedSpawningInfo& pedInfo, bool isHighPriority, f32& dist) {
			return SDK_CALL_FUNC(bool, 0x40E0C0, void*, PedSpawningInfo&, bool, f32&)(this, pedInfo, isHighPriority, dist);
		}

		bool JoinGroup(SimObject* pObj, qPropertySet* pPropSet, qVector3& startPos, SpawnRegion* pSourceRegion) {
			return SDK_CALL_FUNC(bool, 0x40E180, void*, SimObject*, qPropertySet*, qVector3&, SpawnRegion*)(this, pObj, pPropSet, startPos, pSourceRegion);
		}

		int MakeRoomForMorePeds(u32 how_many, bool high_priority) { return SDK_CALL_FUNC(int, 0x40E570, void*, u32, bool)(this, how_many, high_priority); }
		void ProcessZonesDueToSpawn() { SDK_CALL_FUNC(void, 0x4136F0, void*)(this); }
		void ReInitAmbient() { SDK_CALL_FUNC(void, 0x413F20, void*)(this); }

		int RegisterActiveSpawnPoint(SpawnPoint* pPoint, SceneObjectProperties* pSpawnSceneObj) {
			return SDK_CALL_FUNC(int, 0x4143C0, void*, SpawnPoint*, SceneObjectProperties*)(this, pPoint, pSpawnSceneObj);
		}

		void RegisterActiveSpawnRegion(SpawnRegion* pRegion, SceneObjectProperties* pSceneObj) {
			SDK_CALL_FUNC(void, 0x414530, void*, SpawnRegion*, SceneObjectProperties*)(this, pRegion, pSceneObj);
		}

		void RegisterPed(SimObjectCharacter* pedToRegister, qPropertySet* pArchetypePropSet, qPropertySet* pInstancePropertySet, qWiseSymbol IsAmbientRegionPed, bool canSuspend, bool called_from_skookum) {
			SDK_CALL_FUNC(void, 0x414B60, void*, SimObjectCharacter*, qPropertySet*, qPropertySet*, qWiseSymbol, bool, bool)(this, pedToRegister, pArchetypePropSet, pInstancePropertySet, IsAmbientRegionPed, canSuspend, called_from_skookum);
		}

		int RegisterSpawnSet(qPropertySet* pSpawnInfoSet, bool needed_for_thug_region) {
			return SDK_CALL_FUNC(int, 0x4150F0, void*, qPropertySet*, bool)(this, pSpawnInfoSet, needed_for_thug_region);
		}

		void RegisterSpawningPOI(InterestPoint* pPOI, SceneObjectProperties* pSceneObj) { SDK_CALL_FUNC(void, 0x4152A0, void*, InterestPoint*, SceneObjectProperties*)(this, pPOI, pSceneObj); }
		
		SimObject* ReleaseOwnership(SimObject* _a_pObj, u32 desired_suspend_option, bool returning_from_mission_use) {
			return SDK_CALL_FUNC(SimObject*, 0x4153B0, SimObject*, u32, bool)(_a_pObj, desired_suspend_option, returning_from_mission_use);
		}

		int ReleaseRefToSpawnInfo(qPropertySet* pSpawnInfoSet) { return SDK_CALL_FUNC(int, 0x4156C0, void*, qPropertySet*)(this, pSpawnInfoSet); }
		void ResetSpawnZones() { SDK_CALL_FUNC(void, 0x416140, void*)(this); }
		void RestoreAllScriptedToFullyActive() { SDK_CALL_FUNC(void, 0x4161D0, void*)(this); }
		void SetAmbientStartingMode(PedSpawningInfo& info, const qVector3& pos) { SDK_CALL_FUNC(void, 0x416620, void*, PedSpawningInfo&, const qVector3&)(this, info, pos); }
		void SetHighDefSpawning(bool hi_def_setting) { SDK_CALL_FUNC(void, 0x4166F0, void*, bool)(this, hi_def_setting); }

		void SetStartMode(SimObject* pObj, qPropertySet* pPropSet, const qVector3& startPos) {
			SDK_CALL_FUNC(void, 0x416A80, void*, SimObject*, qPropertySet*, const qVector3&)(this, pObj, pPropSet, startPos);
		}

		bool SetSuspendOption(SimObjectGame* pedSimObj, PedSpawningInfo::eSuspendAction suspendAction) {
			return SDK_CALL_FUNC(bool, 0x416AA0, void*, SimObjectGame*, PedSpawningInfo::eSuspendAction)(this, pedSimObj, suspendAction);
		}

		void SetupSocialForNIS(bool bNISStarting) { SDK_CALL_FUNC(void, 0x416E60, void*, bool)(this, bNISStarting); }
		int SpawnPedsInActiveZones(int howManyToSpawn) { return SDK_CALL_FUNC(int, 0x4172C0, void*, int)(this, howManyToSpawn); }
		void SpawnZonesNearCamera(f32 dist) { SDK_CALL_FUNC(void, 0x417710, void*, f32)(this, dist); }
		void SuspendAllScripted() { SDK_CALL_FUNC(void, 0x417A40, void*)(this); }
		int ThugZoneDisabled(SpawnZone* pZone) { return SDK_CALL_FUNC(int, 0x417C10, void*, SpawnZone*)(this, pZone); }

		bool TryJoinGroup(PedSpawningInfo& pPed, qVector3& pos, const bool groupIsNotAllowed, SpawnRegion* pSourceRegion) {
			return SDK_CALL_FUNC(bool, 0x417D70, void*, PedSpawningInfo&, qVector3&, const bool, SpawnRegion*)(this, pPed, pos, groupIsNotAllowed, pSourceRegion);
		}

		void UnRegisterActiveSpawnPoint(SpawnPoint* pPoint, SceneObjectProperties* pSceneObj) { SDK_CALL_FUNC(void, 0x417EC0, void*, SpawnPoint*, SceneObjectProperties*)(this, pPoint, pSceneObj); }
		void UnRegisterActiveSpawnRegion(SpawnRegion* pRegion) { SDK_CALL_FUNC(void, 0x418040, void*, SpawnRegion*)(this, pRegion); }
		void UnRegisterSpawningPOI(InterestPoint* pPOI, SceneObjectProperties* pSceneObj) { SDK_CALL_FUNC(void, 0x4180C0, void*, InterestPoint*, SceneObjectProperties*)(this, pPOI, pSceneObj); }
	};
	SDK_ASSERT_SIZEOF(PedSpawnManager, 0x4D018);

	//---------------------------------------------

	SDK_INLINE void PedSpawning_AmbientPedEnableHelper(bool enablePeds) { SDK_CALL_FUNC(void, 0x413620, bool)(enablePeds); }
	SDK_INLINE void PedSpawning_AmbientPedEnableLockHelper(bool lock) { sAmbientPedEnableLocked = lock; }
}