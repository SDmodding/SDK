#pragma once

namespace UFG
{
	class UIHK_PDARootMenuWidget
	{
	public:
		enum eState
		{
			STATE_IDLE,
			STATE_INTRO,
			STATE_ACTIVE,
			STATE_SUBMENU,
			STATE_SHOULD_ACTIVATE,
			STATE_SHOULD_EXIT,
			STATE_ENTER_SUBMENU
		};

		eState mState;
		f32 mIdleTime;
		f32 mRefreshTimer;
		bool mLastScrolledPrev;
		u32 mIntroIndex;
		u32 mSelectedIndex;
		qString mSelectedItem;
		UIHK_PDAInputLocker mInputLocker;

		/* Static Functions */

		SDK_SINLINE void PlayPdaClick() { SDK_CALL_FUNC(void, 0x5F4090)(); }

		/* Functions */

		void Activate(u32 introIndex, bool preLocked) { SDK_CALL_FUNC(void, 0x5D1850, void*, u32, bool)(this, introIndex, preLocked); }
		bool CanActivate() { return SDK_CALL_FUNC(bool, 0x5D47F0, void*)(this); }
		bool CanUseCamera() { return SDK_CALL_FUNC(bool, 0x5D48F0, void*)(this); }
		void Deactivate() { SDK_CALL_FUNC(void, 0x5D5FB0, void*)(this); }
		void Flash_EnterSubmenu(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DA860, void*, UIScreen*)(this, screen); }
		void Flash_GetSelected(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DAC70, void*, UIScreen*)(this, screen); }
		void Flash_Hide(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DBA40, void*, UIScreen*)(this, screen); }
		void Flash_Refresh(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5DEA00, void*, UIScreen*)(this, screen); }
		void Flash_SetGlobals(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E0020, void*, UIScreen*)(this, screen); }
		void Flash_Show(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E39B0, void*, UIScreen*)(this, screen); }
		void HandleMessage(UIScreen* screen, u32 msgId) { SDK_CALL_FUNC(void, 0x5EB3C0, void*, UIScreen*, u32)(this, screen, msgId); }
		bool IsInVehicle() { return SDK_CALL_FUNC(bool, 0x5EE2A0, void*)(this); }
		void LeaveSubMenu(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5F09B0, void*, UIScreen*)(this, screen); }
		void ScrollNext(UIScreen* screen) { SDK_CALL_FUNC(void, 0x603FC0, void*, UIScreen*)(this, screen); }
		void ScrollPrev(UIScreen* screen) { SDK_CALL_FUNC(void, 0x604310, void*, UIScreen*)(this, screen); }
	};
	SDK_ASSERT_SIZEOF(UIHK_PDARootMenuWidget, 0x70);
}