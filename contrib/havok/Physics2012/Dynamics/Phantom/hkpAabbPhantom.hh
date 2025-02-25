#pragma once

class hkpAabbPhantom : public hkpPhantom
{
public:
	hkAabb m_aabb;
	hkArray<hkpCollidable*> m_overlappingCollidables;
	hkBool m_orderDirty;
};