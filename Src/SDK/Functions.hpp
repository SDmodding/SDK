#pragma once

namespace UFG
{
	uint32_t Hash32(const char* str, uint32_t prevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<unsigned int(__fastcall*)(const char*, unsigned int)>(UFG_RVA(0x18B680))(str, prevHash);
	}

	uint32_t HashUpper32(const char* str, uint32_t prevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<unsigned int(__fastcall*)(const char*, unsigned int)>(UFG_RVA(0x18B720))(str, prevHash);
	}
}