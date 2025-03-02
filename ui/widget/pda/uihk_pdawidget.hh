#pragma once

namespace UFG
{
	enum ePDAStateEnum
	{
		STATE_IDLE,
		STATE_ROOT_MENU,
		STATE_PHONE_CONTACTS,
		STATE_TEXT_INBOX,
		STATE_INCOMING_CALL,
		STATE_OUTGOING_CALL,
		STATE_INCOMING_TEXT,
		STATE_DISPLAY_TEXT,
		STATE_OUTGOING_TEXT,
		STATE_PHOTO_CAMERA,
		STATE_READING_TEXT,
		STATE_WAIT_TO_WRITE_TEXT,
		STATE_WRITING_TEXT,
		NUM_PDA_STATES
	};

	class UIHK_PDAWidget
	{
	public:
		qProxy<UIHK_PDAPhoneContactsWidget> PhoneContacts;
		ePDAStateEnum mState;
		ePDAStateEnum mPrevState;
		Scaleform::GFx::Movie* mMovie;
		UIHK_PDARootMenuWidget RootMenu;
		UIHK_PDATextInboxWidget TextInbox;
		UIHK_PDAIncomingCallWidget IncomingCall;
		UIHK_PDAIncomingTextWidget IncomingText;
		UIHK_PDAClockWidget Clock;
		qPropertySet* mContactData;
		bool m_objectiveScrollingInProgress;
		f32 m_objectiveScrollingTimer;
		f32 m_R1_timer;
		f32 m_R3_timer;
		f32 mLeftStickTimer;
		f32 mRightStickTimer;
		bool mLeftStickActive;
		bool mRightStickActive;
		bool mGPSActivatedFlag;
		u32 mPDAOpenDelay;
		bool mTextMsgRead;
		bool mShouldHighlight;
		bool mPreLocked;
		u32 mRootIntro;
		qString mPhoneContact;
		bool mOutgoingCall;
		bool mAutoAnsCall;
		bool mVoiceMail;
		f32 mTime;

		/* Virtual Functions */

		virtual ~UIHK_PDAWidget() = 0;
		virtual void init(UIScreen* screen) = 0;
		virtual void update(UIScreen* screen, f32 elapsed) = 0;
		virtual bool handleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;

		/* Static Functions */

		SDK_SINLINE ePDAStateEnum GetState() { return SDK_CALL_FUNC(ePDAStateEnum, 0x5E9520)(); }
		SDK_SINLINE void Lock() { SDK_CALL_FUNC(void, 0x5F1C70)(); }
		SDK_SINLINE void Unlock() { SDK_CALL_FUNC(void, 0x613250)(); }

		/* Impl Functions */

		SDK_INLINE UIHK_PDAIncomingTextWidget::eDismissCause GetDismissCause() { return IncomingText.mDismissCause; }
		SDK_INLINE bool HasAnswered() { return IncomingCall.mState == UIHK_PDAIncomingCallWidget::STATE_CALL_ANSWERED; }
		SDK_INLINE bool HasReadTextMessage() { return IncomingText.mMessageRead; }
		SDK_INLINE bool IsIdle() { return mState == STATE_IDLE; }

		/* Functions */

		bool AnswerPhoneCall() { return SDK_CALL_FUNC(bool, 0x5D3B10, void*)(this); }
		void DeactivateAll() { SDK_CALL_FUNC(void, 0x5D6080, void*)(this); }

		bool DismissTextMessage(UIHK_PDAIncomingTextWidget::eDismissCause dismissCause) {
			return SDK_CALL_FUNC(bool, 0x5D6640, void*, UIHK_PDAIncomingTextWidget::eDismissCause)(this, dismissCause);
		}

		void DisplayObjective() { SDK_CALL_FUNC(void, 0x5D6A80, void*)(this); }
		void DisplayTextMessage() { SDK_CALL_FUNC(void, 0x5D6EB0, void*)(this); }
		bool EndPhoneCall(bool playSound) { return SDK_CALL_FUNC(bool, 0x5D7150, void*, bool)(this, playSound); }
		void Flash_UIHighlight_Init(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E5540, void*, UIScreen*)(this, screen); }
		void ForceIdle() { SDK_CALL_FUNC(void, 0x5E6510, void*)(this); }
		void HandleCustomInput(UIScreen* screen, u32 msgId) { SDK_CALL_FUNC(void, 0x5EA850, void*, UIScreen*, u32)(this, screen, msgId); }
		void ProcessCustomInput(UIScreen* screen, f32 elapsed) { SDK_CALL_FUNC(void, 0x5FE430, void*, UIScreen*, f32)(this, screen, elapsed); }

		bool QueueIncomingPhoneCall(const char* contactName, bool outgoing, bool autoCall, bool voiceMail) {
			return SDK_CALL_FUNC(bool, 0x5FE9C0, void*, const char*, bool, bool, bool)(this, contactName, outgoing, autoCall, voiceMail);
		}

		bool QueueIncomingTextMessage(const char* contactName, const char* message, const char* portrait, bool outgoing, bool autoAnswer) {
			return SDK_CALL_FUNC(bool, 0x5FEC40, void*, const char*, const char*, const char*, bool, bool)(this, contactName, message, portrait, outgoing, autoAnswer);
		}

		void ShowIncomingPhoneCall() { SDK_CALL_FUNC(void, 0x610890, void*)(this); }
		void ShowIncomingTextMessage() { SDK_CALL_FUNC(void, 0x610900, void*)(this); }
		bool StartReadingText() { return SDK_CALL_FUNC(bool, 0x612190, void*)(this); }
		bool StartWritingText() { return SDK_CALL_FUNC(bool, 0x6124A0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(UIHK_PDAWidget, 0x300);
}