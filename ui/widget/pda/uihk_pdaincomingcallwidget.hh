#pragma once

namespace UFG
{
	class UIHK_PDAIncomingCallWidget
	{
	public:
		enum eState
		{
			STATE_IDLE,
			STATE_WAIT_FOR_SUCCESS_PHONE,
			STATE_INCOMING_CALL,
			STATE_OUTGOING_CALL,
			STATE_CALL_ANSWERED,
			STATE_DISCONNECTED,
			NUM_STATES
		};

		eState mState;
		f32 mTimer;
		int mOldSeconds;
		bool mUpdateTimer;
		qString mCallerName;
		qString mCallerPortrait;
		bool mVoiceMail;
		UIHK_PDAInputLocker mInputLocker;

		/* Functions */

		void Activate(const char* callerName, const char* portrait, bool outgoing, bool voiceMail) {
			SDK_CALL_FUNC(void, 0x5D1260, void*, const char*, const char*, bool, bool)(this, callerName, portrait, outgoing, voiceMail);
		}

		void Answer() { SDK_CALL_FUNC(void, 0x5D3810, void*)(this); }
		void HangUp(bool playSound) { SDK_CALL_FUNC(void, 0x5EC890, void*, bool)(this, playSound); }
		void ReleaseInputLock(const char* trace) { SDK_CALL_FUNC(void, 0x600BD0, void*, const char*)(this, trace); }
		void SetCallerName(const char* callerName, const char* portrait, bool voiceMail) { SDK_CALL_FUNC(void, 0x605570, void*, const char*, const char*, bool)(this, callerName, portrait, voiceMail); }
	};
	SDK_ASSERT_SIZEOF(UIHK_PDAIncomingCallWidget, 0x98);
}