#pragma once

namespace UFG
{
	class CWheeledVehicleManager
	{
	public:
		static UFG_INLINE CWheeledVehicleManager* Instance()
		{
			return *reinterpret_cast<CWheeledVehicleManager**>(UFG_RVA(0x2433B10));
		}

		UFG_INLINE void DestroyAllWheeledVehicles()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x64ADF0))(this);
		}

		static UFG_INLINE bool* TrafficSystemEnabled()
		{ 
			return reinterpret_cast<bool*>(UFG_RVA(0x2090514)); 
		}

		static UFG_INLINE bool* UpdateTrafficRegionEnabled()
		{ 
			return reinterpret_cast<bool*>(UFG_RVA(0x2090515)); 
		}

		static UFG_INLINE bool* TrafficCarSpawningEnabled()
		{
			return reinterpret_cast<bool*>(UFG_RVA(0x2090516)); 
		}

		static UFG_INLINE bool* ParkedCarSpawningEnabled()
		{
			return reinterpret_cast<bool*>(UFG_RVA(0x2090517)); 
		}
	};
}