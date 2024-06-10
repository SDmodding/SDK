#pragma once

namespace Scaleform
{
	class MemoryHeap : public ListNode<MemoryHeap>
	{
	public:
		struct HeapDesc
		{
			uint32_t Flags;
			uint64_t MinAlign;
			uint64_t Granularity;
			uint64_t Reserve;
			uint64_t Threshold;
			uint64_t Limit;
			uint64_t HeapId;
			uint64_t Arena;
		};

		struct HeapInfo
		{
			HeapDesc Desc;
			MemoryHeap* pParent;
			char* pName;
		};

		uint64_t SelfSize;
		volatile unsigned int RefCount;
		uint64_t OwnerThreadId;
		void* pAutoRelease;
		HeapInfo Info;
		List<MemoryHeap> ChildHeaps;
		Lock HeapLock;
		bool UseLocks;
		bool TrackDebugInfo;

		virtual ~MemoryHeap() = 0;
		virtual void VFunc1() = 0;
		virtual void VFunc2() = 0;
		virtual void VFunc3() = 0;
		virtual void VFunc4() = 0;
		virtual void VFunc5() = 0;
		virtual void VFunc6() = 0;
		virtual void VFunc7() = 0;
		virtual void VFunc8() = 0;
		virtual void VFunc9() = 0;

		virtual void* Alloc(size_t p_Size, void* p_Info = nullptr) = 0;
		virtual void* Realloc(void* p_OldPtr, size_t p_Size) = 0;
		virtual void Free(void* p_Ptr) = 0;
	};

	namespace Memory
	{
		UFG_INLINE MemoryHeap* GetGlobalHeap()
		{
			return *reinterpret_cast<MemoryHeap**>(UFG_RVA(0x2451A10));
		}
	}
}