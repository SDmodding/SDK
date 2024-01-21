#pragma once

namespace Scaleform
{
	template <typename T>
	struct List
	{
		T* pPrev;
		T* pNext;
	};

	template <typename T>
	struct ListNode : List<T> {};

	template <typename T, size_t S>
	struct RefCountBase
	{
		void* vfptr;
		volatile int RefCount;

		UFG_INLINE void AddRef()
		{
			_InterlockedIncrement(reinterpret_cast<volatile long*>(&RefCount));
		}

		UFG_INLINE void Release()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x9A7C60))(this);
		}
	};
}
