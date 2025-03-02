#pragma once

namespace UFG
{
	class UIHK_PDAClockWidget
	{
	public:
		int mClockTime;

		/* Functions */

		void Flash_SetTime(UIScreen* screen, const char* timeStr) { SDK_CALL_FUNC(void, 0x5E13F0, void*, UIScreen*, const char*)(this, screen, timeStr); }
	};
}