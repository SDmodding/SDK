#pragma once

namespace UFG
{
	enum LeaderboardCategory
	{
		InvalidLeaderboardCategory = -1,
		LeaderboardCategory_StatAward = 0,
		LeaderboardCategory_StatGame,
		LeaderboardCategory_Mission,
		LeaderboardCategory_Race,
		NumLeaderboardCategories
	};

	class OSuiteLeaderboardData
	{
	public:
		int mLeaderboardId;
		int mLeaderboardLocalId;
		qString mLeaderboardNameStr;
		qSymbol mLeaderboardName;
		qString mCaption;
		LeaderboardCategory mCategory;
		qString mSliceNameStr;
		qSymbol mSliceName;
		qString mDesc;
		qString mImage;
		const char* mFormat;
		int mGold;
		int mSilver;
		int mBronze;
		int mStartMs;
		int mDeltaTime;
		int mAttemptCount;
		qString mRankDesc;
		qSymbol mFlow;
	};
}