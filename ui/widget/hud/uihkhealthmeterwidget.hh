#pragma once

namespace UFG
{
	class UIHKHealthMeterWidget
	{
	public:
		f32 mHealthPercent;
		f32 mHealthPercentOfMaxPossible;
		bool mChanged;
		bool mShouldHighlight;
		bool mIsFirstUpdate;

		/* Static Members */

		SDK_VINLINE qGlobalVar<bool, 0x208E331> gVisible;

		/* Functions */

		void Flash_SetVisible(UIScreen* screen, bool visible) { SDK_CALL_FUNC(void, 0x5E1A40, void*, UIScreen*, bool)(this, screen, visible); }
		void Flash_UIHighlight_Init(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5E5410, void*, UIScreen*)(this, screen); }
		void Flash_UpdateFullscreenFX(UIScreen* screen, f32 health, f32 deltaHealth) { SDK_CALL_FUNC(void, 0x5E5B00, UIScreen*, f32, f32)(screen, health, deltaHealth); }
		void Flash_UpdateHealthMeter(UIScreen* screen, f32 health) { SDK_CALL_FUNC(void, 0x5E5BF0, UIScreen*, f32)(screen, health); }
	};
}