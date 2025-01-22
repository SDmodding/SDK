#pragma once

namespace UFG
{
	template <typename T>
	class qSetBase
	{
	public:
		u32 mCount;
		u32 mBufferSize;
		T** mppArray;

		SDK_INLINE T* operator[](int index) { return mppArray[index]; }
	};

	template <typename T, typename U = T>
	class qSet : public qSetBase<T>
	{
	public:
	};

	template <typename T, typename U = T>
	class qSetLogical : public qSet<T, U>
	{
	public:
	};
}