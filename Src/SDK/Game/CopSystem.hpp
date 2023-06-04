#pragma once

namespace UFG
{
	class CCopSystemStats
	{
	public:
		eCopSystemFinishReason mFinishReason;
		int mLastLevelSpawnCount;
		int mLastLevelKillCount;
	};

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
		bool mReloadTuningFiles;
		int mDebugDrawLevel;
		bool mShowCops;
		bool mShowStimulus;
		bool mShowResources;
		CCopSystemStats mStats;
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

		UFG_PAD(0x30);
		/*UFG::qSafePointer<UFG::SimObject, UFG::SimObject> mpAmbientSuspect;
		UFG::qSafePointer<UFG::SimObject, UFG::SimObject> mpArrestRightHumanCop;*/

		float mArrestRightTimestamp;
		qString mLastHeatEventCaption;
		eHeatEventEnum mLastHeatEventIndex;
		float mLastHeatEventTimer;
		float mOnFootNoSprintTimer;
		bool mIsExcludingPlayerForRestOfChase;
		bool mIsAmbientUnitsAllowed;
		bool mIsSafehouseInstantCooldownActive;
		unsigned __int64 mHeatLevelTimestamp;

		float GetHeatThresholdByLevel(eHeatLevelEnum m_HeatLevel)
		{
			return reinterpret_cast<float(__fastcall*)(void*, eHeatLevelEnum)>(UFG_RVA(0x3EDA60))(this, m_HeatLevel);
		}

		void ReportInfractionTarget(CSimObject* m_Witness, CSimObject* m_Suspect)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*, CSimObject*)>(UFG_RVA(0x3F02E0))(this, m_Witness, m_Suspect);
		}

		void SetHeatLevel(eHeatLevelEnum m_HeatLevel, eHeatEventEnum m_HeatEvent, float m_HeatValue)
		{
			reinterpret_cast<void(__fastcall*)(void*, eHeatLevelEnum, eHeatEventEnum, float)>(UFG_RVA(0x3F0550))(this, m_HeatLevel, m_HeatEvent, m_HeatValue);
		}
	};
	CCopSystem* CopSystem = reinterpret_cast<CCopSystem*>(UFG_RVA(0x23D9AA0));
}