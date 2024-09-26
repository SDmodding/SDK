#pragma once

namespace UFG
{
	UFG_INLINE float qRandom(float p_Range, int* p_Seed = reinterpret_cast<int*>(UFG_RVA(0x203BC24)))
	{
		return reinterpret_cast<float(__fastcall*)(float, int*)>(UFG_RVA(0x189620))(p_Range, p_Seed);
	}

	UFG_INLINE __int64 DecompressLZ(void* p_Input, __int64 p_Length, void* p_Output, __int64 p_OutputLength)
	{
		return reinterpret_cast<__int64(__fastcall*)(void*, __int64, void*, __int64)>(UFG_RVA(0x183080))(p_Input, p_Length, p_Output, p_OutputLength);
	}

	//==================================================
	// Memory

	UFG_INLINE void* Malloc(uint64_t p_Size, const char* p_Name, uint64_t p_AllocationParams)
	{
		return reinterpret_cast<void*(__fastcall*)(unsigned __int64, const char*, unsigned __int64)>(UFG_RVA(0x187BE0))(p_Size, p_Name, p_AllocationParams);
	}

	template <typename T>
	UFG_INLINE T* Malloc(const char* p_Name, uint64_t p_AllocationParams)
	{
		return reinterpret_cast<T*>(Malloc(sizeof(T), p_Name, p_AllocationParams));
	}

	//==================================================
	// Malloc

	UFG_INLINE uint32_t DataHash32(void* p_Data, uint64_t p_NumBytes, uint32_t p_PrevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<uint32_t(__fastcall*)(void*, uint64_t, uint32_t)>(UFG_RVA(0x182B70))(p_Data, p_NumBytes, p_PrevHash);
	}

	UFG_INLINE uint32_t Hash32(const char* p_Str, uint32_t p_PrevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<uint32_t(__fastcall*)(const char*, uint32_t)>(UFG_RVA(0x18B680))(p_Str, p_PrevHash);
	}

	UFG_INLINE uint32_t HashUpper32(const char* p_Str, uint32_t p_PrevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<uint32_t(__fastcall*)(const char*, uint32_t)>(UFG_RVA(0x18B720))(p_Str, p_PrevHash);
	}

	UFG_INLINE uint64_t Hash64(const char* p_Str, uint64_t p_PrevHash = 0xFFFFFFFFFFFFFFFF)
	{
		return reinterpret_cast<uint64_t(__fastcall*)(const char*, uint64_t)>(UFG_RVA(0x18B6D0))(p_Str, p_PrevHash);
	}
}