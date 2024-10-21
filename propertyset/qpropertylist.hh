#pragma once

namespace UFG
{
	class qPropertyList : public qPropertyCollection
	{
	public:
		enum Flags
		{
			FLAG_DELETED = (1 << 16)
		};

		qOffset64<u8*> mValues;
		u32 mTypeUID;
		u32 mElementSize;
		qOffset64<u32*> mWeights;
		u32 mNumElements;
		u32 mTotalWeight;
	};
	SDK_ASSERT_SIZEOF(qPropertyList, 0x30);
}