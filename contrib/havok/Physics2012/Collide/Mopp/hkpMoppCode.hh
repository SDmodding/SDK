#pragma once

class hkpMoppCode : public hkReferencedObject
{
public:
	enum BuildType
	{
		BUILT_WITH_CHUNK_SUBDIVISION,
		BUILT_WITHOUT_CHUNK_SUBDIVISION,
		BUILD_NOT_SET
	};

	struct CodeInfo
	{
		hkVector4 m_offset;
	};

	hkpMoppCode::CodeInfo m_info;
	hkArray<u8, hkContainerHeapAllocator> m_data;
	hkEnum<BuildType, s8> m_buildType;
};
SDK_ASSERT_SIZEOF(hkpMoppCode, 0x40);