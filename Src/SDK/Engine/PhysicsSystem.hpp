#pragma once

namespace UFG
{
	class CPhysicsSystem
	{
	public:
		void DisableCollisionsBetween(CSimObject* simObjectA, CSimObject* simObjectB)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*, CSimObject*)>(UFG_RVA(0x461A40))(this, simObjectA, simObjectB);
		}

		void ReEnableCollisionsBetween(CSimObject* simObjectA, CSimObject* simObjectB)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*, CSimObject*)>(UFG_RVA(0x4723A0))(this, simObjectA, simObjectB);
		}
	};

	namespace PhysicsSystem
	{
		CPhysicsSystem* Get()
		{
			return *reinterpret_cast<CPhysicsSystem**>(UFG_RVA(0x216B2C8));
		}
	}
}