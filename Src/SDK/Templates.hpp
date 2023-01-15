#pragma once

template<typename T>
struct qSetBase
{
	unsigned int mCount;
	unsigned int mBufferSize;
	T** mppArray;
};

namespace UFG
{
	template<typename T>
	struct qArray
	{
		unsigned int size;
		unsigned int capacity;
		T* p;
	};


	template<typename T>
	struct HomerCubic
	{
		T mDuration;
		T mParameter;
		T A;
		T B;
		T C;
		T D;
		T p0;
		T p1;
		T v0;
		T v1;
	};

	template<typename T>
	struct qSafePointerBase
	{
		void* mPrev;
		void* mNext;

		T* m_pPointer;
	};

	template<typename T>
	struct qSafePointer : qSafePointerBase<T>
	{ };

	template<typename T>
	struct RebindingComponentHandle
	{
		UFG_PAD(0x10);

		unsigned int m_TypeUID;

		UFG_PAD(0x4);

		T* m_pSimComponent;
		void* m_pSimObject;
		unsigned int m_Changed;

		UFG_PAD(0x4);
	};
}
