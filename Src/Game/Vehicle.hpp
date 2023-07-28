#pragma once

namespace UFG
{
	namespace Vehicle
	{
		#ifndef SDK_SD_MINIMAL_BUILD
		std::unordered_map<qSymbol, const char*> m_List =
		{ 
			{ 0x4AF5557A,		"270 DX (Red)" },
			{ 0x47B673A3,		"270 DX (Green)" },
			{ 0x134FD95D,		"600 Coupe-s (Red)" },
			{ 0x178EC4EA,		"600 Coupe-s (Yellow)" },
			{ 0xBB2DDCCC,		"600 Coupe-s (Green)" },
			{ 0xB66EFA15,		"600 Coupe-s (Brown)" },
			{ 0x1E0CFF84,		"600 Coupe-s (White)" },
			{ 0x64CD583E,		"600 Coupe-s (Old Salty)" },
			{ 0x21742357,		"860 MHC (White)" },
			{ 0x3DCB85AE,		"860 MHC (Black)" },
			{ 0xF699C81F,		"860 MHC (Red)" },
			{ 0x25B53EE0,		"860 MHC (Blue)" },
			{ 0x28F61839,		"860 MHC (Orange)" },
			{ 0xF258D5A8,		"860 MHC (Cyan)" },
			{ 0x3088A377,		"860 MHC (Whitejob)" },
			{ 0xD90856F7,		"1100 NAR (Black)" },
			{ 0xBFE53971,		"1100 NAR (Gray)" },
			{ 0xC74F06F2,		"1100 NAR (Red)" },
			{ 0xD34A4FC4,		"1100 NAR (Red)" },
			{ 0xDDC94B40,		"1100 NAR (Orange)" },
			{ 0xD44B702E,		"1100 NAR (Yellow)" },
			{ 0xC38E1B45,		"1100 NAR (Green)" },
			{ 0xCA0C202B,		"1100 NAR (Cyan)" },
			{ 0xDE09691D,		"1100 NAR (Cyan/Green)" },
			{ 0x62820F7D,		"Aggressor Armoured" },
			{ 0x6DC316F3,		"Aggressor Armoured" },
			{ 0xD2C18B62,		"Aggressor SWAT" },
			{ 0x6467E5DC,		"Airbrushed Dragon Armored Van" },
			{ 0x5C08220B,		"Ambulance" },
			{ 0x4BD70156,		"Bisai (Black)" },
			{ 0x99B61EEA,		"Bisai (Black/Red)" },
			{ 0x94F53833,		"Bisai (Black/Yellow)" },
			{ 0x42553A38,		"Bisai (Red)" },
			{ 0x4694278F,		"Bisai (Cyan)" },
			{ 0x9D77035D,		"Bisai (Blue)" },
			{ 0x6D58FF43,		"Bisai (Security)" },
			{ 0x1007AA0C,		"Bismarck (Gray)" },
			{ 0x14C6B7BB,		"Bismarck (Beaver)" },
			{ 0x1D448CD5,		"Bismarck (White)" },
			{ 0x17C0B330,		"Bismarck (Gray)" },
			{ 0xD6159037,		"Bismarck (White)" },
			{ 0x31AC2252,		"Bismarck (Winston)" },
			{ 0x4C4E8876,		"Blast (White)" },
			{ 0x488F95C1,		"Blast (Brown)" },
			{ 0x5209D873,		"Blast (Red)" },
			{ 0x5B8BE31D,		"Blast (Red/White)" },
			{ 0x45CCB318,		"Blast (Yellow)" },
			{ 0x56C8C5C4,		"Blast (Yellow/Gray)" },
			{ 0x72C8D541,		"Can Zi (Red)" },
			{ 0xADC3F561,		"Can Zi (Green)" },
			{ 0x2FC80D0,		"Cheer (White)" },
			{ 0xCF24DC4D,		"Cung Sau" },
			{ 0xECFDBF15,		"Cung Sau Delivery" },
			{ 0xF03FCDEE,		"Cung Sau Hijack" },
			{ 0xDD894BE6,		"Coast Guard" },
			{ 0xBCA6530F,		"CS 750 R (Red)" },
			{ 0x31749284,		"CS 750 R (Orange)" },
			{ 0x35B58F33,		"CS 750 R (Blue)" },
			{ 0x4AD0610B,		"CS 750 R (Blue/Orange)" },
			{ 0x38F6A9EA,		"CS 750 R (Gray)" },
			{ 0x2C8E3EE1,		"CS 750 R (Gray)" },
			{ 0x479347D2,		"CS 750 R (Green/Pink)" },
			{ 0xD5386F1,		"Dampfross (White)" },
			{ 0x3A9B88A2,		"Dampfross (Blue)" },
			{ 0x909D0962,		"Dampfross (Armoured)" },
			{ 0x7165510A,		"Dampfross (SWAT)" },
			{ 0xB36E2FD8,		"Dampfross (Cargo Yellow)" },
			{ 0xBE2D0901,		"Dampfross (Cargo Blue)" },
			{ 0xEA111F56,		"Dampfross (Cargo Chicken)" },
			{ 0xEC52885C,		"Dampfross (Cargo CNY)" },
			{ 0x5E8177C6,		"Drag 979 (Black)" },
			{ 0xDFECCC4E,		"Drag 979 (Red)" },
			{ 0x716DFCE0,		"Drag 979 (Orange)" },
			{ 0xD2AFEA97,		"Drag 979 (Purple)" },
			{ 0x563A02A5,		"Drifter GT (Gray)" },
			{ 0x547B254,		"Drifter GT (Red)" },
			{ 0x398561A3,		"Drifter GT (Green)" },
			{ 0xDA336F1,		"Drifter GT (Blue)" },
			{ 0x34C6477A,		"Drifter GT (Pink)" },
			{ 0x5B79247C,		"Drifter GT (White)" },		
			{ 0xBA19D629,		"DZS-90 (Black)" },
			{ 0xD5ECAA7B,		"DZS-90 (Green)" },
			{ 0x1DF029C9,		"DZS-90 (White)" },
			{ 0x99BAAD3E,		"DX 305 (Red)" },
			{ 0xDBAC553B,		"DX 305 (Orange)" },
			{ 0x90389650,		"DX 305 (Green)" },
			{ 0x94F98BE7,		"DX 305 (Blue)" },
			{ 0x30005155,		"Enterprise (Black)" },
			{ 0x8A20B8D,		"Enterprise (Gray)" },
			{ 0x3D43778C,		"Enterprise (Red)" },
			{ 0xBD0494ED,		"Enterprise (Blue)" },
			{ 0xEA52FCD3,		"Enterprise (Green)" },
			{ 0x5A1E9358,		"Enterprise (Popstar)" },
			{ 0x233154CC,		"Etalon (White)" },
			{ 0x27F0497B,		"Etalon (Orange)" },
			{ 0x3D7604C9,		"Etalon (Orange)" },
			{ 0x2E727215,		"Etalon (Black)" },
			{ 0x39B7197E,		"Etalon (Blue)" },
			{ 0x30352210,		"Etalon (Greenjob)" },
			{ 0x19CA28C6,		"Etalon (Gray)" },
			{ 0x64AB12C7,		"Executive (Gray)" },
			{ 0x8CD77AF8,		"Executive (Red)" },
			{ 0x8816674F,		"Executive (Green)" },
			{ 0x9FD30C24,		"Executive (Brown)" },
			{ 0x9651374A,		"Executive (White)" },
			{ 0x20761CD2,		"Fire Engine" },
			{ 0x35180BFF,		"Fuel Truck" },
			{ 0x46CEBF66,		"Gopher (Gray)" },
			{ 0xCB48113E,		"Guide (White)" },
			{ 0xD854C7A,		"Hassha (Black)" },
			{ 0x94451CD,		"Hassha (Red)" },
			{ 0x70147085,		"Hassha (Redjob)" },
			{ 0xC66AA3,			"Hassha (Orange)" },
			{ 0x9C9A7613,		"Hassha (White)" },
			{ 0x4A42E1C0,		"HKPD Cruiser" },
			{ 0x5920BEAE,		"HKPD SUV" },
			{ 0x5FCF84C6,		"HKPD Van" },
			{ 0x1B5E20EA,		"Jet 620V (Black)" },
			{ 0x806C8609,		"Jet 620V (Cooper)" },
			{ 0xEE0A3F13,		"Jet 620V (Red)" },
			{ 0x9E2BD60C,		"Jet 620V (Green)" },
			{ 0x9AEACBBB,		"Jet 620V (Blue)" },
			{ 0x97A9ED62,		"Jet 620V (White)" },
			{ 0xC15C4D40,		"Kyou Kan (Gray)" },
			{ 0xCC1F6B99,		"Kyou Kan (Red)" },
			{ 0x2AE3225C,		"Kyou Kan (Yellow)" },
			{ 0x6ECAF62F,		"Kyou Kan (Wei)" },
			{ 0x27A00485,		"Kyou Kan (White)" },
			{ 0x4484AE46,		"Leo Police" },
			{ 0xC911701F,		"Limo (Weeding)" },
			{ 0x5EAD89E,		"Little Bear" },
			{ 0x106CF590,		"Panzer (Red)" },
			{ 0x368834C,		"Panzer (Black)" },
			{ 0x81962F4D,		"Panzer (HotShot)" },
			{ 0x7A99EFB,		"Panzer (Orange)" },
			{ 0x1D2FD349,		"Panzer (Blue)" },
			{ 0xE2BA595,		"Panzer (White)" },
			{ 0x19EECEFE,		"Panzer (Dark Green)" },
			{ 0xA51E333,		"Prime (Gray)" },
			{ 0xC3E8EF55,		"Prime (Red)" },
			{ 0xC729F2E2,		"Prime (White)" },
			{ 0xCE3CEE0B,		"Red Siren (Red)" },
			{ 0xC37FC8D2,		"Red Siren (Cyan)" },
			{ 0xCAFDF3BC,		"Red Siren (Pink)" },
			{ 0xD4BAA3B9,		"Red Siren (White)" },
			{ 0xA1B4B94D,		"Neo V (Gray)" },
			{ 0xA575A4FA,		"Neo V (Red)" },
			{ 0xACF79F94,		"Neo V (Blue)" },
			{ 0xBF1CFB46,		"Neo V (Brown)" },
			{ 0x1579E9EA,		"MHC Taxi (Red)" },
			{ 0x8CB0BCCA,		"MHC Taxi (Red)" },
			{ 0x2D788CA,		"MHC Taxi (Green)" },
			{ 0x92B0C0F4,		"MHC Taxi (Green)" },
			{ 0x43BE6D5,		"Movit Cargo" },
			{ 0x74E3BCDE,		"Odaiko (Black)" },
			{ 0x7D6187B0,		"Odaiko (Red)" },
			{ 0x7022A169,		"Odaiko (White)" },
			{ 0x96A6511C,		"Tug" },
			{ 0x9BE577C5,		"Tug" },
			{ 0xE2C0FC64,		"Tug" },
			{ 0x4DC61DF4,		"Tug (Box)" },
			{ 0x49C4C726,		"Tuono" },
			{ 0x4487E1FF,		"Tuono (Black)" },
			{ 0xDD49B9,			"Tuono (Red)" },
			{ 0x41C540E,		"Tuono (Blue)" },
			{ 0x95F72D7,		"Tuono (White)" },
			{ 0x4046FC48,		"Tuono (Dark Cyan)" },
			{ 0x7FA665E2,		"Ridge Sport (Black)" },
			{ 0x72E5433B,		"Ridge Sport (White)" },
			{ 0x7B677855,		"Ridge Sport (Red)" },
			{ 0xAE96CA4,		"Ridge Sport (Gray)" },
			{ 0xA2B453C0,		"SES (Black)" },
			{ 0xAB3668AE,		"SES (Gray)" },
			{ 0x60AC9143,		"SES (Blue)" },
			{ 0xA6754E77,		"SES (White)" },
			{ 0xC6679659,		"Seaker (Red)" },
			{ 0xCB24B080,		"Seaker (Yellow)" },
			{ 0xDCE1DBEB,		"Seaker (Green)" },
			{ 0xC2A68BEE,		"Seaker (Blue)" },
			{ 0x523B728,		"Somersault Cloud" },
			{ 0x560C58DE,		"Superlight (White)" },
			{ 0x22C31C5F,		"Taikai (Gray)" },
			{ 0xC5D45A72,		"Taikai (Grayjob)" },
			{ 0x260201E8,		"Taikai (Orange)" },
			{ 0x2F803A86,		"Taikai (Red)" },
			{ 0x90B610B,		"Taikai (Blue)" },
			{ 0xC8977CAB,		"Taikai (Cyanjob)" },
			{ 0x633157D2,		"Taikai (Triad)" },
			{ 0x809E6D31,		"Terre GT (Black)" },
			{ 0x228CDB3F,		"Terre GT (Gray)" },
			{ 0xDAF6505D,		"Terre GT (Caramel)" },
			{ 0x264DC688,		"Terre GT (Red)" },
			{ 0xAD985169,		"Terre GT (Brown)" },
			{ 0x22A4EEEA,		"Terre GT (White)" },
			{ 0xA774A4CA,		"Terre GT (Ricky)" },
			{ 0x813657AB,		"Undercover Police Cruiser" },
			{ 0xACFF25EC,		"Velocita (Gray)" },
			{ 0xBFFB5330,		"Velocita (Gray)" },
			{ 0xBB3A4E87,		"Velocita (Red)" },
			{ 0x6CDE10D7,		"Velocita (Yellow)" },
			{ 0xA57D1E82,		"Velocita (Orange)" },
			{ 0x619D360E,		"Velocita (White)" },
			{ 0x6525D53,		"Wangan GSX (Red)" },
			{ 0x3E1C7CE5,		"Wangan GSX (Red)" },
			{ 0x249A3157,		"Wangan GSX (Gray)" },
			{ 0x379E478B,		"Wangan GSX (Blue)" },
			{ 0x205B2CE0,		"Wangan GSX (Yellow)" },
			{ 0x29D9178E,		"Wangan GSX (White)" },
			{ 0x3ADD6152,		"Wangan GSX (Black)" },
			{ 0xEF5D6AC3,		"Wangan GSX (Dog Eyes)" },
		};
		#endif
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