#pragma once

namespace UFG
{
	class SimComponent;
	class SimObjectWeaponPropertiesComponent;
	class SubTargetingLocation;

	class ProjectileInfo
	{
	public:
		qSafePointer<SimComponent, SimObjectWeaponPropertiesComponent> m_pSOWPC;
		SubTargetingLocation* m_pSubTargetingLocation;
		bool m_bIsFullyAccurate;
		bool m_bIsHardLocked;
	};
	SDK_ASSERT_SIZEOF(ProjectileInfo, 0x28);
}