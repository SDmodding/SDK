#pragma once

namespace Scaleform
{
	class SysAllocBase
	{
	public:
		virtual ~SysAllocBase() = 0;
		virtual bool initHeapEngine(MemoryHeap::HeapDesc* heapDesc) = 0;
		virtual bool shutdownHeapEngine() = 0;
	};

	class SysAlloc : public SysAllocBase
	{
	public:
		virtual void* Alloc(u64 size, u64 align) = 0;
		virtual void Free(void* ptr, u64 size, u64 align) = 0;
		virtual void* Realloc(void* oldPtr, u64 oldSize, u64 newSize, u64 align) = 0;
	};
}