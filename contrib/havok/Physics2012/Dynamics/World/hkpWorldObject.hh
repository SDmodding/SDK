#pragma once

class hkpWorldObject : public hkReferencedObject
{
public:
	hkpWorld* m_world;
	u64 m_userData;
	hkpLinkedCollidable m_collidable;
	hkMultiThreadCheck m_multiThreadCheck;
	hkStringPtr m_name;
	hkArray<hkSimpleProperty, hkContainerHeapAllocator> m_properties;
};
SDK_ASSERT_SIZEOF(hkpWorldObject, 0xC8);