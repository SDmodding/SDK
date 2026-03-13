#pragma once

namespace UFG
{
	class StreamFileWrapper
	{
	public:
		enum QUEUE_CLASS {};

		enum READ_OP_STATE
		{
			STATE_QUEUED,
			STATE_EXECUTING,
			STATE_COMPLETE
		};

		SDK_SINLINE u32 GetAllocationSize(const char* filename) { return SDK_CALL_FUNC(u32, 0x229610, const char*)(filename); }

		SDK_SINLINE void* ReadEntireFile(const char* filename, i64* loaded_size = 0, qMemoryPool* memory_pool = 0, u32 alloc_flags = 0, const char* dbg_tag = 0) {
			return SDK_CALL_FUNC(void*, 0x22C7F0, const char*, i64*, qMemoryPool*, u32, const char*)(filename, loaded_size, memory_pool, alloc_flags, dbg_tag);
		}
	};
}