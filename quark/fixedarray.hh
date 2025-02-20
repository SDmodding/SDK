#pragma once

namespace UFG
{
	template <typename T, u32 N>
	class qFixedArray
	{
	public:
		u32 size;
		T p[N];

		SDK_INLINE T& operator[](u32 index) { return p[index]; }
		SDK_INLINE const T& operator[](u32 index) const { return p[index]; }
	};
}