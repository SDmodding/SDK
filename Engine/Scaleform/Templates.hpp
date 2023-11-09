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
	};
}
