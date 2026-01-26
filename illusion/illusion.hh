#pragma once

namespace Illusion
{
	class Engine : public IEnginePlat
	{
	public:
		u32 mFrameCount;
		u32 mSafeToDeleteFrameCount;
		UFG::qMemoryStreamer* MemoryStreamer;
		UFG::qLinearAllocator* FrameMemory;
		UFG::qLinearAllocator* PrevFrameMemory;
		UFG::qLinearAllocator* FrameWriteMemory;
		UFG::qLinearAllocator* PrimitiveFrameWriteMemory;
		UFG::qLinearAllocator* FramePatchMemory;
		UFG::qLinearAllocator* FrameIndexMemory;

		/* Static Functions */
		
		SDK_SINLINE Engine* Instance() { return SDK_VAR(Engine*, 0x2167800); }
	};
}