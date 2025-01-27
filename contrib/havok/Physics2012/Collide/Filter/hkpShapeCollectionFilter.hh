#pragma once

class hkpShapeCollectionFilter
{
public:
	virtual hkBool isCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& bodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeB, hkpShapeKey keyB) const = 0;
	virtual hkBool isCollisionEnabled(const hkpCollisionInput& input, const hkpCdBody& collectionBodyA, const hkpCdBody& collectionBodyB, const hkpShapeContainer& containerShapeA, const hkpShapeContainer& containerShapeB, hkpShapeKey keyA, hkpShapeKey keyB) const = 0;
	virtual int numShapeKeyHitsLimitBreached(const hkpCollisionInput& input,
		const hkpCdBody& bodyA, const hkpCdBody& bodyB,
		const hkpBvTreeShape* bvTreeShapeB, hkAabb& aabb,
		hkpShapeKey* shapeKeysInOut,
		int shapeKeysCapacity) const = 0;
	virtual ~hkpShapeCollectionFilter() = 0;
};