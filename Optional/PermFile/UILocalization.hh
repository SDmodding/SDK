#pragma once

namespace UFG
{
	struct UILocalization_t : ResourceData_t // TypeUID: 0x90CE6B7A
	{
		uint32_t m_ChunkSize;

		UFG_PAD(0x4);

		int64_t m_ChunkData;
		uint32_t m_SymbolsSize;
		uint32_t m_StringsSize;

		void* GetChunkPtr()
		{
			if (!m_ChunkData)
				return nullptr;

			return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(this) + sizeof(UILocalization_t));
		}

		char* GetStringPtr()
		{
			void* m_ChunkPtr = GetChunkPtr();
			if (!m_ChunkPtr)
				return nullptr;

			return &reinterpret_cast<char*>(m_ChunkPtr)[m_SymbolsSize];
		}

		uint32_t* GetSymbolsArray()
		{
			return reinterpret_cast<uint32_t*>(GetChunkPtr());
		}

		void GetMap(std::unordered_map<uint32_t, std::string>& m_Map)
		{
			char* m_StringPtr = GetStringPtr();
			if (!m_StringPtr)
				return;

			uint32_t* m_Symbols = GetSymbolsArray();
			if (!m_Symbols)
				return;

			uint32_t m_Index = 0;
			uint32_t m_StringOffset = 0;
			while (m_StringsSize > m_StringOffset)
			{
				char* m_String = &m_StringPtr[m_StringOffset];
				m_Map[m_Symbols[m_Index]] = m_String;

				++m_Index;
				m_StringOffset += (static_cast<uint32_t>(strlen(m_String)) + 1);
			}
		}
	};
}