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
}