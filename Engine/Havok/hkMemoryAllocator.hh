#pragma once

class hkMemoryAllocator
{
public:
	UFG_INLINE static hkMemoryAllocator* Instance()
	{
		return reinterpret_cast<hkMemoryAllocator*>(UFG_RVA(0x2173880)); // CustomHavokMemoryAllocator
	}

	UFG_INLINE void* BlockAlloc(int64_t p_NumBytes)
	{
		return reinterpret_cast<void*(__fastcall*)(void*, int64_t)>(UFG_RVA(0xB6710))(this, p_NumBytes);
	}

	template <typename T>
	UFG_INLINE T* BlockAlloc()
	{
		return reinterpret_cast<T*>(BlockAlloc(sizeof(T)));
	}
};