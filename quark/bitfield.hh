#pragma once

namespace UFG
{
	template <u32 N>
	class qStaticBitField
	{
	public:
		static const u64 numBits = (N + 63) / 64;
		u64 mBits[numBits];
	};
}