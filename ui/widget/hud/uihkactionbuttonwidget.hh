#pragma once

namespace UFG
{
	class UIHKActionButtonWidget
	{
	public:
		UI::eButtons mButton;
		bool mVisible;
		bool mChanged;
		qString mActionText;
		qString mActionType;
		bool mShowOneFrameActive;
		bool mShowOneFrameFlag;

		/* Static Functions */

		SDK_SINLINE UIHKActionButtonWidget* Instance() { return SDK_VAR_GET(UIHKActionButtonWidget*, 0x2430BB8); }

		/* Impl Functions */

		SDK_INLINE void Hide() { mChanged |= mVisible; mVisible = 0; }
		SDK_INLINE void RefreshOneFrame() { mShowOneFrameFlag = 1; }

		/* Functions */

		void Flash_Show(UIScreen* screen, const char* icon, const char* actionType) { SDK_CALL_FUNC(void, 0x5E23C0, void*, UIScreen*, const char*, const char*)(this, screen, icon, actionType); }

		void Show(const char* actionText, UI::eButtons button, const char* actionType) {
			SDK_CALL_FUNC(void, 0x60CA80, void*, const char*, UI::eButtons, const char*)(this, actionText, button, actionType);
		}

		void ShowOneFrame(const char* actionText, UI::eButtons button, const char* actionType) {
			SDK_CALL_FUNC(void, 0x610C90, void*, const char*, UI::eButtons, const char*)(this, actionText, button, actionType);
		}

		void Update(UIScreen* screen) { SDK_CALL_FUNC(void, 0x613360, void*, UIScreen*)(this, screen); }
	};
}