#pragma once

namespace UFG
{
	class ComponentTypeEntry
	{
	public:
		u32 uid;
	};

	class SimObjectGame : public SimObject
	{
	public:
		u32 mComponentTableEntryCount;
		ComponentTypeEntry* mComponentTableEntries;

		/* Functions */

		template <typename T = SimComponent>
		T* GetComponentOfTypeHK(u32 type_uid) { return reinterpret_cast<T*(SDK_CALL*)(void*, u32)>(SDK_RVA(0x52BBC0))(this, type_uid); }
	};
	SDK_ASSERT_SIZEOF(SimObjectGame, 0x90);

	class SimObjectCVBase : public SimObjectGame
	{
	public:
	};

	class SimObjectCharacter : public SimObjectCVBase
	{
	public:
	};

	class SimObjectVehicle : public SimObjectCVBase
	{
	public:
	};
}