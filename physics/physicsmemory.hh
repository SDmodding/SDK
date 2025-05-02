#pragma once

class HavokJobMemoryPoolTagger : public hkExternalJobProfiler
{
public:
};

class CustomHavokMemoryAllocator : public hkMemoryAllocator
{
public:
	UFG::qMemoryPool* m_pools[4];
	void* mRigidBodyBuffer;

	/* Static Functions */

	SDK_SINLINE CustomHavokMemoryAllocator* Instance() { SDK_VAR(CustomHavokMemoryAllocator*, 0x2173880); }
};
