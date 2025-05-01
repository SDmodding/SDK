#pragma once

namespace UFG
{
	class VehicleAerodynamics : public hkpVehicleDefaultAerodynamics
	{
	public:
		f32 mDragBoost;
		f32 mExtraGravityMultiplier;
	};
}