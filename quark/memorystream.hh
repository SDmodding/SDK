#pragma once

namespace UFG
{
	class qTask;

	class qMemoryStreamer
	{
	public:
		qTask* mMainMemTask;
		u32 mWorkerID;
		u32 mDmaChannelRead;
		u32 mDmaChannelWrite;
		u64 mWaitReadTicks;
		u64 mWaitWriteTicks;
		u32 mNumReads;
		u32 mNumWrites;
		f32 mWaitReadTime;
		f32 mWaitWriteTime;
		int* mTweakParams;
		int* mUserStats;
	};
	SDK_ASSERT_SIZEOF(qMemoryStreamer, 0x48);
}