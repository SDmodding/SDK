#pragma once

namespace UFG
{
	namespace StreamFileWrapper
	{
		UFG_INLINE bool FileExists(const char* p_szFileName)
		{
			return reinterpret_cast<bool(__fastcall*)(const char*)>(UFG_RVA(0x2290D0))(p_szFileName);
		}

		UFG_INLINE void* ReadEntireFile(const char* p_szFileName, int64_t* p_LoadedSize, UFG::CMemoryPool* p_MemoryPool = nullptr, uint32_t p_AllocFlags = 0, const char* p_DbgTag = reinterpret_cast<const char*>(UFG_RVA(0x167DBE0)))
		{
			return reinterpret_cast<void*(__fastcall*)(const char*, int64_t*, UFG::CMemoryPool*, uint32_t, const char*)>(UFG_RVA(0x22C7F0))(p_szFileName, p_LoadedSize, p_MemoryPool, p_AllocFlags, p_DbgTag);
		}

		static bool ReadAndOutputFile(const char* p_szFileName, const char* p_szOutputFile)
		{
			if (!FileExists(p_szFileName))
				return false;

			__int64 iSize = 0;
			void* pFileData = ReadEntireFile(p_szFileName, &iSize);
			if (!pFileData) {
				return false;
			}

			if (!iSize)
			{
				MemoryPool::GetMainPool()->Free(pFileData);
				return false;
			}

			FILE* pFile = nullptr;
			fopen_s(&pFile, p_szOutputFile, "wb");
			if (pFile)
			{
				fwrite(pFileData, sizeof(uint8_t), iSize, pFile);
				fclose(pFile);
			}

			MemoryPool::GetMainPool()->Free(pFileData);
			return true;
		}
	}
}