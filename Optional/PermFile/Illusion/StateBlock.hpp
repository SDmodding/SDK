#pragma once

namespace Illusion
{
	struct StateBlock_t : UFG::ResourceData_t // TypeUID: 0xAF015A94 || ChunkUID: 0x4D04C7F2
	{
		UFG_PAD(0x10);

		uint32_t m_ParentUID;
		uint32_t m_DataByteSize;
		uint32_t m_NumValues;
		uint32_t m_StateUID;
	};
}