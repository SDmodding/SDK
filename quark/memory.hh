#pragma once

namespace UFG
{
	template <typename T>
	SDK_INLINE T qAlignUp(T n, T align) { return (n + (align - 1)) & ~(align - 1); }
}