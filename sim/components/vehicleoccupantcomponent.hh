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

		/* Impl Functions */

		SDK_INLINE u32 GetNumberOfSeats() { return mSeatCount; }
		SDK_INLINE qSafePointer<SimObject>* GetReservationList() { return mpReservations; }
		SDK_INLINE bool IsParked() { return mpParkingSpot; }
		SDK_INLINE void SetParkingSpot(ParkingSpot* parkingSpot) { mpParkingSpot = parkingSpot; }

		/* Functions */

		void AddOccupant(CharacterOccupantComponent* pOccupant, bool bDriver) { SDK_CALL_FUNC(void, 0x66FAE0, void*, CharacterOccupantComponent*, bool)(this, pOccupant, bDriver); }
		void DeleteAllOccupants() { SDK_CALL_FUNC(void, 0x676600, void*)(this); }
		u32 GetNumberOfOccupants() { return SDK_CALL_FUNC(u32, 0x67ADA0, void*)(this); }
		u32 GetNumberOfPassengers() { return SDK_CALL_FUNC(u32, 0x67AE00, void*)(this); }
		SimObject* GetOccupant(u32 index, eTargetTypeEnum* pTargetType) { return SDK_CALL_FUNC(SimObject*, 0x67AE50, void*, u32, eTargetTypeEnum*)(this, index, pTargetType); }
		SimObject* GetPassenger(int iIndex, bool excludeEnteringAndExiting) { return SDK_CALL_FUNC(SimObject*, 0x67AF40, void*, int, bool)(this, iIndex, excludeEnteringAndExiting); }
		bool HasPassengers() { return SDK_CALL_FUNC(bool, 0x67D1E0, void*)(this); }
		void RemoveOccupant(CharacterOccupantComponent* pOccupant) { SDK_CALL_FUNC(void, 0x689710, void*, CharacterOccupantComponent*)(this, pOccupant); }
		void SetupPassengerData(SceneObjectProperties* pSOP) { SDK_CALL_FUNC(void, 0x68BA50, void*, SceneObjectProperties*)(this, pSOP); }
		void UpdateOccupantPriority(const qSymbol& oldPriority, const qSymbol& newPriority) { SDK_CALL_FUNC(void, 0x698600, void*, const qSymbol&, const qSymbol&)(this, oldPriority, newPriority); }
	};
	SDK_ASSERT_SIZEOF(VehicleOccupantComponent, 0x178);
}