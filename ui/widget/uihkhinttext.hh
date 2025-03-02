#pragma once

namespace UFG
{
	class UIHKHintText
	{
	public:
		enum eState
		{
			STATE_IDLE,
			STATE_SUPPRESSED,
			STATE_OPENING_HINT,
			STATE_DISPLAYING_HINT,
			STATE_HIDING_HINT,
			STATE_WAITING_FOR_OUTRO,
			STATE_WAITING_TO_REDISPLAY
		};

		eState m_eState;
		bool m_bShowMsg;
		u32 m_Suppress;
		qString m_sHintTxt;
		qString m_sOnlineDisconnectMessage;
		bool m_bUseTimer;
		f32 m_fDisplayTime;
		bool m_bRepeatMsg;
		f32 m_fRepeatTime;
		f32 m_fTimerDisplay;
		f32 m_fTimerRepeat;
		f32 m_fHintReminderTimeout;
		bool m_queueOnlineDisconnectMessage;
		bool m_isShowingOnlineDisconnect;

		/* Virtual Functions */

		virtual ~UIHKHintText() = 0;
		virtual void HandleScreenInit(UIScreen* screen) = 0;
		virtual bool HandleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;
		virtual void Update(UIScreen* screen, f32 elapsed) = 0;

		/* Static Functions */

		SDK_SINLINE UIHKHintText* Instance() { return SDK_VAR_GET(UIHKHintText*, 0x2430C40); }

		/* Functions */

		void hide() { SDK_CALL_FUNC(void, 0x62FBF0, void*)(this); }
		void show(const char* text, f32 displayTime, bool repeat, f32 repeatTime) { SDK_CALL_FUNC(void, 0x63AFD0, void*, const char*, f32, bool, f32)(this, text, displayTime, repeat, repeatTime); }
		void unsuppress() { SDK_CALL_FUNC(void, 0x63B8C0, void*)(this); }
	};
}