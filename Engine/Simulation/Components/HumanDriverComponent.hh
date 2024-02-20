#pragma once

namespace UFG
{
	class CCruiseControl
	{
	public:
		void* vfptr;
		class qPidController* mPidController;
		float mSetSpeedMPS;
		bool mIsActive;
		bool mIsEnabled;
	};
	UFG_ASSERT_CLASS(CCruiseControl, 0x18);

	//=================================================================

	class CHumanDriverComponent : public CVehicleDriverInterface, public qNode<CHumanDriverComponent>
	{
	public:
		SimpleTimer mHangTime;
		SimpleTimer mMaxSpeedTime;
		CCruiseControl* mCruiseControl;
		class CController* mController;
		unsigned int mVehicleType;
		float mJumpLocHeight;
		float mJumpDistance;
		float mHighestJump;
		float mCollisionFreeDriving;
		float reverseLockoutDelay;
		float mChaseTime;
		bool mAtMaxSpeed;
		bool mIsInAir;
		bool mSirenIsOn;
		bool mEnableMaxSpeedStat;
	};
	UFG_ASSERT_CLASS(CHumanDriverComponent, 0x190);
}