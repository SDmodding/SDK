#pragma once

class hkMemoryAllocator
{
public:
	void* BlockAlloc(int64_t p_NumBytes)
	{
		return reinterpret_cast<void*(__fastcall*)(void*, int64_t)>(UFG_RVA(0xB6710))(this, p_NumBytes);
	}
};
hkMemoryAllocator* g_HavokMemoryAllocator = reinterpret_cast<hkMemoryAllocator*>(UFG_RVA(0x2173880)); // CustomHavokMemoryAllocator