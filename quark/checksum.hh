#pragma once

namespace UFG
{
	SDK_INLINE u32 qDataHash32(const void* data, s64 num_bytes, u32 prevHash = -1) {
		return reinterpret_cast<u32(__fastcall*)(const void*, s64, u32)>(SDK_RVA(0x182B70))(data, num_bytes, prevHash);
	}

	SDK_INLINE u64 qDataHash64(const void* data, s64 num_bytes, u64 prevHash = -1) {
		return reinterpret_cast<u64(__fastcall*)(const void*, s64, u64)>(SDK_RVA(0x182BC0))(data, num_bytes, prevHash);
	}

	SDK_INLINE u32 qStringHash32(const char* str, u32 prevHash = -1) { 
		return reinterpret_cast<u32(__fastcall*)(const char*, u32)>(SDK_RVA(0x18B680))(str, prevHash);
	}

	SDK_INLINE u64 qStringHash64(const char* str, u64 prevHash = -1) {
		return reinterpret_cast<u64(__fastcall*)(const char*, u64)>(SDK_RVA(0x18B6D0))(str, prevHash);
	}

	SDK_INLINE u32 qStringHashUpper32(const char* str, u32 prevHash = -1) {
		return reinterpret_cast<u32(__fastcall*)(const char*, u32)>(SDK_RVA(0x18B720))(str, prevHash);
	}

	SDK_INLINE u64 qStringHashUpper64(const char* str, u64 prevHash = -1) {
		return reinterpret_cast<u64(__fastcall*)(const char*, u64)>(SDK_RVA(0x18B780))(str, prevHash);
	}

#ifdef SDK_CXX20

	//----------------------------------------------------------
	//	Compile-Time Helpers
	//----------------------------------------------------------

	consteval void cInitializeCRC32Table(u32* table)
	{
		for (u32 i = 0; 256 > i; ++i)
		{
			u32 crc = (i << 24);

			for (int j = 0; 8 > j; ++j)
			{
				if (crc & (1 << 31)) {
					crc = (crc << 1) ^ 0x04C11DB7;
				}
				else {
					crc = (crc << 1);
				}
			}

			table[i] = crc;
		}
	}

	consteval u32 cStringHash32(const char* str, u32 prevHash = -1)
	{
		uint32_t crcTable[256]; cInitializeCRC32Table(crcTable);
		for (const char* p = str; *p; ++p) {
			prevHash = (prevHash << 8) ^ crcTable[((prevHash >> 24) ^ *p) & 0xFF];
		}
		return prevHash;
	}

	consteval u32 cStringHashUpper32(const char* str, u32 prevHash = -1)
	{
		uint32_t crcTable[256]; cInitializeCRC32Table(crcTable);
		for (const char* p = str; *p; ++p)
		{
			char c = *p;
			prevHash = (prevHash << 8) ^ crcTable[((prevHash >> 24) ^ (c >= 'a' && c <= 'z' ? c - ('a' - 'A') : c)) & 0xFF];
		}
		return prevHash;
	}

#endif
}