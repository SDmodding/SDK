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

	class CCopSystem
	{
	public:
		UFG_PAD(0xC90); // UFG::EncounterBase

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

		void SetHeatLevel(eHeatLevelEnum heatLevel, eHeatEventEnum heatEvent, float heatValue)
		{
			reinterpret_cast<void(__fastcall*)(void*, eHeatLevelEnum, eHeatEventEnum, float)>(UFG_RVA(0x3F0550))(this, heatLevel, heatEvent, heatValue);
		}
	};
	CCopSystem* CopSystem = reinterpret_cast<CCopSystem*>(UFG_RVA(0x23D9AA0));
}