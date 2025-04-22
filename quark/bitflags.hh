#pragma once

namespace UFG
{
	class BitFlags128
	{
	public:
		u64 mFlags[2];

		bool IsSet(u64 index) const
		{
			if (index >= 64) {
				return mFlags[1] & (1ull << (index - 64ull));
			}

			return mFlags[0] & (1ull << index);
		}

		void Set(u64 index)
		{
			if (index >= 64) {
				mFlags[1] |= (1ull << (index - 64ull));
			}
			else {
				mFlags[0] |= (1ull << index);
			}
		}

		void Remove(u64 index)
		{
			if (index >= 64) {
				mFlags[1] &= ~(1ull << (index - 64ull));
			}
			else {
				mFlags[0] &= ~(1ull << index);
			}
		}
	};
}