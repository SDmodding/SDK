#pragma once

namespace UFG
{
	enum UIButtons : unsigned int
	{
		INVALID_BUTTON = 0x0,
		ACCEPT_BUTTON = 0x1,
		BACK_BUTTON = 0x2,
		BUTTON1_BUTTON = 0x3,
		BUTTON2_BUTTON = 0x4,
		START_BUTTON = 0x5,
		SELECT_BUTTON = 0x6,
		L1_BUTTON = 0x7,
		R1_BUTTON = 0x8,
		L2_BUTTON = 0x9,
		R2_BUTTON = 0xA,
		L3_BUTTON = 0xB,
		R3_BUTTON = 0xC,
		L1R1_BUTTON = 0xD,
		L2R2_BUTTON = 0xE,
		DPAD_UP_BUTTON = 0xF,
		DPAD_DOWN_BUTTON = 0x10,
		DPAD_LEFT_BUTTON = 0x11,
		DPAD_RIGHT_BUTTON = 0x12,
		DPAD_LR_BUTTON = 0x13,
		DPAD_UD_BUTTON = 0x14,
		L_STICK_BUTTON = 0x15,
		R_STICK_BUTTON = 0x16,
		L_STICK_LR_BUTTON = 0x17,
		L_STICK_UD_BUTTON = 0x18,
		R_STICK_LR_BUTTON = 0x19,
		R_STICK_UD_BUTTON = 0x1A,
		ACCEPT_BUTTON_HOLD = 0x1B,
		BACK_BUTTON_HOLD = 0x1C,
		BUTTON1_BUTTON_HOLD = 0x1D,
		BUTTON2_BUTTON_HOLD = 0x1E,
		L1_BUTTON_HOLD = 0x1F,
		R1_BUTTON_HOLD = 0x20,
		L2_BUTTON_HOLD = 0x21,
		R2_BUTTON_HOLD = 0x22,
		F1_BUTTON = 0x23,
		WHEEL_UP_BUTTON = 0x24,
		WHEEL_DOWN_BUTTON = 0x25,
		NUM_BUTTONS = 0x26,
	};

	enum UIMessageType : unsigned int
	{
		UIMESSAGE_UNKNOWN = 0xFFFFFFFF,
		UIMESSAGE_PAD_INPUT = 0x0,
		UIMESSAGE_PAD_INPUT_ANALOG_STICK = 0x1,
		UIMESSAGE_KEYBOARD_INPUT = 0x2,
		UIMESSAGE_MOUSE_INPUT = 0x3,
		UIMESSAGE_FLASH = 0x4,
		UIMESSAGE_NUM = 0x5,
	};


	class CUICommand
	{
	public:
		void* vfptr;

		void* m_Pad0x8[0x2];

		unsigned int m_commandType;

		char m_Pad0x1C[0x4];

		void* m_commandData;
	};

	class CUIMessage : public CUICommand
	{
	public:
		unsigned int m_messageId;
		unsigned int m_resultId;
		unsigned int m_receiverUID;
		UIMessageType m_messageType;

		char m_Pad0x38[0x18];

		const char* m_messageResult;
	};

	class CUITranslator
	{
	public:
		char* Translate(unsigned int hash) { return reinterpret_cast<char*(__fastcall*)(void*, unsigned int)>(UFG_RVA(0xA28340))(this, hash); }

		__inline char* Translate(const char* text) { return Translate(HashUpper32(text)); }
	};

	class CUIPropertySetMenu
	{
	public:
		UFG_PAD(0x70);

		unsigned int mState;
		qString mSelectedItem;
		qString mSelectedSubItem;
		unsigned int mNumVisibleSlots;
		qString mGameSetup;
		qString mOperation;
		qString mOpDependant;
		qString mScriptFunc;
		qSymbol mProgressionFlow;

		void AddItem(const char* caption, bool enabled)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, bool)>(UFG_RVA(0x61DD50))(this, caption, enabled);
		}
	};

	class CUIScreenManager
	{
	public:
		void* vfptr;
		qList<CScreen> m_screenStack;
		qList<CScreen> m_overlayStack;

		UFG_PAD(0x90);

		void* mMainThreadId;
		bool m_renderUI;
		bool m_useWireframe;
		bool m_eatInputForScreens;
		bool m_updateUI;
		int m_maxScreenLimit;
		unsigned int m_targetWidth;
		unsigned int m_targetHeight;
		unsigned int m_flashWidth;
		unsigned int m_flashHeight;
		bool mScaleViewportInCode;
		unsigned int mScreenUIDCounter;
		int m_defaultControllerMask;
		int m_inputSuspended;

		UFG_PAD(0x98);

		CUITranslator* m_translator;

		/*void* m_gfxFileOpener;
		unsigned int m_currentNumDrawText;
		Scaleform::GFx::DrawText* m_drawText[32];
		int m_inputEnabled;
		UFG::UIScreenFactory* m_screenFactory;
		bool mIsMidSwitch;
		char mLastScreenPopped[64];
		UFG::qString mDebugStackPrint;*/

		CScreen* GetTopScreen()
		{
			return reinterpret_cast<CScreen*(__fastcall*)(void*)>(UFG_RVA(0xA2BEF0))(this);
		}
	};

	namespace UI
	{
		CUIScreenManager* GetScreenManager()
		{
			return *reinterpret_cast<CUIScreenManager**>(UFG_RVA(0x249C1C0));
		}

		CUITranslator* GetTranslator()
		{
			return GetScreenManager()->m_translator;
		}

		bool IsGamePaused()
		{
			return reinterpret_cast<bool(__fastcall*)()>(UFG_RVA(0x5EE1B0))();
		}
	}
}

#define UIHASH_SELECT 0x6256006A