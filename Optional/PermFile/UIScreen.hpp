#pragma once

namespace UFG
{
	struct UIScreen_t : ResourceData_t // TypeUID & ChunkUID: 0x442A39D9
	{
		uint32_t m_BufferSize;

		UFG_PAD(0x4);

		int64_t m_BufferDataOffset;

		void* GetBufferData()
		{
			return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(&m_BufferDataOffset) + m_BufferDataOffset);
		}
	};
}