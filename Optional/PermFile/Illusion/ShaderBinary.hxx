#pragma once

namespace Illusion
{

	struct ShaderBinary_t : UFG::ResourceData_t // TypeUID: 0x985BE50C || ChunkUID: 0xE80F42E1
	{
		enum eStageType : uint32_t
		{
			STAGE_VERTEX = 0x0,
			STAGE_PIXEL = 0x1,
			STAGE_COMPUTE = 0x2,
			STAGE_GEOMETRY = 0x3,
			STAGE_HULL = 0x4,
			STAGE_DOMAIN = 0x5,
			MAX_STAGES = 0x6,
			STAGE_INVALID = 0x63,
		};

		uint32_t m_DataByteSize;
		eStageType m_ShaderStageType;
		int64_t m_DataOffset;
		char m_ShaderName[52];
	};
}