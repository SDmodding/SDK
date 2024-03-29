#pragma once

namespace Illusion
{
	namespace Factory
	{
		UFG_INLINE CMaterial* NewMaterial(const char* p_Name, uint32_t p_NameUID, uint32_t p_NumParams, class CMemImageSceham* p_Schema = nullptr, UFG::CMemoryPool* p_MemoryPool = nullptr, uint64_t p_AllocationParams = 0)
		{
			return reinterpret_cast<CMaterial*(__fastcall*)(const char*, uint32_t, uint32_t, void*, UFG::CMemoryPool*, uint64_t)>(UFG_RVA(0x92CB0))(p_Name, p_NameUID, p_NumParams, p_Schema, p_MemoryPool, p_AllocationParams);
		}

		UFG_INLINE CTexture* NewTexture(const char* p_Name, uint32_t p_NameUID, class CMemImageSceham* p_Schema = nullptr, UFG::CMemoryPool* p_MemoryPool = nullptr, uint64_t p_AllocationParams = 0)
		{
			return reinterpret_cast<CTexture*(__fastcall*)(const char*, uint32_t, void*, UFG::CMemoryPool*, uint64_t)>(UFG_RVA(0xA1D8A0))(p_Name, p_NameUID, p_Schema, p_MemoryPool, p_AllocationParams);
		}
	}
}