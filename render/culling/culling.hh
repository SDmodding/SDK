#pragma once

class CullInfo;
class CullInfoFull;
class CullResults;

class CullBucket : public UFG::qNode<CullBucket, CullBucket>
{
public:
	CullInfo* mCullInfos;
	CullInfoFull* mFullCullInfos;
	CullResults* mResults;
	u32 mType;
	u32 mMax;
	u32 mCullInfosAlloced;
	i8 mPad[12];
};
SDK_ASSERT_SIZEOF(CullBucket, 0x40);

class CullResultBucket : public UFG::qSNode<CullResultBucket>
{
public:
	u32 mNumResults;
	i8 mCullFlags[7];
	i8 pad0;
	void* mParams0[7];
	void* mParams1[7];
	f32 mPixelCoverages[7];
	f32 mDistances[7];
};
SDK_ASSERT_SIZEOF(CullResultBucket, 0xC0);

class __declspec(align(64)) CullLayer : public UFG::qNode<CullLayer, CullLayer>
{
	enum CullLayerType : i32
	{
		TYPE_CULL,
		TYPE_OCCLUSION,
		NUM_TYPES
	};

	CullLayerType mType;
	const char* mName;
	bool mDrawEnabled;
	u32 pad0;
	u32 pad1;
	u32 pad2;
	UFG::qList<CullBucket> mFrameCullBuckets;
	UFG::qList<CullBucket> mPersistentCullBuckets;
	UFG::qSList<CullResultBucket> mCullResultBuckets[16];
};
SDK_ASSERT_SIZEOF(CullLayer, 0x100);