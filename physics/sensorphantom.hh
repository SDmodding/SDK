#pragma once

namespace UFG
{
	class PhantomBase
	{
	public:
		virtual ~PhantomBase() = 0;
		virtual hkArray<class hkpCollidable*>* GetOverlappingCollidables() = 0;
		virtual void SetTransform(const qMatrix44& transform) = 0;
		virtual void GetExtents(qVector3& bmin, qVector3& bmax) = 0;
		virtual void SetExtents(const qVector3& bmin, const qVector3& bmax) = 0;
	};

	class SensorPhantom
	{
	public:
		enum PhantomType : i32
		{
			AABB_PHANTOM,
			SHAPE_PHANTOM
		};

		PhantomType mType;
		PhantomBase* mPhantom;

		virtual ~SensorPhantom() = 0;
	};

}