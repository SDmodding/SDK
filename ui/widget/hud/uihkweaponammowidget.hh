#pragma once

namespace UFG
{
	class UIWeaponAmmoData
	{
	public:
		int ReserveAmmo;
		int ClipAmmo;
		int ClipCapacity;
		int Clips;
		int OldClips;
		int OldReserveAmmo;
		bool IsCamera;
		bool UnlimitedAmmo;
		eInventoryItemEnum InventoryItem;
		const char* IconTexture;
		const char* TexturePack;
		qSafePointer<SimComponent, GunComponent> mGunComponent;
	};

	class UIHKWeaponAmmoWidget
	{
	public:
		bool mVisible;
		bool mVisibleChanged;
		UIWeaponAmmoData mDisplayedWeapons[1];
		bool mTextureRefeshFlag;
		qString mTexturePack;
		qSafePointer<SimComponent, TargetingSystemBaseComponent> mTargetingSystemBaseComponent;
		qString mLastIconTexture;
		int mLastClipAmmo;
		bool mLastHasLowAmmo;
		bool mLastHasReserve;
		bool mLastHasStowedWeapon;
		bool mForceUpdate;
		bool mVehicleReloadPromptActive;
		f32 mEquipErrorTimer;

		/* Functions */

		void Flash_EquipError_SetVisible(UIScreen* screen, bool visible) { SDK_CALL_FUNC(void, 0x5DA8A0, void*, UIScreen*, bool)(this, screen, visible); }

		void Flash_SetAmmo(UIScreen* screen, const UIWeaponAmmoData& data, bool weaponChanged) {
			SDK_CALL_FUNC(void, 0x5DF200, void*, UIScreen*, const UIWeaponAmmoData&, bool)(this, screen, data, weaponChanged);
		}
		
		void Flash_SetWeapon(UIScreen* screen, const char* iconTexture, int clipAmmo) { SDK_CALL_FUNC(void, 0x5E1F90, void*, UIScreen*, const char*, int)(this, screen, iconTexture, clipAmmo); }
		
		bool GetWeaponImageInfo(eInventoryItemEnum iType, const char*& szTexturePack, const char*& szImageName) {
			return SDK_CALL_FUNC(bool, 0x5E9F50, eInventoryItemEnum, const char*&, const char*&)(iType, szTexturePack, szImageName);
		}

		void LoadWeaponTexture(const char* texturePack) { SDK_CALL_FUNC(void, 0x5F1B80, void*, const char*)(this, texturePack); }
		void Update(UIScreen* screen, f32 elapsed) { SDK_CALL_FUNC(void, 0x618760, void*, UIScreen*, f32)(this, screen, elapsed); }
	};
}