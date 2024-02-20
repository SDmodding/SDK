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

	UFG_INLINE void Constructor(hkpRigidBody* p_Body, const hkVector4f& p_RotationAxis, const hkVector4f& p_UpAxis, float p_Strength, float p_Damping)
	{
		reinterpret_cast<void(__fastcall*)(void*, hkpRigidBody*, const hkVector4f&, const hkVector4f&, float, float)>(UFG_RVA(0xE13020))(this, p_Body, p_RotationAxis, p_UpAxis, p_Strength, p_Damping);
	}
};
