#pragma once

namespace UFG
{
	template <typename T>
	class qReflectArrayData
	{
	public:
		T* mItems;
		u32 mNumItems;
		u32 mFlags;
	};

	template <typename T>
	class qReflectArray
	{
	public:
		qReflectArrayData<T> mData;

		void Set(T* items, u32 numItems)
		{
			mData.mItems = items;
			mData.mNumItems = numItems;
		}

		bool IsEmpty() const { return mData.mNumItems == 0; }
		bool IsDynamicallyAllocated() const { return mData.mFlags & 2; }
	};
}