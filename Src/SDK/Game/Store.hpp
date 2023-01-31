#pragma once

namespace UFG
{
	class CStoreFrontTracker
	{
	public:
		CPropertySetHandle mProperties;

		// 0 - Clothing | 1 - Vehicles | 2 - Boats
		void LoadStoreData(int inventoryType)
		{
			qSymbol m_InventoryTypes[3] = { 0x9773EC16, 0x9B06086B, 0xACB107F7 };
			reinterpret_cast<void(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x4AEFF0))(this, &m_InventoryTypes[inventoryType]);
		}

		qPropertySet* FindItemSlow(qSymbol* itemName)
		{
			return reinterpret_cast<qPropertySet*(__fastcall*)(void*, qSymbol*)>(UFG_RVA(0x4A0690))(this, itemName);
		}
	};
	CStoreFrontTracker* StoreFrontTracker = reinterpret_cast<CStoreFrontTracker*>(UFG_RVA(0x2408280));

	namespace StoreFront
	{
		void EquipItem(qPropertySet* pItem, bool bSaveToStats, bool bRefreshPlayer, bool bRemoveAnyPredefinedOutfit, bool bUpdateLastEquipItem, bool bPreviewing)
		{
			reinterpret_cast<void(__fastcall*)(qPropertySet*, bool, bool, bool, bool, bool)>(UFG_RVA(0x49E860))(pItem, bSaveToStats, bRefreshPlayer, bRemoveAnyPredefinedOutfit, bUpdateLastEquipItem, bPreviewing);
		}
	}

	namespace StoreMeshHelper
	{
		void CommitResource(CSimObject* object, qPropertySet* pSet)
		{
			reinterpret_cast<void(__fastcall*)(CSimObject*, qPropertySet*)>(UFG_RVA(0x4A0690))(object, pSet);
		}
	}
}