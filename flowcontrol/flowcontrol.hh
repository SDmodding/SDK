#pragma once

namespace UFG
{
	class FlowController
	{
	public:
		enum eStackOperation : s32
		{
			Set,
			Push,
			Pop
		};

		enum eStateStatus : s32
		{
			INITIAL_GAME_STATE,
			STEADY_STATE
		};

		class StateHistory : public qNode<StateHistory>
		{
		public:
			qString mStateName;
			u32 mStateStartFrame;
			u32 mStateEndFrame;
			u32 mFilesLoaded;
		};


		GameState* mCurrentState;
		GameState* mPendingState;
		GameState* mAbsolutePrevState;
		GameState* mGameStateList[30];
		eStackOperation mPendingStateOperation;
		GameState* mPrevStateStack[5];
		int mStateStackIndex;
		eStateStatus mCurrentStateStatus;
		bool mTrackStateHistory;
		int mLoadsLastLoadScreen;
		qList<StateHistory> mStateHistoryList;

		SDK_SINLINE FlowController* Instance() { return reinterpret_cast<FlowController*>(SDK_RVA(0x23ECF00)); }
	};
	SDK_ASSERT_SIZEOF(FlowController, 0x158);
}