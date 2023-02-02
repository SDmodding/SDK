#pragma once

namespace UFG
{
	struct RayCastData
	{
		UFG_PAD(0x90);
		/*hkpWorldRayCastInput mInput;
		hkpWorldRayCastOutput mOutput;*/

		const char* mDebugName;
		qSymbol mCollisionModelName;
		qVector3 point;
		qVector3 normal;
		float t;
		hkpRigidBody* mHavokRigidBody;
		void* mHavokPhantom;
		bool hit;
		unsigned __int64 mPhysicsObjectPropertyHandleUid;
		unsigned __int64 mPhysicsSurfacePropertyHandleUid;

		RayCastData(qVector3 m_Start, qVector3 m_End, uint32_t m_CollisionFilter)
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x99880))(this); // Initializor
			reinterpret_cast<void(__fastcall*)(void*, qVector3*, qVector3*, uint32_t)>(UFG_RVA(0xAC0E0))(this, &m_Start, &m_End, m_CollisionFilter); // Init
		}
	};

	class CPhysicsSystem
	{
	public:
		// return: true (it hit something)
		bool CastRay(RayCastData* data) 
		{
			return reinterpret_cast<bool(__fastcall*)(void*, RayCastData*)>(UFG_RVA(0xA1950))(this, data);
		}

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