#pragma once

class __declspec(align(16)) CloudTaskInstance
{
public:
	UFG::qMatrix44 mTransform;
	UFG::qMatrix44 mInverseTransform;
	u32 mNumWisps;
	f32 mScale;
	f32 mOpacity;
	UFG::qVector3 mCenter;
	UFG::qVector3 mAABBMin;
	UFG::qVector3 mAABBMax;
	f32 mRadius;
	UFG::qstream_typed<Illusion::Buffer> mAttributeBuffer;
	void* mAttributeBufferData;
	UFG::qstream_typed<Illusion::Buffer> mIndexBuffer;
	void* mIndexBufferData;
	void* mDebugName;
	bool mReset;
	bool mSort;
};

namespace Render
{
	class Cloud : public UFG::qResourceData
	{
	public:
		u32 mNumWisps;
		UFG::qVector3 mAABBMin;
		UFG::qVector3 mAABBMax;
		UFG::qVector3 mCenter;
		f32 mRadius;
		Illusion::BufferHandle mWispBuffer;
	};

	class CloudHandle : public UFG::qTypedResourceHandle<RTypeUID_Cloud, Cloud>{};

	class CloudInstance
	{
	public:
		UFG::qMatrix44 mTransform;
		Render::CloudHandle mCloud;
		UFG::qVector3 mInitialTranslation;
		UFG::qMatrix44 mInverseTransform;
		f32 mScale;
		f32 mOpacity;
		f32 dsqrToCamera;
		u32 mIsStatic;
	};

	class CloudScene : public UFG::qResourceData
	{
	public:
		u32 mNumClouds;
		f32 mElapsedSecs;
		UFG::qVector3 mAABBMin;
		UFG::qVector3 mAABBDimensions;
		UFG::qOffset64<CloudInstance*> mInstances;
	};

	class CloudSceneHandle : public UFG::qTypedResourceHandle<RTypeUID_CloudScene, CloudScene>{};
}