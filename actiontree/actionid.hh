#pragma once

class ActionID
{
public:
	u32 mUID;
};

class ActionPath
{
public:
	BinArray<ActionID> mPath;

	SDK_INLINE ActionPath() {}
	SDK_INLINE ActionPath(ActionID* array, int count)
	{
		mPath.mData.Set(array);
		mPath.mCount = count;
	}
};
