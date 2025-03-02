#pragma once

namespace UFG
{
	class UIHKTutorialOverlay
	{
	public:
		enum eState
		{
			STATE_IDLE,
			STATE_OPENING_TUTORIAL,
			STATE_DISPLAYING_TUTORIAL,
			STATE_HIDING_TUTORIAL,
			STATE_WAITING_FOR_OUTRO
		};

		eState m_eState;
		bool m_bShowMsg;
		qString m_TitleTxt;
		qString m_BodyTxt;

		/* Virtual Functions */

		virtual ~UIHKTutorialOverlay() = 0;
		virtual bool handleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;
		virtual void update(UIScreen* screen, f32 elapsed) = 0;

		/* Functions */

		void hide() { SDK_CALL_FUNC(void, 0x62FC30, void*)(this); }
		void show(const char* titleTxt, const char* bodyTxt) { SDK_CALL_FUNC(void, 0x63B200, void*, const char*, const char*)(this, titleTxt, bodyTxt); }
	};
}