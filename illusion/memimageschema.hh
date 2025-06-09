#pragma once

namespace Illusion
{
	class MemImageSchema
	{
	public:
		struct MemStructure
		{
			const char* mName;
			usize mBaseOffset;
			u32 mSize;
			void** mPointer;
			usize mFixupOffset;
			usize mFixupOffsetPointer;
		};

		u32 mNumMemStructures;
		MemStructure mMemStructure[1000];
		usize mCurrSize;
		void* mAllocatedMemory;
		u32 mCurrSerializeIndex;
		u64 mBaseFilePosition;

		virtual ~MemImageSchema() = 0;

		/* Static Functions */

		SDK_SINLINE MemImageSchema* Instance() { return SDK_VAR(MemImageSchema*, 0x2025AB0); }

		/* Functions */

		void Align16() { SDK_CALL_FUNC(void, 0x8E390, void*)(this); }
		void Allocate(UFG::qMemoryPool* memory_pool = 0, u64 allocation_params = 0) { SDK_CALL_FUNC(void, 0x8E3B0, void*, UFG::qMemoryPool*, u64)(this, memory_pool, allocation_params); }
		void Init() { SDK_CALL_FUNC(void, 0x92850, void*)(this); }
	};
}