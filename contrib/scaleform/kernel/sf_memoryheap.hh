#pragma once

namespace Scaleform
{
	class MemoryHeap : public ListNode<MemoryHeap>
	{
	public:
		struct HeapDesc
		{
			u32 Flags;
			u64 MinAlign;
			u64 Granularity;
			u64 Reserve;
			u64 Threshold;
			u64 Limit;
			u64 HeapId;
			u64 Arena;
		};

		struct HeapInfo
		{
			HeapDesc Desc;
			MemoryHeap* pParent;
			char* pName;
		};

		u64 SelfSize;
		volatile u32 RefCount;
		u64 OwnerThreadId;
		void* pAutoRelease;
		HeapInfo Info;
		List<MemoryHeap> ChildHeaps;
		Lock HeapLock;
		bool UseLocks;
		bool TrackDebugInfo;

		virtual ~MemoryHeap() = 0;
	};
}