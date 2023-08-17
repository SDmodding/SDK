#pragma once

namespace UFG
{
	class CLinearAllocator
	{
	public:
		volatile uint32_t mCurrentPos;
		uint32_t pad0;
		char* mBuffer0Start;
		char* mBuffer0End;
		char* mBuffer1Start;
		char* mBuffer1End;
		CLinearAllocator* mMainMemoryAddress;
		uint32_t mLastFrameNumBytes;
		uint32_t mLastFrameNumAllocBytes;
		uint32_t mLastFrameNumFreeBytes;
		uint32_t mLastFrameOverflowed;
		uint32_t mNumRetries;
		char pad[60];

		void* Malloc(uint32_t p_Size, uint32_t p_Alignment)
		{
			return reinterpret_cast<void*(__fastcall*)(void*, uint32_t, uint32_t)>(UFG_RVA(0x1775D0))(this, p_Size, p_Alignment);
		}

		template <typename T>
		T* Malloc(uint32_t p_Alignment)
		{
			return reinterpret_cast<T*>(Malloc(sizeof(T), p_Alignment));
		}
	};
}