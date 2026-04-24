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

		T& operator[](u32 i) { return mItems[i]; }
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

		void Resize(u32 newSize, bool useMalloc = false)
		{
			if (mData.mNumItems >= newSize) {
				return;
			}

			T* items = mData.mItems;
			const u32 size = (sizeof(T) * newSize);
			const bool dynAllocated = IsDynamicallyAllocated();

			if (useMalloc)
			{
				if (dynAllocated) {
					items = malloc(size);
				}
				else {
					items = realloc(items, size);
				}
			}
			else {
				items = qMalloc(size);
			}

			if (mData.mItems && dynAllocated)
			{
				memcpy(items, mData.mItems, sizeof(T) * mData.mNumItems);
				qFree(mData.mItems);
			}

			mData.mItems = items;
			mData.mNumItems = newSize;
			mData.mFlags = useMalloc ? 0 : 2;
		}

		T& ExpandOne(bool useMalloc = false)
		{
			Resize(mData.mNumItems + 1, useMalloc);
			return mData[mData.mNumItems - 1];
		}

		bool IsEmpty() const { return mData.mNumItems == 0; }
		bool IsDynamicallyAllocated() const { return mData.mFlags & 2; }
	};
}