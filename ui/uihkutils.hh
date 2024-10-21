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

		SDK_SINLINE void FormatMoneyStr(int money, qString& string) { reinterpret_cast<void(SDK_CALL*)(int, qString&)>(SDK_RVA(0x5E6640))(money, string); }

		SDK_SINLINE eButtons GetButton(const char* text) { return reinterpret_cast<eButtons(SDK_CALL*)(const char*)>(SDK_RVA(0x5E6DC0))(text); }

		SDK_SINLINE qPropertySet* GetDLCPropertyNode(const char* rootName, const char* listName) { 
			return reinterpret_cast<qPropertySet*(SDK_CALL*)(const char*, const char*)>(SDK_RVA(0x5E7480))(rootName, listName); 
		}

		SDK_SINLINE qPropertySet* GetDLCPropertyNode(const char* rootName, const char* listName, const char* nodeName, const qSymbol& nodeCompare) { 
			return reinterpret_cast<qPropertySet*(SDK_CALL*)(const char*, const char*, const char*, const qSymbol&)>(SDK_RVA(0x5E7340))(rootName, listName, nodeName, nodeCompare); 
		}

		SDK_SINLINE qString GetDateString(u64 systemTime, bool includeSeconds) { return reinterpret_cast<qString(SDK_CALL*)(u64, bool)>(SDK_RVA(0x5E7550))(systemTime, includeSeconds); }

		SDK_SINLINE char* GetGamepadButtonTextureName(eButtons button, bool remappable) { return reinterpret_cast<char*(SDK_CALL*)(eButtons, bool)>(SDK_RVA(0x5E79A0))(button, remappable); }

		SDK_SINLINE char* GetKeyboardButtonTextureNameNonRemappable(eButtons button) { return reinterpret_cast<char*(SDK_CALL*)(eButtons)>(SDK_RVA(0x5E80C0))(button); }

		SDK_SINLINE char* GetPlayerDisplayName() { return reinterpret_cast<char*(SDK_CALL*)()>(SDK_RVA(0x5E8980))(); }

		SDK_SINLINE bool GetPlayerWorldPosition(qVector3* pos, qVector3* dir) { return reinterpret_cast<bool(SDK_CALL*)(qVector3*, qVector3*)>(SDK_RVA(0x5E89E0))(pos, dir); }

		SDK_SINLINE void HandleGameCheckpointRestore() { reinterpret_cast<void(SDK_CALL*)()>(SDK_RVA(0x5EB870))(); }

		SDK_SINLINE bool InGameIntroChapter() { return reinterpret_cast<bool(SDK_CALL*)()>(SDK_RVA(0x5ED4C0))(); }

		SDK_SINLINE bool InMinigame() { return reinterpret_cast<bool(SDK_CALL*)()>(SDK_RVA(0x5ED510))(); }

		SDK_SINLINE void InitHDSettings() { reinterpret_cast<void(SDK_CALL*)()>(SDK_RVA(0x5ED5D0))(); }

		SDK_SINLINE bool IsGamePaused() { return reinterpret_cast<bool(SDK_CALL*)()>(SDK_RVA(0x5EE1B0))(); }

		SDK_SINLINE bool IsInHDMode() { return *reinterpret_cast<bool*>(SDK_RVA(0x208E691)); }

		SDK_SINLINE bool IsMissionActive(bool includeEvents) { return reinterpret_cast<bool(SDK_CALL*)(bool)>(SDK_RVA(0x5EE420))(includeEvents); }

		SDK_SINLINE bool IsMissionWithCheckpointsActive(bool includeEvents) { return reinterpret_cast<bool(SDK_CALL*)(bool)>(SDK_RVA(0x5EE490))(includeEvents); }

		SDK_SINLINE bool IsPlayerInCombat() { return reinterpret_cast<bool(SDK_CALL*)()>(SDK_RVA(0x5EE680))(); }

		SDK_SINLINE bool IsPlayerInVehicle() { return reinterpret_cast<bool(SDK_CALL*)()>(SDK_RVA(0x5EE690))(); }

		SDK_SINLINE bool IsPlayerInWater() { return reinterpret_cast<bool(SDK_CALL*)()>(SDK_RVA(0x5EE720))(); }

		SDK_SINLINE bool IsPlayerVehiclePassenger() { return reinterpret_cast<bool(SDK_CALL*)()>(SDK_RVA(0x5EE730))(); }

		SDK_SINLINE const char* LocalizeText(const char* tag) { return reinterpret_cast<const char* (SDK_CALL*)(const char*)>(SDK_RVA(0x5F1C00))(tag); }

		SDK_SINLINE void LockGameplayInput() { reinterpret_cast<void(SDK_CALL*)()>(SDK_RVA(0x5F1CC0))(); }

		SDK_SINLINE void UnlockGameplayInput() { reinterpret_cast<void(SDK_CALL*)()>(SDK_RVA(0x613270))(); }

		SDK_SINLINE void ResetGameplayInput() { reinterpret_cast<void(SDK_CALL*)()>(SDK_RVA(0x6028C0))(); }

		SDK_SINLINE void ResetInputCounterHack(u32 counter) { reinterpret_cast<void(SDK_CALL*)(u32)>(SDK_RVA(0x602930))(counter); }

		SDK_SINLINE bool PauseGame(const char* pauseScreen) { return reinterpret_cast<bool(SDK_CALL*)(const char*)>(SDK_RVA(0x5F3910))(pauseScreen); }

		SDK_SINLINE void UnpauseGame() { reinterpret_cast<void(SDK_CALL*)()>(SDK_RVA(0x6132A0))(); }

		SDK_SINLINE void StartPauseVFX(u32 hashID) { reinterpret_cast<void(SDK_CALL*)(u32)>(SDK_RVA(0x612150))(hashID); }

		SDK_SINLINE void StopPauseVFX(bool fade) { reinterpret_cast<void(SDK_CALL*)(bool)>(SDK_RVA(0x612670))(fade); }

		SDK_SINLINE void QuitGame(const char* frontEndScreen) { reinterpret_cast<void(SDK_CALL*)(const char*)>(SDK_RVA(0x5FF020))(frontEndScreen); }
	};
}