#pragma once

namespace UFG
{
	namespace StreamFileWrapper
	{
		void* ReadEntireFile(const char* filename, __int64* loaded_size, void* memory_pool = nullptr, unsigned int alloc_flags = 0, const char* dbg_tag = "StreamFileWrapper::ReadEntireFile")
		{
			return reinterpret_cast<void*(__fastcall*)(const char*, __int64*, void*, unsigned int, const char*)>(UFG_RVA(0x22C7F0))(filename, loaded_size, memory_pool, alloc_flags, dbg_tag);
		}
	}
}