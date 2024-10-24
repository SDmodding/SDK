#pragma once

namespace UFG
{
	class RenderContextPlat
	{
	public:
		RenderContext* mRenderContext;
		Illusion::Target* mSavedGBuffer;
	};

	class __declspec(align(16)) RenderContext
	{
	public:
		enum AntiAliasState : s32
		{
			AASTATE_NONE,
			AASTATE_SEPERATE_PASS,
			NUM_AASTATE
		};

		u32 mGBufferWidth;
		u32 mGBufferHeight;
		Illusion::Target* mGBufferTarget;
		Illusion::Target* mGBufferDepthTarget;
		Illusion::Target* mGBufferDiffuseAlbedoAliasTarget;
		Illusion::Target* mDynamicRangeTarget;
		Illusion::Target* mLightBufferTarget;
		Illusion::Target* mHDRBloomTarget;
		Illusion::Target* mHalfSizeTarget;
		Illusion::Target* mHalfSizeLinearDepthTarget;
		Illusion::Target* mReflectionMipTarget;
		Illusion::Target* mReflectionTarget;
		Illusion::Target* mSphericalEnvMapTarget;
		Illusion::Target* mAmbientOcclusionAliasTarget;
		Illusion::Target* mSkyOcclusionAliasTarget;
		Illusion::Target* mNearBlur;
		Illusion::Target* mQuarterSizeLinearDepthTarget;
		Illusion::Target* mQuarterSizeVolumetricTarget;
		Illusion::Target* mHalfSizeVolumetricTarget;
		Render::EnvCubeMap* mEnvCubeMap;
		Illusion::Target* mFullSizeScratchTargetA;
		Illusion::Target* mHalfSizeScratchTargetA;
		Illusion::Target* mHalfSizeScratchTargetB;
		Illusion::Target* mHalfSizeScratchTargetC;
		Illusion::Target* mQuarterSizeScratchTargetA;
		Illusion::Target* mQuarterSizeScratchTargetB;
		Illusion::Target* mEighthSizeScratchTargetA;
		Illusion::Target* mEighthSizeScratchTargetB;
		Illusion::Target* mSixteenthSizeScratchTargetA;
		Illusion::Target* mSixteenthSizeScratchTargetB;
		Illusion::Target* mThrityTwoSizeScratchTargetA;
		Illusion::Target* mThrityTwoSizeScratchTargetB;
		Illusion::Target* mSixtyFourSizeScratchTargetA;
		Illusion::Target* mSixtyFourSizeScratchTargetB;
		Illusion::Target* mAAResultTarget;
		Illusion::Target* mDirectionalOcclusionTarget;
		Illusion::Target* mQuarterSizeAmbientOcclusionTarget;
		Render::RenderOutputParams mRenderSettingsForFrame;
		Illusion::Texture* mLightBufferMain;
		Illusion::Texture* mQuarterSizeScratchAPointSampleTexture;
		Illusion::Texture* mQuarterSizeScratchBPointSampleTexture;
		Illusion::Texture* mHalfSizeScratchCPointSampleTexture;
		Illusion::Texture* mHalfSizeScratchBPointSampleTexture;
		Illusion::UnorderedAccessView* mAmbientOcclusionAliasUAV;
		Illusion::UnorderedAccessView* mAmbientOcclusionScratchUAV;
		Illusion::UnorderedAccessView* mQuarterSizeAmbientOcclusionAliasUAV;
		Illusion::UnorderedAccessView* mQuarterSizeAmbientOcclusionScratchUAV;
		u32 mAmbientSpecShaderUID;
		u32 mAmbientSpecWithSunShaderUID;
		u32 mAmbientSpecWithSunShader_DOUID;
		Illusion::Material* mSunAfterAmbientSpecMarkMaterial;
		u32 mSunAfterAmbientSpecTestRasterStateUID;
		u32 mSunAfterAmbientSpecTestNoClearRasterStateUID;
		u32 mCascadeShadowSize;
		u32 mSpotShadowSize;
		u32 mCharacterShadowSize;
		Illusion::Texture* mSingleShadowSubtexture;
		Illusion::Target* mSingleShadowTarget;
		Illusion::Texture* mHalfSizeSingleShadowAliasTexture;
		Illusion::Target* mHalfSizeSingleShadowTarget;
		Illusion::Target* mHalfSizeShadowTarget;
		Illusion::Texture* mHalfSizeShadowAliasTexture;
		Illusion::Target* mQuarterSizeShadowTarget;
		Illusion::Texture* mQuarterSizeShadowAliasTexture;
		Illusion::Target* mCharacterShadowTarget;
		Illusion::Texture* mCharacterShadowTexture;
		Illusion::Texture* mCharacterShadowTextureAliasDepth;
		Illusion::Texture* mSingleShadowTextureAliasDepth;
		Illusion::Target* mHeightmapTarget;
		Illusion::Texture* mHeightmapShadowTextureAlias;
		Illusion::Target* mCascadeShadowTarget;
		Illusion::Texture* mCascadeShadowTexture;
		Illusion::Texture* mCascadeShadowTextureAliasDepth;
		Illusion::Target* mCubeMapTarget;
		Illusion::Material* mLightMaterial;
		Illusion::Material* mIrradianceVolumeMaterial;
		Illusion::Material* mIrradianceVolumeSkyMaterial;
		Illusion::Material* mIrradianceVolumeSkyMaterial2;
		Illusion::Material* mIrradianceVolumeSkyBlackMaterial;
		Illusion::Material* mCompositeLightingMaterial;
		Illusion::Material* mCompositeFinalMaterial;
		Illusion::Material* mShadowCollectorMaterial;
		Illusion::Material* mSunUsingCollectorMaterial;
		Illusion::Material* mSkyAmbientMaterial;
		Illusion::Material* mBlobMaterial;
		Illusion::Material* mCameraBlurMaterial;
		Illusion::Material* mDownsampleDepthMaterial;
		Illusion::Material* mSSAOMaterial;
		Illusion::Material* mSSAONISMaterial;
		Illusion::Material* mSSAOHighMaterial;
		Illusion::Material* mSSDOMaterial;
		Illusion::Material* mLightShaftSpotLightMaterial;
		Illusion::Material* mMatBlendVolumesIntoHalfSize;
		Illusion::Material* mBloomThresholdMaterial;
		Illusion::Material* mAntiAliasMaterial;
		Illusion::Material* mDistortionMaterial;
		Illusion::Material* mPostCompLightshaftMaterial;
		int mNumSpotShadowsAllowed;
		f32 mAOOpacity;
		f32 mMotionBlurStrength;
		int mLightWithIrradianceVolumesType;
		int mAmbientOcclusionVolumesType;
		Render::RenderFrameFeatures mRenderFeatures;
		bool mCombineAmbientSpecAndSun;
		Render::ViewMetrics mRenderStats;
		Render::ViewSettings mMainViewSettings;
		bool mRenderSun;
		bool mRenderRain;
		bool mRenderSkinSS;
		CB_EnvironmentSettings* mEnvState;
		CB_SkySettings* mSkyState;
		u32 mNumCascades;
		AntiAliasState mAntiAliasState;
		Reflection* mReflection;
		bool mTargetsCreated;
		qTask* mLightingSubmitTask;
		LightingSubmitTaskParams* mLightingSubmitTaskParams;
		RenderContextPlat* mRenderContextPlat;
	};
	SDK_ASSERT_SIZEOF(RenderContext, 0x4D0);
}