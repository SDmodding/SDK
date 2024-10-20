#pragma once

namespace UFG
{
	template <typename T>
	class qArray
	{
	public:
		u32 size;
		u32 capacity;
		T* p;

		SDK_INLINE T* begin() { return p; }
		SDK_INLINE T* end() { return &p[size]; }
	};

}