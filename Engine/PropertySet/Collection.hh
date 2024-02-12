#pragma once

namespace UFG
{
	struct qPropertyCollection
	{
		uint32_t mFlags;

		UFG_PAD(0x4);

		qOffset64<qPropertyCollection> mOwner;
	};
}