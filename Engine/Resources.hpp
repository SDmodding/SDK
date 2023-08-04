#pragma once

namespace UFG
{
	struct qResourceData
	{
		qBaseNodeRB m_Node;

		UFG_PAD(0x10);

		uint32_t mTypeUID;
		char mDebugName[0x24];
	};

	struct qResourceHandle
	{
		qNode<qResourceHandle> mNode;
		qResourceData* mData;
		uint32_t mNameUID;
		uint32_t mTailPad;
	};
}