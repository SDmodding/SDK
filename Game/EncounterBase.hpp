#pragma once

namespace UFG
{
	class CEncounterBase;

	class CEncounterUnitContext
	{
	public:
		CSimObject* mpSimObject;
		CSimObject* mpVehicle;
		float mWaterContextTimer;
		bool mIsOnFootRaw;
		bool mIsInsideInterior;
		bool mIsInWater;
		bool mIsOnFootHeuristic;
		bool mIsOnMeshHeuristic;
		bool mOpenFired;
		bool mOpenFiredWithHostage;
	};

	class CEncounterUnitComponent : public CSimComponent
	{
	public:
		int mRole; // 0 - None | 1 - Enforcer | 2 - Supporter
		qSafePointerWithCallbacksBase<CEncounterBase> mpEncounter;
		UFG::qSymbol mWaveType;
		char mWaveTypeGroupIndex;
		char mUsageCount;
		bool mEngaged;
		bool mUnitDisabled;
		bool mEnableKillCount;
		float mInsideRadiusTimer;
		float mAcquiredTimer;
		float mVehicleFlipTimer;
		qSafePointer<CSimObject> mGroupVehicle;
		void* mpObjectiveIndicator;
		CEncounterUnitContext mContext;
	};

	class CEncounterBase : public qSafePointerNodeWithCallbacks<CEncounterBase>
	{
	public:
		bool mEnable;
		CPropertySetHandle mProperties;
		eAIObjective mObjective;
		eAIObjective mPostObjective;
		qSymbol mCurrentWaveType;
		int mReplenishStyle; // 0 - ByPopulation | 1 - ByWaveType
		qSymbol mHeatLevelPropertiesName[6];
		qSymbol mWaterHeatLevelPropertiesName[6];
		qPropertySet* mHeatLevelProperties[6];
		qPropertySet* mWaterHeatLevelProperties[6];
		bool mPreloadedResources[6];
		uint32_t mInsideDynamicRadiusCount;
		eHeatLevelEnum mHeatLevel;
		int mMaxHeatLevel;
		void* mpVehicleSpawnSensor;
		uint64_t mStartTimestamp;
		int mVehicleSpawnIteratingIndex;
		float mNonEventfulCooldownTimestamp;
		qVector3 mFocusTargetPosition;
		int mWaveCount;
		int mWavesDisabledUnitCount;
		float mWaveTimer;
		float mReplenishTimeout;
		float mSpawnTimeout;
		float mReducedRadiusTimer;
		float mReducedRadiusPercentage;
		bool mHasSpawnedInFrontForCurrentWave;
		bool mDisabledUnitForCurrentWave;
		bool mIsAvoidPeds;
		bool mIsAllowedToPass;
		bool mIsStaysOffSidewalk;
		bool mIsRespectSpeedLimit;
		bool mIsCanTurnAround;
		bool mSuppressVehicleSpawningByKillCount;
		bool mIsReplenishing;
		bool mInstantCooldownActive;
		bool mCoolingDown;
		bool mCooldownAllowed;
		bool mEnableWaveTimerChangesByDisabledUnits;
		CEncounterUnitContext mFocusTargetContext;
		UFG::qFixedArray<CEncounterUnitComponent*, 32> mHumans;
		UFG::qFixedArray<CEncounterUnitComponent*, 8> mVehicles;
		UFG::qFixedArray<void*, 20> mHumanSpawnRegions;
		int mWaveGroupTypes[10];
		int mWaveGroupInstancesRequired[10];
		int mWaveGroupInstances[10];
		unsigned int mNumWaveGroupTypes;
		int mNumDesiredVehicleGroups;
		int mNumDesiredCharacterGroups;
		int mVehicleSpawnCount;
		int mCharacterSpawnCount;
		int mVehicleKillCount;
		int mCharacterKillCount;

		UFG_PAD(0x850);
		//UFG::WayTraversalClient mWayTraversalClient;

		qSafePointer<CSimObject> mpFocusTarget;
		qSafePointer<CSimObject> mpSecondaryTarget;
		qSafePointer<void*> mpCombatRegion;

		CSimObject* GetFocusTarget()
		{
			return mpFocusTarget.m_pPointer;
		}

		void SetFocusTarget(CSimObject* m_SimObject)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x3F0500))(this, m_SimObject);
		}

		void SetCurrentWaveType(qSymbol m_WaveID)
		{
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x3F9350))(this, &m_WaveID);
		}

		void UpdateOnFootPopulation(CSimObject* m_Target, CTransformNodeComponent* m_TargetTransform)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*, CTransformNodeComponent*)>(UFG_RVA(0x3FA530))(this, m_Target, m_TargetTransform);
		}
	};
}