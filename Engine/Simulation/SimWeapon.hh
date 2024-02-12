#pragma once

namespace UFG
{
	class CSimWeapon : public CSimObject
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
	};
}