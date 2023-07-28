#pragma once

namespace UFG
{
	namespace StreamFileWrapper
	{
		bool FileExists(const char* filename)
		{
			return reinterpret_cast<bool(__fastcall*)(const char*)>(UFG_RVA(0x2290D0))(filename);
		}

		void* ReadEntireFile(const char* filename, __int64* loaded_size, void* memory_pool = nullptr, unsigned int alloc_flags = 0, const char* dbg_tag = "StreamFileWrapper::ReadEntireFile")
		{
			return reinterpret_cast<void*(__fastcall*)(const char*, __int64*, void*, unsigned int, const char*)>(UFG_RVA(0x22C7F0))(filename, loaded_size, memory_pool, alloc_flags, dbg_tag);
		}

		bool ReadAndOutputFile(const char* m_FileName, const char* m_OutputFile)
		{
			if (!FileExists(m_FileName))
				return false;

			__int64 m_Size = 0;
			void* m_Ptr = ReadEntireFile(m_FileName, &m_Size);
			if (!m_Ptr)
				return false;

			if (!m_Size)
			{
				gMainMemoryPool->Free(m_Ptr);
				return false;
			}

			FILE* m_File = fopen(m_OutputFile, "wb");
			if (m_File)
			{
				fwrite(m_Ptr, sizeof(uint8_t), m_Size, m_File);
				fclose(m_File);
			}

			gMainMemoryPool->Free(m_Ptr);
			return true;
		}
	}
}