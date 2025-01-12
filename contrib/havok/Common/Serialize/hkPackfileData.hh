#pragma once

class hkPackfileData : public hkResource
{
public:
	struct Chunk
	{
		void* pointer;
		int numBytes;
		HK_MEMORY_CLASS memClass;
	};

	void* m_topLevelObject;
	char* m_name;
	hkPointerMap<void*, char const*> m_trackedObjects;
	hkStringMap<hkTypeInfo const*> m_trackedTypes;
	hkRefPtr<hkClassNameRegistry const> m_packfileClassRegistry;
	u32 m_destructorsEnabled;
	hkArray<void*> m_memory;
	hkArray<Chunk> m_chunks;
	hkArray<hkResource::Export> m_exports;
	hkArray<hkResource::Import> m_imports;
	hkArray<hkVariant> m_postFinishObjects;
};
SDK_ASSERT_SIZEOF(hkPackfileData, 0xA8);