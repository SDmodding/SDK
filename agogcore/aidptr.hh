#pragma once

template <typename T>
class AIdPtr
{
public:
	T* i_obj_p;
	u32 i_ptr_id;

	SDK_INLINE T* operator->() { return i_obj_p; }
};
