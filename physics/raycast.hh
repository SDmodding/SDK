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
}