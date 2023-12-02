#pragma once
#include "Primitive.hxx"
#include "Material.hxx"
#include "Target.hxx"
#include "Texture.hxx"

namespace Illusion
{
	// StateValue Params
	struct CB_BeamSettings
	{
		float Colour[4];
		float AnimUVScaleOffset[4];
	};

	struct CB_EnvironmentSettings
	{
		float SunDir[4];
		float SunDirWorld[4];
		float SunColor[4];
		float AmbientColorHorizon[4];
		float ScaleAndHeight[4];
		float ScatterZenithColor[4];
		float ScatterHorizonColor[4];
		float ScatterGroundColor[4];
		float ScatterSunColor[4];
		float CharacterParams[4];
		float FogStartStopSky[4];
		float WindDirAndMag[4];
		float DisplayDebug[4];
		float LitWindowTimeOn[4];
		float Lighting[4];
		float SunScatterParams[4];
	};

	struct CB_FXOverrideSettings
	{
		float ColorTint[4];
		float Params1[4];
	};

	struct CB_RainSettings
	{
		float WorldViewProj[16];
		float PreviousWorldViewProj[16];
		float WorldView[16];
		float PositionOffset[4];
		float Velocity[4];
		float Alpha[4];
		float ViewPosition[4];
		float SizeScale[4];
		float Lighting[4];
		float Forward[4];
		float ParticleBoxSize[4];
	};

	struct CB_SceneryInstance
	{
		float ColourTint[4];
		float SIColourTint[4];
		float Mask[4];
		float Value0[4];
	};

	struct CB_SkySettings
	{
		float CloudColourTop[4];
		float CloudColourMid[4];
		float CloudColourBottom[4];
		float CloudShadingComponents[4];
		float CloudColourCeiling[4];
	};

	// Generic
	class  __declspec(align(16)) CViewportScissorState
	{
	public:
		float mViewPortX;
		float mViewPortY;
		float mViewPortWidth;
		float mViewPortHeight;
		float mViewPortMinDepth;
		float mViewPortMaxDepth;
		int mScissorX;
		int mScissorY;
		int mScissorWidth;
		int mScissorHeight;
	};

	class CStateValues
	{
	public:
		UFG::BitFlags128 mSetValueMask;
		void* mParamValues[128];

		void ApplyMaskFlag(uint32_t p_Flag)
		{
			if (p_Flag >= 64)
				mSetValueMask.mFlags[1] |= 1ui64 << static_cast<uint64_t>(p_Flag - 64);
			else
				mSetValueMask.mFlags[0] |= 1ui64 << static_cast<uint64_t>(p_Flag);
		}
	};

	class CSubmitContext
	{
	public:
		void* vfptr;
		CStateValues mStateValues;

		UFG_PAD(0x848);
		/*Illusion::StateArgs mStateArgs;
		Illusion::eRenderPass::Enum mRenderPass;
		Illusion::ShaderSelector* mShaderSelector;
		Illusion::MaterialModifierData* mMaterialModifier;*/

		void AddRenderCommand(int16_t p_CommandType, int16_t p_Index, void* p_Data)
		{
			reinterpret_cast<void(_fastcall*)(void*, int16_t, int16_t, void*)>(UFG_RVA(0x5DDE0))(this, p_CommandType, p_Index, p_Data);
		}
	};

	class CMaterialUser
	{
	public:
		int16_t mVisibilityFlags;
		int16_t mShadowFlags;
	};

	class CRMaterial
	{
	public:
		UFG_PAD(0x190);
		/*UFG::qReflectObjectType<Illusion::rMaterial, UFG::qReflectObject>
		Illusion::rMaterial::rRenderState mRenderState;
		Illusion::eRenderPass::StaticPassData* mStaticRenderPass;
		Illusion::eRenderPass::PassData mRenderPass[4];*/
	};

	class RMesh
	{
	public:
		UFG::qReflectString mMaterialName;
		UFG::qReflectHandle<CRMaterial> mMaterial;
		UFG::qResourceHandle mVertexDeclHandle;
		UFG::qResourceHandle mIndexBufferHandle;
		UFG::qResourceHandle mVertexBufferHandles[4];
		int mPrimType;
		int mIndexStart;
		uint32_t mNumPrims;
		const char* mDescription;
	};

	class CRModel
	{
	public:
		UFG::qReflectString mModelName;
		UFG::qReflectArray<RMesh> mMeshes;

		enum eType
		{
			LOD_A = 0x0,
			LOD_B = 0x1,
			LOD_C = 0x2,
			LOD_D = 0x3,
			OccluderAABB = 0x4,
			OccluderModel = 0x5,
			OccluderModelDoubleSided = 0x6,
			Shadow = 0x7,
			NonDrawable = 0x8,
			Physics = 0x8,
		};
		eType mModelType;

		UFG::qResourceHandle mBonePaletteHandle;
		UFG::qVector3 mAABBMin;
		unsigned int mNumPrims;
		UFG::qVector3 mAABBMax;
		unsigned int mLastUsedFrameNum;
		UFG::CMemoryPool* mMemoryPool;
	};

	class CModelProxy
	{
	public:
		UFG::qResourceHandle mModelHandle;
		CRModel* mRModel;

		~CModelProxy()
		{
			reinterpret_cast<void(__fastcall*)(void*)>(UFG_RVA(0x27F0))(this);
		}

		void Init(uint32_t p_NameUID)
		{
			reinterpret_cast<void(__fastcall*)(void*, uint32_t)>(UFG_RVA(0x3C70))(this, p_NameUID);
		}
	};
}