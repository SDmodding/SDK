#pragma once

namespace UFG
{
	namespace VehicleUtility
	{
		UFG_INLINE void ClearDriver(SimVehicle* p_Vehicle)
		{
			reinterpret_cast<void(__fastcall*)(SimVehicle*)>(UFG_RVA(0x674480))(p_Vehicle);
		}

		UFG_INLINE CAiDriverComponent* SetAIDriver(SimVehicle* p_Vehicle, bool p_Ambient)
		{
			return reinterpret_cast<CAiDriverComponent*(__fastcall*)(CSimCharacter*, SimVehicle*, bool)>(UFG_RVA(0x68A270))(nullptr, p_Vehicle, p_Ambient);
		}

		UFG_INLINE void PlaceCharacterInVehicle(CSimCharacter* p_Character, SimVehicle* p_Vehicle, eTargetTypeEnum p_Role, bool p_AddAI, bool p_DestroyEquipped, bool p_IgnoreRoleGetInFirstEmptyPassengerSeat)
		{
			reinterpret_cast<void(__fastcall*)(CSimCharacter*, SimVehicle*, eTargetTypeEnum, bool, bool, bool)>(UFG_RVA(0x6864B0))(p_Character, p_Vehicle, p_Role, p_AddAI, p_DestroyEquipped, p_IgnoreRoleGetInFirstEmptyPassengerSeat);
		}

		UFG_INLINE void ExitVehicleNoAnim(CSimCharacter* p_Character)
		{
			reinterpret_cast<void(__fastcall*)(CSimCharacter*)>(UFG_RVA(0x6782B0))(p_Character);
		}

		UFG_INLINE void ExitVehicleNow(CSimCharacter* p_Character, bool p_ForceClearDriver, bool p_DispatchNonCameraEvents, bool p_DispatchCameraEvents)
		{
			reinterpret_cast<void(__fastcall*)(CSimCharacter*, bool, bool, bool)>(UFG_RVA(0x678FB0))(p_Character, p_ForceClearDriver, p_DispatchNonCameraEvents, p_DispatchCameraEvents);
		}
	}
}