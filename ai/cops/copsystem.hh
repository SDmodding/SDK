#pragma once

namespace UFG
{
	enum eHeatEventEnum : s32
	{
		eHEATEVENT_NONE,
		eHEATEVENT_INTIMIDATION,
		eHEATEVENT_ASSAULT_MELEE_PEDESTRIAN,
		eHEATEVENT_ASSAULT_MELEE_COP,
		eHEATEVENT_ASSAULT_WEAPON_PEDESTRIAN,
		eHEATEVENT_ASSAULT_WEAPON_COP,
		eHEATEVENT_MANSLAUGHTER_PEDESTRIAN,
		eHEATEVENT_MANSLAUGHTER_COP,
		eHEATEVENT_GANG_FIGHT,
		eHEATEVENT_WAVE_WEAPON,
		eHEATEVENT_FIRE_WEAPON,
		eHEATEVENT_WRECKLESS_DRIVING,
		eHEATEVENT_ASSAULT_VEHICLE_PEDESTRIAN,
		eHEATEVENT_ASSAULT_VEHICLE_COP,
		eHEATEVENT_MANSLAUGHTER_VEHICLE_PEDESTRIAN,
		eHEATEVENT_MANSLAUGHTER_VEHICLE_COP,
		eHEATEVENT_VEHICLE_HIJACK,
		eHEATEVENT_GRAPPLE_OTHER,
		eHEATEVENT_GRAPPLE_COP,
		eHEATEVENT_VEHICLE_COLLISION_OTHER,
		eHEATEVENT_VEHICLE_COLLISION_COP,
		eHEATEVENT_VEHICLE_TIRE_HIT_OTHER,
		eHEATEVENT_VEHICLE_TIRE_HIT_COP,
		eHEATEVENT_KIDNAP,
		eHEATEVENT_EXPLOSION,
		eHEATEVENT_RESIST_ARRES,
		NUM_HEATEVENTS,
	};

	class CopHeatEvent
	{
	public:
		f32 mTimestamp;
		bool mTracked;
		eHeatEventEnum mHeatEventIndex;
	};

	class CopSystem : public EncounterBase
	{
	public:
		enum eFinishReason : s32
		{
			eFinishReason_Unknown,
			eFinishReason_Arrested,
			eFinishReason_Death,
			eFinishReason_Escaped,
			eFinishReason_Script,
			NUM_FINISH_REASONS
		};

		struct Stats
		{
			eFinishReason mFinishReason;
			int mLastLevelSpawnCount;
			int mLastLevelKillCount;
		};


		bool mReloadTuningFiles;
		int mDebugDrawLevel;
		bool mShowCops;
		bool mShowStimulus;
		bool mShowResources;
		Stats mStats;
		int mNumArrestAttempts;
		bool mAreRoadBlocksActive;
		f32 mRoadBlockCooldownTimestamp;
		qVector3 mRoadBlockTriggerOrigin;
		f32 mAudioTimer;
		f32 mAudioScannerDelay;
		f32 mAudioPursuitDelay;
		OneShotHandle mDistantSirens;
		RateLimitedFloatNoMinMax mAudioHeatLevel;
		qPropertySet* mCopAudioConfig;
		bool mStimulusWatchList[116];
		char mStimulusCount[116];
		CopHeatEvent mHeatEvents[26];
		qSafePointer<SimObject, SimObject> mpAmbientSuspect;
		qSafePointer<SimObject, SimObject> mpArrestRightHumanCop;
		f32 mArrestRightTimestamp;
		qString mLastHeatEventCaption;
		eHeatEventEnum mLastHeatEventIndex;
		f32 mLastHeatEventTimer;
		f32 mOnFootNoSprintTimer;
		bool mIsExcludingPlayerForRestOfChase;
		bool mIsAmbientUnitsAllowed;
		bool mIsSafehouseInstantCooldownActive;
		u64 mHeatLevelTimestamp;

		SDK_SINLINE CopSystem* Instance() { return reinterpret_cast<CopSystem*>(SDK_RVA(0x23D9AA0)); }

		/* Functions */

		void ShutdownAudio() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x3F0720))(this); }

		void SetMaxHeatLevel(int maxHeatLevel) { reinterpret_cast<void(SDK_CALL*)(void*, int)>(SDK_RVA(0x3F05E0))(this, maxHeatLevel); }

		void SetHeatLevel(HeatLevelEnum heatLevel, eHeatEventEnum heatEvent) { 
			reinterpret_cast<void(SDK_CALL*)(void*, HeatLevelEnum, eHeatEventEnum)>(SDK_RVA(0x3F0550))(this, heatLevel, heatEvent); 
		}

		void ResetChaseStats() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x3F03C0))(this); }

		void ReportInfractionTarget(SimObject* pWitness, SimObject* pSuspect) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*, SimObject*)>(SDK_RVA(0x3F02E0))(this, pWitness, pSuspect); }

		void Replenish() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x3F02D0))(this); }

		void RemoveAllUnitsOnScene(bool includeNonManaged) { reinterpret_cast<void(SDK_CALL*)(void*, bool)>(SDK_RVA(0x3F0170))(this, includeNonManaged); }

		void ReleaseArrestRight(SimObject* pCop) { reinterpret_cast<void(SDK_CALL*)(void*, SimObject*)>(SDK_RVA(0x3F0120))(this, pCop); }

		bool IsActive() { return mHeatLevel != HEATLEVEL_NONE; }

		float GetHeatThresholdByLevel(int heatLevel) { return reinterpret_cast<float(SDK_CALL*)(void*, int)>(SDK_RVA(0x3EDA60))(this, heatLevel); }

		float GetHeatRadius(bool isOnfoot, EncounterUnitComponent* pEncounterUnitComponent = 0) { 
			return reinterpret_cast<float(SDK_CALL*)(void*, bool, EncounterUnitComponent*)>(SDK_RVA(0x3ED930))(this, isOnfoot, pEncounterUnitComponent); 
		}

		float GetHeatLevelPercentage() { return reinterpret_cast<float(SDK_CALL*)(void*)>(SDK_RVA(0x3ED860))(this); }

		const char* GetHeatEventName(eHeatEventEnum heatEvent) { return reinterpret_cast<const char*(SDK_CALL*)(void*, eHeatEventEnum)>(SDK_RVA(0x3ED850))(this, heatEvent); }

		float GetCurrentHeatLevelElapsedTime() { return reinterpret_cast<float(SDK_CALL*)(void*)>(SDK_RVA(0x3ED690))(this); }

		void GenerateHeatEvent(eHeatEventEnum heatEvent) { reinterpret_cast<void(SDK_CALL*)(void*, eHeatEventEnum)>(SDK_RVA(0x3ED420))(this, heatEvent); }

		void ReIncludePlayerForRestOfChase() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x3EF990))(this); }

		void ExcludePlayerForRestOfChase() { reinterpret_cast<void(SDK_CALL*)(void*)>(SDK_RVA(0x3ED000))(this); }

		void EnableAmbientUnits(bool enable) { reinterpret_cast<void(SDK_CALL*)(void*, bool)>(SDK_RVA(0x3ECF90))(this, enable); }

		void Enable(bool enable) { reinterpret_cast<void(SDK_CALL*)(void*, bool)>(SDK_RVA(0x3ECEE0))(this, enable); }
	};
	SDK_ASSERT_SIZEOF(CopSystem, 0xF88);
}