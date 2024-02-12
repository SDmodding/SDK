#pragma once

namespace UFG
{
	struct ScoreAffector_t
	{
		float mPoints;
		float mCurrentMultiplier;
		float mMultiplierReplenishRate;
		float mMultiplierReduction;
		float mMultiplierResetTimer;
		uint64_t mTimestamp;
		bool mIsActive;
		qString mCaption;
	};

	class CFaceMeterComponent : public CSimComponent, public qNode<CFaceMeterComponent>
	{
	public:
		ScoreAffector_t mAffectors[107];
		uint64_t mLastActionPerformedTimestamp;
		bool mFaceMeterEnabled;
		bool mFaceMeterActivated;
		CPropertySetHandle mProperties;
	};
	UFG_ASSERT_CLASS(CFaceMeterComponent, 0x21E0);
}