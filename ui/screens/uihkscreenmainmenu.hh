#pragma once

namespace UFG
{
	class UIHKScreenMainMenu : public UIScreen, public OnlineManagerObserver, public OSuiteManagerObserver
	{
	public:
		enum eState
		{
			STATE_INIT,
			STATE_MAIN,
			STATE_WAIT_TO_CONTINUE_GAME,
			STATE_WAIT_FOR_HEADER_LOAD_FOR_CONTINUE,
			STATE_WAIT_FOR_HEADER_LOAD_FOR_FLOW_CHECK,
			STATE_DETERMINING_FLOW_FOR_CONTINUE,
			STATE_WAIT_FOR_GAME_LOAD,
			STATE_SHOW_SAVE_PROMPT,
			STATE_WAIT_FOR_CHILD_SCREEN_LOAD,
			STATE_OUTRO,
			STATE_EXIT,
			STATE_SHOW_QUIT_PROMPT
		};

		enum eFriendsListState
		{
			FL_STATE_WAITING,
			FL_STATE_PROCESSING,
			FL_STATE_DONE
		};

		class HeaderInfo
		{
		public:
			u64 headerTimeStamp;
			qSymbol flow;
		};

		class SocialWidgetProperty
		{
		public:
			OSuiteLeaderboardData* mLBD;
			int mUIItemIndex;
			f32 mCopPercent;
			f32 mTriadPercent;
		};

		bool mInfoTickerSet;
		__declspec(align(8)) qProxy<UIPropertySetMenuMainNav> mMenu;
		bool mContinueEnabled;
		bool mDisplaySocialHubWidget;
		qList<OnlineId> mOnlineIdsToGetDisplayImageFor;
		int mCurrentDisplayImageSlot;
		qArray<SocialWidgetProperty> mSocialWidgetProperties;
		eFriendsListState mFriendsListState;
		bool mIsHeaderLoadStarted;
		qArray<HeaderInfo> mHeaderInfo;
		qSymbol mFlowList[3];
		int mCurrentFlowToCheck;
		bool mIsLoadingSaveGame;
		bool mIsContinue;
		bool mIsTransitionToGame;
		qSymbol mFlowForContinue;
		eState mState;
		MoviePlayer HKUIMovie;
		f32 mInactivityTimer;

		/* Functions */

		void PlayOutro() { SDK_CALL_FUNC(void, 0x5F4030, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(UIHKScreenMainMenu, 0x308);
}