#pragma once

namespace UFG
{
	class ParkingSpot;

	class VehicleOccupantComponent : public SimComponent, public qNode<VehicleOccupantComponent>
	{
	public:
		enum { _TypeUID = 0xDE000001 };

		ParkingSpot* mpParkingSpot;
		qSafePointer<SimObject> mpDriver;
		qList<CharacterOccupantComponent> mPassengers;
		qSafePointer<SimObject> mpReservations[10];
		u32 mSeatCount;

		/* Functions */
	};
	SDK_ASSERT_SIZEOF(VehicleOccupantComponent, 0x178);
}