#pragma once

namespace UFG
{
	class UIHKObjectiveFlasherWidget
	{
	public:
		enum eState
		{
			STATE_IDLE,
			STATE_SHOULD_SHOW,
			STATE_ACTIVE,
			STATE_SHOULD_HIDE,
			STATE_OUTRO,
			NUM_STATES
		};

		bool mOldVisible;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x2430FC5> mVisible;
		SDK_VINLINE qGlobalVar<bool, 0x2430FC7> mUsesPDA;
		SDK_VINLINE qGlobalVar<bool, 0x2430FD1> mPDAStateChanged;
		SDK_VINLINE qGlobalVar<eState, 0x2430FE4> mState;
		SDK_VINLINE qGlobalVar<qString, 0x24310F0> mCaption;
		SDK_VINLINE qGlobalVar<qString, 0x2433018> mObjectiveType;
		SDK_VINLINE qGlobalVar<qColour, 0x2433400> mColour;

		/* Static Functions */

		SDK_SINLINE void Clear() { SDK_CALL_FUNC(void, 0x5D5270)(); }
		SDK_SINLINE void Show(const char* caption, const char* objectiveType, bool usesPDA) { SDK_CALL_FUNC(void, 0x60D180, const char*, const char*, bool)(caption, objectiveType, usesPDA); }

		/* Functions */

		bool CanShowPDAReminder() { return SDK_CALL_FUNC(bool, 0x5D4860, void*)(this); }
		void Flash_Hide(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DB9A0, void*, UIScreen*)(this, screen); }
		void Flash_HideSmartphone(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DBE80, void*, UIScreen*)(this, screen); }
		void Flash_SetColor(UIScreen* screen, const qColour& color) { SDK_CALL_FUNC(void, 0x5DFD00, void*, UIScreen*, const qColour&)(this, screen, color); }

		void Flash_Show(UIScreen* screen, const char* caption, const char* objectiveType) {
			SDK_CALL_FUNC(void, 0x5E3410, void*, UIScreen*, const char*, const char*)(this, screen, caption, objectiveType);
		}

		void Flash_ShowSmartphone(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E4D10, void*, UIScreen*)(this, screen); }
		bool HandleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) { return SDK_CALL_FUNC(bool, 0x5EADE0, void*, UIScreen*, u32, UIMessage*)(this, screen, msgId, msg); }
	};
}