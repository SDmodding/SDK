#pragma once

namespace UFG
{
	// This mostly wrapped around (VirtualAlloc & VirtualFree)
	class MemoryPool
	{
	public:
		qNode<MemoryPool> mNode;
		unsigned int mInitializedUID = 0;
		void* mAutoAllocatedBuffer = nullptr;
		void* mData = nullptr;
		char mDataBuffer[9216] = { 0 };
		unsigned int mFlags = 0;
		bool mUsePageBasedStompFinder = false;
		char* mStart = nullptr;
		char* mEnd = nullptr;
		MemoryPool* mOverflowPool = nullptr;
		int mOverflowOccurred = 0;
		int mPrintWarningOnOverflow = 0;
		int mAmountOfSpilledMemory = 0;
		int mMaxAmountOfSpilledMemory = 0;
		int mNumActiveSpilledAllocs = 0;
		int mTotalSpilledAllocs = 0;

		MemoryPool() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x161710))(this); 
		}

		//===========================================================
		// Functions

		UFG_INLINE void Init(const char* p_Name, int64_t p_MemoryByteSize, int p_SmallBlockByteSize, int p_CanSmallBlockOverFlowIntoLargeBlock = 0, uint32_t p_InStatList = 1, MemoryPool* p_OverFlowPool = nullptr, int p_PrintWarningOnOverflow = 1, bool p_InitializeAllocator = true)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, int64_t, int, int, uint32_t, void*, int, bool)>(UFG_RVA(0x173370))(this, p_Name, p_MemoryByteSize, p_SmallBlockByteSize, p_CanSmallBlockOverFlowIntoLargeBlock, p_InStatList, p_OverFlowPool, p_PrintWarningOnOverflow, p_InitializeAllocator);
		}

		UFG_INLINE void* Allocate(uint64_t p_Size, const char* p_Name, uint64_t p_AllocationParams = 0, uint32_t p_CheckNull = 1)
		{
			return reinterpret_cast<void*(__fastcall*)(void*, uint64_t, const char*, uint64_t, uint32_t)>(UFG_RVA(0x166B60))(this, p_Size, p_Name, p_AllocationParams, p_CheckNull);
		}

		UFG_INLINE void Free(void* p_Ptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, void*)>(UFG_RVA(0x16E720))(this, p_Ptr);
		}

		UFG_INLINE const char* GetName()
		{
			return reinterpret_cast<const char*(__fastcall*)(void*)>(UFG_RVA(0x1713C0))(this);
		}

		//===========================================================
		// Static Functions

		UFG_STATIC_INLINE MemoryPool* GetMainPool()
		{
			return reinterpret_cast<MemoryPool*>(UFG_RVA(0x22581A0));
		}

		UFG_STATIC_INLINE MemoryPool* GetSimulationPool()
		{
			return *reinterpret_cast<MemoryPool**>(UFG_RVA(0x235C278));
		}

		UFG_STATIC_INLINE MemoryPool* GetScaleformPool()
		{
			return *reinterpret_cast<MemoryPool**>(UFG_RVA(0x23F1B00));
		}

		UFG_STATIC_INLINE qList<MemoryPool>* GetList()
		{
			return reinterpret_cast<qList<MemoryPool>*>(UFG_RVA(0x235B2D8));
		}

		UFG_STATIC_INLINE MemoryPool* FindByName(const char* m_Name)
		{
			qList<MemoryPool>* pList = GetList();
			for (qNode<MemoryPool>* i = pList->mNode.mNext; i != &pList->mNode; i = i->mNext)
			{
				MemoryPool* pMemoryPool = i->GetPointer();

				if (strcmp(pMemoryPool->GetName(), m_Name) == 0) {
					return pMemoryPool;
				}
			}

			return nullptr;
		}
	};
	typedef MemoryPool CMemoryPool;
}