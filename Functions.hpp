#pragma once

namespace UFG
{
	__int64 DecompressLZ(void* input, __int64 input_length, void* output, __int64 output_length)
	{
		return reinterpret_cast<__int64(__fastcall*)(void*, __int64, void*, __int64)>(UFG_RVA(0x183080))(input, input_length, output, output_length);
	}

	void* Malloc(unsigned __int64 m_Size, const char* m_Name, unsigned __int64 m_AllocationParams)
	{
		return reinterpret_cast<void*(__fastcall*)(unsigned __int64, const char*, unsigned __int64)>(UFG_RVA(0x187BE0))(m_Size, m_Name, m_AllocationParams);
	}

	uint32_t DataHash32(void* p_Data, uint64_t p_NumBytes, uint32_t p_PrevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<uint32_t(__fastcall*)(void*, uint64_t, uint32_t)>(UFG_RVA(0x182B70))(p_Data, p_NumBytes, p_PrevHash);
	}

	uint32_t Hash32(const char* p_Str, uint32_t p_PrevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<uint32_t(__fastcall*)(const char*, uint32_t)>(UFG_RVA(0x18B680))(p_Str, p_PrevHash);
	}

	uint32_t HashUpper32(const char* p_Str, uint32_t p_PrevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<uint32_t(__fastcall*)(const char*, uint32_t)>(UFG_RVA(0x18B720))(p_Str, p_PrevHash);
	}

	uint64_t Hash64(const char* p_Str, uint64_t p_PrevHash = 0xFFFFFFFFFFFFFFFF)
	{
		return reinterpret_cast<uint64_t(__fastcall*)(const char*, uint64_t)>(UFG_RVA(0x18B6D0))(p_Str, p_PrevHash);
	}
}