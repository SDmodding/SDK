#pragma once

namespace Scaleform
{
	template < class T>
	struct ListNode
	{
		union
		{
			T* pPrev;
			void* pVoidPrev;
		};

		union 
		{
			T* pNext;
			void* pVoidNext;
		};
	};

	template<class T, class B = T> 
	class List
	{
	public:
		ListNode<B> Root;
	};
}