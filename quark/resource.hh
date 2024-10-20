#pragma once

namespace UFG
{
	class qResourceData;

	//-------------------------------------------------------------------
	// Handle
	//-------------------------------------------------------------------

	class qResourceHandle : public qNode<qResourceHandle>
	{
	public:
		qResourceData* mData;
		u32 mNameUID;
		u32 mTailPad;
	};
	SDK_ASSERT_SIZEOF(qResourceHandle, 0x20);


	template <u32 type_uid, typename T>
	class qTypedResourceHandle : public qResourceHandle
	{
	public:
	};

	//-------------------------------------------------------------------
	// Data
	//-------------------------------------------------------------------

	class qResourceData : public qNodeRB<qResourceData>
	{
	public:
		qList<qResourceHandle> mResourceHandles;
		u32 mTypeUID;
		char mDebugName[36];
	};
	SDK_ASSERT_SIZEOF(qResourceData, 0x58);
}