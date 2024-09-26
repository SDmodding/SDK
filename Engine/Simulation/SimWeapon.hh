#pragma once

namespace UFG
{
	class SimWeapon : public SimObject
	{
	public:
		UFG_INLINE CGunComponent* GetGun()
		{
			return GetComponentOfType<CGunComponent>(WeaponGunComponent_TypeUID);
		}

		UFG_INLINE CSimWeaponPropertiesComponent* GetWeaponProperties()
		{
			return GetComponentOfType<CSimWeaponPropertiesComponent>(WeaponPropertiesComponent_TypeUID);
		}
	}; typedef SimWeapon CSimWeapon;
}