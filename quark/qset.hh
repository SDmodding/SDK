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