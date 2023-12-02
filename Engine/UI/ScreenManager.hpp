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
		uint32_t m_targetWidth;
		uint32_t m_targetHeight;
		uint32_t m_flashWidth;
		uint32_t m_flashHeight;
		bool mScaleViewportInCode;
		uint32_t mScreenUIDCounter;
		int m_defaultControllerMask;
		int m_inputSuspended;

		UFG_PAD(0x98);

		CUIGfxTranslator* m_translator;
		CUIGfxFileOpener* m_gfxFileOpener;
		uint32_t m_currentNumDrawText;

		/*Scaleform::GFx::DrawText* m_drawText[32];
		int m_inputEnabled;
		UFG::UIScreenFactory* m_screenFactory;
		bool mIsMidSwitch;
		char mLastScreenPopped[64];
		UFG::qString mDebugStackPrint;*/

		static __inline CUIScreenManager* Instance()
		{
			return *reinterpret_cast<CUIScreenManager**>(UFG_RVA(0x249C1C0));
		}

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

		void QueuePushOverlay(const char* p_ScreenName, int p_Priority = 0, int p_ControllerMask = -1)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, int, int)>(UFG_RVA(0xA31720))(this, p_ScreenName, p_Priority, p_ControllerMask);
		}
	};
	
	class CUIScreenTextureManager
	{
	public:
		void QueueTexturePackLoad(const char* p_TextureName, DataStreamer::PRIORITY p_Priority = DataStreamer::DEFAULT_PRIORITY, void* p_Callback = nullptr, void* p_CallbackParam = nullptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, DataStreamer::PRIORITY, void*, void*)>(UFG_RVA(0x5C1CA0))(this, p_TextureName, p_Priority, p_Callback, p_CallbackParam);
		}
	};
}