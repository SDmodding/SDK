#pragma once

namespace UFG
{
	class AILightWeightComponent;
	class CullInfo;
	class CullResults;
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

	class PedSpawningInfo : public qProxy<SimComponent>, qNode<void**>, qNode<void*>, public qNode<PedSpawningInfo>
	{
	public:
		enum eActiveStatus : s32
		{
			Inactive,
			Active,
			ExtraLowPower,
			NormalSuspend,
			NetFull,
			NetProxy,
			eActiveStatus_Count,
		};

		enum eDrawList : s32
		{
			DrawList_None,
			DrawList_Draw,
			DrawList_NoDraw,
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
		PedSpawningInfo mAmbientPed[260];
		PedSpawningInfo mScriptedPed[120];
		ActiveSpawnSetInfo mActiveSpawnSets[40];
		int mPedSpawnHistoryIndex;
		u32 mNetRecycleCounter;

		SDK_SINLINE PedSpawnManager* Instance() { return SDK_VAR_GET(PedSpawnManager*, 0x23DC610); }

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x207AE69> msAmbientSpawningEnable;
		SDK_VINLINE qGlobalVar<bool, 0x207AE6A> msAmbientStatusCheckEnable;
		SDK_VINLINE qGlobalVar<bool, 0x207AE6B> msScriptedStatusCheckEnable;
		SDK_VINLINE qGlobalVar<bool, 0x207AE6C> msCheckStatusMode;
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

		/* Functions */

		PedSpawningInfo* FindPedInfoFromSimObject(SimObject* simObj) { return SDK_CALL_FUNC(PedSpawningInfo*, 0x40B4E0, void*, SimObject*)(this, simObj); }
		void ReInitAmbient() { SDK_CALL_FUNC(void, 0x413F20, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(PedSpawnManager, 0x4D018);
}