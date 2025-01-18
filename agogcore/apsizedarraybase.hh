#pragma once

template <typename T>
class APSizedArrayBase : public APArrayBase<T>
{
public:
	u32 i_size;
};