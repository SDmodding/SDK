#pragma once

namespace UFG
{
	class qVRAMemoryHandle : public qNode<qVRAMemoryHandle>
	{
	public:
		char* mData;
		u16 mReadOnlyAndPoolID;
		u16 mBlockID;
	};

	class BlockInfo : public qNode<BlockInfo, class Primary>, qNode<BlockInfo, class Secondary>
	{
	public:
		qList<qVRAMemoryHandle> mAllocationHandles;
		s8* mData;
		const char* mName;
		u32 mRequestedSize;
		u32 mActualSize;
		u16 mBlockID;
		s8 mUsage;
		s8 mFlags;
		s8 mKeepAliveFrames;
		s8 mAlignmentShift;
		qMemoryPool* mMemoryPool;
		qList<BlockInfo> mContainedBlocks;
		u16 mContainerID;
		u16 mMoveSourceID;
		u64 mCallbackData64;
		u32 mCallbackData32;
	};
	SDK_ASSERT_SIZEOF(BlockInfo, 0x80);

	class qVRAMemoryPool : public qNode<qVRAMemoryPool>
	{
	public:
		qMutex mPoolLock;
		qVRAMemoryHandle mPoolMemory;
		char* mVRAMemoryStart;
		u32 mVRAMemorySize;
		qMemoryPool* mMainMemoryPool;
		qVRAMemoryPool* mOverflowVRAM;
		qMemoryPool* mOverflowMain;
		qList<BlockInfo> mUnusedBlocks;
		qList<BlockInfo> mMainMemoryBlocks;
		qList<BlockInfo> mUsedBlocks;
		qList<BlockInfo> mFreeList;
		qList<BlockInfo> mPendingFreeList;
		qList<BlockInfo> mMoveTargetsList;
		qList<BlockInfo> mContainerList;
		BlockInfo* mBlocks;
		char* mBlocksMemory;
		u32 mBlocksMemorySize;
		u16 mNumBlocksTotal;
		u32 mMinAlignment;
		u32 mFreeMemory;
		u32 mLargestFreeBlock;
		u32 mUsedMemory;
		u32 mPeakUsedMemory;
		u32 mAllocatedMemory;
		u32 mAlignmentLoss;
		u32 mUsedMainMemory;
		u16 mUsedBlocksCount;
		u16 mUsedBlocksMax;
		u16 mAllocatedBlocksCount;
		u16 mAllocatedBlocksMax;
		char mName[32];
		u16 mPoolID;
		u32 mDefragFreeFrameDelay;
		s8 mDefragAllowed;
		s8 mNeedsDefragmentUp;
		s8 mNeedsDefragmentDown;
		s8 mInitialized;
		const char mValidate;
	};
	SDK_ASSERT_SIZEOF(qVRAMemoryPool, 0x168);
}