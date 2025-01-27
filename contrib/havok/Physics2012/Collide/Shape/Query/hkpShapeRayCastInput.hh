#pragma once

struct hkpShapeRayCastInput
{
	hkVector4f m_from;
	hkVector4f m_to;
	u32 m_filterInfo;
	class hkpRayShapeCollectionFilter* m_rayShapeCollectionFilter;
	hkpCollidable* m_collidable;
	u64 m_userData;
};