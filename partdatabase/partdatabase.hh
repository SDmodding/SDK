#pragma once

namespace UFG
{
	class PartLoader;

	class PartRequest : public qNode<PartRequest>
	{
	public:
		enum eLoadStatus
		{
			Undefined,
			Queued,
			Loading,
			Loaded
		};

		void* mModelDataStreamerHandle;
		void* mTextureDataStreamerHandle;
		u32 mLoadCount;
		qReflectHandle<PartDefinition> mPartDefHandle;
		eLoadStatus mLoadStatus;
		u32 mPriorityRefCounts[5];
		u32 mLastReferencedFrame;
		qArray<PartLoader*> mInstances;

		/* Functions */

		void AddDependency(PartLoader* dependency) { SDK_CALL_FUNC(void, 0x1561F0, void*, PartLoader*)(this, dependency); }
		u32 GetHighestBucket() { return SDK_CALL_FUNC(u32, 0x158BA0, void*)(this); }
	};
	SDK_ASSERT_SIZEOF(PartRequest, 0x80);
}