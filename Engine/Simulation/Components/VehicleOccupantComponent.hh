#pragma once

namespace UFG
{
	class SimCharacter;

	class VehicleOccupantComponent : public SimComponent
	{
	public:
		qNode<VehicleOccupantComponent> mNode;
		void* mpParkingSpot;
		qSafePointer<SimCharacter> mpDriver;
		qList<class CCharacterOccupantComponent> mPassengers;
		qSafePointer<SimObject> mpReservations[10];
		uint32_t mSeatCount;

		UFG_INLINE SimCharacter* GetPassenger(int p_Index, bool p_ExcludeEnteringAndExiting)
		{
			return reinterpret_cast<SimCharacter * (__fastcall*)(void*, int, bool)>(UFG_RVA(0x67AF40))(this, p_Index, p_ExcludeEnteringAndExiting);
		}

		UFG_INLINE SimCharacter* GetOccupant(uint32_t p_Index, eTargetTypeEnum* p_TargetType)
		{
			return reinterpret_cast<SimCharacter * (__fastcall*)(void*, unsigned int, eTargetTypeEnum*)>(UFG_RVA(0x67AE50))(this, p_Index, p_TargetType);
		}

		SimCharacter* FindOccupant(eTargetTypeEnum p_TargetType)
		{
			eTargetTypeEnum _TargetTypeResult;

			for (uint32_t i = 0; mSeatCount > i; ++i)
			{
				SimCharacter* _Occupant = GetOccupant(i, &_TargetTypeResult);
				if (_TargetTypeResult == p_TargetType) {
					return _Occupant;
				}
			}

			return nullptr;
		}

		bool IsOccupant(SimCharacter* m_Character)
		{
			if (mpDriver.m_pPointer == m_Character) {
				return true;
			}

			for (uint32_t i = 0; mSeatCount > i; ++i)
			{
				if (GetPassenger(i, false) == m_Character) {
					return true;
				}
			}

			return false;
		}
	}; typedef VehicleOccupantComponent CVehicleOccupantComponent;
}