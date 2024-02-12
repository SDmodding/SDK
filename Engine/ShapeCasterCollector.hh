#pragma once

namespace UFG
{
	class CShapeCasterCollector
	{
	public:
		void* vfptr;

		struct HitInfo_t
		{
			qNode<HitInfo_t> mNode;
			qVector3 mContactPosition;
			qVector3 mContactNormal;
			void* mRigidBody;
			void* mCollidableA;
			uint32_t mShapeKeyA;
			hkpCollidable* mCollidableB;
			uint32_t mShapeKeyB;
			CSimObject* mSimObject;
			uint64_t mPhysicsObjectPropertyHandleUID;
			uint64_t mPhysicsSurfacePropertyHandleUID;
		};
		qList<HitInfo_t> mHitList;

		void* mPhantom;
		hkpShape* mShape;
		float mRadius;

		~CShapeCasterCollector()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x9D2D0))(this);
		}

		CShapeCasterCollector(float m_Radius, uint32_t m_CollisionFilter, int m_SimpleOrCached = 0)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, uint32_t, int)>(UFG_RVA(0x99E30))(this, m_Radius, m_CollisionFilter, m_SimpleOrCached);
		}
	};
}