#pragma once

class hkpAction : public hkReferencedObject
{
public:
	class hkpWorld* m_world;
	class hkpSimulationIsland* m_island;
	uint64_t m_userData;
	const char* m_name;
};

class hkpUnaryAction : public hkpAction
{
public:
	hkpEntity* m_entity;
};