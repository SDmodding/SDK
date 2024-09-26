#pragma once

namespace UFG
{
	class CGunComponent : public SimComponent
	{
	public:
		UFG_PAD(0x10);

		uint32_t mNetShootSequence;
		qVector3 mNetBulletPosition;
		qVector3 mNetBulletVelocity;

		UFG_PAD(0x4);

		RebindingComponentHandle<CSimWeaponPropertiesComponent> mSimObjectWeaponPropertiesComponent;
		RebindingComponentHandle<class CInventoryItemComponent> mInventoryItemComponent;

		eTargetTypeEnum mMustHitTarget;
		int mClipAmmo[2];
		float mLastFiredTime;
		float mRateOfFireOverride;
		bool mIfResetAmmoOnDeath;

		//UFG::GunComponent::ShootParams mShootParams;

		void SetClipAmmo(int p_Count) // .text:000000014054BF40
		{
			if (0 > p_Count) {
				p_Count = 0;
			}

			CSimWeaponPropertiesComponent* _SimWeaponPropertes = this->mSimObjectWeaponPropertiesComponent.m_pSimComponent;
			int _AmmoClipCapacity = _SimWeaponPropertes->mWeaponTypeInfo->mFireModes[_SimWeaponPropertes->mFireMode]->mAmmoClipCapacity;
			this->mClipAmmo[_SimWeaponPropertes->mFireMode] = (_AmmoClipCapacity > p_Count ? p_Count : _AmmoClipCapacity);
		}

		UFG_INLINE int GetClipAmmo()
		{
			return this->mClipAmmo[this->mSimObjectWeaponPropertiesComponent.m_pSimComponent->mFireMode];
		}

		UFG_INLINE void SetTotalAmmo(int p_Count)
		{
			reinterpret_cast<void(__fastcall*)(void*, int)>(UFG_RVA(0x54F410))(this, p_Count);
		}

		UFG_INLINE int GetTotalAmmo()
		{
			return reinterpret_cast<int(__fastcall*)(void*)>(UFG_RVA(0x530B50))(this);
		}
	};
}