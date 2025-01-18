#pragma once

namespace UFG
{
	template <typename T, u32 N>
	class qSafeArray
	{
	public:
		T array[N];

		SDK_INLINE T& operator[](int index) { return array[index]; }
	};
}