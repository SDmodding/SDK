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
	};
}