#pragma once

namespace UFG
{
	class CSimCharacter;

	class CVehicleOccupantComponent : public CSimComponent
	{
	public:
		qNode<CVehicleOccupantComponent> mNode;
		void* mpParkingSpot;
		qSafePointer<CSimCharacter> mpDriver;
		qList<class CCharacterOccupantComponent> mPassengers;
		qSafePointer<CSimObject> mpReservations[10];
		uint32_t mSeatCount;

		UFG_INLINE CSimCharacter* GetPassenger(int p_Index, bool p_ExcludeEnteringAndExiting)
		{
			return reinterpret_cast<CSimCharacter * (__fastcall*)(void*, int, bool)>(UFG_RVA(0x67AF40))(this, p_Index, p_ExcludeEnteringAndExiting);
		}

		UFG_INLINE CSimCharacter* GetOccupant(uint32_t p_Index, eTargetTypeEnum* p_TargetType)
		{
			return reinterpret_cast<CSimCharacter * (__fastcall*)(void*, unsigned int, eTargetTypeEnum*)>(UFG_RVA(0x67AE50))(this, p_Index, p_TargetType);
		}

		CSimCharacter* FindOccupant(eTargetTypeEnum p_TargetType)
		{
			eTargetTypeEnum _TargetTypeResult;

			for (uint32_t i = 0; mSeatCount > i; ++i)
			{
				CSimCharacter* _Occupant = GetOccupant(i, &_TargetTypeResult);
				if (_TargetTypeResult == p_TargetType) {
					return _Occupant;
				}
			}

			return nullptr;
		}

		bool IsOccupant(CSimCharacter* m_Character)
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
	};
}