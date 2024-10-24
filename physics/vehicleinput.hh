#pragma once

namespace UFG
{
	class VehicleInput
	{
	public:
		f32 mSteering;
		f32 mForwardWeightShift;
		f32 mGasBrakes;
		f32 mRawGasBrakes;
		bool mInReverse : 1;
		bool mForceNeutral : 1;
		bool mHandBrakeSet : 1;
		bool mDoWheelie : 1;
		bool mDoOneEighty : 1;
		bool mDoBurnout : 1;
		bool mFreemanStopTask : 1;
		bool mFreemanSteerTask : 1;
		bool mFreemanPreventWheelie : 1;
		bool mHasHumanDriver : 1;
		bool mHasAiDriver : 1;
	};
	SDK_ASSERT_SIZEOF(VehicleInput, 0x14);
}