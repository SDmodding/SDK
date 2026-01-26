#pragma once

namespace UFG
{
	class StreamPool;

	class BlockHeader : public qNodeRB<BlockHeader>
	{
	public:
		BlockHeader* mPrev;
		BlockHeader* mNext;
		u16 mFlags;
		u16 mType;
		u32 mSize;
		u32 mSizeOriginal;
		u32 mSizeData;
		u32 mLargestChunk;
		void* mData;
		BlockHeader* mNextUnused;
	};

	class DefragState
	{
	public:
		enum STATE
		{
			INACTIVE,
			POST_DEFRAG,
			WAIT_FRAME,
			WAIT_FRAME_BMOVE,
			MOVE_TO_NEXT_BLOCK,
			BLOCK_MOVESTART,
			BLOCK_MOVECONTINUE
		};

		class PendingFreeOp : public qNode<PendingFreeOp>
		{
		public:
			u64 mHandle;
			bool mPossibleToCache;
		};

		BlockHeader* mMovingBlock;
		BlockHeader* mCurrentBlock;
		StreamPool* mpStreamPool;
		STATE meState;
		u32 mMaxPendingAlloc;
		int mFrameDelay;
		u32 mCurrentOffset;
		char* mSourceDataStart;
		u32 mSourceDataSize;
		char* mTargetDataStart;
		u32 mTargetDataSize;
		u32 mTargetSize;
		char* mSafeGPUDataTargetStart;
		u32 mSafeGPUDataTargetSize;
		qList<PendingFreeOp> mPendingFreeOps;
	};

	class StreamPool : public qNode<StreamPool>
	{
	public:
		u32 mPoolSize;
		u32 mHighWatermark;
		u32 mDefragReserve;
		u32 mTopAllocSizeThreshold;
		u32 mSizeByType[4];
		bool mbAllowDefrag;
		bool mbPotentiallyDefraggable;
		bool mbGPUBlockOnDefag;
		char mPoolName[32];
		BlockHeader mBlockHead;
		qTreeRB<BlockHeader> mBlockLookup;
		u32 mPoolIndex;
		u32 mPageSize;
		u32 mAlignment;
		void* mOwnedDataBuffer;
		DefragState mDefragState;
	};

	SDK_VINLINE qGlobalArray<StreamPool*, 32, 0x236FBD0> gStreamPools;
}