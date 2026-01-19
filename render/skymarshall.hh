#pragma once

namespace Render
{
	class SkyMarshall
	{
	public:
		enum SkydomeState
		{
			FADE_OUT,
			UNLOADING,
			UNLOADED,
			LOADING,
			FADE_IN,
			COMPLETE
		};

		struct CloudInstanceID
		{
			u16 mSceneIndex;
			u16 mInstanceIndex;
		};

		struct SkydomeModelResource
		{
			u32 model_uid;
			f32 rotation;
		};

		struct SkydomeResource
		{
			UFG::qSymbol mNameUID;
			SkydomeModelResource modelResource[6];
			u32 num_models;
			UFG::qString texture_pack_name;
		};

		struct WispIndexBuffer
		{
			CloudInstanceID mCloudInstanceID;
			Illusion::BufferHandle mBufferHandle[2];
			u32 mNumWisps;
			u32 mNewestBuffer;
			bool mOutOfSync;
		};

		Illusion::TextureHandle mTexture;
		Illusion::TextureHandle mNoiseTexture;
		Illusion::MaterialHandle mCloudMaterial;
		Illusion::MaterialHandle mTestCloudMaterial;
		Illusion::MaterialHandle mRimMaterial;
		Illusion::ModelHandle mWispModel;
		bool mEnableDome;
		Render::CloudSceneHandle mCloudSceneHandle[4];
		CullResults* mCullResults[4];
		WispIndexBuffer mWispIndexBuffer[17];
		u32 mCloudInstanceBuffer[4][512];
		u32 mAvailableBuffers[16];
		CloudTaskInstance mTaskInstance[128];
		u32 mBoundaryCloudSceneID;
		f32 mBoundaryCloudSceneOpacity;
		f32 mEnviroScalar;
		int mSkydomeIndex;
		int mNextSkydomeIndex;
		int mLockSkydomeIndex;
		int mSkydomeRotationIndex;
		SkydomeState mSkydomeState;
		f32 mSkydomeOpacity;
		__declspec(align(8)) UFG::DataStreamer::Handle mSkydomeHandle;
		UFG::qArray<SkydomeResource> mSkydomeResources;
		bool mLockSkydome;
		f32 mFadeInDuration;
		f32 mFadeOutDuration;
		u32 mSkydomeTypeIndex[4];
		Illusion::ModelHandle mSkydomeModel[6];
		u32 mNumSkydomeModels;
		int mDebugDomeIndex;
		UFG::qVector2 mCeilingUV[2];
		f32 mDomeUVOffset;
		f32 mOuterDomeUVOffset;
		f32 mDomeRotation;

		/* Static Functions */

		SDK_SINLINE SkyMarshall* Instance() { return SDK_VAR(SkyMarshall*, 0x2138DF0); }
	};
	SDK_ASSERT_SIZEOF(SkyMarshall, 0xA0F0);
}