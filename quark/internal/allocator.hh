#pragma once

namespace UFG
{
	class intrusive_multi_rbtree_base
	{
	public:
		struct node_base
		{
			node_base* mChildren[2];
			node_base* mNeighbours[2];
			node_base* mParent;
		};

		node_base mHead;
	};

	template <typename T>
	class intrusive_multi_rbtree : public intrusive_multi_rbtree_base 
	{
	public:
		struct node : intrusive_multi_rbtree_base::node_base {};
	};

	//--------------------------------------------------------------------------------
	//	Allocator
	//--------------------------------------------------------------------------------

	class allocator
	{
	public:
		enum system_mode : s32
		{
			ACTIVE_REGION_MGT = (1 << 0),
			INFLATED = (1 << 1),
			SPAWNED_FROM_STREAMED_GEO = (1 << 2),
			RESOURCE_UNLOADED = (1 << 3),
			JUST_SPAWNED = (1 << 4),
			JUST_FRACTURED = (1 << 5),
			MODE_FIXED = (1 << 6),
			MODE_SIMULATED = (1 << 7),
			MODE_ANIMATED_HARDKEYFRAME = (1 << 8),
			MODE_ANIMATED_SOFTKEYFRAME = (1 << 9),
			MODEL_ASSET_BODY = (1 << 10),
		};

		struct free_node : intrusive_multi_rbtree<free_node>::node
		{
		};

		struct free_link
		{
			free_link* mNext;
		};

		struct small_free_node : qNode<small_free_node>
		{
		};


		struct page : qNode<page>
		{
			free_link* mFreeList;
			u16 mBucketIndex;
			u16 mUseCount;
		};

		struct bucket
		{
			qMutex mLock;
			qList<page> mPageList;
			u64 mAllocNumBytes;
			u64 mFreeNumBytes;
			char _padding[48];
		};

		struct block_header
		{
			block_header* mPrev;
			const char* mName;
			u64 mSizeAndFlags;
			u32 pad0;
		};

		struct stats
		{
			u64 mSystemPageNumBytes;
			u64 mSystemPageNumPages;
			u64 mSmallSystemAllocNumBytes;
			u64 mSmallSystemAllocNumBlocks;
			u64 mLargePoolNumBytes;
			u64 mLargeAllocNumBytes;
			u64 mLargeAllocNumBlocks;
			u64 mLargeAllocHighWaterNumBytes;
			u64 mSmallPoolNumBytes;
			u64 mSmallPoolNumPages;
			u64 mSmallAllocNumBytes;
			u64 mSmallAllocNumPages;
			u64 mSmallAllocHighWaterNumBytes;
			u64 mSmallAllocHighWaterNumPages;
			u64 mLinearAllocNumBytes;
		};

		struct system_page_header : qNode<system_page_header>
		{
			u64 mByteSize;
			u64 pad0;
		};


		const char* mName;
		int mLargeBlockMemoryPlatformAllocated;
		int mCanSmallBlockOverflowIntoLargeBlock;
		volatile int mAllocationNumber;
		system_mode mSystemMode;
		qList<system_page_header> mSystemPages;
		char* mFixedSystemPageStart;
		char* mFixedSystemPageEnd;
		stats mStats;
		qList<system_page_header> mSmallBlockSystemPages;
		char* mSmallBlockStart;
		char* mSmallBlockEnd;
		bucket mBuckets[32];
		qList<page> mBucketFreePages;
		qMutex mBucketFreePagesMutex;
		block_header* mMRFreeBlock;
		intrusive_multi_rbtree<free_node> mFreeTree;
		qList<small_free_node> mSmallFreeList;
		qMutex mTreeMutex;
		int mTreeMutexLockCount;
		int mReportBucketIndex;
		int mReportSmallBucketIndex;
		page* mReportSmallPage;
		int mReportSmallSlot;
		system_page_header* mReportLargeSystemPage;
		block_header* mReportLargeBlock;
	};
	SDK_ASSERT_SIZEOF(allocator, 0x11B0);
}