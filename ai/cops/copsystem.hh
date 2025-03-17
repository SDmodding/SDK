#pragma once

namespace UFG
{
	enum eHeatEventEnum
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
		NUM_HEATEVENTS
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
		enum eFinishReason
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

		/* Static Functions */

		SDK_SINLINE CopSystem* Instance() { return SDK_VAR(CopSystem*, 0x23D9AA0); }

		/* Virtual Functions */

		virtual void EnableAmbientUnits(bool enable) = 0;
		virtual void OnRestore() = 0;
		virtual f32 GetHeatThresholdByLevel(int heatLevel) = 0;
		virtual void SetHeatLevel(HeatLevelEnum heatLevel, eHeatEventEnum heatEvent) = 0;
		virtual HeatLevelEnum _GetHeatLevel() = 0;
		virtual f32 GetHeatLevelPercentage() = 0;
		virtual int _GetNumArrestAttempts() = 0;
		virtual void HandleDestructionEvent(DestructionEvent* e) = 0;
		virtual void HandleGameStatEvent(Event* e) = 0;
		virtual void HandleArrest(SimObject* pSource, SimObject* pTarget) = 0;
		virtual void HandleDamageEvent(SimObject* pSource, SimObject* pTarget, HitRecord* pHitRecord, HealthComponent* pTargetHealthComponent, bool appliedDamage) = 0;
		virtual void HandleVehicleMeleeDamage(SimObject* pSource, SimObject* pTarget) = 0;
		virtual void HandleDryWeaponFire(SimObject* pSource) = 0;
		virtual void HandleFaceAction(SimObject* pSource, Stimulus* pStimulus) = 0;
		virtual void CommitHeatEvent(eHeatEventEnum heatEvent) = 0;
		virtual void SetMaxHeatLevel(int maxHeatLevel) = 0;
		virtual void _ClearMaxHeatLevel() = 0;
		virtual void ExcludePlayerForRestOfChase() = 0;
		virtual void ReIncludePlayerForRestOfChase() = 0;
		virtual bool AcquireArrestRight(SimObject* pCop) = 0;
		virtual void ReleaseArrestRight(SimObject* pCop) = 0;
		virtual eHeatEventEnum _GetLastHeatEventIndex() = 0;
		virtual const char* GetHeatEventName(eHeatEventEnum heatEvent) = 0;
		virtual eHeatEventEnum GetHeatEventEnum(const qString& heatEventName) = 0;
		virtual void ReportInfractionTarget(SimObject* pWitness, SimObject* pSuspect) = 0;
		virtual void GenerateHeatEvent(eHeatEventEnum heatEvent) = 0;
		virtual void UpdateHeatLevel() = 0;
		virtual bool IsAmbientUnitsAllowed() = 0;
		virtual void UpdateRoadBlocks() = 0;
		virtual void HandleHeatLevelChangeAudio(HeatLevelEnum oldHeatLevel, HeatLevelEnum newHeatLevel) = 0;
		virtual void UpdateAudio(f32 deltaTime) = 0;
		virtual void ShutdownAudio() = 0;
		virtual bool IsStimulusUpdateRequired() = 0;
		virtual f32 CalculateMultiplier(eHeatEventEnum heatEvent) = 0;
		virtual void ResetChaseStats() = 0;

		/* Impl Functions */

		SDK_INLINE HeatLevelEnum GetHeatLevel() { return mHeatLevel; }
		SDK_INLINE int GetNumArrestAttempts() { return mNumArrestAttempts; }
		SDK_INLINE void ClearMaxHeatLevel() { mMaxHeatLevel = -1; }
		SDK_INLINE eHeatEventEnum GetLastHeatEventIndex() { return mLastHeatEventIndex; }

		/* Functions */

		f32 GetCurrentHeatLevelElapsedTime() { return SDK_CALL_FUNC(f32, 0x3ED690, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(CopSystem, 0xF88);
}