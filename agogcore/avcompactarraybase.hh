#pragma once

template <typename T>
class AVCompactArrayBase
{
public:
	u32 i_count;
	T* i_array_p;

	SDK_INLINE T& operator[](int i) { return i_array_p[i]; }
};