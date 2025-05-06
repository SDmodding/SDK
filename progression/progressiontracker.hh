#pragma once

namespace UFG
{
	class ProgressionTracker
	{
	public:
		enum ActiveMasterMode
		{
			ActiveMasterMode_OpenWorld,
			ActiveMasterMode_Container,
			ActiveMasterMode_Challenge_Container,
			ActiveMasterMode_Undefined
		};

		enum ModeType
		{
			ModeType_Normal,
			ModeType_Challenge_Setup,
			ModeType_Challenge
		};

		enum MonetaryPenaltyType
		{
			MonetaryPenalty_None,
			MonetaryPenalty_Arrest,
			MonetaryPenalty_Hospitalization
		};

		enum OpenWorldSnapshotState
		{
			Update_Requested,
			Update_Pending,
			Update_Completed
		};

		enum RestoreType
		{
			RestoreType_Unknown,
			RestoreType_Safehouse,
			RestoreType_SafehouseComputer,
			RestoreType_SafehouseFailure,
			RestoreType_GameLoad,
			RestoreType_Hospital,
			RestoreType_PoliceStation,
			RestoreType_ScriptLocation
		};

		enum State
		{
			STATE_INVALID,
			STATE_NORMAL,
			STATE_DANGER,
			STATE_COMPLETE,
			STATE_INCOMPLETE,
			STATE_ANIMATE_COMPLETE,
			NUM_STATES
		};

		enum TimeShiftState
		{
			TS_STATE_NONE,
			TS_FADE_IN,
			TS_FADE_IN2,
			TS_SHIFT,
			TS_SHIFT2,
			TS_FADE_OUT,
			TS_FADE_OUT2
		};

		struct LayerOwnershipInfo
		{
			SceneLayer* mpLayer;
			GameSlice* mpGameSlice;
		};

		s8 gActiveGameSlices[12];
		s8 gActiveContainers[12];
		State mState;
		qTreeRB<GameSlice> mGameSlices;
		qTreeRB<GameSlice> mContainerGameSlices;
		qTreeRB<GameSlice> mDisabledGameSlices;
		qTreeRB<GameSliceCollection> mCollections;
		qTreeRB<SceneSettings> mSceneSettings;
		qSet<LayerOwnershipInfo> mLayerOwnership;
		ObjectiveTracker mObjectiveTracker;
		SecondaryObjectiveTracker mSecondaryObjectiveTracker;
		PDATriggerTracker mPDATriggerTracker;
		CaseTracker mCaseTracker;
		GameSliceStreamer mGameSliceStreamer;
		qString mLocationPath;
		qString mDependencyGraphName;
		qSymbol mDEBUGTestScenarioScriptName;
		qSymbol mDEBUGTestScenarioParameter;
		GameSlice* mpActiveMaster;
		GameSlice* mpLastCheckpoint;
		GameSlice* mpLastFailed;
		OpenWorldSnapshotState mbOpenWorldSnapshotState;
		bool mbPendingSceneSettingsValid;
		SceneSettings mPendingSceneSettingsLocal;
		SceneSettings mPendingSceneSettingsCache;
		MonetaryPenaltyType mMonetaryPenalty;
		bool mIsLoaded;
		bool mIsLoadedSimple;
		bool mDirty;
		bool mContainerCompleted;
		bool mDisableProgression;
		bool mHoldCurtainPostRestore;
		bool mIsWorldDataRestored;
		RestoreType mRestoreType;
		RestoreType mRestoringType;
		ModeType mModeType;
		qSymbol mSubSetModeType;
		bool mResourceFreezeMode;
		bool mCheckpointChanged;
		bool mMasterModeChanged;
		bool mCommitOnMasterModeChanged;
		GameSlice* mpAutoSaveQueuedSlice;
		ActiveMasterMode mActiveMasterMode;
		u64 mLastUpdateTimestamp;
		u64 mContainerCompletedTimestamp;
		AnimationGroupHandleContainer mAnimationGroupHandleContainer;
		qString mGlobalAlternateLayer;
		TimeShiftState mTimeShiftState;
		f32 mTimeShiftTimer;
		GameSlice* mTimeShiftSlice;
		ProgressionTriggerComponent* mTimeShiftTrigger;
		qSafePointer<SimObject, SimObjectVehicle> mLastUsedVehicle;
		qProxy<GameSetup> mGameSetup;
		qSymbol mActiveFlowId;
		bool mIsPossessedPedsEnabled;

		/* Static Functions */

		SDK_SINLINE ProgressionTracker* Instance() { return SDK_VAR(ProgressionTracker*, 0x240A0E0); }
		SDK_SINLINE qStaticSymbol GetDefaultFlow() { return 0xAA1CA048; } // Main

		/* Impl Functions */

		SDK_INLINE const qSymbol& GetActiveFlow() const { return mActiveFlowId; }
		SDK_INLINE GameSlice* GetActiveMaster() { return mpActiveMaster; }
		SDK_INLINE GameSetup* GetGameSetup() { return &mGameSetup; }
		SDK_INLINE GameSlice* GetLastCheckpoint() { return mpLastCheckpoint; }
		SDK_INLINE int GetNumContainerSlices() { return mContainerGameSlices.mTree.mCount; }
		SDK_INLINE bool IsUICancellationAllowed() { return (!mpActiveMaster || mpActiveMaster->mAllowUICancellation); }
		SDK_INLINE void SetMode(ModeType mode) { mModeType = mode; }

		/* Functions */

		void ActiveMasterCheck() { SDK_CALL_FUNC(void, 0x492400, void*)(this); }
		void AdjustPlayerLocationToGround() { SDK_CALL_FUNC(void, 0x493D10, void*)(this); }
		void ApplyGameplayEffects() { SDK_CALL_FUNC(void, 0x4944D0, void*)(this); }
		void ApplyMonetaryPenalty() { SDK_CALL_FUNC(void, 0x494590, void*)(this); }
		void ApplyMonetaryReward(int moneyCount) { SDK_CALL_FUNC(void, 0x494670, void*, int)(this, moneyCount); }
		void ApplySceneSettings(SceneSettings* settings) { SDK_CALL_FUNC(void, 0x494C90, void*, SceneSettings*)(this, settings); }
		void ApplySceneSettings(const qVector3& position) { SDK_CALL_FUNC(void, 0x494C10, void*, const qVector3&)(this, position); }
		void ApplySceneSettingsCached(const SceneSettings& settings) { SDK_CALL_FUNC(void, 0x494CC0, void*, const SceneSettings&)(this, settings); }
		void BindChallengeGameSlice(const char* gameslicename) { SDK_CALL_FUNC(void, 0x495180, void*, const char*)(this, gameslicename); }
		void BindProgressionStage() { SDK_CALL_FUNC(void, 0x495450, void*)(this); }
		void BindStartupLocation() { SDK_CALL_FUNC(void, 0x495650, void*)(this); }
		void BuildSavegameSnapshot() { SDK_CALL_FUNC(void, 0x495D20, void*)(this); }

		void CancelMission(GameSlice* pGameSlice, bool resetScene, RestoreType restoreType) {
			SDK_CALL_FUNC(void, 0x4968F0, void*, GameSlice*, bool, RestoreType)(this, pGameSlice, resetScene, restoreType);
		}

		void DEBUG_LaunchTestScenarioIfAvailable() { SDK_CALL_FUNC(void, 0x49A0B0, void*)(this); }
		void DeleteDisabledGameSlices() { SDK_CALL_FUNC(void, 0x49A980, void*)(this); }
		void DestroyVehicle() { SDK_CALL_FUNC(void, 0x49D0B0, void*)(this); }
		void DiscardSnapshot() { SDK_CALL_FUNC(void, 0x49D0D0, void*)(this); }
		void DrawMissionWorkStates(f32 realTimeDelta) { SDK_CALL_FUNC(void, 0x49DAC0, void*, f32)(this, realTimeDelta); }

		void EnableGameSliceTODWait(GameSlice* slice, ProgressionTriggerComponent* trigger) {
			SDK_CALL_FUNC(void, 0x49DC00, void*, GameSlice*, ProgressionTriggerComponent*)(this, slice, trigger);
		}

		void ExitChallenge(bool success) { SDK_CALL_FUNC(void, 0x49FC20, void*, bool)(this, success); }
		GameSlice* Find(const qSymbol& name, bool searchDisabledSlices) { return SDK_CALL_FUNC(GameSlice*, 0x4A0380, void*, const qSymbol&, bool)(this, name, searchDisabledSlices); }
		GameSlice* FindByLayer(const qSymbol& name) { return SDK_CALL_FUNC(GameSlice*, 0x4A03F0, void*, const qSymbol&)(this, name); }
		GameSlice* FindSceneSettings(const qSymbol& name) { return SDK_CALL_FUNC(GameSlice*, 0x4A07F0, void*, const qSymbol&)(this, name); }
		void FixupMasterLists(bool allowDisabledSlices) { SDK_CALL_FUNC(void, 0x4A0CF0, void*, bool)(this, allowDisabledSlices); }
		void ForceProgress(GameSlice* pData, bool simulateRewards) { SDK_CALL_FUNC(void, 0x4A11F0, void*, GameSlice*, bool)(this, pData, simulateRewards); }
		void ForceSliceChange(GameSlice* pData, bool simulateRewards) { SDK_CALL_FUNC(void, 0x4A1390, void*, GameSlice*, bool)(this, pData, simulateRewards); }
		GameSlice* GetContainerSlice(int index) { return SDK_CALL_FUNC(GameSlice*, 0x4A2000, void*, int)(this, index); }
		qPropertySet* GetGameFlowProperties(const qSymbol& flowId) { return SDK_CALL_FUNC(qPropertySet*, 0x4A3310, void*, const qSymbol&)(this, flowId); }
		const char* GetSaveGameName() { return SDK_CALL_FUNC(const char*, 0x4A60E0, void*)(this); }
		bool GetStartupLocation(qMatrix44& transRotation) { return SDK_CALL_FUNC(bool, 0x4A6340, void*, qMatrix44&)(this, transRotation); }
		GameSlice* GetStartupSlice() { return SDK_CALL_FUNC(GameSlice*, 0x4A6410, void*)(this); }
		void HandleActiveMasterChanged() { SDK_CALL_FUNC(void, 0x4A7390, void*)(this); }
		bool IsCleanupCompleted() { return SDK_CALL_FUNC(bool, 0x4ABA50, void*)(this); }
		bool IsRunningCriticalActiveMaster() { return SDK_CALL_FUNC(bool, 0x4ACC30, void*)(this); }
		bool LoadDependencyGraph() { return SDK_CALL_FUNC(bool, 0x4ADF10, void*)(this); }
		void LoadGraph() { SDK_CALL_FUNC(void, 0x4AE620, void*)(this); }
		void LoadSnapshotWeather() { SDK_CALL_FUNC(void, 0x4AEE80, void*)(this); }

		bool LoadSupportFile(const char* pLocationPath, const char* pFilename, ProgressionTracker* pAuthor) {
			return SDK_CALL_FUNC(bool, 0x4AF1A0, void*, const char*, const char*, ProgressionTracker*)(this, pLocationPath, pFilename, pAuthor);
		}

		bool LoadedProgression(u32 dPoint, char* pDeserializeBuffer, u32 bufferSize, bool resetProgression) {
			return SDK_CALL_FUNC(bool, 0x4B0680, void*, u32, char*, u32, bool)(this, dPoint, pDeserializeBuffer, bufferSize, resetProgression);
		}

		void LockAllRunningGameSlicesForSoftReset() { SDK_CALL_FUNC(void, 0x4B0850, void*)(this); }
		void MarkCleanup() { SDK_CALL_FUNC(void, 0x4B0D20, void*)(this); }
		void MoveAllSlicesInDisabledList() { SDK_CALL_FUNC(void, 0x4B1070, void*)(this); }
		void OnFailGameSlice(GameSlice* pGameSlice, const qString& caption) { SDK_CALL_FUNC(void, 0x4B1840, void*, GameSlice*, const qString&)(this, pGameSlice, caption); }
		void OnFailObject(SimObjectGame* pObject, const qString& caption) { SDK_CALL_FUNC(void, 0x4B1970, void*, SimObjectGame*, const qString&)(this, pObject, caption); }

		//void ParseSceneSettings(SimpleXML::XMLDocument* pDocument, SimpleXML::XMLNode* pSceneSettingsXMLNode) { SDK_CALL_FUNC(void, 0x4B1FA0, void*, SimpleXML::XMLDocument*, SimpleXML::XMLNode*)(this, pDocument, pSceneSettingsXMLNode); }
		
		void PublishProgressionStatistics() { SDK_CALL_FUNC(void, 0x4B2D10, void*)(this); }

		void ResetProgression(RestoreType restoreType, u32 newGameState, bool useCurrentLocation) {
			SDK_CALL_FUNC(void, 0x4B7060, void*, RestoreType, u32, bool)(this, restoreType, newGameState, useCurrentLocation);
		}

		void Restart(GameSlice* pData) { SDK_CALL_FUNC(void, 0x4B75A0, void*, GameSlice*)(this, pData); }
		void RestoreCheckpoint() { SDK_CALL_FUNC(void, 0x4B7660, void*)(this); }
		void RestoreCheckpointInternal() { SDK_CALL_FUNC(void, 0x4B7690, void*)(this); }
		void RestorePlayerLocation() { SDK_CALL_FUNC(void, 0x4B7AE0, void*)(this); }
		void RestoreVehicle(GameSlice* slice) { SDK_CALL_FUNC(void, 0x4B7E70, void*, GameSlice*)(this, slice); }
		void SaveSnapshotWeather() { SDK_CALL_FUNC(void, 0x4B8DB0, void*)(this); }
		void SetActiveFlow(const qSymbol& flowId) { SDK_CALL_FUNC(void, 0x4BB850, void*, const qSymbol&)(this, flowId); }

		void SetActiveMaster(GameSlice* pActiveMaster, GameSlice* pCheckpoint, bool forceSave) {
			SDK_CALL_FUNC(void, 0x4BB8B0, void*, GameSlice*, GameSlice*, bool)(this, pActiveMaster, pCheckpoint, forceSave);
		}

		void SetLastCompleted(GameSlice* pGameSlice) { SDK_CALL_FUNC(void, 0x4BCCE0, void*, GameSlice*)(this, pGameSlice); }
		void SetLastUsedVehicle(SimObjectVehicle* vehicle) { SDK_CALL_FUNC(void, 0x303690, void*, SimObjectVehicle*)(this, vehicle); }
		void SetResourceFreezeMode(bool enable) { SDK_CALL_FUNC(void, 0x4BCFA0, void*, bool)(this, enable); }
		void SetRestoreType(RestoreType restoreType, bool useCurrentLocation) { SDK_CALL_FUNC(void, 0x4BCFB0, void*, RestoreType, bool)(this, restoreType, useCurrentLocation); }
		void SetScriptRestoreLocation(const qVector3& position) { SDK_CALL_FUNC(void, 0x4BD0F0, void*, const qVector3&)(this, position); }
		void SetupGlobalAlternateLayer() { SDK_CALL_FUNC(void, 0x4BDDF0, void*)(this); }
		void StartTrackingMissionScoring(GameSlice* pGameSlice, bool resetScore) { SDK_CALL_FUNC(void, 0x4BFC40, void*, GameSlice*, bool)(this, pGameSlice, resetScore); }
		void SyncCompleted(bool simulateRewards) { SDK_CALL_FUNC(void, 0x4C2400, void*, bool)(this, simulateRewards); }
		void TeleportVehicle(SceneSettings* settings) { SDK_CALL_FUNC(void, 0x4C2A80, void*, SceneSettings*)(this, settings); }
		void UnloadGraph() { SDK_CALL_FUNC(void, 0x4C3A10, void*)(this); }
		void Update(f32 realTimeDelta) { SDK_CALL_FUNC(void, 0x4C4360, void*, f32)(this, realTimeDelta); }
		f32 UpdateCompletionPercentage() { return SDK_CALL_FUNC(f32, 0x4C5D00, void*)(this); }
		void UpdateDependency() { SDK_CALL_FUNC(void, 0x4C6630, void*)(this); }
		void UpdateGameSlicesSnapshot() { SDK_CALL_FUNC(void, 0x4C7480, void*)(this); }
		void UpdatePermanentDLC() { SDK_CALL_FUNC(void, 0x4C7980, void*)(this); }
		void UpdateSnapshot() { SDK_CALL_FUNC(void, 0x4C8470, void*)(this); }
		bool UpdateTimeShift(f32 realTimeDelta) { return SDK_CALL_FUNC(bool, 0x4C8A60, void*, f32)(this, realTimeDelta); }
		void VendorExtortionHack() { SDK_CALL_FUNC(void, 0x4C8F60, void*)(this); }
		void WaitForStreamer() { SDK_CALL_FUNC(void, 0x4C8FE0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(ProgressionTracker, 0x1A08);
}