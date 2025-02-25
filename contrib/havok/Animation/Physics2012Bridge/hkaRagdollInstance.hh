#pragma once

class hkaRagdollInstance : public hkReferencedObject
{
public:
	hkArray<hkpRigidBody*> m_rigidBodies;
	hkArray<hkpConstraintInstance*> m_constraints;
	hkArray<int> m_boneToRigidBodyMap;
	hkRefPtr<const hkaSkeleton> m_skeleton;
};