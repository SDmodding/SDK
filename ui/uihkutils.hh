#pragma once

namespace UFG
{
	class UI
	{
	public:
		enum eButtons : int
		{
			INVALID_BUTTON,
			ACCEPT_BUTTON,
			BACK_BUTTON ,
			BUTTON1_BUTTON,
			BUTTON2_BUTTON,
			START_BUTTON,
			SELECT_BUTTON,
			L1_BUTTON,
			R1_BUTTON,
			L2_BUTTON,
			R2_BUTTON,
			L3_BUTTON,
			R3_BUTTON,
			L1R1_BUTTON,
			L2R2_BUTTON,
			DPAD_UP_BUTTON,
			DPAD_DOWN_BUTTON,
			DPAD_LEFT_BUTTON,
			DPAD_RIGHT_BUTTON,
			DPAD_LR_BUTTON,
			DPAD_UD_BUTTON,
			L_STICK_BUTTON,
			R_STICK_BUTTON,
			L_STICK_LR_BUTTON,
			L_STICK_UD_BUTTON,
			R_STICK_LR_BUTTON,
			R_STICK_UD_BUTTON,
			ACCEPT_BUTTON_HOLD,
			BACK_BUTTON_HOLD,
			BUTTON1_BUTTON_HOLD,
			BUTTON2_BUTTON_HOLD,
			L1_BUTTON_HOLD,
			R1_BUTTON_HOLD,
			L2_BUTTON_HOLD,
			R2_BUTTON_HOLD,
			F1_BUTTON,
			WHEEL_UP_BUTTON,
			WHEEL_DOWN_BUTTON,
			NUM_BUTTONS
		};

		/* Static Functions */

		SDK_INLINE void FormatMoneyStr(int money, qString& string) { SDK_CALL_FUNC(void, 0x5E6640, int, qString&)(money, string); }

		SDK_INLINE eButtons GetButton(const char* text) { return SDK_CALL_FUNC(eButtons, 0x5E6DC0, const char*)(text); }

		SDK_INLINE qPropertySet* GetDLCPropertyNode(const char* rootName, const char* listName) { 
			return SDK_CALL_FUNC(qPropertySet*, 0x5E7480, const char*, const char*)(rootName, listName);
		}

		SDK_INLINE qPropertySet* GetDLCPropertyNode(const char* rootName, const char* listName, const char* nodeName, const qSymbol& nodeCompare) { 
			return SDK_CALL_FUNC(qPropertySet*, 0x5E7340, const char*, const char*, const char*, const qSymbol&)(rootName, listName, nodeName, nodeCompare);
		}

		SDK_INLINE qString GetDateString(u64 systemTime, bool includeSeconds) { return SDK_CALL_FUNC(qString, 0x5E7550, u64, bool)(systemTime, includeSeconds); }

		SDK_INLINE const char* GetGamepadButtonTextureName(eButtons button, bool remappable) { return SDK_CALL_FUNC(const char*, 0x5E79A0, eButtons, bool)(button, remappable); }

		SDK_INLINE const char* GetKeyboardButtonTextureNameNonRemappable(eButtons button) { return SDK_CALL_FUNC(const char*, 0x5E80C0, eButtons)(button); }

		SDK_INLINE const char* GetPlayerDisplayName() { return SDK_CALL_FUNC(const char*, 0x5E8980)(); }

		SDK_INLINE bool GetPlayerWorldPosition(qVector3& pos, qVector3& dir) { return SDK_CALL_FUNC(bool, 0x5E89E0, qVector3&, qVector3&)(pos, dir); }

		SDK_INLINE void HandleGameCheckpointRestore() { SDK_CALL_FUNC(void, 0x5EB870)(); }

		SDK_INLINE bool InGameIntroChapter() { return SDK_CALL_FUNC(bool, 0x5ED4C0)(); }

		SDK_INLINE bool InMinigame() { return SDK_CALL_FUNC(bool, 0x5ED510, )(); }

		SDK_INLINE void InitHDSettings() { SDK_CALL_FUNC(void, 0x5ED5D0)(); }

		SDK_INLINE bool IsGamePaused() { return SDK_CALL_FUNC(bool, 0x5EE1B0, )(); }

		SDK_INLINE bool IsInHDMode() { return SDK_CALL_FUNC(bool, 0x5EE290, )(); }

		SDK_INLINE bool IsMissionActive(bool includeEvents) { return SDK_CALL_FUNC(bool, 0x5EE420, bool)(includeEvents); }

		SDK_INLINE bool IsMissionWithCheckpointsActive(bool includeEvents) { return SDK_CALL_FUNC(bool, 0x5EE490, bool)(includeEvents); }

		SDK_INLINE bool IsPlayerInCombat() { return SDK_CALL_FUNC(bool, 0x5EE680)(); }

		SDK_INLINE bool IsPlayerInVehicle() { return SDK_CALL_FUNC(bool, 0x5EE690, )(); }

		SDK_INLINE bool IsPlayerInWater() { return SDK_CALL_FUNC(bool, 0x5EE720)(); }

		SDK_INLINE bool IsPlayerVehiclePassenger() { return SDK_CALL_FUNC(bool, 0x5EE730)(); }

		SDK_INLINE const char* LocalizeText(const char* tag) { return SDK_CALL_FUNC(const char*, 0x5F1C00, const char*)(tag); }

		SDK_INLINE void LockGameplayInput() { SDK_CALL_FUNC(void, 0x5F1CC0)(); }

		SDK_INLINE void UnlockGameplayInput() { SDK_CALL_FUNC(void, 0x613270)(); }

		SDK_INLINE void ResetGameplayInput() { SDK_CALL_FUNC(void, 0x6028C0)(); }

		SDK_INLINE void ResetInputCounterHack(UI* counter) { SDK_CALL_FUNC(void, 0x602930, UI*)(counter); }

		SDK_INLINE char PauseGame(const char* pauseScreen) { return SDK_CALL_FUNC(char, 0x5F3910, const char*)(pauseScreen); }

		SDK_INLINE void UnpauseGame() { SDK_CALL_FUNC(void, 0x6132A0)(); }

		SDK_INLINE void StartPauseVFX(u32 hashID) { SDK_CALL_FUNC(void, 0x612150, u32)(hashID); }

		SDK_INLINE void StopPauseVFX(bool fade) { SDK_CALL_FUNC(void, 0x612670, bool)(fade); }

		SDK_INLINE void QuitGame(const char* frontEndScreen) { SDK_CALL_FUNC(void, 0x5FF020, const char*)(frontEndScreen); }
	};
}