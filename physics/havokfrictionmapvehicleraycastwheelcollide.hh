#pragma once

namespace UFG
{
	class VehicleRaycastWheelCollide : public hkpVehicleRayCastWheelCollide
	{
	public:
		u64 mSurfacePropertyHandleUid[4];
		u64 mObjectPropertyHandleUid[4];
		qVector3 mSurfaceNormal[4];
		f32 mFrictionMultiplier[4];
	};
}