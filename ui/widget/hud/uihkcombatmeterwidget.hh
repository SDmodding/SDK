#pragma once

namespace UFG
{
	class UIHKCombatMeterWidget
	{
	public:
		enum eCombatActions
		{
			COMBAT_INVALID,
			COMBAT_INTIMIDATE,
			COMBAT_HEALTH_REGEN,
			COMBAT_GROUP_INTIMIDATE,
			COMBAT_BERSERK,
			COMBAT_MARKSMAN
		};

		enum eState
		{
			STATE_IDLE,
			STATE_PRE_INTRO,
			STATE_INTRO,
			STATE_ACTIVE,
			STATE_BUFF,
			STATE_OUTRO
		};

		eState mState;
		eState mSleepPrevState;
		f32 mChargedFacePercent;
		f32 mCombatMeterValue;
		qString mDebugFaceEventCaption;
		int mPipCount;
		bool mChanged;
		bool mCombatActive;
		eCombatActions mCombatAction;
		bool mPingCombatActionFlag;
		bool mShouldHighlight;
		f32 mBuffStartingMeter;
		f32 mBuffStartingDuration;
		bool mPreserveBuffStartingDuration;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x208E335> m_bScriptWantVisible;
		SDK_VINLINE qGlobalVar<bool, 0x2430D33> mEnabled;

		/* Static Functions */

		SDK_SINLINE UIHKCombatMeterWidget* Instance() { return SDK_VAR_GET(UIHKCombatMeterWidget*, 0x2430BC0); }

		/* Impl Functions */

		SDK_INLINE f32 GetCombatCharge() { return mChargedFacePercent * 5.f; }
		SDK_INLINE void PingCombatAction() { mPingCombatActionFlag = 1; }

		/* Functions */

		void Flash_UIHighlight_Init(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E52E0, void*, UIScreen*)(this, screen); }
		void Flash_Update(UIScreen* screen, f32 oldCombatValue, f32 combatMeterValue) { SDK_CALL_FUNC(void, 0x5E5670, void*, UIScreen*, f32, f32)(this, screen, oldCombatValue, combatMeterValue); }
		void PipsUsed(int numPips) { SDK_CALL_FUNC(void, 0x5F3AF0, void*, int)(this, numPips); }
		void SetCombatAction() { SDK_CALL_FUNC(void, 0x605640, void*)(this); }
		void SetCombatCharge(f32 charge) { SDK_CALL_FUNC(void, 0x6056C0, void*, f32)(this, charge); }
		void Update(UIScreen* screen) { SDK_CALL_FUNC(void, 0x613720, void*, UIScreen*)(this, screen); }
		void UpdatePipCount(f32 combatMeterValue) { SDK_CALL_FUNC(void, 0x61CDE0, void*, f32)(this, combatMeterValue); }
	};
}