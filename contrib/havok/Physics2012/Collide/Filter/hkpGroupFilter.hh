#pragma once

class hkpGroupFilter : public hkpCollisionFilter
{
public:
	int m_nextFreeSystemGroup;
	u32 m_collisionLookupTable[32];
	hkVector4f m_pad256[4];
};