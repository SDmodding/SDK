#pragma once

class hkaSkeleton : public hkReferencedObject
{
public:
	const char* m_name;
	hkArray<short> m_parentIndices;
	hkArray<class hkaBone> m_bones;
	hkArray<void*> m_referencePose;
	hkArray<float> m_referenceFloats;
	hkArray<const char*> m_floatSlots;
	hkArray<void*> m_localFrames;
	hkArray<void*> m_partitions;

	UFG_INLINE int GetNumBones()
	{
		return m_bones.m_size;
	}
};