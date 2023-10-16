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

class hkpReorientAction : public hkpUnaryAction
{
public:
	hkVector4f m_rotationAxis;
	hkVector4f m_upAxis;
	float m_strength;
	float m_damping;
};
