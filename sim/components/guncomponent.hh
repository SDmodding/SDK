#pragma once

namespace UFG
{
	class GunComponent : public SimComponent, public qNode<GunComponent>
	{
	public:
		enum { _TypeUID = 0x9C000001 };

		struct ShootParams
		{
			u32 shootFlags;
			qSafePointer<SimObject> pShootOriginSimObject;
			qSymbolUC shootBoneId;
			qSafePointer<SimObject> pWeaponOwnerSimObject;
			AimingBaseComponent* pAimingC;
			SubTargetingLocation* pSubTargetingLocation;
		};

		u32 mNetShootSequence;
		qVector3 mNetBulletPosition;
		qVector3 mNetBulletVelocity;
		RebindingComponentHandle<SimObjectWeaponPropertiesComponent> mSimObjectWeaponPropertiesComponent;
		RebindingComponentHandle<InventoryItemComponent> mInventoryItemComponent;
		eTargetTypeEnum mMustHitTarget;
		int mClipAmmo[2];
		f32 mLastFiredTime;
		f32 mRateOfFireOverride;
		bool mIfResetAmmoOnDeath;
		ShootParams mShootParams;

		/* Static Functions */

		SDK_SINLINE bool HasComponent(SceneObjectProperties* pSceneObj) { return SDK_CALL_FUNC(bool, 0x5356A0, SceneObjectProperties*)(pSceneObj); }
		SDK_SINLINE GunComponent* PropertiesOnActivate(SceneObjectProperties* sceneObject) { return SDK_CALL_FUNC(GunComponent*, 0x544FE0, SceneObjectProperties*)(sceneObject); }

		/* Impl Functions */

		SDK_INLINE SimObjectWeaponPropertiesComponent* GetSimObjectWeaponPropertiesComponent() { return mSimObjectWeaponPropertiesComponent.GetComponent(); }

		SDK_INLINE int GetClipAmmo() { return mClipAmmo[GetSimObjectWeaponPropertiesComponent()->mFireMode]; }

		SDK_INLINE int GetClipCapacity()
		{ 
			auto weaponProperties = GetSimObjectWeaponPropertiesComponent();
			return weaponProperties->mWeaponTypeInfo->mFireModes[weaponProperties->mFireMode]->mAmmoClipCapacity;
		}

		SDK_INLINE bool IsStowable()
		{
			auto weaponProperties = GetSimObjectWeaponPropertiesComponent();
			return weaponProperties->mWeaponTypeInfo->mFireModes[weaponProperties->mFireMode]->mStowable;
		}

		SDK_INLINE void OverrideRateOfFire(bool bOverride, f32 fSecondsPerShot) { mRateOfFireOverride = (bOverride ? fSecondsPerShot : -1.f); }

		/* Functions */

		void AddClipOfAmmo() { SDK_CALL_FUNC(void, 0x520940, void*)(this); }
		bool CanFireWeapon(bool bIsAI) { return SDK_CALL_FUNC(bool, 0x522BE0, void*, bool)(this, bIsAI); }
		bool CanReload() { return SDK_CALL_FUNC(bool, 0x522C50, void*)(this); }
		int GetClipsRemaining() { return SDK_CALL_FUNC(int, 0x52B220, void*)(this); }
		int GetTotalAmmo() { return SDK_CALL_FUNC(int, 0x530B50, void*)(this); }
		void Initialize() { SDK_CALL_FUNC(void, 0x5392B0, void*)(this); }
		void InitializeGunIntoInventory() { SDK_CALL_FUNC(void, 0x539340, void*)(this); }
		void PlayReloadSFX() { SDK_CALL_FUNC(void, 0x5427C0, void*)(this); }
		void Reload(int amount) { SDK_CALL_FUNC(void, 0x548CA0, void*, int)(this, amount); }
		void ReloadFromInventory(int amount) { SDK_CALL_FUNC(void, 0x548D70, void*, int)(this, amount); }
		void RemoveGunFromInventory() { SDK_CALL_FUNC(void, 0x548FF0, void*)(this); }
		void SetAmmoForAIDeath() { SDK_CALL_FUNC(void, 0x54BC40, void*)(this); }
		void SetClipAmmo(int count) { SDK_CALL_FUNC(void, 0x54BF40, void*, int)(this, count); }
		void SetTotalAmmo(int count) { SDK_CALL_FUNC(void, 0x54F410, void*, int)(this, count); }

		bool Shoot(SimObject* pWeaponOwnerSimObject, AimingBaseComponent* pAimingC, u32 shootFlags, const SubTargetingLocation* pSubTargetingLocation, SimObject* pShootOriginSimObject, const qSymbolUC& originBoneId) {
			return SDK_CALL_FUNC(bool, 0x54F550, void*, SimObject*, AimingBaseComponent*, u32, const SubTargetingLocation*, SimObject*, const qSymbolUC&)(this, pWeaponOwnerSimObject, pAimingC, shootFlags, pSubTargetingLocation, pShootOriginSimObject, originBoneId);
		}

		bool Shoot(u32 shootFlags) { return SDK_CALL_FUNC(char, 0x54F520, void*, u32)(this, shootFlags); }
		void TransferAmmoFromGun(GunComponent* pFromGC) { SDK_CALL_FUNC(void, 0x556C50, void*, GunComponent*)(this, pFromGC); }
		void UpdateTransforms() { SDK_CALL_FUNC(void, 0x561340, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(GunComponent, 0x138);
}