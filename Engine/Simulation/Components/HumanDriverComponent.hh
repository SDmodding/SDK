#pragma once

namespace UFG
{
	class CruiseControl
	{
	public:
		void* vfptr;
		class qPidController* mPidController;
		float mSetSpeedMPS;
		bool mIsActive;
		bool mIsEnabled;
	}; typedef CruiseControl CCruiseControl;
	UFG_ASSERT_CLASS(CruiseControl, 0x18);

	//=================================================================

	class HumanDriverComponent : public VehicleDriverInterface, public qNode<HumanDriverComponent>
	{
	public:
		SimpleTimer mHangTime;
		SimpleTimer mMaxSpeedTime;
		CruiseControl* mCruiseControl;
		class CController* mController;
		eSimObjectVehicleTypeEnum mVehicleType;
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
	}; typedef HumanDriverComponent CHumanDriverComponent;
	UFG_ASSERT_CLASS(HumanDriverComponent, 0x190);
}