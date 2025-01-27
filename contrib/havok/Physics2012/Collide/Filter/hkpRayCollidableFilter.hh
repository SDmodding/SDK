#pragma once

class hkpRayCollidableFilter
{
public:
	virtual ~hkpRayCollidableFilter() = 0;
	virtual hkBool isCollisionEnabled(const hkpWorldRayCastInput& a, const hkpCollidable& collidableB) const = 0;
};