#pragma once

namespace UFG
{
	template <typename T>
	class qCircularArray
	{
	public:
		T* mData;
		int mCapacity;
		u32 mHeadIndex;
		u32 mTailIndex;
		qMemoryPool* mpMemoryPool;
		u32 pad1;
		u32 pad2;
		u32 pad3;

		SDK_INLINE T& operator[](u32 index) { return mData[index]; }
	};
}