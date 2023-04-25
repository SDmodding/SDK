#pragma once

namespace UFG
{
	class CPedSpawningInfo
	{
	public:
		UFG_PAD(0x70);

		CSimObject* mProxySimObjectPtr;

		UFG_PAD(0x48);

		CSimObject* mSimObjectPtr;

		void Reset(bool m_PreserveProxies = false)
		{
			reinterpret_cast<void(__fastcall*)(void*, bool)>(UFG_RVA(0x415820))(this, m_PreserveProxies);
		}

		void Unregister()
		{
			mProxySimObjectPtr = nullptr;
			mSimObjectPtr = nullptr;
			Reset();
		}
	};

	class CPedSpawnManager
	{
	public:
		void ReInitAmbient()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x413F20))(this);
		}

		CPedSpawningInfo* FindPedInfo(CSimObject* m_SimObject)
		{
			return reinterpret_cast<CPedSpawningInfo*(__fastcall*)(void*, CSimObject*)>(UFG_RVA(0x40B4E0))(this, m_SimObject);
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