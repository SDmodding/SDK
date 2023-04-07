#pragma once

namespace UFG
{
	class CPedSpawnManager
	{
	public:
		void ReInitAmbient()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x413F20))(this);
		}

		static bool* AmbientSpawningEnable() { return reinterpret_cast<bool*>(UFG_RVA(0x207AE69)); }
		static bool* AmbientStatusCheckEnable() { return reinterpret_cast<bool*>(UFG_RVA(0x207AE6A)); }
		static bool* ScriptedStatusCheckEnable() { return reinterpret_cast<bool*>(UFG_RVA(0x207AE6B)); }
		static int* CheckStatusMode() { return reinterpret_cast<int*>(UFG_RVA(0x207AE6C)); }
		static bool* ResourcesSuspended() { return reinterpret_cast<bool*>(UFG_RVA(0x23DE286)); }
	};

	namespace PedSpawnManager
	{
		CPedSpawnManager* Get()
		{
			return *reinterpret_cast<CPedSpawnManager**>(UFG_RVA(0x23DC610));
		}
	}
}