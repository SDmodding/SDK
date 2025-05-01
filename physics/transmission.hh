#pragma once

namespace UFG
{
	class Transmission : public hkpVehicleDefaultTransmission
	{
	public:
		hkArray<f32> mUpshiftRPM;
		hkArray<f32> mDownshiftRPM;
		bool mForceNeutral : 1;

		/* Functions */

		void InitializeFromPropertySet(WheeledVehiclePhysicsDef* vehicle_data_ptr, int numWheels, int firstFrontWheel, int lastFrontWheel, int firstRearWheel, int lastRearWheel) {
			SDK_CALL_FUNC(void, 0x46A340, void*, WheeledVehiclePhysicsDef*, int, int, int, int, int)(this, vehicle_data_ptr, numWheels, firstFrontWheel, lastFrontWheel, firstRearWheel, lastRearWheel);
		}
	};
}