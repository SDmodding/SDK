#pragma once

namespace UFG
{
	class CUICommandData
	{
	public:
		void* vfptr;
	};

	class CUICommand
	{
	public:
		enum eUICommandType : int
		{
			UICOMMAND_UNKNOWN = -1,
			UICOMMAND_SCREEN_PUSH,
			UICOMMAND_SCREEN_POP,
			UICOMMAND_SCREEEN_SWITCH,
			UICOMMAND_OVERLAY_PUSH,
			UICOMMAND_OVERLAY_POP,
			UICOMMAND_MESSAGE,
			UICOMMAND_INPUT,
			UICOMMAND_FLASH_COMMAND,
			UICOMMAND_NUM,
		};

		void* vfptr;
		qNode<CUICommand> mNode;
		eUICommandType m_commandType;
		CUICommandData* m_commandData;
	};

	class CUIMessage : public CUICommand
	{
	public:
		enum eUIMessageType : int
		{
			UIMESSAGE_UNKNOWN = -1,
			UIMESSAGE_PAD_INPUT,
			UIMESSAGE_PAD_INPUT_ANALOG_STICK,
			UIMESSAGE_KEYBOARD_INPUT,
			UIMESSAGE_MOUSE_INPUT,
			UIMESSAGE_FLASH,
			UIMESSAGE_NUM,
		};

		uint32_t m_messageId;
		uint32_t m_resultId;
		uint32_t m_receiverUID;
		eUIMessageType m_messageType;

		__inline const char* GetMessageResult()
		{
			return *reinterpret_cast<const char**>(reinterpret_cast<uintptr_t>(this) + 0x50);
		}
	};
}