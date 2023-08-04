#pragma once

namespace Render
{
	class CDepthOfField
	{
	public:
		void* mMaterial;
		__int16 mStateBlockIndex;
		float mFocalDistance;
		float mInFocusRange;
		float mNearRange;
		float mNearBlurRadius;
		float mFarRange;
		float mFarBlurRadius;
		bool mNearBlurRendered;

		bool* DontRender() { return reinterpret_cast<bool*>(UFG_RVA(0x2136120)); }

		void Enable(bool enable)
		{
			if (*DontRender() != enable) return;

			*DontRender() = !enable;

			mFocalDistance	= 0.f;
			mInFocusRange	= 0.f;
			mNearRange		= 0.f;
			mNearBlurRadius = 0.f;
			mFarRange		= 0.f;
			mFarBlurRadius	= 0.f;
		}
	};
	CDepthOfField* DepthOfField = reinterpret_cast<CDepthOfField*>(UFG_RVA(0x2129328));
}

namespace UFG
{
	class CRenderContext
	{
	public:
		UFG_PAD(0x348);

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

		void EnableAntiAlias(bool enable)
		{
			mAntiAliasState = (enable ? 1 : 0);
		}
	};

	namespace RenderContext
	{
		CRenderContext* Get()
		{
			return *reinterpret_cast<CRenderContext**>(UFG_RVA(0x21299D8));
		}
	}
}