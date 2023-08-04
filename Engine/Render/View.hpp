#pragma once

namespace Render
{
	UFG::qVector2* GetViewportScale()
	{
		static UFG::qVector2 m_ViewportScale;
		int* m_BackBufferTarget = *reinterpret_cast<int**>(UFG_RVA(0x2439A50));

		m_ViewportScale.x = static_cast<float>(m_BackBufferTarget[0]);
		m_ViewportScale.y = static_cast<float>(m_BackBufferTarget[1]);
		return &m_ViewportScale;
	}

	class CViewMetrics
	{
	public:
		uint64_t mTargetTimingStartTicks;
		float mTargetTiming;
		float mDrawScenery;
		float mDrawComposite;
		float mDrawLights;
		float mClouds;
		uint32_t mPad0;
		uint32_t mNumCompositeProcessed;
		uint32_t mNumModelsProcessed;
		uint32_t mNumModelsRendered;
		uint32_t mNumSkinnedModelsRendered;
		uint32_t mNumRigidModelsRendered;
		uint32_t mNumMeshsRendered;
		uint32_t mPad1;
		uint32_t mPad2;
		uint32_t mNumLightsProcessed;
		uint32_t mNumLightsNearTotal;
		uint32_t mNumLightsNearRendered;
		uint32_t mNumLightsStencilTotal;
		uint32_t mNumLightsStencilRendered;
		uint32_t mNumLightsFarTotal;
		uint32_t mNumLightsFarRendered;
		uint32_t mNumLightCards;
		uint32_t mNumShadowsRendered;
		uint32_t mNumCloudsRendered;
		uint32_t mNumParticles;
		uint32_t mNumLargeParticleBatches;
		uint32_t mNumSmallParticleBatches;
		uint32_t mPad3;
		uint32_t mPad4;
		uint32_t mPad5;
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

	class CView
	{
	public:
		CViewSettings* mSettings;
		Illusion::CSubmitContext* mSubmitContext;
		UFG::qVector4 mFrustumPlanes[6];
		CViewMetrics mViewMetrics;
		uint32_t mLastBeginFrameCounter;

		UFG_PAD(0xC);

		UFG::qMatrix44 mWorldViewProjection;
		UFG::qMatrix44 mViewWorld;
		float mExtractedNearPlane;
		float mExtractedFarPlane;

		void Draw(CPoly* p_Poly, Illusion::CMaterial* p_Material, UFG::qMatrix44* p_LocalWorld)
		{
			reinterpret_cast<void(__fastcall*)(void*, CPoly*, Illusion::CMaterial*, UFG::qMatrix44*)>(UFG_RVA(0xE880))(this, p_Poly, p_Material, p_LocalWorld);
		}

		void SubmitRenderModel(Illusion::CModel* p_Model, UFG::qMatrix44* p_LocalWorld)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CModel*, UFG::qMatrix44*)>(UFG_RVA(0x7D20))(this, p_Model, p_LocalWorld);
		}
	};
}