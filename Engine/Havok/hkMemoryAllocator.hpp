#pragma once

class hkMemoryAllocator
{
public:
	static hkMemoryAllocator* Instance()
	{
		return reinterpret_cast<hkMemoryAllocator*>(UFG_RVA(0x2173880)); // CustomHavokMemoryAllocator
	}

	void* BlockAlloc(int64_t p_NumBytes)
	{
		return reinterpret_cast<void*(__fastcall*)(void*, int64_t)>(UFG_RVA(0xB6710))(this, p_NumBytes);
	}
};