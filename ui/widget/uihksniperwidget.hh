#pragma once

namespace UFG
{
	class UIHKSniperWidget
	{
	public:
		enum eSniperState
		{
			STATE_HIDE,
			STATE_SETTING,
			STATE_LOOKING_FOR_SIGNAL,
			STATE_FOUND_SIGNAL,
			STATE_PLAYING_INTRO,
			STATE_WAITING_FOR_TEXTURE_LOAD
		};

		eSniperState mState;
		bool mSniperMode;

		/* Virtual Functions */

		virtual ~UIHKSniperWidget() = 0;

		/* Functions */

		void Exit(UIScreen* screen) { SDK_CALL_FUNC(void, 0x5D7CD0, void*, UIScreen*)(this, screen); }
		void HandleMessage(UIScreen* screen, u32 msgId) { SDK_CALL_FUNC(void, 0x5EAED0, void*, UIScreen*, u32)(this, screen, msgId); }
	};
}