#pragma once

class BinString
{
public:
	s64 mOffset;

	SDK_INLINE char* Get()
	{
		if (!mOffset) {
			return 0;
		}

		return (reinterpret_cast<char*>(this) + (mOffset & ~1));
	}
};
