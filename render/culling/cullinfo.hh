#pragma once

class CullInfo
{
public:
	f32 mAABBMin[3];
	u16 mIsLocalWorldIdentity;
	u16 mNextSiblingSkip;
	f32 mAABBMax[3];
	u16 mPixelScaleBias;
	u16 mViewsCulled;
	CullLayer* mCullLayer;
	void* mParam0;
	void* mParam1;
	f32* mpLocalWorld;
};
SDK_ASSERT_SIZEOF(CullInfo, 0x40);

class CullInfoFull : public CullInfo
{
public:
	float mLocalWorld[4][4];
};
SDK_ASSERT_SIZEOF(CullInfoFull, 0x80);
