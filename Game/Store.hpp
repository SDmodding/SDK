#pragma once

namespace UFG
{
	class CStoreFrontTracker
	{
	public:
		CPropertySetHandle mProperties;

		static CStoreFrontTracker* Instance()
		{
			return reinterpret_cast<CStoreFrontTracker*>(UFG_RVA(0x2408280));
		}

		// 0 - Clothing | 1 - Vehicles | 2 - Boats
		void LoadStoreData(int p_InventoryType)
		{
			qSymbol m_InventoryTypes[3] = { 0x9773EC16, 0x9B06086B, 0xACB107F7 };
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x4AEFF0))(this, &m_InventoryTypes[p_InventoryType % 3]);
		}

		qPropertySet* FindItemSlow(qSymbol p_ItemName)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x4A0690))(this, &p_ItemName);
		}

		void ResetEquipment()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x4B6A50))(this);
		}
	};

	namespace StoreFront
	{
		void EquipItem(qPropertySet* p_Item, bool p_SaveToStats, bool p_RefreshPlayer, bool p_RemoveAnyPredefinedOutfit, bool p_UpdateLastEquipItem, bool p_Previewing)
		{
			reinterpret_cast<void(__fastcall*)(qPropertySet*, bool, bool, bool, bool, bool)>(UFG_RVA(0x49E860))(p_Item, p_SaveToStats, p_RefreshPlayer, p_RemoveAnyPredefinedOutfit, p_UpdateLastEquipItem, p_Previewing);
		}

		void EquipItem(qSymbol p_Item, bool p_SaveToStats, bool p_RefreshPlayer, bool p_RemoveAnyPredefinedOutfit, bool p_UpdateLastEquipItem, bool p_Previewing)
		{
			UFG::CStoreFrontTracker* m_StoreFrontTracker = CStoreFrontTracker::Instance();
			m_StoreFrontTracker->LoadStoreData(0);
			qPropertySet* m_ItemPropertySet = m_StoreFrontTracker->FindItemSlow(p_Item);
			if (m_ItemPropertySet)
				EquipItem(m_ItemPropertySet, p_SaveToStats, p_RefreshPlayer, p_RemoveAnyPredefinedOutfit, p_UpdateLastEquipItem, p_Previewing);
		}
	}

	namespace StoreMeshHelper
	{
		void CommitResource(CSimObject* p_SimObject, qPropertySet* p_PropertySet)
		{
			reinterpret_cast<void(__fastcall*)(CSimObject*, qPropertySet*)>(UFG_RVA(0x4A0690))(p_SimObject, p_PropertySet);
		}
	}
}