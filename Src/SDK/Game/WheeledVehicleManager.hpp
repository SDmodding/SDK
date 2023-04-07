#pragma once

namespace UFG
{
	class CWheeledVehicleManager
	{
	public:
		void DestroyAllWheeledVehicles()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x64ADF0))(this);
		}

		static bool* TrafficSystemEnabled() { return reinterpret_cast<bool*>(UFG_RVA(0x2090514)); }
		static bool* UpdateTrafficRegionEnabled() { return reinterpret_cast<bool*>(UFG_RVA(0x2090515)); }
		static bool* TrafficCarSpawningEnabled() { return reinterpret_cast<bool*>(UFG_RVA(0x2090516)); }
		static bool* ParkedCarSpawningEnabled() { return reinterpret_cast<bool*>(UFG_RVA(0x2090517)); }
	};

	namespace WheeledVehicleManager
	{
		CWheeledVehicleManager* Get()
		{
			return *reinterpret_cast<CWheeledVehicleManager**>(UFG_RVA(0x2433B10));
		}
	}
}