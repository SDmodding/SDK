#pragma once

template <typename T>
class BinArray
{
public:
	int mCount;
	UFG::qOffset64<T*> mData;
};