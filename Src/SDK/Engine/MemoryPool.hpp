#pragma once

namespace UFG
{
	// This mostly wrapped around (VirtualAlloc & VirtualFree)
	class CMemoryPool
	{
	public:
		UFG_PAD(0x2460);

		CMemoryPool() {}
		CMemoryPool(const char* name, int64_t memory_byte_size, int small_block_byte_size, int can_small_block_overflow_into_large_block = 0, unsigned int InStatList = 1, void* overflow_pool = nullptr, int printWarningOnOverflow = 1, bool bInitializeAllocator = true)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, int64_t, int, int, unsigned int, void*, int, bool)>(UFG_RVA(0x173370))(this, name, memory_byte_size, small_block_byte_size, can_small_block_overflow_into_large_block, InStatList, overflow_pool, printWarningOnOverflow, bInitializeAllocator);
		}

		void* Allocate(uint64_t m_Size, const char* m_Name, uint64_t m_AllocationParams = 0, uint32_t m_CheckNull = 1)
		{
			return reinterpret_cast<void*(__fastcall*)(void*, uint64_t, const char*, uint64_t, uint32_t)>(UFG_RVA(0x166B60))(this, m_Size, m_Name, m_AllocationParams, m_CheckNull);
		}

		void Free(void* m_Ptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, void*)>(UFG_RVA(0x16E720))(this, m_Ptr);
		}

		const char* GetName()
		{
			return reinterpret_cast<const char*(__fastcall*)(void*)>(UFG_RVA(0x1713C0))(this);
		}
	};
}