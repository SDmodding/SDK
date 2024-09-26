#pragma once

namespace UFG
{
	class CActiveSpawnSetInfo
	{
	public:
		qPropertySet* mpPropertySet;
		int mRefCount;
		int mPopulationPotential;
		float mPercentOfGlobalPopulation;
		bool mMediumPriorityOverride;
		qArray<qPropertySet*> mSpawnInfoArray;
		qArray<qPropertySet*> mRareSpawnInfoArray;
	};


	class CPedSpawningInfo : public SimComponent
	{
	public:
		qNode<CPedSpawningInfo> mNode;
		qNode<CPedSpawningInfo> mNode1;
		qNode<CPedSpawningInfo> mNode2;
		SimObject* mProxySimObjectPtr;
		CTransformNodeComponent* mProxyTransformNode;
		int mPedIndex;
		float mSuspendedTime;
		float mCulledTime;
		float mPrevCulledTime;
		qSafePointer<void*> mCreationSpawnZone;
		PedSpawningInfo::eActiveStatus mActiveStatus;
		PedSpawningInfo::eDrawList mDrawList;
		qSafePointerWithCallbacks<CSimCharacter> mSimObjectPtr;
		CTransformNodeComponent* mTransformNodePtr;
		void* mProxyAIComponent;
		void* mGroupComponent;
		void* mNetworkComponent;
		uint32_t mProxyOverDrawFrames;
		int mProxyModelHandleIndex;
		float mProxyTimeSinceLastAIUpdate;
		float mProxyTimeSinceLastFrameUpdate;
		float mProxyIndividualTimeScale;

		UFG_PAD_ALIGN(0x4);

		RebindingComponentHandle<CharacterOccupantComponent> mCharacterOccupantComponent;
		eActiveZoneClass mLocationClassification;
		bool mIsDead;

		UFG_PAD_ALIGN(0x3);

		qSymbol mLifetimeInstanceNameSymbol;

		UFG_PAD_ALIGN(0x4);

		UFG_PAD(0x118);
		//TrueCrowdSet::Instance mTrueCrowdSignature;

		qSymbol mRigNameSymbol;
		qSymbol mPropSetSymbol;
		qSymbol mArchetypePropSetSymbol;
		qSymbol mFactionSymbol;
		uint32_t mNumAttachedProps;
		qSymbol mAttachedPropNames[4];
		uint32_t mCanSuspendScripted;
		float mDumpResourcePriorityScore;
		qSafePointer<CSimComponent> mUpgradePOI; // UFG::InterestPoint
		int mLockActiveFrameCount;
		float mShouldCheckZoneInAreaTime;
		bool mIsNearDeactivatedZones;
		qVector3 mSuspendedPos;
		uint32_t mRestoreAttempts;
		uint32_t mBlipActive;
		eHowSpawned mHowSpawned;
		qVector3 mSpawnLocation;
		float mSpawnTime;
		bool mTeleportOnResumeRequired;
		bool mPhysicsLoadedForLocation;
		qVector3 mCurrentLocation;
		qVector3 mLocationInCameraSpace;
		float mDistInCameraSpace;
		float mBiasedDist;
		void* mCullInfo;
		void* mCullResults;
		ePedType mPedType;
		uint32_t mStatusChangedFrame;

		static UFG_INLINE CPedSpawningInfo* GetLastRegisterPedInfo()
		{
			return *reinterpret_cast<CPedSpawningInfo**>(UFG_RVA(0x23DE338));
		}

		UFG_INLINE float GetSpawnDelta()
		{
			return (CMetrics::Instance()->mSimTimeFloat - mSpawnTime);
		}

		UFG_INLINE bool CanDraw()
		{
			return (mCulledTime == 0.f && (mPrevCulledTime <= 0.f || mLocationClassification));
		}

		UFG_INLINE void Reset(bool p_bPreserveProxies = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x415820))(this, p_bPreserveProxies);
		}

		UFG_INLINE void Unregister()
		{
			mProxySimObjectPtr = nullptr;
			mSimObjectPtr.m_pPointer = nullptr;
			Reset();
		}
	};

	class CPedSpawnManager
	{
	public:
		void* vfptr;
		int mNumAmbientCurrentlyActive;
		int mNumAmbientCurrentlySuspended;
		int mTargetNumActive;
		float mUpdateDelta;
		float mTimeOfLastEnableCheck;
		int mNumberSpawnedSoFar;
		eHowSpawned mSpawningModeNow;
		float mLastTraversalTime;
		uint32_t mLastTraversalFrameCount;
		int mMode;
		CPedSpawningInfo mAmbientPed[260];
		CPedSpawningInfo mScriptedPed[120];
		CActiveSpawnSetInfo mActiveSpawnSets[40];
		int mPedSpawnHistoryIndex;
		uint32_t mNetRecycleCounter;

		static UFG_INLINE CPedSpawnManager* Instance()
		{
			return *reinterpret_cast<CPedSpawnManager**>(UFG_RVA(0x23DC610));
		}

		UFG_INLINE void ReInitAmbient()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x413F20))(this);
		}

		UFG_INLINE CPedSpawningInfo* FindPedInfo(SimObject* p_SimObject)
		{
			return reinterpret_cast<CPedSpawningInfo*(__fastcall*)(void*, SimObject*)>(UFG_RVA(0x40B4E0))(this, p_SimObject);
		}

		static UFG_INLINE bool* AmbientSpawningEnable() 
		{ 
			return reinterpret_cast<bool*>(UFG_RVA(0x207AE69));
		}

		static UFG_INLINE bool* AmbientStatusCheckEnable() 
		{
			return reinterpret_cast<bool*>(UFG_RVA(0x207AE6A)); 
		}

		static UFG_INLINE bool* ScriptedStatusCheckEnable() 
		{
			return reinterpret_cast<bool*>(UFG_RVA(0x207AE6B)); 
		}

		static UFG_INLINE int* CheckStatusMode() 
		{ 
			return reinterpret_cast<int*>(UFG_RVA(0x207AE6C));
		}

		static UFG_INLINE bool* ResourcesSuspended() 
		{ 
			return reinterpret_cast<bool*>(UFG_RVA(0x23DE286));
		}
	};

	/* DebugInfo
	*
	* PedSpawnManager Render (Green: Ambient | Red: Scripted): https://i.imgur.com/MBrjEPL.png
	*/
}