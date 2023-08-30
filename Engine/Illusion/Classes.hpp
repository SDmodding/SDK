#pragma once

namespace Illusion
{
	// StateValue Params
	struct CB_BeamSettings
	{
		float Colour[4];
		float AnimUVScaleOffset[4];
	};

	struct CB_FXOverrideSettings
	{
		float ColorTint[4];
		float Params1[4];
	};

	struct CB_SceneryInstance
	{
		float ColourTint[4];
		float SIColourTint[4];
		float Mask[4];
		float Value0[4];
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
	};

	class CMaterial;
}