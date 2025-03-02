#pragma once

namespace UFG
{
	class UITiledMapZoomCalc
	{
	public:
		f32 mScale;
		bool mInteriorActiveLastFrame;
		f32 mZoomHistory[12];
		int mZoomHistoryIndex;

		/* Static Functions */

		SDK_SINLINE void LockScale(f32 scale) { SDK_CALL_FUNC(void, 0xC6120, f32)(scale); }
		SDK_SINLINE void UnlockScale() { SDK_CALL_FUNC(void, 0xCBDA0)(); }
	};
}