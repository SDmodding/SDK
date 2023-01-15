#pragma once

namespace UFG
{
	unsigned int HashUpper32(const char* str, unsigned int prevHash = 0xFFFFFFFF)
	{
		return reinterpret_cast<unsigned int(__fastcall*)(const char*, unsigned int)>(UFG_RVA(0x18B720))(str, prevHash);
	}
}