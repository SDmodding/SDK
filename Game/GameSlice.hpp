#pragma once

namespace UFG
{
	namespace GameSlice
	{
		enum State
		{
			STATE_LOCKED = 0x0,
			STATE_UNLOCKED = 0x1,
			STATE_RESTORING = 0x2,
			STATE_STARTED = 0x4,
			STATE_COMPLETED = 0x8,
			STATE_STARTEDorCOMPLETED = 0xC,
		};

		enum CleanupState
		{
			CLEANUP_NONE = 0x0,
			CLEANUP_SCRIPT_PENDING = 0x1,
			CLEANUP_SCRIPT_CLEANUP = 0x2,
			CLEANUP_LAYER_PENDING = 0x3,
			CLEANUP_LAYER_CLEANUP = 0x4,
		};

		enum CompletionStatus
		{
			STATUS_DISABLE = 0x0,
			STATUS_ENABLE = 0x1,
		};
	}

	class CGameSlice : public qBaseNodeRB
	{
	public:
		qSharedString mName;
		qSharedString mTitle;
		qSharedString mScriptClassName;
		void* mPDATriggerParameters;
		qSharedString mNisPath;
		void* mNisSceneSettings;
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
		float mVehicleMarkerRange;
		qSymbol mCancelLocationMarker;
		qSymbol mCompleteLocationMarker;
		int mMinimumDependentsRequired;
		int mMaxHeatLevel;
		int mMinPipLevel;
		int mFaceActionType;
		bool mAutosave;
		bool mAllowUICancellation;
		qVector3 mLocation;
		unsigned int mRepeatableInterval;
		__int64 mScriptBinaryFileSize;
		void* mScript;
		CGameSlice* mExclusiveChild;
		GameSlice::State mState;
		unsigned int mType;
		GameSlice::CompletionStatus mCompletionStatus;
		unsigned __int64 mCompletionStatusTimestamp;
		bool mIsTODRestricted;
		float mTODActive;
		float mTODInactive;
		float mTODRestore;
		bool mTODBypassPrompt;
		bool mPerformTimeShift;
		bool mVehicleSuperStop;
		bool mKeepTriggerObjectiveEnabled;
		bool mDisableCopScoring;
		bool mDisableTriadScoring;
		unsigned __int64 mFailTimeout;
		char mEnabled;
		char mRoot;
		char mDirty;
		char mOptional;
		char mExclusive;
		char mPersistent;
		char mRequiresSave;
		char mRandomExclusive;
		char mHoldCurtain;
		char mHoldStreamer;
		char mCheckpointSlice;
		char mInternalSlice;
		char mWaitingForTrigger;
		char mLayerEnabledByMe;
		char mIgnoreSafehouseRestore;
		char mDeferStartIfInsideRegion;
		char mDeferRestartIfInsideRegion;
		char mCountedStats;
		char mStreamRequested;
		char mTrackType;
		char mStatsId;
		qSymbol mDLCProductId;
		void* mSceneSettings;
		GameSlice::CleanupState mCleanupPending;
		__int16 mCompletionCount;
		__int16 mCleanupCount;
		CGameSlice* mpParent;
		qSetBase<CGameSlice> mDependents;
		qSetBase<CGameSlice> mChildren;
		CPropertySetHandle mRewardsProperties;
		CPropertySetHandle mRepeatedRewardsProperties;
		CGameSlice* mpDependentMission;
		CGameSlice* mpLastActiveSublice;
		void* maMasks[2];
		void* mpCollection;
		bool mCollectionHighPriority;
		bool mIsSingleCharacterSprinkle;
		qSymbol mSprinkleCharacter1Override;
		qSymbol mSprinkleCharacter2Override;
		qSymbol mSubsetModeType;

		void ForceLock(bool isReset)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x4A1050))(this, isReset);
		}

		void SetState(GameSlice::State newState)
		{
			reinterpret_cast<void(__fastcall*)(void*, GameSlice::State)>(UFG_RVA(0x4BD6F0))(this, newState);
		}

		void Start()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x4BEF50))(this);
		}

		void StartScript()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x4BF760))(this);
		}
	};
}