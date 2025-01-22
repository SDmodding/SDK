#pragma once

// Move this to appropriate file.
namespace UFG
{
	class MissionWorkStatus : public qNode<MissionWorkStatus>
	{
	public:
		qString mCategory;
		qString mStatus;
	};
}

namespace UFG
{
	class GameSliceCollection : public qNodeRB<GameSliceCollection>
	{
	public:
		qSymbol mName;
		qSet<GameSlice> mHighPrioritySlices;
	};

	class GameSliceMasks
	{
	public:
		bool mEnabledCategory[12];
		qSet<GameSlice> mMasks;
	};

	class GameSlice : public qNodeRB<GameSlice>
	{
	public:
		enum CleanupState
		{
			CLEANUP_NONE,
			CLEANUP_SCRIPT_PENDING,
			CLEANUP_SCRIPT_CLEANUP,
			CLEANUP_LAYER_PENDING,
			CLEANUP_LAYER_CLEANUP
		};

		enum CompletionStatus
		{
			STATUS_DISABLE,
			STATUS_ENABLE,
			QUERY_STATUS = -1
		};

		enum ContentPriority
		{
			CONTENTPRIORITY_DISABLED,
			CONTENTPRIORITY_AMBIENT,
			CONTENTPRIORITY_SPRINKLE,
			CONTENTPRIORITY_SCENARIO,
			CONTENTPRIORITY_EVENT,
			CONTENTPRIORITY_CRITICAL
		};

		enum MaskType
		{
			MASK_ENABLE,
			MASK_DISABLE,
			MASK_COUNT
		};

		enum State
		{
			STATE_LOCKED,
			STATE_UNLOCKED = (1 << 0),
			STATE_RESTORING = (1 << 1),
			STATE_STARTED = (1 << 2),
			STATE_COMPLETED = (1 << 3),
			STATE_STARTEDorCOMPLETED = STATE_STARTED | STATE_COMPLETED,
		};

		enum TrackType
		{
			STAT_INVALID,
			STAT_MISSION,
			STAT_CASE,
			STAT_EVENT,
			STAT_FAVOUR,
			STAT_JOB,
			STAT_DATE,
			STAT_RACE,
			STAT_DLC,
			STAT_JOB_PRESENCE,
			STAT_CASE_PRESENCE
		};

		enum Type
		{
			TYPE_DISABLED,
			TYPE_AMBIENT,
			TYPE_FAIL,
			TYPE_SCENARIO,
			TYPE_SPRINKLE,
			TYPE_EVENT,
			TYPE_FAVOUR,
			TYPE_JOB,
			TYPE_RACE,
			TYPE_DATE,
			TYPE_CASE,
			TYPE_MISSION,
			NUM_TYPES
		};

		qSharedString mName;
		qSharedString mTitle;
		qSharedString mScriptClassName;
		PDATriggerParameters* mPDATriggerParameters;
		qSharedString mNisPath;
		SceneSettings* mNisSceneSettings;
		bool mNisPostFadeIn;
		bool mNisIntermediate;
		qSharedString mGamePlayState;
		qSharedString mGeoState;
		qSharedString mLightingState;
		qSharedString mMissionFlowState;
		qSharedString mObjectiveBlipState;
		qSharedString mEncounterState;
		qSharedString mAssetState;
		qSharedString mPresentationState;
		qSharedString mAudioOverride;
		qSharedString mSaveGameNameOverride;
		qSymbol mLayerName;
		qSymbol mTriggerObjectName;
		qSymbol mRestoreLocationMarker;
		qSymbol mVehicleMarker;
		qSymbol mRestoreWeapon;
		qSymbol mSaveGamesliceOverrideName;
		f32 mVehicleMarkerRange;
		qSymbol mCancelLocationMarker;
		qSymbol mCompleteLocationMarker;
		int mMinimumDependentsRequired;
		int mMaxHeatLevel;
		int mMinPipLevel;
		int mFaceActionType;
		bool mAutosave;
		bool mAllowUICancellation;
		qVector3 mLocation;
		u32 mRepeatableInterval;
		i64 mScriptBinaryFileSize;
		SSGameSlice* mScript;
		GameSlice* mExclusiveChild;
		State mState;
		Type mType;
		CompletionStatus mCompletionStatus;
		u64 mCompletionStatusTimestamp;
		bool mIsTODRestricted;
		f32 mTODActive;
		f32 mTODInactive;
		f32 mTODRestore;
		bool mTODBypassPrompt;
		bool mPerformTimeShift;
		bool mVehicleSuperStop;
		bool mKeepTriggerObjectiveEnabled;
		bool mDisableCopScoring;
		bool mDisableTriadScoring;
		u64 mFailTimeout;
		i8 mEnabled;
		i8 mRoot;
		i8 mDirty;
		i8 mOptional;
		i8 mExclusive;
		i8 mPersistent;
		i8 mRequiresSave;
		i8 mRandomExclusive;
		i8 mHoldCurtain;
		i8 mHoldStreamer;
		i8 mCheckpointSlice;
		i8 mInternalSlice;
		i8 mWaitingForTrigger;
		i8 mLayerEnabledByMe;
		i8 mIgnoreSafehouseRestore;
		i8 mDeferStartIfInsideRegion;
		i8 mDeferRestartIfInsideRegion;
		i8 mCountedStats;
		i8 mStreamRequested;
		i8 mTrackType;
		i8 mStatsId;
		qSymbol mDLCProductId;
		SceneSettings* mSceneSettings;
		CleanupState mCleanupPending;
		i16 mCompletionCount;
		i16 mCleanupCount;
		GameSlice* mpParent;
		qSet<GameSlice> mDependents;
		qSet<GameSlice> mChildren;
		PropertySetHandle mRewardsProperties;
		PropertySetHandle mRepeatedRewardsProperties;
		GameSlice* mpDependentMission;
		GameSlice* mpLastActiveSublice;
		GameSliceMasks* maMasks[2];
		GameSliceCollection* mpCollection;
		bool mCollectionHighPriority;
		bool mIsSingleCharacterSprinkle;
		qSymbol mSprinkleCharacter1Override;
		qSymbol mSprinkleCharacter2Override;
		qSymbol mSubsetModeType;
		qSafePointer<SimObject, SimObject> mpRestoredVehicle;
		qSet<qSafePointer<SimObject, SimObject>> mBorrowedActors;
		qList<MissionWorkStatus> mMissionStates;
		qSet<GameSlice> mReEnableSlices;
		f32 mStateDisplaySeconds;
		f32 mSecondsLeftToDisplayFor;

		/* Impl Functions */

		SDK_INLINE GameSlice* GetChild(int index) { return mChildren[index]; }
		SDK_INLINE u32 GetNumChildren() { return mChildren.mCount; }
		SDK_INLINE GameSlice* GetParent() { return mpParent; }

		/* Functions */

		GameSlice* AddChild(const qString& pName) { return SDK_CALL_FUNC(GameSlice*, 0x492A10, void*, const qString&)(this, pName); }
		void AddDependency(const char* pName) { SDK_CALL_FUNC(void, 0x492B80, void*, const char*)(this, pName); }
		void AddReEnableSlice(const qString& pName) { SDK_CALL_FUNC(void, 0x4938D0, void*, const qString&)(this, pName); }
		void BorrowAmbientActor(SimObject* actor) { SDK_CALL_FUNC(void, 0x4956E0, void*, SimObject*)(this, actor); }
		bool CanBeEnabled() { return SDK_CALL_FUNC(bool, 0x4967E0, void*)(this); }
		bool CanDependantsBeEnabled() { return SDK_CALL_FUNC(bool, 0x496820, void*)(this); }
		void ClaimExclusive() { SDK_CALL_FUNC(void, 0x496CF0, void*)(this); }
		void CleanupPedsAndVehicles() { SDK_CALL_FUNC(void, 0x496F80, void*)(this); }
		void CleanupSceneLayers() { SDK_CALL_FUNC(void, 0x496FF0, void*)(this); }
		void CleanupTimeAndWeather() { SDK_CALL_FUNC(void, 0x497600, void*)(this); }
		void CompleteSlice() { SDK_CALL_FUNC(void, 0x499710, void*)(this); }
		void CreateRuntimeRewardsPropertySets() { SDK_CALL_FUNC(void, 0x499F00, void*)(this); }
		void End(CompletionStatus status) { SDK_CALL_FUNC(void, 0x49DD90, void*, CompletionStatus)(this, status); }
		void FailSlice(const qString& caption) { SDK_CALL_FUNC(void, 0x4A01C0, void*, const qString&)(this, caption); }
		void ForceLock(bool isReset) { SDK_CALL_FUNC(void, 0x4A1050, void*, bool)(this, isReset); }
		qSharedString GetAudioName() { return SDK_CALL_FUNC(qSharedString, 0x59CD00, void*)(this); }
		const qSymbol& GetCancelLocationMarker() { return SDK_CALL_FUNC(const qSymbol&, 0x4A1D20, void*)(this); }
		GameSlice* GetDependentRecursive(Type type, int& depth) { return SDK_CALL_FUNC(GameSlice*, 0x4A22B0, void*, Type, int&)(this, type, depth); }
		qPropertySet* GetRewardsProperties() { return SDK_CALL_FUNC(qPropertySet*, 0x4A6070, void*)(this); }
		Type GetTypeFromCategoryName(const qString& name) { return SDK_CALL_FUNC(Type, 0x4A7210, const qString&)(name); }
		bool HasProgressionTrigger() { return SDK_CALL_FUNC(bool, 0x4AA820, void*)(this); }
		bool IsAllowedAtThisTimeOfDay() { return SDK_CALL_FUNC(bool, 0x4AB9E0, void*)(this); }
		bool IsDeferredRestartIfInsideRegion() { return SDK_CALL_FUNC(bool, 0x4ABF00, void*)(this); }
		bool IsEnabledForCurrentMode() { return SDK_CALL_FUNC(bool, 0x4ABF30, void*)(this); }
		bool IsExclusiveAvailable() { return SDK_CALL_FUNC(bool, 0x4ABFB0, void*)(this); }
		bool IsRewardPropertyRaceType() { return SDK_CALL_FUNC(bool, 0x4ACBD0, void*)(this); }
		bool IsRunningExclusiveChild(GameSlice* pChild) { return SDK_CALL_FUNC(bool, 0x4ACC60, void*, GameSlice*)(this, pChild); }
		bool IsWaitingForTrigger() { return SDK_CALL_FUNC(bool, 0x4AD130, void*)(this); }
		void OnEnterTrigger(TriggerRegion* pTriggerRegion) { SDK_CALL_FUNC(void, 0x4B1670, void*, TriggerRegion*)(this, pTriggerRegion); }
		void OnExitTrigger(TriggerRegion* pTriggerRegion) { SDK_CALL_FUNC(void, 0x4B16E0, void*, TriggerRegion*)(this, pTriggerRegion); }
		void OnSafehouseRestore() { SDK_CALL_FUNC(void, 0x4B1DC0, void*)(this); }
		void ReturnAllAmbientActors() { SDK_CALL_FUNC(void, 0x4B8110, void*)(this); }
		void SetCollection(const qString& collectionName, bool highPriority) { SDK_CALL_FUNC(void, 0x4BBD40, void*, const qString&, bool)(this, collectionName, highPriority); }
		void SetEnabled(bool isEnabled) { SDK_CALL_FUNC(void, 0x4BC130, void*, bool)(this, isEnabled); }
		void SetRestoreVehicle(SimObject* vehicle) { SDK_CALL_FUNC(void, 0x4BD0A0, void*, SimObject*)(this, vehicle); }
		void SetState(State newState) { SDK_CALL_FUNC(void, 0x4BD6F0, void*, State)(this, newState); }
		void SetType(Type type) { SDK_CALL_FUNC(void, 0x4BDCE0, void*, Type)(this, type); }
		void SetWaitingForTrigger(bool isWaiting, bool turnLayerOn) { SDK_CALL_FUNC(void, 0x4BDD50, void*, bool, bool)(this, isWaiting, turnLayerOn); }
		void SetupPedsAndVehicles() { SDK_CALL_FUNC(void, 0x4BDE40, void*)(this); }
		void SetupSceneLayers() { SDK_CALL_FUNC(void, 0x4BDEB0, void*)(this); }
		void SetupTimeAndWeather(bool immediate) { SDK_CALL_FUNC(void, 0x4BE5C0, void*, bool)(this, immediate); }
		bool ShouldDestroyVehicleOnStart() { return SDK_CALL_FUNC(bool, 0x4BE6F0, void*)(this); }
		bool ShouldTeleportOnStart() { return SDK_CALL_FUNC(bool, 0x4BE910, void*)(this); }
		bool ShouldTeleportVehicleOnStart() { return SDK_CALL_FUNC(bool, 0x4BE930, void*)(this); }
		void ShutdownScript(CompletionStatus status) { SDK_CALL_FUNC(void, 0x4BEB80, void*, CompletionStatus)(this, status); }
		void Start() { SDK_CALL_FUNC(void, 0x4BEF50, void*)(this); }
		void StartScript() { SDK_CALL_FUNC(void, 0x4BF760, void*)(this); }
		void StopDrivenVehicle() { SDK_CALL_FUNC(void, 0x4C1960, void*)(this); }
		void Unlock(State newState) { SDK_CALL_FUNC(void, 0x4C3F20, void*, State)(this, newState); }
		void UpdateCleanupPending() { SDK_CALL_FUNC(void, 0x4C5C50, void*)(this); }
		void UpdateDependency() { SDK_CALL_FUNC(void, 0x4C60A0, void*)(this); }
		void _DisableLayer() { SDK_CALL_FUNC(void, 0x4C9210, void*)(this); }
		void _EnableLayer() { SDK_CALL_FUNC(void, 0x4C9260, void*)(this); }
		//void _HandleCompletionRewards(ShowRewardType showRewardType) { SDK_CALL_FUNC(void, 0x4C92B0, void*, ShowRewardType)(this, showRewardType); }
		bool _IsChildOf(GameSlice* pSlice) { return SDK_CALL_FUNC(bool, 0x4C9440, void*, GameSlice*)(this, pSlice); }
		void _MarkExclusiveChild(GameSlice* pChild) { SDK_CALL_FUNC(void, 0x4C9810, void*, GameSlice*)(this, pChild); }
		void _SimulateComplete(bool simulateRewards) { SDK_CALL_FUNC(void, 0x4C9850, void*, bool)(this, simulateRewards); }
		void _SimulateUnlock(bool simulateRewards) { SDK_CALL_FUNC(void, 0x4C9960, void*, bool)(this, simulateRewards); }
	};
	SDK_ASSERT_SIZEOF(GameSlice, 0x240);
}