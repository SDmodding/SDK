#pragma once

template <typename T>
class ARefPtr
{
public:
	T* i_obj_p;

	SDK_INLINE T* operator->() { return i_obj_p; }
};