#pragma once

namespace UFG
{
	class PredictiveStreamingStats
	{
	public:
		struct CharacterInfo
		{
			bool* m_bHasWeaponTypeEquipped;
		};

		struct PlayerVehicleInfo
		{
			f32 m_fDistanceToDriverSide;
			f32 m_fDistanceToPassengerSide;
			bool m_bIsDriver;
			bool m_bIsPassenger;
		};

		struct PlayerWeaponInfo
		{
			f32 m_fDistanceSquared;
			bool m_bOwned;
		};

		struct PlayerInfo
		{
			bool m_bIsDriver;
			bool m_bIsPassenger;
			PlayerWeaponInfo* m_PlayerWeaponInfo;
			PlayerVehicleInfo* m_PlayerVehicleInfo;
			PlayerVehicleInfo* m_PlayerBoatInfo;
		};

		struct VehicleInfo
		{
			bool m_bHasDriver;
			bool m_bHasPassenger;
			bool m_bTargetedForInteractionOnFootDriverSide;
			bool m_bTargetedForInteractionOnFootPassengerSide;
			bool* m_bHasDriverByWeaponType;
			bool* m_bHasPassengerByWeaponType;
			bool* m_bTargetedForInteractionDriverSideOnFootByWeaponType;
			bool* m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
		};

		struct WeaponInfo
		{
			bool m_bOwned;
			bool m_bTargetedForInteractionOnFoot;
		};

		PlayerInfo m_PlayerInfo;
		WeaponInfo* m_WeaponInfo;
		VehicleInfo m_VehicleInfo[10];
		VehicleInfo m_BoatInfo[7];
		CharacterInfo m_CharacterInfo[43];
		SimObject* m_pPlayerSimObject;
		TargetingSystemPedPlayerComponent* m_pPlayerTSC;
		CharacterOccupantComponent* m_pPlayerCOC;
		TransformNodeComponent* m_pPlayerTNC;

		/* Static Functions */

		SDK_SINLINE PredictiveStreamingStats* Instance() { return SDK_VAR_GET(PredictiveStreamingStats*, 0x23D8F40); }
	};
}