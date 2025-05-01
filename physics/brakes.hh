#pragma once

namespace UFG
{
	class Brakes : public hkpVehicleDefaultBrake
	{
	public:
		f32 mTimeToMaxPedal;
		f32 mTimePedalDown;

		/* Functions */

		void InitializeFromPropertySet(WheeledVehiclePhysicsDef* vehicle_data_ptr, int numWheels, int firstFrontWheel, int lastFrontWheel, int firstRearWheel, int lastRearWheel) {
			SDK_CALL_FUNC(void, 0x469C70, void*, WheeledVehiclePhysicsDef*, int, int, int, int, int)(this, vehicle_data_ptr, numWheels, firstFrontWheel, lastFrontWheel, firstRearWheel, lastRearWheel);
		}
	};
}