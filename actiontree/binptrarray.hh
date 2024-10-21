#pragma once

template <typename T>
class BinPtrArray
{
public:
	int mCount;
	UFG::qOffset64<UFG::qOffset64<T*>*> mData;
};
