#pragma once

class hkpRayShapeCollectionFilter
{
public:
	virtual hkBool isCollisionEnabled(const hkpShapeRayCastInput& aInput, const hkpShapeContainer& bContainer, hkpShapeKey bKey) const = 0;
	virtual ~hkpRayShapeCollectionFilter() = 0;
};