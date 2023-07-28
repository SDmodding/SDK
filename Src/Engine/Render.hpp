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

	class CViewMetrics
	{
	public:
		unsigned __int64 mTargetTimingStartTicks;
		float mTargetTiming;
		float mDrawScenery;
		float mDrawComposite;
		float mDrawLights;
		float mClouds;
		unsigned int mPad0;
		unsigned int mNumCompositeProcessed;
		unsigned int mNumModelsProcessed;
		unsigned int mNumModelsRendered;
		unsigned int mNumSkinnedModelsRendered;
		unsigned int mNumRigidModelsRendered;
		unsigned int mNumMeshsRendered;
		unsigned int mPad1;
		unsigned int mPad2;
		unsigned int mNumLightsProcessed;
		unsigned int mNumLightsNearTotal;
		unsigned int mNumLightsNearRendered;
		unsigned int mNumLightsStencilTotal;
		unsigned int mNumLightsStencilRendered;
		unsigned int mNumLightsFarTotal;
		unsigned int mNumLightsFarRendered;
		unsigned int mNumLightCards;
		unsigned int mNumShadowsRendered;
		unsigned int mNumCloudsRendered;
		unsigned int mNumParticles;
		unsigned int mNumLargeParticleBatches;
		unsigned int mNumSmallParticleBatches;
		unsigned int mPad3;
		unsigned int mPad4;
		unsigned int mPad5;
	};

	class CViewSettings
	{
	public:
		UFG::qMatrix44 mWorldView;
		UFG::qMatrix44 mProjection;
		int mCullIndex;
		float mCullPixelDensityThreshold;
		float mCullPixelDistanceBias;
	};

	UFG::qVector2* GetViewportScale()
	{
		static UFG::qVector2 m_ViewportScale;
		int* m_BackBufferTarget = *reinterpret_cast<int**>(UFG_RVA(0x2439A50));

		m_ViewportScale.x = static_cast<float>(m_BackBufferTarget[0]);
		m_ViewportScale.y = static_cast<float>(m_BackBufferTarget[1]);
		return &m_ViewportScale;
	}

	class CView
	{
	public:
		CViewSettings* mSettings;
		void* mSubmitContext;
		UFG::qVector4 mFrustumPlanes[6];
		CViewMetrics mViewMetrics;
		unsigned int mLastBeginFrameCounter;
		UFG::qMatrix44 mWorldViewProjection;
		UFG::qMatrix44 mViewWorld;
		float mExtractedNearPlane;
		float mExtractedFarPlane;

		void SubmitRenderModel(Illusion::CModel* model, UFG::qMatrix44* local_world)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CModel*, UFG::qMatrix44*)>(UFG_RVA(0x7D20))(this, model, local_world);
		}
	};
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