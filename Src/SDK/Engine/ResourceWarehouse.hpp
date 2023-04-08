#pragma once
#define FXEffectsInventory_UID		0xED341A8D
#define ModelDataInventory_UID		0xA2ADCD77
#define StateBlockInventory_UID		0x4D04C7F2

namespace UFG
{
	class CResourceWarehouse
	{
	public:
		qResourceInventory* GetInventory(unsigned int type_uid)
		{
			return reinterpret_cast<qResourceInventory*(__fastcall*)(void*, unsigned int)>(UFG_RVA(0x170B80))(this, type_uid);
		}

		qResourceInventory* GetFXEffectsInventory() { return GetInventory(FXEffectsInventory_UID); }

		qResourceInventory* GetModelDataInventory() { return GetInventory(ModelDataInventory_UID); }

		Illusion::CStateBlockInventory* GetStateBlockInventory() { return reinterpret_cast<Illusion::CStateBlockInventory*>(GetInventory(StateBlockInventory_UID)); }
	};
	CResourceWarehouse* ResourceWarehouse = reinterpret_cast<CResourceWarehouse*>(UFG_RVA(0x235B2F0));
}