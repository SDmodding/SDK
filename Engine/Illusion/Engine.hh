#pragma once

namespace Illusion
{
	class Engine
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

		UFG_STATIC_INLINE Engine* Instance()
		{
			return reinterpret_cast<Engine*>(UFG_RVA(0x2167800));
		}
	}; typedef Engine CEngine;
}