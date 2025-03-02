#pragma once

namespace UFG
{
	class UIHK_PDAIncomingTextWidget
	{
	public:
		enum eDismissCause
		{
			DISMISS_CAUSE_NONE,
			DISMISS_CAUSE_DEACTIVATE,
			DISMISS_CAUSE_SCRIPT,
			DISMISS_CAUSE_INPUT
		};

		enum eState
		{
			STATE_IDLE,
			STATE_WAIT_TO_PUSH_TXTMSG,
			STATE_INCOMING_TEXT,
			STATE_OUTGOING_TEXT,
			STATE_SHOWING_INCOMING_TEXT,
			STATE_SHOWING_OUTGOING_TEXT,
			NUM_STATES
		};

		eState mState;
		bool mMessageRead;
		bool mHelpbarShown;
		bool mIgnoreButtonOnce;
		eDismissCause mDismissCause;
		float mDisplayTime;
		UIHK_PDAInputLocker mInputLocker;

		/* Static Functions */

		SDK_SINLINE void DisplayHelpbar() { SDK_CALL_FUNC(void, 0x5D66B0)(); }

		/* Functions */

		void Activate(const char* textMessage, const char* contactName, bool outgoing, const char* contactImage) {
			SDK_CALL_FUNC(void, 0x5D14E0, void*, const char*, const char*, bool, const char*)(this, textMessage, contactName, outgoing, contactImage);
		}

		void DismissMessage(eDismissCause dismissCause) { SDK_CALL_FUNC(void, 0x5D6500, void*, eDismissCause)(this, dismissCause); }
		void DisplayMessage() { SDK_CALL_FUNC(void, 0x5D6730, void*)(this); }
		void HandleMessage(UIScreen* screen, u32 msgId) { SDK_CALL_FUNC(void, 0x5EB340, void*, UIScreen*, u32)(this, screen, msgId); }
	};
	SDK_ASSERT_SIZEOF(UIHK_PDAIncomingTextWidget, 0x40);
}