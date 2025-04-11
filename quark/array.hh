#pragma once

namespace UFG
{
	template <typename T, u32 WHAT = 0>
	class qArray
	{
	public:
		u32 size;
		u32 capacity;
		T* p;

		SDK_INLINE T& operator[](u32 index) { return p[index]; }

		SDK_INLINE T* begin() { return p; }
		SDK_INLINE T* end() { return &p[size]; }
	};

}