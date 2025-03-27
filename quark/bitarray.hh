#pragma once

namespace UFG
{
	class BitArray
	{
	public:
		u32 mNumBits;
		u32 mNumWords;
		u32* mData;

		virtual ~BitArray() = 0;
	};
}