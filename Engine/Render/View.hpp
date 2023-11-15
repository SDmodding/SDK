#pragma once

namespace Render
{
	Illusion::CTarget* GetBackBufferTarget()
	{
		return *reinterpret_cast<Illusion::CTarget**>(UFG_RVA(0x2439A50));
	}

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

		CView(CViewSettings* p_Settings, Illusion::CSubmitContext* p_SubmitCtx)
		{
			reinterpret_cast<void(__fastcall*)(void*, CViewSettings*, Illusion::CSubmitContext*)>(UFG_RVA(0xC850))(this, p_Settings, p_SubmitCtx);
		}

		void BeginTarget(Illusion::CTarget* p_Target, const char* p_Description, uint32_t p_DestSliceFace, uint32_t p_DestMipLevel, Illusion::CViewportScissorState* p_VPScissor, bool p_ClearOnResolve, bool p_IgnoreResolveDepth, bool p_PS4DecompressDepth, bool p_D3DDisableDepthCopy)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CTarget*, const char*, uint32_t, uint32_t, Illusion::CViewportScissorState*, bool, bool, bool, bool)>(UFG_RVA(0xD2D0))(this, p_Target, p_Description, p_DestSliceFace, p_DestMipLevel, p_VPScissor, p_ClearOnResolve, p_IgnoreResolveDepth, p_PS4DecompressDepth, p_D3DDisableDepthCopy);
		}

		void Clear(UFG::qColour* p_Colour, uint32_t p_Flags, float p_Depth, uint32_t p_Stencil)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::qColour*, uint32_t, float, uint32_t)>(UFG_RVA(0xD4D0))(this, p_Colour, p_Flags, p_Depth, p_Stencil);
		}

		void Draw(CPoly* p_Poly, Illusion::CMaterial* p_Material, UFG::qMatrix44* p_LocalWorld)
		{
			reinterpret_cast<void(__fastcall*)(void*, CPoly*, Illusion::CMaterial*, UFG::qMatrix44*)>(UFG_RVA(0xE880))(this, p_Poly, p_Material, p_LocalWorld);
		}

		uint32_t Draw(UFG::qResourceHandle* p_ModelHandle, UFG::qMatrix44* p_LocalWorld, bool p_DoClip)
		{
			return reinterpret_cast<uint32_t(__fastcall*)(void*, UFG::qResourceHandle*, UFG::qMatrix44*, bool)>(UFG_RVA(0xE420))(this, p_ModelHandle, p_LocalWorld, p_DoClip);
		}

		void SubmitRenderModel(Illusion::CModel* p_Model, UFG::qMatrix44* p_LocalWorld)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CModel*, UFG::qMatrix44*)>(UFG_RVA(0x7D20))(this, p_Model, p_LocalWorld);
		}
	};
}