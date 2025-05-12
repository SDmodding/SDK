#pragma once

namespace UFG
{
	class qSharedString
	{
	public:
		char* mText;

		SDK_INLINE operator const char*() const { return mText; }
	};
}