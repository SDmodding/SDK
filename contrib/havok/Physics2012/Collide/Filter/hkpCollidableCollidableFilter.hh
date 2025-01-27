#pragma once

class hkpCollidableCollidableFilter
{
public:
	virtual ~hkpCollidableCollidableFilter() = 0;
	virtual hkBool isCollisionEnabled(const hkpCollidable& a, const hkpCollidable& b) const = 0;
};