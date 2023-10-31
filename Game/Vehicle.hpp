#pragma once

namespace UFG
{
	namespace Vehicle
	{

	}

	namespace VehicleUtility
	{
		// If you really wanna use this, re-write it from scratch was used for MP development and will be unused...
		/*unsigned int GetDoorUID(int m_ID)
		{
			switch (m_ID)
			{
				case 0: return BoneUID_C_SeatSync01;
				case 1: return BoneUID_C_SeatSync02;
				case 2: return BoneUID_C_SeatSync03;
				case 3: return BoneUID_C_SeatSync04;
				case 6: return BoneUID_M_Trunk;
			}

			return -1;
		}

		bool GetDoorPosition(UFG::CSimVehicle* m_Vehicle, UFG::qVector3* m_Result, int m_ID)
		{
			UFG::CBaseAnimationComponent* m_VehicleAnimation = m_Vehicle->GetAnimation();
			if (!m_VehicleAnimation) return false;

			unsigned int m_DoorUID = GetDoorUID(m_ID);
			if (m_DoorUID == -1) return false;

			UFG::CCreature* m_VehicleCreature = m_VehicleAnimation->mCreature;
			if (!m_VehicleCreature) return false;

			int m_DoorBoneID = m_VehicleCreature->GetBoneID(m_DoorUID);
			if (m_DoorBoneID == -1) return false;

			m_VehicleCreature->GetTranslation(m_Result, m_DoorBoneID);

			return true;
		}

		int GetClosetDoor(UFG::CSimVehicle* m_Vehicle, float m_MaxDistance, UFG::qVector3* m_Target, UFG::qVector3* m_Result)
		{
			int m_BestID = -1;

			UFG::CSimObjectVehiclePropertiesComponent* m_VehicleProperties = m_Vehicle->GetVehicleProperties();
			if (m_VehicleProperties)
			{
				for (unsigned int i = 0; m_VehicleProperties->mDoorPhantomInfo.size > i; ++i)
				{
					UFG::qVector3 m_DoorPosition;
					if (!GetDoorPosition(m_Vehicle, &m_DoorPosition, i)) continue;

					float m_Dist = m_Target->DistTo(&m_DoorPosition);
					if (m_MaxDistance > m_Dist)
					{
						m_MaxDistance = m_Dist;
						m_BestID = i;
						memcpy(m_Result, &m_DoorPosition, sizeof(UFG::qVector3));
					}
				}
			}

			return m_BestID;
		}*/

		void ClearDriver(UFG::CSimVehicle* p_Vehicle)
		{
			reinterpret_cast<void(__fastcall*)(UFG::CSimVehicle*)>(UFG_RVA(0x674480))(p_Vehicle);
		}

		CAiDriverComponent* SetAIDriver(UFG::CSimVehicle* p_Vehicle, bool p_Ambient)
		{
			return reinterpret_cast<CAiDriverComponent*(__fastcall*)(UFG::CSimCharacter*, UFG::CSimVehicle*, bool)>(UFG_RVA(0x68A270))(nullptr, p_Vehicle, p_Ambient);
		}

		void PlaceCharacterInVehicle(UFG::CSimCharacter* character, UFG::CSimVehicle* vehicle, UFG::eTargetTypeEnum eRole, bool addAI, bool destroyEquipped, bool ignoreRoleGetInFirstEmptyPassengerSeat)
		{
			reinterpret_cast<void(__fastcall*)(UFG::CSimCharacter*, UFG::CSimVehicle*, UFG::eTargetTypeEnum, bool, bool, bool)>(UFG_RVA(0x6864B0))(character, vehicle, eRole, addAI, destroyEquipped, ignoreRoleGetInFirstEmptyPassengerSeat);
		}
		
		void ExitVehicleNoAnim(UFG::CSimCharacter* character)
		{
			reinterpret_cast<void(__fastcall*)(UFG::CSimCharacter*)>(UFG_RVA(0x6782B0))(character);
		}

		void ExitVehicleNow(UFG::CSimCharacter* pOccupantSimObject, bool bForceClearDriver, bool bDispatchNonCameraEvents, bool bDispatchCameraEvents)
		{
			reinterpret_cast<void(__fastcall*)(UFG::CSimCharacter*, bool, bool, bool)>(UFG_RVA(0x678FB0))(pOccupantSimObject, bForceClearDriver, bDispatchNonCameraEvents, bDispatchCameraEvents);
		}
	}
}