#pragma once

namespace Illusion
{
	class ComponentLookup
	{
	public:
		u32 mNumComponentBits;
		UFG::BitFlags128 mComponentBit[11];
	};

	class ShaderComponent
	{
	public:
		const char* mStateBlockName;
		UFG::BitFlags128 mStateBlockMask;
	};

	class ShaderPermutation
	{
	public:
		const char* mShaderName;
		ShaderHandle mShaderHandle;
		UFG::BitFlags128 mStateBlockMask;
		u32 mNumStateBlocks;
	};

	class ShaderTemplate : public UFG::qResourceData
	{
	public:
		u32 mPad0;
		u32 mNumShaderPermutations;
		ShaderPermutation* mShaderPermutations;
		UFG::BitFlags128 mPermutationStateBlockMask;
		u32 mNumComponents;
		ShaderComponent* mComponents;
		UFG::BitFlags128 mlodRemoveFlags[8];
		bool mHasLod;
		ComponentLookup mComponentLookup;
		u16 mNumPermutationIndices;
		u16* mPermutationIndexTable;
	};

	class ShaderTemplateHandle : public UFG::qTypedResourceHandle<RTypeUID_ShaderTemplate, ShaderTemplate>{};
}