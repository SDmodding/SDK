#pragma once

class hkpPhysicsSystem : public hkReferencedObject
{
public:
	hkArray<class hkpRigidBody*> m_rigidBodies;
	hkArray<hkpConstraintInstance*> m_constraints;
	hkArray<hkpAction*> m_actions;
	hkArray<hkpPhantom*> m_phantoms;
	hkStringPtr m_name;
	u64 m_userData;
	hkBool m_active;

	~hkpPhysicsSystem() { SDK_CALL_FUNC(void, 0xD655B0, void*)(this); }

	void ctor() { SDK_CALL_FUNC(void, 0xD65530, void*)(this); }
};