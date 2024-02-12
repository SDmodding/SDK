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

		CMemoryPool() 
		{ 
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x161710))(this); 
		}

		void Init(const char* p_Name, int64_t p_MemoryByteSize, int p_SmallBlockByteSize, int p_CanSmallBlockOverFlowIntoLargeBlock = 0, uint32_t p_InStatList = 1, CMemoryPool* p_OverFlowPool = nullptr, int p_PrintWarningOnOverflow = 1, bool p_InitializeAllocator = true)
		{
			reinterpret_cast<void(__fastcall*)(void*, const char*, int64_t, int, int, uint32_t, void*, int, bool)>(UFG_RVA(0x173370))(this, p_Name, p_MemoryByteSize, p_SmallBlockByteSize, p_CanSmallBlockOverFlowIntoLargeBlock, p_InStatList, p_OverFlowPool, p_PrintWarningOnOverflow, p_InitializeAllocator);
		}

		void* Allocate(uint64_t p_Size, const char* p_Name, uint64_t p_AllocationParams = 0, uint32_t p_CheckNull = 1)
		{
			return reinterpret_cast<void*(__fastcall*)(void*, uint64_t, const char*, uint64_t, uint32_t)>(UFG_RVA(0x166B60))(this, p_Size, p_Name, p_AllocationParams, p_CheckNull);
		}

		void Free(void* p_Ptr)
		{
			reinterpret_cast<void(__fastcall*)(void*, void*)>(UFG_RVA(0x16E720))(this, p_Ptr);
		}

		const char* GetName()
		{
			return reinterpret_cast<const char*(__fastcall*)(void*)>(UFG_RVA(0x1713C0))(this);
		}
	};

	namespace MemoryPool
	{
		CMemoryPool* GetMainPool()
		{
			return reinterpret_cast<CMemoryPool*>(UFG_RVA(0x22581A0));
		}

		CMemoryPool* GetSimulationPool()
		{
			return *reinterpret_cast<CMemoryPool**>(UFG_RVA(0x235C278));
		}

		CMemoryPool* GetScaleformPool()
		{
			return *reinterpret_cast<CMemoryPool**>(UFG_RVA(0x23F1B00));
		}

		qList<CMemoryPool>* GetList()
		{
			return reinterpret_cast<qList<CMemoryPool>*>(UFG_RVA(0x235B2D8));
		}

		CMemoryPool* FindByName(const char* m_Name)
		{
			qList<CMemoryPool>* m_List = GetList();
			for (qNode<CMemoryPool>* i = m_List->mNode.mNext; i != &m_List->mNode; i = i->mNext)
			{
				CMemoryPool* m_MemoryPool = i->GetPointer();
				const char* m_MemoryPoolName = m_MemoryPool->GetName();
				if (strcmp(m_MemoryPoolName, m_Name) == 0)
					return m_MemoryPool;
			}

			return nullptr;
		}
	}
}