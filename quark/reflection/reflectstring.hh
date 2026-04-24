#pragma once

namespace UFG
{
	class qReflectString
	{
	public:
		qReflectArray<char> mText;

		void Set(const char* value) { SDK_CALL_FUNC(void, 0xB0580, void*, const char*)(this, value); }

		void Set(const char* value, u32 len)
		{
			mText.mData.mItems = const_cast<char*>(value);
			mText.mData.mNumItems = len;
		}
	};
}