#pragma once

namespace UFG
{
	class HumanDriverComponent : public VehicleDriverInterface, public qNode<HumanDriverComponent>
	{
	public:
		enum { _TypeUID = 0xD8000005 };

		SimpleTimer mHangTime;
		SimpleTimer mMaxSpeedTime;
		CruiseControl* mCruiseControl;
		Controller* mController;
		u32 mVehicleType;
		f32 mJumpLocHeight;
		f32 mJumpDistance;
		f32 mHighestJump;
		f32 mCollisionFreeDriving;
		f32 reverseLockoutDelay;
		f32 mChaseTime;
		bool mAtMaxSpeed;
		bool mIsInAir;
		bool mSirenIsOn;
		bool mEnableMaxSpeedStat;

		/* Functions */

		void Update(f32 deltaTime) { SDK_CALL_FUNC(void, 0x691130, void*, f32)(this, deltaTime); }
		void StatGameStopMaxSpeed() { SDK_CALL_FUNC(void, 0x68C5E0, void*)(this); }
		void StatGameStopInAir() { SDK_CALL_FUNC(void, 0x68C540, void*)(this); }
		void ResetVehicle() { SDK_CALL_FUNC(void, 0x689A40, )(); }
	};
}