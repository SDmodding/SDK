#pragma once

namespace UFG
{
	class UIHKRegionIndicatorWidget
	{
	public:
		bool mChanged;
		bool mVisible;
		bool mIsVisible;
		u32 mZone;
		f32 mOutroTimer;

		/* Static Functions */

		SDK_SINLINE UIHKRegionIndicatorWidget* Instance() { return SDK_VAR_GET(UIHKRegionIndicatorWidget*, 0x2430C18); }
		SDK_SINLINE void GetTimeString(f32 time, qString& timeStr) { SDK_CALL_FUNC(void, 0x5E9890, f32, qString&)(time, timeStr); }

		/* Functions */

		void Flash_SetVisible(UIScreen* screen, bool visible) { SDK_CALL_FUNC(void, 0x5E1DF0, void*, UIScreen*, bool)(this, screen, visible); }
		void Flash_Show(UIScreen* screen, u32 zone, f32 time) { SDK_CALL_FUNC(void, 0x5E36F0, void*, UIScreen*, u32, f32)(this, screen, zone, time); }
		void Update(UIScreen* screen, f32 elapsed) { SDK_CALL_FUNC(void, 0x616850, void*, UIScreen*, f32)(this, screen, elapsed); }
	};
}