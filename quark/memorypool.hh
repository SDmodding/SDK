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
}