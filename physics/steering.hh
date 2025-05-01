#pragma once

namespace UFG
{
	class Steering : public hkpVehicleSteering
	{
	public:
		hkArray<f32> mWheelSteeringMultiplier;
		f32 mMaxSteeringAngle;
		f32 mSteeringSensitivityLo;
		f32 mSteeringSensitivityHi;
		f32 mSteeringSensitivityMinSpeed;
		f32 mSteeringSensitivityMaxSpeed;
		f32 mSteeringCenteringRate;
		f32 mMaxSteeringAngleForSpeed;
		f32 mCurrentSteeringAngle;
		f32 mSteeringModel;
		f32 mPrevInputValue;

		/* Functions */

		void InitializeFromPropertySet(WheeledVehiclePhysicsDef* vehicle_data_ptr, int numWheels, int firstFrontWheel, int lastFrontWheel, int firstRearWheel, int lastRearWheel) {
			SDK_CALL_FUNC(void, 0x46A180, void*, WheeledVehiclePhysicsDef*, int, int, int, int, int)(this, vehicle_data_ptr, numWheels, firstFrontWheel, lastFrontWheel, firstRearWheel, lastRearWheel);
		}
	};
}