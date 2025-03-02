#pragma once

namespace UFG
{
	class UIHKHelpBarData
	{
	public:
		enum eAlignment
		{
			ALIGN_LEFT,
			ALIGN_RIGHT,
			ALIGN_CENTER,
			ALIGN_JUSTIFY
		};

		enum ePriority
		{
			PRIORITY_ONE,
			PRIORITY_TWO,
			PRIORITY_THREE,
			PRIORITY_FOUR
		};

		u32 id;
		ePriority priority;
		eAlignment alignment;
		bool isWeaponPickup;
		UI::eButtons Buttons[6];
		qString Captions[6];
		qString Icons[6];
		u32 MessageIds[6];
		qString CustomTexturePack;

		/* Functions */

		void Add(UI::eButtons button, const char* caption, u32 messageId) { SDK_CALL_FUNC(void, 0x5D1A10, void*, UI::eButtons, const char*, u32)(this, button, caption, messageId); }

		/* Operators */

		void operator=(const UIHKHelpBarData& __that) { SDK_CALL_FUNC(void, 0x5CEAC0, void*, const UIHKHelpBarData&)(this, __that); }
		bool operator==(const UIHKHelpBarData& rval) { return SDK_CALL_FUNC(char, 0x5CEF50, void*, const UIHKHelpBarData&)(this, rval); }
	};

	class UIHKHelpBarWidget
	{
	public:
		bool mVisible;
		bool mChanged;
		bool mRemappable;
		qArray<UIHKHelpBarData*> mData;
		UIHKHelpBarData mOneFrameData;
		bool mShowingInFlash;
		float mYOffset;
		qString mTexturePackName;
		int mIndexShowing;
		bool mShowOneFrameActive;
		bool mShowOneFrameFlag;

		/* Static Functions */

		SDK_SINLINE void Lock() { SDK_CALL_FUNC(void, 0x5F1C60)(); }
		SDK_SINLINE void Unlock() { SDK_CALL_FUNC(void, 0x613210)(); }

		/* Functions */

		void ClearAll() { SDK_CALL_FUNC(void, 0x5D54E0, void*)(this); }
		void Flash_Hide(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DB920, void*, UIScreen*)(this, screen); }
		void Flash_SetAlignment(UIScreen* screen, UIHKHelpBarData::eAlignment alignment) { SDK_CALL_FUNC(void, 0x5DF120, void*, UIScreen*, UIHKHelpBarData::eAlignment)(this, screen, alignment); }
		void Flash_SetYOffset(UIScreen* screen, f32 yoffset) { SDK_CALL_FUNC(void, 0x5E22E0, void*, UIScreen*, f32)(this, screen, yoffset); }
		void Flash_Show(UIScreen* screen, UIHKHelpBarData* data) { SDK_CALL_FUNC(void, 0x5E2BE0, void*, UIScreen*, UIHKHelpBarData*)(this, screen, data); }
		void Flash_handleMouseClick(UIScreen* screen, f32 mouseX, f32 mouseY) { SDK_CALL_FUNC(void, 0x5E6010, void*, UIScreen*, f32, f32)(this, screen, mouseX, mouseY); }
		void Flash_handleMouseMove(UIScreen* screen, f32 mouseX, f32 mouseY) { SDK_CALL_FUNC(void, 0x5E6290, void*, UIScreen*, f32, f32)(this, screen, mouseX, mouseY); }
		void HandleMessage(UIScreen* screen, u32 msgId, UIMessage* msg) { SDK_CALL_FUNC(void, 0x5EA970, void*, UIScreen*, u32, UIMessage*)(this, screen, msgId, msg); }
		void Hide(u32 id) { SDK_CALL_FUNC(void, 0x5ECAB0, void*, u32)(this, id); }
		void LoadIconTexturePack(const char* texturePack) { SDK_CALL_FUNC(void, 0x5F0BF0, void*, const char*)(this, texturePack); }
		void ReleaseIconTexturePack() { SDK_CALL_FUNC(void, 0x600B80, void*)(this); }
		void Show(const UIHKHelpBarData& data) { SDK_CALL_FUNC(void, 0x60CE80, void*, const UIHKHelpBarData&)(this, data); }

		void Show(u32 id, UIHKHelpBarData::ePriority priority, UIHKHelpBarData::eAlignment alignment, UI::eButtons button0, const char* caption0, UI::eButtons button1, const char* caption1, UI::eButtons button2, const char* caption2, UI::eButtons button3, const char* caption3, UI::eButtons button4, const char* caption4, UI::eButtons button5, const char* caption5) {
			SDK_CALL_FUNC(void, 0x60D040, void*, u32, UIHKHelpBarData::ePriority, UIHKHelpBarData::eAlignment, UI::eButtons, const char*, UI::eButtons, const char*, UI::eButtons, const char*, UI::eButtons, const char*, UI::eButtons, const char*, UI::eButtons, const char*)(this, id, priority, alignment, button0, caption0, button1, caption1, button2, caption2, button3, caption3, button4, caption4, button5, caption5);
		}

		void ShowOneFrame(UI::eButtons button0, const char* caption0, UI::eButtons button1, const char* caption1, UI::eButtons button2, const char* caption2, UI::eButtons button3, const char* caption3, UI::eButtons button4, const char* caption4, UI::eButtons button5, const char* caption5) {
			SDK_CALL_FUNC(void, 0x610D40, void*, UI::eButtons, const char*, UI::eButtons, const char*, UI::eButtons, const char*, UI::eButtons, const char*, UI::eButtons, const char*, UI::eButtons, const char*)(this, button0, caption0, button1, caption1, button2, caption2, button3, caption3, button4, caption4, button5, caption5);
		}

		void ShowWithMessage(u32 id, UIHKHelpBarData::ePriority priority, UIHKHelpBarData::eAlignment alignment, const char* button0, const char* caption0, UI::eButtons messageId0, const char* button1, const char* caption1, UI::eButtons messageId1, const char* button2, const char* caption2, UI::eButtons messageId2, const char* button3, const char* caption3, UI::eButtons messageId3, const char* button4, const char* caption4, UI::eButtons messageId4, const char* button5, const char* caption5) {
			SDK_CALL_FUNC(void, 0x611600, void*, u32, UIHKHelpBarData::ePriority, UIHKHelpBarData::eAlignment, const char*, const char*, UI::eButtons, const char*, const char*, UI::eButtons, const char*, const char*, UI::eButtons, const char*, const char*, UI::eButtons, const char*, const char*, UI::eButtons, const char*, const char*)(this, id, priority, alignment, button0, caption0, messageId0, button1, caption1, messageId1, button2, caption2, messageId2, button3, caption3, messageId3, button4, caption4, messageId4, button5, caption5);
		}

		void Sort() { SDK_CALL_FUNC(void, 0x611B00, void*)(this); }
	};
}