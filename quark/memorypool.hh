#pragma once

namespace UFG
{
	class qFixedAllocator
	{
	public:
		const char* mName;
		char* mBuffer;
		u32 mBufferSize;
		u32 mSlotSize;
		char* mFreeListHead;
		int mBufferWasAllocated;
		u32 mNumSlotsAllocated;
		u32 mMostSlotsAllocated;
	};
	SDK_ASSERT_SIZEOF(qFixedAllocator, 0x30);

	class qMemoryPoolData
	{
	public:
		allocator mAllocator;
	};

	class qMemoryPool : public qNode<qMemoryPool>
	{
	public:
		u32 mInitializedUID;
		void* mAutoAllocatedBuffer;
		qMemoryPoolData* mData;
		s8 mDataBuffer[9216];
		u32 mFlags;
		bool mUsePageBasedStompFinder;
		s8* mStart;
		s8* mEnd;
		qMemoryPool* mOverflowPool;
		int mOverflowOccurred;
		int mPrintWarningOnOverflow;
		int mAmountOfSpilledMemory;
		int mMaxAmountOfSpilledMemory;
		int mNumActiveSpilledAllocs;
		int mTotalSpilledAllocs;

		/* Functions */

		void* Allocate(u64 size, const char* name, u64 allocation_params, bool check_null) { 
			return SDK_CALL_FUNC(void*, 0x166B60, void*, u64, const char*, u64, bool)(this, size, name, allocation_params, check_null);
		}

		void* Realloc(void* mem, u64 size, const char* name, u64 allocation_params) {
			return SDK_CALL_FUNC(void*, 0x179A50, void*, void*, u64, const char*, u64)(this, mem, size, name, allocation_params);
		}

		void* Realloc(void* mem, u64 new_size, u64 old_size, const char* name, u64 allocation_params) {
			return SDK_CALL_FUNC(char*, 0x179900, void*, void*, u64, u64, const char*, u64)(this, mem, new_size, old_size, name, allocation_params);
		}

		void Free(void* ptr) { SDK_CALL_FUNC(void, 0x16E720, void*, void*)(this, ptr); }

		u64 Size(void* ptr) { return SDK_CALL_FUNC(u64, 0x17D3B0, void*, void*)(this, ptr); }

		SDK_INLINE const char* GetName() { return mData->mAllocator.mName; }

		u64 GetTotalFreeBytes() { return SDK_CALL_FUNC(u64, 0x172BD0, void*)(this); }

	};
	SDK_ASSERT_SIZEOF(qMemoryPool, 0x2460);

	/* Globals */

	SDK_VINLINE qGlobalPVar<qMemoryPool*, 0x2258190> gMainMemoryPool;
	SDK_VINLINE qGlobalVar<qList<qMemoryPool>*, 0x235B2D8> sMemoryPoolList;

	/* Functions */

	SDK_SINLINE void* qMalloc(u64 size, const char* name = "Global New", u64 allocation_params = 0) { 
		return SDK_CALL_FUNC(void*, 0x187BE0, u64, const char*, u64)(size, name, allocation_params);
	}

	SDK_SINLINE void qFree(void* ptr) { gMainMemoryPool->Free(ptr); }
}