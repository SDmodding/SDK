#pragma once

namespace UFG
{
	class UIHK_NISFrameCounterWidget
	{
	public:
		bool mChanged;
		bool mVisible;
		qString mCaption;

		/* Impl Functions */

		SDK_INLINE void SetVisible(bool visible) { mChanged |= (mVisible != visible); mVisible = visible; }

		/* Functions */

		void SetCaption(const char* caption) { SDK_CALL_FUNC(void, 0x605620, void*, const char*)(this, caption); }
		void SetSceneTime(f32 sceneTime) { SDK_CALL_FUNC(void, 0x607330, void*, f32)(this, sceneTime); }
	};
}