#pragma once

namespace UFG
{
	__int64 DecompressLZ(void* input, __int64 input_length, void* output, __int64 output_length)
	{
		return reinterpret_cast<__int64(__fastcall*)(void*, __int64, void*, __int64)>(UFG_RVA(0x183080))(input, input_length, output, output_length);
	}

	uint32_t Hash32(const char* str, uint32_t prevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<unsigned int(__fastcall*)(const char*, unsigned int)>(UFG_RVA(0x18B680))(str, prevHash);
	}

	uint32_t HashUpper32(const char* str, uint32_t prevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<unsigned int(__fastcall*)(const char*, unsigned int)>(UFG_RVA(0x18B720))(str, prevHash);
	}
}