#pragma once

namespace UFG
{
	class PopUpMessage : public qNode<PopUpMessage>
	{
	public:
		qString m_sTitle;
		qString m_sBody;
	};

	class UIHKPopUpNotifier
	{
	public:
		enum eState
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

		eState m_eState;
		qList<PopUpMessage> m_MessageQueue;
		u32 m_iNumMessages;
		f32 m_fElapsedTime;

		/* Virtual Functions */

		virtual ~UIHKPopUpNotifier() = 0;
		virtual bool handleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) = 0;
		virtual void update(UIScreen* screen, f32 elapsed) = 0;
	};
}