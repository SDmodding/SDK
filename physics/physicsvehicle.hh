#pragma once

namespace UFG
{
	class VehicleParams
	{
	public:
		qSymbol mPhysicsPropertiesName;
		qSafePointer<SimObject> mSimObject;
		qString modelName;
		int firstFrontWheel;
		int lastFrontWheel;
		int firstRearWheel;
		int lastRearWheel;
	};
	SDK_ASSERT_SIZEOF(VehicleParams, 0x58);
}