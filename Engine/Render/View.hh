#pragma once

namespace Render
{
	Illusion::CTarget* GetBackBufferTarget()
	{
		return *reinterpret_cast<Illusion::CTarget**>(UFG_RVA(0x2439A50));
	}

	UFG_INLINE UFG::qVector2 GetViewportScale()
	{
		Illusion::CTarget* _BackBufferTarget = GetBackBufferTarget();
		return { static_cast<float>(_BackBufferTarget->mWidth), static_cast<float>(_BackBufferTarget->mHeight) };
	}

	//=====================================================================================

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

		Illusion::CMaterial* CreateSimpleMaterial(uint32_t p_TextureNameUID, uint32_t p_RasterStateUID = 0x62F81854, uint32_t p_AlphaStateUID = 0x2782CCE6, bool p_DepthBias = false)
		{
			return reinterpret_cast<Illusion::CMaterial*(__fastcall*)(void*, uint32_t, uint32_t, uint32_t, bool)>(UFG_RVA(0xD590))(this, p_TextureNameUID, p_RasterStateUID, p_AlphaStateUID, p_DepthBias);
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

		void Draw(Illusion::CPrimitive* p_Primitive, Illusion::CMaterial* p_Material, UFG::qMatrix44* p_LocalWorld)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CPrimitive*, Illusion::CMaterial*, UFG::qMatrix44*)>(UFG_RVA(0xEB70))(this, p_Primitive, p_Material, p_LocalWorld);
		}

		void DrawColoredRect_Xform(float p_X, float p_Y, float p_Width, float p_Height, UFG::qColour* p_Colour, uint32_t p_TextureUID, float* p_UVs, uint32_t p_AlphaStateUID, uint32_t p_RasterStateUID, UFG::qMatrix44* p_TransformMatrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, float, float, float, float, UFG::qColour*, uint32_t, float*, uint32_t, uint32_t, UFG::qMatrix44*)>(UFG_RVA(0xBFF80))(this, p_X, p_Y, p_Width, p_Height, p_Colour, p_TextureUID, p_UVs, p_AlphaStateUID, p_RasterStateUID, p_TransformMatrix);
		}

		void DrawClippedPolys(UFG::ClipRect* p_Rects, int p_RectCount, UFG::qColour* p_Colour, uint32_t p_TextureUID, uint32_t p_AlphaStateUID, uint32_t p_RasterStateUID, UFG::qMatrix44* p_TransformMatrix)
		{
			reinterpret_cast<void(__fastcall*)(void*, UFG::ClipRect*, int, UFG::qColour*, uint32_t, uint32_t, uint32_t, UFG::qMatrix44*)>(UFG_RVA(0xBFAD0))(this, p_Rects, p_RectCount, p_Colour, p_TextureUID, p_AlphaStateUID, p_RasterStateUID, p_TransformMatrix);
		}

		void SubmitRenderModel(Illusion::CModel* p_Model, UFG::qMatrix44* p_LocalWorld)
		{
			reinterpret_cast<void(__fastcall*)(void*, Illusion::CModel*, UFG::qMatrix44*)>(UFG_RVA(0x7D20))(this, p_Model, p_LocalWorld);
		}
	};
}