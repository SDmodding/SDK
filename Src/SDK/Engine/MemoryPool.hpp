#pragma once

namespace UFG
{
	// This mostly wrapped around (VirtualAlloc & VirtualFree)
	class CMemoryPool
	{
	public:
		qNode<CMemoryPool> mNode;
		unsigned int mInitializedUID = 0;
		void* mAutoAllocatedBuffer = nullptr;
		void* mData = nullptr;
		char mDataBuffer[9216] = { 0 };
		unsigned int mFlags = 0;
		bool mUsePageBasedStompFinder = false;
		char* mStart = nullptr;
		char* mEnd = nullptr;
		CMemoryPool* mOverflowPool = nullptr;
		int mOverflowOccurred = 0;
		int mPrintWarningOnOverflow = 0;
		int mAmountOfSpilledMemory = 0;
		int mMaxAmountOfSpilledMemory = 0;
		int mNumActiveSpilledAllocs = 0;
		int mTotalSpilledAllocs = 0;

		CMemoryPool() { reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x161710))(this); }

		void Init(const char* name, int64_t memory_byte_size, int small_block_byte_size, int can_small_block_overflow_into_large_block = 0, unsigned int InStatList = 1, CMemoryPool* overflow_pool = nullptr, int printWarningOnOverflow = 1, bool bInitializeAllocator = true)
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
	CMemoryPool* gMainMemoryPool = reinterpret_cast<CMemoryPool*>(UFG_RVA(0x22581A0));
	qList<CMemoryPool>* gMemoryPoolList = reinterpret_cast<qList<CMemoryPool>*>(UFG_RVA(0x235B2D8));

	namespace MemoryPool
	{
		CMemoryPool* FindByName(const char* m_Name)
		{
			for (qNode<CMemoryPool>* i = gMemoryPoolList->mNode.mNext; i != &gMemoryPoolList->mNode; i = i->mNext)
			{
				CMemoryPool* m_MemoryPool = i->GetPointer();
				if (strcmp(m_MemoryPool->GetName(), m_Name) == 0)
					return m_MemoryPool;
			}

			return nullptr;
		}
	}
}