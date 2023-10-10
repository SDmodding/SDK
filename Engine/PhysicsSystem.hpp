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
		void* vfptr;
		qTreeRB mCollisionModels;

		CRigidBodyComponent* OnCollisionInstanceAddedToWorld(CCollisionInstanceData* p_Instance, CCollisionMeshData* p_Mesh, uint32_t p_OnAddedFlags, uint32_t p_RigidBodyFlags, CSimObject* p_SimObject)
		{
			return reinterpret_cast<CRigidBodyComponent*(__fastcall*)(void*, CCollisionInstanceData*, CCollisionMeshData*, uint32_t, uint32_t, CSimObject*)>(UFG_RVA(0x46E150))(this, p_Instance, p_Mesh, p_OnAddedFlags, p_RigidBodyFlags, p_SimObject);
		}

		void AddRenderHelper(CSimObject* p_SimObject, CRigidBodyComponent* p_RigidBody, CCollisionInstanceData* p_Instance, CCollisionMeshData* p_Mesh)
		{
			reinterpret_cast<void(__fastcall*)(void*, CSimObject*, CRigidBodyComponent*, CCollisionInstanceData*, CCollisionMeshData*)>(UFG_RVA(0x455670))(this, p_SimObject, p_RigidBody, p_Instance, p_Mesh);
		}

		// return: true (it hit something)
		bool CastRay(RayCastData* data) 
		{
			return reinterpret_cast<bool(__fastcall*)(void*, RayCastData*)>(UFG_RVA(0xA1950))(this, data);
		}

		bool CastShape(CShapeCasterCollector* m_ShapeCasterCollector, qVector3 m_Start, qVector3 m_End)
		{
			return reinterpret_cast<bool(__fastcall*)(void*, CShapeCasterCollector*, qVector3*, qVector3*)>(UFG_RVA(0xA1DD0))(this, m_ShapeCasterCollector, &m_Start, &m_End);
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