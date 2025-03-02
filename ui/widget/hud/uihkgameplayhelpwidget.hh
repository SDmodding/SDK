#pragma once

namespace UFG
{
	class UIHKGameplayHelpData
	{
	public:
		enum eChargeAnimState
		{
			CHARGE_ANIM_IDLE,
			CHARGE_ANIM_SHOULD_PLAY,
			CHARGE_ANIM_SHOULD_STOP,
			CHARGE_ANIM_PLAYING,
			CHARGE_ANIM_STOPPED
		};

		u32 id;
		u32 priority;
		UI::RemapContext remapContext;
		bool isWeaponPickup;
		UI::eButtons Buttons[2];
		qString Captions[2];
		qString Icons[2];
		eChargeAnimState ChargeAnimState[2];
		qString CustomTexturePack;
	};

	class UIHKGameplayHelpWidget
	{
	public:
		bool mScriptVisible;
		bool mScriptVisibleChanged;
		bool mVisible;
		bool mChanged;
		qArray<UIHKGameplayHelpData*> mData;
		UIHKGameplayHelpData mOneFrameData;
		bool mShowingInFlash;
		f32 mYOffset;
		qString mTexturePackName;
		bool mShowOneFrameActive;
		bool mShowOneFrameFlag;

		/* Static Functions */

		SDK_SINLINE UIHKGameplayHelpWidget* Instance() { return SDK_VAR_GET(UIHKGameplayHelpWidget*, 0x2430C48); }

		/* Functions */

		void ClearAll() { SDK_CALL_FUNC(void, 0x5D5400, void*)(this); }
		void Flash_Hide(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DB860, void*, UIScreen*)(this, screen); }
		void Flash_PlayChargeAnim(UIScreen* screen, int index) { SDK_CALL_FUNC(void, 0x5DE610, void*, UIScreen*, int)(this, screen, index); }
		void Flash_SetYOffset(UIScreen* screen, f32 yoffset) { SDK_CALL_FUNC(void, 0x5E2200, void*, UIScreen*, f32)(this, screen, yoffset); }
		void Flash_Show(UIScreen* screen, UIHKGameplayHelpData* data) { SDK_CALL_FUNC(void, 0x5E2760, void*, UIScreen*, UIHKGameplayHelpData*)(this, screen, data); }
		void Flash_StopChargeAnim(UIScreen* screen, int index) { SDK_CALL_FUNC(void, 0x5E5200, void*, UIScreen*, int)(this, screen, index); }
		void Hide(u32 id) { SDK_CALL_FUNC(void, 0x5EC9A0, void*, u32)(this, id); }
		bool LoadIconTexturePack(const char* texturePack) { return SDK_CALL_FUNC(bool, 0x5F0B40, void*, const char*)(this, texturePack); }
		void PlayButtonCharge(u32 id, int index) { SDK_CALL_FUNC(void, 0x5F3F50, void*, u32, int)(this, id, index); }
		void ReleaseIconTexturePack() { SDK_CALL_FUNC(void, 0x600B30, void*)(this); }
		void Show(const UIHKGameplayHelpData& data) { SDK_CALL_FUNC(void, 0x60CB20, void*, const UIHKGameplayHelpData&)(this, data); }

		void Show(u32 id, u32 priority, UI::eButtons button0, const char* caption0, UI::eButtons button1, const char* caption1) {
			SDK_CALL_FUNC(void, 0x60CDB0, void*, u32, u32, UI::eButtons, const char*, UI::eButtons, const char*)(this, id, priority, button0, caption0, button1, caption1);
		}

		void ShowOneFrame(const UIHKGameplayHelpData& data) { SDK_CALL_FUNC(void, 0x610CB0, void*, const UIHKGameplayHelpData&)(this, data); }
		void StopButtonCharge(u32 id, int index) { SDK_CALL_FUNC(void, 0x612560, void*, u32, int)(this, id, index); }
	};
}