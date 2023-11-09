#pragma once

namespace UFG
{
	class CUIScreenManager
	{
	public:
		void* vfptr;
		qList<CUIScreen> m_screenStack;
		qList<CUIScreen> m_overlayStack;

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

		CUIGfxTranslator* m_translator;

		/*void* m_gfxFileOpener;
		unsigned int m_currentNumDrawText;
		Scaleform::GFx::DrawText* m_drawText[32];
		int m_inputEnabled;
		UFG::UIScreenFactory* m_screenFactory;
		bool mIsMidSwitch;
		char mLastScreenPopped[64];
		UFG::qString mDebugStackPrint;*/

		CUIScreen* GetScreen(const char* p_FileName)
		{
			return reinterpret_cast<CUIScreen*(__fastcall*)(void*, const char*)>(UFG_RVA(0xA2BA30))(this, p_FileName);
		}

		CUIScreen* GetScreen(uint32_t p_ScreenUID)
		{
			return reinterpret_cast<CUIScreen*(__fastcall*)(void*, uint32_t)>(UFG_RVA(0xA2B9E0))(this, p_ScreenUID);
		}

		CUIScreen* GetOverlay(const char* p_FileName)
		{
			return reinterpret_cast<CUIScreen*(__fastcall*)(void*, const char*)>(UFG_RVA(0xA2B9A0))(this, p_FileName);
		}

		CUIScreen* GetOverlay(uint32_t p_OverlayUID)
		{
			for (auto i = m_overlayStack.mNode.mNext; i != &m_overlayStack.mNode; i = i->mNext)
			{
				UFG::CUIScreen* m_UIScreen = i->GetPointerSub<offsetof(UFG::CUIScreen, mNode)>();
				if (m_UIScreen->m_screenNameHash == p_OverlayUID)
					return m_UIScreen;
			}

			return nullptr;
		}

		CUIScreen* GetTopScreen()
		{
			return reinterpret_cast<CUIScreen*(__fastcall*)(void*)>(UFG_RVA(0xA2BEF0))(this);
		}
	};
}