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


	class CPedSpawningInfo : public CSimComponent
	{
	public:
		qNode<CPedSpawningInfo> mNode;
		qNode<CPedSpawningInfo> mNode1;
		qNode<CPedSpawningInfo> mNode2;
		CSimObject* mProxySimObjectPtr;
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

		RebindingComponentHandle<CCharacterOccupantComponent> mCharacterOccupantComponent;
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

		void Reset(bool m_PreserveProxies = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x415820))(this, m_PreserveProxies);
		}

		void Unregister()
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

		void ReInitAmbient()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x413F20))(this);
		}

		CPedSpawningInfo* FindPedInfo(CSimObject* m_SimObject)
		{
			return reinterpret_cast<CPedSpawningInfo*(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x40B4E0))(this, m_SimObject);
		}

		static bool* AmbientSpawningEnable() { return reinterpret_cast<bool*>(UFG_RVA(0x207AE69)); }
		static bool* AmbientStatusCheckEnable() { return reinterpret_cast<bool*>(UFG_RVA(0x207AE6A)); }
		static bool* ScriptedStatusCheckEnable() { return reinterpret_cast<bool*>(UFG_RVA(0x207AE6B)); }
		static int* CheckStatusMode() { return reinterpret_cast<int*>(UFG_RVA(0x207AE6C)); }
		static bool* ResourcesSuspended() { return reinterpret_cast<bool*>(UFG_RVA(0x23DE286)); }
	};

	namespace PedSpawnManager
	{
		CPedSpawnManager* Get()
		{
			return *reinterpret_cast<CPedSpawnManager**>(UFG_RVA(0x23DC610));
		}

		CPedSpawningInfo* GetLastRegisterPedInfo()
		{
			return *reinterpret_cast<CPedSpawningInfo**>(UFG_RVA(0x23DE338));
		}
	}
}