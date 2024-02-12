#pragma once

namespace Illusion
{
	class CEngine
	{
	public:
		uint32_t mFrameCount;
		uint32_t mSafeToDeleteFrameCount;
		void* MemoryStreamer;
		UFG::CLinearAllocator* FrameMemory;
		UFG::CLinearAllocator* PrevFrameMemory;
		UFG::CLinearAllocator* FrameWriteMemory;
		UFG::CLinearAllocator* PrimitiveFrameWriteMemory;
		UFG::CLinearAllocator* FramePatchMemory;
		UFG::CLinearAllocator* FrameIndexMemory;

		static CEngine* Instance()
		{
			return reinterpret_cast<CEngine*>(UFG_RVA(0x2167800));
		}
	};
}