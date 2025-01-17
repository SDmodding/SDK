#pragma once

namespace UFG
{
	class WaterFloatingTrackerComponent : public WaterFloatingTrackerBaseComponent, public qNode<WaterFloatingTrackerComponent>
	{
	public:
		class RippleGenerator* mRippleGenerator;
		hkpRigidBody* mBody;
		int mInWaterState;
		f32 mBuoyancyFactor;
		f32 mLinearDamping;
		f32 mAngularDamping;
		f32 mSinkRate;
		f32 mWaterElevation;
		class BuoyancyAction* mBuoyancyAction;
		bool mGenerateSplash;
		void(__fastcall* mOnEnterWaterCallback)(void*);
		void(__fastcall* mOnExitWaterCallback)(void*);
		void* mCallbackObject;
	};
}