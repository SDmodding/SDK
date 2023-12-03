#pragma once

namespace UFG
{
	class __declspec(align(16)) CRenderContext
	{
	public:
		uint32_t mGBufferWidth;
		uint32_t mGBufferHeight;
		Illusion::CTarget* mGBufferTarget;
		Illusion::CTarget* mGBufferDepthTarget;
		Illusion::CTarget* mGBufferDiffuseAlbedoAliasTarget;
		Illusion::CTarget* mDynamicRangeTarget;
		Illusion::CTarget* mLightBufferTarget;
		Illusion::CTarget* mHDRBloomTarget;
		Illusion::CTarget* mHalfSizeTarget;
		Illusion::CTarget* mHalfSizeLinearDepthTarget;
		Illusion::CTarget* mReflectionMipTarget;
		Illusion::CTarget* mReflectionTarget;
		Illusion::CTarget* mSphericalEnvMapTarget;
		Illusion::CTarget* mAmbientOcclusionAliasTarget;
		Illusion::CTarget* mSkyOcclusionAliasTarget;
		Illusion::CTarget* mNearBlur;
		Illusion::CTarget* mQuarterSizeLinearDepthTarget;
		Illusion::CTarget* mQuarterSizeVolumetricTarget;
		Illusion::CTarget* mHalfSizeVolumetricTarget;
		class Render_EnvCubeMap* mEnvCubeMap;
		Illusion::CTarget* mFullSizeScratchTargetA;
		Illusion::CTarget* mHalfSizeScratchTargetA;
		Illusion::CTarget* mHalfSizeScratchTargetB;
		Illusion::CTarget* mHalfSizeScratchTargetC;
		Illusion::CTarget* mQuarterSizeScratchTargetA;
		Illusion::CTarget* mQuarterSizeScratchTargetB;
		Illusion::CTarget* mEighthSizeScratchTargetA;
		Illusion::CTarget* mEighthSizeScratchTargetB;
		Illusion::CTarget* mSixteenthSizeScratchTargetA;
		Illusion::CTarget* mSixteenthSizeScratchTargetB;
		Illusion::CTarget* mThrityTwoSizeScratchTargetA;
		Illusion::CTarget* mThrityTwoSizeScratchTargetB;
		Illusion::CTarget* mSixtyFourSizeScratchTargetA;
		Illusion::CTarget* mSixtyFourSizeScratchTargetB;
		Illusion::CTarget* mAAResultTarget;
		Illusion::CTarget* mDirectionalOcclusionTarget;
		Illusion::CTarget* mQuarterSizeAmbientOcclusionTarget;

		UFG_PAD(0x68);
		//Render::RenderOutputParams mRenderSettingsForFrame;

		Illusion::CTexture* mLightBufferMain;
		Illusion::CTexture* mQuarterSizeScratchAPointSampleTexture;
		Illusion::CTexture* mQuarterSizeScratchBPointSampleTexture;
		Illusion::CTexture* mHalfSizeScratchCPointSampleTexture;
		Illusion::CTexture* mHalfSizeScratchBPointSampleTexture;
		class Illusion_UnorderedAccessView* mAmbientOcclusionAliasUAV;
		class Illusion_UnorderedAccessView* mAmbientOcclusionScratchUAV;
		class Illusion_UnorderedAccessView* mQuarterSizeAmbientOcclusionAliasUAV;
		class Illusion_UnorderedAccessView* mQuarterSizeAmbientOcclusionScratchUAV;
		uint32_t mAmbientSpecShaderUID;
		uint32_t mAmbientSpecWithSunShaderUID;
		uint32_t mAmbientSpecWithSunShader_DOUID;
		Illusion::CMaterial* mSunAfterAmbientSpecMarkMaterial;
		uint32_t mSunAfterAmbientSpecTestRasterStateUID;
		uint32_t mSunAfterAmbientSpecTestNoClearRasterStateUID;
		uint32_t mCascadeShadowSize;
		uint32_t mSpotShadowSize;
		uint32_t mCharacterShadowSize;
		Illusion::CTexture* mSingleShadowSubtexture;
		Illusion::CTarget* mSingleShadowTarget;
		Illusion::CTexture* mHalfSizeSingleShadowAliasTexture;
		Illusion::CTarget* mHalfSizeSingleShadowTarget;
		Illusion::CTarget* mHalfSizeShadowTarget;
		Illusion::CTexture* mHalfSizeShadowAliasTexture;
		Illusion::CTarget* mQuarterSizeShadowTarget;
		Illusion::CTexture* mQuarterSizeShadowAliasTexture;
		Illusion::CTarget* mCharacterShadowTarget;
		Illusion::CTexture* mCharacterShadowTexture;
		Illusion::CTexture* mCharacterShadowTextureAliasDepth;
		Illusion::CTexture* mSingleShadowTextureAliasDepth;
		Illusion::CTarget* mHeightmapTarget;
		Illusion::CTexture* mHeightmapShadowTextureAlias;
		Illusion::CTarget* mCascadeShadowTarget;
		Illusion::CTexture* mCascadeShadowTexture;
		Illusion::CTexture* mCascadeShadowTextureAliasDepth;
		Illusion::CTarget* mCubeMapTarget;
		Illusion::CMaterial* mLightMaterial;
		Illusion::CMaterial* mIrradianceVolumeMaterial;
		Illusion::CMaterial* mIrradianceVolumeSkyMaterial;
		Illusion::CMaterial* mIrradianceVolumeSkyMaterial2;
		Illusion::CMaterial* mIrradianceVolumeSkyBlackMaterial;
		Illusion::CMaterial* mCompositeLightingMaterial;
		Illusion::CMaterial* mCompositeFinalMaterial;
		Illusion::CMaterial* mShadowCollectorMaterial;
		Illusion::CMaterial* mSunUsingCollectorMaterial;
		Illusion::CMaterial* mSkyAmbientMaterial;
		Illusion::CMaterial* mBlobMaterial;
		Illusion::CMaterial* mCameraBlurMaterial;
		Illusion::CMaterial* mDownsampleDepthMaterial;
		Illusion::CMaterial* mSSAOMaterial;
		Illusion::CMaterial* mSSAONISMaterial;
		Illusion::CMaterial* mSSAOHighMaterial;
		Illusion::CMaterial* mSSDOMaterial;
		Illusion::CMaterial* mLightShaftSpotLightMaterial;
		Illusion::CMaterial* mMatBlendVolumesIntoHalfSize;
		Illusion::CMaterial* mBloomThresholdMaterial;
		Illusion::CMaterial* mAntiAliasMaterial;
		Illusion::CMaterial* mDistortionMaterial;
		Illusion::CMaterial* mPostCompLightshaftMaterial;
		int mNumSpotShadowsAllowed;
		float mAOOpacity;
		float mMotionBlurStrength;
		int mLightWithIrradianceVolumesType;
		int mAmbientOcclusionVolumesType;
		bool mWorld;
		bool mScenery;
		bool mWireframeScenery;
		bool mLights;
		bool mAlternateGradientBackground;
		bool mPostFX;
		bool mUI;
		bool mDOF;
		bool mAO;
		bool mMotionBlur;
		bool mForceLetterBox;
		bool mForceSceneryDoubleSided;
		bool mCombineAmbientSpecAndSun;

		UFG_PAD(0x8);

		Render::CViewMetrics mRenderStats;
		Render::CViewSettings mMainViewSettings;
		bool mRenderSun;
		bool mRenderRain;
		bool mRenderSkinSS;
		void* mEnvState;
		void* mSkyState;
		unsigned int mNumCascades;
		int mAntiAliasState;
		void* mReflection;
		bool mTargetsCreated;
		void* mLightingSubmitTask;
		void* mLightingSubmitTaskParams;
		void* mRenderContextPlat;

		static __inline CRenderContext* Instance()
		{
			return *reinterpret_cast<CRenderContext**>(UFG_RVA(0x21299D8));
		}

		void EnableAntiAlias(bool enable)
		{
			mAntiAliasState = (enable ? 1 : 0);
		}
	};
}