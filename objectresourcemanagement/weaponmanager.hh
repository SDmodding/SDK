#pragma once

namespace UFG
{
	class WeaponManager
	{
	public:
		struct WeaponEntry
		{
			f32 mScore;
			f32 mSpawnTime;
			f32 mTimeAlive;
			f32 mDistFromPlayer;
			bool mEquipped;
			qSafePointer<SimObjectWeaponPropertiesComponent> mComponent;
		};

		qArray<WeaponEntry> mElements;

		/* Static Members */

		SDK_VINLINE qGlobalVar<u32, 0x2081290> sMaxWeaponElements;
		SDK_VINLINE qGlobalVar<u32, 0x2081294> sSoftContractionCount;
		SDK_VINLINE qGlobalVar<u32, 0x2081298> sHardContractionCount;
		SDK_VINLINE qGlobalVar<f32, 0x208129C> sSoftContractionMinDist;
		SDK_VINLINE qGlobalVar<f32, 0x20812A0> sTimeAliveScoreMultiplier;
		SDK_VINLINE qGlobalVar<f32, 0x20812A4> sDistanceScoreMultiplier;
		SDK_VINLINE qGlobalVar<f32, 0x20812A8> sNoAmmoMultiplier;

		/* Static Functions */

		SDK_SINLINE WeaponManager* Instance() { return SDK_VAR_GET(WeaponManager*, 0x2401618); }
		SDK_SINLINE void CleanUpFreeWeapons(bool in_view) { SDK_CALL_FUNC(void, 0x43A780, void*, bool)(0, in_view); }

		/* Functions */

		void AddWeapon(SimObjectWeaponPropertiesComponent* weapon) { SDK_CALL_FUNC(void, 0x438920, void*, SimObjectWeaponPropertiesComponent*)(this, weapon); }
		void DoCleanUp() { SDK_CALL_FUNC(void, 0x43BB70, void*)(this); }

		/* Elements Functions */

		void FastDelete(u32 index) { SDK_CALL_FUNC(void, 0x43CAE0, void*, u32)(&mElements, index); }
		void Reallocate(u32 newsize, const char* reason) { SDK_CALL_FUNC(void, 0x4412F0, void*, u32, const char*)(&mElements, newsize, reason); }
		void StableDelete(u32 index) { SDK_CALL_FUNC(void, 0x443480, void*, u32)(&mElements, index); }
	};
}