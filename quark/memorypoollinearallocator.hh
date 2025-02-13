#pragma once

namespace UFG
{
	class qLinearAllocator
	{
	public:
		volatile u32 mCurrentPos;
		u32 pad0;
		s8* mBuffer0Start;
		s8* mBuffer0End;
		s8* mBuffer1Start;
		s8* mBuffer1End;
		qLinearAllocator* mMainMemoryAddress;
		u32 mLastFrameNumBytes;
		u32 mLastFrameNumAllocBytes;
		u32 mLastFrameNumFreeBytes;
		u32 mLastFrameOverflowed;
		u32 mNumRetries;
		s8 pad[60];

		/* Functions */

		bool InFrame(s8* address) { return SDK_CALL_FUNC(bool, 0x172FC0, void*, s8*)(this, address); }
		void Init(s8* buffer0, i64 byte_size0, s8* buffer1, i64 byte_size1) { SDK_CALL_FUNC(void, 0x173120, void*, s8*, i64, s8*, i64)(this, buffer0, byte_size0, buffer1, byte_size1); }
		s8* Malloc(u32 size, u32 alignment) { return SDK_CALL_FUNC(s8*, 0x1775D0, void*, u32, u32)(this, size, alignment); }
		void Reset() { SDK_CALL_FUNC(void, 0x17ACC0, void*)(this); }
	};
}