#pragma once

namespace UFG
{
	enum eGameStateMode : s32
	{
		eGSM_NONE,
		eGSM_PAUSED,
		eGSM_DEBUG_CAM
	};

	class GameState
	{
	public:
		qString mGameStateName;
		const u32 mGameStateUID;
		u32 mGameStateUserDataInt;
		qString mGameStateUserDataStr;
		u32 mMode;
		bool mInitialPass;

		virtual ~GameState() = 0;
		virtual void OnPreUpdate(f32 deltaSeconds) = 0;
		virtual void OnPostUpdate(f32 fRealTimeDelta) = 0;
		virtual void OnEnter(f32 fRealTimeDelta) = 0;
		virtual void OnUpdate(f32 fRealTimeDelta) = 0;
		virtual void OnExit(f32 fRealTimeDelta) = 0;
		virtual bool CanSwitchFrom(u32 stateUID) = 0;
		virtual bool ModeIsSet(eGameStateMode mode) = 0;
		virtual bool ModeSet(eGameStateMode mode, bool enable) = 0;
		virtual void SetIsFading(bool) = 0; /* Unused */
	};
	SDK_ASSERT_SIZEOF(GameState, 0x68);
}