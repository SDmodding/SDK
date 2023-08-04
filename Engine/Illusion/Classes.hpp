#pragma once

namespace Illusion
{
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