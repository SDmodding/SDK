#pragma once

class hkpRayShapeCollectionFilter
{
public:
	void* vfptr;
};

class hkpWorldRayCastInput
{
public:
	hkVector4f m_from;
	hkVector4f m_to;
	bool m_enableShapeCollectionFilter = false;
	uint32_t m_filterInfo = 0;
	uint64_t m_userData = 0;

	hkpWorldRayCastInput() { }
	hkpWorldRayCastInput(UFG::qVector3 m_Start, UFG::qVector3 m_End, uint32_t m_CollisionFilter)
	{
		m_from.Set(m_Start.x, m_Start.y, m_Start.z, 0.f);
		m_to.Set(m_End.x, m_End.y, m_End.z, 0.f);
		m_enableShapeCollectionFilter = true;
		m_filterInfo = m_CollisionFilter;
	}
};

class hkpShapeRayCastInput
{
public:
	hkVector4f m_from;
	hkVector4f m_to;
	uint32_t m_filterInfo = 0;
	hkpRayShapeCollectionFilter* m_rayShapeCollectionFilter = nullptr;
	hkpCollidable* m_collidable = nullptr;
	uint64_t m_userData = 0;

	hkpShapeRayCastInput() { }
	hkpShapeRayCastInput(UFG::qVector3 m_Start, UFG::qVector3 m_End, uint32_t m_CollisionFilter)
	{
		m_from.Set(m_Start.x, m_Start.y, m_Start.z, 0.f);
		m_to.Set(m_End.x, m_End.y, m_End.z, 0.f);
		m_filterInfo = m_CollisionFilter;
	}
};

class hkpShapeRayCastCollectorOutput
{
public:
	hkVector4f m_normal;
	float m_hitFraction;
	int m_extraInfo;
	int m_pad[2];
};

class hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
{
public:
	unsigned int m_shapeKeys[8];
	int m_shapeKeyIndex;
};

class hkpWorldRayCastOutput : public hkpShapeRayCastOutput
{
public:
	hkpCollidable* m_rootCollidable = nullptr;
};
