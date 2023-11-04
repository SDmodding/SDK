#pragma once

namespace UFG
{
	struct ResourceEntry_t
	{
		uint32_t m_TypeUID = 0x0;
		uint32_t m_EntrySize[2] = { 0x0, 0x0 };
		uint32_t m_Offset = 0x0;

		struct ResourceData_t* GetData()
		{
			if (m_Offset)
				return reinterpret_cast<struct ResourceData_t*>(reinterpret_cast<uintptr_t>(this) + m_Offset);

			return reinterpret_cast<struct ResourceData_t*>(this);
		}

		uint32_t GetEntrySize()
		{
			return (m_EntrySize[0] + sizeof(ResourceEntry_t));
		}

		void SetEntrySize(uint32_t p_Size)
		{
			m_EntrySize[0] = m_EntrySize[1] = (max(sizeof(ResourceEntry_t), p_Size) - sizeof(ResourceEntry_t));
		}
	};	

	struct ResourceData_t : ResourceEntry_t
	{
		UFG_PAD(0x18);

		uint32_t m_NameUID = 0x0;

		UFG_PAD(0x14);

		uint32_t m_ChunkUID = 0x0;

		char m_DebugName[36];
	};
}