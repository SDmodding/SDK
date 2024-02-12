#pragma once

class hkpMoppCode : public hkReferencedObject
{
public:
	struct CodeInfo
	{
		hkVector4f m_offset;
	};

	CodeInfo m_info;
	hkArray<uint8_t> m_data;

	enum BuildType : int8_t
	{
		BUILT_WITH_CHUNK_SUBDIVISION = 0x0,
		BUILT_WITHOUT_CHUNK_SUBDIVISION = 0x1,
		BUILD_NOT_SET = 0x2,
	};
	BuildType m_buildType;
};