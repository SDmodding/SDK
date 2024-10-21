#pragma once

namespace UFG
{
	template <typename T, u32 N>
	class qFixedArray
	{
	public:
		u32 size;
		T p[N];
	};
}