#pragma once

template <typename T>
class BinPtrArray
{
public:
	int mCount;
	UFG::qOffset64<UFG::qOffset64<T*>*> mData;

	int GetCount() const { return mCount & 0x7FFFFFFF; }

	UFG::qOffset64<T*>* begin()
	{
		if (GetCount())
		{
			if (auto data = mData.Get()) {
				return data;
			}
		}

		return 0;
	}

	UFG::qOffset64<T*>* end()
	{
		if (auto count = GetCount())
		{
			if (auto data = mData.Get()) {
				return &data[count];
			}
		}

		return 0;
	}
};
