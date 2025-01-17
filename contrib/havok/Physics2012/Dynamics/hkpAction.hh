#pragma once

class hkpAction : public hkReferencedObject
{
public:
	hkpWorld* m_world;
	hkpSimulationIsland* m_island;
	u64 m_userData;
	hkStringPtr m_name;
};