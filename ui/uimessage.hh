#pragma once

namespace UFG
{
	class UICommandData
	{
	public:
		virtual ~UICommandData() = 0;
	};

	class UICommand : public qNode<UICommand>
	{
	public:
		enum UICommandType : i32
		{
			UICOMMAND_SCREEN_PUSH,
			UICOMMAND_SCREEN_POP,
			UICOMMAND_SCREEEN_SWITCH,
			UICOMMAND_OVERLAY_PUSH,
			UICOMMAND_OVERLAY_POP,
			UICOMMAND_MESSAGE,
			UICOMMAND_INPUT,
			UICOMMAND_FLASH_COMMAND,
			UICOMMAND_NUM,
			UICOMMAND_UNKNOWN = -1
		};

		UICommandType m_commandType;
		UICommandData* m_commandData;
	};

	class UIMessage : public UICommand
	{
	public:
		enum UIMessageType : i32
		{
			UIMESSAGE_PAD_INPUT,
			UIMESSAGE_PAD_INPUT_ANALOG_STICK,
			UIMESSAGE_KEYBOARD_INPUT,
			UIMESSAGE_MOUSE_INPUT,
			UIMESSAGE_FLASH,
			UIMESSAGE_NUM,
			UIMESSAGE_UNKNOWN = -1,
		};

		u32 m_messageId;
		u32 m_resultId;
		u32 m_receiverUID;
		UIMessageType m_messageType;
	};

}