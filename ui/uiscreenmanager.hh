#pragma once

namespace UFG
{
	class UIThreadCommandQueue : public Scaleform::Render::ThreadCommandQueue
	{
	public:
		Scaleform::Render::HAL* pHAL;
		Scaleform::Render::Renderer2D* pR2D;
	};

	class UIScreenManagerBase
	{
	public:
		qList<UIScreen> m_screenStack;
		qList<UIScreen> m_overlayStack;
		Scaleform::Lock mScreenStackLock;
		qList<UIPendingScreenLoad> mPendingScreenLoads;
		qList<UIPendingScreenLoad> mPendingOverlayLoads;
		qList<UIScreen> mPendingPoppedScreens;
		UIGfxAllocator* m_gfxAllocator;
		Scaleform::GFx::Loader* m_gfxMovieLoader;
		Scaleform::Ptr<Scaleform::Render::Renderer2D> mRenderer2D;
		UIThreadCommandQueue* mThreadCommandQueue;
		UIGfxTextureManager* mTextureManager;
		Scaleform::GFx::DrawTextManager* m_gfxDrawTextManager;
		struct UIGfxAmpAppControlInterface* mAmpAppControl;
		void* mMainThreadId;
		bool m_renderUI;
		bool m_useWireframe;
		bool m_eatInputForScreens;
		bool m_updateUI;
		int m_maxScreenLimit;
		u32 m_targetWidth;
		u32 m_targetHeight;
		u32 m_flashWidth;
		u32 m_flashHeight;
		bool mScaleViewportInCode;
		u32 mScreenUIDCounter;
		int m_defaultControllerMask;
		int m_inputSuspended;
		qList<UICommand> m_commandQueue;
		qList<UICommand> m_screenCommandQueue;
		qList<UICommand> m_pendingMessages;
		qList<qValueNode<u32>> m_inputDisabledQueue;
		qMutex m_pendingMessagesMutex;
		qList<UITween> m_activeTweens;
		UIInputHandler* m_inputHandler;
		void(__fastcall* m_audioCallback)(const char*, u32, u32, u32);
		void(__fastcall* m_DisplayChangeCallback)(Render::RenderOutputParams*);
		UIGfxTranslator* m_translator;
		UIGfxFileOpener* m_gfxFileOpener;
		u32 m_currentNumDrawText;
		Scaleform::GFx::DrawText* m_drawText[32];
		int m_inputEnabled;
		UIScreenFactory* m_screenFactory;
		bool mIsMidSwitch;
		i8 mLastScreenPopped[64];
		qString mDebugStackPrint;

		/* Virtual Functions */

		virtual void update(f32 elapsed) = 0;
		virtual void render() = 0;
		virtual void emableInput(bool enable) = 0;
		virtual bool isInputEnabled() = 0;
		virtual Scaleform::Ptr<Scaleform::Render::Renderer2D> getRenderer2D() = 0;
		virtual ~UIScreenManagerBase() = 0;

		/* Functions */

		UIScreen* getScreen(const char* fileName) { return SDK_CALL_FUNC(UIScreen*, 0xA2BA30, void*, const char*)(this, fileName); }
		UIScreen* getScreen(u32 screenUID) { return SDK_CALL_FUNC(UIScreen*, 0xA2B9E0, void*, u32)(this, screenUID); }
		UIScreen* getTopScreen() { return SDK_CALL_FUNC(UIScreen*, 0xA2BEF0, void*)(this); }
		UICommand* queuePopAllScreens() { return SDK_CALL_FUNC(UICommand*, 0xA31300, void*)(this); }
		UICommand* queuePopOverlay(const char* fileName) { return SDK_CALL_FUNC(UICommand*, 0xA31530, void*, const char*)(this, fileName); }
		UICommand* queuePopOverlay(u32 screenUID) { return SDK_CALL_FUNC(UICommand*, 0xA31410, void*, u32)(this, screenUID); }
		UICommand* queuePopScreen(u32 screenUID) { return SDK_CALL_FUNC(UICommand*, 0xA31600, void*, u32)(this, screenUID); }
		UICommand* queuePushOverlay(const char* fileName, int priority = 0, int controllerMask = -1) { 
			return SDK_CALL_FUNC(UICommand*, 0xA31720, void*, const char*, int, int)(this, fileName, priority, controllerMask);
		}
		UICommand* queuePushScreen(const char* fileName, int controllerMask = -1) { return SDK_CALL_FUNC(UICommand*, 0xA31820, void*, const char*, int)(this, fileName, controllerMask); }
		void setFontScale(f32 scale) { SDK_CALL_FUNC(void, 0xA31F20, void*, f32)(this, scale); }
		void shutdownScreen(UIScreen* screen) { SDK_CALL_FUNC(void, 0xA32220, void*, UIScreen*)(this, screen); }
	};
	SDK_ASSERT_SIZEOF(UIScreenManagerBase, 0x318);

	class UIScreenManager : public UIScreenManagerBase
	{
	public:
		//Scaleform::Render::D3D1x::HAL* mRenderHAL;

		/* Static Functions */

		SDK_SINLINE UIScreenManager* Instance() { return SDK_VAR_GET(UIScreenManager*, 0x249C1C0); }
	};
}