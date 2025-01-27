#pragma once

namespace UFG
{
	class ShapeCasterCollector
	{
	public:
		enum HitFlag
		{
			HitFlag_First,
			HitFlag_Multiple,
			HitFlag_All
		};

		struct HitInfo : qNode<HitInfo>
		{
			qVector3 mContactPosition;
			qVector3 mContactNormal;
			hkpRigidBody* mRigidBody;
			hkpCollidable* mCollidableA;
			u32 mShapeKeyA;
			hkpCollidable* mCollidableB;
			u32 mShapeKeyB;
			SimObject* mSimObject;
			u64 mPhysicsObjectPropertyHandleUID;
			u64 mPhysicsSurfacePropertyHandleUID;
		};

		qList<HitInfo> mHitList;
		hkpShapePhantom* mPhantom;
		hkpShape* mShape;
		f32 mRadius;

		/* Virtual Functions */

		virtual ~ShapeCasterCollector() = 0;
		//virtual void AddHit(const hkpRootCdPoint& pt, bool oneHitPerRigidBody) = 0;
	};

	class AsyncShapeCasterCollector : public ShapeCasterCollector
	{
	public:
		hkVector4f m_from;
		hkVector4f m_to;
		void(__fastcall* mShapecastCallback)(AsyncShapeCasterCollector*);
		hkpLinearCastInput mInput;
		hkpRootCdPoint mOutput;
		int mJobID;
		bool mHit;
	};

	class CastData
	{
	public:
		qSafePointer<SimComponent> simComponent;
		void* callbackUserData;
	};

	class RayCastData
	{
	public:
		hkpWorldRayCastInput mInput;
		hkpWorldRayCastOutput mOutput;
		const char* mDebugName;
		qSymbol mCollisionModelName;
		qVector3 point;
		qVector3 normal;
		f32 t;
		hkpRigidBody* mHavokRigidBody;
		hkpPhantom* mHavokPhantom;
		bool hit;
		u64 mPhysicsObjectPropertyHandleUid;
		u64 mPhysicsSurfacePropertyHandleUid;

		RayCastData() { SDK_CALL_FUNC(void, 0x99880, void*)(this); }

		/* Functions */

		void Init(const qVector3& rayStart, const qVector3& rayEnd, u32 collisionFilter) {
			SDK_CALL_FUNC(void, 0xAC0E0, void*, const qVector3&, const qVector3&, u32)(this, rayStart, rayEnd, collisionFilter);
		}
		void Init(const hkVector4f& rayStart, const hkVector4f& rayEnd, u32 collisionFilter) {
			SDK_CALL_FUNC(void, 0xAC0B0, void*, const hkVector4f&, const hkVector4f&, u32)(this, rayStart, rayEnd, collisionFilter);
		}
	};

	class AsyncRayCastData : public RayCastData, public CastData
	{
	public:
		void(__fastcall* raycastCallback)(RayCastData*, SimComponent*, void*);

		AsyncRayCastData() { SDK_CALL_FUNC(void, 0x969F0, void*)(this); }
		~AsyncRayCastData() { SDK_CALL_FUNC(void, 0x9B430, void*)(this); }
	};
}