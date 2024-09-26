#pragma once

namespace UFG
{
	class CSceneObjectProperties
	{
	public:
		UFG_PAD(0x18);

		uint32_t m_TypeUID;
		uint32_t m_NameUID;
		uint16_t m_Flags;
		int16_t m_SimObjIndex;
		SimObject* m_pSimObject;

		UFG_PAD(0x58);

		uint32_t mLastTeleportFrame;
		qPropertySet* mpWritableProperties;
		qPropertySet* mpConstProperties;
		uint32_t mPrevNameHash;
		uint32_t mChildIndex;

		UFG_INLINE qPropertySet* GetPropertySet()
		{
			if (mpWritableProperties) {
				return mpWritableProperties;
			}

			return mpConstProperties;
		}

		/*
		* If 'mpWritableProperties' is nullptr, using this will create New PropertySet and append 'mpConstProperties'.
		* This is useful if we wanna modify some data.
		*/
		UFG_INLINE qPropertySet* GetWritableProperties()
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*)>(UFG_RVA(0x23E2F0))(this);
		}

		eSimObjectTypeEnum2 GetType()
		{
			qPropertySet* m_PropertySet = GetPropertySet();
			if (!m_PropertySet)
				return eSIM_OBJ_TYPE2_Invalid;

			qSymbol* m_TypeHash = m_PropertySet->GetSymbol(0x510C404C); // ObjectType
			switch (m_TypeHash ? *m_TypeHash : 0x0)
			{
			default: return eSIM_OBJ_TYPE2_Invalid;
			case 0x7B6A0689: return eSIM_OBJ_TYPE2_AIPathMarker;
			case 0x58DAEF8A: return eSIM_OBJ_TYPE2_AIJumpPoint;
			case 0x7C9CA7E3: return eSIM_OBJ_TYPE2_AIOutlineRegion;
			case 0x38DD7EFE: return eSIM_OBJ_TYPE2_AISeedPoint;
			case 0xA24EA7CA: return eSIM_OBJ_TYPE2_AudioEmitterMarker;
			case 0x278618B: return eSIM_OBJ_TYPE2_AudioTriggerRegion;
			case 0xF92D474D: return eSIM_OBJ_TYPE2_BoostRegion;
			case 0xDB0B6EC5: return eSIM_OBJ_TYPE2_Camera;
			case 0x2F962C69: return eSIM_OBJ_TYPE2_CameraMarker;
			case 0xB825B7BB: return eSIM_OBJ_TYPE2_Character;
			case 0x27691395: return eSIM_OBJ_TYPE2_Collectible;
			case 0xEF69DBBB: return eSIM_OBJ_TYPE2_CombatRegion;
			case 0xD4D7D5DD: return eSIM_OBJ_TYPE2_CopRoadBlock;
			case 0xB0EF2BAB: return eSIM_OBJ_TYPE2_Director;
			case 0x1946D26D: return eSIM_OBJ_TYPE2_Door;
			case 0x25504106: return eSIM_OBJ_TYPE2_DynamicLight;
			case 0x903AE4F8: return eSIM_OBJ_TYPE2_FleeToPoint;
			case 0x861E5147: return eSIM_OBJ_TYPE2_FXSimComponent;
			case 0x868843: return eSIM_OBJ_TYPE2_HidingSpot;
			case 0x1CDBE0A9: return eSIM_OBJ_TYPE2_HijackReturn;
			case 0x81A1E08A: return eSIM_OBJ_TYPE2_InterestPoint;
			case 0xEB604C0A: return eSIM_OBJ_TYPE2_IrradianceVolume;
			case 0x261DF63D: return eSIM_OBJ_TYPE2_Marker;
			case 0xACCF9D70: return eSIM_OBJ_TYPE2_MarkerProgressionTrigger;
			case 0x7AE3B440: return eSIM_OBJ_TYPE2_MarkerRaceStartingGrid;
			case 0xD5131A4E: return eSIM_OBJ_TYPE2_MeleeScriptSystem;
			case 0xA113AB1A: return eSIM_OBJ_TYPE2_ModelAsset;
			case 0x4C183A2: return eSIM_OBJ_TYPE2_NISScriptSystem;
			case 0x67FCE20C: return eSIM_OBJ_TYPE2_ParkingSpot;
			case 0x8C8D9A7B: return eSIM_OBJ_TYPE2_Prefab;
			case 0x8ED03A76: return eSIM_OBJ_TYPE2_Prop;
			case 0x86AA2526: return eSIM_OBJ_TYPE2_ReinforcementPoint;
			case 0x57F90554: return eSIM_OBJ_TYPE2_TrafficRegion;
			case 0xE1A54C5C: return eSIM_OBJ_TYPE2_TriggerRegion;
			case 0xAC9D9F10: return eSIM_OBJ_TYPE2_Turf;
			case 0x9B06086B: return eSIM_OBJ_TYPE2_Vehicle;
			case 0x8A5A95FC: return eSIM_OBJ_TYPE2_Weapon;
			case 0x28B63779: return eSIM_OBJ_TYPE2_WeaponSpawner;
			case 0xEF977909: return eSIM_OBJ_TYPE2_StartRegion;
			case 0xF9D450A8: return eSIM_OBJ_TYPE2_SpawnPoint;
			case 0x1A4E4099: return eSIM_OBJ_TYPE2_SpawnPointProgressionTrigger;
			case 0xDE552DA6: return eSIM_OBJ_TYPE2_SpawnRegion;
			}
		}
	};
}