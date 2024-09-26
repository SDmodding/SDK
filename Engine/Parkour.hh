#pragma once

namespace UFG
{
	class CParkourHandleInfo
	{
	public:
		qVector3 start;
		qVector3 end;
		qVector3 axis;
		qVector3 normal;
		qVector3 centre;
		float halfLength;
		bool hasValidNormal;
	};

	class CParkourHandle
	{
	public:
		qSafePointerNode<CParkourHandle> mSafeNode;
		qNode<CParkourHandle> mNode;
		qSafePointer<class SimObject> mSimObject;
		qSafePointer<CParkourHandle> mCachedLeftNeighbor;
		qSafePointer<CParkourHandle> mCachedRightNeighbor;
		qVector3 v0;
		qVector3 v1;
		uint64_t mUid;
		int mFramesUntilDeleted;
		uint16_t mFlags;
		uint32_t mIsLatched : 1;
		uint32_t mEnabled : 1;
		uint32_t mNumUsers : 3;
	};

	class CParkourQuery
	{
	public:

	};

	class CParkourQueryManager
	{
	public:
		qList<CParkourHandle> mActiveHandles[257];

		UFG_PAD(0x10);
		//hkArray<UFG::ParkourData*, hkContainerHeapAllocator> mTempOutput;

		uint32_t mInactiveSearchBucket;
		uint32_t mFrameNumber;
		uint32_t mNumQueries;
		uint32_t mConnectivityUpdateBucket;
		qList<CParkourQuery> mQueries;

		static UFG_INLINE CParkourQueryManager* Instance()
		{
			return *reinterpret_cast<CParkourQueryManager**>(UFG_RVA(0x2403598));
		}
	};
}