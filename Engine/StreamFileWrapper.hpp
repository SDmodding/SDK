#pragma once

namespace UFG
{
	namespace StreamFileWrapper
	{
		bool FileExists(const char* p_FileName)
		{
			return reinterpret_cast<bool(__fastcall*)(const char*)>(UFG_RVA(0x2290D0))(p_FileName);
		}

		void* ReadEntireFile(const char* p_FileName, int64_t* p_LoadedSize, UFG::CMemoryPool* p_MemoryPool = nullptr, uint32_t p_AllocFlags = 0, const char* p_DbgTag = reinterpret_cast<const char*>(UFG_RVA(0x167DBE0)))
		{
			return reinterpret_cast<void*(__fastcall*)(const char*, int64_t*, UFG::CMemoryPool*, uint32_t, const char*)>(UFG_RVA(0x22C7F0))(p_FileName, p_LoadedSize, p_MemoryPool, p_AllocFlags, p_DbgTag);
		}

		bool ReadAndOutputFile(const char* p_FileName, const char* p_OutputFile)
		{
			if (!FileExists(p_FileName))
				return false;

			__int64 m_Size = 0;
			void* m_Ptr = ReadEntireFile(p_FileName, &m_Size);
			if (!m_Ptr)
				return false;

			if (!m_Size)
			{
				gMainMemoryPool->Free(m_Ptr);
				return false;
			}

			FILE* m_File = fopen(p_OutputFile, "wb");
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