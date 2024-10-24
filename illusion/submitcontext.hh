#pragma once

namespace Illusion
{
	namespace eRenderPass /* Unknown where this should be placed at. */
	{
		enum Enum : s32
		{
			Custom = -1,
			Solid = 0,
			Decal,
			FeatherPunchThru,
			Depth,
			MAX_PASSES
		};
	}

	class ShaderSelector
	{
	public:
		UFG::BitFlags128 mAddState;
		UFG::BitFlags128 mRemoveState;
		u32 mLod;
	};

	class SubmitContext
	{
	public:
		StateValues mStateValues;
		StateArgs mStateArgs;
		eRenderPass::Enum mRenderPass;
		ShaderSelector* mShaderSelector;
		MaterialModifierData* mMaterialModifier;

		virtual void AddRenderCommand(s16 command_type, s16 index, void* data) = 0;
	};
	SDK_ASSERT_SIZEOF(SubmitContext, 0xC60);
}