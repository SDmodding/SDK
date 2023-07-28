#pragma once
#define ActionTreeResourceInventory_UID			0x8DB8241B
#define FXEffectsInventory_UID					0xED341A8D
#define ModelDataInventory_UID					0xA2ADCD77
#define StateBlockInventory_UID					0x4D04C7F2
#define TextureInventory_UID					0x8B43FABF

namespace UFG
{
	class CResourceWarehouse
	{
	public:
		qBaseTreeRB mInventoryTree;
		qList<qResourceInventory> mInventoryList;
		qResourceInventory* mLastInventory;
		unsigned int mLastTypeUID;
		int mNumInventories;
		float mAddTime;
		float mRemoveTime;
		float mUnresolvedTime;
		float mLoadTime;
		float mUnloadTime;

		qResourceInventory* GetInventory(unsigned int type_uid)
		{
			return reinterpret_cast<qResourceInventory*(__fastcall*)(void*, unsigned int)>(UFG_RVA(0x170B80))(this, type_uid);
		}

		qResourceInventory* GetActionTreeResourceInventory() { return GetInventory(ActionTreeResourceInventory_UID); }

		qResourceInventory* GetFXEffectsInventory() { return GetInventory(FXEffectsInventory_UID); }

		qResourceInventory* GetModelDataInventory() { return GetInventory(ModelDataInventory_UID); }

		Illusion::CStateBlockInventory* GetStateBlockInventory() { return reinterpret_cast<Illusion::CStateBlockInventory*>(GetInventory(StateBlockInventory_UID)); }

		qResourceInventory* GetTextureInventory() { return GetInventory(TextureInventory_UID); }
	};
	CResourceWarehouse* ResourceWarehouse = reinterpret_cast<CResourceWarehouse*>(UFG_RVA(0x235B2F0));
}