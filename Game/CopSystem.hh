#pragma once

namespace UFG
{
	class CCopHeatEvent
	{
	public:
		float mTimestamp;
		bool mTracked;
		eHeatEventEnum mHeatEventIndex;
	};

	class CCopSystem : public CEncounterBase
	{
	public:
		enum eCopSystemFinishReason
		{
			eCopSystemFinishReason_Unknown = 0x0,
			eCopSystemFinishReason_Arrested = 0x1,
			eCopSystemFinishReason_Death = 0x2,
			eCopSystemFinishReason_Escaped = 0x3,
			eCopSystemFinishReason_Script = 0x4,
			NUM_COP_SYSTEM_FINISH_REASONS = 0x5,
		};

		struct Stats_t
		{
			eCopSystemFinishReason mFinishReason;
			int mLastLevelSpawnCount;
			int mLastLevelKillCount;
		};

		bool mReloadTuningFiles;
		int mDebugDrawLevel;
		bool mShowCops;
		bool mShowStimulus;
		bool mShowResources;
		Stats_t mStats;
		int mNumArrestAttempts;
		bool mAreRoadBlocksActive;
		float mRoadBlockCooldownTimestamp;
		qVector3 mRoadBlockTriggerOrigin;
		float mAudioTimer;
		float mAudioScannerDelay;
		float mAudioPursuitDelay;
		void* mDistantSirens;
		float mAudioHeatLevel[4]; // m_currentValue, m_targetValue, m_riseRate, m_fallRate
		qPropertySet* mCopAudioConfig;
		bool mStimulusWatchList[116];
		char mStimulusCount[116];
		CCopHeatEvent mHeatEvents[26];
		qSafePointer<CSimObject> mpAmbientSuspect;
		qSafePointer<CSimObject> mpArrestRightHumanCop;
		float mArrestRightTimestamp;
		qString mLastHeatEventCaption;
		eHeatEventEnum mLastHeatEventIndex;
		float mLastHeatEventTimer;
		float mOnFootNoSprintTimer;
		bool mIsExcludingPlayerForRestOfChase;
		bool mIsAmbientUnitsAllowed;
		bool mIsSafehouseInstantCooldownActive;
		uint64_t mHeatLevelTimestamp;

		static UFG_INLINE CCopSystem* Instance()
		{
			return reinterpret_cast<CCopSystem*>(UFG_RVA(0x23D9AA0));
		}

		UFG_INLINE float GetHeatThresholdByLevel(eHeatLevelEnum p_HeatLevel)
		{
			return reinterpret_cast<float(__fastcall*)(void*, eHeatLevelEnum)>(UFG_RVA(0x3EDA60))(this, p_HeatLevel);
		}

		UFG_INLINE void ReportInfractionTarget(CSimObject* p_Witness, CSimObject* p_Suspect)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*, CSimObject*)>(UFG_RVA(0x3F02E0))(this, p_Witness, p_Suspect);
		}

		UFG_INLINE void SetHeatLevel(eHeatLevelEnum p_HeatLevel, eHeatEventEnum p_HeatEvent)
		{
			reinterpret_cast<void(__fastcall*)(void*, eHeatLevelEnum, eHeatEventEnum)>(UFG_RVA(0x3F0550))(this, p_HeatLevel, p_HeatEvent);
		}

		UFG_INLINE void ResetChaseStats()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x3F03C0))(this);
		}
	};
}