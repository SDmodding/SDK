#pragma once

namespace UFG
{
	// Components
	class CGunComponent : public CSimComponent
	{
	public:
		UFG_PAD(0x10);

		unsigned int mNetShootSequence;
		qVector3 mNetBulletPosition;
		qVector3 mNetBulletVelocity;

		UFG_PAD(0x64);
		/*UFG::RebindingComponentHandle<UFG::SimObjectWeaponPropertiesComponent, 0> mSimObjectWeaponPropertiesComponent;
		UFG::RebindingComponentHandle<UFG::InventoryItemComponent, 0> mInventoryItemComponent;*/

		eTargetTypeEnum mMustHitTarget;
		int mClipAmmo[2];
		float mLastFiredTime;
		float mRateOfFireOverride;
		bool mIfResetAmmoOnDeath;

		//UFG::GunComponent::ShootParams mShootParams;

		int GetClipAmmo()
		{
			return reinterpret_cast<int(__fastcall*)(void*)>(UFG_RVA(0x52B1E0))(this);
		}

		int GetTotalAmmo()
		{
			return reinterpret_cast<int(__fastcall*)(void*)>(UFG_RVA(0x530B50))(this);
		}

		void SetClipAmmo(int count)
		{
			reinterpret_cast<void(__fastcall*)(void*, int)>(UFG_RVA(0x54BF40))(this, count);
		}

		void SetTotalAmmo(int count)
		{
			reinterpret_cast<void(__fastcall*)(void*, int)>(UFG_RVA(0x54F410))(this, count);
		}
	};

	// Main
	class CSimWeapon : public CSimObject
	{
	public:
		CGunComponent* GetGun()
		{
			CSimComponent* m_Component = nullptr;

			if ((m_Flags >> 14) & 1)
				m_Component = GetComponentOfTypeHK(WeaponGunComponent_TypeUID);
			else if ((m_Flags & 0x8000u) == 0)
			{
				if ((m_Flags >> 13) & 1 || (m_Flags >> 12) & 1)
					m_Component = GetComponentOfTypeHK(WeaponGunComponent_TypeUID);
				else
					m_Component = GetComponentOfType(CharacterActiveAIEntityComponent_TypeUID);
			}
			else
				m_Component = GetComponentOfTypeHK(WeaponGunComponent_TypeUID);

			return reinterpret_cast<CGunComponent*>(m_Component);
		}
	};
}