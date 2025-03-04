#pragma once

namespace UFG
{
	class UIHKMoneyPopupWidget
	{
	public:
		bool mIsVisible;
		bool mForceShow;
		bool mLeaveOn;
		bool mLeaveOnChanged;
		bool mTryToHide;
		bool mTimerActive;
		int mMoney;
		f32 mHideTimer;

		/* Functions */

		void Flash_Show(UIScreen* screen, int oldMoney, int newMoney) { SDK_CALL_FUNC(void, 0x5E3280, void*, UIScreen*, int, int)(this, screen, oldMoney, newMoney); }
	};
}