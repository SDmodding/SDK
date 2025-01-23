#pragma once

namespace Render
{
	class IDecalScenery;

	class DecalSettings : public UFG::qResourceData, public FXComponentSettings
	{
	public:
		CB_DecalSettings mCBSettings;
		u32 mTextureUID;
		u32 mNormalUID;
		u32 mShaderUID;
		u32 mAlphaStateUID;
		u32 mRasterStateUID;
		u32 mCount;
		f32 mEmissionRate;
		u32 mSpawnAgainOnLoop;
		f32 mRadiusMin;
		f32 mRadiusMax;
		f32 mDepth;
		f32 mFalloff;
		UFG::qVector3 mMinDir;
		UFG::qVector3 mMaxDir;
		u32 mDrawPass;
		int mNumPages;
		u32 mTextureOrientation;
		f32 mRotateMin;
		f32 mRotateMax;
		u32 mOnlyClipAlpha;
	};

	class vDecal
	{
	public:
		UFG::qVector3 mPosition;
		u16 mTexCoord0[2];
		i8 mNormal[4];
		i8 mTangent[4];
	};

	class Decal : public UFG::qNode<Decal>
	{
	public:
		DecalSettings* mSettings;
		IDecalScenery* mScenery;
		void* mSceneryData1;
		void* mSceneryData2;
		u32 mBindIndex;
		u32 mSequenceID;
		u32 mNameUID;
		u16 mNumFragments;
	};

	class DecalClipTaskParams
	{
	public:
		void* mIndexBufferPtr;
		void* mVertexBufferPtr;
		UFG::qMatrix44 mLocalWorld;
		UFG::qMatrix44 mWorldBasis;
		f32 mTexOrientation;
		f32 mTexOffset;
		f32 mOneOverNumTexPages;
		u32 mPrimCount;
		u32 mVertexStreamStride;
		f32 mDecalCutoff;
		f32 mDecalRadius;
		f32 mDecalDepth;
	};

	class DecalClipTaskResults
	{
	public:
		vDecal mVerts[128];
		i8 mPrimVertCount[42];
		u32 mNumPrims;
		u32 mNumVerts;
		UFG::qVector3 mAabbMin;
		UFG::qVector3 mAabbMax;
		bool mResultReady;
	};

	class DecalObjectLink
	{
	public:
		UFG::qSafePointer<UFG::SimComponent> mComponentPtr;
		IDecalScenery* mScenery;
		u32 mIndex;
	};

	class DecalClipInfo
	{
	public:
		DecalSettings* mSettingsPtr;
		DecalObjectLink mStoredObjLink;
		u32 mSequenceID;
		bool mIsValid;
	};

	class DecalClipQuery
	{
	public:
		DecalClipTaskParams* task_params;
		DecalClipTaskResults* task_results;
		DecalClipInfo* decal_info;
	};

	class IDecalScenery
	{
	public:
		UFG::qList<Decal> mAttachedDecals;

		virtual bool GetTransform(Decal* decal, UFG::qMatrix44& mat) = 0;
		virtual void OnResetDecal(Decal* decal) = 0;
		virtual void OnAttachDecal(Decal* decal, DecalClipQuery* dcq) = 0;
	};
}