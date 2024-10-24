#pragma once

namespace UFG
{
	class VehicleSpot : public MarkerBase, public qNode<VehicleSpot>
	{
	public:
		u32 mRoadSegmentID;
		f32 mClosestT;
		u16 mClosestLaneIndex;
		s8 mCanSpawn;
		u16 mRoadNetworkType;
		u16 mNearOrOnIntersection;
		qVector3 mBoundingBoxMin;
		qVector3 mBoundingBoxMax;
		qSafePointer<SimObject, SimObjectVehicle> mOccupier;
	};
	SDK_ASSERT_SIZEOF(VehicleSpot, 0xC0);

	class ParkingSpot : public VehicleSpot, public qNode<ParkingSpot>
	{
	public:
	};
}