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

	/* Functions */

	void Append(const char* value) { SDK_CALL_FUNC(void, 0x15DE50, void*, const char*)(this, value); }
};
